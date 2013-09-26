/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */

/* Line 293 of lalr1.cc  */
#line 14 "yare.y"

	#include "astnode.h"
	#include <cstdarg>
	#include <cstring>
	#include "Variables.h"
	#include "Pila.hh"
	#include "procs.h"
	#include "mymath.h"
	#include "Pila.hh"
	#include <cmath>
	#include <sstream>
	#include <cstdio>
	#include <fstream>
	#include <cstdlib>
	#include "MathFunctions.h"
	#include "NanOrInfinity.h"

	// The symbol table:
	long double sym[26];
	Variables *vars = NULL;
	Pila *pila = NULL;
	struct proc *procs = NULL;
	Arrays *arrays = NULL;
	char opVar[4];


/* Line 293 of lalr1.cc  */
#line 66 "yare.tab.c"


#include "yare.tab.h"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 75 "yare.tab.c"
/* Unqualified %code blocks.  */

/* Line 300 of lalr1.cc  */
#line 46 "yare.y"

	using std::endl;
	using std::cout;
	using std::cerr;
	using std::cin;

	static int yylex(YL::YareParser::semantic_type * yylval, YL::FlexScanner &scanner);
	unsigned short int getAscii(long long);
	
	// Node Constants:
	nodeTypeTag *con(long double);
	
	// Node Strings ... 
	nodeType *conStr(char [], short);
	
	// Node Operators:
	nodeType *opr(int oper, unsigned short nops, ...);
	
	// Node Virtual Vars
	nodeType *id(char i);

	// Node User defined variables:	
	nodeType *idS(char *s);

	// Node User defined arrays:
	nodeType *idA(char *arrayStr);

	// Node User defined arrays with Index:
	nodeType *idA_Index(char *arrayStr, nodeTypeTag *node);

	void freeNode(nodeType *);
	long double run(nodeType *);
	void  freeResources(void);

	long double validateInput(char *, bool &);

	unsigned short int getAscii(long long);
	int i_pila = 0;
	void ver_pila(short);
	short __i__stack__;
	long double _temp_swap;
	double recibido;
	double _temp_swap_id_var_;
	double _temp_swap_var_id_;
	double _temp_concatenate_digits;
	char str_concatena_[100];
	long _exit_return_;

	// La variable índice que controla la pila 
	short spLoop = -1;
	
	// FIXME Ver si es conveniente una pila de 100 elementos o más
	short pilaLoop[100] = {0};
	// Para el rango inferior y mayor. expr ...? expr
	long double inferior;
	long double superior;
	long double _dec_inc_return;

	long double check(char *s, char **end) {
	    long double temp = strtold(s, end);
	    return temp;
	}
	



/* Line 300 of lalr1.cc  */
#line 147 "yare.tab.c"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                               \
 do                                                                    \
   if (N)                                                              \
     {                                                                 \
       (Current).begin = YYRHSLOC (Rhs, 1).begin;                      \
       (Current).end   = YYRHSLOC (Rhs, N).end;                        \
     }                                                                 \
   else                                                                \
     {                                                                 \
       (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;        \
     }                                                                 \
 while (false)
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 382 of lalr1.cc  */
#line 9 "yare.y"
namespace YL {

/* Line 382 of lalr1.cc  */
#line 235 "yare.tab.c"

  /// Build a parser object.
  YareParser::YareParser (YL::FlexScanner &scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg)
  {
  }

  YareParser::~YareParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  YareParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  YareParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  YareParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  YareParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  YareParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  YareParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  YareParser::debug_level_type
  YareParser::debug_level () const
  {
    return yydebug_;
  }

  void
  YareParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  YareParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  YareParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  YareParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, scanner);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yy_table_value_is_error_ (yyn))
	  goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 690 of lalr1.cc  */
#line 299 "yare.y"
    {
	exit(EXIT_SUCCESS);
}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 305 "yare.y"
    {
		push_l_proc(&procs, (yysemantic_stack_[(6) - (3)].nameFunction), (yysemantic_stack_[(6) - (5)].nPtr));
	}
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 308 "yare.y"
    {;}
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 312 "yare.y"
    { 
		run((yysemantic_stack_[(2) - (2)].nPtr));		
		freeNode((yysemantic_stack_[(2) - (2)].nPtr));

	}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 317 "yare.y"
    {;}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 321 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, NULL, NULL); 
	}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 324 "yare.y"
    { 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 327 "yare.y"
    {		// x to 1 + 2; 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 330 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (4)].sIndex)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 333 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (4)].identificador)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 336 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 339 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 342 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 345 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 348 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 351 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 354 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 357 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 360 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 363 "yare.y"
    { 	// :x: to 1 + 2;
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 366 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 369 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 372 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, id((yysemantic_stack_[(4) - (1)].sIndex)));
	}
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 375 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, idS((yysemantic_stack_[(4) - (1)].identificador)));
	}
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 378 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 381 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 384 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 387 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 390 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(2) - (1)].nPtr); 
	}
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 393 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 394 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 395 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 396 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 397 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 398 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 399 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINTN, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 402 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRASCII, 1, (yysemantic_stack_[(5) - (3)].nPtr));
	}
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 405 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINT, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 408 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 411 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 414 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 417 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 420 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTSN, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 423 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTSN, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 426 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 429 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(3) - (2)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 432 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DO_WHILE, 2, (yysemantic_stack_[(7) - (2)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 435 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FOREACH, 4, (yysemantic_stack_[(9) - (3)].nPtr), (yysemantic_stack_[(9) - (5)].nPtr), id((yysemantic_stack_[(9) - (7)].sIndex)), (yysemantic_stack_[(9) - (9)].nPtr));
	}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 438 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::BREAK, 0);
	}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 441 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SYSTEM, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));	
	}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 444 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXIT, 1, (yysemantic_stack_[(5) - (3)].nPtr));		
	}
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 447 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr));
	}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 450 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 3, (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr), (yysemantic_stack_[(7) - (7)].nPtr)); 
	}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 453 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 456 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 459 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 462 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 465 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 468 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 471 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 474 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 477 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 480 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 483 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 486 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 489 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 492 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 495 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 498 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 501 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 504 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 507 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 510 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 513 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 516 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 519 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 522 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 525 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUSH, 1, (yysemantic_stack_[(2) - (2)].nPtr));	
	}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 528 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_ASSIGN, 3, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (6)].nPtr));
	}
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 531 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_C, 1, idA((yysemantic_stack_[(5) - (3)].identificador)));
	}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 534 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_PUT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 537 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_PUTFRONT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 540 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SORT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 543 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_DEL, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 546 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_FILL, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 549 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_CLEAR, 1, idA((yysemantic_stack_[(6) - (1)].identificador)));
	}
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 552 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_REVERSE, 1, idA((yysemantic_stack_[(6) - (1)].identificador)));
	}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 555 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_ADD, 0); 
	}
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 558 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_SUB, 0); 
	}
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 561 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_MUL, 0); 
	}
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 564 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_DIV, 0); 
	}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 567 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_POW, 0); 
	}
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 570 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CLEARVARS, 0);
	}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 573 "yare.y"
    {;}
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 577 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(1) - (1)].nPtr); 
	}
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 580 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, (yysemantic_stack_[(2) - (1)].nPtr), (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 586 "yare.y"
    {
		(yyval.nPtr) = con((yysemantic_stack_[(1) - (1)].valnum));
	}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 589 "yare.y"
    { 
		if(vars == NULL) {
			cout << "La variable '" << (yysemantic_stack_[(1) - (1)].identificador) << "' no ha sido declarada";
			exit(EXIT_FAILURE);
		} else {
			(yyval.nPtr) = idS((yysemantic_stack_[(1) - (1)].identificador));	
		}
	}
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 597 "yare.y"
    {
		(yyval.nPtr) = conStr((yysemantic_stack_[(1) - (1)].cadena), typeCadena);
	}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 600 "yare.y"
    { 
		(yyval.nPtr) = id((yysemantic_stack_[(1) - (1)].sIndex)); 
	}
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 603 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SHIT, 2, idA((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 606 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 609 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA((yysemantic_stack_[(3) - (1)].identificador)));
	}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 612 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_MIN, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 615 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_MAX, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 618 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_TAIL, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 621 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_HEAD, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 624 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_AVERAGE, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 627 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::UMINUS, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 630 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 633 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 636 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 639 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 642 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 645 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 648 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 651 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 654 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 657 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 660 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 663 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 666 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 669 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 672 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 675 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 678 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 681 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 684 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 687 "yare.y"
    { 
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 690 "yare.y"
    {
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 693 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 696 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 699 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 702 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 705 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 708 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 711 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 714 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::AND, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 717 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OR, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 720 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ANDBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 723 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ORBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 726 "yare.y"
    {
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr);
	}
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 729 "yare.y"
    { 
		// Comparaciones de operadores
			if(strcmp(opVar, "+") == 0) {
				(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
			} else if(strcmp(opVar, "-") == 0) {
				(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
			} else if(strcmp(opVar, "*") == 0) {
				(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
			} else if(strcmp(opVar, "/") == 0) {
				(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
			} else if(strcmp(opVar, "^") == 0) {
				(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
			} 
	}
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 743 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TERNARY, 3, (yysemantic_stack_[(5) - (1)].nPtr), (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr));
	}
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 746 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READ, 0);
	}
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 749 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READP, 1, conStr((yysemantic_stack_[(4) - (3)].cadena), typeCadena));
	}
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 752 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RAND, 0);
	}
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 755 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::POP, 0);
	}
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 758 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::STACK_SIZE, 0);
	}
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 761 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ABS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 764 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SQRT, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 767 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ACOS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 770 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ASIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 773 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 777 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 780 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CEIL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 783 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 786 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COSH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 789 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXP, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 792 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FLOOR, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 795 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::LN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 798 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 801 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SINH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 804 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 807 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 810 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SUMATORIA, 2, (yysemantic_stack_[(6) - (3)].nPtr), (yysemantic_stack_[(6) - (5)].nPtr));	
	}
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 813 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FACTORIAL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 816 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 819 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 822 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 825 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 828 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::XOROP, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 831 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RANGE_RANDOM, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 834 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 837 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 840 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CALL, 1, idS((yysemantic_stack_[(2) - (2)].nameFunction)));
	}
    break;



/* Line 690 of lalr1.cc  */
#line 2082 "yare.tab.c"
	default:
          break;
      }
    /* User semantic actions sometimes alter yychar, and that requires
       that yytoken be updated with the new translation.  We take the
       approach of translating immediately before every use of yytoken.
       One alternative is translating here after every semantic action,
       but that translation would be missed if the semantic action
       invokes YYABORT, YYACCEPT, or YYERROR immediately after altering
       yychar.  In the case of YYABORT or YYACCEPT, an incorrect
       destructor might then be invoked immediately.  In the case of
       YYERROR, subsequent parser actions might lead to an incorrect
       destructor call or verbose syntax error message before the
       lookahead is translated.  */
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* Make sure we have latest lookahead translation.  See comments at
       user semantic actions for why this is necessary.  */
    yytoken = yytranslate_ (yychar);

    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	if (yychar == yyempty_)
	  yytoken = yyempty_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[1] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[1] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (!yy_pact_value_is_default_ (yyn))
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[1] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[2] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      {
        /* Make sure we have latest lookahead translation.  See comments
           at user semantic actions for why this is necessary.  */
        yytoken = yytranslate_ (yychar);
        yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval,
                     &yylloc);
      }

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  YareParser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const short int YareParser::yypact_ninf_ = -141;
  const short int
  YareParser::yypact_[] =
  {
      -141,    10,   -68,  -141,   -55,   774,  -127,  -141,   -56,  -141,
     -39,  -140,  -121,  -118,  1306,  -108,  1621,   -92,   -85,   -64,
    1306,   -58,   -51,   -48,   -47,   -45,   -42,   -40,     3,     4,
     -37,  1692,   -36,   -34,    27,    25,  1692,    42,    46,    58,
      59,   -33,   -32,   -28,   -27,   -26,   -25,   -12,   -11,   -10,
       6,     7,    11,    12,    13,    15,    17,    22,    30,  1692,
    -141,  -141,  1692,  -141,  1306,  -141,  1692,  1692,  1692,  -141,
    1760,  1306,    77,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1377,    47,  -128,    78,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1461,
      60,    57,  1692,    51,    37,  -141,   907,   187,    55,  -141,
    -139,  1692,   484,  1692,   191,  1692,   183,  -141,  1692,    66,
     214,  1692,  1692,  1692,    74,   216,   104,   251,   105,   265,
      88,    91,  -141,   -87,   -86,  1800,   110,   111,   112,   113,
     114,   115,   116,   117,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  6313,   265,  1040,  1917,   265,   265,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  1692,  1692,  -141,  1692,  1692,  1692,
    1692,  1692,  1173,   120,   121,  6313,  6313,  6313,  1957,  6313,
    6313,  6313,  6313,  6313,  2074,  6313,   122,   123,   125,   126,
    2114,  1692,  -141,  -141,   127,   128,  6313,  6313,  6313,  2231,
    6313,  6313,  6313,  6313,  6313,  2271,  6313,   130,   131,   132,
     133,  2388,  1692,   129,   134,   135,   136,   137,   139,   140,
     141,   142,   143,   155,   159,   161,  2428,   138,   167,   169,
     170,   171,  -141,  -141,  -141,   166,    35,  1692,  2545,  1537,
    1692,  -141,  2585,   168,  2702,   174,  2742,  -141,   175,  2859,
    2899,  3016,  -141,   176,  -141,   179,  -141,   182,   185,   186,
     188,  1692,  1692,  1692,  1692,    92,  1692,  1692,  1692,  1692,
    1692,  1692,  1692,  1692,  3056,  3173,  3213,  3330,  3370,  3487,
    3527,  3644,  3684,  3801,  3841,  3958,  3998,  4115,  4155,  4272,
    4312,  4429,  -141,  -141,  6313,   302,   271,  6565,  6565,  6565,
    6565,   271,   302,  6565,    21,  6565,  6565,  6313,  6313,  6353,
    6506,  6565,  6565,  6565,  6565,   271,   271,   302,   302,    21,
      34,   265,  6313,   246,  6313,  6313,  6313,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  6470,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  6470,  1692,  1692,
     189,  1692,  1692,  1692,   190,   192,   197,   206,   207,   208,
     209,   172,  -141,  -141,  -141,  -141,  -141,   218,  4469,   641,
    4586,  1692,   219,   220,  1692,  1306,  -141,   225,   226,   227,
     228,   229,  -141,  -141,  -141,  -141,  4626,  4743,  4783,  4900,
    -141,  -141,  4940,  5057,  5097,  5214,  5254,  5371,  5411,  5528,
    -141,  -141,  1692,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  1692,  5568,
    5685,  -141,  5725,  5842,  5882,   241,  -141,  -141,  -141,  -141,
    -141,   242,  1692,  -141,  -141,  -141,  5999,  -141,  -141,  6039,
     160,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  6156,  6313,
     243,   244,   245,   247,   252,  -141,  -141,  6196,   278,   253,
    1306,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   210,  -141,
    -141,  1306,  -141
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  YareParser::yydefact_[] =
  {
         4,     0,     6,     1,     0,     0,     0,    98,   101,   100,
      99,     0,     0,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,   150,     0,     2,    95,     7,     0,     0,     0,     5,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,     0,     0,   101,    99,
       0,     0,    95,     0,     0,     0,     0,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,   110,     0,     0,   111,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    71,    65,     0,    63,
      67,    73,    75,    77,     0,    16,     0,     0,     0,     0,
       0,     0,   176,   175,     0,     0,    70,    72,    66,     0,
      64,    68,    74,    76,    78,     0,    17,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    41,    97,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,   146,     0,     0,
       0,     0,    43,     0,    45,     0,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,   143,   144,   121,   117,   126,   133,   123,
     135,   116,   119,   138,   131,   127,   124,   174,   173,   140,
     139,   136,   137,   134,   132,   114,   115,   118,   120,   130,
     128,   129,   122,     0,   125,   141,   142,     3,    26,    28,
      55,     9,    31,    32,    33,    24,     8,    14,    27,    29,
      56,    21,    34,    35,    36,    25,    20,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   102,    89,    90,    91,    92,    93,     0,     0,   143,
     115,     0,     0,     0,     0,    95,   147,     0,     0,     0,
       0,     0,   170,   169,   172,   171,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   168,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     0,     0,
       0,   103,     0,     0,     0,     0,   105,   106,   108,   107,
     109,     0,     0,    81,   102,    46,     0,    51,    52,     0,
      53,    38,    37,    39,    42,    44,    19,    18,    23,    22,
      12,    13,    59,    60,    57,    58,    61,    62,     0,   145,
       0,     0,     0,     0,     0,    87,    88,     0,     0,     0,
      95,   167,    82,    83,    84,    85,    86,    80,     0,    48,
      54,    95,    49
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  YareParser::yypgoto_[] =
  {
      -141,  -141,  -141,  -141,    -5,   -59,    54
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  YareParser::yydefgoto_[] =
  {
        -1,     1,     2,     5,   105,   106,    70
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char YareParser::yytable_ninf_ = -111;
  const short int
  YareParser::yytable_[] =
  {
        69,   291,   293,   101,   266,   164,   222,   223,   124,   126,
       3,    72,   202,   102,   267,   116,     4,    71,    73,    74,
      75,    76,    77,    78,    79,    80,   103,    81,    87,   133,
       6,   134,    82,   104,    83,    88,    89,    90,    91,    92,
      93,    94,    95,   107,    96,   168,   136,   245,   137,    97,
     138,    98,   139,   250,   251,   252,   253,   254,   168,   113,
     292,   294,   140,   142,   141,   143,   114,   243,   244,   245,
     112,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   203,   224,   204,   225,   129,   181,   115,   117,   182,
     135,    84,   287,    85,   288,   289,   420,   290,   421,   181,
     118,   264,   182,   119,   120,    86,   121,   271,    99,   122,
     100,   123,   132,   162,   128,   130,   163,   131,   144,   145,
     165,   166,   167,   146,   147,   148,   149,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   220,   150,
     151,   152,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   241,   125,   127,   256,   153,   154,   264,
     194,   195,   155,   156,   157,   268,   158,   272,   159,   274,
     197,   198,   276,   160,   195,   279,   280,   281,   199,   200,
     201,   161,   221,   197,   198,   257,   258,   259,   260,   262,
     261,   199,   200,   201,   265,   242,   273,   264,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,    86,   275,   277,   278,
     282,   283,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     284,   352,   353,   354,   355,   356,   285,   286,   296,   297,
     298,   299,   300,   301,   302,   303,   358,   359,   362,   363,
     168,   364,   365,   368,   369,   367,   372,   373,   374,   375,
     378,   500,   508,     0,   392,   379,   380,   381,   382,   168,
     383,   384,   385,   386,   387,   168,   377,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   388,   178,   179,   180,
     389,   181,   390,   393,   182,   394,   395,   396,   397,   462,
     402,   398,   169,   324,   400,   404,   168,   406,   410,   176,
     181,   411,   178,   182,   412,     0,   181,   413,   414,   182,
     415,   451,   455,     0,   456,   416,   417,   418,   419,   457,
     422,   423,   424,   425,   426,   427,   428,   429,   458,   459,
     460,   461,   511,   178,   463,   467,   468,   181,   183,   184,
     182,   471,   472,   473,   474,   475,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   495,   496,   502,
     503,   504,     0,   505,   465,   197,   198,     0,   506,   509,
     470,     0,     0,   199,   200,   201,   448,   191,   192,   193,
     194,   195,     0,     0,   197,   198,     0,     0,     0,     0,
     197,   198,   199,   200,   201,     0,     0,     0,   199,   200,
     201,     0,   449,   450,     0,   452,   453,   454,     0,     0,
     193,   194,   195,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   198,     0,     0,   466,     0,     0,   469,   199,
     200,   201,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   488,     7,     8,     9,
      10,    11,     0,     0,     0,   510,     0,     0,     0,     0,
       0,     0,   489,     0,     0,     0,   512,     0,   269,     0,
       0,     0,     0,     0,    13,    14,   497,    15,    16,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   169,   170,   171,   172,   173,
     174,   175,   176,   177,    31,   178,   179,   180,     0,   181,
       0,     0,   182,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,    36,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
      59,    60,    61,     0,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   270,
     191,   192,   193,   194,   195,     0,     0,     0,    64,     0,
      65,     0,     0,   197,   198,    66,     0,     0,     0,    67,
      68,   199,   200,   201,     7,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
       0,    13,    14,   -95,    15,    16,     0,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,     0,
      36,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,     0,     0,    59,    60,    61,
       0,     0,   -95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     7,     8,     9,
      10,    11,     0,     0,   -95,    64,   -95,    65,     0,     0,
       0,     0,    66,     0,     0,     0,    67,    68,    12,     0,
       0,     0,     0,     0,    13,    14,     0,    15,    16,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,    36,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       7,     8,     9,    10,    11,     0,     0,    63,    64,     0,
      65,     0,     0,     0,     0,    66,     0,     0,     0,    67,
      68,    12,     0,     0,     0,     0,     0,    13,    14,   263,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,    36,     0,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     0,     0,    59,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     7,     8,     9,    10,    11,     0,     0,
       0,    64,     0,    65,     0,     0,     0,     0,    66,     0,
       0,     0,    67,    68,    12,     0,     0,     0,     0,     0,
      13,    14,     0,    15,    16,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,    36,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,    59,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     7,     8,     9,    10,
      11,     0,     0,     0,    64,   322,    65,     0,     0,     0,
       0,    66,     0,     0,     0,    67,    68,    12,     0,     0,
       0,     0,     0,    13,    14,     0,    15,    16,     0,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,    36,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,     0,     0,    59,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     7,
       8,     9,    10,    11,     0,     0,     0,    64,   357,    65,
       0,     0,     0,     0,    66,     0,     0,     0,    67,    68,
      12,     0,     0,     0,     0,     0,    13,    14,     0,    15,
      16,     0,    17,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,     0,
       7,   108,     9,   109,   110,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,    36,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
      23,    24,    59,    60,    61,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,    62,     0,     0,     0,     0,    32,    33,     0,     0,
      64,     0,    65,     0,     0,     0,     0,    66,     0,     0,
       0,    67,    68,    34,     7,   108,     9,   109,   110,     0,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
     216,   217,   218,     0,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,     0,     0,     0,     0,
       0,    30,    62,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,   219,    66,     0,
      32,    33,    67,    68,     0,     0,     0,     0,     0,     0,
       7,   108,     9,   109,   110,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   237,   238,   239,     0,    60,    61,
      23,    24,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
       0,   240,    66,     0,     0,     0,    67,    68,     0,     0,
       0,     0,     0,    34,     7,   108,     9,   109,   110,     0,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     0,     0,     0,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,     0,     0,     0,     0,
       0,    30,    62,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,   103,     0,     0,     0,    66,     0,
      32,    33,    67,    68,     0,     7,   108,     9,   109,   110,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,    23,    24,     0,    60,    61,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,    62,     0,     0,     0,
       0,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,     0,     0,     0,    67,    68,    34,     0,
       0,     0,     0,     0,   168,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,    60,
      61,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,   180,   168,   181,     0,    62,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,     0,    67,    68,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,   180,     0,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,     0,     0,     0,     0,   295,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     0,     0,     0,     0,     0,   196,     0,     0,   197,
     198,     0,     0,     0,     0,     0,     0,   199,   200,   201,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   168,     0,     0,     0,     0,     0,     0,     0,   197,
     198,     0,     0,     0,     0,     0,     0,   199,   200,   201,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,   168,   181,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,     0,   181,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,     0,     0,     0,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   198,     0,   323,
       0,     0,     0,     0,   199,   200,   201,     0,     0,   183,
     184,     0,     0,     0,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   168,     0,
       0,     0,     0,   360,     0,     0,   197,   198,     0,     0,
       0,     0,     0,     0,   199,   200,   201,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,   168,   181,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,     0,   181,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,     0,     0,     0,     0,
     361,     0,     0,   197,   198,     0,     0,     0,     0,     0,
       0,   199,   200,   201,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   168,     0,     0,     0,     0,
     366,     0,     0,   197,   198,     0,     0,     0,     0,     0,
       0,   199,   200,   201,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   168,   181,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,     0,   181,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,     0,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,     0,     0,     0,     0,   370,     0,     0,
     197,   198,     0,     0,     0,     0,     0,     0,   199,   200,
     201,     0,     0,   183,   184,     0,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   168,     0,     0,     0,     0,   371,     0,     0,
     197,   198,     0,     0,     0,     0,     0,     0,   199,   200,
     201,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,   180,   168,   181,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,   180,     0,   181,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
       0,     0,     0,     0,   376,     0,     0,   197,   198,     0,
       0,     0,     0,     0,     0,   199,   200,   201,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   168,
       0,     0,     0,     0,     0,     0,     0,   197,   198,     0,
       0,     0,   391,     0,     0,   199,   200,   201,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,   180,   168,
     181,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,   180,     0,
     181,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   198,     0,   399,     0,     0,
       0,     0,   199,   200,   201,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   168,     0,     0,     0,
       0,     0,     0,     0,   197,   198,     0,     0,     0,     0,
       0,     0,   199,   200,   201,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   168,   181,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,   180,     0,   181,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   198,     0,   403,     0,     0,     0,     0,   199,
     200,   201,     0,     0,   183,   184,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   168,     0,     0,     0,     0,     0,     0,
       0,   197,   198,     0,   405,     0,     0,     0,     0,   199,
     200,   201,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,   180,   168,   181,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,   180,     0,   181,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   198,
       0,   407,     0,     0,     0,     0,   199,   200,   201,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     168,     0,     0,     0,     0,     0,     0,     0,   197,   198,
       0,   408,     0,     0,     0,     0,   199,   200,   201,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,   180,
     168,   181,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,   180,
       0,   181,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
       0,     0,     0,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   198,     0,   409,     0,
       0,     0,     0,   199,   200,   201,     0,     0,   183,   184,
       0,     0,     0,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   168,     0,     0,
       0,     0,     0,     0,     0,   197,   198,     0,   430,     0,
       0,     0,     0,   199,   200,   201,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,   180,   168,   181,     0,
       0,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,   180,     0,   181,     0,
       0,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,     0,   431,     0,     0,     0,     0,
     199,   200,   201,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   168,     0,     0,     0,     0,     0,
       0,   432,   197,   198,     0,     0,     0,     0,     0,     0,
     199,   200,   201,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,   180,   168,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,   180,     0,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     0,     0,     0,     0,     0,     0,     0,     0,   197,
     198,     0,   433,     0,     0,     0,     0,   199,   200,   201,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   168,     0,     0,     0,     0,     0,     0,     0,   197,
     198,     0,   434,     0,     0,     0,     0,   199,   200,   201,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,   168,   181,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,     0,   181,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,     0,     0,     0,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   198,     0,   435,
       0,     0,     0,     0,   199,   200,   201,     0,     0,   183,
     184,     0,     0,     0,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   168,     0,
       0,     0,     0,     0,     0,     0,   197,   198,     0,   436,
       0,     0,     0,     0,   199,   200,   201,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,   168,   181,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,     0,   181,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,     0,     0,     0,     0,
       0,     0,     0,   197,   198,     0,   437,     0,     0,     0,
       0,   199,   200,   201,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   168,     0,     0,     0,     0,
       0,     0,     0,   197,   198,     0,   438,     0,     0,     0,
       0,   199,   200,   201,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   168,   181,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,     0,   181,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,     0,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   198,     0,   439,     0,     0,     0,     0,   199,   200,
     201,     0,     0,   183,   184,     0,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   168,     0,     0,     0,     0,     0,     0,     0,
     197,   198,     0,   440,     0,     0,     0,     0,   199,   200,
     201,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,   180,   168,   181,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,   180,     0,   181,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
       0,     0,     0,     0,     0,     0,     0,   197,   198,     0,
     441,     0,     0,     0,     0,   199,   200,   201,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   168,
       0,     0,     0,     0,     0,     0,     0,   197,   198,     0,
     442,     0,     0,     0,     0,   199,   200,   201,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,   180,   168,
     181,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,   180,     0,
     181,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   198,     0,   443,     0,     0,
       0,     0,   199,   200,   201,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   168,     0,     0,     0,
       0,     0,     0,     0,   197,   198,     0,   444,     0,     0,
       0,     0,   199,   200,   201,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   168,   181,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,   180,     0,   181,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   198,     0,   445,     0,     0,     0,     0,   199,
     200,   201,     0,     0,   183,   184,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   168,     0,     0,     0,     0,     0,     0,
       0,   197,   198,     0,   446,     0,     0,     0,     0,   199,
     200,   201,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,   180,   168,   181,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,   180,     0,   181,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   198,
       0,   447,     0,     0,     0,     0,   199,   200,   201,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     168,     0,     0,     0,     0,     0,     0,     0,   197,   198,
       0,     0,     0,   464,     0,     0,   199,   200,   201,     0,
       0,     0,     0,     0,     0,     0,     0,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     0,  -110,  -110,  -110,
     168,   181,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,   180,
       0,   181,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -110,  -110,
       0,     0,     0,     0,     0,     0,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,     0,     0,     0,
       0,     0,  -110,     0,     0,   197,   198,     0,     0,     0,
       0,     0,     0,   199,   200,   201,     0,     0,   183,   184,
       0,     0,     0,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   168,     0,     0,
       0,     0,   476,     0,     0,   197,   198,     0,     0,     0,
       0,     0,     0,   199,   200,   201,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,   180,   168,   181,     0,
       0,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,   180,     0,   181,     0,
       0,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,     0,     0,     0,     0,   477,
       0,     0,   197,   198,     0,     0,     0,     0,     0,     0,
     199,   200,   201,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   168,     0,     0,     0,     0,   478,
       0,     0,   197,   198,     0,     0,     0,     0,     0,     0,
     199,   200,   201,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,   180,   168,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   178,   179,   180,     0,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,     0,     0,     0,     0,     0,   479,     0,     0,   197,
     198,     0,     0,     0,     0,     0,     0,   199,   200,   201,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   168,     0,     0,     0,     0,   480,     0,     0,   197,
     198,     0,     0,     0,     0,     0,     0,   199,   200,   201,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,   168,   181,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,   172,   173,   174,   175,   176,   177,     0,   178,   179,
     180,     0,   181,     0,     0,   182,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     184,     0,     0,     0,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     0,     0,
       0,     0,     0,   481,     0,     0,   197,   198,     0,     0,
       0,     0,     0,     0,   199,   200,   201,     0,     0,   183,
     184,     0,     0,     0,     0,     0,     0,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   168,     0,
       0,     0,     0,   482,     0,     0,   197,   198,     0,     0,
       0,     0,     0,     0,   199,   200,   201,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,   168,   181,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   178,   179,   180,     0,   181,
       0,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,     0,     0,     0,     0,     0,
     483,     0,     0,   197,   198,     0,     0,     0,     0,     0,
       0,   199,   200,   201,     0,     0,   183,   184,     0,     0,
       0,     0,     0,     0,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   168,     0,     0,     0,     0,
     484,     0,     0,   197,   198,     0,     0,     0,     0,     0,
       0,   199,   200,   201,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,   168,   181,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,   170,   171,   172,   173,   174,   175,   176,
     177,     0,   178,   179,   180,     0,   181,     0,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,     0,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,     0,     0,     0,     0,     0,   485,     0,     0,
     197,   198,     0,     0,     0,     0,     0,     0,   199,   200,
     201,     0,     0,   183,   184,     0,     0,     0,     0,     0,
       0,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   168,     0,     0,     0,     0,   486,     0,     0,
     197,   198,     0,     0,     0,     0,     0,     0,   199,   200,
     201,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,   180,   168,   181,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,   172,   173,   174,   175,   176,   177,     0,   178,
     179,   180,     0,   181,     0,     0,   182,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,     0,
       0,     0,     0,     0,   487,     0,     0,   197,   198,     0,
       0,     0,     0,     0,     0,   199,   200,   201,     0,     0,
     183,   184,     0,     0,     0,     0,     0,     0,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   168,
       0,     0,     0,     0,     0,     0,     0,   197,   198,     0,
     490,     0,     0,     0,     0,   199,   200,   201,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,   180,   168,
     181,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,   171,   172,
     173,   174,   175,   176,   177,     0,   178,   179,   180,     0,
     181,     0,     0,   182,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   198,     0,   491,     0,     0,
       0,     0,   199,   200,   201,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   168,     0,     0,     0,
       0,     0,     0,     0,   197,   198,     0,   492,     0,     0,
       0,     0,   199,   200,   201,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,   180,   168,   181,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,     0,   178,   179,   180,     0,   181,     0,     0,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   183,   184,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   198,     0,   493,     0,     0,     0,     0,   199,
     200,   201,     0,     0,   183,   184,     0,     0,     0,     0,
       0,     0,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   168,     0,     0,     0,     0,     0,     0,
       0,   197,   198,     0,   494,     0,     0,     0,     0,   199,
     200,   201,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,   180,   168,   181,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,   180,     0,   181,     0,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
       0,     0,     0,     0,     0,     0,     0,   498,   197,   198,
       0,     0,     0,     0,     0,     0,   199,   200,   201,     0,
       0,   183,   184,     0,     0,     0,     0,     0,     0,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     168,     0,     0,     0,     0,     0,     0,     0,   197,   198,
       0,   499,     0,     0,     0,     0,   199,   200,   201,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,   180,
     168,   181,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,   180,
       0,   181,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,   184,
       0,     0,     0,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   198,     0,   501,     0,
       0,     0,     0,   199,   200,   201,     0,     0,   183,   184,
       0,     0,     0,     0,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   168,     0,     0,
       0,     0,   507,     0,     0,   197,   198,     0,     0,     0,
       0,     0,     0,   199,   200,   201,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,   180,   168,   181,     0,
       0,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,   180,     0,   181,     0,
       0,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,     0,     0,     0,     0,     0,     0,
     199,   200,   201,     0,     0,     0,   184,     0,     0,     0,
       0,     0,     0,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   168,     0,     0,     0,     0,     0,
       0,     0,   197,   198,     0,     0,     0,     0,     0,     0,
     199,   200,   201,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     168,   178,   179,   180,     0,   181,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     172,   173,   174,   175,   176,   177,     0,   178,   179,   180,
       0,   181,     0,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
       0,     0,   183,   184,     0,     0,     0,     0,     0,     0,
     185,   186,   187,   188,   189,     0,   191,   192,   193,   194,
     195,     0,     0,     0,     0,     0,   169,   170,     0,   197,
     198,     0,   175,   176,     0,     0,   178,   199,   200,   201,
     181,     0,     0,   182,     0,     0,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   198,     0,     0,     0,
       0,     0,     0,   199,   200,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     190,   191,   192,   193,   194,   195,     0,     0,     0,     0,
       0,     0,     0,     0,   197,   198,     0,     0,     0,     0,
       0,     0,   199,   200,   201
  };

  /* YYCHECK.  */
  const short int
  YareParser::yycheck_[] =
  {
         5,    88,    88,   143,   143,    64,   134,   135,     5,     5,
       0,    67,    71,   153,   153,    20,    84,   144,    74,    75,
      76,    77,    78,    79,    80,    81,   147,    83,    67,     4,
      85,     6,    88,   151,    90,    74,    75,    76,    77,    78,
      79,    80,    81,   151,    83,    24,     4,    12,     6,    88,
       4,    90,     6,    18,    19,    20,    21,    22,    24,   151,
     147,   147,     4,     4,     6,     6,   151,    10,    11,    12,
      16,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     4,     4,     6,     6,    31,    65,   151,   146,    68,
      36,   147,     4,   149,     6,     4,     4,     6,     6,    65,
     151,   106,    68,   151,   151,   161,   151,   112,   147,   151,
     149,   151,    85,    59,   151,   151,    62,   151,   151,   151,
      66,    67,    68,   151,   151,   151,   151,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   151,
     151,   151,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   151,   151,   102,   151,   151,   164,
     139,   140,   151,   151,   151,   111,   151,   113,   151,   115,
     149,   150,   118,   151,   140,   121,   122,   123,   157,   158,
     159,   151,   135,   149,   150,   134,   135,   136,   137,   152,
     139,   157,   158,   159,     7,   135,     5,   202,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   161,    34,   152,     5,
     146,     5,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     146,   197,   198,   199,   200,   201,     5,   152,   148,   148,
     148,   148,   148,   148,   148,   148,   146,   146,   146,   146,
      24,   146,   146,   146,   146,   221,   146,   146,   146,   146,
     151,   121,     4,    -1,   146,   151,   151,   151,   151,    24,
     151,   151,   151,   151,   151,    24,   242,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   151,    61,    62,    63,
     151,    65,   151,   146,    68,   146,   146,   146,   152,   147,
     152,   267,    51,   269,   270,   151,    24,   152,   152,    58,
      65,   152,    61,    68,   152,    -1,    65,   152,   152,    68,
     152,   152,   152,    -1,   152,   291,   292,   293,   294,   152,
     296,   297,   298,   299,   300,   301,   302,   303,   152,   152,
     152,   152,   152,    61,   146,   146,   146,    65,   122,   123,
      68,   146,   146,   146,   146,   146,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   146,   146,   146,
     146,   146,    -1,   146,   399,   149,   150,    -1,   146,   146,
     405,    -1,    -1,   157,   158,   159,   160,   136,   137,   138,
     139,   140,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,
     149,   150,   157,   158,   159,    -1,    -1,    -1,   157,   158,
     159,    -1,   378,   379,    -1,   381,   382,   383,    -1,    -1,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,    -1,   401,    -1,    -1,   404,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   432,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   500,    -1,    -1,    -1,    -1,
      -1,    -1,   448,    -1,    -1,    -1,   511,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,   462,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,   144,    -1,
     146,    -1,    -1,   149,   150,   151,    -1,    -1,    -1,   155,
     156,   157,   158,   159,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      89,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,    -1,    -1,   116,   117,   118,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,     3,     4,     5,
       6,     7,    -1,    -1,   143,   144,   145,   146,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,   155,   156,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,    -1,    -1,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
       3,     4,     5,     6,     7,    -1,    -1,   143,   144,    -1,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,
     156,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   144,    -1,   146,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,   155,   156,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,    -1,    -1,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   144,   145,   146,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,   155,   156,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   144,   145,   146,
      -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   156,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
      43,    44,   116,   117,   118,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,   135,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
     144,    -1,   146,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,   155,   156,    86,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,    -1,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    50,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,   150,   151,    -1,
      69,    70,   155,   156,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,    -1,   117,   118,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
      -1,   150,   151,    -1,    -1,    -1,   155,   156,    -1,    -1,
      -1,    -1,    -1,    86,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    50,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,   147,    -1,    -1,    -1,   151,    -1,
      69,    70,   155,   156,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,    43,    44,    -1,   117,   118,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,   135,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,   155,   156,    86,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,   117,
     118,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,   135,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,   155,   156,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    88,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    24,    -1,
      -1,    -1,    -1,   146,    -1,    -1,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    24,    -1,    -1,    -1,    -1,
     146,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    24,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    24,    -1,    -1,    -1,    -1,   146,    -1,    -1,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,
      -1,    -1,   154,    -1,    -1,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    24,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    24,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    24,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,   152,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    24,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    24,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
      -1,    -1,    -1,   154,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,   146,    -1,    -1,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    24,    -1,    -1,
      -1,    -1,   146,    -1,    -1,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    24,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    24,    -1,    -1,    -1,    -1,   146,
      -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,    24,    -1,    -1,    -1,    -1,   146,    -1,    -1,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    -1,    -1,
      -1,    -1,    -1,   146,    -1,    -1,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,    24,    -1,
      -1,    -1,    -1,   146,    -1,    -1,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
     146,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    24,    -1,    -1,    -1,    -1,
     146,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    24,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    24,    -1,    -1,    -1,    -1,   146,    -1,    -1,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    -1,
      -1,    -1,    -1,    -1,   146,    -1,    -1,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,    -1,
     152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    24,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,    -1,
      -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,
      -1,    -1,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,    -1,   152,    -1,    -1,    -1,    -1,   157,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
      -1,   152,    -1,    -1,    -1,    -1,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,    -1,   152,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    24,    -1,    -1,
      -1,    -1,   146,    -1,    -1,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    24,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      24,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   133,   134,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,   149,
     150,    -1,    57,    58,    -1,    -1,    61,   157,   158,   159,
      65,    -1,    -1,    68,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,   158,   159
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  YareParser::yystos_[] =
  {
         0,   163,   164,     0,    84,   165,    85,     3,     4,     5,
       6,     7,    24,    30,    31,    33,    34,    36,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    60,    69,    70,    86,    87,    89,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   116,
     117,   118,   135,   143,   144,   146,   151,   155,   156,   166,
     168,   144,    67,    74,    75,    76,    77,    78,    79,    80,
      81,    83,    88,    90,   147,   149,   161,    67,    74,    75,
      76,    77,    78,    79,    80,    81,    83,    88,    90,   147,
     149,   143,   153,   147,   151,   166,   167,   151,     4,     6,
       7,   151,   168,   151,   151,   151,   166,   146,   151,   151,
     151,   151,   151,   151,     5,   151,     5,   151,   151,   168,
     151,   151,    85,     4,     6,   168,     4,     6,     4,     6,
       4,     6,     4,     6,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   168,   168,   167,   168,   168,   168,    24,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    61,    62,
      63,    65,    68,   122,   123,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   146,   149,   150,   157,
     158,   159,   167,     4,     6,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   113,   114,   115,   150,
     168,   135,   134,   135,     4,     6,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   113,   114,   115,
     150,   168,   135,    10,    11,    12,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   168,   134,   135,   136,
     137,   139,   152,    32,   166,     7,   143,   153,   168,    24,
     135,   166,   168,     5,   168,    34,   168,   152,     5,   168,
     168,   168,   146,     5,   146,     5,   152,     4,     6,     4,
       6,    88,   147,    88,   147,    88,   148,   148,   148,   148,
     148,   148,   148,   148,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   145,   152,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   168,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   168,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   154,   146,   146,   146,   146,   146,   152,   168,   152,
     168,    37,   152,   152,   151,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   168,   168,   168,   168,
       4,     6,   168,   168,   168,   168,   168,   168,   168,   168,
     152,   152,   148,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   160,   168,
     168,   152,   168,   168,   168,   152,   152,   152,   152,   152,
     152,   152,   147,   146,   154,   166,   168,   146,   146,   168,
     166,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   168,   168,
     152,   152,   152,   152,   152,   146,   146,   168,   148,   152,
     121,   152,   146,   146,   146,   146,   146,   146,     4,   146,
     166,   152,   166
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  YareParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,    43,    45,    42,    47,    37,    94,
     389,   390,   391,    46,   123,   125,    59,    61,    44,    60,
      63,    40,    41,    91,    93,    33,   126,    62,    38,   124,
      58,    64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  YareParser::yyr1_[] =
  {
         0,   162,   163,   164,   164,   165,   165,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   167,   167,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  YareParser::yyr2_[] =
  {
         0,     2,     3,     6,     0,     2,     0,     1,     4,     4,
       4,     4,     5,     5,     4,     4,     3,     3,     5,     5,
       4,     4,     5,     5,     4,     4,     4,     4,     4,     4,
       2,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       3,     3,     5,     3,     5,     3,     5,     3,     7,     9,
       2,     5,     5,     5,     7,     4,     4,     5,     5,     5,
       5,     5,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       7,     5,     7,     7,     7,     7,     7,     6,     6,     4,
       4,     4,     4,     4,     3,     0,     1,     2,     1,     1,
       1,     1,     4,     5,     3,     5,     5,     5,     5,     5,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     4,     3,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     3,     3,     3,     3,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const YareParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMERIC", "VARIABLE", "CADENA", "ID",
  "ARRAY_ID", "ARRAY_ASSIGN", "ARRAY_ADD_ELEMENT", "ARRAY_PUT",
  "ARRAY_PUTFRONT", "ARRAY_SIZE", "ARRAY_SHIT", "ARRAY_SORT", "ARRAY_DEL",
  "ARRAY_FILL", "ARRAY_CLEAR", "ARRAY_MIN", "ARRAY_MAX", "ARRAY_HEAD",
  "ARRAY_TAIL", "ARRAY_AVERAGE", "ARRAY_REVERSE", "OPVAR_OP", "OPVAR_ADD",
  "OPVAR_SUB", "OPVAR_MUL", "OPVAR_DIV", "OPVAR_POW", "CLEARVARS", "THEN",
  "FIN", "ARRAY_C", "WHILE", "DO_WHILE", "FOREACH", "ELIPSIS", "SYSTEM",
  "EXIT", "DO", "BREAK", "IF", "READ", "READP", "PRASCII", "PRINTN",
  "PRINT", "PUTS", "PUTSN", "RAND", "EXPR_DIV", "EXPR_MAS", "EXPR_MAYOR",
  "EXPR_MAYORIGUAL", "EXPR_MENOR", "EXPR_MENORIGUAL", "EXPR_MENOS",
  "EXPR_MUL", "EXPR_IGUAL", "EXPR_NOT", "MOD_WORD", "_GT_", "_LT_",
  "INIT_RANDOM", "RANGE_RANDOM", "SWAP_ID_VAR", "SWAP_OP", "XOROP", "DEC",
  "INC", "DEC_CPP", "INC_CPP", "ID_ASIGNACION", "OP_ASIGN_ABR_MUL",
  "OP_ASIGN_ABR_DIV", "OP_ASIGN_ABR_MOD", "OP_ASIGN_ABR_MAS",
  "OP_ASIGN_ABR_MENOS", "OP_ASIGN_ABR_SHIFTLEFT",
  "OP_ASIGN_ABR_SHIFTRIGHT", "OP_ASIGN_ABR_AND", "OP_ASIGN_ABR_OR",
  "OP_ASIGN_ABR_POW", "PROC", "FUNCNAME", "CALL", "LETSET_ASSIGN", "TO",
  "MOVE", "PASCAL_ASSIGN", "MOV_ASM", "SUB_ASM", "ADD_ASM", "MUL_ASM",
  "ABS", "FACTORIAL", "SUMATORIA", "SQRT", "ACOS", "ASIN", "ATAN", "ATANH",
  "CEIL", "COS", "COSH", "EXP", "FLOOR", "LN", "SIN", "SINH", "TAN",
  "TANH", "FACE_HAPPY", "FACE_SAD", "FACE_NO", "PUSH", "POP", "STACK_SIZE",
  "TERNARY", "IFX", "ELSE", "OR", "AND", "SHIFTRIGHT", "SHIFTLEFT",
  "ANDBITS", "ORBITS", "LT", "GT", "NE", "EQ", "LE", "GE", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'^'", "EXPR_ELEVADO", "NEGACION", "UMINUS", "'.'",
  "'{'", "'}'", "';'", "'='", "','", "'<'", "'?'", "'('", "')'", "'['",
  "']'", "'!'", "'~'", "'>'", "'&'", "'|'", "':'", "'@'", "$accept",
  "program", "funciones", "cuerpo", "stmt", "stmt_list", "expr", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const YareParser::rhs_number_type
  YareParser::yyrhs_[] =
  {
       163,     0,    -1,   164,   165,   143,    -1,   164,    84,    85,
     144,   167,   145,    -1,    -1,   165,   166,    -1,    -1,   146,
      -1,     4,   147,   168,   146,    -1,     4,    88,   168,   146,
      -1,    89,   168,    88,     4,    -1,    89,   168,    88,     6,
      -1,    91,     4,   148,   168,   146,    -1,    91,     6,   148,
     168,   146,    -1,     4,   149,   135,   168,    -1,     6,   149,
     135,   168,    -1,     4,    90,   168,    -1,     6,    90,   168,
      -1,    87,     4,   147,   168,   146,    -1,    87,     4,    88,
     168,   146,    -1,     6,   147,   168,   146,    -1,     6,    88,
     168,   146,    -1,    87,     6,   147,   168,   146,    -1,    87,
       6,    88,   168,   146,    -1,     4,   147,   150,   146,    -1,
       6,   147,   150,   146,    -1,     4,    67,     4,   146,    -1,
       6,    67,     4,   146,    -1,     4,    67,     6,   146,    -1,
       6,    67,     6,   146,    -1,   168,   146,    -1,     4,   147,
     113,   146,    -1,     4,   147,   114,   146,    -1,     4,   147,
     115,   146,    -1,     6,   147,   113,   146,    -1,     6,   147,
     114,   146,    -1,     6,   147,   115,   146,    -1,    46,   151,
     168,   152,   146,    -1,    45,   151,   168,   152,   146,    -1,
      47,   151,   168,   152,   146,    -1,   144,   167,   145,    -1,
      31,   167,    32,    -1,    48,   151,     5,   152,   146,    -1,
      48,     5,   146,    -1,    49,   151,     5,   152,   146,    -1,
      49,     5,   146,    -1,    34,   151,   168,   152,   166,    -1,
      34,   168,   166,    -1,    40,   166,    34,   151,   168,   152,
     146,    -1,    36,   151,   168,    37,   168,   148,     4,   152,
     166,    -1,    41,   146,    -1,    38,   151,     5,   152,   146,
      -1,    39,   151,   168,   152,   146,    -1,    42,   151,   168,
     152,   166,    -1,    42,   151,   168,   152,   166,   121,   166,
      -1,     4,    77,   168,   146,    -1,     6,    77,   168,   146,
      -1,    93,     4,   148,   168,   146,    -1,    93,     6,   148,
     168,   146,    -1,    92,     4,   148,   168,   146,    -1,    92,
       6,   148,   168,   146,    -1,    94,     4,   148,   168,   146,
      -1,    94,     6,   148,   168,   146,    -1,     4,    78,   168,
      -1,     6,    78,   168,    -1,     4,    76,   168,    -1,     6,
      76,   168,    -1,     4,    79,   168,    -1,     6,    79,   168,
      -1,     4,    74,   168,    -1,     6,    74,   168,    -1,     4,
      75,   168,    -1,     6,    75,   168,    -1,     4,    80,   168,
      -1,     6,    80,   168,    -1,     4,    81,   168,    -1,     6,
      81,   168,    -1,     4,    83,   168,    -1,     6,    83,   168,
      -1,   116,   168,    -1,     7,   153,   168,   154,   147,   168,
     146,    -1,    33,   151,     7,   152,   146,    -1,     7,   143,
      10,   151,   168,   152,   146,    -1,     7,   143,    11,   151,
     168,   152,   146,    -1,     7,   143,    14,   151,   168,   152,
     146,    -1,     7,   143,    15,   151,   168,   152,   146,    -1,
       7,   143,    16,   151,   168,   152,   146,    -1,     7,   143,
      17,   151,   152,   146,    -1,     7,   143,    23,   151,   152,
     146,    -1,    24,   147,   134,   146,    -1,    24,   147,   135,
     146,    -1,    24,   147,   136,   146,    -1,    24,   147,   137,
     146,    -1,    24,   147,   139,   146,    -1,    30,   151,   152,
      -1,    -1,   166,    -1,   167,   166,    -1,     3,    -1,     6,
      -1,     5,    -1,     4,    -1,     7,   153,   168,   154,    -1,
       7,   143,    12,   151,   152,    -1,     7,   143,    12,    -1,
       7,   143,    18,   151,   152,    -1,     7,   143,    19,   151,
     152,    -1,     7,   143,    21,   151,   152,    -1,     7,   143,
      20,   151,   152,    -1,     7,   143,    22,   151,   152,    -1,
     135,   168,    -1,   155,   168,    -1,   156,   168,    -1,    60,
     168,    -1,   168,   134,   168,    -1,   168,   135,   168,    -1,
     168,    57,   168,    -1,   168,    52,   168,    -1,   168,   136,
     168,    -1,   168,    58,   168,    -1,   168,   137,   168,    -1,
     168,    51,   168,    -1,   168,   149,   168,    -1,   168,    55,
     168,    -1,   168,    63,   168,    -1,   168,   157,   168,    -1,
     168,    53,   168,    -1,   168,    62,   168,    -1,   168,   139,
     168,    -1,   168,   140,   168,    -1,   168,   138,   168,    -1,
     168,    61,   168,    -1,   168,   133,   168,    -1,   168,    54,
     168,    -1,   168,   132,   168,    -1,   168,    56,   168,    -1,
     168,   130,   168,    -1,   168,   131,   168,    -1,   168,    59,
     168,    -1,   168,   123,   168,    -1,   168,   122,   168,    -1,
     168,   158,   168,    -1,   168,   159,   168,    -1,   151,   168,
     152,    -1,   168,    24,   168,    -1,   168,   150,   168,   160,
     168,    -1,    43,   151,   152,    -1,    44,   151,     5,   152,
      -1,    50,   151,   152,    -1,   117,    -1,   118,    -1,    95,
     151,   168,   152,    -1,    98,   151,   168,   152,    -1,    99,
     151,   168,   152,    -1,   100,   151,   168,   152,    -1,   101,
     151,   168,   152,    -1,   102,   151,   168,   152,    -1,   103,
     151,   168,   152,    -1,   104,   151,   168,   152,    -1,   105,
     151,   168,   152,    -1,   106,   151,   168,   152,    -1,   107,
     151,   168,   152,    -1,   108,   151,   168,   152,    -1,   109,
     151,   168,   152,    -1,   110,   151,   168,   152,    -1,   111,
     151,   168,   152,    -1,   112,   151,   168,   152,    -1,    97,
     151,   168,   148,   168,   152,    -1,    96,   151,   168,   152,
      -1,    69,   151,     6,   152,    -1,    69,   151,     4,   152,
      -1,    70,   151,     6,   152,    -1,    70,   151,     4,   152,
      -1,   168,    68,   168,    -1,   168,    65,   168,    -1,     4,
     161,   135,    -1,     4,   161,   134,    -1,    86,    85,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  YareParser::yyprhs_[] =
  {
         0,     0,     3,     7,    14,    15,    18,    19,    21,    26,
      31,    36,    41,    47,    53,    58,    63,    67,    71,    77,
      83,    88,    93,    99,   105,   110,   115,   120,   125,   130,
     135,   138,   143,   148,   153,   158,   163,   168,   174,   180,
     186,   190,   194,   200,   204,   210,   214,   220,   224,   232,
     242,   245,   251,   257,   263,   271,   276,   281,   287,   293,
     299,   305,   311,   317,   321,   325,   329,   333,   337,   341,
     345,   349,   353,   357,   361,   365,   369,   373,   377,   381,
     384,   392,   398,   406,   414,   422,   430,   438,   445,   452,
     457,   462,   467,   472,   477,   481,   482,   484,   487,   489,
     491,   493,   495,   500,   506,   510,   516,   522,   528,   534,
     540,   543,   546,   549,   552,   556,   560,   564,   568,   572,
     576,   580,   584,   588,   592,   596,   600,   604,   608,   612,
     616,   620,   624,   628,   632,   636,   640,   644,   648,   652,
     656,   660,   664,   668,   672,   676,   682,   686,   691,   695,
     697,   699,   704,   709,   714,   719,   724,   729,   734,   739,
     744,   749,   754,   759,   764,   769,   774,   779,   786,   791,
     796,   801,   806,   811,   815,   819,   823,   827
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  YareParser::yyrline_[] =
  {
         0,   299,   299,   305,   308,   312,   317,   321,   324,   327,
     330,   333,   336,   339,   342,   345,   348,   351,   354,   357,
     360,   363,   366,   369,   372,   375,   378,   381,   384,   387,
     390,   393,   394,   395,   396,   397,   398,   399,   402,   405,
     408,   411,   414,   417,   420,   423,   426,   429,   432,   435,
     438,   441,   444,   447,   450,   453,   456,   459,   462,   465,
     468,   471,   474,   477,   480,   483,   486,   489,   492,   495,
     498,   501,   504,   507,   510,   513,   516,   519,   522,   525,
     528,   531,   534,   537,   540,   543,   546,   549,   552,   555,
     558,   561,   564,   567,   570,   573,   577,   580,   586,   589,
     597,   600,   603,   606,   609,   612,   615,   618,   621,   624,
     627,   630,   633,   636,   639,   642,   645,   648,   651,   654,
     657,   660,   663,   666,   669,   672,   675,   678,   681,   684,
     687,   690,   693,   696,   699,   702,   705,   708,   711,   714,
     717,   720,   723,   726,   729,   743,   746,   749,   752,   755,
     758,   761,   764,   767,   770,   773,   777,   780,   783,   786,
     789,   792,   795,   798,   801,   804,   807,   810,   813,   816,
     819,   822,   825,   828,   831,   834,   837,   840
  };

  // Print the state stack on the debug stream.
  void
  YareParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  YareParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  YareParser::token_number_type
  YareParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   155,     2,     2,     2,   138,   158,     2,
     151,   152,   136,   134,   148,   135,   143,   137,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   160,   146,
     149,   147,   157,   150,   161,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   153,     2,   154,   139,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   144,   159,   145,   156,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   140,
     141,   142
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int YareParser::yyeof_ = 0;
  const int YareParser::yylast_ = 6724;
  const int YareParser::yynnts_ = 7;
  const int YareParser::yyempty_ = -2;
  const int YareParser::yyfinal_ = 3;
  const int YareParser::yyterror_ = 1;
  const int YareParser::yyerrcode_ = 256;
  const int YareParser::yyntokens_ = 162;

  const unsigned int YareParser::yyuser_token_number_max_ = 391;
  const YareParser::token_number_type YareParser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 9 "yare.y"
} // YL

/* Line 1136 of lalr1.cc  */
#line 4171 "yare.tab.c"


/* Line 1138 of lalr1.cc  */
#line 844 "yare.y"


void YL::YareParser::error(const YL::YareParser::location_type &loc, const std::string &msg) {
	std::cerr << "Error :'(    -> [" << msg << "]" << std::endl;
	
}

#include "YareScanner.h"
static int yylex(YL::YareParser::semantic_type * yylval, YL::FlexScanner &scanner) {
	return scanner.yylex(yylval);
}

nodeTypeTag *con(long double value) {
	nodeType *p;
	/* allocate node */
	if((p = (nodeTypeTag *)malloc(sizeof(nodeTypeTag))) == NULL) {
		cerr << "Memoria insuficiente!" << endl;
		exit(EXIT_FAILURE);
	}
	/* copy information */
	p->type = typeCon;
	p->con.value = value;
	return p;
}

nodeType *opr(int oper, unsigned short nops, ...) {
	va_list ap;
	nodeType *p;
	size_t size;
	int i;
	/* allocate node */
	size = sizeof(oprNodeType) + (nops - 1) * sizeof(nodeType*);
	if ((p = (nodeType *)malloc(size)) == NULL) {
		cerr << "Error, insuficiente memoria." << endl;		
		exit(EXIT_FAILURE);
	}
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;

	va_start(ap, nops);
	for (i = 0; i < nops; i++)
		p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}

nodeType *id(char i) {
	nodeType *p;
	/* allocate node */
	if ((p = (nodeTypeTag *)malloc(sizeof(idNodeType))) == NULL) {
		cerr << "Memoria insuficiente para este programa." << endl;
		exit(EXIT_FAILURE);
	}	
	/* copy information */
	p->type = typeId;
	p->id.i = i;
	return p;
}

nodeType *conStr(char valueString[], short type) {
	nodeType *p = NULL;
	if((p = (nodeTypeTag *)malloc(sizeof(conNodeType))) == NULL) {
		cerr << "Memoria insuficiente para este programa" << endl;
		exit(EXIT_FAILURE);
	}
	// Assign the type:
	p->type = typeCadena;
	strcpy(p->con.cadena, valueString);
	return p;
}

nodeType *idS(char *s) {

	nodeType *p;
	/* allocate node */
	if ((p =(nodeTypeTag *)malloc(sizeof(idNodeType))) == NULL) {
		cerr << "Memoria insuficiente para este programa." << endl;
	}	
	/* copy information */
	p->type = typeVar;
	/* Copiar el id: */
	strcpy(p->id.identificador, s);
	return p;
}

nodeType *idA(char *arrayStr) {
	nodeType *p;

	/* allocate node */
	if ((p = (nodeTypeTag *)malloc(sizeof(idNodeType))) == NULL) {
		cerr << "Memoria insuficiente para este programa." << endl;
		exit(EXIT_FAILURE);
	}
	// copy information:
	p->type = typeArray;
	// Copiar el id:
	strcpy(p->id.identificador, arrayStr);

	return p;
}

nodeType *idA_Index(char *arrayStr, nodeTypeTag *node) {
	nodeType *p;

	/* allocate node */
	if ((p = (nodeTypeTag *)malloc(sizeof(idNodeType))) == NULL) {
		cerr << "Memoria insuficiente para este programa." << endl;
		exit(EXIT_FAILURE);
	}
	// copy information:
	p->type = typeArray;
	p->id.index_array = 2;
	// Copiar el id:
	strcpy(p->id.identificador, arrayStr);

	return p;	
}

void yyerror(char *s) {
	cout << s << ", probable antes de la línea %d.\n" << endl;
}

void freeNode(nodeType *p) {
	
	if (!p) 
		return;

	if (p->type == typeOpr) {
		int i;
		for (i = 0; i < p->opr.nops; i++) 
			freeNode(p->opr.op[i]);
	}
	free(p);
}

// Ejecutar el árbol AST.
long double run(nodeType *p) {

	if(!p) 
		return 0.0L;

	switch(p->type) {

		case typeCon:
			return p->con.value;

		case typeId:
			if((spLoop < 0) || pilaLoop[spLoop]) 
				return sym[p->id.i];
			return 0.0L;

		case typeVar:
			if(vars->isDefined(p->id.identificador)) {
				return vars->getLongValueById(p->id.identificador);
			} else {
				cerr << "La variable '" << p->id.identificador << "' no está definida\n";
				return 0.0L;
			}
			return 0.0L;

		case typeArray:
			if(arrays != NULL) {

				if(arrays->isDefined(p->id.identificador) == false) {
					cerr << "El array '" << p->id.identificador << "' no está declarado\n";
					return 0.0L;	
				} else {

					int __index = p->id.index_array;
					
					if(__index >= arrays->getListById(p->id.identificador).size()) {
						cout << "El índice " << __index << " excede la cantidad de elementos del array '" <<
								p->id.identificador << "'" << endl;
						return 0.0L;
					} else {
						long double val_return = arrays->getListById(p->id.identificador).getList().at(__index);
						cout << "Kaka" << val_return << "\n";
						return val_return;
					}

				}
			} else {
				cerr << "El array '" << p->id.identificador << "' no está declarado\n";
				return 0.0L;
			}
			return 0.0L;

		case typeOpr:
			switch(p->opr.oper) {

				case YL::YareParser::token::WHILE: 
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {	
							while(run(p->opr.op[0]) && pilaLoop[spLoop]) {
								run(p->opr.op[1]);
							}
						} else if(spLoop > 0) {
							while((pilaLoop[spLoop - 1] && pilaLoop[spLoop]) && run(p->opr.op[0])) {
								run(p->opr.op[1]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
					return 0.0L;

				case YL::YareParser::token::BREAK:
					if(spLoop < 0)	{
						cerr << "\nWarning: break fuera de ciclo";
						return 0.0L;
					} else {
						return (pilaLoop[spLoop] = 0);
					}
					return 0.0L;
				
				case YL::YareParser::token::IF:
					if(spLoop < 0) {
						if(run(p->opr.op[0]))
							run(p->opr.op[1]);
						else if (p->opr.nops > 2)
							run(p->opr.op[2]);
					} else if(pilaLoop[spLoop]) {
						if(run(p->opr.op[0]))
							run(p->opr.op[1]);
						else if (p->opr.nops > 2)
							run(p->opr.op[2]);
					}
					return 0.0L;

				case YL::YareParser::token::PRINTN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						// Check if the node is a virtual var:	
						cout.precision(16);
						if(p->opr.op[0]->type == typeId) 
							cout << sym[p->opr.op[0]->id.i] << endl;
						 else 
							cout << run(p->opr.op[0]) << endl;
						return 0.0L;
					}
					return 0.0L;

				case YL::YareParser::token::PRINT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						// Check if the node is a virtual var:	
						cout.precision(16);
						if(p->opr.op[0]->type == typeId) 
							cout << sym[p->opr.op[0]->id.i];
						 else 
							cout << run(p->opr.op[0]);
						return 0.0L;
					}
					return 0.0L;

				case YL::YareParser::token::PUTS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						cout << p->opr.op[0]->con.cadena;
					}
					return 0.0L;	
				

				case YL::YareParser::token::PUTSN: {
					if((spLoop < 0) || pilaLoop[spLoop]) {
						cout << p->opr.op[0]->con.cadena << endl;
					}
					return 0.0L;	
				}

				case YL::YareParser::token::CALL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscarProc(procs, p->opr.op[0]->id.identificador)) {
							return run(getValueProc(procs, p->opr.op[0]->id.identificador));
						} else {
							cerr << "Error, no existe una función" << p->opr.op[0]->id.identificador << endl;
							exit(EXIT_FAILURE);
						}
					}
					return 0.0L;

				case YL::YareParser::token::RAND:
					if((spLoop < 0) || pilaLoop[spLoop])
						return (long double)(rand() % 101);
					return 0.0L;

				case YL::YareParser::token::XOROP:
					if((spLoop < 0) || pilaLoop[spLoop])
						return ((long long)run(p->opr.op[0]) ^ (long long)run(p->opr.op[1]));
					return 0.0L;

				case YL::YareParser::token::RANGE_RANDOM:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						inferior = run(p->opr.op[0]);
						superior = run(p->opr.op[1]);
						if(inferior >= superior) {
							cerr << "Superior range must be greater than inferior range" << endl;
							return -1.0L;
						} else {
							return (long long)rand() % (long long)((run(p->opr.op[1]) + 1.0L) - run(p->opr.op[0])) + run(p->opr.op[0]);
						}
					}
					return 0.0L;

				case YL::YareParser::token::SWAP_OP:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if((p->opr.op[0]->type == typeId) && (p->opr.op[1]->type == typeId)) { //a<->b
							_temp_swap = sym[p->opr.op[0]->id.i];	
							sym[p->opr.op[0]->id.i] = sym[p->opr.op[1]->id.i];
							sym[p->opr.op[1]->id.i] = _temp_swap;
							return 0.0L;
						} else if((p->opr.op[0]->type == typeId) && (p->opr.op[1]->type == typeVar)) { //a<->:x:
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[1]->id.identificador << "' no se ha declarado.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[1]->id.identificador)) {
									_temp_swap = sym[p->opr.op[0]->id.i];	
									sym[p->opr.op[0]->id.i] = vars->getLongValueById(p->opr.op[1]->id.identificador);
									vars->getVarByIndex(vars->getIndex(p->opr.op[1]->id.identificador)).setLongValue(_temp_swap);
								}
							}
						} else if((p->opr.op[0]->type == typeVar) && (p->opr.op[1]->type == typeId)) { //:a:<->b
							if(vars == NULL) {	
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se ha declarado.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									_temp_swap = vars->getLongValueById(p->opr.op[0]->id.identificador);
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(sym[p->opr.op[1]->id.i]);
									sym[p->opr.op[1]->id.i] = _temp_swap;
								}
							}
						} else if((p->opr.op[0]->type == typeVar) && (p->opr.op[1]->type == typeVar)) { //:a:<->:b:
							if(vars == NULL) {	
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se ha declarado.\n";
								exit(EXIT_FAILURE);
							} else {
								_temp_swap = vars->getLongValueById(p->opr.op[0]->id.identificador);
								vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(
									vars->getLongValueById(p->opr.op[1]->id.identificador)
								);
								vars->getVarByIndex(vars->getIndex(p->opr.op[1]->id.identificador)).setLongValue(_temp_swap);
							}
						}
					}
					return 0.0L;

				case ';':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						run(p->opr.op[0]);
						return run(p->opr.op[1]);
					} else 
						return 0.0L;

				case '=':
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (sym[p->opr.op[0]->id.i] = run(p->opr.op[1]));
					return 0.0L;

				//////////////////////////////// Asignaciones abreviadas ////////////////////////////////////////
				case YL::YareParser::token::OP_ASIGN_ABR_MAS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] += run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() + run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_MENOS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] -= run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() - run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_MOD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] = (long long)sym[p->opr.op[0]->id.i] % (long long)run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										(long long)vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() % (long long)run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] = (long long)sym[p->opr.op[0]->id.i] >> (long long)run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										(long long)vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() >> (long long)run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_AND:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] = (long long)sym[p->opr.op[0]->id.i] & (long long)run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										(long long)vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() & (long long)run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] = (long long)sym[p->opr.op[0]->id.i] << (long long)run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										(long long)vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() << (long long)run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_POW:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] = (long double)pow(sym[p->opr.op[0]->id.i], run(p->opr.op[1]));

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										pow(vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble(), run(p->opr.op[1]))
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_MUL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] *= run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "'\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() * run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::OP_ASIGN_ABR_DIV:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							sym[p->opr.op[0]->id.i] /= run(p->opr.op[1]);

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "'\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(
										vars->getIndex(p->opr.op[0]->id.identificador)
									).setLongValue(
										vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).getLongDouble() / run(p->opr.op[1])
									);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::INIT_RANDOM:
					// x = ? | :x: = ?
					if((spLoop < 0) || pilaLoop[spLoop]) {
						switch(p->opr.op[0]->type) {
							case typeId: 
								sym[p->opr.op[0]->id.i] = rand() % 100;
								break;
							case typeVar:
								if(vars == NULL) {
									vars = new Variables();
									vars->add(*(new Var(p->opr.op[0]->id.identificador, rand() % 100)));
								} else {
									if(vars->isDefined(p->opr.op[0]->id.identificador))
										vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(rand() % 100);
								}
								break;
							default:
								break;
						}
					}
					return 0.0L;

				case YL::YareParser::token::DEC:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							_dec_inc_return = --sym[p->opr.op[0]->id.i];
							return _dec_inc_return;

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {		// Si no se ha inicializado el objeto variables:
								cerr << "Variable '" << p->opr.op[0]->id.identificador << "' no declarada." << endl;
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador) == false) {
									cerr << "La variable '" << p->opr.op[0]->id.identificador << "'\n";
									exit(EXIT_FAILURE);
								} else {
									_dec_inc_return = vars->getLongValueById(p->opr.op[0]->id.identificador) - 1.0L;
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(
										_dec_inc_return
									);
									return _dec_inc_return;
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::INC:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							_dec_inc_return = ++sym[p->opr.op[0]->id.i];
							return _dec_inc_return;

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {		// Si no se ha inicializado el objeto variables:
								cerr << "Variable '" << p->opr.op[0]->id.identificador << "' no declarada." << endl;
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador) == false) {
									cerr << "La variable '" << p->opr.op[0]->id.identificador << "'\n";
									exit(EXIT_FAILURE);
								} else {
									_dec_inc_return = vars->getLongValueById(p->opr.op[0]->id.identificador) + 1.0L;
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(
										_dec_inc_return
									);
									return _dec_inc_return;
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::INC_CPP:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							_dec_inc_return = sym[p->opr.op[0]->id.i]++;
							return _dec_inc_return;

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {		// Si no se ha inicializado el objeto variables:
								cerr << "Variable '" << p->opr.op[0]->id.identificador << "' no declarada." << endl;
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador) == false) {
									cerr << "La variable '" << p->opr.op[0]->id.identificador << "'\n";
									exit(EXIT_FAILURE);
								} else {
									_dec_inc_return = vars->getLongValueById(p->opr.op[0]->id.identificador) + 1.0L;
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(
										_dec_inc_return
									);
									return _dec_inc_return - 1.0L;
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::DEC_CPP:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {

							_dec_inc_return = --sym[p->opr.op[0]->id.i];
							return _dec_inc_return;

						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {		// Si no se ha inicializado el objeto variables:
								cerr << "Variable '" << p->opr.op[0]->id.identificador << "' no declarada." << endl;
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador) == false) {
									cerr << "La variable '" << p->opr.op[0]->id.identificador << "'\n";
									exit(EXIT_FAILURE);
								} else {
									_dec_inc_return = vars->getLongValueById(p->opr.op[0]->id.identificador) - 1.0L;
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(
										_dec_inc_return
									);
									return _dec_inc_return;
								}
							}
						}
					}

				case YL::YareParser::token::UMINUS:
					if((spLoop < 0) || pilaLoop[spLoop])
						return -run(p->opr.op[0]);
					return 0.0L;

				////// Creación de identificadores:
				case YL::YareParser::token::ID_ASIGNACION:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(vars == NULL) {
							vars = new Variables();
							vars->add(*(new Var(p->opr.op[0]->id.identificador, run(p->opr.op[1]))));
						} else {

							if(vars->isDefined(p->opr.op[0]->id.identificador)) {
								vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(run(p->opr.op[1]));
							} else {
								vars->add(*(new Var(p->opr.op[0]->id.identificador, run(p->opr.op[1]))));
							}
						}
					}
					return 0.0L;

				/////// Expresiones aritméticas comúnes ////////
				case '+':
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) + run(p->opr.op[1]);
					return 0.0L;
				
				case '-':
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) - run(p->opr.op[1]);
					return 0.0L;

				case '*':
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) * run(p->opr.op[1]);
					return 0.0L;

				case '/':
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) / run(p->opr.op[1]);
					return 0.0L;
				
				case '^':
					if((spLoop < 0) || pilaLoop[spLoop])
						return (long double)pow(run(p->opr.op[0]), run(p->opr.op[1]));
					return 0.0L;

				case '%':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						// cout << "Entra aquí ... \n";
						//return fmod(run(p->opr.op[0]), run(p->opr.op[1]));
						// return (long long)run(p->opr.op[0]) % (long long)run(p->opr.op[1]);
						return (long long)run(p->opr.op[0]) % (long long)run(p->opr.op[1]);
					}
					return 0.0L;

				case YL::YareParser::token::LT:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) < run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::GT:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) > run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::NEGACION:		// "no"|"not"|!|~
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return !run(p->opr.op[0]);
					return 0.0L;
				
				case YL::YareParser::token::GE:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return run(p->opr.op[0]) >= run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::LE:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) <= run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::NE:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) != run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::EQ:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return run(p->opr.op[0]) == run(p->opr.op[1]);
					return 0.0L;
				
				case YL::YareParser::token::AND:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) && run(p->opr.op[1]);
					return 0.0L;
			
				case YL::YareParser::token::OR:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) || run(p->opr.op[1]);
					return 0.0L;
				
				case YL::YareParser::token::ANDBITS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) & (long long)run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::ORBITS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) | (long long)run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::SHIFTLEFT:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) << (long long)run(p->opr.op[1]);
					return 0.0L;

				case YL::YareParser::token::SHIFTRIGHT:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) >> (long long)run(p->opr.op[1]);
					return 0.0L;
				case YL::YareParser::token::ABS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return fabs(run(p->opr.op[0]));
					return 0.0L;
				case YL::YareParser::token::SQRT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						//return sqrt(run(p->opr.op[0]));
						try {
							return MathFunctions::raiz(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'sqrt'" << std::endl;
							exit(EXIT_FAILURE);
						}
					}
					return 0.0L;
				case YL::YareParser::token::ACOS:
					if((spLoop < 0) || pilaLoop[spLoop]) {

						try {
							//return acos(run(p->opr.op[0]));
							return MathFunctions::math_acos(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'acos'" << std::endl;
							exit(EXIT_FAILURE);
						}

						// return acos(run(p->opr.op[0]));
					}
					return 0.0L;

				case YL::YareParser::token::ASIN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						try {
							return MathFunctions::math_asin(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'asin'" << std::endl;
							exit(EXIT_FAILURE);
						}
						// return asin(run(p->opr.op[0]));
					}
					return 0.0L;

				case YL::YareParser::token::CEIL:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return ceil(run(p->opr.op[0]));
					return 0.0L;

				case YL::YareParser::token::COS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return cos(run(p->opr.op[0]));
					return 0.0L;

				case YL::YareParser::token::COSH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return cosh(run(p->opr.op[0]));
					return 0.0L;

				case YL::YareParser::token::EXP:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return exp(run(p->opr.op[0]));
					return 0.0L;

				case YL::YareParser::token::FLOOR:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return floor(run(p->opr.op[0]));
					else
						return 0.0L;

				case YL::YareParser::token::LN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						try {
							return MathFunctions::math_log(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'ln'" << std::endl;
							exit(EXIT_FAILURE);
						}
					} else
						return 0.0L;

				case YL::YareParser::token::SIN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						//return sin(run(p->opr.op[0]));
						return MathFunctions::math_sin_test(run(p->opr.op[0]));
					}
					else
						return 0.0L;

				case YL::YareParser::token::SINH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sinh(run(p->opr.op[0]));
					else
						return 0.0L;

				case YL::YareParser::token::TAN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						try {
							return MathFunctions::math_tan(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'tan'" << std::endl;
							exit(EXIT_FAILURE);

						}
						
					}
					else
						return 0.0L;

				case YL::YareParser::token::ATAN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return MathFunctions::math_atan(run(p->opr.op[0]));
					}
					return 0.0L;

				case YL::YareParser::token::ATANH:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						//return MathFunctions::math_atan(run(p->opr.op[0]));
						try {
							return MathFunctions::math_atanh(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'atanh'" << std::endl;
							exit(EXIT_FAILURE);

						}
					}
					return 0.0L;



				case YL::YareParser::token::TANH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return tanh(run(p->opr.op[0]));
					else
						return 0.0L;

				case YL::YareParser::token::SUMATORIA:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sumatoria((short)run(p->opr.op[0]), (short)run(p->opr.op[1]));
					else
						return 0.0L;

				case YL::YareParser::token::FACTORIAL:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return factorial((long)run(p->opr.op[0]));
					else
						return 0.0L;

				////// Código para la pila Virtual:
				case YL::YareParser::token::PUSH:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(pila == NULL) {
							pila = new Pila();
							pila->add(run(p->opr.op[0]));
						} else {
							pila->add(run(p->opr.op[0]));
						}
						return 0.0L;
					}
					return 0.0L;

				case YL::YareParser::token::POP:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(pila == NULL) {
							cout << "Pila vacía 0x1" << endl;
						} else {
							if(pila->size() > 0) {
								return pila->pop();
							} else {
								cout << "Pila vacía 0x2" << endl;
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::FACE_HAPPY:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {
							return sym[p->opr.op[0]->id.i] = 1.0f;
						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(1.0f);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::FACE_SAD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {
							return sym[p->opr.op[0]->id.i] = -1.0f;
						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(-1.0f);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::FACE_NO:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {
							return sym[p->opr.op[0]->id.i] = 0.0L;
						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(0.0L);
								}
							}
						}
					}
					return 0.0L;

				case YL::YareParser::token::DO_WHILE:
					spLoop++;
					pilaLoop[spLoop] = 1;

					if(spLoop == 0) {
						 while(run(p->opr.op[1]) && pilaLoop[spLoop]) {
							run(p->opr.op[0]);
						}
					} else if(spLoop > 0) {
						while((pilaLoop[spLoop - 1] && pilaLoop[spLoop]) && run(p->opr.op[1])) {
							run(p->opr.op[0]);
						}
					}
					pilaLoop[spLoop] = 0;
					spLoop--;
					return 0.0L;

				case YL::YareParser::token::READ:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						
						char _temp[100];
						char *_end;
						unsigned short _index = 0;
						unsigned char _c;

						long double _resultado;
						
						while((_c = getchar()) != '\n') 
							_temp[_index++] = _c;
						
						_temp[_index] = '\0';
	
						_resultado = check(_temp, &_end);

						if(*_end != '\0') {
							return -1.0f;
						} else {
							return _resultado;
						}
					}

				case YL::YareParser::token::READP:
					
					if((spLoop < 0) || pilaLoop[spLoop]) {
						
						cout << p->opr.op[0]->con.cadena;

						char _temp[100];
						char *_end;
						unsigned short _index = 0;
						unsigned char _c;

						long double _resultado;
						
						while((_c = getchar()) != '\n') 
							_temp[_index++] = _c;
						
						_temp[_index] = '\0';
	
						_resultado = check(_temp, &_end);
						if(*_end != '\0') {
							return -1.0f;
						} else {
							return _resultado;
						}
					}
					return 0.0L;

				case YL::YareParser::token::PRASCII:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						std::cout << (char)getAscii(run(p->opr.op[0]));
					}
					return 0.0L;

				case YL::YareParser::token::FOREACH:
					// std::cout << "Entra aquí ... " << std::endl;
					spLoop++;
					pilaLoop[spLoop] = 1;

					if(spLoop == 0) {
							for(sym[p->opr.op[2]->id.i] = run(p->opr.op[0]);
								(sym[p->opr.op[2]->id.i] <= run(p->opr.op[1]));
								sym[p->opr.op[2]->id.i]++) {
									run(p->opr.op[3]);
							}
						} else if(spLoop > 0) {
							for(sym[p->opr.op[2]->id.i] = run(p->opr.op[0]);
								(pilaLoop[spLoop - 1] && pilaLoop[spLoop]) && (sym[p->opr.op[2]->id.i] <= run(p->opr.op[1]));
								sym[p->opr.op[2]->id.i]++) {
									run(p->opr.op[3]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
					return 0.0L;

				case YL::YareParser::token::SYSTEM:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						int ____x = system(p->opr.op[0]->con.cadena);
					}
					return 0.0L;

				case YL::YareParser::token::EXIT:
					if((spLoop < 0) || pilaLoop[spLoop]) {

						if(vars != NULL) {
							delete(vars);
						}
						if(pila != NULL) {
							delete(pila);
						}

						_exit_return_ = run(p->opr.op[0]);
						freeNode(p);
						exit(_exit_return_);
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_C:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays == NULL) {
							// Crear el objeto de arrays
							arrays = new Arrays();

							if(arrays->isDefined(p->opr.op[0]->id.identificador)) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' ya está declarado" << endl;
							} else {
								arrays->add(*(new Array(p->opr.op[0]->id.identificador)));
							}
							return 0.0L;
						} else {

							if(arrays->isDefined(p->opr.op[0]->id.identificador)) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' ya está declarado" << endl;
							} else {
								arrays->add(*(new Array(p->opr.op[0]->id.identificador)));
							}
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_ASSIGN:
					if((spLoop < 0) || pilaLoop[spLoop]) {

						if(arrays != NULL) {

							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {

								long double __index_array = run(p->opr.op[1]);

								if(__index_array >= arrays->getListById(p->opr.op[0]->id.identificador).size()) {
									cout << "El índice " << __index_array << " excede la cantidad de elementos del array '" <<
										p->opr.op[0]->id.identificador << "'" << endl;
										return 0.0L;
								} else {

									arrays->getListById(p->opr.op[0]->id.identificador).getList().at(__index_array) = 
										run(p->opr.op[2]);
									return 0.0L;
								}

							}

						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_PUT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								arrays->getListById(p->opr.op[0]->id.identificador).add(run(p->opr.op[1]));
								return 0.0L;
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_PUTFRONT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								arrays->getListById(p->opr.op[0]->id.identificador).putfront(run(p->opr.op[1]));
								return 0.0L;
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_SORT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								arrays->getListById(p->opr.op[0]->id.identificador).ordenar(run(p->opr.op[1]));
								return 0.0L;
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_REVERSE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								//	Empezar la copia:
								arrays->getListById(p->opr.op[0]->id.identificador).reverse();
								return 0.0L;
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;
				
				case YL::YareParser::token::ARRAY_DEL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								
								int __index_del = (int)run(p->opr.op[1]);
								if(__index_del < 0) {
									cout << "Error, no existe un elemento con índice negativo." << endl;
									return 0.0L;
								}

								if(__index_del >= arrays->getListById(p->opr.op[0]->id.identificador).size()) {
									cout << "Error, se intenta eliminar un elemento del array que no existe." << endl;
									return 0.0L;
								} else {
									arrays->getListById(p->opr.op[0]->id.identificador).eliminarN(__index_del);
									return 0.0L;
								}
								
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_FILL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								
								int __index_del = (int)run(p->opr.op[1]);
								
								if(__index_del < 0) {
									cout << "Error, introduzca un número positivo." << endl;
									return 0.0L;
								}

								arrays->getListById(p->opr.op[0]->id.identificador).fill(__index_del);
								return 0.0L;
								
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_CLEAR:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								
								arrays->getListById(p->opr.op[0]->id.identificador).limpiar();
								return 0.0L;
								
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_SIZE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								int __size = arrays->getListById(p->opr.op[0]->id.identificador).size();
								return __size;
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_SHIT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								
								long double __index_array = run(p->opr.op[1]);

								if(__index_array >= arrays->getListById(p->opr.op[0]->id.identificador).size()) {
									cout << "El índice " << __index_array << " excede la cantidad de elementos del array '" <<
										p->opr.op[0]->id.identificador << "'" << endl;
										return 0.0L;
								} else {

									return arrays->getListById(p->opr.op[0]->id.identificador).getList().at(__index_array);
								}


							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_MIN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								return arrays->getListById(p->opr.op[0]->id.identificador).minmax(true);
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_MAX:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								return arrays->getListById(p->opr.op[0]->id.identificador).minmax(!true);
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_TAIL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								return arrays->getListById(p->opr.op[0]->id.identificador).tail();
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_HEAD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								return arrays->getListById(p->opr.op[0]->id.identificador).head();
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::ARRAY_AVERAGE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(arrays != NULL) {
							if(arrays->isDefined(p->opr.op[0]->id.identificador) == false) {
								cout << "El array '" << p->opr.op[0]->id.identificador << "' no se ha declarado." << endl;
								return 0.0L;
							} else {
								return arrays->getListById(p->opr.op[0]->id.identificador).average();
							}
						} else {
							cout << "Error, no se ha declarado el array '" << p->opr.op[0]->id.identificador << "'" << endl;
							return 0.0L;
						}
					}
					return 0.0L;

				case YL::YareParser::token::STACK_SIZE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(pila == NULL) {
							return 0.0L;
						} else {
							return pila->size();
						}
					}
					return 0.0L;

				case YL::YareParser::token::OPVAR_ADD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "+");
					}
					return 0.0L;

				case YL::YareParser::token::OPVAR_SUB:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "-");
					}
					return 0.0L;

				case YL::YareParser::token::OPVAR_MUL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "*");
					}
					return 0.0L;

				case YL::YareParser::token::OPVAR_DIV:	
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "/");
					}
					return 0.0L;

				case YL::YareParser::token::OPVAR_POW:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "^");
					}
					return 0.0L;

				case YL::YareParser::token::CLEARVARS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(vars != NULL) {
							vars->limpiar();
						}
					}
					return 0.0L;

				case YL::YareParser::token::TERNARY:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(run(p->opr.op[0])) {
							return run(p->opr.op[1]);
						} else {
							return run(p->opr.op[2]);
						}
					}
					return 0.0L;

			}
			default:
					break;
	}
	return 0.0L;
}

long double validateInput(char *s, bool &result) {
    std::istringstream test(s);

    long double value;
    std::string rest;

    if (!(test >> value) || (test >> rest)) {
        result = false;
        return 0.0L;
    } else {
        result = true;
        return value;
    }
}

void freeResources(void) {
	if(vars != NULL) {
		delete(vars);
	}
	if(pila != NULL) {
		delete(pila);
	}
	if(arrays != NULL) {
		delete(arrays);
	}
}

unsigned short int getAscii(long long valor) {
	/* PENDIENTE Ponerlo en forma sexy: */
	if((valor >= 0) && (valor <= 255))
		return valor;
	else
		return (valor % 255);
}

