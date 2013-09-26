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
#line 303 "yare.y"
    {
	exit(EXIT_SUCCESS);
}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 309 "yare.y"
    {
		push_l_proc(&procs, (yysemantic_stack_[(6) - (3)].nameFunction), (yysemantic_stack_[(6) - (5)].nPtr));
	}
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 312 "yare.y"
    {;}
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 316 "yare.y"
    { 
		run((yysemantic_stack_[(2) - (2)].nPtr));		
		freeNode((yysemantic_stack_[(2) - (2)].nPtr));

	}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 321 "yare.y"
    {;}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 325 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, NULL, NULL); 
	}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 328 "yare.y"
    { 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 331 "yare.y"
    {		// x to 1 + 2; 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 334 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (4)].sIndex)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 337 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (4)].identificador)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 340 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 343 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 346 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 349 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 352 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 355 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 358 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 361 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 364 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 367 "yare.y"
    { 	// :x: to 1 + 2;
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 370 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 373 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 376 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, id((yysemantic_stack_[(4) - (1)].sIndex)));
	}
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 379 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, idS((yysemantic_stack_[(4) - (1)].identificador)));
	}
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 382 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 385 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 388 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 391 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 394 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(2) - (1)].nPtr); 
	}
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 397 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 398 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 399 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 400 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 401 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 402 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 403 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINTN, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 406 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRASCII, 1, (yysemantic_stack_[(5) - (3)].nPtr));
	}
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 409 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINT, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 412 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 415 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 418 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 421 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 424 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTSN, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 427 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTSN, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 430 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 433 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(3) - (2)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 436 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DO_WHILE, 2, (yysemantic_stack_[(7) - (2)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 439 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FOREACH, 4, (yysemantic_stack_[(9) - (3)].nPtr), (yysemantic_stack_[(9) - (5)].nPtr), id((yysemantic_stack_[(9) - (7)].sIndex)), (yysemantic_stack_[(9) - (9)].nPtr));
	}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 442 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::BREAK, 0);
	}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 445 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SYSTEM, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));	
	}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 448 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXIT, 1, (yysemantic_stack_[(5) - (3)].nPtr));		
	}
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 451 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr));
	}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 454 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 3, (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr), (yysemantic_stack_[(7) - (7)].nPtr)); 
	}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 457 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 460 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 463 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 466 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 469 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 472 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 475 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 478 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 481 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 484 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 487 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 490 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 493 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 496 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 499 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 502 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 505 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 508 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 511 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 514 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 517 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 520 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 523 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 526 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 529 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUSH, 1, (yysemantic_stack_[(2) - (2)].nPtr));	
	}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 532 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_ASSIGN, 3, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (6)].nPtr));
	}
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 535 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_C, 1, idA((yysemantic_stack_[(5) - (3)].identificador)));
	}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 538 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_PUT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 541 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_PUTFRONT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 544 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SORT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 547 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_DEL, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 550 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_FILL, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 553 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_CLEAR, 1, idA((yysemantic_stack_[(6) - (1)].identificador)));
	}
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 556 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_REVERSE, 1, idA((yysemantic_stack_[(6) - (1)].identificador)));
	}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 559 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_ADD, 0); 
	}
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 562 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_SUB, 0); 
	}
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 565 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_MUL, 0); 
	}
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 568 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_DIV, 0); 
	}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 571 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_POW, 0); 
	}
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 574 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CLEARVARS, 0);
	}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 577 "yare.y"
    {;}
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 581 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(1) - (1)].nPtr); 
	}
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 584 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, (yysemantic_stack_[(2) - (1)].nPtr), (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 590 "yare.y"
    {
		(yyval.nPtr) = con((yysemantic_stack_[(1) - (1)].valnum));
	}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 593 "yare.y"
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
#line 601 "yare.y"
    {
		(yyval.nPtr) = conStr((yysemantic_stack_[(1) - (1)].cadena), typeCadena);
	}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 604 "yare.y"
    { 
		(yyval.nPtr) = id((yysemantic_stack_[(1) - (1)].sIndex)); 
	}
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 607 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SHIT, 2, idA((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 610 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 613 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA((yysemantic_stack_[(3) - (1)].identificador)));
	}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 616 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_MIN, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 619 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_MAX, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 622 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_TAIL, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 625 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_HEAD, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 628 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_AVERAGE, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 631 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::UMINUS, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 634 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 637 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 640 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 643 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 646 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 649 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 652 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 655 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 658 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 661 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 664 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 667 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 670 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 673 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 676 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 679 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 682 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 685 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 688 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 691 "yare.y"
    { 
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 694 "yare.y"
    {
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 697 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 700 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 703 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 706 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 709 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 712 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 715 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 718 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::AND, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 721 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OR, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 724 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ANDBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 727 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ORBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 730 "yare.y"
    {
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr);
	}
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 733 "yare.y"
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
#line 747 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TERNARY, 3, (yysemantic_stack_[(5) - (1)].nPtr), (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr));
	}
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 750 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READ, 0);
	}
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 753 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READP, 1, conStr((yysemantic_stack_[(4) - (3)].cadena), typeCadena));
	}
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 756 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RAND, 0);
	}
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 759 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::POP, 0);
	}
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 762 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::STACK_SIZE, 0);
	}
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 765 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ABS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 768 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SQRT, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 771 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ACOS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 774 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ACOSH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 777 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ASIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 780 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ASINH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 783 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 787 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 790 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CEIL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 793 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 796 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COSH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 799 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXP, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 802 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FLOOR, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 805 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::LN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 808 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 811 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SINH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 814 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 817 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SEC, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 820 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CSC, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 823 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 826 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SUMATORIA, 2, (yysemantic_stack_[(6) - (3)].nPtr), (yysemantic_stack_[(6) - (5)].nPtr));	
	}
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 829 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FACTORIAL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 832 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 835 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 838 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 841 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 177:

/* Line 690 of lalr1.cc  */
#line 844 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::XOROP, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 178:

/* Line 690 of lalr1.cc  */
#line 847 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RANGE_RANDOM, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 179:

/* Line 690 of lalr1.cc  */
#line 850 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 180:

/* Line 690 of lalr1.cc  */
#line 853 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 181:

/* Line 690 of lalr1.cc  */
#line 856 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CALL, 1, idS((yysemantic_stack_[(2) - (2)].nameFunction)));
	}
    break;



/* Line 690 of lalr1.cc  */
#line 2118 "yare.tab.c"
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
  const short int YareParser::yypact_ninf_ = -142;
  const short int
  YareParser::yypact_[] =
  {
      -142,    18,   -76,  -142,   -54,   800,  -112,  -142,   -55,  -142,
     -37,  -141,  -102,  -103,  1348,   -85,  1672,   -66,   -63,   -62,
    1348,   -44,   -47,   -46,   -43,   -42,   -40,   -38,     8,     9,
     -36,  1756,   -35,   -34,    33,     5,  1756,    23,    28,    41,
      55,   -32,   -31,   -29,   -28,   -27,   -23,   -22,   -21,   -20,
      -7,    -6,    11,    16,    17,    20,    22,    35,    40,    42,
      43,    44,    48,  1756,  -142,  -142,  1756,  -142,  1348,  -142,
    1756,  1756,  1756,  -142,  1866,  1348,    56,  1756,  1756,  1756,
    1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1423,    34,
    -134,    82,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,
    1756,  1756,  1756,  1510,    52,    62,  1756,   -72,    38,  -142,
     937,   143,    31,  -142,  -140,  1756,   502,  1756,   199,  1756,
     172,  -142,  1756,    73,   225,  1756,  1756,  1756,    81,   227,
      83,   229,   107,   277,    93,    96,  -142,   -87,   -86,  1906,
     117,   118,   119,   120,   121,   122,   123,   124,  1756,  1756,
    1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,
    1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,
    6857,   277,  1074,  2027,   277,   277,  1756,  1756,  1756,  1756,
    1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,
    1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,  1756,
    1756,  1756,  1756,  1756,  -142,  1756,  1756,  1756,  1756,  1756,
    1211,   127,   128,  6857,  6857,  6857,  2067,  6857,  6857,  6857,
    6857,  6857,  2188,  6857,   129,   130,   131,   132,  2228,  1756,
    -142,  -142,   133,   135,  6857,  6857,  6857,  2349,  6857,  6857,
    6857,  6857,  6857,  2389,  6857,   136,   137,   140,   141,  2510,
    1756,   138,   139,   142,   144,   145,   147,   148,   149,   150,
     151,   152,   153,   155,  2550,   146,   170,   174,   176,   177,
    -142,  -142,  -142,   173,    36,  1756,  2671,  1597,  1756,  -142,
    2711,   175,  2832,   180,  2872,  -142,   182,  2993,  3033,  3154,
    -142,   183,  -142,   184,  -142,   185,   187,   190,   191,  1756,
    1756,  1756,  1756,    97,  1756,  1756,  1756,  1756,  1756,  1756,
    1756,  1756,  3194,  3315,  3355,  3476,  3516,  3637,  3677,  3798,
    3838,  3959,  3999,  4120,  4160,  4281,  4321,  4442,  4482,  4603,
    4643,  4764,  4804,  4925,  -142,  -142,  6857,    26,  1740,   320,
     320,   320,   320,  1740,    26,   320,    39,   320,   320,  6857,
    6857,  6897,  7054,   320,   320,   320,   320,  1740,  1740,    26,
      26,    39,   265,   277,  6857,   260,  6857,  6857,  6857,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  7018,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  7018,
    1756,  1756,   192,  1756,  1756,  1756,   193,   194,   195,   196,
     197,   198,   200,   181,  -142,  -142,  -142,  -142,  -142,   205,
    4965,   663,  5086,  1756,   207,   212,  1756,  1348,  -142,   223,
     224,   226,   230,   232,  -142,  -142,  -142,  -142,  5126,  5247,
    5287,  5408,  -142,  -142,  5448,  5569,  5609,  5730,  5770,  5891,
    5931,  6052,  -142,  -142,  1756,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  1756,  6092,  6213,  -142,  6253,  6374,
    6414,   233,  -142,  -142,  -142,  -142,  -142,   234,  1756,  -142,
    -142,  -142,  6535,  -142,  -142,  6575,   167,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  6696,  6857,   239,   240,   241,   242,
     243,  -142,  -142,  6736,   291,   255,  1348,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,   219,  -142,  -142,  1348,  -142
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
       0,     0,     0,     0,   149,   150,     0,     2,    95,     7,
       0,     0,     0,     5,     0,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,   101,    99,     0,     0,    95,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    71,    65,     0,    63,    67,    73,
      75,    77,     0,    16,     0,     0,     0,     0,     0,     0,
     180,   179,     0,     0,    70,    72,    66,     0,    64,    68,
      74,    76,    78,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    41,    97,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,   146,     0,     0,     0,     0,
      43,     0,    45,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,   143,   144,   121,   117,   126,
     133,   123,   135,   116,   119,   138,   131,   127,   124,   178,
     177,   140,   139,   136,   137,   134,   132,   114,   115,   118,
     120,   130,   128,   129,   122,     0,   125,   141,   142,     3,
      26,    28,    55,     9,    31,    32,    33,    24,     8,    14,
      27,    29,    56,    21,    34,    35,    36,    25,    20,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   102,    89,    90,    91,    92,    93,     0,
       0,   143,   115,     0,     0,     0,     0,    95,   147,     0,
       0,     0,     0,     0,   174,   173,   176,   175,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   172,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,     0,     0,     0,   103,     0,     0,
       0,     0,   105,   106,   108,   107,   109,     0,     0,    81,
     102,    46,     0,    51,    52,     0,    53,    38,    37,    39,
      42,    44,    19,    18,    23,    22,    12,    13,    59,    60,
      57,    58,    61,    62,     0,   145,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,    95,   171,    82,    83,
      84,    85,    86,    80,     0,    48,    54,    95,    49
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  YareParser::yypgoto_[] =
  {
      -142,  -142,  -142,  -142,    -5,   -65,    59
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  YareParser::yydefgoto_[] =
  {
        -1,     1,     2,     5,   109,   110,    74
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char YareParser::yytable_ninf_ = -111;
  const short int
  YareParser::yytable_[] =
  {
        73,   299,   301,   172,   230,   231,   105,   274,     4,   137,
     210,   138,    76,   128,   130,   120,   106,   275,     3,    77,
      78,    79,    80,    81,    82,    83,    84,   140,    85,   141,
      91,     6,   142,    86,   143,    87,    75,    92,    93,    94,
      95,    96,    97,    98,    99,   144,   100,   145,   253,   107,
     176,   101,   108,   102,   258,   259,   260,   261,   262,   146,
     211,   147,   212,   176,   300,   302,   265,   266,   267,   268,
     111,   269,   251,   252,   253,   116,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   232,   186,   233,   117,
     133,   189,   118,   119,   190,   139,    88,   295,    89,   296,
     297,   432,   298,   433,   189,   272,   121,   190,   122,   123,
      90,   279,   124,   125,   103,   126,   104,   127,   136,   132,
     134,   135,   170,   148,   149,   171,   150,   151,   152,   173,
     174,   175,   153,   154,   155,   156,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   228,   157,   158,
     273,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   249,   129,   131,   264,   159,   272,   201,   202,
     203,   160,   161,   229,   276,   162,   280,   163,   282,   205,
     206,   284,   202,   203,   287,   288,   289,   207,   208,   209,
     164,   250,   205,   206,   270,   165,    90,   166,   167,   168,
     207,   208,   209,   169,   281,   272,   283,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   285,
     286,   290,   291,   292,   293,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   294,   364,   365,   366,   367,   368,   304,
     305,   306,   307,   308,   309,   310,   311,   370,   371,   374,
     375,   376,   377,   380,   176,   381,   384,   385,   379,   176,
     386,   387,   516,   390,   391,   524,   404,   392,     0,   393,
     394,   176,   395,   396,   397,   398,   399,   400,   401,   389,
     402,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     405,   186,   187,   188,   406,   189,   407,   408,   190,   409,
     189,   414,   478,   190,   410,   416,   336,   412,   418,   422,
     423,   424,   189,   425,   176,   190,   426,   427,   467,   471,
     472,   473,   474,   475,   476,   479,   477,   483,   428,   429,
     430,   431,   484,   434,   435,   436,   437,   438,   439,   440,
     441,   177,   178,   487,   488,   527,   489,   183,   184,     0,
     490,   186,   491,   511,   512,   189,   191,   192,   190,   518,
     519,   520,   521,   522,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   525,   481,     0,     0,   203,
       0,     0,   486,   205,   206,     0,     0,     0,   205,   206,
       0,   207,   208,   209,   464,     0,   207,   208,   209,     0,
     205,   206,     0,     0,     0,     0,     0,     0,   207,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   465,
     466,     0,   468,   469,   470,     0,     0,     0,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,   482,   205,   206,   485,     0,     0,     0,     0,
       0,   207,   208,   209,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     7,     8,     9,    10,    11,
       0,   526,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,   505,     0,     0,   277,     0,     0,     0,
       0,     0,    13,    14,     0,    15,    16,   513,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   177,   178,   179,   180,   181,   182,   183,
     184,   185,    31,   186,   187,   188,     0,   189,     0,     0,
     190,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    35,
       0,    36,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,    63,    64,    65,     0,     0,     0,   191,   192,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   278,   199,   200,   201,   202,   203,     0,     0,     0,
      68,     0,    69,     0,     0,   205,   206,    70,     0,     0,
       0,    71,    72,   207,   208,   209,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,    13,    14,   -95,    15,    16,     0,    17,
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,    36,     0,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,    63,    64,    65,     0,     0,   -95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     7,     8,     9,    10,    11,     0,     0,
     -95,    68,   -95,    69,     0,     0,     0,     0,    70,     0,
       0,     0,    71,    72,    12,     0,     0,     0,     0,     0,
      13,    14,     0,    15,    16,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,    36,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       7,     8,     9,    10,    11,     0,     0,    67,    68,     0,
      69,     0,     0,     0,     0,    70,     0,     0,     0,    71,
      72,    12,     0,     0,     0,     0,     0,    13,    14,   271,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,    36,     0,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,    63,    64,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     7,     8,     9,
      10,    11,     0,     0,     0,    68,     0,    69,     0,     0,
       0,     0,    70,     0,     0,     0,    71,    72,    12,     0,
       0,     0,     0,     0,    13,    14,     0,    15,    16,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,    36,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,     0,     0,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     7,     8,     9,    10,    11,     0,
       0,     0,    68,   334,    69,     0,     0,     0,     0,    70,
       0,     0,     0,    71,    72,    12,     0,     0,     0,     0,
       0,    13,    14,     0,    15,    16,     0,    17,     0,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,     0,
      36,     0,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,    63,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     7,     8,     9,    10,    11,     0,     0,     0,    68,
     369,    69,     0,     0,     0,     0,    70,     0,     0,     0,
      71,    72,    12,     0,     0,     0,     0,     0,    13,    14,
       0,    15,    16,     0,    17,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     7,   112,     9,   113,
     114,     0,     0,     0,    34,    35,     0,    36,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    23,    24,    63,    64,
      65,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,    66,     0,     0,
       0,     0,    32,    33,     0,     0,    68,     0,    69,     0,
       0,     0,     0,    70,     0,     0,     0,    71,    72,    34,
       0,     0,     0,     7,   112,     9,   113,   114,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     224,   225,   226,     0,    64,    65,     0,     0,     0,     0,
       0,     0,     0,    23,    24,     0,     0,     0,     0,     0,
      30,     0,    66,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,   227,    70,    32,
      33,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       7,   112,     9,   113,   114,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   245,   246,   247,
       0,    64,    65,     0,     0,     0,     0,     0,     0,     0,
      23,    24,     0,     0,     0,     0,     0,    30,     0,    66,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,   248,    70,    32,    33,     0,    71,
      72,     0,     0,     0,     0,     7,   112,     9,   113,   114,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    23,    24,     0,    64,    65,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,    66,     0,     0,     0,
       0,    32,    33,     0,     0,     0,     0,     0,   107,     0,
       0,     0,    70,     0,     0,     0,    71,    72,    34,     7,
     112,     9,   113,   114,   176,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,   177,     0,    64,    65,     0,     0,     0,   184,    23,
      24,   186,     0,     0,     0,   189,    30,     0,   190,     0,
       0,    66,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,   115,     0,     0,
       0,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,     0,     0,    64,    65,     0,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
     176,     0,     0,   205,   206,    66,     0,     0,     0,     0,
       0,   207,   208,   209,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,    71,    72,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     176,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   303,     0,     0,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,   204,     0,     0,   205,
     206,     0,     0,     0,     0,     0,     0,   207,   208,   209,
       0,     0,   191,   192,     0,     0,     0,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   176,     0,     0,     0,     0,     0,     0,     0,   205,
     206,     0,     0,     0,     0,     0,     0,   207,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   176,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,     0,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,   335,     0,     0,     0,     0,   207,   208,
     209,     0,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   176,     0,     0,     0,     0,   372,     0,     0,
     205,   206,     0,     0,     0,     0,     0,     0,   207,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   176,   189,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,     0,   189,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,   373,     0,
       0,   205,   206,     0,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   176,     0,     0,     0,     0,   378,     0,
       0,   205,   206,     0,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   176,   189,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,     0,   189,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   382,
       0,     0,   205,   206,     0,     0,     0,     0,     0,     0,
     207,   208,   209,     0,     0,   191,   192,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   176,     0,     0,     0,     0,   383,
       0,     0,   205,   206,     0,     0,     0,     0,     0,     0,
     207,   208,   209,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   176,   189,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,     0,   189,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   192,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
     388,     0,     0,   205,   206,     0,     0,     0,     0,     0,
       0,   207,   208,   209,     0,     0,   191,   192,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   176,     0,     0,     0,     0,
       0,     0,     0,   205,   206,     0,     0,     0,   403,     0,
       0,   207,   208,   209,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   176,   189,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,   413,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,     0,   189,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   192,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   206,     0,   411,     0,     0,
       0,     0,   207,   208,   209,     0,     0,   191,   192,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   176,     0,     0,     0,
       0,     0,     0,     0,   205,   206,     0,     0,     0,     0,
       0,     0,   207,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   176,   189,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,     0,   189,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   192,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   206,     0,   415,     0,
       0,     0,     0,   207,   208,   209,     0,     0,   191,   192,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   176,     0,     0,
       0,     0,     0,     0,     0,   205,   206,     0,   417,     0,
       0,     0,     0,   207,   208,   209,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   176,   189,     0,
       0,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,     0,   189,     0,
       0,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     192,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,   419,
       0,     0,     0,     0,   207,   208,   209,     0,     0,   191,
     192,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   176,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,   420,
       0,     0,     0,     0,   207,   208,   209,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,   176,   189,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   192,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
     421,     0,     0,     0,     0,   207,   208,   209,     0,     0,
     191,   192,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   176,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
     442,     0,     0,     0,     0,   207,   208,   209,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   176,
     189,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,     0,
     189,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   206,
       0,   443,     0,     0,     0,     0,   207,   208,   209,     0,
       0,   191,   192,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     176,     0,     0,     0,     0,     0,     0,   444,   205,   206,
       0,     0,     0,     0,     0,     0,   207,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     176,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,     0,     0,     0,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,     0,     0,     0,   205,
     206,     0,   445,     0,     0,     0,     0,   207,   208,   209,
       0,     0,   191,   192,     0,     0,     0,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   176,     0,     0,     0,     0,     0,     0,     0,   205,
     206,     0,   446,     0,     0,     0,     0,   207,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   176,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,     0,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,   447,     0,     0,     0,     0,   207,   208,
     209,     0,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   176,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,   448,     0,     0,     0,     0,   207,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   176,   189,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,     0,   189,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   206,     0,   449,     0,     0,     0,     0,   207,
     208,   209,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   176,     0,     0,     0,     0,     0,     0,
       0,   205,   206,     0,   450,     0,     0,     0,     0,   207,
     208,   209,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   176,   189,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,     0,   189,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   206,     0,   451,     0,     0,     0,     0,
     207,   208,   209,     0,     0,   191,   192,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   176,     0,     0,     0,     0,     0,
       0,     0,   205,   206,     0,   452,     0,     0,     0,     0,
     207,   208,   209,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   176,   189,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,     0,   189,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   192,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   206,     0,   453,     0,     0,     0,
       0,   207,   208,   209,     0,     0,   191,   192,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   176,     0,     0,     0,     0,
       0,     0,     0,   205,   206,     0,   454,     0,     0,     0,
       0,   207,   208,   209,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   176,   189,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,     0,   189,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   192,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,     0,     0,     0,   205,   206,     0,   455,     0,     0,
       0,     0,   207,   208,   209,     0,     0,   191,   192,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   176,     0,     0,     0,
       0,     0,     0,     0,   205,   206,     0,   456,     0,     0,
       0,     0,   207,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   176,   189,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,     0,   189,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   192,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,     0,     0,
       0,     0,     0,     0,     0,   205,   206,     0,   457,     0,
       0,     0,     0,   207,   208,   209,     0,     0,   191,   192,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   176,     0,     0,
       0,     0,     0,     0,     0,   205,   206,     0,   458,     0,
       0,     0,     0,   207,   208,   209,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   176,   189,     0,
       0,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,     0,   189,     0,
       0,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     192,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,   459,
       0,     0,     0,     0,   207,   208,   209,     0,     0,   191,
     192,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   176,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,   460,
       0,     0,     0,     0,   207,   208,   209,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,   176,   189,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   192,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
     461,     0,     0,     0,     0,   207,   208,   209,     0,     0,
     191,   192,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   176,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
     462,     0,     0,     0,     0,   207,   208,   209,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   176,
     189,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,     0,
     189,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,     0,   205,   206,
       0,   463,     0,     0,     0,     0,   207,   208,   209,     0,
       0,   191,   192,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     176,     0,     0,     0,     0,     0,     0,     0,   205,   206,
       0,     0,     0,   480,     0,     0,   207,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     0,  -110,  -110,  -110,
     176,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -110,  -110,     0,     0,     0,     0,     0,     0,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,     0,     0,     0,     0,     0,  -110,     0,     0,   205,
     206,     0,     0,     0,     0,     0,     0,   207,   208,   209,
       0,     0,   191,   192,     0,     0,     0,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   176,     0,     0,     0,     0,   492,     0,     0,   205,
     206,     0,     0,     0,     0,     0,     0,   207,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   176,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,     0,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,   493,     0,     0,
     205,   206,     0,     0,     0,     0,     0,     0,   207,   208,
     209,     0,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   176,     0,     0,     0,     0,   494,     0,     0,
     205,   206,     0,     0,     0,     0,     0,     0,   207,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,   176,   189,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,     0,   189,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,   495,     0,
       0,   205,   206,     0,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   176,     0,     0,     0,     0,   496,     0,
       0,   205,   206,     0,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,   176,   189,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,     0,   189,     0,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   497,
       0,     0,   205,   206,     0,     0,     0,     0,     0,     0,
     207,   208,   209,     0,     0,   191,   192,     0,     0,     0,
       0,     0,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   176,     0,     0,     0,     0,   498,
       0,     0,   205,   206,     0,     0,     0,     0,     0,     0,
     207,   208,   209,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   176,   189,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,     0,   189,     0,     0,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   192,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,     0,     0,     0,     0,     0,
     499,     0,     0,   205,   206,     0,     0,     0,     0,     0,
       0,   207,   208,   209,     0,     0,   191,   192,     0,     0,
       0,     0,     0,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   176,     0,     0,     0,     0,
     500,     0,     0,   205,   206,     0,     0,     0,     0,     0,
       0,   207,   208,   209,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,   176,   189,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,     0,   189,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   191,   192,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,   501,     0,     0,   205,   206,     0,     0,     0,     0,
       0,     0,   207,   208,   209,     0,     0,   191,   192,     0,
       0,     0,     0,     0,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   176,     0,     0,     0,
       0,   502,     0,     0,   205,   206,     0,     0,     0,     0,
       0,     0,   207,   208,   209,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,   176,   189,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,     0,   189,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   191,   192,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,     0,     0,     0,
       0,     0,   503,     0,     0,   205,   206,     0,     0,     0,
       0,     0,     0,   207,   208,   209,     0,     0,   191,   192,
       0,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   176,     0,     0,
       0,     0,     0,     0,     0,   205,   206,     0,   506,     0,
       0,     0,     0,   207,   208,   209,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,   176,   189,     0,
       0,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,     0,   189,     0,
       0,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
     192,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,   507,
       0,     0,     0,     0,   207,   208,   209,     0,     0,   191,
     192,     0,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   176,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,   508,
       0,     0,     0,     0,   207,   208,   209,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,   176,   189,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,   192,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
     509,     0,     0,     0,     0,   207,   208,   209,     0,     0,
     191,   192,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   176,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
     510,     0,     0,     0,     0,   207,   208,   209,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,   176,
     189,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,     0,
     189,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,   192,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,     0,     0,   514,   205,   206,
       0,     0,     0,     0,     0,     0,   207,   208,   209,     0,
       0,   191,   192,     0,     0,     0,     0,     0,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     176,     0,     0,     0,     0,     0,     0,     0,   205,   206,
       0,   515,     0,     0,     0,     0,   207,   208,   209,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
     176,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,     0,     0,     0,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,     0,     0,     0,   205,
     206,     0,   517,     0,     0,     0,     0,   207,   208,   209,
       0,     0,   191,   192,     0,     0,     0,     0,     0,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   176,     0,     0,     0,     0,   523,     0,     0,   205,
     206,     0,     0,     0,     0,     0,     0,   207,   208,   209,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,   176,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,     0,   189,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,     0,     0,     0,     0,     0,   207,   208,
     209,     0,     0,     0,   192,     0,     0,     0,     0,     0,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   176,     0,     0,     0,     0,     0,     0,     0,
     205,   206,     0,     0,     0,     0,     0,     0,   207,   208,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   176,   186,
     187,   188,     0,   189,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   191,   192,     0,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,     0,   199,   200,
     201,   202,   203,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   206,     0,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,     0,     0,     0,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   206,     0,
       0,     0,     0,     0,     0,   207,   208,   209
  };

  /* YYCHECK.  */
  const short int
  YareParser::yycheck_[] =
  {
         5,    88,    88,    68,   138,   139,   147,   147,    84,     4,
      75,     6,    67,     5,     5,    20,   157,   157,     0,    74,
      75,    76,    77,    78,    79,    80,    81,     4,    83,     6,
      67,    85,     4,    88,     6,    90,   148,    74,    75,    76,
      77,    78,    79,    80,    81,     4,    83,     6,    12,   151,
      24,    88,   155,    90,    18,    19,    20,    21,    22,     4,
       4,     6,     6,    24,   151,   151,   138,   139,   140,   141,
     155,   143,    10,    11,    12,    16,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     4,    61,     6,   155,
      31,    65,   155,   155,    68,    36,   151,     4,   153,     6,
       4,     4,     6,     6,    65,   110,   150,    68,   155,   155,
     165,   116,   155,   155,   151,   155,   153,   155,    85,   155,
     155,   155,    63,   155,   155,    66,   155,   155,   155,    70,
      71,    72,   155,   155,   155,   155,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   155,   155,
       7,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   155,   155,   106,   155,   172,   142,   143,
     144,   155,   155,   139,   115,   155,   117,   155,   119,   153,
     154,   122,   143,   144,   125,   126,   127,   161,   162,   163,
     155,   139,   153,   154,   156,   155,   165,   155,   155,   155,
     161,   162,   163,   155,     5,   210,    34,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   156,
       5,   150,     5,   150,     5,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   156,   205,   206,   207,   208,   209,   152,
     152,   152,   152,   152,   152,   152,   152,   150,   150,   150,
     150,   150,   150,   150,    24,   150,   150,   150,   229,    24,
     150,   150,   125,   155,   155,     4,   150,   155,    -1,   155,
     155,    24,   155,   155,   155,   155,   155,   155,   155,   250,
     155,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     150,    61,    62,    63,   150,    65,   150,   150,    68,   156,
      65,   156,   151,    68,   275,   155,   277,   278,   156,   156,
     156,   156,    65,   156,    24,    68,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   150,   156,   150,   299,   300,
     301,   302,   150,   304,   305,   306,   307,   308,   309,   310,
     311,    51,    52,   150,   150,   156,   150,    57,    58,    -1,
     150,    61,   150,   150,   150,    65,   126,   127,    68,   150,
     150,   150,   150,   150,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   150,   411,    -1,    -1,   144,
      -1,    -1,   417,   153,   154,    -1,    -1,    -1,   153,   154,
      -1,   161,   162,   163,   164,    -1,   161,   162,   163,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,
     391,    -1,   393,   394,   395,    -1,    -1,    -1,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   413,   153,   154,   416,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,    -1,     3,     4,     5,     6,     7,
      -1,   516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   527,   464,    -1,    -1,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,   478,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    89,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    -1,   120,   121,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
     148,    -1,   150,    -1,    -1,   153,   154,   155,    -1,    -1,
      -1,   159,   160,   161,   162,   163,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      87,    -1,    89,    -1,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
      -1,    -1,    -1,   120,   121,   122,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   139,     3,     4,     5,     6,     7,    -1,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,   159,   160,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
     120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
       3,     4,     5,     6,     7,    -1,    -1,   147,   148,    -1,
     150,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,   159,
     160,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,    -1,    89,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    -1,    -1,   120,   121,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   148,    -1,   150,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,   159,   160,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    -1,    -1,    -1,   120,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   148,   149,   150,    -1,    -1,    -1,    -1,   155,
      -1,    -1,    -1,   159,   160,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      89,    -1,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,    -1,    -1,
      -1,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,     3,     4,     5,     6,     7,    -1,    -1,    -1,   148,
     149,   150,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
     159,   160,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    86,    87,    -1,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,    -1,    43,    44,   120,   121,
     122,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    69,    70,    -1,    -1,   148,    -1,   150,    -1,
      -1,    -1,    -1,   155,    -1,    -1,    -1,   159,   160,    86,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,    -1,   121,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    -1,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    69,
      70,    -1,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,   154,   155,    69,    70,    -1,   159,
     160,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,    43,    44,    -1,   121,   122,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,   155,    -1,    -1,    -1,   159,   160,    86,     3,
       4,     5,     6,     7,    24,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,    -1,
      -1,    51,    -1,   121,   122,    -1,    -1,    -1,    58,    43,
      44,    61,    -1,    -1,    -1,    65,    50,    -1,    68,    -1,
      -1,   139,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,   155,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,    -1,    -1,    -1,    -1,   121,   122,    -1,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,   153,   154,   139,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,    -1,    -1,   159,   160,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    88,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    24,    -1,    -1,    -1,    -1,   150,    -1,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    24,    -1,    -1,    -1,    -1,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    24,    -1,    -1,    -1,    -1,   150,
      -1,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
     150,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    24,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    24,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    24,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,
      -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      24,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,   154,    -1,   156,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   153,   154,    -1,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   153,   154,    -1,   156,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,    -1,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,   154,    -1,   156,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    24,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    24,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    24,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,
      -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    24,    -1,    -1,    -1,    -1,   150,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    24,    -1,    -1,    -1,    -1,   150,    -1,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,    24,    -1,    -1,    -1,    -1,   150,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,    24,    -1,    -1,    -1,    -1,   150,
      -1,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
     150,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,    24,    -1,    -1,    -1,    -1,
     150,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    24,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    -1,    -1,    -1,    -1,
      -1,   150,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    24,    -1,    -1,    -1,
      -1,   150,    -1,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    -1,    -1,    -1,
      -1,    -1,   150,    -1,    -1,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    24,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,   156,
      -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
     156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    24,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,
      -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
     154,    -1,   156,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,    24,    -1,    -1,    -1,    -1,   150,    -1,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    24,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,   134,   135,   136,   137,   138,    -1,   140,   141,
     142,   143,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,   163
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  YareParser::yystos_[] =
  {
         0,   167,   168,     0,    84,   169,    85,     3,     4,     5,
       6,     7,    24,    30,    31,    33,    34,    36,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    60,    69,    70,    86,    87,    89,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   120,   121,   122,   139,   147,   148,   150,
     155,   159,   160,   170,   172,   148,    67,    74,    75,    76,
      77,    78,    79,    80,    81,    83,    88,    90,   151,   153,
     165,    67,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    88,    90,   151,   153,   147,   157,   151,   155,   170,
     171,   155,     4,     6,     7,   155,   172,   155,   155,   155,
     170,   150,   155,   155,   155,   155,   155,   155,     5,   155,
       5,   155,   155,   172,   155,   155,    85,     4,     6,   172,
       4,     6,     4,     6,     4,     6,     4,     6,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     172,   172,   171,   172,   172,   172,    24,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    61,    62,    63,    65,
      68,   126,   127,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   150,   153,   154,   161,   162,   163,
     171,     4,     6,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   117,   118,   119,   154,   172,   139,
     138,   139,     4,     6,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   117,   118,   119,   154,   172,
     139,    10,    11,    12,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   172,   138,   139,   140,   141,   143,
     156,    32,   170,     7,   147,   157,   172,    24,   139,   170,
     172,     5,   172,    34,   172,   156,     5,   172,   172,   172,
     150,     5,   150,     5,   156,     4,     6,     4,     6,    88,
     151,    88,   151,    88,   152,   152,   152,   152,   152,   152,
     152,   152,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   149,   156,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   149,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   172,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   172,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   158,   150,   150,   150,   150,   150,   156,
     172,   156,   172,    37,   156,   156,   155,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   172,   172,
     172,   172,     4,     6,   172,   172,   172,   172,   172,   172,
     172,   172,   156,   156,   152,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   164,   172,   172,   156,   172,   172,
     172,   156,   156,   156,   156,   156,   156,   156,   151,   150,
     158,   170,   172,   150,   150,   172,   170,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   172,   172,   156,   156,   156,   156,
     156,   150,   150,   172,   152,   156,   125,   156,   150,   150,
     150,   150,   150,   150,     4,   150,   170,   156,   170
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
     385,   386,   387,   388,   389,   390,   391,   392,    43,    45,
      42,    47,    37,    94,   393,   394,   395,    46,   123,   125,
      59,    61,    44,    60,    63,    40,    41,    91,    93,    33,
     126,    62,    38,   124,    58,    64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  YareParser::yyr1_[] =
  {
         0,   166,   167,   168,   168,   169,   169,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   171,   171,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     2
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
  "ABS", "FACTORIAL", "SUMATORIA", "SQRT", "ACOS", "ACOSH", "ASIN",
  "ASINH", "ATAN", "ATANH", "CEIL", "COS", "COSH", "EXP", "FLOOR", "LN",
  "SIN", "SINH", "TAN", "SEC", "CSC", "TANH", "FACE_HAPPY", "FACE_SAD",
  "FACE_NO", "PUSH", "POP", "STACK_SIZE", "TERNARY", "IFX", "ELSE", "OR",
  "AND", "SHIFTRIGHT", "SHIFTLEFT", "ANDBITS", "ORBITS", "LT", "GT", "NE",
  "EQ", "LE", "GE", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'",
  "EXPR_ELEVADO", "NEGACION", "UMINUS", "'.'", "'{'", "'}'", "';'", "'='",
  "','", "'<'", "'?'", "'('", "')'", "'['", "']'", "'!'", "'~'", "'>'",
  "'&'", "'|'", "':'", "'@'", "$accept", "program", "funciones", "cuerpo",
  "stmt", "stmt_list", "expr", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const YareParser::rhs_number_type
  YareParser::yyrhs_[] =
  {
       167,     0,    -1,   168,   169,   147,    -1,   168,    84,    85,
     148,   171,   149,    -1,    -1,   169,   170,    -1,    -1,   150,
      -1,     4,   151,   172,   150,    -1,     4,    88,   172,   150,
      -1,    89,   172,    88,     4,    -1,    89,   172,    88,     6,
      -1,    91,     4,   152,   172,   150,    -1,    91,     6,   152,
     172,   150,    -1,     4,   153,   139,   172,    -1,     6,   153,
     139,   172,    -1,     4,    90,   172,    -1,     6,    90,   172,
      -1,    87,     4,   151,   172,   150,    -1,    87,     4,    88,
     172,   150,    -1,     6,   151,   172,   150,    -1,     6,    88,
     172,   150,    -1,    87,     6,   151,   172,   150,    -1,    87,
       6,    88,   172,   150,    -1,     4,   151,   154,   150,    -1,
       6,   151,   154,   150,    -1,     4,    67,     4,   150,    -1,
       6,    67,     4,   150,    -1,     4,    67,     6,   150,    -1,
       6,    67,     6,   150,    -1,   172,   150,    -1,     4,   151,
     117,   150,    -1,     4,   151,   118,   150,    -1,     4,   151,
     119,   150,    -1,     6,   151,   117,   150,    -1,     6,   151,
     118,   150,    -1,     6,   151,   119,   150,    -1,    46,   155,
     172,   156,   150,    -1,    45,   155,   172,   156,   150,    -1,
      47,   155,   172,   156,   150,    -1,   148,   171,   149,    -1,
      31,   171,    32,    -1,    48,   155,     5,   156,   150,    -1,
      48,     5,   150,    -1,    49,   155,     5,   156,   150,    -1,
      49,     5,   150,    -1,    34,   155,   172,   156,   170,    -1,
      34,   172,   170,    -1,    40,   170,    34,   155,   172,   156,
     150,    -1,    36,   155,   172,    37,   172,   152,     4,   156,
     170,    -1,    41,   150,    -1,    38,   155,     5,   156,   150,
      -1,    39,   155,   172,   156,   150,    -1,    42,   155,   172,
     156,   170,    -1,    42,   155,   172,   156,   170,   125,   170,
      -1,     4,    77,   172,   150,    -1,     6,    77,   172,   150,
      -1,    93,     4,   152,   172,   150,    -1,    93,     6,   152,
     172,   150,    -1,    92,     4,   152,   172,   150,    -1,    92,
       6,   152,   172,   150,    -1,    94,     4,   152,   172,   150,
      -1,    94,     6,   152,   172,   150,    -1,     4,    78,   172,
      -1,     6,    78,   172,    -1,     4,    76,   172,    -1,     6,
      76,   172,    -1,     4,    79,   172,    -1,     6,    79,   172,
      -1,     4,    74,   172,    -1,     6,    74,   172,    -1,     4,
      75,   172,    -1,     6,    75,   172,    -1,     4,    80,   172,
      -1,     6,    80,   172,    -1,     4,    81,   172,    -1,     6,
      81,   172,    -1,     4,    83,   172,    -1,     6,    83,   172,
      -1,   120,   172,    -1,     7,   157,   172,   158,   151,   172,
     150,    -1,    33,   155,     7,   156,   150,    -1,     7,   147,
      10,   155,   172,   156,   150,    -1,     7,   147,    11,   155,
     172,   156,   150,    -1,     7,   147,    14,   155,   172,   156,
     150,    -1,     7,   147,    15,   155,   172,   156,   150,    -1,
       7,   147,    16,   155,   172,   156,   150,    -1,     7,   147,
      17,   155,   156,   150,    -1,     7,   147,    23,   155,   156,
     150,    -1,    24,   151,   138,   150,    -1,    24,   151,   139,
     150,    -1,    24,   151,   140,   150,    -1,    24,   151,   141,
     150,    -1,    24,   151,   143,   150,    -1,    30,   155,   156,
      -1,    -1,   170,    -1,   171,   170,    -1,     3,    -1,     6,
      -1,     5,    -1,     4,    -1,     7,   157,   172,   158,    -1,
       7,   147,    12,   155,   156,    -1,     7,   147,    12,    -1,
       7,   147,    18,   155,   156,    -1,     7,   147,    19,   155,
     156,    -1,     7,   147,    21,   155,   156,    -1,     7,   147,
      20,   155,   156,    -1,     7,   147,    22,   155,   156,    -1,
     139,   172,    -1,   159,   172,    -1,   160,   172,    -1,    60,
     172,    -1,   172,   138,   172,    -1,   172,   139,   172,    -1,
     172,    57,   172,    -1,   172,    52,   172,    -1,   172,   140,
     172,    -1,   172,    58,   172,    -1,   172,   141,   172,    -1,
     172,    51,   172,    -1,   172,   153,   172,    -1,   172,    55,
     172,    -1,   172,    63,   172,    -1,   172,   161,   172,    -1,
     172,    53,   172,    -1,   172,    62,   172,    -1,   172,   143,
     172,    -1,   172,   144,   172,    -1,   172,   142,   172,    -1,
     172,    61,   172,    -1,   172,   137,   172,    -1,   172,    54,
     172,    -1,   172,   136,   172,    -1,   172,    56,   172,    -1,
     172,   134,   172,    -1,   172,   135,   172,    -1,   172,    59,
     172,    -1,   172,   127,   172,    -1,   172,   126,   172,    -1,
     172,   162,   172,    -1,   172,   163,   172,    -1,   155,   172,
     156,    -1,   172,    24,   172,    -1,   172,   154,   172,   164,
     172,    -1,    43,   155,   156,    -1,    44,   155,     5,   156,
      -1,    50,   155,   156,    -1,   121,    -1,   122,    -1,    95,
     155,   172,   156,    -1,    98,   155,   172,   156,    -1,    99,
     155,   172,   156,    -1,   100,   155,   172,   156,    -1,   101,
     155,   172,   156,    -1,   102,   155,   172,   156,    -1,   103,
     155,   172,   156,    -1,   104,   155,   172,   156,    -1,   105,
     155,   172,   156,    -1,   106,   155,   172,   156,    -1,   107,
     155,   172,   156,    -1,   108,   155,   172,   156,    -1,   109,
     155,   172,   156,    -1,   110,   155,   172,   156,    -1,   111,
     155,   172,   156,    -1,   112,   155,   172,   156,    -1,   113,
     155,   172,   156,    -1,   114,   155,   172,   156,    -1,   115,
     155,   172,   156,    -1,   116,   155,   172,   156,    -1,    97,
     155,   172,   152,   172,   156,    -1,    96,   155,   172,   156,
      -1,    69,   155,     6,   156,    -1,    69,   155,     4,   156,
      -1,    70,   155,     6,   156,    -1,    70,   155,     4,   156,
      -1,   172,    68,   172,    -1,   172,    65,   172,    -1,     4,
     165,   139,    -1,     4,   165,   138,    -1,    86,    85,    -1
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
     744,   749,   754,   759,   764,   769,   774,   779,   784,   789,
     794,   799,   806,   811,   816,   821,   826,   831,   835,   839,
     843,   847
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  YareParser::yyrline_[] =
  {
         0,   303,   303,   309,   312,   316,   321,   325,   328,   331,
     334,   337,   340,   343,   346,   349,   352,   355,   358,   361,
     364,   367,   370,   373,   376,   379,   382,   385,   388,   391,
     394,   397,   398,   399,   400,   401,   402,   403,   406,   409,
     412,   415,   418,   421,   424,   427,   430,   433,   436,   439,
     442,   445,   448,   451,   454,   457,   460,   463,   466,   469,
     472,   475,   478,   481,   484,   487,   490,   493,   496,   499,
     502,   505,   508,   511,   514,   517,   520,   523,   526,   529,
     532,   535,   538,   541,   544,   547,   550,   553,   556,   559,
     562,   565,   568,   571,   574,   577,   581,   584,   590,   593,
     601,   604,   607,   610,   613,   616,   619,   622,   625,   628,
     631,   634,   637,   640,   643,   646,   649,   652,   655,   658,
     661,   664,   667,   670,   673,   676,   679,   682,   685,   688,
     691,   694,   697,   700,   703,   706,   709,   712,   715,   718,
     721,   724,   727,   730,   733,   747,   750,   753,   756,   759,
     762,   765,   768,   771,   774,   777,   780,   783,   787,   790,
     793,   796,   799,   802,   805,   808,   811,   814,   817,   820,
     823,   826,   829,   832,   835,   838,   841,   844,   847,   850,
     853,   856
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
       2,     2,     2,   159,     2,     2,     2,   142,   162,     2,
     155,   156,   140,   138,   152,   139,   147,   141,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   164,   150,
     153,   151,   161,   154,   165,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   157,     2,   158,   143,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   148,   163,   149,   160,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   144,   145,   146
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int YareParser::yyeof_ = 0;
  const int YareParser::yylast_ = 7217;
  const int YareParser::yynnts_ = 7;
  const int YareParser::yyempty_ = -2;
  const int YareParser::yyfinal_ = 3;
  const int YareParser::yyterror_ = 1;
  const int YareParser::yyerrcode_ = 256;
  const int YareParser::yyntokens_ = 166;

  const unsigned int YareParser::yyuser_token_number_max_ = 395;
  const YareParser::token_number_type YareParser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 9 "yare.y"
} // YL

/* Line 1136 of lalr1.cc  */
#line 4315 "yare.tab.c"


/* Line 1138 of lalr1.cc  */
#line 860 "yare.y"


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

				case YL::YareParser::token::ACOSH:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						try {
							return MathFunctions::math_acosh(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'acosh'" << std::endl;
							exit(EXIT_FAILURE);
						}
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

				case YL::YareParser::token::ASINH:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return MathFunctions::math_asinh(run(p->opr.op[0]));
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

				case YL::YareParser::token::SEC:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						try {
							return MathFunctions::math_sec(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'sec'" << std::endl;
							exit(EXIT_FAILURE);

						}
						
					}
					else
						return 0.0L;

				case YL::YareParser::token::CSC:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						try {
							return MathFunctions::math_csc(run(p->opr.op[0]));
						} catch(NanOrInfinity ex) {
							std::cout << "Argumento fuera de la función para la función 'csc'" << std::endl;
							exit(EXIT_FAILURE);
						}
					}
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
							std::cout << "Argumento fuera de la función para la función 'atan'" << std::endl;
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

