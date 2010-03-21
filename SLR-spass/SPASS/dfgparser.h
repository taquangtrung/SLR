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
/* Line 1285 of yacc.c.  */
#line 218 "dfgparser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE dfg_lval;



