/* A Bison parser, made by GNU Bison 1.875d.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse dfg_parse
#define yylex   dfg_lex
#define yyerror dfg_error
#define yylval  dfg_lval
#define yychar  dfg_char
#define yydebug dfg_debug
#define yynerrs dfg_nerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DFG_AND = 258,
     DFG_AUTHOR = 259,
     DFG_AXIOMS = 260,
     DFG_BEGPROB = 261,
     DFG_BY = 262,
     DFG_CLAUSE = 263,
     DFG_CLOSEBRACE = 264,
     DFG_CLSLIST = 265,
     DFG_CNF = 266,
     DFG_CONJECS = 267,
     DFG_DATE = 268,
     DFG_DECLLIST = 269,
     DFG_DESC = 270,
     DFG_DESCLIST = 271,
     DFG_DNF = 272,
     DFG_DOMPRED = 273,
     DFG_ENDLIST = 274,
     DFG_ENDPROB = 275,
     DFG_EQUAL = 276,
     DFG_EQUIV = 277,
     DFG_EXISTS = 278,
     DFG_FALSE = 279,
     DFG_FORMLIST = 280,
     DFG_FORMULA = 281,
     DFG_FORALL = 282,
     DFG_FREELY = 283,
     DFG_FUNC = 284,
     DFG_GENERATED = 285,
     DFG_GENSET = 286,
     DFG_HYPOTH = 287,
     DFG_IMPLIED = 288,
     DFG_IMPLIES = 289,
     DFG_LOGIC = 290,
     DFG_NAME = 291,
     DFG_NOT = 292,
     DFG_OPENBRACE = 293,
     DFG_OPERAT = 294,
     DFG_OR = 295,
     DFG_PREC = 296,
     DFG_CLFORE = 297,
     DFG_PRED = 298,
     DFG_PRDICAT = 299,
     DFG_PRFLIST = 300,
     DFG_QUANTIF = 301,
     DFG_SATIS = 302,
     DFG_SELECT = 303,
     DFG_SETFLAG = 304,
     DFG_SETTINGS = 305,
     DFG_SYMLIST = 306,
     DFG_SORT = 307,
     DFG_SORTS = 308,
     DFG_STATUS = 309,
     DFG_STEP = 310,
     DFG_SUBSORT = 311,
     DFG_TERMLIST = 312,
     DFG_TRUE = 313,
     DFG_UNKNOWN = 314,
     DFG_UNSATIS = 315,
     DFG_VERSION = 316,
     DFG_END_OF_CONSTRAINT_LITERALS = 317,
     DFG_END_OF_ANTECEDENT_LITERALS = 318,
     DFG_LITERAL_IS_SELECTED = 319,
     DFG_EML = 320,
     DFG_PROP_FORMULA = 321,
     DFG_REL_FORMULA = 322,
     DFG_SPECIALFORMLIST = 323,
     DFG_TRANSLPAIRS = 324,
     DFG_BOX = 325,
     DFG_DIA = 326,
     DFG_TEST = 327,
     DFG_DOMAIN = 328,
     DFG_RANGE = 329,
     DFG_COMP = 330,
     DFG_SUM = 331,
     DFG_CONV = 332,
     DFG_IDENTITY = 333,
     DFG_DIVERSITY = 334,
     DFG_DOMRESTR = 335,
     DFG_RANRESTR = 336,
     DFG_NUM = 337,
     DFG_MINUS1 = 338,
     DFG_ID = 339,
     DFG_TEXT = 340
   };
#endif
#define DFG_AND 258
#define DFG_AUTHOR 259
#define DFG_AXIOMS 260
#define DFG_BEGPROB 261
#define DFG_BY 262
#define DFG_CLAUSE 263
#define DFG_CLOSEBRACE 264
#define DFG_CLSLIST 265
#define DFG_CNF 266
#define DFG_CONJECS 267
#define DFG_DATE 268
#define DFG_DECLLIST 269
#define DFG_DESC 270
#define DFG_DESCLIST 271
#define DFG_DNF 272
#define DFG_DOMPRED 273
#define DFG_ENDLIST 274
#define DFG_ENDPROB 275
#define DFG_EQUAL 276
#define DFG_EQUIV 277
#define DFG_EXISTS 278
#define DFG_FALSE 279
#define DFG_FORMLIST 280
#define DFG_FORMULA 281
#define DFG_FORALL 282
#define DFG_FREELY 283
#define DFG_FUNC 284
#define DFG_GENERATED 285
#define DFG_GENSET 286
#define DFG_HYPOTH 287
#define DFG_IMPLIED 288
#define DFG_IMPLIES 289
#define DFG_LOGIC 290
#define DFG_NAME 291
#define DFG_NOT 292
#define DFG_OPENBRACE 293
#define DFG_OPERAT 294
#define DFG_OR 295
#define DFG_PREC 296
#define DFG_CLFORE 297
#define DFG_PRED 298
#define DFG_PRDICAT 299
#define DFG_PRFLIST 300
#define DFG_QUANTIF 301
#define DFG_SATIS 302
#define DFG_SELECT 303
#define DFG_SETFLAG 304
#define DFG_SETTINGS 305
#define DFG_SYMLIST 306
#define DFG_SORT 307
#define DFG_SORTS 308
#define DFG_STATUS 309
#define DFG_STEP 310
#define DFG_SUBSORT 311
#define DFG_TERMLIST 312
#define DFG_TRUE 313
#define DFG_UNKNOWN 314
#define DFG_UNSATIS 315
#define DFG_VERSION 316
#define DFG_END_OF_CONSTRAINT_LITERALS 317
#define DFG_END_OF_ANTECEDENT_LITERALS 318
#define DFG_LITERAL_IS_SELECTED 319
#define DFG_EML 320
#define DFG_PROP_FORMULA 321
#define DFG_REL_FORMULA 322
#define DFG_SPECIALFORMLIST 323
#define DFG_TRANSLPAIRS 324
#define DFG_BOX 325
#define DFG_DIA 326
#define DFG_TEST 327
#define DFG_DOMAIN 328
#define DFG_RANGE 329
#define DFG_COMP 330
#define DFG_SUM 331
#define DFG_CONV 332
#define DFG_IDENTITY 333
#define DFG_DIVERSITY 334
#define DFG_DOMRESTR 335
#define DFG_RANRESTR 336
#define DFG_NUM 337
#define DFG_MINUS1 338
#define DFG_ID 339
#define DFG_TEXT 340




/* Copy the first part of user declarations.  */
#line 48 "dfgparser.y"


#include <ctype.h>
#include "dfg.h"
#include "symbol.h"
#include "term.h"
#include "foldfg.h"
#include "strings.h"
#include "eml.h"
#include "../usercode/user-defined.h"

/* Used for the texts from description section. */
typedef struct {
  char*     name;
  char*     author;
  char*     version;
  char*     logic;
  DFG_STATE status;
  char*     description;
  char*     date;
} DFG_DESCRIPTIONTYPE;

/* Used for delayed parsing of plain clauses */
typedef struct {
  LIST constraint;
  LIST antecedent;
  LIST succedent;

#ifdef _TRUNGTQ_CODE_

  LIST justified;

#endif

  TERM selected;
} DFG_PLAINCLAUSEHELP, *DFG_PLAINCLAUSE;

static DFG_DESCRIPTIONTYPE dfg_DESC;
static LIST                dfg_AXIOMLIST;
static LIST                dfg_CONJECLIST;
static LIST                dfg_SORTDECLLIST;
/* symbol precedence explicitly defined by user */
static LIST                dfg_USERPRECEDENCE;
static LIST                dfg_USERSELECTION;
static LIST                dfg_CLAXRELATION;
static LIST                dfg_CLAXAXIOMS;
static LIST                dfg_AXCLAUSES;
static LIST                dfg_CONCLAUSES;
static LIST                dfg_PROOFLIST;     /* list_of_proofs */
static LIST                dfg_TERMLIST;      /* list_of_terms  */
static LIST                dfg_PLAINAXCLAUSES; /* list of DFG_PLAINCLAUSE */
static LIST                dfg_PLAINCONCLAUSES; /* list of DFG_PLAINCLAUSE */
static LIST                dfg_TEMPPLAINCLAUSES; /* temporal list of DFG_PlAINCLAUSE, until they are concatenated to dfg_PLAINAXCLAUSES or dfg_PLAINCONCLAUSES */
static TERM                dfg_SELECTED_LITERAL; /* last selected literal */
static BOOL                dfg_IGNORE;      /* tokens are ignored while TRUE */
static FLAGSTORE           dfg_FLAGS;
static PRECEDENCE          dfg_PRECEDENCE;

/* used also in the scanner */
NAT                        dfg_LINENUMBER;
BOOL			   dfg_IGNORETEXT;

void yyerror(const char*);
int  yylex(void);		/* Defined in dfgscanner.l */

static void   dfg_SymbolDecl(int, char*, int);
static SYMBOL dfg_Symbol(char*, NAT);
static void   dfg_SubSort(char*, char*);
static void   dfg_SymbolGenerated(SYMBOL, BOOL, LIST);
static void   dfg_TranslPairDecl(char*, char*);

static __inline__ TERM dfg_TermCreate(char* Name, LIST Arguments)
/***************************************************************
  INPUT:   A string <Name> and a list of terms <Arguments>.
  RETURNS: Does a symbol lookup for <Name> and creates out of
           the found or otherwise created new symbol and <Arguments>
           a new term.
  CAUTION: Deletes the string <Name>.
***************************************************************/
{
  SYMBOL s;
  NAT    arity;
  arity = list_Length(Arguments);
  s = dfg_Symbol(Name, arity); /* Frees the string */
  if (!symbol_IsVariable(s) && !symbol_IsFunction(s)) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("\n Line %d: is not a function.\n", dfg_LINENUMBER);
    misc_FinishUserErrorReport();
  }
  return term_Create(s, Arguments);
}

static __inline__ TERM dfg_AtomCreate(char* Name, LIST Arguments)
/* Look up the symbol, check its arity and create the atom term */
{
  SYMBOL s;
  s = dfg_Symbol(Name, list_Length(Arguments)); /* Frees the string */
  if (symbol_IsVariable(s) || !symbol_IsPredicate(s)) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("\n Line %d: Symbol is not a predicate.\n", dfg_LINENUMBER);
    misc_FinishUserErrorReport();
  }
  return term_Create(s, Arguments);
}

static __inline__ void dfg_DeleteStringList(LIST List)
{
  list_DeleteWithElement(List, (void (*)(POINTER)) string_StringFree);
}

/**************************************************************/
/* Functions that handle symbols with unspecified arity       */
/**************************************************************/

/* The symbol list holds all symbols whose arity wasn't       */
/* specified in the symbol declaration section.               */
/* If the arity of a symbol was not specified in this section */
/* it is first set to 0. If the symbol occurs with always the */
/* same arity 'A' the arity of this symbol is set to 'A'.     */
static LIST   dfg_SYMBOLLIST;

static void dfg_SymAdd(SYMBOL);
static void dfg_SymCheck(SYMBOL, NAT);
static void dfg_SymCleanUp(void);

/**************************************************************/
/* Functions that handle variable names                       */
/**************************************************************/

/* List of quantified variables in the current input formula. */
/* This list is used to find symbols that by mistake weren't  */
/* declared in the symbol declaration section                 */
/* --> free variables                                         */
/* This is a list of lists, since each time a quantifier is   */
/* reached, a new list is added to the global list.           */
static LIST dfg_VARLIST;
static BOOL dfg_VARDECL;

static void   dfg_VarStart(void);
static void   dfg_VarStop(void);
static void   dfg_VarBacktrack(void);
static void   dfg_VarCheck(void);
static SYMBOL dfg_VarLookup(char*);
static DFG_PLAINCLAUSE dfg_PlainClauseCreate(void);
static void dfg_PlainClauseFree(DFG_PLAINCLAUSE Clause);

/*
#define DEBUG_PARSER
*/
#ifdef DEBUG_PARSER
#define YYERROR_VERBOSE
#define YYDEBUG 1000

dfg_debug = 1;
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 197 "dfgparser.y"
typedef union YYSTYPE {
  int       number;
  char*     string;
  SYMBOL    symbol;
  SPROPERTY property;
  TERM      term;
  LIST      list;
  DFG_STATE state;
  BOOL      bool;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 415 "dfgparser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 427 "dfgparser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   757

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  124
/* YYNRULES -- Number of rules. */
#define YYNRULES  266
/* YYNRULES -- Number of states. */
#define YYNSTATES  641

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      86,    87,     2,     2,    91,     2,    88,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    92,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,    90,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,    14,    26,    32,    38,    44,    50,    51,
      57,    58,    64,    65,    71,    73,    75,    77,    85,    86,
      97,    98,   104,   106,   110,   112,   118,   119,   125,   127,
     131,   133,   139,   140,   146,   148,   152,   153,   159,   161,
     165,   167,   173,   174,   180,   182,   186,   188,   194,   196,
     198,   199,   205,   207,   211,   212,   218,   219,   225,   226,
     229,   231,   239,   242,   250,   251,   252,   264,   274,   275,
     277,   279,   283,   285,   289,   298,   300,   302,   303,   306,
     307,   315,   316,   319,   321,   326,   333,   338,   339,   340,
     351,   352,   354,   356,   360,   362,   364,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   390,
     394,   396,   401,   412,   413,   416,   417,   425,   433,   441,
     442,   444,   445,   447,   449,   453,   455,   459,   461,   463,
     465,   470,   475,   480,   487,   492,   499,   501,   503,   505,
     510,   512,   514,   519,   524,   531,   538,   545,   550,   552,
     554,   556,   558,   560,   562,   563,   566,   577,   578,   590,
     591,   599,   600,   602,   603,   604,   612,   614,   615,   616,
     627,   632,   633,   635,   639,   640,   643,   644,   647,   651,
     653,   658,   660,   664,   666,   668,   670,   677,   682,   683,
     691,   692,   694,   696,   705,   710,   712,   717,   719,   723,
     724,   727,   728,   738,   739,   755,   757,   761,   762,   767,
     771,   777,   778,   782,   784,   786,   788,   790,   792,   794,
     796,   798,   800,   801,   805,   813,   815,   817,   818,   821,
     822,   829,   830,   834,   835,   838,   844,   845,   855,   857,
     861,   862,   866,   871,   876,   881,   886,   893,   895,   899,
     901,   908,   910,   914,   920,   922,   926,   928,   930,   934,
     936,   937,   940,   942,   945,   951,   953
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
      94,     0,    -1,     6,    86,   146,    87,    88,    95,   104,
     199,    20,    88,    -1,    16,    88,    96,    97,   100,   101,
      98,    99,   102,    19,    88,    -1,    36,    86,    85,    87,
      88,    -1,     4,    86,    85,    87,    88,    -1,    54,    86,
     103,    87,    88,    -1,    15,    86,    85,    87,    88,    -1,
      -1,    61,    86,    85,    87,    88,    -1,    -1,    35,    86,
      85,    87,    88,    -1,    -1,    13,    86,    85,    87,    88,
      -1,    47,    -1,    60,    -1,    59,    -1,   105,   124,   135,
     150,   160,   183,   195,    -1,    -1,    51,    88,   106,   109,
     112,   114,   117,   121,    19,    88,    -1,    -1,    29,    89,
     107,    90,    88,    -1,   108,    -1,   107,    91,   108,    -1,
     146,    -1,    86,   146,    91,   120,    87,    -1,    -1,    44,
      89,   110,    90,    88,    -1,   111,    -1,   110,    91,   111,
      -1,   146,    -1,    86,   146,    91,   120,    87,    -1,    -1,
      53,    89,   113,    90,    88,    -1,   146,    -1,   113,    91,
     146,    -1,    -1,    39,    89,   115,    90,    88,    -1,   116,
      -1,   115,    91,   116,    -1,   146,    -1,    86,   146,    91,
     120,    87,    -1,    -1,    46,    89,   118,    90,    88,    -1,
     119,    -1,   118,    91,   119,    -1,   146,    -1,    86,   146,
      91,   120,    87,    -1,    83,    -1,    82,    -1,    -1,    69,
      89,   122,    90,    88,    -1,   123,    -1,   122,    91,   123,
      -1,    -1,    86,   146,    91,   146,    87,    -1,    -1,    14,
      88,   125,    19,    88,    -1,    -1,   125,   126,    -1,   129,
      -1,    56,    86,   146,    91,   146,    87,    88,    -1,   176,
      88,    -1,    43,    86,   146,    91,   132,    87,    88,    -1,
      -1,    -1,    27,    86,    89,   127,   147,   128,    90,    91,
     176,    87,    88,    -1,    52,   146,   130,    30,     7,    89,
     131,    90,    88,    -1,    -1,    28,    -1,   146,    -1,   131,
      91,   146,    -1,   146,    -1,   132,    91,   146,    -1,    25,
      86,   134,    87,    88,   136,    19,    88,    -1,     5,    -1,
      12,    -1,    -1,   135,   133,    -1,    -1,   136,    26,    86,
     141,   137,    87,    88,    -1,    -1,    91,   146,    -1,   176,
      -1,    37,    86,   138,    87,    -1,   143,    86,   138,    91,
     138,    87,    -1,   144,    86,   142,    87,    -1,    -1,    -1,
     145,    86,    89,   139,   147,   140,    90,    91,   138,    87,
      -1,    -1,   138,    -1,   138,    -1,   142,    91,   138,    -1,
      22,    -1,    33,    -1,    34,    -1,     3,    -1,    40,    -1,
      23,    -1,    27,    -1,    84,    -1,    82,    -1,    49,    -1,
      18,    -1,    41,    -1,    42,    -1,    48,    -1,   148,    -1,
     147,    91,   148,    -1,   146,    -1,   146,    86,   146,    87,
      -1,    68,    86,   134,    91,    65,    87,    88,   151,    19,
      88,    -1,    -1,   150,   149,    -1,    -1,   151,    26,    86,
     141,   137,    87,    88,    -1,   151,    66,    86,   152,   137,
      87,    88,    -1,   151,    67,    86,   153,   137,    87,    88,
      -1,    -1,   156,    -1,    -1,   157,    -1,   156,    -1,   154,
      91,   156,    -1,   157,    -1,   155,    91,   157,    -1,   146,
      -1,    58,    -1,    24,    -1,    37,    86,   156,    87,    -1,
      73,    86,   157,    87,    -1,    74,    86,   157,    87,    -1,
     143,    86,   156,    91,   156,    87,    -1,   144,    86,   154,
      87,    -1,   158,    86,   157,    91,   156,    87,    -1,   146,
      -1,    58,    -1,    24,    -1,    37,    86,   157,    87,    -1,
      78,    -1,    79,    -1,    77,    86,   157,    87,    -1,    72,
      86,   156,    87,    -1,    80,    86,   157,    91,   156,    87,
      -1,    81,    86,   157,    91,   156,    87,    -1,   143,    86,
     157,    91,   157,    87,    -1,   159,    86,   155,    87,    -1,
      70,    -1,    71,    -1,     3,    -1,    40,    -1,    75,    -1,
      76,    -1,    -1,   160,   161,    -1,    10,    86,   134,    91,
      11,    87,    88,   163,    19,    88,    -1,    -1,    10,    86,
     134,    91,    17,    87,    88,   162,   177,    19,    88,    -1,
      -1,   163,     8,    86,   164,   137,    87,    88,    -1,    -1,
     167,    -1,    -1,    -1,   165,   172,    62,   173,    63,   172,
     166,    -1,   170,    -1,    -1,    -1,    27,    86,    89,   168,
     147,   169,    90,    91,   170,    87,    -1,    40,    86,   171,
      87,    -1,    -1,   174,    -1,   171,    91,   174,    -1,    -1,
     172,   174,    -1,    -1,   173,   174,    -1,   173,   174,    64,
      -1,   176,    -1,    37,    86,   176,    87,    -1,   176,    -1,
     175,    91,   176,    -1,   146,    -1,    58,    -1,    24,    -1,
      21,    86,   181,    91,   181,    87,    -1,   146,    86,   182,
      87,    -1,    -1,   177,     8,    86,   178,   137,    87,    88,
      -1,    -1,   179,    -1,   180,    -1,    23,    86,    89,   175,
      90,    91,   180,    87,    -1,     3,    86,   171,    87,    -1,
     146,    -1,   146,    86,   182,    87,    -1,   181,    -1,   182,
      91,   181,    -1,    -1,   183,   184,    -1,    -1,    45,    86,
     146,    87,    88,   185,   186,    19,    88,    -1,    -1,   186,
      55,    86,   190,    91,   194,    91,   146,    91,    89,   187,
      90,   188,    87,    88,    -1,   190,    -1,   187,    91,   190,
      -1,    -1,    91,    89,   189,    90,    -1,   190,    92,   190,
      -1,   189,    91,   190,    92,   190,    -1,    -1,   192,   191,
     193,    -1,   146,    -1,    37,    -1,    22,    -1,    33,    -1,
      34,    -1,     3,    -1,    40,    -1,    27,    -1,    23,    -1,
      -1,    86,   142,    87,    -1,    86,    89,   147,    90,    91,
     138,    87,    -1,   167,    -1,   179,    -1,    -1,   195,   196,
      -1,    -1,    57,    88,   197,   198,    19,    88,    -1,    -1,
     198,   181,    88,    -1,    -1,   199,   200,    -1,    31,    88,
     214,    19,    88,    -1,    -1,    50,    86,   146,   201,    87,
      88,   202,    19,    88,    -1,    85,    -1,    38,   203,     9,
      -1,    -1,   203,   204,    88,    -1,    41,    86,   205,    87,
      -1,    48,    86,   211,    87,    -1,    42,    86,   207,    87,
      -1,    18,    86,   216,    87,    -1,    49,    86,    84,    91,
     120,    87,    -1,   206,    -1,   205,    91,   206,    -1,   146,
      -1,    86,   146,    91,    82,   213,    87,    -1,   208,    -1,
     207,    91,   208,    -1,    86,    82,    91,   209,    87,    -1,
     210,    -1,   209,    91,   210,    -1,   146,    -1,   212,    -1,
     211,    91,   212,    -1,   146,    -1,    -1,    91,    84,    -1,
     215,    -1,   214,   215,    -1,    32,    89,   216,    90,    88,
      -1,   146,    -1,   216,    91,   146,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   252,   252,   264,   275,   279,   283,   287,   291,   292,
     296,   297,   301,   302,   306,   307,   308,   315,   328,   329,
     339,   340,   343,   344,   347,   348,   352,   353,   356,   357,
     360,   361,   364,   365,   368,   369,   372,   373,   376,   377,
     380,   381,   384,   385,   388,   389,   392,   393,   396,   397,
     400,   401,   404,   405,   408,   408,   415,   416,   421,   422,
     425,   426,   428,   429,   431,   432,   431,   441,   445,   446,
     449,   450,   453,   454,   461,   471,   472,   475,   476,   479,
     480,   494,   495,   498,   499,   501,   503,   505,   506,   505,
     513,   514,   517,   519,   523,   524,   525,   528,   529,   532,
     533,   536,   542,   544,   546,   548,   550,   552,   556,   558,
     562,   573,   597,   608,   609,   612,   613,   626,   638,   654,
     655,   658,   659,   666,   667,   670,   671,   674,   676,   678,
     680,   682,   684,   686,   688,   690,   694,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   714,   716,   720,   721,
     724,   725,   726,   727,   735,   736,   739,   761,   760,   767,
     768,   782,   783,   784,   784,   784,   802,   803,   804,   803,
     811,   815,   816,   818,   822,   823,   827,   828,   830,   845,
     846,   850,   851,   854,   856,   858,   860,   862,   869,   870,
     873,   874,   877,   878,   881,   888,   890,   894,   896,   904,
     905,   909,   908,   922,   923,   944,   946,   951,   952,   955,
     963,   974,   973,   985,   986,   987,   988,   989,   990,   991,
     992,   993,   996,   997,   998,  1001,  1002,  1010,  1011,  1014,
    1014,  1021,  1022,  1029,  1030,  1033,  1034,  1034,  1042,  1045,
    1048,  1049,  1052,  1053,  1054,  1055,  1075,  1087,  1088,  1091,
    1103,  1120,  1121,  1124,  1131,  1132,  1135,  1141,  1142,  1145,
    1164,  1165,  1182,  1183,  1186,  1190,  1191
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DFG_AND", "DFG_AUTHOR", "DFG_AXIOMS",
  "DFG_BEGPROB", "DFG_BY", "DFG_CLAUSE", "DFG_CLOSEBRACE", "DFG_CLSLIST",
  "DFG_CNF", "DFG_CONJECS", "DFG_DATE", "DFG_DECLLIST", "DFG_DESC",
  "DFG_DESCLIST", "DFG_DNF", "DFG_DOMPRED", "DFG_ENDLIST", "DFG_ENDPROB",
  "DFG_EQUAL", "DFG_EQUIV", "DFG_EXISTS", "DFG_FALSE", "DFG_FORMLIST",
  "DFG_FORMULA", "DFG_FORALL", "DFG_FREELY", "DFG_FUNC", "DFG_GENERATED",
  "DFG_GENSET", "DFG_HYPOTH", "DFG_IMPLIED", "DFG_IMPLIES", "DFG_LOGIC",
  "DFG_NAME", "DFG_NOT", "DFG_OPENBRACE", "DFG_OPERAT", "DFG_OR",
  "DFG_PREC", "DFG_CLFORE", "DFG_PRED", "DFG_PRDICAT", "DFG_PRFLIST",
  "DFG_QUANTIF", "DFG_SATIS", "DFG_SELECT", "DFG_SETFLAG", "DFG_SETTINGS",
  "DFG_SYMLIST", "DFG_SORT", "DFG_SORTS", "DFG_STATUS", "DFG_STEP",
  "DFG_SUBSORT", "DFG_TERMLIST", "DFG_TRUE", "DFG_UNKNOWN", "DFG_UNSATIS",
  "DFG_VERSION", "DFG_END_OF_CONSTRAINT_LITERALS",
  "DFG_END_OF_ANTECEDENT_LITERALS", "DFG_LITERAL_IS_SELECTED", "DFG_EML",
  "DFG_PROP_FORMULA", "DFG_REL_FORMULA", "DFG_SPECIALFORMLIST",
  "DFG_TRANSLPAIRS", "DFG_BOX", "DFG_DIA", "DFG_TEST", "DFG_DOMAIN",
  "DFG_RANGE", "DFG_COMP", "DFG_SUM", "DFG_CONV", "DFG_IDENTITY",
  "DFG_DIVERSITY", "DFG_DOMRESTR", "DFG_RANRESTR", "DFG_NUM", "DFG_MINUS1",
  "DFG_ID", "DFG_TEXT", "'('", "')'", "'.'", "'['", "']'", "','", "':'",
  "$accept", "problem", "description", "name", "author", "status",
  "desctext", "versionopt", "logicopt", "dateopt", "log_state",
  "logicalpart", "symbollistopt", "functionsopt", "functionlist", "func",
  "predicatesopt", "predicatelist", "pred", "sortsopt", "sortlist",
  "operatorsopt", "operatorlist", "op", "quantifiersopt", "quantifierlist",
  "quant", "number", "translpairsopt", "translpairlist", "translpair",
  "declarationlistopt", "decllistopt", "decl", "@1", "@2", "gendecl",
  "freelyopt", "funclist", "sortdecl", "formulalist", "origin",
  "formulalistsopt", "formulalistopt", "labelopt", "formula", "@3", "@4",
  "formulaopt", "arglist", "binsymbol", "nsymbol", "quantsymbol", "id",
  "qtermlist", "qterm", "specialformulalist", "specialformulalistsopt",
  "specialformulalistopt", "propformulaopt", "relformulaopt",
  "proparglist", "relarglist", "propformula", "relformula",
  "relpropbinsymbol", "relnsymbol", "clauselistsopt", "clauselist", "@5",
  "cnfclausesopt", "cnfclauseopt", "@6", "@7", "cnfclause", "@8", "@9",
  "cnfclausebody", "litlist", "litlist_ws", "selected_litlist_ws", "lit",
  "atomlist", "atom", "dnfclausesopt", "dnfclauseopt", "dnfclause",
  "dnfclausebody", "term", "termlist", "prooflistsopt", "prooflist", "@10",
  "prooflistopt", "parentlist", "assoclistopt", "assoclist",
  "id_or_formula", "@11", "anysymbol", "optargs", "clause",
  "listOfTermsopt", "listOfTerms", "@12", "terms", "settinglistsopt",
  "settinglist", "@13", "flags", "spassflags", "spassflag", "preclist",
  "precitem", "clfolist", "clfoitem", "clfoaxseq", "clfoaxseqitem",
  "selectlist", "selectitem", "statopt", "gsettings", "gsetting",
  "labellist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,    40,    41,    46,    91,
      93,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    93,    94,    95,    96,    97,    98,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   103,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   126,   127,   128,   126,   129,   130,   130,
     131,   131,   132,   132,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   138,   138,   138,   138,   139,   140,   138,
     141,   141,   142,   142,   143,   143,   143,   144,   144,   145,
     145,   146,   146,   146,   146,   146,   146,   146,   147,   147,
     148,   148,   149,   150,   150,   151,   151,   151,   151,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   158,   158,
     159,   159,   159,   159,   160,   160,   161,   162,   161,   163,
     163,   164,   164,   165,   166,   164,   167,   168,   169,   167,
     170,   171,   171,   171,   172,   172,   173,   173,   173,   174,
     174,   175,   175,   176,   176,   176,   176,   176,   177,   177,
     178,   178,   179,   179,   180,   181,   181,   182,   182,   183,
     183,   185,   184,   186,   186,   187,   187,   188,   188,   189,
     189,   191,   190,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   193,   193,   193,   194,   194,   195,   195,   197,
     196,   198,   198,   199,   199,   200,   201,   200,   202,   202,
     203,   203,   204,   204,   204,   204,   204,   205,   205,   206,
     206,   207,   207,   208,   209,   209,   210,   211,   211,   212,
     213,   213,   214,   214,   215,   216,   216
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,    10,    11,     5,     5,     5,     5,     0,     5,
       0,     5,     0,     5,     1,     1,     1,     7,     0,    10,
       0,     5,     1,     3,     1,     5,     0,     5,     1,     3,
       1,     5,     0,     5,     1,     3,     0,     5,     1,     3,
       1,     5,     0,     5,     1,     3,     1,     5,     1,     1,
       0,     5,     1,     3,     0,     5,     0,     5,     0,     2,
       1,     7,     2,     7,     0,     0,    11,     9,     0,     1,
       1,     3,     1,     3,     8,     1,     1,     0,     2,     0,
       7,     0,     2,     1,     4,     6,     4,     0,     0,    10,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,    10,     0,     2,     0,     7,     7,     7,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     1,     1,
       4,     4,     4,     6,     4,     6,     1,     1,     1,     4,
       1,     1,     4,     4,     6,     6,     6,     4,     1,     1,
       1,     1,     1,     1,     0,     2,    10,     0,    11,     0,
       7,     0,     1,     0,     0,     7,     1,     0,     0,    10,
       4,     0,     1,     3,     0,     2,     0,     2,     3,     1,
       4,     1,     3,     1,     1,     1,     6,     4,     0,     7,
       0,     1,     1,     8,     4,     1,     4,     1,     3,     0,
       2,     0,     9,     0,    15,     1,     3,     0,     4,     3,
       5,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     7,     1,     1,     0,     2,     0,
       6,     0,     3,     0,     2,     5,     0,     9,     1,     3,
       0,     3,     4,     4,     4,     4,     6,     1,     3,     1,
       6,     1,     3,     5,     1,     3,     1,     1,     3,     1,
       0,     2,     1,     2,     5,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       0,     0,     0,     0,     1,   104,   105,   106,   107,   103,
     102,   101,     0,     0,     0,     0,    18,     0,     0,   233,
      56,     0,     0,    20,     0,     0,    77,     0,     0,     8,
       0,    26,     0,     0,     0,   234,    58,   113,     0,     0,
       0,    10,     0,     0,    32,     2,     0,     0,     0,     0,
      78,   154,     0,     0,     0,     0,     0,     0,     0,    22,
      24,     0,     0,    36,     0,     0,   262,   236,     0,     0,
     185,     0,     0,     0,     0,   184,    59,    60,   183,     0,
       0,     0,   114,   199,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    30,     0,     0,    42,
       0,     0,   263,     0,    57,     0,     0,     0,    68,     0,
       0,    62,    75,    76,     0,     0,     0,   155,   227,     5,
       0,     0,     0,     0,    12,     0,    21,    23,     0,     0,
       0,     0,    34,     0,     0,    50,   265,     0,   235,     0,
     195,     0,    64,     0,    69,     0,     0,   197,     0,     0,
       0,     0,     0,   200,    17,     9,     0,    14,    16,    15,
       0,     0,     0,     0,    49,    48,     0,     0,    27,    29,
       0,     0,     0,     0,    38,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,     0,
      79,     0,     0,     0,     0,   228,    11,     0,     0,     0,
       0,    25,     0,    33,    35,     0,     0,     0,     0,     0,
      44,    46,    54,     0,   264,   266,   240,   238,     0,     0,
       0,   110,    65,   108,     0,    72,     0,     0,   198,     0,
       0,     0,     0,   229,     6,     0,     0,     3,    31,     0,
      37,    39,     0,     0,     0,     0,     0,    52,    19,     0,
       0,   196,   186,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   231,     7,     0,     0,
       0,    43,    45,     0,     0,    54,   239,     0,     0,     0,
       0,     0,     0,   237,     0,   109,     0,    63,    73,     0,
      70,    61,    74,    90,   115,     0,     0,   201,     0,    13,
      41,     0,     0,    51,    53,     0,     0,     0,     0,     0,
     241,   111,     0,     0,     0,    97,    94,    99,   100,    95,
      96,     0,    98,    91,    81,     0,     0,     0,    83,     0,
     159,   157,   203,     0,     0,    47,     0,     0,     0,   249,
       0,   247,     0,     0,   251,   259,     0,   257,     0,     0,
      67,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,     0,   230,   232,    55,   245,     0,
     242,     0,     0,   244,     0,   243,     0,     0,     0,     0,
      82,     0,     0,    92,     0,    87,   112,    90,   119,   121,
       0,     0,     0,     0,     0,     0,   248,     0,   252,   258,
       0,    66,    84,    80,     0,    86,     0,     0,    81,   129,
       0,   128,   148,   149,     0,     0,     0,     0,   127,    81,
     120,     0,   150,   138,     0,   151,   137,     0,   152,   153,
       0,   140,   141,     0,     0,     0,   136,    81,   122,     0,
     163,   156,     0,     0,   202,     0,   260,   256,     0,   254,
     246,     0,    93,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,   174,   162,   166,   190,   158,   218,   215,
     221,   220,   216,   217,   214,   219,   213,     0,   211,     0,
       0,   253,     0,    85,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,     0,   171,     0,     0,     0,     0,    81,
     191,   192,     0,   222,   261,   250,   255,     0,   116,   130,
     131,   132,     0,   134,     0,   117,     0,   139,   143,   142,
       0,     0,     0,   118,   147,     0,   167,     0,     0,   172,
     179,     0,   176,   175,   171,     0,     0,   225,   226,     0,
       0,   212,     0,     0,   124,     0,     0,     0,     0,   126,
       0,     0,   170,     0,   160,     0,     0,     0,     0,     0,
       0,     0,     0,   133,   135,   144,   145,   146,   168,     0,
     173,   174,   177,   194,     0,   181,   189,     0,     0,   223,
      89,     0,   180,   164,   178,     0,     0,     0,     0,     0,
     165,     0,   182,     0,     0,     0,     0,     0,   205,     0,
       0,   193,   207,     0,   224,   169,     0,     0,   206,     0,
       0,     0,     0,   204,   208,     0,     0,     0,   209,     0,
     210
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,    16,    22,    29,    89,   124,    41,    56,   163,
     160,    19,    20,    31,    58,    59,    44,    94,    95,    63,
     131,    99,   173,   174,   135,   209,   210,   166,   178,   246,
     247,    26,    48,    76,   184,   255,    77,   145,   289,   224,
      50,   114,    37,   229,   354,   323,   407,   494,   324,   384,
     435,   326,   327,    78,   222,   223,    82,    51,   329,   419,
     437,   500,   511,   420,   438,   421,   439,    83,   117,   363,
     362,   472,   473,   610,   474,   570,   601,   475,   548,   516,
     575,   549,   594,   328,   392,   519,   520,   521,   147,   148,
     118,   153,   332,   364,   617,   627,   631,   487,   523,   488,
     561,   559,   154,   195,   266,   298,    24,    35,   103,   218,
     249,   282,   340,   341,   343,   344,   448,   449,   346,   347,
     490,    65,    66,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -511
static const short int yypact[] =
{
       8,   -69,    19,   644,  -511,  -511,  -511,  -511,  -511,  -511,
    -511,  -511,   -58,   -45,    30,   -17,    29,    56,    24,  -511,
     103,    45,   144,   124,     6,    75,  -511,    81,    88,   141,
     130,   164,   139,   148,   157,  -511,  -511,   220,   162,   173,
     175,   229,     0,   179,   228,  -511,   252,   644,   522,   212,
    -511,   246,   218,   232,   236,   245,   269,   644,    55,  -511,
    -511,    73,   243,   297,   248,    66,  -511,  -511,   250,   256,
    -511,   258,   260,   644,   261,  -511,  -511,  -511,   262,   264,
      91,   271,  -511,   343,  -511,   272,   277,   274,   279,   351,
     276,   283,     0,   644,    74,  -511,  -511,   644,   286,   326,
     644,   289,  -511,   293,  -511,   644,   294,   644,   353,   644,
     644,  -511,  -511,  -511,   295,    91,   298,  -511,   342,  -511,
     300,   302,    78,   304,   379,   152,  -511,  -511,   316,   307,
      73,   176,  -511,   101,   319,   344,  -511,   185,  -511,   328,
     332,   323,  -511,   329,  -511,   389,   333,  -511,    53,   335,
     336,    91,   340,  -511,   374,  -511,   345,  -511,  -511,  -511,
     347,   350,   346,   419,  -511,  -511,   352,   152,  -511,  -511,
     355,   644,   644,   187,  -511,  -511,   292,   356,   425,   361,
     644,   -25,   644,   644,   644,   644,   443,   644,  -511,   644,
    -511,   386,   366,   644,   377,  -511,  -511,   380,   387,   390,
     385,  -511,   391,  -511,  -511,   393,   392,   101,   644,   192,
    -511,  -511,   396,   400,  -511,  -511,  -511,  -511,   457,    60,
     405,   401,   402,  -511,    71,  -511,   407,   410,  -511,   115,
     411,    84,   412,  -511,  -511,   406,   413,  -511,  -511,   152,
    -511,  -511,   415,   416,   292,   644,   202,  -511,  -511,   191,
     423,  -511,  -511,   644,   644,   422,   426,   644,   644,   427,
     430,   417,   431,   433,   434,   435,  -511,  -511,   437,   440,
     152,  -511,  -511,   441,   446,   396,  -511,   436,   449,   450,
     458,   459,   460,  -511,   464,  -511,   456,  -511,  -511,   206,
    -511,  -511,  -511,   388,  -511,   465,   466,  -511,   238,  -511,
    -511,   470,   644,  -511,  -511,   644,   399,   469,   644,   395,
    -511,  -511,   631,   472,   644,  -511,  -511,  -511,  -511,  -511,
    -511,   475,  -511,  -511,   467,   476,   480,   482,  -511,    43,
    -511,  -511,  -511,   481,   484,  -511,   486,    85,   644,  -511,
     102,  -511,   493,   104,  -511,  -511,   107,  -511,   488,   494,
    -511,  -511,   388,   644,   495,   388,   388,   424,   497,   500,
     502,   503,    26,  -511,     2,  -511,  -511,  -511,  -511,   492,
    -511,   399,   501,  -511,   469,  -511,   644,   152,   505,   504,
    -511,   506,   507,  -511,   110,  -511,  -511,   388,   189,   321,
     509,   508,    58,   512,   511,   519,  -511,   644,  -511,  -511,
     524,  -511,  -511,  -511,   388,  -511,   388,   644,   467,  -511,
     523,  -511,  -511,  -511,   526,   527,   530,   531,  -511,   467,
    -511,   533,  -511,  -511,   535,  -511,  -511,   539,  -511,  -511,
     541,  -511,  -511,   545,   548,   549,  -511,   467,  -511,   552,
     -15,  -511,   555,   554,  -511,   468,   556,  -511,   112,  -511,
    -511,   558,  -511,   402,   559,   189,   321,   321,   189,   189,
     564,   321,   321,   189,   321,   321,   321,   321,   567,   321,
     571,   572,   467,  -511,  -511,  -511,     1,  -511,  -511,  -511,
    -511,  -511,  -511,  -511,  -511,  -511,  -511,   562,  -511,   575,
     577,  -511,   644,  -511,   576,   582,   584,   587,   588,   578,
     119,  -511,   590,   585,   594,   595,   596,   593,   597,   599,
     603,   127,  -511,   598,   619,   607,   566,   609,   610,   467,
    -511,  -511,    13,   611,  -511,  -511,  -511,   608,  -511,  -511,
    -511,  -511,   189,  -511,   189,  -511,   189,  -511,  -511,  -511,
     189,   189,   321,  -511,  -511,   321,  -511,   612,   129,  -511,
    -511,   614,  -511,  -511,   619,   615,   613,  -511,  -511,   616,
     267,  -511,   388,   618,  -511,   621,   622,   623,   624,  -511,
     644,   631,  -511,   619,  -511,   581,   134,   631,   626,   644,
     644,   137,   625,  -511,  -511,  -511,  -511,  -511,   402,   629,
    -511,  -511,   642,  -511,   222,  -511,  -511,   627,   227,  -511,
    -511,   630,  -511,   619,  -511,   628,   631,   632,   633,   634,
    -511,   474,  -511,   468,   388,   677,   635,   237,  -511,   636,
     640,  -511,   638,   468,  -511,  -511,   641,   645,  -511,   468,
     643,   239,   646,  -511,  -511,   468,   468,   647,  -511,   468,
    -511
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,
    -511,  -511,  -511,  -511,  -511,   648,  -511,  -511,   604,  -511,
    -511,  -511,  -511,   528,  -511,  -511,   489,  -165,  -511,  -511,
     461,  -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,
    -511,   -63,  -511,  -511,  -399,  -345,  -511,  -511,   354,   177,
    -288,  -380,  -511,    -3,  -392,   490,  -511,  -511,  -511,  -511,
    -511,  -511,  -511,  -408,  -434,  -511,  -511,  -511,  -511,  -511,
    -511,  -511,  -511,  -511,   221,  -511,  -511,   131,   188,   154,
    -511,  -510,  -511,   -47,  -511,  -511,   225,   138,  -102,   568,
    -511,  -511,  -511,  -511,  -511,  -511,  -511,  -500,  -511,  -511,
    -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,  -511,
    -511,  -511,  -511,   381,  -511,   382,  -511,   259,  -511,   372,
    -511,  -511,   688,   452
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -162
static const short int yytable[] =
{
      12,    79,   202,   141,   517,   325,   553,   379,   417,   454,
     382,   383,   470,   216,     1,   453,   517,     3,     5,     4,
     460,   393,   497,   498,   518,   471,    32,   503,   504,    13,
     506,   507,   508,   509,   390,   512,   518,    33,   468,    60,
     470,     6,     7,    14,    67,   391,    15,   496,     8,     9,
     499,   501,   150,   471,    90,   505,    34,   394,    96,   451,
     217,   452,   358,   590,   325,   592,   442,   325,   325,   359,
     108,    17,  -161,   515,   269,   417,  -161,   443,   417,   417,
      18,   220,    10,   417,    11,   101,    57,   228,   192,    60,
     128,     5,    21,   553,   132,   263,   112,   136,    64,   325,
     416,   264,   140,   113,   143,   301,   146,   140,   568,   360,
     361,   569,    23,   618,     6,     7,   325,    25,   325,     5,
     556,     8,     9,   628,   563,   157,   564,    96,   565,   632,
     175,    27,   566,   567,   260,   637,   638,   158,   159,   640,
     188,   261,     6,     7,   189,    91,    92,   251,    28,     8,
       9,   189,   417,    30,   417,    10,   417,    11,   256,    93,
     417,   417,   257,    36,   129,   130,    38,   416,   204,   205,
     416,   416,   368,   211,    39,   416,   180,   215,   588,   140,
     140,   221,   225,    10,   227,    11,   140,   172,   598,   370,
     232,   373,   315,   371,   375,   374,   334,   405,   376,   491,
     276,   406,    40,   492,   175,   242,   533,     5,    43,   277,
     534,   316,   400,   409,   544,   383,   572,   582,   545,    42,
     573,   593,   319,   320,   599,   573,   410,    45,   406,   322,
       6,     7,   278,   279,   164,   165,    46,     8,     9,   280,
     281,   211,   273,    47,   416,    49,   416,   411,   416,    52,
     284,   221,   416,   416,   288,   290,     5,   333,    53,   412,
     413,    54,   414,   415,    55,   349,   170,   171,    61,   619,
     315,    10,   325,    11,   325,   179,   180,   206,   207,     6,
       7,    62,   243,   244,    64,     5,     8,     9,    69,   316,
     317,    70,   274,   275,   318,   140,   313,   314,    80,   336,
     319,   320,   136,   339,   321,   345,    84,   322,     6,     7,
       5,   351,   605,   606,    81,     8,     9,   608,   254,    85,
      10,    86,    11,    88,   422,    75,   325,   622,   623,   634,
     635,    87,    97,     6,     7,   369,    98,   100,   104,     5,
       8,     9,   105,   316,   106,   423,   107,   109,   110,    10,
     380,    11,   111,   116,   319,   320,   580,   115,   424,   121,
     119,   425,     6,     7,   120,   122,   123,   125,   339,     8,
       9,   126,   134,   345,    10,   133,    11,   138,   208,   426,
     139,   144,   149,   142,   151,   418,   436,   152,   155,   156,
     161,   315,   162,   427,   447,   168,   428,   429,   430,   431,
     432,   433,   434,    10,   221,    11,     5,   167,   176,    69,
     316,   317,    70,   177,   183,   318,   181,     5,   182,   186,
     185,   319,   320,   190,   187,   321,   193,   191,   322,     6,
       7,   194,   199,   196,   197,   198,     8,     9,   200,   201,
       6,     7,   486,   203,   213,   212,    75,     8,     9,   214,
     226,   230,   418,   436,   436,   418,   418,   231,   436,   436,
     418,   436,   436,   436,   436,   233,   436,   550,   234,   550,
      10,   478,    11,   237,   235,   236,   250,   517,   238,   348,
     240,    10,   245,    11,   239,   338,     5,   253,   248,   447,
     479,   480,   252,   254,   267,   481,   258,   259,   262,   265,
     268,   482,   483,   293,   271,   484,   270,   550,   485,     6,
       7,   283,   286,   385,   287,   291,     8,     9,   292,   294,
     295,   296,   305,   297,   589,   299,   550,   300,   550,   418,
     595,   418,   302,   418,   303,   306,   307,   418,   418,   436,
       5,    68,   436,    69,   308,   309,    70,   312,   310,    71,
      10,   311,    11,   330,   331,   342,   550,   335,   353,   612,
     350,   352,   355,     6,     7,    72,   356,   221,   357,   365,
       8,     9,   366,   367,    73,   372,   597,   221,    74,   377,
      75,   378,   381,   395,     5,   386,   387,    69,   388,   389,
      70,   402,   397,   401,   403,   440,   441,   445,   404,     5,
     444,   446,    69,   547,    10,    70,    11,     6,     7,   455,
     486,   450,   456,   457,     8,     9,   458,   459,   547,   461,
     486,   462,     6,     7,    75,   463,   486,   464,   552,     8,
       9,   465,   486,   486,   466,   467,   486,     5,   469,    75,
      69,   476,   477,    70,   591,   493,   495,   489,    10,     5,
      11,   502,    69,   522,   510,    70,   547,   513,   514,   524,
       6,     7,     5,    10,   525,    11,   527,     8,     9,   532,
     528,   529,     6,     7,   530,   531,   536,    75,   535,     8,
       9,   537,   538,   539,   540,     6,     7,   546,   541,    75,
     542,   543,     8,     9,   551,   554,   555,   560,   571,   562,
     578,    10,   574,    11,   577,   583,   604,   579,   584,   585,
     586,   587,   600,    10,   596,    11,   602,   471,   607,   611,
     609,   613,   621,   624,   614,   615,    10,   625,    11,   626,
     629,   633,   630,   272,   169,   241,   304,   581,   636,   639,
     127,   408,   576,   557,   285,   603,   620,   558,   399,   616,
     219,   526,   396,   102,     0,     0,   398,   337
};

static const short int yycheck[] =
{
       3,    48,   167,   105,     3,   293,   516,   352,   388,   408,
     355,   356,    27,    38,     6,   407,     3,    86,    18,     0,
     419,    19,   456,   457,    23,    40,    20,   461,   462,    87,
     464,   465,   466,   467,     8,   469,    23,    31,   437,    42,
      27,    41,    42,    88,    47,    19,    16,   455,    48,    49,
     458,   459,   115,    40,    57,   463,    50,    55,    61,   404,
      85,   406,    19,   573,   352,   575,     8,   355,   356,    26,
      73,    88,    87,   472,   239,   455,    91,    19,   458,   459,
      51,   183,    82,   463,    84,    19,    86,   189,   151,    92,
      93,    18,    36,   603,    97,    11,     5,   100,    32,   387,
     388,    17,   105,    12,   107,   270,   109,   110,   542,    66,
      67,   545,    88,   613,    41,    42,   404,    14,   406,    18,
     519,    48,    49,   623,   532,    47,   534,   130,   536,   629,
     133,    86,   540,   541,    19,   635,   636,    59,    60,   639,
      87,    26,    41,    42,    91,    90,    91,    87,     4,    48,
      49,    91,   532,    29,   534,    82,   536,    84,    87,    86,
     540,   541,    91,    88,    90,    91,    85,   455,   171,   172,
     458,   459,    87,   176,    86,   463,    91,   180,   570,   182,
     183,   184,   185,    82,   187,    84,   189,    86,   580,    87,
     193,    87,     3,    91,    87,    91,   298,    87,    91,    87,
       9,    91,    61,    91,   207,   208,    87,    18,    44,    18,
      91,    22,   377,    24,    87,   560,    87,   562,    91,    89,
      91,    87,    33,    34,    87,    91,    37,    88,    91,    40,
      41,    42,    41,    42,    82,    83,    88,    48,    49,    48,
      49,   244,   245,    86,   532,    25,   534,    58,   536,    87,
     253,   254,   540,   541,   257,   258,    18,    19,    85,    70,
      71,    86,    73,    74,    35,   312,    90,    91,    89,   614,
       3,    82,   560,    84,   562,    90,    91,    90,    91,    41,
      42,    53,    90,    91,    32,    18,    48,    49,    21,    22,
      23,    24,    90,    91,    27,   298,    90,    91,    86,   302,
      33,    34,   305,   306,    37,   308,    88,    40,    41,    42,
      18,   314,    90,    91,    68,    48,    49,    90,    91,    87,
      82,    85,    84,    54,     3,    58,   614,    90,    91,    90,
      91,    86,    89,    41,    42,   338,    39,    89,    88,    18,
      48,    49,    86,    22,    86,    24,    86,    86,    86,    82,
     353,    84,    88,    10,    33,    34,    89,    86,    37,    85,
      88,    40,    41,    42,    87,    86,    15,    91,   371,    48,
      49,    88,    46,   376,    82,    89,    84,    88,    86,    58,
      87,    28,    87,    89,    86,   388,   389,    45,    88,    87,
      86,     3,    13,    72,   397,    88,    75,    76,    77,    78,
      79,    80,    81,    82,   407,    84,    18,    91,    89,    21,
      22,    23,    24,    69,    91,    27,    88,    18,    86,    30,
      91,    33,    34,    88,    91,    37,    86,    91,    40,    41,
      42,    57,    86,    88,    87,    85,    48,    49,    19,    87,
      41,    42,   445,    88,    19,    89,    58,    48,    49,    88,
       7,    65,   455,   456,   457,   458,   459,    91,   461,   462,
     463,   464,   465,   466,   467,    88,   469,   514,    88,   516,
      82,     3,    84,    88,    87,    85,    19,     3,    87,    84,
      88,    82,    86,    84,    91,    86,    18,    86,    88,   492,
      22,    23,    87,    91,    88,    27,    89,    87,    87,    87,
      87,    33,    34,    86,    88,    37,    91,   554,    40,    41,
      42,    88,    90,    89,    88,    88,    48,    49,    88,    88,
      87,    87,    86,    88,   571,    88,   573,    87,   575,   532,
     577,   534,    91,   536,    88,    86,    86,   540,   541,   542,
      18,    19,   545,    21,    86,    86,    24,    91,    88,    27,
      82,    87,    84,    88,    88,    86,   603,    87,    91,   606,
      88,    86,    86,    41,    42,    43,    86,   570,    86,    88,
      48,    49,    88,    87,    52,    82,   579,   580,    56,    91,
      58,    87,    87,    91,    18,    88,    86,    21,    86,    86,
      24,    87,    91,    88,    88,    86,    88,    86,    91,    18,
      88,    82,    21,    37,    82,    24,    84,    41,    42,    86,
     613,    87,    86,    86,    48,    49,    86,    86,    37,    86,
     623,    86,    41,    42,    58,    86,   629,    86,    62,    48,
      49,    86,   635,   636,    86,    86,   639,    18,    86,    58,
      21,    86,    88,    24,    63,    87,    87,    91,    82,    18,
      84,    87,    21,    91,    87,    24,    37,    86,    86,    84,
      41,    42,    18,    82,    87,    84,    90,    48,    49,    91,
      88,    87,    41,    42,    87,    87,    91,    58,    88,    48,
      49,    87,    87,    87,    91,    41,    42,    89,    91,    58,
      91,    88,    48,    49,    87,    86,    86,    86,    86,    91,
      87,    82,    88,    84,    89,    87,    64,    91,    87,    87,
      87,    87,    87,    82,    88,    84,    87,    40,    91,    91,
      90,    89,    87,    87,    91,    91,    82,    87,    84,    91,
      89,    88,    87,   244,   130,   207,   275,   560,    92,    92,
      92,   387,   554,   522,   254,   591,   615,   522,   376,   611,
     182,   492,   371,    65,    -1,    -1,   374,   305
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     6,    94,    86,     0,    18,    41,    42,    48,    49,
      82,    84,   146,    87,    88,    16,    95,    88,    51,   104,
     105,    36,    96,    88,   199,    14,   124,    86,     4,    97,
      29,   106,    20,    31,    50,   200,    88,   135,    85,    86,
      61,   100,    89,    44,   109,    88,    88,    86,   125,    25,
     133,   150,    87,    85,    86,    35,   101,    86,   107,   108,
     146,    89,    53,   112,    32,   214,   215,   146,    19,    21,
      24,    27,    43,    52,    56,    58,   126,   129,   146,   176,
      86,    68,   149,   160,    88,    87,    85,    86,    54,    98,
     146,    90,    91,    86,   110,   111,   146,    89,    39,   114,
      89,    19,   215,   201,    88,    86,    86,    86,   146,    86,
      86,    88,     5,    12,   134,    86,    10,   161,   183,    88,
      87,    85,    86,    15,    99,    91,    88,   108,   146,    90,
      91,   113,   146,    89,    46,   117,   146,   216,    88,    87,
     146,   181,    89,   146,    28,   130,   146,   181,   182,    87,
     134,    86,    45,   184,   195,    88,    87,    47,    59,    60,
     103,    86,    13,   102,    82,    83,   120,    91,    88,   111,
      90,    91,    86,   115,   116,   146,    89,    69,   121,    90,
      91,    88,    86,    91,   127,    91,    30,    91,    87,    91,
      88,    91,   134,    86,    57,   196,    88,    87,    85,    86,
      19,    87,   120,    88,   146,   146,    90,    91,    86,   118,
     119,   146,    89,    19,    88,   146,    38,    85,   202,   182,
     181,   146,   147,   148,   132,   146,     7,   146,   181,   136,
      65,    91,   146,    88,    88,    87,    85,    88,    87,    91,
      88,   116,   146,    90,    91,    86,   122,   123,    88,   203,
      19,    87,    87,    86,    91,   128,    87,    91,    89,    87,
      19,    26,    87,    11,    17,    87,   197,    88,    87,   120,
      91,    88,   119,   146,    90,    91,     9,    18,    41,    42,
      48,    49,   204,    88,   146,   148,    90,    88,   146,   131,
     146,    88,    88,    86,    88,    87,    87,    88,   198,    88,
      87,   120,    91,    88,   123,    86,    86,    86,    86,    86,
      88,    87,    91,    90,    91,     3,    22,    23,    27,    33,
      34,    37,    40,   138,   141,   143,   144,   145,   176,   151,
      88,    88,   185,    19,   181,    87,   146,   216,    86,   146,
     205,   206,    86,   207,   208,   146,   211,   212,    84,   176,
      88,   146,    86,    91,   137,    86,    86,    86,    19,    26,
      66,    67,   163,   162,   186,    88,    88,    87,    87,   146,
      87,    91,    82,    87,    91,    87,    91,    91,    87,   138,
     146,    87,   138,   138,   142,    89,    88,    86,    86,    86,
       8,    19,   177,    19,    55,    91,   206,    91,   208,   212,
     120,    88,    87,    88,    91,    87,    91,   139,   141,    24,
      37,    58,    70,    71,    73,    74,   143,   144,   146,   152,
     156,   158,     3,    24,    37,    40,    58,    72,    75,    76,
      77,    78,    79,    80,    81,   143,   146,   153,   157,   159,
      86,    88,     8,    19,    88,    86,    82,   146,   209,   210,
      87,   138,   138,   147,   137,    86,    86,    86,    86,    86,
     137,    86,    86,    86,    86,    86,    86,    86,   137,    86,
      27,    40,   164,   165,   167,   170,    86,    88,     3,    22,
      23,    27,    33,    34,    37,    40,   146,   190,   192,    91,
     213,    87,    91,    87,   140,    87,   156,   157,   157,   156,
     154,   156,    87,   157,   157,   156,   157,   157,   157,   157,
      87,   155,   157,    86,    86,   137,   172,     3,    23,   178,
     179,   180,    91,   191,    84,    87,   210,    90,    88,    87,
      87,    87,    91,    87,    91,    88,    91,    87,    87,    87,
      91,    91,    91,    88,    87,    91,    89,    37,   171,   174,
     176,    87,    62,   174,    86,    86,   137,   167,   179,   194,
      86,   193,    91,   156,   156,   156,   156,   156,   157,   157,
     168,    86,    87,    91,    88,   173,   171,    89,    87,    91,
      89,   142,   138,    87,    87,    87,    87,    87,   147,   176,
     174,    63,   174,    87,   175,   176,    88,   146,   147,    87,
      87,   169,    87,   172,    64,    90,    91,    91,    90,    90,
     166,    91,   176,    89,    91,    91,   180,   187,   190,   138,
     170,    87,    90,    91,    87,    87,    91,   188,   190,    89,
      87,   189,   190,    88,    90,    91,    92,   190,   190,    92,
     190
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 256 "dfgparser.y"
    { string_StringFree(yyvsp[-7].string);
					  YYACCEPT; /* Stop immediately */ ;}
    break;

  case 4:
#line 276 "dfgparser.y"
    { dfg_DESC.name = yyvsp[-2].string; ;}
    break;

  case 5:
#line 280 "dfgparser.y"
    { dfg_DESC.author = yyvsp[-2].string; ;}
    break;

  case 6:
#line 284 "dfgparser.y"
    { dfg_DESC.status = yyvsp[-2].state; ;}
    break;

  case 7:
#line 288 "dfgparser.y"
    { dfg_DESC.description = yyvsp[-2].string; ;}
    break;

  case 9:
#line 293 "dfgparser.y"
    { dfg_DESC.version = yyvsp[-2].string; ;}
    break;

  case 11:
#line 298 "dfgparser.y"
    { dfg_DESC.logic = yyvsp[-2].string; ;}
    break;

  case 13:
#line 303 "dfgparser.y"
    { dfg_DESC.date = yyvsp[-2].string; ;}
    break;

  case 14:
#line 306 "dfgparser.y"
    { yyval.state = DFG_SATISFIABLE; ;}
    break;

  case 15:
#line 307 "dfgparser.y"
    { yyval.state = DFG_UNSATISFIABLE; ;}
    break;

  case 16:
#line 308 "dfgparser.y"
    { yyval.state = DFG_UNKNOWNSTATE; ;}
    break;

  case 24:
#line 347 "dfgparser.y"
    { dfg_SymbolDecl(DFG_FUNC, yyvsp[0].string, -2); ;}
    break;

  case 25:
#line 349 "dfgparser.y"
    { dfg_SymbolDecl(DFG_FUNC, yyvsp[-3].string, yyvsp[-1].number); ;}
    break;

  case 30:
#line 360 "dfgparser.y"
    { dfg_SymbolDecl(DFG_PRDICAT, yyvsp[0].string, -2); ;}
    break;

  case 31:
#line 361 "dfgparser.y"
    { dfg_SymbolDecl(DFG_PRDICAT, yyvsp[-3].string, yyvsp[-1].number); ;}
    break;

  case 34:
#line 368 "dfgparser.y"
    { dfg_SymbolDecl(DFG_PRDICAT, yyvsp[0].string, 1); ;}
    break;

  case 35:
#line 369 "dfgparser.y"
    { dfg_SymbolDecl(DFG_PRDICAT, yyvsp[0].string, 1); ;}
    break;

  case 40:
#line 380 "dfgparser.y"
    { dfg_SymbolDecl(DFG_OPERAT, yyvsp[0].string, -2); ;}
    break;

  case 41:
#line 381 "dfgparser.y"
    { dfg_SymbolDecl(DFG_OPERAT, yyvsp[-3].string, yyvsp[-1].number); ;}
    break;

  case 46:
#line 392 "dfgparser.y"
    { dfg_SymbolDecl(DFG_QUANTIF, yyvsp[0].string, -2); ;}
    break;

  case 47:
#line 393 "dfgparser.y"
    { dfg_SymbolDecl(DFG_QUANTIF, yyvsp[-3].string, yyvsp[-1].number); ;}
    break;

  case 48:
#line 396 "dfgparser.y"
    { yyval.number = -1; ;}
    break;

  case 49:
#line 397 "dfgparser.y"
    { yyval.number = yyvsp[0].number; ;}
    break;

  case 55:
#line 408 "dfgparser.y"
    { dfg_TranslPairDecl(yyvsp[-3].string, yyvsp[-1].string); ;}
    break;

  case 61:
#line 427 "dfgparser.y"
    { dfg_SubSort(yyvsp[-4].string,yyvsp[-2].string); ;}
    break;

  case 62:
#line 428 "dfgparser.y"
    { dfg_SORTDECLLIST = list_Nconc(dfg_SORTDECLLIST,list_List(list_PairCreate(NULL,yyvsp[-1].term))); ;}
    break;

  case 63:
#line 430 "dfgparser.y"
    { string_StringFree(yyvsp[-4].string); ;}
    break;

  case 64:
#line 431 "dfgparser.y"
    { dfg_VarStart(); ;}
    break;

  case 65:
#line 432 "dfgparser.y"
    { dfg_VarStop();  ;}
    break;

  case 66:
#line 433 "dfgparser.y"
    { TERM term;
					  dfg_VarBacktrack();
					  dfg_VarCheck();
					  term = dfg_CreateQuantifier(fol_All(),yyvsp[-6].list,yyvsp[-2].term);
					  dfg_SORTDECLLIST = list_Nconc(dfg_SORTDECLLIST,list_List(list_PairCreate(NULL,term)));
					;}
    break;

  case 67:
#line 442 "dfgparser.y"
    { dfg_SymbolGenerated(dfg_Symbol(yyvsp[-7].string,1), yyvsp[-6].bool, yyvsp[-2].list); ;}
    break;

  case 68:
#line 445 "dfgparser.y"
    { yyval.bool = FALSE; ;}
    break;

  case 69:
#line 446 "dfgparser.y"
    { yyval.bool = TRUE; ;}
    break;

  case 70:
#line 449 "dfgparser.y"
    { yyval.list = list_List(yyvsp[0].string); ;}
    break;

  case 71:
#line 450 "dfgparser.y"
    { yyval.list = list_Cons(yyvsp[0].string, yyvsp[-2].list); ;}
    break;

  case 72:
#line 453 "dfgparser.y"
    { string_StringFree(yyvsp[0].string); ;}
    break;

  case 73:
#line 454 "dfgparser.y"
    { string_StringFree(yyvsp[0].string); ;}
    break;

  case 74:
#line 463 "dfgparser.y"
    { list_NReverse(yyvsp[-2].list);
                                  if (yyvsp[-5].bool) /* Axioms */
				    dfg_AXIOMLIST = list_Nconc(dfg_AXIOMLIST, yyvsp[-2].list);
				  else
				    dfg_CONJECLIST = list_Nconc(dfg_CONJECLIST, yyvsp[-2].list);
				;}
    break;

  case 75:
#line 471 "dfgparser.y"
    { yyval.bool = TRUE;  ;}
    break;

  case 76:
#line 472 "dfgparser.y"
    { yyval.bool = FALSE; ;}
    break;

  case 79:
#line 479 "dfgparser.y"
    { yyval.list = list_Nil(); ;}
    break;

  case 80:
#line 481 "dfgparser.y"
    { LIST pair;
					  if (yyvsp[-3].term == NULL) { /* No term */
					    if (yyvsp[-2].string != NULL)
					      string_StringFree(yyvsp[-2].string);
					    yyval.list = yyvsp[-6].list;
					  } else {
					    pair = list_PairCreate(yyvsp[-2].string, yyvsp[-3].term);
					    yyval.list = list_Cons(pair, yyvsp[-6].list);
					  }
					  dfg_VarCheck();
					;}
    break;

  case 81:
#line 494 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 82:
#line 495 "dfgparser.y"
    { yyval.string = yyvsp[0].string;   ;}
    break;

  case 83:
#line 498 "dfgparser.y"
    { yyval.term = yyvsp[0].term; ;}
    break;

  case 84:
#line 500 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_Not(),list_List(yyvsp[-1].term)); ;}
    break;

  case 85:
#line 502 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(yyvsp[-5].symbol, list_Cons(yyvsp[-3].term, list_List(yyvsp[-1].term))); ;}
    break;

  case 86:
#line 504 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(yyvsp[-3].symbol, yyvsp[-1].list); ;}
    break;

  case 87:
#line 505 "dfgparser.y"
    { dfg_VarStart(); ;}
    break;

  case 88:
#line 506 "dfgparser.y"
    { dfg_VarStop(); ;}
    break;

  case 89:
#line 508 "dfgparser.y"
    { dfg_VarBacktrack();
		    yyval.term = dfg_IGNORE ? NULL : dfg_CreateQuantifier(yyvsp[-9].symbol,yyvsp[-5].list,yyvsp[-1].term);
		  ;}
    break;

  case 90:
#line 513 "dfgparser.y"
    { yyval.term = NULL; ;}
    break;

  case 91:
#line 514 "dfgparser.y"
    { yyval.term = yyvsp[0].term; ;}
    break;

  case 92:
#line 518 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? list_Nil() : list_List(yyvsp[0].term); ;}
    break;

  case 93:
#line 520 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? yyvsp[-2].list : list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].term)); ;}
    break;

  case 94:
#line 523 "dfgparser.y"
    { yyval.symbol = fol_Equiv();    ;}
    break;

  case 95:
#line 524 "dfgparser.y"
    { yyval.symbol = fol_Implied();  ;}
    break;

  case 96:
#line 525 "dfgparser.y"
    { yyval.symbol = fol_Implies();  ;}
    break;

  case 97:
#line 528 "dfgparser.y"
    { yyval.symbol = fol_And(); ;}
    break;

  case 98:
#line 529 "dfgparser.y"
    { yyval.symbol = fol_Or();  ;}
    break;

  case 99:
#line 532 "dfgparser.y"
    { yyval.symbol = fol_Exist(); ;}
    break;

  case 100:
#line 533 "dfgparser.y"
    { yyval.symbol = fol_All(); ;}
    break;

  case 101:
#line 536 "dfgparser.y"
    { if (dfg_IGNORE) {
  					    string_StringFree(yyvsp[0].string);
					    yyval.string = NULL;
					  } else
					    yyval.string = yyvsp[0].string;
					;}
    break;

  case 102:
#line 543 "dfgparser.y"
    { yyval.string = dfg_IGNORE ? NULL : string_IntToString(yyvsp[0].number); ;}
    break;

  case 103:
#line 545 "dfgparser.y"
    { yyval.string = dfg_IGNORE ? NULL : string_StringCopy("set_flag"); ;}
    break;

  case 104:
#line 547 "dfgparser.y"
    { yyval.string = dfg_IGNORE ? NULL : string_StringCopy("set_DomPred"); ;}
    break;

  case 105:
#line 549 "dfgparser.y"
    { yyval.string = dfg_IGNORE ? NULL : string_StringCopy("set_precedence"); ;}
    break;

  case 106:
#line 551 "dfgparser.y"
    { yyval.string = dfg_IGNORE ? NULL : string_StringCopy("set_ClauseFormulaRelation"); ;}
    break;

  case 107:
#line 553 "dfgparser.y"
    { yyval.string = dfg_IGNORE ? NULL : string_StringCopy("set_selection"); ;}
    break;

  case 108:
#line 557 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? list_Nil() : list_List(yyvsp[0].term); ;}
    break;

  case 109:
#line 559 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? yyvsp[-2].list : list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].term)); ;}
    break;

  case 110:
#line 563 "dfgparser.y"
    { if (!dfg_IGNORE) {
		      SYMBOL s = dfg_Symbol(yyvsp[0].string,0);
		      if (!symbol_IsVariable(s)) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Line %d: Symbol is not a variable.\n",dfg_LINENUMBER);
			misc_FinishUserErrorReport();
		      }
		      yyval.term = term_Create(s, list_Nil());
		    }
		  ;}
    break;

  case 111:
#line 574 "dfgparser.y"
    { if (!dfg_IGNORE) {
		      SYMBOL p, v;
		      p = dfg_Symbol(yyvsp[-3].string, 1);
		      if (!symbol_IsPredicate(p)) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Line %d: Symbol is not a predicate.\n",dfg_LINENUMBER);
			misc_FinishUserErrorReport();
		      }
		      v = dfg_Symbol(yyvsp[-1].string, 0);
		      if (!symbol_IsVariable(v)) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Line %d: Symbol is not a variable.\n",dfg_LINENUMBER);
			misc_FinishUserErrorReport();
		      }
		      yyval.term = term_Create(p, list_List(term_Create(v,list_Nil())));
		    }
		  ;}
    break;

  case 112:
#line 599 "dfgparser.y"
    { list_NReverse(yyvsp[-2].list);
                       	                  if (yyvsp[-7].bool) /* Axioms */
				    	    dfg_AXIOMLIST = list_Nconc(dfg_AXIOMLIST, yyvsp[-2].list);
				  	  else
				            dfg_CONJECLIST = list_Nconc(dfg_CONJECLIST, yyvsp[-2].list);
				          flag_SetFlagValue(dfg_FLAGS, flag_EML, flag_EMLON);
					;}
    break;

  case 115:
#line 612 "dfgparser.y"
    { yyval.list = list_Nil(); ;}
    break;

  case 116:
#line 615 "dfgparser.y"
    { LIST pair;
					  if (yyvsp[-3].term == NULL) { /* No term */
					    if (yyvsp[-2].string != NULL)
					      string_StringFree(yyvsp[-2].string);
					    yyval.list = yyvsp[-6].list;
					  } else {
					    pair = list_PairCreate(yyvsp[-2].string, yyvsp[-3].term);
					    yyval.list = list_Cons(pair, yyvsp[-6].list);
					  }
					  dfg_VarCheck();
					;}
    break;

  case 117:
#line 628 "dfgparser.y"
    { LIST pair;
					  if (yyvsp[-3].term == NULL) { /* No term */
					    if (yyvsp[-2].string != NULL)
					      string_StringFree(yyvsp[-2].string);
					    yyval.list = yyvsp[-6].list;
					  } else {
					    pair = list_PairCreate(yyvsp[-2].string, yyvsp[-3].term);
					    yyval.list = list_Nconc(yyvsp[-6].list, list_List(pair));
					  }
					;}
    break;

  case 118:
#line 640 "dfgparser.y"
    { LIST pair;
					  if (yyvsp[-3].term == NULL) { /* No term */
					    if (yyvsp[-2].string != NULL)
					      string_StringFree(yyvsp[-2].string);
					    yyval.list = yyvsp[-6].list;
					  } else {
					    pair = list_PairCreate(yyvsp[-2].string, yyvsp[-3].term);
					    yyval.list = list_Nconc(yyvsp[-6].list, list_List(pair));
					  }
					;}
    break;

  case 119:
#line 654 "dfgparser.y"
    { yyval.term = NULL; ;}
    break;

  case 120:
#line 655 "dfgparser.y"
    { yyval.term = yyvsp[0].term; ;}
    break;

  case 121:
#line 658 "dfgparser.y"
    { yyval.term = NULL; ;}
    break;

  case 122:
#line 659 "dfgparser.y"
    { yyval.term = term_Create(eml_Box(), 
					list_Cons(term_Create(fol_Not(), list_List(yyvsp[0].term)), 
					  list_List(term_Create(fol_False(), list_Nil())))); 
					/* since r = 1 iff (r':1)' = 1 */
                                ;}
    break;

  case 123:
#line 666 "dfgparser.y"
    { yyval.list = list_List(yyvsp[0].term); ;}
    break;

  case 124:
#line 667 "dfgparser.y"
    { yyval.list = list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].term)); ;}
    break;

  case 125:
#line 670 "dfgparser.y"
    { yyval.list = list_List(yyvsp[0].term); ;}
    break;

  case 126:
#line 671 "dfgparser.y"
    { yyval.list = list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].term)); ;}
    break;

  case 127:
#line 675 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : dfg_AtomCreate(yyvsp[0].string, list_Nil()); ;}
    break;

  case 128:
#line 677 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_True(),list_Nil()); ;}
    break;

  case 129:
#line 679 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_False(),list_Nil()); ;}
    break;

  case 130:
#line 681 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_Not(),list_List(yyvsp[-1].term)); ;}
    break;

  case 131:
#line 683 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_Domain(),list_List(yyvsp[-1].term)); ;}
    break;

  case 132:
#line 685 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_Range(),list_List(yyvsp[-1].term)); ;}
    break;

  case 133:
#line 687 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(yyvsp[-5].symbol, list_Cons(yyvsp[-3].term, list_List(yyvsp[-1].term))); ;}
    break;

  case 134:
#line 689 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(yyvsp[-3].symbol, yyvsp[-1].list); ;}
    break;

  case 135:
#line 691 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(yyvsp[-5].symbol, list_Cons(yyvsp[-3].term, list_List(yyvsp[-1].term))); ;}
    break;

  case 136:
#line 695 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : dfg_AtomCreate(yyvsp[0].string, list_Nil()); ;}
    break;

  case 137:
#line 697 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_True(),list_Nil()); ;}
    break;

  case 138:
#line 699 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_False(),list_Nil()); ;}
    break;

  case 139:
#line 701 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_Not(),list_List(yyvsp[-1].term)); ;}
    break;

  case 140:
#line 703 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_Id(),list_Nil()); ;}
    break;

  case 141:
#line 705 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_Div(),list_Nil()); ;}
    break;

  case 142:
#line 707 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_Conv(),list_List(yyvsp[-1].term)); ;}
    break;

  case 143:
#line 709 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_Test(),list_List(yyvsp[-1].term)); ;}
    break;

  case 144:
#line 711 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_DomRestr(), list_Cons(yyvsp[-3].term, list_List(yyvsp[-1].term))); ;}
    break;

  case 145:
#line 713 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(eml_RanRestr(), list_Cons(yyvsp[-3].term, list_List(yyvsp[-1].term))); ;}
    break;

  case 146:
#line 715 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(yyvsp[-5].symbol, list_Cons(yyvsp[-3].term, list_List(yyvsp[-1].term))); ;}
    break;

  case 147:
#line 717 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(yyvsp[-3].symbol, yyvsp[-1].list); ;}
    break;

  case 148:
#line 720 "dfgparser.y"
    { yyval.symbol = eml_Box();  ;}
    break;

  case 149:
#line 721 "dfgparser.y"
    { yyval.symbol = eml_Dia();  ;}
    break;

  case 150:
#line 724 "dfgparser.y"
    { yyval.symbol = fol_And();  ;}
    break;

  case 151:
#line 725 "dfgparser.y"
    { yyval.symbol = fol_Or();   ;}
    break;

  case 152:
#line 726 "dfgparser.y"
    { yyval.symbol = eml_Comp(); ;}
    break;

  case 153:
#line 727 "dfgparser.y"
    { yyval.symbol = eml_Sum();  ;}
    break;

  case 156:
#line 742 "dfgparser.y"
    { list_NReverse(yyvsp[-2].list);
                  	if (!list_Empty(dfg_TEMPPLAINCLAUSES)) {
                  	  /* Plain clauses are temporarily stored in the list dfg_TEMPPLAINCLAUSES.
                  	     They need to be concatenated to their respective axiom or conjecture 
                  	     plain clause lists. */
                  	  if (yyvsp[-7].bool) /* Axioms */
		                dfg_PLAINAXCLAUSES = list_Nconc(dfg_PLAINAXCLAUSES, dfg_TEMPPLAINCLAUSES);
		              else
		                dfg_PLAINCONCLAUSES = list_Nconc(dfg_PLAINCONCLAUSES, dfg_TEMPPLAINCLAUSES);
		              dfg_TEMPPLAINCLAUSES = list_Nil();
		            }
		    if (!list_Empty(yyvsp[-2].list)) {
                      if (yyvsp[-7].bool) /* Axioms */
		                dfg_AXCLAUSES = list_Nconc(dfg_AXCLAUSES, yyvsp[-2].list);
		              else
		                dfg_CONCLAUSES = list_Nconc(dfg_CONCLAUSES, yyvsp[-2].list);
		            }
		  ;}
    break;

  case 157:
#line 761 "dfgparser.y"
    { stack_Push((POINTER)dfg_IGNORE); dfg_IGNORE = TRUE; ;}
    break;

  case 158:
#line 764 "dfgparser.y"
    { dfg_IGNORE = (BOOL)stack_PopResult(); ;}
    break;

  case 159:
#line 767 "dfgparser.y"
    { yyval.list = list_Nil(); ;}
    break;

  case 160:
#line 769 "dfgparser.y"
    { LIST pair;
		    if (yyvsp[-3].term == NULL) { /* No clause */
		      if (yyvsp[-2].string != NULL)
			string_StringFree(yyvsp[-2].string);
		      yyval.list = yyvsp[-6].list;
		    } else {
		      pair = list_PairCreate(yyvsp[-2].string, yyvsp[-3].term);
		      yyval.list = list_Cons(pair, yyvsp[-6].list);
		    }
		    dfg_VarCheck();
		  ;}
    break;

  case 161:
#line 782 "dfgparser.y"
    { yyval.term = NULL; ;}
    break;

  case 162:
#line 783 "dfgparser.y"
    { yyval.term = yyvsp[0].term; ;}
    break;

  case 163:
#line 784 "dfgparser.y"
    {dfg_VarStart();;}
    break;

  case 164:
#line 784 "dfgparser.y"
    {dfg_VarStop();;}
    break;

  case 165:
#line 785 "dfgparser.y"
    { dfg_VarBacktrack();
		    if (dfg_IGNORE) 
		     yyval.term = NULL;
			else {
              /* C || A -> S */
  		      DFG_PLAINCLAUSE clause = dfg_PlainClauseCreate();
		      clause->constraint = yyvsp[-5].list;
		      clause->antecedent = yyvsp[-3].list;
		      clause->succedent = yyvsp[-1].list;
		      clause->selected = dfg_SELECTED_LITERAL;
		      dfg_SELECTED_LITERAL = (TERM) NULL;
		      dfg_TEMPPLAINCLAUSES = list_Nconc(dfg_TEMPPLAINCLAUSES, list_List(clause));
		      yyval.term = NULL;
		    }
		  ;}
    break;

  case 166:
#line 802 "dfgparser.y"
    { yyval.term = yyvsp[0].term; ;}
    break;

  case 167:
#line 803 "dfgparser.y"
    { dfg_VarStart(); ;}
    break;

  case 168:
#line 804 "dfgparser.y"
    { dfg_VarStop();  ;}
    break;

  case 169:
#line 806 "dfgparser.y"
    { dfg_VarBacktrack();
		    yyval.term = dfg_IGNORE ? NULL : dfg_CreateQuantifier(fol_All(),yyvsp[-5].list,yyvsp[-1].term);
		  ;}
    break;

  case 170:
#line 812 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_Or(), yyvsp[-1].list); ;}
    break;

  case 171:
#line 815 "dfgparser.y"
    {yyval.list = list_Nil();;}
    break;

  case 172:
#line 817 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? list_Nil() : list_List(yyvsp[0].term); ;}
    break;

  case 173:
#line 819 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? yyvsp[-2].list : list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].term)); ;}
    break;

  case 174:
#line 822 "dfgparser.y"
    {yyval.list = list_Nil();;}
    break;

  case 175:
#line 824 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? yyvsp[-1].list : list_Nconc(yyvsp[-1].list, list_List(yyvsp[0].term)); ;}
    break;

  case 176:
#line 827 "dfgparser.y"
    {yyval.list = list_Nil();;}
    break;

  case 177:
#line 829 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? yyvsp[-1].list : list_Nconc(yyvsp[-1].list, list_List(yyvsp[0].term)); ;}
    break;

  case 178:
#line 831 "dfgparser.y"
    { if (dfg_IGNORE)
		  	  yyval.list = yyvsp[-2].list;
		  	else {
		  	  if(dfg_SELECTED_LITERAL != NULL) {
		  	    misc_StartUserErrorReport();
		        misc_UserErrorReport("\n Trying to select two literals in a clause.");
			    misc_FinishUserErrorReport();
			  } 
		  	  dfg_SELECTED_LITERAL = yyvsp[-1].term;
		  	  yyval.list = list_Nconc(yyvsp[-2].list, list_List(yyvsp[-1].term));
		  	} 
		  ;}
    break;

  case 179:
#line 845 "dfgparser.y"
    { yyval.term = yyvsp[0].term; ;}
    break;

  case 180:
#line 847 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? yyvsp[-1].term : term_Create(fol_Not(),list_List(yyvsp[-1].term)); ;}
    break;

  case 181:
#line 850 "dfgparser.y"
    { yyval.list = list_List(yyvsp[0].term); ;}
    break;

  case 182:
#line 851 "dfgparser.y"
    { yyval.list = list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].term)); ;}
    break;

  case 183:
#line 855 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : dfg_AtomCreate(yyvsp[0].string,list_Nil()); ;}
    break;

  case 184:
#line 857 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_True(),list_Nil()); ;}
    break;

  case 185:
#line 859 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_False(),list_Nil()); ;}
    break;

  case 186:
#line 861 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : term_Create(fol_Equality(),list_Cons(yyvsp[-3].term,list_List(yyvsp[-1].term))); ;}
    break;

  case 187:
#line 863 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : dfg_AtomCreate(yyvsp[-3].string, yyvsp[-1].list); ;}
    break;

  case 195:
#line 889 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : dfg_TermCreate(yyvsp[0].string,list_Nil()); ;}
    break;

  case 196:
#line 891 "dfgparser.y"
    { yyval.term = dfg_IGNORE ? NULL : dfg_TermCreate(yyvsp[-3].string, yyvsp[-1].list); ;}
    break;

  case 197:
#line 895 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? list_Nil() : list_List(yyvsp[0].term); ;}
    break;

  case 198:
#line 897 "dfgparser.y"
    { yyval.list = dfg_IGNORE ? yyvsp[-2].list : list_Nconc(yyvsp[-2].list,list_List(yyvsp[0].term)); ;}
    break;

  case 201:
#line 909 "dfgparser.y"
    { if (!string_Equal(yyvsp[-2].string,"SPASS")) {
		      stack_Push((POINTER)dfg_IGNORE);
		      dfg_IGNORE = TRUE;
		    }
		  ;}
    break;

  case 202:
#line 916 "dfgparser.y"
    { if (!string_Equal(yyvsp[-6].string,"SPASS"))
		      dfg_IGNORE = (BOOL)stack_PopResult();
		    string_StringFree(yyvsp[-6].string);
		  ;}
    break;

  case 204:
#line 925 "dfgparser.y"
    { if (!dfg_IGNORE && yyvsp[-11].string!=NULL && yyvsp[-9].term!=NULL && !list_Empty(yyvsp[-4].list)) {
		    LIST tupel;
		    RULE Rule = clause_GetOriginFromString(yyvsp[-7].string);
		    string_StringFree(yyvsp[-7].string);
		    /* Build a tuple (label,clause,parentlist,split level,origin) */
		    tupel = list_Cons((POINTER)yyvsp[-2].number,list_List((POINTER)Rule));
		    tupel = list_Cons(yyvsp[-11].string,list_Cons(yyvsp[-9].term,list_Cons(yyvsp[-4].list,tupel)));
		    dfg_PROOFLIST = list_Cons(tupel, dfg_PROOFLIST);
		  } else {
		    /* ignore DNF clauses and clauses with incomplete data */
		    if (yyvsp[-11].string != NULL) string_StringFree(yyvsp[-11].string);
		    if (yyvsp[-9].term != NULL) term_Delete(yyvsp[-9].term);
		    if (yyvsp[-7].string != NULL) string_StringFree(yyvsp[-7].string);
		    dfg_DeleteStringList(yyvsp[-4].list);
		  }
		  dfg_VarCheck();
		;}
    break;

  case 205:
#line 945 "dfgparser.y"
    { yyval.list = (dfg_IGNORE||yyvsp[0].string==NULL) ? list_Nil() : list_List(yyvsp[0].string); ;}
    break;

  case 206:
#line 947 "dfgparser.y"
    { yyval.list = (dfg_IGNORE||yyvsp[0].string==NULL) ? yyvsp[-2].list : list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].string)); ;}
    break;

  case 207:
#line 951 "dfgparser.y"
    { yyval.number = 0; ;}
    break;

  case 208:
#line 952 "dfgparser.y"
    { yyval.number = yyvsp[-1].number; ;}
    break;

  case 209:
#line 956 "dfgparser.y"
    { if (!dfg_IGNORE && yyvsp[-2].string!=NULL && yyvsp[0].string!=NULL && string_Equal(yyvsp[-2].string,"splitlevel"))
		      string_StringToInt(yyvsp[0].string, TRUE, &yyval.number);
		    else
		      yyval.number = 0;
		    if (yyvsp[-2].string != NULL) string_StringFree(yyvsp[-2].string);
		    if (yyvsp[0].string != NULL) string_StringFree(yyvsp[0].string);
		  ;}
    break;

  case 210:
#line 964 "dfgparser.y"
    { if (!dfg_IGNORE && yyvsp[-2].string!=NULL && yyvsp[0].string!=NULL && string_Equal(yyvsp[-2].string,"splitlevel"))
		      string_StringToInt(yyvsp[0].string, TRUE, &yyval.number);
		    else
		      yyval.number = yyvsp[-4].number;
		    if (yyvsp[-2].string != NULL) string_StringFree(yyvsp[-2].string);
		    if (yyvsp[0].string != NULL) string_StringFree(yyvsp[0].string);
		  ;}
    break;

  case 211:
#line 974 "dfgparser.y"
    { stack_Push((POINTER) dfg_IGNORE); dfg_IGNORE = TRUE; ;}
    break;

  case 212:
#line 976 "dfgparser.y"
    { dfg_IGNORE = (BOOL) stack_PopResult();
		    if (yyvsp[0].bool) {
		      if (yyvsp[-2].string != NULL) string_StringFree(yyvsp[-2].string);
		      yyval.string = NULL;
		    } else
		      yyval.string = yyvsp[-2].string;
		  ;}
    break;

  case 213:
#line 985 "dfgparser.y"
    { yyval.string = yyvsp[0].string; ;}
    break;

  case 214:
#line 986 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 215:
#line 987 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 216:
#line 988 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 217:
#line 989 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 218:
#line 990 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 219:
#line 991 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 220:
#line 992 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 221:
#line 993 "dfgparser.y"
    { yyval.string = NULL; ;}
    break;

  case 222:
#line 996 "dfgparser.y"
    { yyval.bool = FALSE; ;}
    break;

  case 223:
#line 997 "dfgparser.y"
    { yyval.bool = TRUE; ;}
    break;

  case 224:
#line 998 "dfgparser.y"
    { yyval.bool = TRUE; ;}
    break;

  case 225:
#line 1001 "dfgparser.y"
    { yyval.term = yyvsp[0].term;   ;}
    break;

  case 226:
#line 1002 "dfgparser.y"
    { yyval.term = NULL; ;}
    break;

  case 229:
#line 1014 "dfgparser.y"
    { dfg_VarStart(); ;}
    break;

  case 230:
#line 1015 "dfgparser.y"
    {
                                          dfg_VarStop();
                                          dfg_VarBacktrack();
                                          dfg_VarCheck(); ;}
    break;

  case 232:
#line 1022 "dfgparser.y"
    { dfg_TERMLIST = list_Nconc(dfg_TERMLIST, list_List(yyvsp[-1].term)); ;}
    break;

  case 236:
#line 1034 "dfgparser.y"
    { if (string_Equal(yyvsp[0].string,"SPASS"))
					    dfg_IGNORETEXT = FALSE;
					  string_StringFree(yyvsp[0].string);
					;}
    break;

  case 237:
#line 1039 "dfgparser.y"
    { dfg_IGNORETEXT = TRUE; ;}
    break;

  case 238:
#line 1042 "dfgparser.y"
    { /* no SPASS flags */
				  string_StringFree(yyvsp[0].string);
				;}
    break;

  case 245:
#line 1056 "dfgparser.y"
    { SYMBOL s;
		    for ( ; !list_Empty(yyvsp[-1].list); yyvsp[-1].list = list_Pop(yyvsp[-1].list)) {
		      s = symbol_Lookup(list_Car(yyvsp[-1].list));
		      if (s == 0) {
		        misc_StartUserErrorReport();
		        misc_UserErrorReport("\n Undefined symbol %s", list_Car(yyvsp[-1].list));
			misc_UserErrorReport(" in DomPred list.\n"); 
			misc_FinishUserErrorReport(); 
		      }
		      if (!symbol_IsPredicate(s)) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Symbol %s isn't a predicate", list_Car(yyvsp[-1].list));
			misc_UserErrorReport(" in DomPred list.\n");
			misc_FinishUserErrorReport();
		      }
		      string_StringFree(list_Car(yyvsp[-1].list)); 
		      symbol_AddProperty(s, DOMPRED);
		    }
		  ;}
    break;

  case 246:
#line 1076 "dfgparser.y"
    { int flag = flag_Id(yyvsp[-3].string);
		    if (flag == -1) {
		      misc_StartUserErrorReport();
		      misc_UserErrorReport("\n Found unknown flag %s", yyvsp[-3].string);
		      misc_FinishUserErrorReport();
		    }
		    string_StringFree(yyvsp[-3].string);
		    flag_SetFlagValue(dfg_FLAGS, flag, yyvsp[-1].number);
		  ;}
    break;

  case 249:
#line 1092 "dfgparser.y"
    { SYMBOL s = symbol_Lookup(yyvsp[0].string);
		      if (s == 0) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Undefined symbol %s ", yyvsp[0].string);
			misc_UserErrorReport(" in precedence list.\n"); 
			misc_FinishUserErrorReport(); 
		      }
		      string_StringFree(yyvsp[0].string);
		      symbol_SetIncreasedOrdering(dfg_PRECEDENCE, s);
                      dfg_USERPRECEDENCE = list_Cons((POINTER)s, dfg_USERPRECEDENCE);
		    ;}
    break;

  case 250:
#line 1104 "dfgparser.y"
    { SYMBOL s = symbol_Lookup(yyvsp[-4].string);
		      if (s == 0) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Undefined symbol %s", yyvsp[-4].string);
			misc_UserErrorReport("in precedence list.\n");
			misc_FinishUserErrorReport(); 
		      }
		      string_StringFree(yyvsp[-4].string);
		      symbol_SetIncreasedOrdering(dfg_PRECEDENCE, s);
                      dfg_USERPRECEDENCE = list_Cons((POINTER)s, dfg_USERPRECEDENCE);
		      symbol_SetWeight(s, yyvsp[-2].number);
		      if (yyvsp[-1].property != 0)
			symbol_AddProperty(s, yyvsp[-1].property);
		    ;}
    break;

  case 253:
#line 1125 "dfgparser.y"
    {
		      dfg_CLAXRELATION = list_Cons(list_Cons((POINTER)yyvsp[-3].number, dfg_CLAXAXIOMS), dfg_CLAXRELATION);
		      dfg_CLAXAXIOMS   = list_Nil();
		    ;}
    break;

  case 256:
#line 1136 "dfgparser.y"
    {
		      dfg_CLAXAXIOMS = list_Cons((POINTER)yyvsp[0].string, dfg_CLAXAXIOMS);
                    ;}
    break;

  case 259:
#line 1146 "dfgparser.y"
    { SYMBOL s = symbol_Lookup(yyvsp[0].string);
		      if (s == 0) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Undefined symbol %s ", yyvsp[0].string);
			misc_UserErrorReport(" in selection list.\n"); 
			misc_FinishUserErrorReport(); 
		      }
		      if (!symbol_IsPredicate(s)) {
			misc_StartUserErrorReport();
			misc_UserErrorReport("\n Symbol %s isn't a predicate", yyvsp[0].string);
			misc_UserErrorReport(" in selection list.\n");
			misc_FinishUserErrorReport();
		      }
		      string_StringFree(yyvsp[0].string);
                      dfg_USERSELECTION = list_Cons((POINTER)s, dfg_USERSELECTION);
		    ;}
    break;

  case 260:
#line 1164 "dfgparser.y"
    { yyval.property = 0; /* left */ ;}
    break;

  case 261:
#line 1166 "dfgparser.y"
    { if (yyvsp[0].string[1] != '\0' ||
			  (yyvsp[0].string[0]!='l' && yyvsp[0].string[0]!='m' && yyvsp[0].string[0]!='r')) {
		         misc_StartUserErrorReport();
			 misc_UserErrorReport("\n Invalid symbol status %s", yyvsp[0].string);
			 misc_UserErrorReport(" in precedence list.");
			 misc_FinishUserErrorReport();
		      }
		      switch (yyvsp[0].string[0]) {
		      case 'm': yyval.property = ORDMUL;   break;
		      case 'r': yyval.property = ORDRIGHT; break;
		      default:  yyval.property = 0;
		      }
		      string_StringFree(yyvsp[0].string);
		    ;}
    break;

  case 264:
#line 1187 "dfgparser.y"
    { dfg_DeleteStringList(yyvsp[-2].list); ;}
    break;

  case 265:
#line 1190 "dfgparser.y"
    { yyval.list = list_List(yyvsp[0].string); ;}
    break;

  case 266:
#line 1191 "dfgparser.y"
    { yyval.list = list_Nconc(yyvsp[-2].list, list_List(yyvsp[0].string)); ;}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 3157 "dfgparser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
	  yychar = YYEMPTY;

	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1194 "dfgparser.y"


void yyerror(const char *s)
{
  misc_StartUserErrorReport();
  misc_UserErrorReport("\n Line %i: %s\n", dfg_LINENUMBER, s);
  misc_FinishUserErrorReport();
}

static void dfg_Init(FILE* Input, FLAGSTORE Flags, PRECEDENCE Precedence)
/**************************************************************
  INPUT:   The input file stream for the parser, a flag store and
           a precedence.
  RETURNS: Nothing.
  EFFECT:  The parser and scanner are initialized.
           The parser will use the flag store and the precedence
	   to memorize the settings from the input file.
***************************************************************/
{
  extern FILE* dfg_in;  /* declared in dfgscanner */

  dfg_in               = Input;
  dfg_LINENUMBER       = 1;
  dfg_IGNORETEXT       = TRUE;
  dfg_AXIOMLIST        = list_Nil();
  dfg_CONJECLIST       = list_Nil();
  dfg_SORTDECLLIST     = list_Nil();
  dfg_USERPRECEDENCE   = list_Nil();
  dfg_USERSELECTION    = list_Nil();
  dfg_CLAXRELATION     = list_Nil();
  dfg_CLAXAXIOMS       = list_Nil();
  dfg_AXCLAUSES        = list_Nil();
  dfg_CONCLAUSES       = list_Nil();
  dfg_PROOFLIST        = list_Nil();
  dfg_TERMLIST         = list_Nil();
  dfg_SYMBOLLIST       = list_Nil();
  dfg_VARLIST          = list_Nil();
  dfg_PLAINAXCLAUSES   = list_Nil();
  dfg_PLAINCONCLAUSES  = list_Nil();
  dfg_TEMPPLAINCLAUSES = list_Nil();
  dfg_SELECTED_LITERAL = (TERM) NULL;
  dfg_VARDECL          = FALSE;
  dfg_IGNORE           = FALSE;
  dfg_FLAGS            = Flags;
  dfg_PRECEDENCE       = Precedence;
  dfg_DESC.name        = (char*) NULL;
  dfg_DESC.author      = (char*) NULL;
  dfg_DESC.version     = (char*) NULL;
  dfg_DESC.logic       = (char*) NULL;
  dfg_DESC.status      = DFG_UNKNOWNSTATE;
  dfg_DESC.description = (char*) NULL;
  dfg_DESC.date        = (char*) NULL;
}


void dfg_Free(void)
/**************************************************************
  INPUT:   None.
  RETURNS: Nothing.
  EFFECT:  Frees memory used by the problem description.
***************************************************************/
{
  if (dfg_DESC.name != NULL)
    string_StringFree(dfg_DESC.name);
  if (dfg_DESC.author != NULL)
    string_StringFree(dfg_DESC.author);
  if (dfg_DESC.version != NULL)
    string_StringFree(dfg_DESC.version);
  if (dfg_DESC.logic != NULL)
    string_StringFree(dfg_DESC.logic);
  if (dfg_DESC.description != NULL)
    string_StringFree(dfg_DESC.description);
  if(dfg_DESC.date != NULL)
    string_StringFree(dfg_DESC.date);
}

const char* dfg_ProblemName(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The problem's name from the description section.
***************************************************************/
{
  return dfg_DESC.name;
}

const char* dfg_ProblemAuthor(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The problem's author from the description section.
***************************************************************/
{
  return dfg_DESC.author;
}

const char* dfg_ProblemVersion(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The problem's version from the description section.
***************************************************************/
{
  return dfg_DESC.version;
}

const char* dfg_ProblemLogic(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The problem's logic from the description section.
***************************************************************/
{
  return dfg_DESC.logic;
}

DFG_STATE dfg_ProblemStatus(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The problem's status from the description section.
***************************************************************/
{
  return dfg_DESC.status;
}

const char* dfg_ProblemStatusString(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The string representation of the problem's status.
***************************************************************/
{
  const char* result = "";

  switch (dfg_DESC.status) {
  case DFG_SATISFIABLE:
    result = "satisfiable"; break;
  case DFG_UNSATISFIABLE:
    result = "unsatisfiable"; break;
  case DFG_UNKNOWNSTATE:
    result = "unknown"; break;
  default:
    misc_StartErrorReport();
    misc_ErrorReport("\n In dfg_ProblemStatusString: Invalid status.\n");
    misc_FinishErrorReport();
  }
  return result;
}

const char* dfg_ProblemDescription(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The problem's description from the description section.
***************************************************************/
{
  return dfg_DESC.description;
}

const char* dfg_ProblemDate(void)
/**************************************************************
  INPUT:   None.
  RETURNS: The problem's date from the description section.
***************************************************************/
{
  return dfg_DESC.date;
}

void dfg_FPrintDescription(FILE* File)
/**************************************************************
  INPUT:   A file stream.
  RETURNS: Nothing.
  EFFECT:  The description section from the input file
           is printed to 'File'. You must call the parser first
           before calling this function.
***************************************************************/
{
  fputs("list_of_descriptions.\n  name(", File);
  if (dfg_DESC.name != NULL)
    fputs(dfg_DESC.name, File);
  else
    fputs("{* *}", File);
  fputs(").\n  author(", File);
  if (dfg_DESC.author != NULL)
    fputs(dfg_DESC.author, File);
  else
    fputs("{* *}", File);
  fputs(").\n", File);
  if (dfg_DESC.version != NULL) {
    fputs("  version(", File);
    fputs(dfg_DESC.version, File);
    fputs(").\n", File);
  }
  if (dfg_DESC.logic != NULL) {
    fputs("  logic(", File);
    fputs(dfg_DESC.logic, File);
    fputs(").\n", File);
  }
  fputs("  status(", File);
  fputs(dfg_ProblemStatusString(), File);
  fputs(").\n  description(", File);
  if (dfg_DESC.description != NULL)
    fputs(dfg_DESC.description, File);
  else
    fputs("{* *}", File);
  fputs(").\n", File);
  if (dfg_DESC.date != NULL) {
    fputs("  date(", File);
    fputs(dfg_DESC.date, File);
    fputs(").\n", File);
  }
  fputs("end_of_list.", File);
}

void dfg_DeleteClAxRelation(LIST ClAxRelation)
{
  LIST Scan1, Scan2;

  for (Scan1=ClAxRelation;!list_Empty(Scan1);Scan1=list_Cdr(Scan1)) {
    for (Scan2=list_Cdr(list_Car(Scan1));!list_Empty(Scan2);Scan2=list_Cdr(Scan2))
      string_StringFree((char *)list_Car(Scan2));
    list_Delete(list_Car(Scan1));
  }
  list_Delete(ClAxRelation);
}


LIST dfg_DFGParser(FILE* File, FLAGSTORE Flags, PRECEDENCE Precedence,
		   LIST* Axioms, LIST* Conjectures, LIST* SortDecl,
		   LIST* UserDefinedPrecedence, LIST* UserDefinedSelection,
		   LIST* ClAxRelation, BOOL* HasPlainClauses)
/**************************************************************
  INPUT:   The input file containing clauses or formulae in DFG syntax,
           a flag store and a precedence used to memorize settings
	   from the file.
           Axioms, Conjectures, SortDecl, UserDefinedPrecedence
           UserDefinedSelection, and ClAxRelation are
	   pointers to lists used as return values.
           HasPlainClauses is a return value to indicate if
           the problem had clauses in the plain format.
  RETURNS: The list of clauses from File.
  EFFECT:  Reads formulae and clauses from the input file.
           The axioms, conjectures, sort declarations and user-defined
	   precedences are appended to the respective lists, the lists
	   are not deleted!
	   All lists except the returned clause list contain pairs
	   (label, term), where <label> may be NULL, if no
	   label was specified for that term.
	   <UserDefinedPrecedence> contains symbols sorted by decreasing
	   precedence. This list will only be changed, if the precedence
	   is explicitly defined in the input file. This can be done
	   by the 'set_precedence' flag in the SPASS settings list in
	   the DFG input file.
           <UserDefinedSelection> is set to a list of predicates to be
           selected in clause inferences by the 'set_selection' flag
           <ClAxRelation> is set to a clause, axiom relation where the
           clauses are given by their number, the axioms by name (string)
  CAUTION: The weight of the clauses is not correct and the literals
           are not oriented!
***************************************************************/
{
  LIST  scan, tupel;
  TERM  clauseTerm;
  NAT   bottom;

  dfg_Init(File, Flags, Precedence);  /* Initialize the parser and scanner */
  bottom = stack_Bottom();
  dfg_parse();          /* Invoke the parser */
#ifdef CHECK 
  if (!stack_Empty(bottom)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In dfg_DFGParser: Stack not empty!\n");
    misc_FinishErrorReport();
  }
#endif
  dfg_SymCleanUp();

  /* Remove clause labels and create clauses from the terms */
  for (scan = dfg_AXCLAUSES; !list_Empty(scan); scan = list_Cdr(scan)) {
    tupel = list_Car(scan);
    clauseTerm = list_PairSecond(tupel);
    list_Rplaca(scan, dfg_CreateClauseFromTerm(clauseTerm,TRUE, Flags, Precedence));
    if (list_PairFirst(tupel) != NULL)        /* Label is defined */
      string_StringFree(list_PairFirst(tupel));  /* Delete the label */
    list_PairFree(tupel);
  }
  /* Since dfg_CreateClauseFromTerm() returns NULL for trivial tautologies */
  /* we now delete those NULL pointers from the clause list.               */
  dfg_AXCLAUSES = list_PointerDeleteElement(dfg_AXCLAUSES, NULL);
  for (scan = dfg_CONCLAUSES; !list_Empty(scan); scan = list_Cdr(scan)) {
    tupel = list_Car(scan);
    clauseTerm = list_PairSecond(tupel);
    list_Rplaca(scan, dfg_CreateClauseFromTerm(clauseTerm,FALSE, Flags, Precedence));
    if (list_PairFirst(tupel) != NULL)        /* Label is defined */
      string_StringFree(list_PairFirst(tupel));  /* Delete the label */
    list_PairFree(tupel);
  }
  /* Since dfg_CreateClauseFromTerm() returns NULL for trivial tautologies */
  /* we now delete those NULL pointers from the clause list.               */
  dfg_CONCLAUSES = list_PointerDeleteElement(dfg_CONCLAUSES, NULL);

  /* Delete the proof list */
  dfg_DeleteProofList(dfg_PROOFLIST);

  /* Delete the list_of_terms, since it'll be ignored */
  term_DeleteTermList(dfg_TERMLIST);

  if (list_Empty(dfg_PLAINAXCLAUSES) && list_Empty(dfg_PLAINCONCLAUSES))
    *HasPlainClauses = FALSE;
  else
    *HasPlainClauses = TRUE;
  
  for(scan = dfg_PLAINAXCLAUSES;  !list_Empty(scan); scan = list_Cdr(scan)) {
    DFG_PLAINCLAUSE clause = list_Car(scan);
    CLAUSE newclause = clause_CreateFromLiteralLists(clause->constraint, clause->antecedent, 
                                                     clause->succedent, FALSE, clause->selected);
    dfg_AXCLAUSES = list_Nconc(dfg_AXCLAUSES, list_List(newclause));
  }
  list_DeleteWithElement(dfg_PLAINAXCLAUSES, (void (*)(POINTER)) dfg_PlainClauseFree);
  
  for(scan = dfg_PLAINCONCLAUSES;  !list_Empty(scan); scan = list_Cdr(scan)) {
    DFG_PLAINCLAUSE clause = list_Car(scan);
    CLAUSE newclause = clause_CreateFromLiteralLists(clause->constraint, clause->antecedent, 
                                                     clause->succedent, TRUE, clause->selected);
    dfg_CONCLAUSES = list_Nconc(dfg_CONCLAUSES, list_List(newclause));
  }
  list_DeleteWithElement(dfg_PLAINCONCLAUSES, (void (*)(POINTER)) dfg_PlainClauseFree);
   
  scan = list_Nconc(dfg_AXCLAUSES, dfg_CONCLAUSES);

  *Axioms      = list_Nconc(*Axioms, dfg_AXIOMLIST);
  *Conjectures = list_Nconc(*Conjectures, dfg_CONJECLIST);
  *SortDecl    = list_Nconc(*SortDecl, dfg_SORTDECLLIST);
  list_NReverse(dfg_USERPRECEDENCE);
  *UserDefinedPrecedence = list_Nconc(*UserDefinedPrecedence, dfg_USERPRECEDENCE);
  *UserDefinedSelection  = dfg_USERSELECTION;
  *ClAxRelation          = dfg_CLAXRELATION;

  return scan;
}

LIST dfg_ProofParser(FILE* File, FLAGSTORE Flags, PRECEDENCE Precedence)
/**************************************************************
  INPUT:   The input file containing clauses in DFG syntax,
           a flag store and a precedence used to memorize settings
           from the file.
  RETURNS: A list of tuples (label,clause,justificationlist,splitlevel,origin)
           representing a proof.
  EFFECT:  Reads inputs clauses with labels and the proof lists
           from the input file.
           The elements of the list are lists with five items.
	   1. the label (a string) of a clause,
	   2. the clause in TERM format,
           3. the list of justification labels (strings, too),
           4. the split level of the clause,
           5. the origin of the clause (RULE struct from clause.h).
	   Note that the justification list is empty for input
	   clauses.
***************************************************************/
{
  LIST  scan, tupel;
  TERM  term;
  NAT   bottom;

  dfg_Init(File, Flags, Precedence);  /* Initialize the parser and scanner */
  bottom = stack_Bottom();
  dfg_parse();          /* Invoke the parser */
#ifdef CHECK 
  if (!stack_Empty(bottom)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In dfg_ProofParser: Stack not empty!\n");
    misc_FinishErrorReport();
  }
#endif

  dfg_SymCleanUp();

  /* Build the union of axiom and conjecture clauses */
  dfg_AXCLAUSES  = list_Nconc(dfg_AXCLAUSES, dfg_CONCLAUSES);
  dfg_CONCLAUSES = list_Nil();
  for (scan = dfg_AXCLAUSES; !list_Empty(scan); scan = list_Cdr(scan)) {
    tupel = list_Car(scan);
    term  = list_PairSecond(tupel);
    if (list_PairFirst(tupel) == NULL) {
      /* Ignore input clauses without label */
      term_Delete(term);
      list_PairFree(tupel);
      list_Rplaca(scan, NULL);
    } else
      /* Expand the pair to a tuple                            */
      /* (label,clause,justificationlist, split level, origin) */
      /* For input clauses the justificationlist is empty.     */
      /* Input clauses have split level 0.                     */
      list_Rplacd(tupel, list_Cons(term,list_Cons(list_Nil(),list_Cons(0, list_List((POINTER)INPUT)))));
  }
  /* Now delete the list items without labels */
  dfg_AXCLAUSES = list_PointerDeleteElement(dfg_AXCLAUSES, NULL);

  /* Delete the formula lists */
  dfg_DeleteFormulaPairList(dfg_AXIOMLIST);
  dfg_DeleteFormulaPairList(dfg_CONJECLIST);
  /* Delete the list of sort declarations */
  dfg_DeleteFormulaPairList(dfg_SORTDECLLIST);
  /* Delete the list_of_terms, since it'll be ignored */
  term_DeleteTermList(dfg_TERMLIST);

  /* Finally append the proof list to the list of input clauses with labels */
  dfg_PROOFLIST = list_NReverse(dfg_PROOFLIST);
  dfg_AXCLAUSES = list_Nconc(dfg_AXCLAUSES, dfg_PROOFLIST);

  return dfg_AXCLAUSES;
}


LIST dfg_TermParser(FILE* File, FLAGSTORE Flags, PRECEDENCE Precedence)
/**************************************************************
  INPUT:   The input file containing a list of terms in DFG syntax,
           a flag store and a precedence used to memorize settings
	   from the file.
  RETURNS: The list of terms from <File>.
  EFFECT:  Reads terms from the list_of_terms from the input file.
***************************************************************/
{
  NAT bottom;
  
  dfg_Init(File, Flags, Precedence);   /* Initialize the parser and scanner */
  bottom = stack_Bottom();
  dfg_parse();          /* Invoke the parser */
#ifdef CHECK 
  if (!stack_Empty(bottom)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In dfg_TermParser: Stack not empty!\n");
    misc_FinishErrorReport();
  }
#endif

  dfg_SymCleanUp();

  /* Delete the clause lists */
  dfg_DeleteFormulaPairList(dfg_AXCLAUSES);
  dfg_DeleteFormulaPairList(dfg_CONCLAUSES);
  /* Delete the formula lists */
  dfg_DeleteFormulaPairList(dfg_AXIOMLIST);
  dfg_DeleteFormulaPairList(dfg_CONJECLIST);
  /* Delete the proof list */
  dfg_DeleteProofList(dfg_PROOFLIST);
  /* Delete the list of sort declarations */
  dfg_DeleteFormulaPairList(dfg_SORTDECLLIST);

  return dfg_TERMLIST;
}


void dfg_DeleteFormulaPairList(LIST FormulaPairs)
/**************************************************************
  INPUT:   A list of pairs (label, formula).
  RETURNS: Nothing.
  EFFECT:  The list and the pairs with their strings and terms
           are completely deleted.
***************************************************************/
{
  LIST pair;

  for ( ; !list_Empty(FormulaPairs); FormulaPairs = list_Pop(FormulaPairs)) {
    pair = list_Car(FormulaPairs);  /* (label, term) */
    term_Delete(list_PairSecond(pair));
    if (list_PairFirst(pair) != NULL)
      string_StringFree(list_PairFirst(pair));  /* Free the label */
    list_PairFree(pair);
  }
}

void dfg_StripLabelsFromList(LIST FormulaPairs)
/**************************************************************
  INPUT:   A list of pairs (label, formula).
  RETURNS: Nothing.
  EFFECT:  The pairs are replaced by the respective formula
           and the pairs with their label strings are deleted.
***************************************************************/
{
  LIST pair, scan;

  for (scan = FormulaPairs; !list_Empty(scan); scan = list_Cdr(scan)) {
    pair = list_Car(scan);  /* (label, term) */
    list_Rplaca(scan, list_PairSecond(pair));
    if (list_PairFirst(pair) != NULL)
      string_StringFree(list_PairFirst(pair));  /* Free the label */
    list_PairFree(pair);
  }
}

void dfg_DeleteProofList(LIST Proof)
/**************************************************************
  INPUT:   A list of tuples (label, term, justificationlist, split level).
  RETURNS: Nothing.
  EFFECT:  All memory used by the proof list is freed.
           The labels must NOT be NULL entries!
***************************************************************/
{
  /* Delete the proof list */
  for ( ; !list_Empty(Proof); Proof = list_Pop(Proof)) {
    LIST tupel = list_Car(Proof);
    string_StringFree(list_First(tupel));
    term_Delete(list_Second(tupel));
    dfg_DeleteStringList(list_Third(tupel));
    list_Delete(tupel);
  }
}

/**************************************************************/
/* Static Functions                                           */
/**************************************************************/

static void dfg_SymbolDecl(int SymbolType, char* Name, int Arity)
/**************************************************************
  INPUT:   The type of a symbol, the name, and the arity.
  RETURNS: Nothing.
  EFFECT:  This function handles the declaration of symbols.
           If <Arity> is -2, it means that the arity of the symbol
	   was not specified, if it is -1 the symbol is declared
	   with arbitrary arity. User defined symbols with arbitrary
           arity are not allowed.
	   The <Name> is deleted.
***************************************************************/
{
  NAT    arity, length;
  SYMBOL symbol;

  switch (Arity) {
  case -2: /* not specified */
    arity = 0;
    break;
  case -1:
    misc_StartUserErrorReport();
    misc_UserErrorReport("\n Line %u: symbols with arbitrary arity are not allowed.\n",
	    dfg_LINENUMBER);
    misc_FinishUserErrorReport();
  default:
    arity = Arity;
}

  /* Pay attention to the maximum symbol name length */
  length = strlen(Name);
  if (length >= symbol__SYMBOLMAXLEN)
    Name[symbol__SYMBOLMAXLEN-1] = '\0';

  /* Check if this symbol was declared earlier */
  symbol = symbol_Lookup(Name);
  if (symbol != 0) {
    /* Symbol was declared before */
    /* Check if the old and new symbol type are equal */
    if ((SymbolType == DFG_FUNC && !symbol_IsFunction(symbol)) ||
	(SymbolType == DFG_PRDICAT && !symbol_IsPredicate(symbol)) ||
	((SymbolType == DFG_OPERAT || SymbolType == DFG_QUANTIF) && 
	 !symbol_IsJunctor(symbol))) {
      misc_StartUserErrorReport();
      misc_UserErrorReport("\n Line %u: symbol %s was already declared as ",
	      dfg_LINENUMBER, Name);
      switch (symbol_Type(symbol)) {
      case symbol_CONSTANT:
      case symbol_FUNCTION:
	misc_UserErrorReport("function.\n"); break;
      case symbol_PREDICATE:
	misc_UserErrorReport("predicate.\n"); break;
      case symbol_JUNCTOR:
	misc_UserErrorReport("junctor.\n"); break;
      default:
	misc_UserErrorReport("unknown type.\n");
      }
      misc_FinishUserErrorReport();
    }
    /* Now check the old and new arity if specified */
    if (Arity != -2 && Arity != symbol_Arity(symbol)) {
      misc_StartUserErrorReport();
      misc_UserErrorReport("\n Line %u: symbol %s was already declared with arity %d\n",
			   dfg_LINENUMBER, Name, symbol_Arity(symbol));
      misc_FinishUserErrorReport();
    }
  } else {
    /* Symbol was not declared before */
    switch (SymbolType) {
    case DFG_FUNC:
      symbol = symbol_CreateFunction(Name, arity, symbol_STATLEX,dfg_PRECEDENCE);
      break;
    case DFG_PRDICAT:
      symbol = symbol_CreatePredicate(Name, arity,symbol_STATLEX,dfg_PRECEDENCE);
      break;
    default:
      symbol = symbol_CreateJunctor(Name, arity, symbol_STATLEX, dfg_PRECEDENCE);
    }
    if (Arity == -2)
      /* Arity wasn't specified so check the arity for each occurrence */
      dfg_SymAdd(symbol);
  }

  if (length >= symbol__SYMBOLMAXLEN) {
    /* To avoid a memory error restore the old string length */
    Name[symbol__SYMBOLMAXLEN-1] = ' ';  /* Something != '\0' */
  }
  string_StringFree(Name);  /* Name was copied */
}


static SYMBOL dfg_Symbol(char* Name, NAT Arity)
/**************************************************************
  INPUT:   The name of a symbol and the actual arity of the symbol.
  RETURNS: The corresponding SYMBOL.
  EFFECT:  This function checks if the <Name> was declared as
           symbol or variable. If not, an error message is printed
	   to stderr.
	   The <Name> is deleted.
***************************************************************/
{
  SYMBOL symbol;
  char   old;
  NAT    length;

  old = ' ';  /* Just to avoid a compiler warning */
  /* Pay attention to the maximum symbol name length */
  length = strlen(Name);
  if (length >= symbol__SYMBOLMAXLEN) {
    old = Name[symbol__SYMBOLMAXLEN-1];
    Name[symbol__SYMBOLMAXLEN-1] = '\0';
  }

  symbol = symbol_Lookup(Name);
  if (length >= symbol__SYMBOLMAXLEN) {
    /* To avoid a memory error restore the old string */
    Name[symbol__SYMBOLMAXLEN-1] = old;
  }
  if (symbol != 0) {
    string_StringFree(Name);
    dfg_SymCheck(symbol, Arity); /* Check the arity */
  } else {
    /* Variable */
    if (Arity > 0) {
      misc_StartUserErrorReport();
      misc_UserErrorReport("\n Line %d: Undefined symbol %s.\n",dfg_LINENUMBER,Name);
      misc_FinishUserErrorReport();
    }
    symbol = dfg_VarLookup(Name);
  }
  return symbol;
}


TERM dfg_CreateQuantifier(SYMBOL Symbol, LIST VarTermList, TERM Term)
/**************************************************************
  INPUT:   A quantifier symbol, a list possibly containing sorts,
           and a term.
  RETURNS: The created quantifier term..
***************************************************************/
{
  LIST varlist, sortlist, scan;
  TERM helpterm;

  /* First collect the variable symbols in varlist and the sorts in sortlist */
  varlist = sortlist = list_Nil();
  for ( ; !list_Empty(VarTermList); VarTermList = list_Pop(VarTermList)) {
    helpterm = list_Car(VarTermList);
    if (term_IsVariable(helpterm)) {
      varlist = list_Nconc(varlist, list_List((POINTER)term_TopSymbol(helpterm)));
      term_Delete(helpterm);
    } else {
      SYMBOL var = term_TopSymbol(term_FirstArgument(helpterm));
      varlist  = list_Nconc(varlist, list_List((POINTER)var));
      sortlist = list_Nconc(sortlist, list_List(helpterm));
    }
  }

  varlist = list_PointerDeleteDuplicates(varlist);
  /* Now create terms from the variables */
  for (scan = varlist; !list_Empty(scan); scan = list_Cdr(scan))
    list_Rplaca(scan, term_Create((SYMBOL)list_Car(scan), list_Nil()));

  if (!list_Empty(sortlist)) {
    if (symbol_Equal(fol_All(), Symbol)) {
      /* The conjunction of all sortterms implies the Term */
      if (symbol_Equal(fol_Or(), term_TopSymbol(Term))) {
	/* Special treatment if <Term> is a term with "or" like */
	/* in clauses: add all sort terms negated to the args    */
	/* of the "or" */
	for (scan = sortlist; !list_Empty(scan); scan = list_Cdr(scan))
	  /* Negate the sort terms */
	  list_Rplaca(scan, term_Create(fol_Not(), list_List(list_Car(scan))));
	sortlist = list_Nconc(sortlist, term_ArgumentList(Term));
	term_RplacArgumentList(Term, sortlist);
      } else {
	/* No "or" term, so build the implication term */
	if (list_Empty(list_Cdr(sortlist))) {
	  /* Only one sort term */
	  list_Rplacd(sortlist, list_List(Term));
	  Term = term_Create(fol_Implies(), sortlist);
	} else {
	  /* More than one sort term */
	  helpterm = term_Create(fol_And(), sortlist);
	  Term = term_Create(fol_Implies(), list_Cons(helpterm, list_List(Term)));
	}
      }
    } else if (symbol_Equal(fol_Exist(), Symbol)) {
      /* Quantify the conjunction of all sort terms and <Term> */
      if (symbol_Equal(fol_And(), term_TopSymbol(Term))) {
	/* Special treatment if <Term> has an "and" as top symbol: */
	/* just add the sort terms to the args of the "and".       */
	sortlist = list_Nconc(sortlist, term_ArgumentList(Term));
	term_RplacArgumentList(Term, sortlist);
      } else {
	sortlist = list_Nconc(sortlist, list_List(Term));
	Term = term_Create(fol_And(), sortlist);
      }
    }
  }
  helpterm = fol_CreateQuantifier(Symbol, varlist, list_List(Term));
  return helpterm;
}


CLAUSE dfg_CreateClauseFromTerm(TERM Clause, BOOL IsAxiom, FLAGSTORE Flags,
				PRECEDENCE Precedence)
/**************************************************************
  INPUT:   A clause term, a boolean value, a flag store and a precedence.
  RETURNS: The clause term converted to a CLAUSE.
  EFFECT:  This function converts a clause stored as term into an
           EARL clause structure.
	   If 'IsAxiom' is TRUE the clause is treated as axiom
	   clause else as conjecture clause.
           The function deletes the literals "false" and "not(true)"
           if they occur in <Clause>.
	   The contents of the flag store and the precedence are changed
	   because the parser read flag and precedence settings from
  MEMORY:  The clause term is deleted.
***************************************************************/
{
  LIST   literals, scan;
  TERM   literal;
  CLAUSE result;
  
  if (term_TopSymbol(Clause) == fol_All()) {
    /* Remove and free the quantifier and the OR term */
    literals = term_ArgumentList(term_SecondArgument(Clause));
    term_RplacArgumentList(term_SecondArgument(Clause), list_Nil());
  } else {
    /* Remove and free the OR term */
    literals = term_ArgumentList(Clause);
    term_RplacArgumentList(Clause, list_Nil());
  }
  term_Delete(Clause);

  for (scan = literals; !list_Empty(scan); scan = list_Cdr(scan)) {
    literal = (TERM) list_Car(scan);
    if (symbol_IsPredicate(term_TopSymbol(literal))) {  /* Positive literal */
      if (fol_IsFalse(literal)) {
	/* Ignore this literal */
	term_Delete(literal);
	list_Rplaca(scan, NULL); /* Mark the actual list element */
      }
    } else {
      /* Found a negative literal */
      TERM atom = term_FirstArgument(literal);
      if (fol_IsTrue(atom)) {
	/* Ignore this literal */
	term_Delete(literal);
	list_Rplaca(literals, NULL); /* Mark the actual list element */
      }
    }
  }
  

  literals = list_PointerDeleteElement(literals, NULL);
  /* Remove the special literals treated above from the list */
  result = clause_CreateFromLiterals(literals, FALSE, !IsAxiom, FALSE, Flags, Precedence);
  /* Don't create sorts! */
  list_Delete(literals);

  return result;
}


static void dfg_SubSort(char* Name1, char* Name2)
/**************************************************************
  INPUT:   Two sort symbol names.
  RETURNS: Nothing.
  EFFECT:  This functions adds the formula
           forall([U], implies(Name1(U), Name2(U)))
	   to the list of axiom formulas. Both <Name1> and <Name2>
	   are deleted.
***************************************************************/
{
  SYMBOL s1, s2;
  TERM   varterm, t1, t2, term;

  s1 = dfg_Symbol(Name1, 1);   /* Should be unary predicates */
  s2 = dfg_Symbol(Name2, 1);
  if (!symbol_IsPredicate(s1)) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("\n Line %d: Symbol is not a sort predicate.\n", dfg_LINENUMBER);
    misc_FinishUserErrorReport();
  }
  if (!symbol_IsPredicate(s2)) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("\n Line %d: Symbol is not a sort predicate.\n", dfg_LINENUMBER);
    misc_FinishUserErrorReport();
  }

  varterm = term_Create(symbol_CreateStandardVariable(), list_Nil());
  symbol_ResetStandardVarCounter();
  
  t1   = term_Create(s1, list_List(varterm));
  t2   = term_Create(s2, list_List(term_Copy(varterm)));
  term = term_Create(fol_Implies(), list_Cons(t1, list_List(t2)));
  term = fol_CreateQuantifier(fol_All(), list_List(term_Copy(varterm)),
			      list_List(term));
  dfg_SORTDECLLIST = list_Nconc(dfg_SORTDECLLIST, list_List(list_PairCreate(NULL,term)));
}


static void dfg_SymbolGenerated(SYMBOL SortPredicate, BOOL FreelyGenerated,
				LIST GeneratedBy)
/**************************************************************
  INPUT:   A sort predicate, a boolean flag, and a list of function
           symbol names.
  RETURNS: Nothing.
  EFFECT:  This function stores the information that the <SortPredicate>
           is generated by the function symbols from the <GeneratedBy>
           list. The list contains only symbol names!
	   The <SortPredicate> AND the symbols from the list get
           the property GENERATED. Additionally the symbols get
	   the property FREELY, if the flag <FreelyGenerated> is TRUE.
***************************************************************/
{
  SYMBOL symbol;
  LIST   scan;

  if (!symbol_IsPredicate(SortPredicate)) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("\n Line %d: Symbol is not a sort predicate.\n", dfg_LINENUMBER);
    misc_FinishUserErrorReport();
  }
  /* First reset the old information */
  symbol_RemoveProperty(SortPredicate, GENERATED);
  symbol_RemoveProperty(SortPredicate, FREELY);
  list_Delete(symbol_GeneratedBy(SortPredicate));
  /* Now set the new information */
  symbol_AddProperty(SortPredicate, GENERATED);
  if (FreelyGenerated)
    symbol_AddProperty(SortPredicate, FREELY);
  for (scan = GeneratedBy; !list_Empty(scan); scan = list_Cdr(scan)) {
    symbol = symbol_Lookup(list_Car(scan));
    if (symbol == 0) {
      misc_StartUserErrorReport();
      misc_UserErrorReport("\n Line %d: undefined symbol %s.\n", dfg_LINENUMBER,
			   (char*)list_Car(scan));
      misc_FinishUserErrorReport();
    } else if (!symbol_IsFunction(symbol)) { /* must be function or constant */
      misc_StartUserErrorReport();
      misc_UserErrorReport("\n Line %d: Symbol is not a function.\n", dfg_LINENUMBER);
      misc_FinishUserErrorReport();
    }
    string_StringFree(list_Car(scan));
    list_Rplaca(scan, (POINTER)symbol);  /* change the name list to a symbol list */
    /* Set GENERATED properties for generating symbols */
    symbol_AddProperty(symbol, GENERATED);
    if (FreelyGenerated)
      symbol_AddProperty(symbol, FREELY);
  }
  symbol_SetGeneratedBy(SortPredicate, GeneratedBy);
}

static void dfg_TranslPairDecl(char* PropName, char* FoName)
/**************************************************************
  INPUT:   A propositional name/first order name pair
  RETURNS: Nothing.
  EFFECT:  Updates the appropriate list.
***************************************************************/
{
  SYMBOL PropSymbol, FoSymbol;
  
  PropSymbol = symbol_Lookup(PropName);
  FoSymbol = symbol_Lookup(FoName);
  
  if (PropSymbol == 0) {
  	fprintf(stderr, "Line %u: Undefined symbol %s\n", 
  									dfg_LINENUMBER, PropName); 
    misc_Error(); 
  }
  else if (FoName == 0) {
  	fprintf(stderr, "Line %u: Undefined symbol %s\n", 
  									dfg_LINENUMBER, FoName); 
    misc_Error(); 
  }
  else 
    eml_SetPropFoSymbolAssocList(PropSymbol,list_List((POINTER)FoSymbol));
  string_StringFree(PropName);  /* Names were copied */
  string_StringFree(FoName);  
}

/**************************************************************/
/* Functions for the Symbol Table                             */
/**************************************************************/

typedef struct {
  SYMBOL symbol;
  BOOL   valid;
  int    arity;
} DFG_SYMENTRY, *DFG_SYM;

static __inline__ DFG_SYM dfg_SymCreate(void)
{
  return (DFG_SYM) memory_Malloc(sizeof(DFG_SYMENTRY));
}

static __inline__ void dfg_SymFree(DFG_SYM Entry)
{
  memory_Free(Entry, sizeof(DFG_SYMENTRY));
}


static void dfg_SymAdd(SYMBOL Symbol)
/**************************************************************
  INPUT:   A symbol.
  RETURNS: Nothing.
  EFFECT:  This function adds 'Symbol' to the symbol list.
           The arity of these symbols will be checked every time
	   the symbol occurs.
***************************************************************/
{
  DFG_SYM newEntry = dfg_SymCreate();
  newEntry->symbol = Symbol;
  newEntry->valid  = FALSE;
  newEntry->arity  = 0;
  dfg_SYMBOLLIST = list_Cons(newEntry, dfg_SYMBOLLIST);
}


static void dfg_SymCheck(SYMBOL Symbol, NAT Arity)
/**************************************************************
  INPUT:   A symbol and the current arity of this symbol.
  RETURNS: Nothing.
  EFFECT:  This function compares the previous arity of 'Symbol'
           with the actual 'Arity'. If these values differ
	   the symbol's arity is set to arbitrary.
	   The arity of symbols whose arity was specified in
	   the symbol declaration section is checked and a warning
	   is printed to stderr in case of differences.
***************************************************************/
{
  LIST scan = dfg_SYMBOLLIST;
  while (!list_Empty(scan)) {
    DFG_SYM actEntry = (DFG_SYM) list_Car(scan);
    if (actEntry->symbol == Symbol) {
      if (actEntry->valid) {
	if (actEntry->arity != Arity) {
	  misc_StartUserErrorReport();
	  misc_UserErrorReport("\n Line %u:", dfg_LINENUMBER);
	  misc_UserErrorReport(" The actual arity %u", Arity);
	  misc_UserErrorReport(" of symbol %s differs", symbol_Name(Symbol));
	  misc_UserErrorReport(" from the previous arity %u.\n", actEntry->arity);
	  misc_FinishUserErrorReport();
	}
      } else {
	/* Not valid => first time */
	actEntry->arity = Arity;
	actEntry->valid = TRUE;
      }
      return;
    }
    scan = list_Cdr(scan);
  }

  /* Symbol isn't in SymbolList, so its arity was specified.        */
  /* Check if the specified arity corresponds with the actual arity */
  if (symbol_Arity(Symbol) != Arity) {
    misc_StartUserErrorReport();
    misc_UserErrorReport("\n Line %u: Symbol %s was declared with arity %u.\n",
			 dfg_LINENUMBER, symbol_Name(Symbol), symbol_Arity(Symbol));
    misc_FinishUserErrorReport();
  }
}


static void dfg_SymCleanUp(void)
/**************************************************************
  INPUT:   None.
  RETURNS: Nothing.
  EFFECT:  This function corrects all symbols whose arity wasn't
           specified in the symbol declaration section but seem
	   to occur with always the same arity.
	   The memory for the symbol list is freed.
***************************************************************/
{
  while (!list_Empty(dfg_SYMBOLLIST)) {
    DFG_SYM actEntry  = (DFG_SYM) list_Car(dfg_SYMBOLLIST);
    SYMBOL  actSymbol = actEntry->symbol;

    if (actEntry->arity != symbol_Arity(actSymbol))
      symbol_SetArity(actSymbol, actEntry->arity);

    dfg_SymFree(actEntry);
    dfg_SYMBOLLIST = list_Pop(dfg_SYMBOLLIST);
  }
}


/**************************************************************/
/* Functions for the Variable Table                           */
/**************************************************************/
  
typedef struct {
  char*  name;
  SYMBOL symbol;
} DFG_VARENTRY, *DFG_VAR;

static __inline__ char* dfg_VarName(DFG_VAR Entry)
{
  return Entry->name;
}

static __inline__ SYMBOL dfg_VarSymbol(DFG_VAR Entry)
{
  return Entry->symbol;
}

static __inline__ DFG_VAR dfg_VarCreate(void)
{
  return (DFG_VAR) memory_Malloc(sizeof(DFG_VARENTRY));
}

static void dfg_VarFree(DFG_VAR Entry)
{
  string_StringFree(Entry->name);
  memory_Free(Entry, sizeof(DFG_VARENTRY));
}

static void dfg_VarStart(void)
{
  dfg_VARLIST = list_Push(list_Nil(), dfg_VARLIST);
  dfg_VARDECL = TRUE;
}

static void dfg_VarStop(void)
{
  dfg_VARDECL = FALSE;
}

static void dfg_VarBacktrack(void)
{
  list_DeleteWithElement(list_Top(dfg_VARLIST), (void (*)(POINTER)) dfg_VarFree);
  dfg_VARLIST = list_Pop(dfg_VARLIST);
}

static void dfg_VarCheck(void)
/* Should be called after a complete clause or formula was parsed */
{
  if (!list_Empty(dfg_VARLIST)) {
    misc_StartErrorReport();
    misc_ErrorReport("\n In dfg_VarCheck: List of variables should be empty!\n");
    misc_FinishErrorReport();
  }
  symbol_ResetStandardVarCounter();
}

static SYMBOL dfg_VarLookup(char* Name)
/**************************************************************
  INPUT:   A variable name.
  RETURNS: The corresponding variable symbol.
  EFFECT:  If the variable name was quantified before, the
           corresponding symbol is returned and the <Name> is freed.
	   If the variable name was not quantified, and <dfg_VARDECL>
	   is TRUE, a new variable is created, else an error
	   message is printed and the program exits.
***************************************************************/
{
  LIST   scan, scan2;
  SYMBOL symbol = symbol_Null();

  scan  = dfg_VARLIST;
  scan2 = list_Nil();
  while (!list_Empty(scan) && list_Empty(scan2)) {
    scan2 = list_Car(scan);
    while (!list_Empty(scan2) &&
	   (!string_Equal(dfg_VarName(list_Car(scan2)), Name)))
      scan2 = list_Cdr(scan2);
    scan = list_Cdr(scan);
  }

  if (!list_Empty(scan2)) {
    /* Found variable */
    string_StringFree(Name);
    symbol = dfg_VarSymbol(list_Car(scan2));
  } else {
    /* Variable not found */
    if (dfg_VARDECL) {
      DFG_VAR newEntry = dfg_VarCreate();
      newEntry->name   = Name;
      newEntry->symbol = symbol_CreateStandardVariable();
      /* Add <newentry> to the first list in dfg_VARLIST */
      list_Rplaca(dfg_VARLIST, list_Cons(newEntry,list_Car(dfg_VARLIST)));
      symbol = dfg_VarSymbol(newEntry);
    } else {
      misc_StartUserErrorReport();
      misc_UserErrorReport("\n Line %u: Free Variable %s.\n", dfg_LINENUMBER, Name);
      misc_FinishUserErrorReport();
    }
  }
  return symbol;
}

/**************************************************************/
/* Functions for the plain clauses                                           */
/**************************************************************/
static DFG_PLAINCLAUSE dfg_PlainClauseCreate(void)
{
  return (DFG_PLAINCLAUSE) memory_Malloc(sizeof(DFG_PLAINCLAUSEHELP));
}

static void dfg_PlainClauseFree(DFG_PLAINCLAUSE Clause)
{
  list_Delete(Clause->constraint);
  list_Delete(Clause->antecedent);
  list_Delete(Clause->succedent);
  memory_Free(Clause, sizeof(DFG_PLAINCLAUSEHELP));
}

