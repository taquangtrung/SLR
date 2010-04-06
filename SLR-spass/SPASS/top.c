/**************************************************************/
/* ********************************************************** */
/* *                                                        * */
/* *              TOP MODULE OF SPASS                       * */
/* *                                                        * */
/* *  $Module:   TOP                                        * */
/* *                                                        * */
/* *  Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001      * */
/* *  MPI fuer Informatik                                   * */
/* *                                                        * */
/* *  This program is free software; you can redistribute   * */
/* *  it and/or modify it under the terms of the GNU        * */
/* *  General Public License as published by the Free       * */
/* *  Software Foundation; either version 2 of the License, * */
/* *  or (at your option) any later version.                * */
/* *                                                        * */
/* *  This program is distributed in the hope that it will  * */
/* *  be useful, but WITHOUT ANY WARRANTY; without even     * */
/* *  the implied warranty of MERCHANTABILITY or FITNESS    * */
/* *  FOR A PARTICULAR PURPOSE.  See the GNU General Public * */
/* *  License for more details.                             * */
/* *                                                        * */
/* *  You should have received a copy of the GNU General    * */
/* *  Public License along with this program; if not, write * */
/* *  to the Free Software Foundation, Inc., 59 Temple      * */
/* *  Place, Suite 330, Boston, MA  02111-1307  USA         * */
/* *                                                        * */
/* *                                                        * */
/* $Revision: 1.9 $                                       * */
/* $State: Exp $                                            * */
/* $Date: 2007/07/13 08:29:21 $                             * */
/* $Author: weidenb $                                       * */
/* *                                                        * */
/* *             Contact:                                   * */
/* *             Christoph Weidenbach                       * */
/* *             MPI fuer Informatik                        * */
/* *             Stuhlsatzenhausweg 85                      * */
/* *             66123 Saarbruecken                         * */
/* *             Email: spass@mpi-inf.mpg.de                * */
/* *             Germany                                    * */
/* *                                                        * */
/* ********************************************************** */
/**************************************************************/

/* $RCSfile: top.c,v $ */

/*** MAIN LOOP *************************************************/

/**************************************************************/
/* Includes                                                   */
/**************************************************************/

#include "alarm.h"
#include "dfg.h"
#include "defs.h"
#include "ia.h"
#include "rules-inf.h"
#include "rules-sort.h"
#include "rules-split.h"
#include "terminator.h"
#include "rules-red.h"
#include "analyze.h"
#include "clock.h"
#include "strings.h"
#include "options.h"
#include "context.h"
#include "cnf.h"
#include "search.h"
#include "hasharray.h"
#include "closure.h"
#include "eml.h"
#include <errno.h>
#include <stdlib.h>

#include "../usercode/user-defined.h"

/**************************************************************/
/* Types and Variables                                        */
/**************************************************************/

static const char *top_InputFile;

static OPTID top_RemoveFileOptId;

typedef enum {
	top_PROOF, top_COMPLETION, top_RESOURCE
} top_SEARCHRESULT;

/**************************************************************/
/* Catch Signals Section                                      */
/**************************************************************/

#ifdef SPASS_SIGNALS
#include <signal.h>

static PROOFSEARCH *top_PROOFSEARCH;

static void top_SigHandler(int Signal)
/**************************************************************
 INPUT:
 RETURNS:
 EFFECT:
 ***************************************************************/
{
	if (Signal == SIGSEGV || Signal == SIGBUS) {
		puts("\n\n\tSPASS is going to crash. This is probably caused by a");
		puts("\tbug in SPASS.  Please send a copy of the input file(s) together");
		puts("\twith the used options to spass@mpi-inf.mpg.de, and someone will");
		puts("\ttry to fix the problem.\n");
		abort();
	}

	if (Signal == SIGINT || Signal == SIGTERM) {
		clock_StopPassedTime(clock_OVERALL);
		printf("\nSPASS %s ", vrs_VERSION);
		puts("\nSPASS beiseite: Ran out of time. SPASS was killed.");
		printf("Problem: %s ",
				(top_InputFile != (char*)NULL ? top_InputFile : "Read from stdin."));
		printf("\nSPASS derived %d clauses, backtracked %d clauses "
				"and kept %d clauses.",
				(*top_PROOFSEARCH == (PROOFSEARCH)NULL ? 0 : prfs_DerivedClauses(*top_PROOFSEARCH)),
				(*top_PROOFSEARCH == (PROOFSEARCH)NULL ? 0 : prfs_BacktrackedClauses(*top_PROOFSEARCH)),
				(*top_PROOFSEARCH == (PROOFSEARCH)NULL ? 0 : prfs_KeptClauses(*top_PROOFSEARCH)));
		printf("\nSPASS allocated %lu KBytes.", memory_DemandedBytes()/1024);
		fputs("\nSPASS spent\t", stdout);
		clock_PrintTime(clock_OVERALL);
		fputs(" on the problem.\n\t\t", stdout);
		clock_PrintTime(clock_INPUT);
		fputs(" for the input.\n\t\t", stdout);
		clock_PrintTime(clock_CNF);
		fputs(" for the FLOTTER CNF translation.\n\t\t", stdout);
		clock_PrintTime(clock_INFERENCE);
		fputs(" for inferences.\n\t\t", stdout);
		clock_PrintTime(clock_BACKTRACK);
		fputs(" for the backtracking.\n\t\t", stdout);
		clock_PrintTime(clock_REDUCTION);
		puts(" for the reduction.");
	}

	if (opts_IsSet(top_RemoveFileOptId))
	remove(top_InputFile);

	exit(EXIT_FAILURE);
}

#endif

/**************************************************************/
/* Clause Selection Functions                                 */
/**************************************************************/

static CLAUSE top_SelectClauseDepth(LIST List, FLAGSTORE Flags)
/**************************************************************
 INPUT:   A list of clauses and a flag store.
 RETURNS: A clause selected from the list.
 EFFECT:  This function selects a clause from the list according
 to the following criteria:
 1. minimal depth
 2. minimal weight
 3a. maximal number of variable occurrences, if the flag
 'PrefVar' is TRUE
 3b. minimal number of variable occurrences, if 'PrefVar'
 is FALSE
 ***************************************************************/
{
	CLAUSE Result;
	NAT Vars, NewVars, Weight, Depth, NewDepth;

	Result = (CLAUSE) list_Car(List);
	Depth = clause_Depth(Result);
	Weight = clause_Weight(Result);
	Vars = clause_NumberOfVarOccs(Result);
	List = list_Cdr(List);

	while (!list_Empty(List)) {
		NewDepth = clause_Depth(list_Car(List));
		if (NewDepth <= Depth) {
			if (NewDepth < Depth || clause_Weight(list_Car(List)) < Weight) {
				Depth = NewDepth;
				Result = (CLAUSE) list_Car(List);
				Weight = clause_Weight(Result);
				Vars = clause_NumberOfVarOccs(list_Car(List));
			} else if (clause_Weight(list_Car(List)) == Weight) {
				NewVars = clause_NumberOfVarOccs(list_Car(List));
				if (flag_GetFlagValue(Flags, flag_PREFVAR)) {
					if (Vars < NewVars) {
						Depth = NewDepth;
						Result = (CLAUSE) list_Car(List);
						Weight = clause_Weight(Result);
						Vars = NewVars;
					}
				} else if (Vars > NewVars) {
					Depth = NewDepth;
					Result = (CLAUSE) list_Car(List);
					Weight = clause_Weight(Result);
					Vars = NewVars;
				}
			}
		}
		List = list_Cdr(List);
	}

	return Result;
}

static CLAUSE top_SelectMinimalWeightClause(LIST List, FLAGSTORE Flags)
/**************************************************************
 INPUT:   A list of clauses and a flag store.
 RETURNS: A clause selected from the list.
 EFFECT:  This function selects a clause with minimal weight.
 If more than one clause has minimal weight and the flag
 'PrefVar' is TRUE, a clause with maximal number of variable
 occurrences is selected. If 'PrefVar' is FALSE, a clause with
 minimal number of variable occurrences is selected.
 If two clauses are equal with respect to the two criteria
 the clause with the smaller list position is selected.
 CAUTION: THE LIST HAS TO BY SORTED BY WEIGHT IN ASCENDING ORDER!
 ***************************************************************/
{
	CLAUSE Result;
	NAT Vars, NewVars, Weight;

#ifdef CHECK
	/* Check invariant: List has to be sorted by weight (ascending) */
	LIST Scan;
	Weight = clause_Weight(list_Car(List));
	for (Scan = list_Cdr(List); !list_Empty(Scan); Scan = list_Cdr(Scan)) {
		NAT NewWeight;
		NewWeight = clause_Weight(list_Car(Scan));
		if (NewWeight < Weight) {
			misc_StartErrorReport();
			misc_ErrorReport("\n In top_SelectMinimalConWeightClause: clause list ");
			misc_ErrorReport("isn't sorted by weight");
			misc_FinishErrorReport();
		}
		Weight = NewWeight;
	}
#endif

	Result = (CLAUSE) list_Car(List);
	Weight = clause_Weight(Result);
	Vars = clause_NumberOfVarOccs(Result);
	List = list_Cdr(List);

	while (!list_Empty(List)) {
		if (clause_Weight(list_Car(List)) == Weight) {
			NewVars = clause_NumberOfVarOccs(list_Car(List));
			if (flag_GetFlagValue(Flags, flag_PREFVAR)) {
				if (Vars < NewVars) {
					Result = (CLAUSE) list_Car(List);
					Weight = clause_Weight(Result);
					Vars = NewVars;
				}
			} else if (Vars > NewVars) {
				Result = (CLAUSE) list_Car(List);
				Weight = clause_Weight(Result);
				Vars = NewVars;
			}
		} else
			return Result;
		List = list_Cdr(List);
	}
	return Result;
}

static CLAUSE top_SelectMinimalConWeightClause(LIST List, FLAGSTORE Flags)
/**************************************************************
 INPUT:   A non-empty list of clauses and a flag store.
 RETURNS: A clause selected from the list.
 EFFECT:  This function selects a clause from the list in a
 similar way as the function top_SelectMinimalWeightClause.
 The only difference is that conjecture clauses are
 preferred over axiom clauses, because their weight
 is divided by a factor given by the flag 'PrefCon'.
 ***************************************************************/
{
	CLAUSE Result;
	NAT NewWeight, Weight, NewVars, Vars, Factor;

	Result = (CLAUSE) list_Car(List);
	Factor = flag_GetFlagValue(Flags, flag_PREFCON);
	Weight = clause_Weight(Result);
	if (clause_GetFlag(Result, CONCLAUSE))
		Weight = Weight / Factor;
	Vars = clause_NumberOfVarOccs(list_Car(List));
	List = list_Cdr(List);

	while (!list_Empty(List)) {
		NewWeight = clause_Weight(list_Car(List));
		if (clause_GetFlag(list_Car(List), CONCLAUSE))
			NewWeight = NewWeight / Factor;
		if (NewWeight < Weight) {
			Weight = NewWeight;
			Result = list_Car(List);
			Vars = clause_NumberOfVarOccs(list_Car(List));
		} else {
			if (NewWeight == Weight) {
				NewVars = clause_NumberOfVarOccs(list_Car(List));
				if (flag_GetFlagValue(Flags, flag_PREFVAR)) {
					if (Vars < NewVars) {
						Result = (CLAUSE) list_Car(List);
						Weight = NewWeight;
						Vars = NewVars;
					}
				} else if (Vars > NewVars) {
					Result = (CLAUSE) list_Car(List);
					Weight = NewWeight;
					Vars = NewVars;
				}
			}
		}

		List = list_Cdr(List);
	}
	return Result;
}

/*static CLAUSE top_SelectClauseDepth(LIST List)*/
/**************************************************************
 INPUT:   A list of clauses.
 RETURNS: A clause selected from the list.
 EFFECT:
 ***************************************************************/
/*{
 CLAUSE Result;
 int    Min, Depth;

 Result = (CLAUSE)list_Car(List);
 Depth  = clause_Depth(Result);
 Min    = Depth * clause_Weight(Result);
 List   = list_Cdr(List);

 if (Depth == 0)
 return Result;

 while (!list_Empty(List)) {
 Depth =  clause_Depth(list_Car(List));
 if (Min > Depth * clause_Weight(list_Car(List))) {
 Result = list_Car(List);
 if (Depth == 0)
 return Result;
 Min    = clause_Depth(Result) * clause_Weight(Result);
 }
 List = list_Cdr(List);
 }

 return Result;
 }*/

static LIST top_GetLiteralsForSplitting(CLAUSE Clause, BOOL SuccedentOnly)
/**************************************************************
 INPUT:   A clause and a flag whether only succedent literals should be
 considered
 RETURNS: A list of literal indices where every single
 literal doesn't share any variables with other literals.
 So these literals can be split as units.
 If SuccedentOnly is TRUE, only succedent lits are considered
 ***************************************************************/
{
	LIST* Variables; /* An array, mapping literal index to list of variables */
	int i, j, EndIndex;
	BOOL Stop;
	LIST Failed, Result;

	Result = list_Nil();
	EndIndex = (SuccedentOnly ? clause_FirstSuccedentLitIndex(Clause)
			: clause_FirstLitIndex());

	/* Special case: clause is ground, so return all literals */
	if (clause_IsGround(Clause)) {
		for (i = clause_LastLitIndex(Clause); i >= EndIndex; i--)
			Result = list_Cons((POINTER) i, Result);
		return Result;
	}

	Variables = memory_Malloc(sizeof(LIST) * clause_Length(Clause));
	/* Initialize the array */
	for (i = clause_FirstLitIndex(); i <= clause_LastLitIndex(Clause); i++)
		Variables[i] = term_VariableSymbols(clause_GetLiteralAtom(Clause, i));

	/* <Failed> is the set of literals that share variables with other literals */
	Failed = list_Nil();
	for (i = clause_LastLitIndex(Clause); i >= EndIndex; i--) {
		if (list_Empty(Variables[i]))
			Result = list_Cons((POINTER) i, Result);
		else if (!list_PointerMember(Failed, (POINTER) i)) {
			/* We don't know yet whether the literal shares variables */
			Stop = FALSE;
			for (j = clause_FirstLitIndex(); j <= clause_LastLitIndex(Clause)
					&& !Stop; j++) {
				if (i != j && list_HasIntersection(Variables[i], Variables[j])) {
					Stop = TRUE; /* Literal isn�t candidate for "optimal" splitting */
					Failed = list_Cons((POINTER) i, Failed);
					Failed = list_Cons((POINTER) j, Failed);
				}
			}
			if (!Stop)
				Result = list_Cons((POINTER) i, Result);
		}
	}

	/* Cleanup */
	for (i = clause_FirstLitIndex(); i <= clause_LastLitIndex(Clause); i++)
		list_Delete(Variables[i]);
	memory_Free(Variables, sizeof(LIST) * clause_Length(Clause));
	list_Delete(Failed);
	return Result;
}

static int top_GetOptimalSplitLiteralIndex(PROOFSEARCH Search, CLAUSE Clause,
		BOOL Usables)
/**************************************************************
 INPUT:   A proofsearch object, a clause and a boolean flag.
 RETURNS: The index of the positive literal from <Clause>
 with the greatest number of instances (maybe 0) within
 the WorkedOff/Usable sets of the proof search object.
 The literal mustn't share any variables with other literals.
 If the clause doesn't have a suitable literal, a negative
 number is returned.
 EFFECT:  If <Usables> is FALSE, only the number of instances
 within the WorkedOff set is considered, otherwise
 the number of instances within both clause sets is considered.
 ***************************************************************/
{
	LIST SplitLits;
	LITERAL Literal;
	NAT Count, MaxInstances;
	int Result;

	MaxInstances = -1;
	SplitLits = top_GetLiteralsForSplitting(Clause, flag_GetFlagValue(
			prfs_Store(Search), flag_SPLITHEURISTIC)
			== flag_SPLITHEURISTICSTANDARD);
	Result = -1;

	for (; !list_Empty(SplitLits); SplitLits = list_Pop(SplitLits)) {
		Literal = clause_GetLiteral(Clause, (int) list_Car(SplitLits));
		/* Count the number of instances */
		Count = prfs_GetNumberOfInstances(Search, Literal, Usables);
		if (Count > MaxInstances) {
			Result = (int) list_Car(SplitLits);
			MaxInstances = Count;
		}
	}
	return Result;
}

/* EK: hier lassen oder nach search.c oder nach rules-split.c? */
static CLAUSE top_GetPowerfulSplitClause(PROOFSEARCH Search, BOOL Usables,
		int* LitIndex)
/**************************************************************
 INPUT:   A proofsearch object, a boolean flag and a pointer to a literal
 index which is used as return value.
 RETURNS: A clause from the usable set that was selected as given clause.
 Iff no suitable clause was found NULL is returned and <*LitIndex>
 is set to -1.
 Iff a suitable clause was found, this clause is returned and
 <*LitIndex> is set to the index of the "optimal" literal, that
 is a literal that can be split off as unit witha high reduction
 potential
 EFFECT:  This function selects a clause from the "usable" set and
 a literal that are "optimal" for the application of the splitting
 rule with respect to the following criteria:
 1) the literal must occur in the succedent of the non-horn clause,
 2) the literal mustn't share any variables with other literals,
 3) the clause must have a solved constraint,
 4) the atom must have the maximum number of instances
 a) within the set of "workedoff" clauses, iff <Usables>=FALSE
 b) within the set of "usable" and "workedoff" clauses,
 iff "Usables"=TRUE
 5) the atom must have at least one instance in another clause.
 ***************************************************************/
{
	LIST Scan, SplitLits;
	NAT MaxNrOfInstances, NrOfInstances;
	CLAUSE Clause, OptimalClause;
	TERM Atom;
	SHARED_INDEX WOIndex, UsIndex;

	OptimalClause = NULL;
	*LitIndex = -1;
	MaxNrOfInstances = 0;
	WOIndex = prfs_WorkedOffSharingIndex(Search);
	UsIndex = prfs_UsableSharingIndex(Search);

	/* Prepare the term stamp */
	if (term_StampOverflow(sharing_StampID(WOIndex)))
		sharing_ResetAllTermStamps(WOIndex);
	if (Usables && term_StampOverflow(sharing_StampID(UsIndex)))
		sharing_ResetAllTermStamps(UsIndex);
	term_StartStamp();

	for (Scan = prfs_UsableClauses(Search); !list_Empty(Scan); Scan = list_Cdr(
			Scan)) {
		Clause = list_Car(Scan);

		if (clause_HasSolvedConstraint(Clause) && clause_Length(Clause) > 1
				&& (!clause_IsHornClause(Clause) || (flag_GetFlagValue(
						prfs_Store(Search), flag_SPLITHEURISTIC)
						== flag_SPLITHEURISTICGROUND && clause_GetFlag(Clause,
						CONCLAUSE) && /* Split non-Horn clauses or input conjecture clauses */
				clause_Depth(Clause) == 0))) {
			/* Get a list of splittable literal indices */
			SplitLits = top_GetLiteralsForSplitting(Clause, flag_GetFlagValue(
					prfs_Store(Search), flag_SPLITHEURISTIC)
					== flag_SPLITHEURISTICSTANDARD);
			for (; !list_Empty(SplitLits); SplitLits = list_Pop(SplitLits)) {
				LITERAL Literal;

				Literal = clause_GetLiteral(Clause, (int) list_Car(SplitLits));
				Atom = clause_LiteralAtom(Literal);
				if (!term_AlreadyVisited(Atom)) {
					/* Don't visit atom more than once */
					term_SetTermStamp(Atom);
					/* Count the number of instances */
					NrOfInstances = prfs_GetNumberOfInstances(Search, Literal,
							Usables);
					if (NrOfInstances > MaxNrOfInstances || OptimalClause
							== NULL || (NrOfInstances == MaxNrOfInstances &&
					/* Prefer shorter clauses for splitting! */
					clause_Length(Clause) < clause_Length(OptimalClause))) {
						OptimalClause = Clause;
						MaxNrOfInstances = NrOfInstances;
						*LitIndex = (int) list_Car(SplitLits);
					}
				}
			}
		}
	}
	term_StopStamp();

	/* The splittable literal must have at least one instance to be useful */
	/* reducing other clauses. If <Usables> is TRUE, the literal must even */
	/* have two instances, since the literal of the given clause is in the */
	/* usable index, too.                                                  */
	if (OptimalClause != (CLAUSE) NULL && (MaxNrOfInstances == 0 || (Usables
			&& MaxNrOfInstances == 1)) && (clause_Depth(OptimalClause) != 0
			|| flag_GetFlagValue(prfs_Store(Search), flag_SPLITHEURISTIC)
					!= flag_SPLITHEURISTICGROUND)) {
		*LitIndex = -1;
		OptimalClause = NULL;
	}

	return OptimalClause;
}

static LIST top_FullReductionSelectGivenComputeDerivables(PROOFSEARCH Search,
		CLAUSE *SplitClause, int *Counter)
/**************************************************************
 * Ham nay co tac dung tinh ra cac Derivables Clauses
 *
 INPUT:   A proof search object, a pointer to a clause resulting from a
 previous splitting step, and a pointer to an integer counter.
 RETURNS: A list of derived clauses.
 EFFECT:  In this function a clause is selected from the set of
 "usable" clauses. After a clause was selected as "given clause",
 inferences between the given clause and the "worked off" clauses
 are made. The selection works as follows:
 1) If <*SplitClause> is not NULL, the split clause
 is selected as "given clause". <*SplitClause> should result
 from splitting
 2) If <*SplitClause> is NULL, we try to find a clause that is
 "optimal" for splitting. This is done by selecting a literal
 <L> in a clause, such that <L> is variable-disjoint from
 the rest of the clause, and the atom of <L> has the maximum
 number of instances within the set of "usable" and "workoff"
 clauses.
 3) If the previous steps failed, a clause is selected by weight
 or by depth, depending on the parameters "WDRatio", "PrefVar"
 and "PrefCon". Then splitting is tried on the selected clause.
 If the clause is a non-horn clause, we try to find a positive
 literal <L> and a set of negative literals <N>, such that <N>
 and <L> are variable disjoint from the rest of the clause.
 ***************************************************************/
{
	CLAUSE GivenClause, TerminatorClause;
	LIST Derivables, SplitLits;
	FLAGSTORE Flags;
	PRECEDENCE Precedence;
	int LitIndex;

	GivenClause = NULL;
	Derivables = list_Nil();
	Flags = prfs_Store(Search);
	Precedence = prfs_Precedence(Search);

	/* 1) If the last given clause was split or if backtracking was applied, */
	/* then choose the clause resulting from the splitting step as        */
	/* given clause.                                                      */
	/* ATTENTION: Since the <SplitClause> might have been reduced since   */
	/* the time the variable was set, we have to check whether            */
	/* <SplitClause> is still element of the set of usable clauses.       */
	if (*SplitClause != NULL && list_PointerMember(prfs_UsableClauses(Search),
			*SplitClause))
		GivenClause = *SplitClause;

	*SplitClause = NULL;

	// TTQ_COMMENT . GivenClause - Tinh GivenClause trong top_FullReduction...
	if (GivenClause == NULL) {
		if (prfs_SplitCounter(Search) != 0)
			/* 2) Try to find an "optimal" splitting clause, that doesn't share */
			/*    variables with any other literal.                             */
			GivenClause = top_GetPowerfulSplitClause(Search, TRUE, &LitIndex);

		if (GivenClause != NULL) {
			/* Found "optimal" split clause, so apply splitting */
			SplitLits = list_List(clause_GetLiteral(GivenClause, LitIndex));
			*SplitClause = prfs_DoSplitting(Search, GivenClause, SplitLits);
			list_Delete(SplitLits);
		} else {
			/* 3) Splitting wasn't applied, so use the other strategies */
			if ((*Counter) % flag_GetFlagValue(Flags, flag_WDRATIO) == 0)
				GivenClause = top_SelectClauseDepth(prfs_UsableClauses(Search),
						Flags);
			else {
				if (flag_GetFlagValue(Flags, flag_PREFCON)
						!= flag_PREFCONUNCHANGED)
					GivenClause = top_SelectMinimalConWeightClause(
							prfs_UsableClauses(Search), Flags);
				else
					GivenClause = top_SelectMinimalWeightClause(
							prfs_UsableClauses(Search), Flags);
			}
			(*Counter)++; /* EK: hier lassen, oder eine Klammerebene nach aussen? */
		}
	}

	if (*SplitClause == NULL && prfs_SplitCounter(Search) != 0) {
		/* Try to find the "optimal" literal for splitting the clause. */
		/* This makes sense for a clause that is the right part of a   */
		/* splitting step.                                             */
		LitIndex = top_GetOptimalSplitLiteralIndex(Search, GivenClause, FALSE);
		if (LitIndex >= 0) {
			SplitLits = list_List(clause_GetLiteral(GivenClause, LitIndex));
			*SplitClause = prfs_DoSplitting(Search, GivenClause, SplitLits);
			list_Delete(SplitLits);
		} else {
			/* Optimal splitting wasn't possible, so try the old-style splitting. */
			/* Here a split is done if a positive literal doesn't share variables */
			/* with another POSITIVE literal. */
			*SplitClause = prfs_PerformSplitting(Search, GivenClause);
		}
	}

	prfs_ExtractUsable(Search, GivenClause);
	clause_SelectLiteral(GivenClause, Flags);

	if (flag_GetFlagValue(Flags, flag_PGIVEN)) {
		fputs("\n\tGiven clause: ", stdout);
		clause_Print(GivenClause);
		fflush(stdout);
	}

	// TTQ_NOTE . Derivables - sinh ra tu top_FullReductionSeclectGivenComputeDerivables
	if (*SplitClause != NULL)
		Derivables = list_List(*SplitClause);
	else {
		/* No splitting was applied */
		if (flag_GetFlagValue(Flags, flag_RTER) != flag_RTEROFF) {
			clock_StartCounter(clock_REDUCTION);

			/*
			 * Tim xem co dieu kien ket thuc (co xay ra mau thuan) hay ko - (terminator)
			 * 		- Neu tim thay 1 dieu kien mau thuan thi tra ve emptyClause
			 * 		- Neu ko tim thay thi tra ve NULL
			 */

			TerminatorClause = red_Terminator(GivenClause, flag_GetFlagValue(
					Flags, flag_RTER), prfs_WorkedOffSharingIndex(Search),
					prfs_UsableSharingIndex(Search), Flags, Precedence);
			clock_StopAddPassedTime(clock_REDUCTION);

			if (TerminatorClause != NULL) {
				/*
				 * Neu tim thay 1 Terminator Situation thi Derivables se la 1 EmptyClause
				 */
				/* An empty clause was derived by the "terminator" rule */
				Derivables = list_List(TerminatorClause);
				prfs_InsertUsableClause(Search, GivenClause);
			}
		}
		if (list_Empty(Derivables)) {
			// Neu tu cac buoc tren ko tim duoc Derivables nao...

			/* No splitting was applied, no empty clause was found by terminator */
			/*clause_SetSpecialFlags(GivenClause,ana_SortDecreasing());*/

			// ... thi chen GivenClauses vao danh sach cac WorkedOffClause...
			prfs_InsertWorkedOffClause(Search, GivenClause);
			clock_StartCounter(clock_INFERENCE);

			// ... va thuc hien INFERENCE giua GivenClause voi cac WorkedOffClause
			// TTQ_NOTE . RESOLUTION INFERENCE duoc thuc hien tai day
			Derivables = inf_DerivableClauses(Search, GivenClause);
			clock_StopAddPassedTime(clock_INFERENCE);
		}
	}

//	if (codeUser == TrungTQ) {
//		// TTQ_COMMENT . Print Derivables.
//		if (!list_Empty(Derivables)) {
//			printf(
//					"\n===Print derived clauses from top_FullReductionSeclectGivenComputeDerivables: \n");
//			clause_ListPrint(Derivables);
//			printf("\n     ... end print \n");
//
//		}
//	}

	if (codeUser == TrungTQ) {
		printf("\n===Print derived clauses from top_FullReductionSeclectGivenComputeDerivables: \n");
		for (int ii = 1; ii <= list_Length(Derivables); ii++) {
			printf("== clause %d:\n", ii);
			CLAUSE tempClause = list_NthElement(Derivables, ii );
			if (tempClause != NULL) {
				LIST lstLit = clause_GetLiteralList(tempClause);
				for (int jj = 1; jj <= list_Length(lstLit); jj++) {
					printf("===== literal %d:", jj);
					LITERAL tempLit = list_NthElement(lstLit, jj);
					if (tempLit != NULL) {
						clause_LiteralPrint(tempLit);
						printf(" --- ");
						CLAUSE owningClause = clause_LiteralOwningClause(tempLit);
						clause_Print(owningClause);
					}
					printf("\n");
				}
			}
			printf("\n");
		}
		printf("============== end\n");
	}

	prfs_IncDerivedClauses(Search, list_Length(Derivables));

	return Derivables;
}

static LIST top_LazyReductionSelectGivenComputeDerivables(PROOFSEARCH Search,
		CLAUSE *SplitClause, int *Counter)
/**************************************************************
 * Ham nay co tac dung tinh ra cac Derivables Clauses
 *
 INPUT:   A proof search object, a pointer to a clause resulting from a
 previous splitting step, and a pointer to an integer counter.
 RETURNS: A list of derived clauses.
 EFFECT:  In this function a clause is selected from the set of
 "usable" clauses. After a clause was selected as "given clause",
 inferences between the given clause and the "worked off" clauses
 are made. Take a look at the description of the function
 top_FullReduction... for more details.
 This function is more complicated than the other function,
 since clauses in the set of usable clauses may be reducible.
 Because of this fact, the selection of the given clause
 has to be done in a loop. After picking a "candidate" clause
 the clause is inter-reduced with the "worked off" set.
 If the candidate still exists after the reduction it is
 selected as given clause, else another usable clause is picked
 as candidate.
 ***************************************************************/
{
	CLAUSE GivenClause, TerminatorClause;
	LIST Derivables;
	FLAGSTORE Flags;
	PRECEDENCE Precedence;
	int LitIndex;

	/*
	 * GivenClause la clause se dc lay ra tu UsableClause
	 * de tu do thuc hien suy dien giua GivenClause voi cac Worked-Off Clause
	 *
	 */
	GivenClause = (CLAUSE) NULL;
	TerminatorClause = (CLAUSE) NULL;
	Derivables = list_Nil();
	Flags = prfs_Store(Search);
	Precedence = prfs_Precedence(Search);

	/*
	 * TTQ_COMMENT . GivenClause - Tinh GivenClause trong top_LazyReduction...
	 * Vong lap nay ket thuc khi:
	 * 		- tim dc 1 Given clause
	 * 		- hoac danh sach cac UsableClause rong
	 */
	while (GivenClause == (CLAUSE) NULL && !list_Empty(prfs_UsableClauses(
			Search))) {
		/* The selected clause may be redundant */

		if (*SplitClause != NULL && list_PointerMember(prfs_UsableClauses(
				Search), *SplitClause))
			GivenClause = *SplitClause;

		*SplitClause = NULL;

		/* Try selecting a clause that is optimal for splitting */
		// Tinh GivenClause tai day.
		if (GivenClause == NULL) {
			if (prfs_SplitCounter(Search) != 0) {
				GivenClause = top_GetPowerfulSplitClause(Search, FALSE,
						&LitIndex);
				/* The value of <LitIndex> isn't used here. */
			}

			if (GivenClause == NULL) {
				/* No optimal clause for splitting found */
				if ((*Counter) % flag_GetFlagValue(Flags, flag_WDRATIO) == 0)
					GivenClause = top_SelectClauseDepth(prfs_UsableClauses(
							Search), Flags);
				else {
					if (flag_GetFlagValue(Flags, flag_PREFCON)
							!= flag_PREFCONUNCHANGED)
						GivenClause = top_SelectMinimalConWeightClause(
								prfs_UsableClauses(Search), Flags);
					else
						GivenClause = top_SelectMinimalWeightClause(
								prfs_UsableClauses(Search), Flags);
				}
				(*Counter)++;
			}
		}
		// sau khi tinh dc GivenClause roi thi loai no ra khoi danh sach UsableClause
		prfs_ExtractUsable(Search, GivenClause);

		/* Reduce the selected clause */
		clock_StartCounter(clock_REDUCTION);
		GivenClause = red_CompleteReductionOnDerivedClause(Search, GivenClause,
				red_WORKEDOFF);
		clock_StopAddPassedTime(clock_REDUCTION);
	}

	if (GivenClause == (CLAUSE) NULL)
		/* Set of usable clauses is empty */
		return list_Nil();

	// TTQ_NOTE . Derivables - sinh ra tu top_LazyReductionSeclectGivenComputeDerivables
	if (clause_IsEmptyClause(GivenClause)) {
		/*
		 * Neu GivenClause la 1 EmptyClause
		 * thi Derivables tra ve la danh sach gom co 1 EmptyClause
		 */
		Derivables = list_List(GivenClause);
		return Derivables;
	} else {
		/*
		 * Neu GivenClause khong phai la 1 EmptyClause
		 * thi bat dau tinh Derivables tai day
		 */

		/* Reduce Workedoff clauses with selected clause */
		clock_StartCounter(clock_REDUCTION);
		Derivables = red_BackReduction(Search, GivenClause, red_WORKEDOFF);
		clock_StopAddPassedTime(clock_REDUCTION);
	}

	clause_SelectLiteral(GivenClause, Flags);
	/* Print selected clause */
	if (flag_GetFlagValue(Flags, flag_PGIVEN)) {
		fputs("\n\tGiven clause: ", stdout);
		clause_Print(GivenClause);
		fflush(stdout);
	}

	// TTQ_UNKNOWN . SplitClause - ko biet de lam j

	/* Try splitting */
	if (prfs_SplitCounter(Search) != 0) {
		/* First try "optimal" splitting on the selected clause */
		LitIndex = top_GetOptimalSplitLiteralIndex(Search, GivenClause, FALSE);

		if (LitIndex >= 0) {
			LIST SplitLits;

			SplitLits = list_List(clause_GetLiteral(GivenClause, LitIndex));
			*SplitClause = prfs_DoSplitting(Search, GivenClause, SplitLits);
			list_Delete(SplitLits);
		} else {
			/* Try the old splitting that allows negative literals   */
			/* sharing variables with the selected positive literal. */
			*SplitClause = prfs_PerformSplitting(Search, GivenClause);
		}
	}

	if (*SplitClause != NULL) {
		Derivables = list_Cons(*SplitClause, Derivables);
	} else {
		/* Try terminator reduction only for a clause that wasn't splitted. */
		if (flag_GetFlagValue(Flags, flag_RTER) != flag_RTEROFF) {
			TerminatorClause = red_Terminator(GivenClause, flag_GetFlagValue(
					Flags, flag_RTER), prfs_WorkedOffSharingIndex(Search),
					prfs_UsableSharingIndex(Search), Flags, Precedence);
			if (TerminatorClause != NULL) {
				Derivables = list_Cons(TerminatorClause, Derivables);
				prfs_InsertUsableClause(Search, GivenClause);
			}
		}
		if (TerminatorClause == (CLAUSE) NULL) {
			/* clause_SetSpecialFlags(GivenClause,ana_SortDecreasing());*/
			prfs_InsertWorkedOffClause(Search, GivenClause);
			clock_StartCounter(clock_INFERENCE);
			Derivables = list_Nconc(Derivables, inf_DerivableClauses(Search,
					GivenClause));
			clock_StopAddPassedTime(clock_INFERENCE);
		}
	}

//	if (codeUser == TrungTQ) {
//		// TTQ_COMMENT . Print Derivables.
//		if (!list_Empty(Derivables)) {
//			printf(
//					"\n===Print derived clauses from top_LazyReductionSeclectGivenComputeDerivables: \n");
//			clause_ListPrint(Derivables);
//			printf("\n     ... end print \n");
//		}
//	}
//
	if (codeUser == TrungTQ) {
		printf("\n===Print derived clauses from top_LazyReductionSeclectGivenComputeDerivables: \n");
		for (int ii = 1; ii <= list_Length(Derivables); ii++) {
			printf("== clause %d:\n", ii);
			CLAUSE tempClause = list_NthElement(Derivables, ii );
			if (tempClause != NULL) {
				LIST lstLit = clause_GetLiteralList(tempClause);
				for (int jj = 1; jj <= list_Length(lstLit); jj++) {
					printf("===== literal %d:", jj);
					LITERAL tempLit = list_NthElement(lstLit, jj);
					if (tempLit != NULL) {
						clause_LiteralPrint(tempLit);
						printf(" --- ");
						CLAUSE owningClause = clause_LiteralOwningClause(tempLit);
						clause_Print(owningClause);
					}
					printf("\n");
				}
			}
			printf("\n");
		}
		printf("============== end\n");
	}

	prfs_IncDerivedClauses(Search, list_Length(Derivables));

	return Derivables;
}

static PROOFSEARCH top_ProofSearch(PROOFSEARCH Search, LIST ProblemClauses,
		FLAGSTORE InputFlags, LIST UserPrecedence, int *BoundApplied,
		BOOL NativeClauseInput)
/**************************************************************
 INPUT:   A proof search object, a list of clauses, a flag store
 containing the flags from the command line and from
 the input file, a list containing the precedence as
 specified by the user, a pointer to an integer, and a
 boolean indicating if the input clauses need to be
 treated specially.
 RETURNS: The same proof search object
 EFFECTS:
 ***************************************************************/
{
	LIST Scan, EmptyClauses, Derivables;
	LIST UsedEmptyClauses;
	CLAUSE SplitClause, HighestLevelEmptyClause;
	FLAGSTORE Flags;
	PRECEDENCE Precedence;
	int Counter, ActBound, BoundMode, BoundLoops;

	HighestLevelEmptyClause = (CLAUSE) NULL;
	UsedEmptyClauses = list_Nil();
	EmptyClauses = list_Nil();
	Derivables = list_Nil();
	Flags = prfs_Store(Search);
	Precedence = prfs_Precedence(Search);
	Counter = 1;

	clock_InitCounter(clock_REDUCTION);
	clock_InitCounter(clock_BACKTRACK);
	clock_InitCounter(clock_INFERENCE);

	/* Important ! Recomputes Weight ! */
	ana_AnalyzeProblem(Search, ProblemClauses);
	if (flag_GetFlagValue(Flags, flag_AUTO)) {
		prfs_InstallFiniteMonadicPredicates(Search, ProblemClauses,	ana_FinMonPredList());
		/*
		 * Neu chay o che do AUTO, thi SPASS se tu dong phan tich input (cac ProblemClauses)
		 * de tim ra cac tham so hop ly.
		 */
		ana_AutoConfiguration(ProblemClauses, Flags, Precedence);
		/* File and input flags have higher precedence */
		flag_TransferSetFlags(InputFlags, Flags);
	}

	/* Rearrange automatically determined precedence according to user's specification. */
	symbol_RearrangePrecedence(Precedence, UserPrecedence);

	if (NativeClauseInput) {
		CLAUSE Clause;
		for (Scan = ProblemClauses; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
			Clause = (CLAUSE) list_Car(Scan);
			clause_OrientEqualities(Clause, Flags, Precedence);
			clause_Normalize(Clause);
			clause_SetNativeMaxLitFlags(Clause, Flags, Precedence);
			clause_UpdateWeight(Clause, Flags);
			clause_UpdateMaxVar(Clause);
		}
	} else
		for (Scan = ProblemClauses; !list_Empty(Scan); Scan = list_Cdr(Scan))
			clause_OrientAndReInit(list_Car(Scan), Flags, Precedence);

	/* Must be called after ana_AnalyzeProblem and Reorientation */
	ana_AnalyzeSortStructure(ProblemClauses, Flags, Precedence);

	if (flag_GetFlagValue(Flags, flag_AUTO)) {
		ana_ExploitSortAnalysis(Flags);
		/* File and input flags have higher precedence */
		flag_TransferSetFlags(InputFlags, Flags);
	}
	prfs_SetSplitCounter(Search, flag_GetFlagValue(Flags, flag_SPLITS));

	ActBound = flag_GetFlagValue(Flags, flag_BOUNDSTART);
	BoundMode = flag_GetFlagValue(Flags, flag_BOUNDMODE);
	BoundLoops = flag_GetFlagValue(Flags, flag_BOUNDLOOPS);
	*BoundApplied = -1;

	/*
	 * TTQ_NOTE . ** SPASS bat dau tai day
	 */
	if (flag_GetFlagValue(Flags, flag_PPROBLEM)) {
		puts("");
		puts(
				"--------------------------SPASS-START-----------------------------");
		puts("Input Problem:");
		clause_ListPrint(ProblemClauses);
		ana_Print(Flags, Precedence);
	}

	if (!NativeClauseInput && flag_GetFlagValue(Flags, flag_SORTS)
			!= flag_SORTSOFF) {
		BOOL Strong;
		Strong = (flag_GetFlagValue(Flags, flag_SORTS) == flag_SORTSMONADICALL);
		for (Scan = ProblemClauses; !list_Empty(Scan); Scan = list_Cdr(Scan))
			clause_SetSortConstraint((CLAUSE) list_Car(Scan), Strong, Flags,
					Precedence);
	}

	if (flag_GetFlagValue(Flags, flag_RINPUT)) {
		clock_StartCounter(clock_REDUCTION);
		/*
		 * Reduce input tai day
		 */
		EmptyClauses = red_ReduceInput(Search, ProblemClauses);
		clock_StopAddPassedTime(clock_REDUCTION);
		if (list_Empty(EmptyClauses) && flag_GetFlagValue(Flags, flag_SATINPUT))
			EmptyClauses = red_SatInput(Search);
	} else {
		for (Scan = ProblemClauses; !list_Empty(Scan); Scan = list_Cdr(Scan))
			if (red_ExplicitTautology(list_Car(Scan), Flags, Precedence))
				clause_Delete(list_Car(Scan));
			else
				prfs_InsertUsableClause(Search, list_Car(Scan));
	}
	Derivables = list_Nil();

	if (ana_SortRestrictions() || (ana_UnsolvedSortRestrictions()
			&& flag_GetFlagValue(Flags, flag_SORTS) == flag_SORTSMONADICALL)) {
		if (flag_GetFlagValue(Flags, flag_RSST))
			prfs_SetStaticSortTheory(Search, sort_ApproxStaticSortTheory(
					prfs_UsableClauses(Search), Flags, Precedence));
		prfs_SetDynamicSortTheory(Search, sort_TheoryCreate());
	}

	/* Fix literal order in clauses in the usable set.
	 Since they are shared, we have to extract them from
	 the sharing before fixing them. Afterwards, we have to
	 insert them in the sharing again.
	 */
	for (Scan = prfs_UsableClauses(Search); !list_Empty(Scan); Scan = list_Cdr(
			Scan)) {
		CLAUSE clause;
		clause = list_Car(Scan);
		clause_MakeUnshared(clause, prfs_UsableSharingIndex(Search));
		clause_FixLiteralOrder(clause, Flags, Precedence);
		clause_InsertIntoSharing(clause, prfs_UsableSharingIndex(Search),
				prfs_Store(Search), prfs_Precedence(Search));
	}

	/* Calculate the frequency counts for the symbols in the usable set. */
	for (Scan = prfs_UsableClauses(Search); !list_Empty(Scan); Scan = list_Cdr(
			Scan)) {
		CLAUSE clause;
		clause = list_Car(Scan);

		clause_CountSymbols(clause);
	}

	/* Sort usable set. */
	prfs_SetUsableClauses(Search, list_Sort(prfs_UsableClauses(Search),
			(BOOL(*)(void *, void *)) clause_CompareAbstractLEQ));

	if (flag_GetFlagValue(Flags, flag_SOS)) {
		Derivables = list_Copy(prfs_UsableClauses(Search));
		for (Scan = Derivables; !list_Empty(Scan); Scan = list_Cdr(Scan))
			if (!clause_GetFlag(list_Car(Scan), CONCLAUSE))
				prfs_MoveUsableWorkedOff(Search, list_Car(Scan));
		list_Delete(Derivables);
	}

	if (flag_GetFlagValue(Flags, flag_PPROBLEM)) {
		puts("\nProcessed Problem:");
		puts("\nWorked Off Clauses:");
		clause_ListPrint(prfs_WorkedOffClauses(Search));
		puts("\nUsable Clauses:");
		clause_ListPrint(prfs_UsableClauses(Search));
	}

	while ((list_Empty(EmptyClauses) || !prfs_SplitStackEmpty(Search))
			&& prfs_Loops(Search) != 0 && ((*BoundApplied != -1)
			|| !list_Empty(prfs_UsableClauses(Search))) && (flag_GetFlagValue(
			Flags, flag_TIMELIMIT) == flag_TIMELIMITUNLIMITED
			|| flag_GetFlagValue(Flags, flag_TIMELIMIT) > clock_GetSeconds(
					clock_OVERALL))) {

		Derivables = list_Nil();
		SplitClause = (CLAUSE) NULL;
		*BoundApplied = -1;

		while ((list_Empty(EmptyClauses) || !prfs_SplitStackEmpty(Search))
				&& prfs_Loops(Search) != 0 && (!list_Empty(prfs_UsableClauses(
				Search)) || !list_Empty(EmptyClauses)) && (flag_GetFlagValue(
				Flags, flag_TIMELIMIT) == flag_TIMELIMITUNLIMITED
				|| flag_GetFlagValue(Flags, flag_TIMELIMIT) > clock_GetSeconds(
						clock_OVERALL))) {
			// TTQ_NOTE . Tinh ra cac Derivables Clauses
			/*
			 * Tai buoc nay se xu ly cac cho sinh ra Derivables clause theo mo hinh SLR:
			 * 		-- Cu the: Doi voi Derivables vua sinh ra dc
			 * 		   kiem tra xem co literal nao co the chuyen cho SAT SOlver dc ko?
			 * 		   - Neu co thi se tinh justification cua literal do va chuyen cho SAT Solver
			 * 		   - Neu ko co thi tiep tuc de cho SPASS xu ly
			 *
			 */

			if (!list_Empty(EmptyClauses)) {
				/*
				 * TTQ_NOTE . Backtracking RULE of resolution
				 *
				 * Neu tai buoc nay tim thay 1 empty clause thi tai buoc nay
				 * xay ra mau thuan, goi backtracking de tim buoc trc day
				 * gay ra mau thuan
				 */

				/* Backtracking */
				clock_StartCounter(clock_BACKTRACK);
				Derivables = split_Backtrack(Search, HighestLevelEmptyClause,
						&SplitClause);
				clock_StopAddPassedTime(clock_BACKTRACK);
				prfs_IncBacktrackedClauses(Search, list_Length(Derivables));

				if (prfs_SplitStackEmpty(Search))
					Derivables = list_Nconc(EmptyClauses, Derivables);
				else {
					for (; !list_Empty(EmptyClauses); EmptyClauses = list_Pop(
							EmptyClauses))
						if (list_Car(EmptyClauses) != HighestLevelEmptyClause)
							clause_Delete(list_Car(EmptyClauses));
					prfs_InsertDocProofClause(Search, HighestLevelEmptyClause);
					/* Keep HighestLevelEmptyClause for finding the terms required */
					/* for the proof.                                              */
					if (flag_GetFlagValue(Flags, flag_DOCPROOF))
						UsedEmptyClauses = list_Cons(HighestLevelEmptyClause,
								UsedEmptyClauses);
					if (flag_GetFlagValue(Flags, flag_DOCSPLIT)) {
						printf("\n\t Split Backtracking level %d:",
								prfs_ValidLevel(Search));
						if (flag_GetFlagValue(Flags, flag_DOCSPLIT) == 2) {
							LIST Scon;
							printf("\n\t Backtracked clauses:");
							for (Scon = Derivables; !list_Empty(Scon); Scon
									= list_Cdr(Scon)) {
								fputs("\n\tBclause: ", stdout);
								clause_Print((CLAUSE) list_Car(Scon));
								fflush(stdout);
							}
							printf("\n\t End Backtracked clauses:");
						}
					}
				}
				EmptyClauses = list_Nil();
				HighestLevelEmptyClause = (CLAUSE) NULL;
			} else {
				/* no empty clause found */

#ifdef CHECK
				if (!prfs_Check(Search)) {
					misc_StartErrorReport();
					misc_ErrorReport("\n In top_ProofSearch: Illegal state of search in SPASS.\n");
					misc_FinishErrorReport();
				}
				if (!ana_Equations())
				red_CheckSplitSubsumptionCondition(Search);
#endif 

				/*
				 * Derivables o day la danh sach cac clause moi dc sinh ra khi
				 * ap dung luat resolution
				 *
				 *
				 * TTQ_NOTE . Resolution rule thuc hien tai day
				 * Sua cac thu tuc top_FullReducion... va top_LazyReduction...
				 * duoi de bo sung them luat Justified resolution vao trong
				 * cac thu tuc nay
				 */

				if (flag_GetFlagValue(Flags, flag_FULLRED))
					Derivables = top_FullReductionSelectGivenComputeDerivables(
							Search, &SplitClause, &Counter);
				else
					Derivables = top_LazyReductionSelectGivenComputeDerivables(
							Search, &SplitClause, &Counter);
			}

			/* Print the derived clauses, if required */
			if (flag_GetFlagValue(Flags, flag_PDER))
				// TTQ_NOTE . Print 1 List cac clause ra man hinh
				for (Scan = Derivables; !list_Empty(Scan); Scan
						= list_Cdr(Scan)) {
					fputs("\nDerived: ", stdout);
					clause_Print(list_Car(Scan));
				}

			/* Partition the derived clauses into empty and non-empty clauses */

			// Loai bo cac empty clause ra khoi Derivables
			Derivables = split_ExtractEmptyClauses(Derivables, &EmptyClauses);

			/* Apply reduction rules */
			clock_StartCounter(clock_REDUCTION);
			if (flag_GetFlagValue(Flags, flag_FULLRED)) {
				EmptyClauses = list_Nconc(EmptyClauses,
						red_CompleteReductionOnDerivedClauses(Search,
								Derivables, red_ALL, ActBound, BoundMode,
								BoundApplied));
			} else {
				EmptyClauses = list_Nconc(EmptyClauses,
						red_CompleteReductionOnDerivedClauses(Search,
								Derivables, red_WORKEDOFF, ActBound, BoundMode,
								BoundApplied));
			}
			clock_StopAddPassedTime(clock_REDUCTION);

			if (!list_Empty(EmptyClauses)) {
				HighestLevelEmptyClause = split_SmallestSplitLevelClause(
						EmptyClauses);
				if (flag_GetFlagValue(Flags, flag_PEMPTYCLAUSE)) {
					fputs("\nEmptyClause: ", stdout);
					clause_Print(HighestLevelEmptyClause);
				}
			}
			prfs_DecLoops(Search);
		}

		if (ActBound != flag_BOUNDSTARTUNLIMITED && BoundMode
				!= flag_BOUNDMODEUNLIMITED) {
			BoundLoops--;
			if (BoundLoops == flag_BOUNDLOOPSMIN)
				ActBound = flag_BOUNDSTARTUNLIMITED;
			else
				ActBound = *BoundApplied;
			if (*BoundApplied != -1) {
				prfs_SwapIndexes(Search);
				if (flag_GetFlagValue(Flags, flag_PBINC))
					printf("\n\n\t ---- New Clause %s Bound: %2d ----\n",
							(BoundMode == flag_BOUNDMODERESTRICTEDBYDEPTH) ? "Term Depth"
									: "Weight", ActBound);
			}
		}
	}

	prfs_SetEmptyClauses(Search, EmptyClauses);
	prfs_SetUsedEmptyClauses(Search, UsedEmptyClauses);

	return Search;
}

static void top_Flotter(int argc, const char* argv[], LIST InputClauses,
		HASH ClauseToTermLabelList)
/**************************************************************
 INPUT:
 RETURNS: Nothing.
 EFFECT:
 ***************************************************************/
{
	FILE *Output;
	char *description;
	const char *creator = "\n\tCNF generated by FLOTTER " vrs_VERSION " *}";
	int size;
	int creator_size;

	if (argc < opts_Indicator() + 2)
		Output = stdout;
	else
		Output = misc_OpenFile(argv[opts_Indicator() + 1], "w");

	creator_size = (int) strlen(creator);
	size = (int) strlen(dfg_ProblemDescription()) + creator_size;
	description = (char*) memory_Malloc(sizeof(char) * size);
	strncpy(description, dfg_ProblemDescription(), size - creator_size - 3);
	strcpy(description + size - creator_size - 3, creator);

	clause_FPrintCnfDFGProblem(Output, FALSE, dfg_ProblemName(),
			dfg_ProblemAuthor(), dfg_ProblemStatusString(), description,
			InputClauses, NULL, NULL, NULL, ClauseToTermLabelList, FALSE, TRUE);

	fputs("\nFLOTTER needed\t", stdout);
	clock_PrintTime(clock_INPUT);
	puts(" for the input.");
	fputs("\t\t", stdout);
	clock_PrintTime(clock_CNF);
	fputs(" for the  CNF translation.", stdout);

	if (Output != stdout)
		misc_CloseFile(Output, argv[opts_Indicator() + 1]);
	memory_Free(description, sizeof(char) * size);
}

static BOOL top_CalledFlotter(FLAGSTORE Flags, const char* Call) {
	int length;
	BOOL result;
	length = strlen(Call);
	result = string_Equal((Call + (length > 7 ? length - 7 : 0)), "FLOTTER");
	if (result)
		flag_SetFlagValue(Flags, flag_FLOTTER, flag_FLOTTERON);
	return result;
}

static void top_EstablishClAxRelation(LIST ClAxRelation, LIST InputClauses,
		LIST* Labellist, HASH ClauseToTermLabellist, BOOL DocProof)
/**************************************************************
 INPUT:   A list of relations netween clause numbers and formula labels (strings) <ClAxRelation>
 a list of input clauses
 the list of used formula labels
 a hash array relating clauses to formula labels (strings)
 the doc proof flag
 RETURNS: Nothing.
 EFFECT:  If <DocProof> and the <ClAxRelation> is not empty, then the
 list representation of the clause to formula label relation is established
 in the hash array <ClauseToTermLabellist> and the labels are collected in  <Labellist>

 the <ClAxRelation> is eventually deleted
 ***************************************************************/
{
	LIST Scan1, Scan2;
	CLAUSE Clause;

	if (!list_Empty(ClAxRelation)) {
		if (DocProof) {
			for (Scan1 = ClAxRelation; !list_Empty(Scan1); Scan1 = list_Cdr(
					Scan1)) {
				for (Scan2 = InputClauses; !list_Empty(Scan2) && clause_Number(
						(CLAUSE) list_Car(Scan2)) != (int) list_Car(list_Car(
						Scan1)); Scan2 = list_Cdr(Scan2))
					;
				if (list_Empty(Scan2)) {
					misc_StartUserErrorReport();
					misc_UserErrorReport(
							"\n For clause %d a formula relation was defined but the clause was not found in the input file!\n",
							(int) list_Car(list_Car(Scan1)));
					misc_FinishUserErrorReport();
				}
				Clause = (CLAUSE) list_Car(Scan2);
				for (Scan2 = list_Cdr(list_Car(Scan1)); !list_Empty(Scan2); Scan2
						= list_Cdr(Scan2))
					*Labellist = list_Cons(list_Car(Scan2), *Labellist);
				hsh_PutList(ClauseToTermLabellist, Clause, list_Cdr(list_Car(
						Scan1)));
				list_Free(list_Car(Scan1));
			}
			*Labellist = list_PointerDeleteDuplicates(*Labellist);
			for (Scan1 = InputClauses; !list_Empty(Scan1); Scan1 = list_Cdr(
					Scan1))
				if (hsh_Get(ClauseToTermLabellist, list_Car(Scan1)) == NULL) {
					misc_StartUserErrorReport();
					misc_UserErrorReport(
							"\n The formula relation  for clause %d is missing!\n",
							clause_Number((CLAUSE) list_Car(Scan1)));
					misc_FinishUserErrorReport();
				}
		} else {
			for (Scan1 = ClAxRelation; !list_Empty(Scan1); Scan1 = list_Cdr(
					Scan1)) {
				for (Scan2 = list_Cdr(list_Car(Scan1)); !list_Empty(Scan2); Scan2
						= list_Cdr(Scan2))
					string_StringFree((char *) list_Car(Scan2));
				list_Delete(list_Car(Scan1));
			}
		}
		list_Delete(ClAxRelation);
	}
}

// TTQ_NOTE . Ham main cua Spass

/**************************************************************/
/* Main Function                                              */
/**************************************************************/

int main(int argc, const char* argv[]) {
	if (codeUser == TrungTQ) {
		// In cac tham so chay SPASS ra man hinh
		printf("=========== Danh sach tham so cua SPASS ===========\n");
		for (int i = 0; i < argc; i++)
			printf("%s ", argv[i]);
		printf("\n-----------------------\n");


	}

	LIST InputClauses, Scan, Axioms, Conjectures, Sorts, QueryClauses,
			LabelClauses, QueryPair, ProblemClauses, Labellist, Sortlabellist,
			Symblist, UserPrecedence, UserSelection, ClAxRelation;
	PROOFSEARCH Search, FlotterSearch;
	/* <InputFlags> are the flags from the problem file and the command line. */
	FLAGSTORE InputFlags, Flags;
	/* <InputPrecedence> is the precedence after reading the problem file. */
	PRECEDENCE InputPrecedence, Precedence;
	FILE* InputStream;
	HASH TermLabelToClauselist, ClauseToTermLabellist;
	top_SEARCHRESULT Result;
	BOOL NativeClauseInput;

	Search = (PROOFSEARCH) NULL;
	NativeClauseInput = FALSE;

#ifdef SPASS_SIGNALS
	top_PROOFSEARCH = &Search;
	signal(SIGINT, top_SigHandler);
	signal(SIGTERM, top_SigHandler);
	signal(SIGSEGV, top_SigHandler);
	signal(SIGBUS, top_SigHandler);
#endif

	clock_Init();
	clock_StartCounter(clock_OVERALL);
	memory_Init(memory__UNLIMITED);
	atexit(memory_FreeAllMem);
	symbol_Init(TRUE);
	stack_Init();
	hash_Init();
	sort_Init();
	term_Init();

	InputPrecedence = symbol_CreatePrecedence();
	fol_Init(TRUE, InputPrecedence);
	eml_Init(InputPrecedence);
	cont_Init();
	unify_Init();
	flag_Init();
	subs_Init();
	clause_Init();
	red_Init();
	ren_Init();
	dp_Init();
	opts_Init();
	ana_Init();
	cc_Init();
	alarm_Init();

	/* Build proof search object to store definitions in */
	Search = prfs_Create();
	InputFlags = flag_CreateStore();

	/* declare all options */
	opts_DeclareSPASSFlagsAsOptions();
	top_RemoveFileOptId = opts_Declare("rf", opts_NOARGTYPE);

	if (!opts_Read(argc, argv))
		return EXIT_FAILURE;

	/* Check whether flag_STDIN is set in the command line */
	flag_InitStoreByDefaults(InputFlags);
	opts_SetFlags(InputFlags);

	if (argc < opts_Indicator() + 1 && !flag_GetFlagValue(InputFlags,
			flag_STDIN)) {
		/* No input file, no stdin input */
		printf("\n\t          %s %s", argv[0], vrs_VERSION);
		if (top_CalledFlotter(InputFlags, argv[0]) || flag_GetFlagValue(
				InputFlags, flag_FLOTTER))
			puts("\n\t       Usage: FLOTTER [options] [<input-file>] [<output-file>]\n");
		else
			puts("\n\t       Usage: SPASS [options] [<input-file>] \n");
		puts("Possible options:\n");
		opts_PrintSPASSNames();
		return EXIT_FAILURE;
	}
	FlotterSearch = NULL;

	Axioms = Conjectures = Sorts = Labellist = Sortlabellist = UserPrecedence
			= UserSelection = ClAxRelation = list_Nil();

	if (flag_GetFlagValue(InputFlags, flag_STDIN)) {
		/*
		 * TTQ_NOTE . Data Input - Nhap du lieu tu KEYBOARD
		 */
		top_InputFile = (char*) NULL;
		InputStream = stdin;
	} else {
		/*
		 * TTQ_NOTE . Data Input - Nhap du lieu tu File
		 */

		top_InputFile = argv[opts_Indicator()];
		InputStream = misc_OpenFile(top_InputFile, "r");

		if (codeUser == TrungTQ) {
			printf("========= display input file name: %s\n", top_InputFile);
		}
	}

	clock_StartCounter(clock_INPUT);
	flag_CleanStore(InputFlags); /* Mark all flags as unset */

	/* Now add flags from file to InputFlags and set precedence */
	InputClauses = dfg_DFGParser(InputStream, InputFlags, InputPrecedence,
			&Axioms, &Conjectures, &Sorts, &UserPrecedence, &UserSelection,
			&ClAxRelation, &NativeClauseInput);

#ifdef _TRUNGTQ_CODE_

	// Print LABEL & TERM of a FORMULAE
	printf("==========++++++++++++++++++============\n");
	for (Scan = Axioms; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
			LIST current_Axiom = (LIST)list_Car(Scan);

			char* formulae_label = (char*) list_PairFirst(current_Axiom);
			char* mark_string = "Justification";
			printf("Label: %s -", formulae_label);
			printf("\n");

			TERM current_Term = (TERM) list_PairSecond(current_Axiom);
			printf("    Full term: ");
			term_Print(current_Term);
			printf("\n");

			if (strncmp(formulae_label, mark_string, strlen(mark_string)) == 0) {
				/*
				 * Tach va thay the term
				 */
				// tach term
				TERM origin_Term = term_Copy((TERM)term_FirstArgument(current_Term));

				// lay justification
				LIST new_justification = list_Nil();

				LIST old_justification = (LIST)term_ArgumentList((TERM)term_SecondArgument(current_Term));
				for (LIST new_scan = old_justification; !list_Empty(new_scan); new_scan = list_Cdr(new_scan)) {
					TERM justification = list_Car(new_scan);
					printf(" -- just: ");
					term_Print(justification);
					printf("\n");
					new_justification = list_Cons(term_Copy(justification), new_justification);
				}

				// ghep justification vao term
				term_RplacJustificationList(origin_Term, new_justification);

				term_Delete(current_Term);

				// thay the term thu dc vao list
				list_Rplacd(current_Axiom, (LIST)origin_Term);
				// tach va thay the label
				list_Rplaca(current_Axiom, "remove_justified_literals");

				current_Term = (TERM) list_PairSecond(current_Axiom);

				printf("    Edited term: ");
				term_Print(origin_Term);
				printf("\n");
			}
	}


	// Print Axiom
		printf("==========++++Axiom+++++============\n");
		for (Scan = Axioms; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
				LIST current_Axiom = (LIST)list_Car(Scan);



				TERM current_Term = (TERM) list_PairSecond(current_Axiom);
				printf("    Full term: ");
				term_Print(current_Term);
				printf("\n");

		}
#endif


	for (Scan = UserSelection; !list_Empty(Scan); Scan = list_Cdr(Scan))
		symbol_AddProperty((SYMBOL) list_Car(Scan), SELECTED);

	/* Add/overwrite with command line flags */
	opts_SetFlags(InputFlags);
	Flags = prfs_Store(Search);
	Precedence = prfs_Precedence(Search);
	/* The Flags were initialized with the default flag values.  */
	/* This values are now overwritten by command line flags and flags */
	/* from the input file. */
	flag_TransferSetFlags(InputFlags, Flags);
	/* From now on the input flags are not changed! */

	if (flag_GetFlagValue(Flags, flag_TIMELIMIT) != flag_TIMELIMITUNLIMITED)
		alarm_SetAlarm(flag_GetFlagValue(Flags, flag_TIMELIMIT) + 10); /* No race with main loop polling */

	/* Transfer input precedence to search object */
	symbol_TransferPrecedence(InputPrecedence, Precedence);

	/* Complain about missing input clauses/formulae when in */
	/* non-interactive mode */
	if (!flag_GetFlagValue(Flags, flag_INTERACTIVE) && list_Empty(Axioms)
			&& list_Empty(Conjectures) && list_Empty(InputClauses)) {
		misc_StartUserErrorReport();
		misc_UserErrorReport(
				"\n No formulae and clauses found in input file!\n");
		misc_FinishUserErrorReport();
	}

	cnf_Init(Flags); /* Depends on Strong Skolemization Flag */

	/* DocProof is required for interactive mode */
	if (flag_GetFlagValue(Flags, flag_INTERACTIVE)) {
		flag_SetFlagValue(Flags, flag_DOCPROOF, flag_DOCPROOFON);
	}

	if (flag_GetFlagValue(Flags, flag_DOCPROOF))
		prfs_AddDocProofSharingIndex(Search);

	/* Create necessary hasharrays */
	if (flag_GetFlagValue(Flags, flag_DOCPROOF) || top_CalledFlotter(Flags,
			argv[0]) || flag_GetFlagValue(Flags, flag_FLOTTER)) {
		TermLabelToClauselist = hsh_Create();
		ClauseToTermLabellist = hsh_Create();
	} else {
		TermLabelToClauselist = NULL;
		ClauseToTermLabellist = NULL;
	}


	/* Establish clause to term (formula) labels in case of doc proof */
	top_EstablishClAxRelation(ClAxRelation, InputClauses, &Labellist,
			ClauseToTermLabellist, flag_GetFlagValue(Flags, flag_DOCPROOF));

	/* Build conjecture formula and negate it: Conjectures are taken disjunctively!!*/
	for (Scan = Conjectures; !list_Empty(Scan); Scan = list_Cdr(Scan))
		list_Rplacd(list_Car(Scan), (LIST) term_Create(fol_Not(), list_List(
				list_PairSecond(list_Car(Scan)))));

	clock_StopPassedTime(clock_INPUT);

	if (top_InputFile) {
		misc_CloseFile(InputStream, top_InputFile);
		if (opts_IsSet(top_RemoveFileOptId))
			remove(top_InputFile);
	}

	clock_StartCounter(clock_CNF);

	// Neu doc InputClauses tu file thi tai buoc nay InputClauses co the van Empty
	if (list_Empty(InputClauses)) {
		NAT Termcount;

		Termcount = 0;

		//TTQ_COMMENT . Axioms nay chua cap <Label - term> cua 1 formula

		/* Create labels for formulae without them */
		for (Scan = Axioms; !list_Empty(Scan); Scan = list_Cdr(Scan), Termcount++) {

			if (list_PairFirst(list_Car(Scan)) == NULL) {
				char L[100];
				char* Label;
				sprintf(L, "axiom%d", Termcount);
				Label = string_StringCopy(L);
				list_Rplaca(list_Car(Scan), Label);
				if (flag_GetFlagValue(Flags, flag_DOCPROOF)
						&& flag_GetFlagValue(Flags, flag_PLABELS)) {
					printf("\nAdded label %s for axiom \n", Label);
					fol_PrettyPrintDFG((TERM) list_PairSecond(list_Car(Scan)));
				}
			}
		}
		Termcount = 0;
		for (Scan = Sorts; !list_Empty(Scan); Scan = list_Cdr(Scan), Termcount++) {
			char L[100];
			char* Label;
			sprintf(L, "declaration%d", Termcount);
			Label = string_StringCopy(L);
			list_Rplaca(list_Car(Scan), Label);
			if (flag_GetFlagValue(Flags, flag_DOCPROOF) && flag_GetFlagValue(
					Flags, flag_PLABELS)) {
				printf("\nAdded label %s for declaration \n", Label);
				fol_PrettyPrintDFG((TERM) list_PairSecond(list_Car(Scan)));
			}
			Sortlabellist = list_Cons(Label, Sortlabellist);
		}
		Axioms = list_Nconc(Axioms, Sorts);

		if (flag_GetFlagValue(Flags, flag_EML)) {
			clock_StartCounter(clock_TRANSL);

			/* Reduce EML special formulae to first-order logic */
			if (flag_GetFlagValue(Flags, flag_EML)) {
				eml_TranslateToFolMain(&Axioms, &Conjectures,
						flag_GetFlagValue(Flags, flag_INTERACTIVE), Flags,
						Precedence);
			}

			clock_StopPassedTime(clock_TRANSL);
		}



		if (flag_GetFlagValue(Flags, flag_APPLYDEFS) != flag_APPLYDEFSOFF) {
			def_ExtractDefsFromTermlist(Search, Axioms, Conjectures);
			Conjectures = def_ApplyDefinitionToTermList(
					prfs_Definitions(Search), Conjectures, Flags, Precedence);
		}

		/* We must keep the list of symbols because they can't be freed in cnf_Flotter */
		Symblist = list_Nil();

#ifdef _TRUNGTQ_CODE_
/*
 * 		// Print LABEL & TERM of a FORMULAE
		printf("==========++++++++++++++++++============\n");
		for (Scan = Axioms; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
				char* Label = (char*) list_PairFirst((LIST) list_Car(Scan));
				printf("Label: %s -", Label);
				TERM ConTerm = (TERM) list_PairSecond((LIST) list_Car(Scan));
				term_Print(ConTerm);
				printf("\n");
			}
*/
#endif


		/* Axioms is list of pairs, conjectures is list of terms */
		/* A ProofSearch object is only returned and the symbols kept in Symblist
		 if flag_INTERACTIVE is set */
		FlotterSearch = cnf_Flotter(Axioms, Conjectures, &InputClauses,
				&Labellist, TermLabelToClauselist, ClauseToTermLabellist,
				Flags, Precedence, &Symblist);

		/*
		 * TTQ_NOTE . Tinh duoc InputClauses sau  buoc nay
		 */
		InputClauses = clause_ListSortWeighed(InputClauses);

//		if (codeUser == TrungTQ) {
//			printf("============== begin print Input clauses\n");
//			for (int ii = 1; ii <= list_Length(InputClauses); ii++) {
//				printf("== clause %d:\n", ii);
//				CLAUSE tempClause = list_NthElement(InputClauses, ii );
//				if (tempClause != NULL) {
//					LIST lstLit = clause_GetLiteralList(tempClause);
//					for (int jj = 1; jj <= list_Length(lstLit); jj++) {
//						printf("===== literal %d:", jj);
//						LITERAL tempLit = list_NthElement(lstLit, jj);
//						if (tempLit != NULL) {
//							clause_LiteralPrint(tempLit);
//							printf(" --- ");
//							CLAUSE owningClause = clause_LiteralOwningClause(tempLit);
//							clause_Print(owningClause);
//						}
//						printf("\n");
//					}
//				}
//				printf("\n");
//			}
//			printf("============== end\n");
//		}

		clause_SetCounter(1);
		for (Scan = InputClauses; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
			clause_NewNumber(list_Car(Scan));
		}
	} else {
		dfg_DeleteFormulaPairList(Axioms);
		dfg_DeleteFormulaPairList(Sorts);
		dfg_DeleteFormulaPairList(Conjectures);
		if (flag_GetFlagValue(Flags, flag_APPLYDEFS) != flag_APPLYDEFSOFF) {
			/* Extract list of definitions */
			def_ExtractDefsFromClauselist(Search, InputClauses);
			def_FlattenDefinitionsDestructive(Search);
			for (Scan = prfs_Definitions(Search); !list_Empty(Scan); Scan
					= list_Cdr(Scan))
				InputClauses = def_ApplyDefToClauselist(Search, (DEF) list_Car(
						Scan), InputClauses, TRUE);
		}
	}

	clock_StopPassedTime(clock_CNF);

	if (top_CalledFlotter(Flags, argv[0]) || flag_GetFlagValue(Flags,
			flag_FLOTTER)) {
		top_Flotter(argc, argv, InputClauses, ClauseToTermLabellist);
		flag_SetFlagValue(Flags, flag_TIMELIMIT, 0); /* Exit No Output */
		flag_SetFlagValue(Flags, flag_INTERACTIVE, flag_INTERACTIVEOFF);
		flag_SetFlagValue(Flags, flag_PPROBLEM, flag_PPROBLEMOFF);
	}

	memory_Restrict(flag_GetFlagValue(Flags, flag_MEMORY));
	symbol_SeparateVariableSymbolNames();

	// TTQ_NOTE . vong lap xay dung clauses va chuan bi cho resolution

	do {
		LIST deflist;
		int BoundApplied;
		ProblemClauses = list_Nil(); // TTQ_NOTE . maybe - danh sach cac clause
		LabelClauses = list_Nil();
		Result = top_RESOURCE;

		/*
		 * TTQ_NOTE . Tinh Problem clauses (trong ca doan if-then-else duoi day)
		 */
		if (flag_GetFlagValue(Flags, flag_INTERACTIVE)) {
			QueryPair = ia_GetNextRequest(InputStream, Flags);
			/* A pair (<formula,labellist>) */
			/* Get list of clauses derivable from formulae with labels in labellist */
			if (list_Empty(QueryPair)) {
				break;
			}

			for (Scan = list_PairSecond(QueryPair); !list_Empty(Scan); Scan
					= list_Cdr(Scan)) {
				LIST l;
				l = hsh_GetWithCompareFunc(TermLabelToClauselist,
						list_Car(Scan),
						(BOOL(*)(POINTER, POINTER)) cnf_LabelEqual,
						(unsigned long(*)(POINTER)) hsh_StringHashKey);

				l = list_PointerDeleteDuplicates(list_Copy(l));
				LabelClauses = list_Nconc(l, LabelClauses);
			}

			/* Get list of clauses derivable from sorts */
			for (Scan = Sortlabellist; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
				LIST l;
				l = hsh_GetWithCompareFunc(TermLabelToClauselist,
						list_Car(Scan),
						(BOOL(*)(POINTER, POINTER)) cnf_LabelEqual,
						(unsigned long(*)(POINTER)) hsh_StringHashKey);

				l = list_PointerDeleteDuplicates(list_Copy(l));
				LabelClauses = list_Nconc(l, LabelClauses);
			}

			/* For labelclauses copies are introduced */
			/* So an update to the clause to term mapping is necessary */
			for (Scan = LabelClauses; !list_Empty(Scan); Scan = list_Cdr(Scan)) {
				CLAUSE C;
				LIST l;
				C = (CLAUSE) list_Car(Scan);
				l = list_Copy(hsh_Get(ClauseToTermLabellist, C));
				l = cnf_DeleteDuplicateLabelsFromList(l);
				list_Rplaca(Scan, clause_Copy(C));
				hsh_PutList(ClauseToTermLabellist, list_Car(Scan), l);
			}
			QueryClauses = cnf_QueryFlotter(FlotterSearch, list_PairFirst(
					QueryPair), &Symblist);
			ProblemClauses = list_Nconc(QueryClauses, LabelClauses); // TTQ_COMMENT . Tinh ProblemClause tai day

			for (Scan = list_PairSecond(QueryPair); !list_Empty(Scan); Scan
					= list_Cdr(Scan))
				string_StringFree(list_Car(Scan)); /* Free the label strings */
			list_Delete(list_PairSecond(QueryPair));
			list_PairFree(QueryPair);
			clock_InitCounter(clock_OVERALL);
			clock_StartCounter(clock_OVERALL);
		} else {
			ProblemClauses = InputClauses; // TTQ_COMMENT . Tinh ProblemClause tai day
			InputClauses = list_Nil();
		}

		prfs_SetSplitCounter(Search, flag_GetFlagValue(Flags, flag_SPLITS));
		prfs_SetLoops(Search, flag_GetFlagValue(Flags, flag_LOOPS));
		prfs_SetBacktrackedClauses(Search, 0);
		BoundApplied = -1;

		// TTQ_NOTE . top_ProofSearch - SPASS se chay trong ham nay

		Search = top_ProofSearch(Search, ProblemClauses, InputFlags,
				UserPrecedence, &BoundApplied, NativeClauseInput);

		if ((flag_GetFlagValue(Flags, flag_TIMELIMIT)
				== flag_TIMELIMITUNLIMITED || flag_GetFlagValue(Flags,
				flag_TIMELIMIT) > clock_GetSeconds(clock_OVERALL))
				&& prfs_Loops(Search) != 0 && (BoundApplied == -1
				|| !list_Empty(prfs_EmptyClauses(Search)))) {
			if (list_Empty(prfs_EmptyClauses(Search)))
				Result = top_COMPLETION;
			else
				Result = top_PROOF;
		}

		/*
		 * TTQ_COMMENT . TIMELIMIT - Ket thuc chuong trinh
		 */
		if (flag_GetFlagValue(Flags, flag_TIMELIMIT) != 0) {
			/* Stop SPASS immediately */
			alarm_Off();
			printf("\nSPASS %s ", vrs_VERSION);
			fputs("\nSPASS beiseite: ", stdout);
			switch (Result) {
			case top_RESOURCE:
				if (prfs_Loops(Search) != 0)
					fputs("Ran out of time.", stdout);
				else
					fputs("Maximal number of loops exceeded.", stdout);
				break;
			case top_PROOF:
				fputs("Proof found.", stdout);
				break;
			default: /* Completion */
				fputs("Completion found.", stdout);
			}
			printf("\nProblem: %s ",
					(top_InputFile != (char*) NULL ? top_InputFile
							: "Read from stdin."));
			if (flag_GetFlagValue(Flags, flag_PSTATISTIC)) {
				clock_StopPassedTime(clock_OVERALL);
				printf("\nSPASS derived %d clauses,", prfs_DerivedClauses(
						Search));
				printf(" backtracked %d clauses", prfs_BacktrackedClauses(
						Search));
				printf(" and kept %d clauses.", prfs_KeptClauses(Search));
				printf("\nSPASS allocated %lu KBytes.", memory_DemandedBytes()
						/ 1024);
				fputs("\nSPASS spent\t", stdout);
				clock_PrintTime(clock_OVERALL);
				fputs(" on the problem.\n\t\t", stdout);
				clock_PrintTime(clock_INPUT);
				fputs(" for the input.\n\t\t", stdout);
				clock_PrintTime(clock_CNF);
				fputs(" for the FLOTTER CNF translation", stdout);
				if (flag_GetFlagValue(Flags, flag_EML)) {
					fputs(", of which", stdout);
					fputs("\n\t\t", stdout);
					clock_PrintTime(clock_TRANSL);
					fprintf(stdout, " for the translation from %s to FOL",
							flag_Name(flag_EML));
				}
				printf(".");
				printf("\n\t\t");
				clock_PrintTime(clock_INFERENCE);
				fputs(" for inferences.\n\t\t", stdout);
				clock_PrintTime(clock_BACKTRACK);
				fputs(" for the backtracking.\n\t\t", stdout);
				clock_PrintTime(clock_REDUCTION);
				puts(" for the reduction.");
			}
			if (Result != top_PROOF && flag_GetFlagValue(Flags, flag_FPMODEL)
					!= flag_FPMODELOFF) {
				FILE *Output;
				char name[100];
				const char * creator = "{*SPASS " vrs_VERSION " *}";
				BOOL PrintPotProductive;

				strcpy(name, (top_InputFile != (char*) NULL ? top_InputFile
						: "SPASS"));
				if (Result == top_COMPLETION)
					strcat(name, ".model");
				else
					strcat(name, ".clauses");
				Output = misc_OpenFile(name, "w");
				PrintPotProductive = (flag_GetFlagValue(Flags, flag_FPMODEL)
						== flag_FPMODELPOTENTIALLYPRODUCTIVECLAUSES);
				if (Result == top_COMPLETION)
					clause_FPrintCnfDFGProblem(Output, PrintPotProductive,
							"{*Completion_by_SPASS*}", creator, "satisfiable",
							dfg_ProblemDescription(), prfs_WorkedOffClauses(
									Search), list_Nil(), Flags, Precedence,
							NULL, TRUE, TRUE);
				else
					clause_FPrintCnfDFGProblem(Output, PrintPotProductive,
							"{*Clauses_generated_by_SPASS*}", creator,
							"unknown", dfg_ProblemDescription(),
							prfs_WorkedOffClauses(Search), prfs_UsableClauses(
									Search), Flags, Precedence, NULL, FALSE,
							TRUE);
				misc_CloseFile(Output, name);
				if (Result == top_COMPLETION)
					printf("\nCompletion printed to: %s\n", name);
				else
					printf("\nClauses printed to: %s\n", name);
			}

			if (flag_GetFlagValue(Flags, flag_DOCPROOF) && Result
					!= top_RESOURCE) {
				if (Result == top_COMPLETION) {
					puts("\n\n The saturated set of worked-off clauses is :");
					clause_ListPrint(prfs_WorkedOffClauses(Search));
				} else {
					LIST UsedClauses, UsedTerms;
					if (!top_InputFile)
						top_InputFile = "SPASS";
					UsedClauses = dp_PrintProof(Search, prfs_EmptyClauses(
							Search), top_InputFile);
					/* Find terms required for proof */
					UsedTerms = list_Nil();

					for (Scan = UsedClauses; !list_Empty(Scan); Scan
							= list_Cdr(Scan))
						if (clause_IsFromInput((CLAUSE) list_Car(Scan))) {
							LIST L;
							L = hsh_Get(ClauseToTermLabellist, list_Car(Scan));
							L = list_Copy(L);
							L = cnf_DeleteDuplicateLabelsFromList(L);
							UsedTerms = list_Nconc(UsedTerms, L);
						}
					list_Delete(UsedClauses);
					UsedTerms = cnf_DeleteDuplicateLabelsFromList(UsedTerms);
					fputs("\nFormulae used in the proof :", stdout);
					for (Scan = UsedTerms; !list_Empty(Scan); Scan = list_Cdr(
							Scan))
						if (!(strncmp((char*) list_Car(Scan), "_SORT_", 6) == 0))
							printf(" %s", (char*) list_Car(Scan));
					putchar('\n');
					list_Delete(UsedTerms);
				}
			}
		}

		/* Delete mapping for the clause copies of the labelclauses */
		for (Scan = LabelClauses; !list_Empty(Scan); Scan = list_Cdr(Scan))
			hsh_DelItem(ClauseToTermLabellist, list_Car(Scan));

		list_Delete(ProblemClauses);

		fflush(stdout);

		/* Keep definitions */
		deflist = prfs_Definitions(Search);
		prfs_SetDefinitions(Search, list_Nil());
		prfs_Clean(Search);
		prfs_SetDefinitions(Search, deflist);

		symbol_TransferPrecedence(InputPrecedence, Precedence);
		if (flag_GetFlagValue(Flags, flag_PPROBLEM))
			fputs("\n--------------------------SPASS-STOP------------------------------",
					stdout);
	} while (flag_GetFlagValue(Flags, flag_INTERACTIVE) && (flag_GetFlagValue(
			Flags, flag_TIMELIMIT) != 0));

	for (Scan = InputClauses; !list_Empty(Scan); Scan = list_Cdr(Scan))
		clause_OrientAndReInit(list_Car(Scan), Flags, Precedence);

	/* Cleanup Flotter data structures */
	if (flag_GetFlagValue(Flags, flag_INTERACTIVE)) {
		if (flag_GetFlagValue(Flags, flag_DOCPROOF))
			list_Delete(Symblist);
		else
			symbol_DeleteSymbolList(Symblist);
		/*  symbol_ResetSkolemIndex(); */
		if (FlotterSearch != NULL)
			prfs_Delete(FlotterSearch);
	}
	if (flag_GetFlagValue(Flags, flag_PFLAGS)) {
		putchar('\n');
		flag_Print(Flags);
	}
	if (TermLabelToClauselist != (HASH) NULL) {
		hsh_Delete(TermLabelToClauselist);
		hsh_Delete(ClauseToTermLabellist);
	}
	for (Scan = Labellist; !list_Empty(Scan); Scan = list_Cdr(Scan))
		string_StringFree(list_Car(Scan));
	list_Delete(Labellist);
	list_Delete(Sortlabellist);
	list_Delete(UserPrecedence);
	list_Delete(UserSelection);

	cnf_Free(Flags);
	eml_Free();

	prfs_Delete(Search);
	clause_DeleteClauseList(InputClauses);
	flag_DeleteStore(InputFlags);
	symbol_DeletePrecedence(InputPrecedence);

	cc_Free();
	ana_Free();
	sort_Free();
	subs_Free();
	unify_Free();
	cont_Free();
	fol_Free();
	symbol_FreeAllSymbols();
	dfg_Free();
	opts_Free();
#ifdef CHECK
	memory_Print();
	memory_PrintLeaks();
#endif
	putchar('\n');
	return 0;
}
