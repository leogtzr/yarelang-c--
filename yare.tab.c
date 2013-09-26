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
#line 298 "yare.y"
    {
	exit(EXIT_SUCCESS);
}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 304 "yare.y"
    {
		push_l_proc(&procs, (yysemantic_stack_[(6) - (3)].nameFunction), (yysemantic_stack_[(6) - (5)].nPtr));
	}
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 307 "yare.y"
    {;}
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 311 "yare.y"
    { 
		run((yysemantic_stack_[(2) - (2)].nPtr));		
		freeNode((yysemantic_stack_[(2) - (2)].nPtr));

	}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 316 "yare.y"
    {;}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 320 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, NULL, NULL); 
	}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 323 "yare.y"
    { 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 326 "yare.y"
    {		// x to 1 + 2; 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 329 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (4)].sIndex)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 332 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (4)].identificador)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 335 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 338 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 341 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 344 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 347 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 350 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 353 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 356 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 359 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 362 "yare.y"
    { 	// :x: to 1 + 2;
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 365 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 368 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 371 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, id((yysemantic_stack_[(4) - (1)].sIndex)));
	}
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 374 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, idS((yysemantic_stack_[(4) - (1)].identificador)));
	}
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 377 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 380 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 383 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 386 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 389 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(2) - (1)].nPtr); 
	}
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 392 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 393 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 394 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 395 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 396 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 397 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 398 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINTN, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 401 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRASCII, 1, (yysemantic_stack_[(5) - (3)].nPtr));
	}
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 404 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINT, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 407 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 410 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 413 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 416 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 419 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTSN, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 422 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTSN, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 425 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 428 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(3) - (2)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 431 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DO_WHILE, 2, (yysemantic_stack_[(7) - (2)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 434 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FOREACH, 4, (yysemantic_stack_[(9) - (3)].nPtr), (yysemantic_stack_[(9) - (5)].nPtr), id((yysemantic_stack_[(9) - (7)].sIndex)), (yysemantic_stack_[(9) - (9)].nPtr));
	}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 437 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::BREAK, 0);
	}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 440 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SYSTEM, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));	
	}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 443 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXIT, 1, (yysemantic_stack_[(5) - (3)].nPtr));		
	}
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 446 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr));
	}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 449 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 3, (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr), (yysemantic_stack_[(7) - (7)].nPtr)); 
	}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 452 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 455 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 458 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 461 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 464 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 467 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 470 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 473 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 476 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 479 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 482 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 485 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 488 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 491 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 494 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 497 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 500 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 503 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 506 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 509 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 512 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 515 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 518 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 521 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 524 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUSH, 1, (yysemantic_stack_[(2) - (2)].nPtr));	
	}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 527 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_ASSIGN, 3, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (6)].nPtr));
	}
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 530 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_C, 1, idA((yysemantic_stack_[(5) - (3)].identificador)));
	}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 533 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_PUT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 536 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_PUTFRONT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 539 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SORT, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 542 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_DEL, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 545 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_FILL, 2, idA((yysemantic_stack_[(7) - (1)].identificador)), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 548 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_CLEAR, 1, idA((yysemantic_stack_[(6) - (1)].identificador)));
	}
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 551 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_REVERSE, 1, idA((yysemantic_stack_[(6) - (1)].identificador)));
	}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 554 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_ADD, 0); 
	}
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 557 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_SUB, 0); 
	}
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 560 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_MUL, 0); 
	}
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 563 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_DIV, 0); 
	}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 566 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OPVAR_POW, 0); 
	}
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 569 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CLEARVARS, 0);
	}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 572 "yare.y"
    {;}
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 576 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(1) - (1)].nPtr); 
	}
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 579 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, (yysemantic_stack_[(2) - (1)].nPtr), (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 585 "yare.y"
    {
		(yyval.nPtr) = con((yysemantic_stack_[(1) - (1)].valnum));
	}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 588 "yare.y"
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
#line 596 "yare.y"
    {
		(yyval.nPtr) = conStr((yysemantic_stack_[(1) - (1)].cadena), typeCadena);
	}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 599 "yare.y"
    { 
		(yyval.nPtr) = id((yysemantic_stack_[(1) - (1)].sIndex)); 
	}
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 602 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SHIT, 2, idA((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 605 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 608 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA((yysemantic_stack_[(3) - (1)].identificador)));
	}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 611 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_MIN, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 614 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_MAX, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 617 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_TAIL, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 620 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_HEAD, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 623 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ARRAY_AVERAGE, 1, idA((yysemantic_stack_[(5) - (1)].identificador)));
	}
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 626 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::UMINUS, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 629 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 632 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 635 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 638 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 641 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 644 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 647 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 650 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 653 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 656 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 659 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 662 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 665 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 668 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 671 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 674 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 677 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 680 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 683 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 686 "yare.y"
    { 
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 689 "yare.y"
    {
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 692 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 695 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 698 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 701 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 704 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 707 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 710 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 713 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::AND, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 716 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OR, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 719 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ANDBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 722 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ORBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 725 "yare.y"
    {
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr);
	}
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 728 "yare.y"
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
#line 742 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TERNARY, 3, (yysemantic_stack_[(5) - (1)].nPtr), (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr));
	}
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 745 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READ, 0);
	}
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 748 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READP, 1, conStr((yysemantic_stack_[(4) - (3)].cadena), typeCadena));
	}
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 751 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RAND, 0);
	}
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 754 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::POP, 0);
	}
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 757 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::STACK_SIZE, 0);
	}
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 760 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ABS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 763 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SQRT, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 766 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ACOS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 769 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ASIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 772 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 775 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CEIL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 778 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 781 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COSH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 784 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXP, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 787 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FLOOR, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 790 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::LN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 793 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 796 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SINH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 799 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 802 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 805 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SUMATORIA, 2, (yysemantic_stack_[(6) - (3)].nPtr), (yysemantic_stack_[(6) - (5)].nPtr));	
	}
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 808 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FACTORIAL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 811 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 814 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 817 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 820 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 823 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::XOROP, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 826 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RANGE_RANDOM, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 829 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 832 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 176:

/* Line 690 of lalr1.cc  */
#line 835 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CALL, 1, idS((yysemantic_stack_[(2) - (2)].nameFunction)));
	}
    break;



/* Line 690 of lalr1.cc  */
#line 2073 "yare.tab.c"
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
  const short int YareParser::yypact_ninf_ = -140;
  const short int
  YareParser::yypact_[] =
  {
      -140,     6,   -68,  -140,   -55,   762,  -126,  -140,   -56,  -140,
     -38,  -139,  -111,  -103,  1290,   -97,  1600,   -92,   -64,   -63,
    1290,   -43,   -37,   -35,   -34,   -33,   -29,   -28,     2,     3,
     -27,  1675,   -26,   -13,    54,    22,  1675,    27,    42,    45,
      50,   -12,     5,    10,    11,    12,    14,    16,    21,    29,
      30,    34,    35,    36,    37,    38,    44,    63,  1675,  -140,
    -140,  1675,  -140,  1290,  -140,  1675,  1675,  1675,  -140,  1742,
    1290,    76,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,
    1675,  1675,  1675,  1360,   -22,  -124,    77,  1675,  1675,  1675,
    1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1447,    49,
      56,  1675,   -39,    41,  -140,   894,   149,    55,  -140,  -138,
    1675,   474,  1675,   188,  1675,   180,  -140,  1675,    65,   212,
    1675,  1675,  1675,    73,   242,   108,   249,   104,   261,    87,
      99,  -140,   -87,   -86,  1782,   109,   110,   111,   112,   113,
     114,   115,   116,  1675,  1675,  1675,  1675,  1675,  1675,  1675,
    1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,
    6150,   261,  1026,  1898,   261,   261,  1675,  1675,  1675,  1675,
    1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,
    1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,  1675,
    1675,  1675,  1675,  1675,  -140,  1675,  1675,  1675,  1675,  1675,
    1158,   119,   120,  6150,  6150,  6150,  1938,  6150,  6150,  6150,
    6150,  6150,  2054,  6150,   121,   122,   124,   125,  2094,  1675,
    -140,  -140,   126,   128,  6150,  6150,  6150,  2210,  6150,  6150,
    6150,  6150,  6150,  2250,  6150,   129,   130,   131,   132,  2366,
    1675,   133,   134,   136,   137,   138,   139,   140,   142,   144,
     154,   158,   160,   161,  2406,   135,   168,   169,   170,   171,
    -140,  -140,  -140,   127,    43,  1675,  2522,  1522,  1675,  -140,
    2562,   166,  2678,   172,  2718,  -140,   173,  2834,  2874,  2990,
    -140,   174,  -140,   176,  -140,   179,   182,   183,   185,  1675,
    1675,  1675,  1675,   103,  1675,  1675,  1675,  1675,  1675,  1675,
    1675,  1675,  3030,  3146,  3186,  3302,  3342,  3458,  3498,  3614,
    3654,  3770,  3810,  3926,  3966,  4082,  4122,  4238,  4278,  -140,
    -140,  6150,   267,  6458,  6442,  6442,  6442,  6442,  6458,   267,
    6442,    20,  6442,  6442,  6150,  6150,  6266,  6416,  6442,  6442,
    6442,  6442,  6458,  6458,   267,   267,    20,    33,   261,  6150,
     244,  6150,  6150,  6150,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  6306,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  6306,  1675,  1675,   186,  1675,  1675,
    1675,   187,   189,   190,   195,   204,   205,   206,   177,  -140,
    -140,  -140,  -140,  -140,   194,  4394,   630,  4434,  1675,   213,
     214,  1675,  1290,  -140,   215,   216,   217,   218,   219,  -140,
    -140,  -140,  -140,  4550,  4590,  4706,  4746,  -140,  -140,  4862,
    4902,  5018,  5058,  5174,  5214,  5330,  5370,  -140,  -140,  1675,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  1675,  5486,  5526,  -140,  5642,  5682,
    5798,   222,  -140,  -140,  -140,  -140,  -140,   223,  1675,  -140,
    -140,  -140,  5838,  -140,  -140,  5954,   159,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  5994,  6150,   224,   225,   226,   227,
     239,  -140,  -140,  6110,   277,   240,  1290,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,   235,  -140,  -140,  1290,  -140
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
     150,     0,     2,    95,     7,     0,     0,     0,     5,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,   101,    99,     0,
       0,    95,     0,     0,     0,     0,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,   176,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,   110,     0,     0,   111,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    71,    65,     0,    63,    67,    73,
      75,    77,     0,    16,     0,     0,     0,     0,     0,     0,
     175,   174,     0,     0,    70,    72,    66,     0,    64,    68,
      74,    76,    78,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    41,    97,     0,     0,     0,     0,     0,     0,    47,
       0,     0,     0,     0,     0,   146,     0,     0,     0,     0,
      43,     0,    45,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
     143,   144,   121,   117,   126,   133,   123,   135,   116,   119,
     138,   131,   127,   124,   173,   172,   140,   139,   136,   137,
     134,   132,   114,   115,   118,   120,   130,   128,   129,   122,
       0,   125,   141,   142,     3,    26,    28,    55,     9,    31,
      32,    33,    24,     8,    14,    27,    29,    56,    21,    34,
      35,    36,    25,    20,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,    89,
      90,    91,    92,    93,     0,     0,   143,   115,     0,     0,
       0,     0,    95,   147,     0,     0,     0,     0,     0,   169,
     168,   171,   170,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,   151,   167,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,     0,   103,     0,     0,
       0,     0,   105,   106,   108,   107,   109,     0,     0,    81,
     102,    46,     0,    51,    52,     0,    53,    38,    37,    39,
      42,    44,    19,    18,    23,    22,    12,    13,    59,    60,
      57,    58,    61,    62,     0,   145,     0,     0,     0,     0,
       0,    87,    88,     0,     0,     0,    95,   166,    82,    83,
      84,    85,    86,    80,     0,    48,    54,    95,    49
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  YareParser::yypgoto_[] =
  {
      -140,  -140,  -140,  -140,    -5,   -58,    53
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  YareParser::yydefgoto_[] =
  {
        -1,     1,     2,     5,   104,   105,    69
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char YareParser::yytable_ninf_ = -111;
  const short int
  YareParser::yytable_[] =
  {
        68,   289,   291,   100,   264,   162,     3,   123,   125,   220,
     221,    71,   200,   101,   265,   115,     4,    70,    72,    73,
      74,    75,    76,    77,    78,    79,   132,    80,   133,    86,
       6,   135,    81,   136,    82,   102,    87,    88,    89,    90,
      91,    92,    93,    94,   166,    95,   137,   103,   138,   139,
      96,   140,    97,   106,   141,   243,   142,   166,   112,   290,
     292,   248,   249,   250,   251,   252,   241,   242,   243,   111,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     201,   222,   202,   223,   128,   179,   113,   114,   180,   134,
      83,   285,    84,   286,   255,   256,   257,   258,   179,   259,
     262,   180,   116,   287,    85,   288,   269,   417,    98,   418,
      99,   160,   219,   117,   161,   118,   119,   120,   163,   164,
     165,   121,   122,   127,   129,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   218,   130,   143,   131,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   239,   124,   126,   254,   144,   263,   262,   192,   193,
     145,   146,   147,   266,   148,   270,   149,   272,   195,   196,
     274,   150,   193,   277,   278,   279,   197,   198,   199,   151,
     152,   195,   196,   240,   153,   154,   155,   156,   157,   197,
     198,   199,   260,   271,   158,   262,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   159,   273,    85,   275,   276,   280,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   281,   349,   350,
     351,   352,   353,   282,   283,   284,   294,   295,   296,   297,
     298,   299,   300,   301,   355,   356,   359,   360,   166,   361,
     362,   365,   364,   366,   369,   370,   371,   372,   394,   496,
     389,   504,     0,   375,   376,   166,   377,   378,   379,   380,
     381,   166,   382,   374,   383,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   384,   176,   177,   178,   385,   179,
     386,   387,   180,   390,   391,   392,   393,   399,   395,     0,
     321,   397,   401,   458,   403,   407,   179,   408,   176,   180,
     409,     0,   179,   410,   411,   180,   412,   447,   451,   459,
     452,   453,   413,   414,   415,   416,   454,   419,   420,   421,
     422,   423,   424,   425,   426,   455,   456,   457,   463,   464,
     467,   468,   469,   470,   471,   181,   182,   491,   492,   498,
     499,   500,   501,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   502,   505,   507,     0,     0,     0,
       0,   461,   195,   196,     0,     0,     0,   466,     0,     0,
     197,   198,   199,   444,   191,   192,   193,     0,     0,   195,
     196,     0,     0,     0,     0,   195,   196,   197,   198,   199,
       0,     0,     0,   197,   198,   199,     0,     0,   445,   446,
       0,   448,   449,   450,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   462,     0,     0,   465,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      10,    11,   484,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,   485,   267,     0,
       0,     0,   508,     0,    13,    14,     0,    15,    16,     0,
      17,   493,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,   167,   168,   169,   170,   171,
     172,   173,   174,   175,    31,   176,   177,   178,     0,   179,
       0,     0,   180,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,    36,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
      59,    60,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   268,   189,
     190,   191,   192,   193,     0,     0,     0,    63,     0,    64,
       0,     0,   195,   196,    65,     0,     0,     0,    66,    67,
     197,   198,   199,     7,     8,     9,    10,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
      13,    14,   -95,    15,    16,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,    36,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    58,    59,    60,     0,     0,
     -95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     7,     8,     9,    10,    11,
       0,     0,   -95,    63,   -95,    64,     0,     0,     0,     0,
      65,     0,     0,     0,    66,    67,    12,     0,     0,     0,
       0,     0,    13,    14,     0,    15,    16,     0,    17,     0,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    35,
       0,    36,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     7,     8,     9,
      10,    11,     0,     0,    62,    63,     0,    64,     0,     0,
       0,     0,    65,     0,     0,     0,    66,    67,    12,     0,
       0,     0,     0,     0,    13,    14,   261,    15,    16,     0,
      17,     0,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,    36,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,     7,
       8,     9,    10,    11,     0,     0,     0,    63,     0,    64,
       0,     0,     0,     0,    65,     0,     0,     0,    66,    67,
      12,     0,     0,     0,     0,     0,    13,    14,     0,    15,
      16,     0,    17,     0,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,    36,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     7,     8,     9,    10,    11,     0,     0,     0,    63,
     319,    64,     0,     0,     0,     0,    65,     0,     0,     0,
      66,    67,    12,     0,     0,     0,     0,     0,    13,    14,
       0,    15,    16,     0,    17,     0,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,     0,    36,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     7,     8,     9,    10,    11,     0,     0,
       0,    63,   354,    64,     0,     0,     0,     0,    65,     0,
       0,     0,    66,    67,    12,     0,     0,     0,     0,     0,
      13,    14,     0,    15,    16,     0,    17,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    32,
      33,     0,     0,     7,   107,     9,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,    36,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,    23,    24,    58,    59,    60,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,    61,     0,     0,     0,     0,    32,
      33,     0,     0,    63,     0,    64,     0,     0,     0,     0,
      65,     0,     0,     0,    66,    67,    34,     0,     0,     0,
       7,   107,     9,   108,   109,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   214,   215,   216,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,     0,     0,    61,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,   217,
      65,     0,     0,     0,    66,    67,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     7,   107,     9,   108,   109,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   235,
     236,   237,     0,    59,    60,    23,    24,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    32,    33,     0,     0,     0,   238,    65,     0,     0,
       0,    66,    67,     7,   107,     9,   108,   109,    34,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,    59,    60,
       0,     0,     0,    23,    24,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,    61,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,   102,    32,
      33,     0,    65,     0,     0,     0,    66,    67,     7,   107,
       9,   108,   109,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     0,    59,    60,    23,    24,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,     0,     0,
     110,     0,     0,     0,    66,    67,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,   166,     0,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,    59,    60,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   166,   179,     0,    61,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,    66,
      67,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,     0,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,     0,
     293,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,   194,     0,     0,
     195,   196,     0,     0,     0,     0,     0,     0,   197,   198,
     199,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   166,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,     0,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,   166,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,     0,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   320,
       0,     0,     0,     0,   197,   198,   199,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   166,     0,
       0,     0,     0,   357,     0,     0,   195,   196,     0,     0,
       0,     0,     0,     0,   197,   198,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   166,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,     0,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,   358,
       0,     0,   195,   196,     0,     0,     0,     0,     0,     0,
     197,   198,   199,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   166,     0,     0,     0,     0,   363,
       0,     0,   195,   196,     0,     0,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   166,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,     0,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,   367,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     166,     0,     0,     0,     0,   368,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     166,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
       0,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,   373,     0,     0,   195,   196,     0,     0,     0,     0,
       0,     0,   197,   198,   199,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   166,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,     0,   388,
       0,     0,   197,   198,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   166,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,   398,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,     0,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   396,     0,     0,     0,     0,   197,   198,
     199,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   166,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,     0,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,   166,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,     0,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   400,
       0,     0,     0,     0,   197,   198,   199,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   166,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   402,
       0,     0,     0,     0,   197,   198,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   166,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,     0,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,   195,   196,     0,   404,     0,     0,     0,     0,
     197,   198,   199,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   166,     0,     0,     0,     0,     0,
       0,     0,   195,   196,     0,   405,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   166,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,     0,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,     0,     0,     0,   195,   196,
       0,   406,     0,     0,     0,     0,   197,   198,   199,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     166,     0,     0,     0,     0,     0,     0,     0,   195,   196,
       0,   427,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     166,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
       0,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,   428,     0,     0,
       0,     0,   197,   198,   199,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   166,     0,     0,     0,
       0,     0,     0,   429,   195,   196,     0,     0,     0,     0,
       0,     0,   197,   198,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   166,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,     0,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   430,     0,     0,     0,     0,   197,   198,
     199,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   166,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   431,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,   166,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,     0,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   432,
       0,     0,     0,     0,   197,   198,   199,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   166,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   433,
       0,     0,     0,     0,   197,   198,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   166,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,     0,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,   195,   196,     0,   434,     0,     0,     0,     0,
     197,   198,   199,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   166,     0,     0,     0,     0,     0,
       0,     0,   195,   196,     0,   435,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   166,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,     0,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,     0,     0,     0,   195,   196,
       0,   436,     0,     0,     0,     0,   197,   198,   199,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     166,     0,     0,     0,     0,     0,     0,     0,   195,   196,
       0,   437,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     166,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
       0,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,   438,     0,     0,
       0,     0,   197,   198,   199,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   166,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,   439,     0,     0,
       0,     0,   197,   198,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   166,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,     0,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   440,     0,     0,     0,     0,   197,   198,
     199,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   166,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   441,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,   166,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,     0,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   442,
       0,     0,     0,     0,   197,   198,   199,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   166,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   443,
       0,     0,     0,     0,   197,   198,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   166,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,     0,  -110,  -110,  -110,     0,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,   195,   196,     0,     0,     0,   460,     0,     0,
     197,   198,   199,     0,     0,  -110,  -110,     0,     0,     0,
       0,     0,     0,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,   166,     0,     0,     0,     0,  -110,
       0,     0,   195,   196,     0,     0,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   166,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,     0,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,   472,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     166,     0,     0,     0,     0,   473,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     166,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
       0,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,   474,     0,     0,   195,   196,     0,     0,     0,     0,
       0,     0,   197,   198,   199,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   166,     0,     0,     0,
       0,   475,     0,     0,   195,   196,     0,     0,     0,     0,
       0,     0,   197,   198,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   166,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,     0,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,   476,     0,     0,
     195,   196,     0,     0,     0,     0,     0,     0,   197,   198,
     199,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   166,     0,     0,     0,     0,   477,     0,     0,
     195,   196,     0,     0,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,   166,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,     0,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,   478,     0,     0,   195,   196,     0,     0,
       0,     0,     0,     0,   197,   198,   199,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   166,     0,
       0,     0,     0,   479,     0,     0,   195,   196,     0,     0,
       0,     0,     0,     0,   197,   198,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   166,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,     0,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,   480,
       0,     0,   195,   196,     0,     0,     0,     0,     0,     0,
     197,   198,   199,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   166,     0,     0,     0,     0,   481,
       0,     0,   195,   196,     0,     0,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   166,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,     0,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,   482,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     166,     0,     0,     0,     0,   483,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     166,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
       0,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,   486,     0,     0,
       0,     0,   197,   198,   199,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   166,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,   487,     0,     0,
       0,     0,   197,   198,   199,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,   166,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,     0,   176,   177,   178,     0,   179,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   488,     0,     0,     0,     0,   197,   198,
     199,     0,     0,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   166,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   489,     0,     0,     0,     0,   197,   198,
     199,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,   166,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,     0,   176,
     177,   178,     0,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,     0,     0,
       0,     0,     0,     0,     0,     0,   195,   196,     0,   490,
       0,     0,     0,     0,   197,   198,   199,     0,     0,   181,
     182,     0,     0,     0,     0,     0,     0,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   166,     0,
       0,     0,     0,     0,     0,   494,   195,   196,     0,     0,
       0,     0,     0,     0,   197,   198,   199,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,   166,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   176,   177,   178,     0,   179,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,     0,     0,     0,     0,     0,     0,
       0,     0,   195,   196,     0,   495,     0,     0,     0,     0,
     197,   198,   199,     0,     0,   181,   182,     0,     0,     0,
       0,     0,     0,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   166,     0,     0,     0,     0,     0,
       0,     0,   195,   196,     0,   497,     0,     0,     0,     0,
     197,   198,   199,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,   166,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,   168,   169,   170,   171,   172,   173,   174,   175,
       0,   176,   177,   178,     0,   179,     0,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,     0,     0,     0,     0,   503,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     166,     0,     0,     0,     0,     0,     0,     0,   195,   196,
       0,     0,     0,     0,     0,     0,   197,   198,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
     166,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
       0,   179,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,     0,     0,
       0,     0,   197,   198,   199,     0,     0,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     166,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,     0,     0,
       0,     0,   197,   198,   199,     0,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,     0,   176,   177,   178,
       0,   179,   166,     0,   180,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   168,     0,     0,     0,     0,   173,
     174,     0,     0,   176,     0,     0,     0,   179,     0,   167,
     180,     0,     0,     0,     0,     0,   174,     0,     0,   176,
       0,     0,     0,   179,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   196,     0,     0,     0,     0,
       0,     0,   197,   198,   199,   187,   188,   189,   190,   191,
     192,   193,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   196,     0,   189,   190,   191,   192,   193,   197,   198,
     199,     0,     0,     0,     0,     0,   195,   196,     0,     0,
       0,     0,     0,     0,   197,   198,   199
  };

  /* YYCHECK.  */
  const short int
  YareParser::yycheck_[] =
  {
         5,    88,    88,   142,   142,    63,     0,     5,     5,   133,
     134,    67,    70,   152,   152,    20,    84,   143,    74,    75,
      76,    77,    78,    79,    80,    81,     4,    83,     6,    67,
      85,     4,    88,     6,    90,   146,    74,    75,    76,    77,
      78,    79,    80,    81,    24,    83,     4,   150,     6,     4,
      88,     6,    90,   150,     4,    12,     6,    24,   150,   146,
     146,    18,    19,    20,    21,    22,    10,    11,    12,    16,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       4,     4,     6,     6,    31,    65,   150,   150,    68,    36,
     146,     4,   148,     6,   133,   134,   135,   136,    65,   138,
     105,    68,   145,     4,   160,     6,   111,     4,   146,     6,
     148,    58,   134,   150,    61,   150,   150,   150,    65,    66,
      67,   150,   150,   150,   150,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,   150,   150,    85,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   150,   150,   101,   150,     7,   162,   138,   139,
     150,   150,   150,   110,   150,   112,   150,   114,   148,   149,
     117,   150,   139,   120,   121,   122,   156,   157,   158,   150,
     150,   148,   149,   134,   150,   150,   150,   150,   150,   156,
     157,   158,   151,     5,   150,   200,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   150,    34,   160,   151,     5,   145,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     5,   195,   196,
     197,   198,   199,   145,     5,   151,   147,   147,   147,   147,
     147,   147,   147,   147,   145,   145,   145,   145,    24,   145,
     145,   145,   219,   145,   145,   145,   145,   145,   151,   120,
     145,     4,    -1,   150,   150,    24,   150,   150,   150,   150,
     150,    24,   150,   240,   150,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   150,    61,    62,    63,   150,    65,
     150,   150,    68,   145,   145,   145,   145,   151,   265,    -1,
     267,   268,   150,   146,   151,   151,    65,   151,    61,    68,
     151,    -1,    65,   151,   151,    68,   151,   151,   151,   145,
     151,   151,   289,   290,   291,   292,   151,   294,   295,   296,
     297,   298,   299,   300,   301,   151,   151,   151,   145,   145,
     145,   145,   145,   145,   145,   121,   122,   145,   145,   145,
     145,   145,   145,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   145,   145,   151,    -1,    -1,    -1,
      -1,   396,   148,   149,    -1,    -1,    -1,   402,    -1,    -1,
     156,   157,   158,   159,   137,   138,   139,    -1,    -1,   148,
     149,    -1,    -1,    -1,    -1,   148,   149,   156,   157,   158,
      -1,    -1,    -1,   156,   157,   158,    -1,    -1,   375,   376,
      -1,   378,   379,   380,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   496,    -1,    -1,    -1,    -1,    -1,   444,    24,    -1,
      -1,    -1,   507,    -1,    30,    31,    -1,    33,    34,    -1,
      36,   458,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,   115,
     116,   117,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,   143,    -1,   145,
      -1,    -1,   148,   149,   150,    -1,    -1,    -1,   154,   155,
     156,   157,   158,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,   115,   116,   117,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,     3,     4,     5,     6,     7,
      -1,    -1,   142,   143,   144,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,   154,   155,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    33,    34,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    89,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,     3,     4,     5,
       6,     7,    -1,    -1,   142,   143,    -1,   145,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,   154,   155,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    -1,    89,    -1,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,    -1,    -1,    -1,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,     3,
       4,     5,     6,     7,    -1,    -1,    -1,   143,    -1,   145,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,   155,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    -1,    89,    -1,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    -1,    -1,
      -1,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     134,     3,     4,     5,     6,     7,    -1,    -1,    -1,   143,
     144,   145,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
     154,   155,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    -1,    89,    -1,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      -1,    -1,    -1,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   134,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   143,   144,   145,    -1,    -1,    -1,    -1,   150,    -1,
      -1,    -1,   154,   155,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    43,    44,   115,   116,   117,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,   143,    -1,   145,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,   154,   155,    86,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    -1,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,   134,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,   149,
     150,    -1,    -1,    -1,   154,   155,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,   117,    43,    44,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    -1,   149,   150,    -1,    -1,
      -1,   154,   155,     3,     4,     5,     6,     7,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,   116,   117,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    69,
      70,    -1,   150,    -1,    -1,    -1,   154,   155,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,   116,   117,    43,    44,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   134,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,   134,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,   154,
     155,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      88,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    24,    -1,
      -1,    -1,    -1,   145,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    24,    -1,    -1,    -1,    -1,   145,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      24,    -1,    -1,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,   153,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    24,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,   151,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,   153,    -1,    -1,
     156,   157,   158,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    24,    -1,    -1,    -1,    -1,   145,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      24,    -1,    -1,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    24,    -1,    -1,    -1,
      -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    24,    -1,    -1,    -1,    -1,   145,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,   145,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    24,    -1,
      -1,    -1,    -1,   145,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    24,    -1,    -1,    -1,    -1,   145,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      24,    -1,    -1,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    24,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    24,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,   121,
     122,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,    24,    -1,
      -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    24,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    24,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      24,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    -1,   121,   122,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
      24,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,    -1,    24,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    24,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    57,
      58,    -1,    -1,    61,    -1,    -1,    -1,    65,    -1,    51,
      68,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    61,
      -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,   133,   134,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,   135,   136,   137,   138,   139,   156,   157,
     158,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  YareParser::yystos_[] =
  {
         0,   162,   163,     0,    84,   164,    85,     3,     4,     5,
       6,     7,    24,    30,    31,    33,    34,    36,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    60,    69,    70,    86,    87,    89,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   115,   116,
     117,   134,   142,   143,   145,   150,   154,   155,   165,   167,
     143,    67,    74,    75,    76,    77,    78,    79,    80,    81,
      83,    88,    90,   146,   148,   160,    67,    74,    75,    76,
      77,    78,    79,    80,    81,    83,    88,    90,   146,   148,
     142,   152,   146,   150,   165,   166,   150,     4,     6,     7,
     150,   167,   150,   150,   150,   165,   145,   150,   150,   150,
     150,   150,   150,     5,   150,     5,   150,   150,   167,   150,
     150,    85,     4,     6,   167,     4,     6,     4,     6,     4,
       6,     4,     6,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     167,   167,   166,   167,   167,   167,    24,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    61,    62,    63,    65,
      68,   121,   122,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   145,   148,   149,   156,   157,   158,
     166,     4,     6,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   112,   113,   114,   149,   167,   134,
     133,   134,     4,     6,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   112,   113,   114,   149,   167,
     134,    10,    11,    12,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   167,   133,   134,   135,   136,   138,
     151,    32,   165,     7,   142,   152,   167,    24,   134,   165,
     167,     5,   167,    34,   167,   151,     5,   167,   167,   167,
     145,     5,   145,     5,   151,     4,     6,     4,     6,    88,
     146,    88,   146,    88,   147,   147,   147,   147,   147,   147,
     147,   147,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   144,
     151,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   144,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   167,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   167,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   153,   145,
     145,   145,   145,   145,   151,   167,   151,   167,    37,   151,
     151,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   167,   167,   167,   167,     4,     6,   167,
     167,   167,   167,   167,   167,   167,   167,   151,   151,   147,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   159,   167,   167,   151,   167,   167,
     167,   151,   151,   151,   151,   151,   151,   151,   146,   145,
     153,   165,   167,   145,   145,   167,   165,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   167,   167,   151,   151,   151,   151,
     151,   145,   145,   167,   147,   151,   120,   151,   145,   145,
     145,   145,   145,   145,     4,   145,   165,   151,   165
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
     385,   386,   387,    43,    45,    42,    47,    37,    94,   388,
     389,   390,    46,   123,   125,    59,    61,    44,    60,    63,
      40,    41,    91,    93,    33,   126,    62,    38,   124,    58,
      64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  YareParser::yyr1_[] =
  {
         0,   161,   162,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   166,   166,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   167
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
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     2
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
  "ABS", "FACTORIAL", "SUMATORIA", "SQRT", "ACOS", "ASIN", "ATAN", "CEIL",
  "COS", "COSH", "EXP", "FLOOR", "LN", "SIN", "SINH", "TAN", "TANH",
  "FACE_HAPPY", "FACE_SAD", "FACE_NO", "PUSH", "POP", "STACK_SIZE",
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
       162,     0,    -1,   163,   164,   142,    -1,   163,    84,    85,
     143,   166,   144,    -1,    -1,   164,   165,    -1,    -1,   145,
      -1,     4,   146,   167,   145,    -1,     4,    88,   167,   145,
      -1,    89,   167,    88,     4,    -1,    89,   167,    88,     6,
      -1,    91,     4,   147,   167,   145,    -1,    91,     6,   147,
     167,   145,    -1,     4,   148,   134,   167,    -1,     6,   148,
     134,   167,    -1,     4,    90,   167,    -1,     6,    90,   167,
      -1,    87,     4,   146,   167,   145,    -1,    87,     4,    88,
     167,   145,    -1,     6,   146,   167,   145,    -1,     6,    88,
     167,   145,    -1,    87,     6,   146,   167,   145,    -1,    87,
       6,    88,   167,   145,    -1,     4,   146,   149,   145,    -1,
       6,   146,   149,   145,    -1,     4,    67,     4,   145,    -1,
       6,    67,     4,   145,    -1,     4,    67,     6,   145,    -1,
       6,    67,     6,   145,    -1,   167,   145,    -1,     4,   146,
     112,   145,    -1,     4,   146,   113,   145,    -1,     4,   146,
     114,   145,    -1,     6,   146,   112,   145,    -1,     6,   146,
     113,   145,    -1,     6,   146,   114,   145,    -1,    46,   150,
     167,   151,   145,    -1,    45,   150,   167,   151,   145,    -1,
      47,   150,   167,   151,   145,    -1,   143,   166,   144,    -1,
      31,   166,    32,    -1,    48,   150,     5,   151,   145,    -1,
      48,     5,   145,    -1,    49,   150,     5,   151,   145,    -1,
      49,     5,   145,    -1,    34,   150,   167,   151,   165,    -1,
      34,   167,   165,    -1,    40,   165,    34,   150,   167,   151,
     145,    -1,    36,   150,   167,    37,   167,   147,     4,   151,
     165,    -1,    41,   145,    -1,    38,   150,     5,   151,   145,
      -1,    39,   150,   167,   151,   145,    -1,    42,   150,   167,
     151,   165,    -1,    42,   150,   167,   151,   165,   120,   165,
      -1,     4,    77,   167,   145,    -1,     6,    77,   167,   145,
      -1,    93,     4,   147,   167,   145,    -1,    93,     6,   147,
     167,   145,    -1,    92,     4,   147,   167,   145,    -1,    92,
       6,   147,   167,   145,    -1,    94,     4,   147,   167,   145,
      -1,    94,     6,   147,   167,   145,    -1,     4,    78,   167,
      -1,     6,    78,   167,    -1,     4,    76,   167,    -1,     6,
      76,   167,    -1,     4,    79,   167,    -1,     6,    79,   167,
      -1,     4,    74,   167,    -1,     6,    74,   167,    -1,     4,
      75,   167,    -1,     6,    75,   167,    -1,     4,    80,   167,
      -1,     6,    80,   167,    -1,     4,    81,   167,    -1,     6,
      81,   167,    -1,     4,    83,   167,    -1,     6,    83,   167,
      -1,   115,   167,    -1,     7,   152,   167,   153,   146,   167,
     145,    -1,    33,   150,     7,   151,   145,    -1,     7,   142,
      10,   150,   167,   151,   145,    -1,     7,   142,    11,   150,
     167,   151,   145,    -1,     7,   142,    14,   150,   167,   151,
     145,    -1,     7,   142,    15,   150,   167,   151,   145,    -1,
       7,   142,    16,   150,   167,   151,   145,    -1,     7,   142,
      17,   150,   151,   145,    -1,     7,   142,    23,   150,   151,
     145,    -1,    24,   146,   133,   145,    -1,    24,   146,   134,
     145,    -1,    24,   146,   135,   145,    -1,    24,   146,   136,
     145,    -1,    24,   146,   138,   145,    -1,    30,   150,   151,
      -1,    -1,   165,    -1,   166,   165,    -1,     3,    -1,     6,
      -1,     5,    -1,     4,    -1,     7,   152,   167,   153,    -1,
       7,   142,    12,   150,   151,    -1,     7,   142,    12,    -1,
       7,   142,    18,   150,   151,    -1,     7,   142,    19,   150,
     151,    -1,     7,   142,    21,   150,   151,    -1,     7,   142,
      20,   150,   151,    -1,     7,   142,    22,   150,   151,    -1,
     134,   167,    -1,   154,   167,    -1,   155,   167,    -1,    60,
     167,    -1,   167,   133,   167,    -1,   167,   134,   167,    -1,
     167,    57,   167,    -1,   167,    52,   167,    -1,   167,   135,
     167,    -1,   167,    58,   167,    -1,   167,   136,   167,    -1,
     167,    51,   167,    -1,   167,   148,   167,    -1,   167,    55,
     167,    -1,   167,    63,   167,    -1,   167,   156,   167,    -1,
     167,    53,   167,    -1,   167,    62,   167,    -1,   167,   138,
     167,    -1,   167,   139,   167,    -1,   167,   137,   167,    -1,
     167,    61,   167,    -1,   167,   132,   167,    -1,   167,    54,
     167,    -1,   167,   131,   167,    -1,   167,    56,   167,    -1,
     167,   129,   167,    -1,   167,   130,   167,    -1,   167,    59,
     167,    -1,   167,   122,   167,    -1,   167,   121,   167,    -1,
     167,   157,   167,    -1,   167,   158,   167,    -1,   150,   167,
     151,    -1,   167,    24,   167,    -1,   167,   149,   167,   159,
     167,    -1,    43,   150,   151,    -1,    44,   150,     5,   151,
      -1,    50,   150,   151,    -1,   116,    -1,   117,    -1,    95,
     150,   167,   151,    -1,    98,   150,   167,   151,    -1,    99,
     150,   167,   151,    -1,   100,   150,   167,   151,    -1,   101,
     150,   167,   151,    -1,   102,   150,   167,   151,    -1,   103,
     150,   167,   151,    -1,   104,   150,   167,   151,    -1,   105,
     150,   167,   151,    -1,   106,   150,   167,   151,    -1,   107,
     150,   167,   151,    -1,   108,   150,   167,   151,    -1,   109,
     150,   167,   151,    -1,   110,   150,   167,   151,    -1,   111,
     150,   167,   151,    -1,    97,   150,   167,   147,   167,   151,
      -1,    96,   150,   167,   151,    -1,    69,   150,     6,   151,
      -1,    69,   150,     4,   151,    -1,    70,   150,     6,   151,
      -1,    70,   150,     4,   151,    -1,   167,    68,   167,    -1,
     167,    65,   167,    -1,     4,   160,   134,    -1,     4,   160,
     133,    -1,    86,    85,    -1
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
     744,   749,   754,   759,   764,   769,   774,   781,   786,   791,
     796,   801,   806,   810,   814,   818,   822
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  YareParser::yyrline_[] =
  {
         0,   298,   298,   304,   307,   311,   316,   320,   323,   326,
     329,   332,   335,   338,   341,   344,   347,   350,   353,   356,
     359,   362,   365,   368,   371,   374,   377,   380,   383,   386,
     389,   392,   393,   394,   395,   396,   397,   398,   401,   404,
     407,   410,   413,   416,   419,   422,   425,   428,   431,   434,
     437,   440,   443,   446,   449,   452,   455,   458,   461,   464,
     467,   470,   473,   476,   479,   482,   485,   488,   491,   494,
     497,   500,   503,   506,   509,   512,   515,   518,   521,   524,
     527,   530,   533,   536,   539,   542,   545,   548,   551,   554,
     557,   560,   563,   566,   569,   572,   576,   579,   585,   588,
     596,   599,   602,   605,   608,   611,   614,   617,   620,   623,
     626,   629,   632,   635,   638,   641,   644,   647,   650,   653,
     656,   659,   662,   665,   668,   671,   674,   677,   680,   683,
     686,   689,   692,   695,   698,   701,   704,   707,   710,   713,
     716,   719,   722,   725,   728,   742,   745,   748,   751,   754,
     757,   760,   763,   766,   769,   772,   775,   778,   781,   784,
     787,   790,   793,   796,   799,   802,   805,   808,   811,   814,
     817,   820,   823,   826,   829,   832,   835
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
       2,     2,     2,   154,     2,     2,     2,   137,   157,     2,
     150,   151,   135,   133,   147,   134,   142,   136,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   159,   145,
     148,   146,   156,   149,   160,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   152,     2,   153,   138,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   143,   158,   144,   155,     2,     2,     2,
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
     125,   126,   127,   128,   129,   130,   131,   132,   139,   140,
     141
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int YareParser::yyeof_ = 0;
  const int YareParser::yylast_ = 6616;
  const int YareParser::yynnts_ = 7;
  const int YareParser::yyempty_ = -2;
  const int YareParser::yyfinal_ = 3;
  const int YareParser::yyterror_ = 1;
  const int YareParser::yyerrcode_ = 256;
  const int YareParser::yyntokens_ = 161;

  const unsigned int YareParser::yyuser_token_number_max_ = 390;
  const YareParser::token_number_type YareParser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 9 "yare.y"
} // YL

/* Line 1136 of lalr1.cc  */
#line 4137 "yare.tab.c"


/* Line 1138 of lalr1.cc  */
#line 839 "yare.y"


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

