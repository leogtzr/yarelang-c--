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
#line 10 "yare.y"

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

	// The symbol table:
	long double sym[26];
	Variables *vars = NULL;
	Pila *pila = NULL;
	struct proc *procs = NULL;


/* Line 293 of lalr1.cc  */
#line 61 "yare.tab.c"


#include "yare.tab.h"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 70 "yare.tab.c"
/* Unqualified %code blocks.  */

/* Line 300 of lalr1.cc  */
#line 37 "yare.y"

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

	void freeNode(nodeType *);
	long double run(nodeType *);

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
#line 135 "yare.tab.c"

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
#line 5 "yare.y"
namespace YL {

/* Line 382 of lalr1.cc  */
#line 223 "yare.tab.c"

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
#line 239 "yare.y"
    {
	if(vars != NULL) {
		delete(vars);
	}
	if(pila != NULL) {
		delete(pila);
	}
	exit(EXIT_SUCCESS);
}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 251 "yare.y"
    {
		push_l_proc(&procs, (yysemantic_stack_[(6) - (3)].nameFunction), (yysemantic_stack_[(6) - (5)].nPtr));
}
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 254 "yare.y"
    {;}
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 258 "yare.y"
    { 
		run((yysemantic_stack_[(2) - (2)].nPtr));			/* Ejecutar los nodos */ 
		freeNode((yysemantic_stack_[(2) - (2)].nPtr)); 	/* Liberar los nodos */

	}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 263 "yare.y"
    {;}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 267 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, NULL, NULL); 
	}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 270 "yare.y"
    { 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 273 "yare.y"
    {		// x to 1 + 2; 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 276 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (4)].sIndex)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 279 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (4)].identificador)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 282 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 285 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 288 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 291 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 294 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 297 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 300 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 303 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 306 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 309 "yare.y"
    { 	// :x: to 1 + 2;
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 312 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 315 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 318 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, id((yysemantic_stack_[(4) - (1)].sIndex)));
	}
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 321 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, idS((yysemantic_stack_[(4) - (1)].identificador)));
	}
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 324 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 327 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 330 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 333 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 336 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(2) - (1)].nPtr); 
	}
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 339 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 340 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 341 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 342 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 343 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 344 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 345 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINTN, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 348 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRASCII, 1, (yysemantic_stack_[(5) - (3)].nPtr));
	}
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 351 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINT, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 354 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 357 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 360 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 363 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 366 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(3) - (2)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 369 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DO_WHILE, 2, (yysemantic_stack_[(7) - (2)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 372 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FOREACH, 4, (yysemantic_stack_[(9) - (3)].nPtr), (yysemantic_stack_[(9) - (5)].nPtr), id((yysemantic_stack_[(9) - (7)].sIndex)), (yysemantic_stack_[(9) - (9)].nPtr));
	}
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 375 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::BREAK, 0);
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 378 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 381 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 3, (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr), (yysemantic_stack_[(7) - (7)].nPtr)); 
	}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 384 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 387 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 390 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 393 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 396 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 399 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 402 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 405 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 408 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 411 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 414 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 417 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 420 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 423 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 426 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 429 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 432 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 435 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 438 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 441 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 444 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 447 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 450 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 453 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 456 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUSH, 1, (yysemantic_stack_[(2) - (2)].nPtr));	
	}
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 459 "yare.y"
    {;}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 463 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(1) - (1)].nPtr); 
	}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 466 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, (yysemantic_stack_[(2) - (1)].nPtr), (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 472 "yare.y"
    {
		(yyval.nPtr) = con((yysemantic_stack_[(1) - (1)].valnum));
	}
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 475 "yare.y"
    { 
		if(vars == NULL) {
			cout << "La variable '" << (yysemantic_stack_[(1) - (1)].identificador) << "' no ha sido declarada";
			exit(EXIT_FAILURE);
		} else {
			(yyval.nPtr) = idS((yysemantic_stack_[(1) - (1)].identificador));	
		}
	}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 483 "yare.y"
    {
		(yyval.nPtr) = conStr((yysemantic_stack_[(1) - (1)].cadena), typeCadena);
	}
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 486 "yare.y"
    { 
		(yyval.nPtr) = id((yysemantic_stack_[(1) - (1)].sIndex)); 
	}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 489 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::UMINUS, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 492 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 495 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 498 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 501 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 504 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 507 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 510 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 513 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 516 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 519 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 522 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 525 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 528 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 531 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 534 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 537 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 540 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 543 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 546 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 549 "yare.y"
    { 
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 552 "yare.y"
    {
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 555 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 558 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 561 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 564 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 567 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 570 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 573 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 576 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::AND, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 579 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OR, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 582 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ANDBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 585 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ORBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 588 "yare.y"
    {
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr);
	}
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 591 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READ, 0);
	}
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 594 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::READP, 1, conStr((yysemantic_stack_[(4) - (3)].cadena), typeCadena));
	}
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 597 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RAND, 0);
	}
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 600 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::POP, 0);
	}
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 603 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ABS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 606 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SQRT, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 609 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ACOS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 612 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ASIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 615 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 618 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CEIL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 621 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 624 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COSH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 627 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXP, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 630 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FLOOR, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 633 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::LN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 636 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 639 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SINH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 642 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 645 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 648 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SUMATORIA, 2, (yysemantic_stack_[(6) - (3)].nPtr), (yysemantic_stack_[(6) - (5)].nPtr));	
	}
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 651 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FACTORIAL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 654 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 657 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 660 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 663 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 666 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::XOROP, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 669 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RANGE_RANDOM, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 672 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 675 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 678 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CALL, 1, idS((yysemantic_stack_[(2) - (2)].nameFunction)));
	}
    break;



/* Line 690 of lalr1.cc  */
#line 1777 "yare.tab.c"
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
  const signed char YareParser::yypact_ninf_ = -96;
  const short int
  YareParser::yypact_[] =
  {
       -96,     4,   -33,   -96,   -23,   510,   -69,   -96,   -35,   -96,
     317,  1119,   -74,   867,   -68,   -72,   -71,   -70,   -65,   -64,
     -60,     0,   -58,  1203,   -56,   -54,    -6,    13,  1203,    16,
      20,    23,    24,   -53,   -52,   -51,   -50,   -49,   -48,   -47,
     -46,   -45,   -44,   -43,   -42,   -41,   -36,   -31,   -30,   -15,
    1203,   -96,  1203,   -96,   867,   -96,  1203,  1203,  1203,   -96,
    1229,   867,    27,  1203,  1203,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1203,   951,   -39,   -95,    30,  1203,  1203,
    1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1035,
     -19,   -75,   -96,  1203,   388,  1203,    54,   -96,  1203,   -14,
      99,  1203,  1203,  1203,     6,   115,     3,   133,    31,    34,
     -96,   -57,   -55,  1379,    10,    12,    19,    21,    29,    32,
      33,    52,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  4415,
     133,   -96,   629,  1407,   133,   133,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,   -96,  1203,  1203,  1203,  1203,   748,    15,
      36,  4415,  4415,  4415,  1511,  4415,  4415,  4415,  4415,  4415,
    1539,  4415,    56,    57,    59,    88,  1643,  1203,   -96,   -96,
      95,    96,  4415,  4415,  4415,  1671,  4415,  4415,  4415,  4415,
    4415,  1775,  4415,    97,    98,   101,   102,  1803,  1203,  1907,
    1203,   -96,  1275,    14,  1935,   -96,    26,  2039,  2067,  2171,
     -96,    93,   -96,    94,   112,   114,   125,  1203,  1203,  1203,
    1203,    37,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,
    2199,  2303,  2331,  2435,  2463,  2567,  2595,  2699,  2727,  2831,
    2859,  2963,  2991,  3095,  3123,  3227,  3255,   -96,   -96,   -96,
     441,   870,  4600,  4600,  4600,  4600,   870,   441,  4600,   100,
    4600,  4600,  4415,  4415,  4443,  4575,  4600,  4600,  4600,  4600,
     870,   870,   441,   441,   100,    17,   133,  4415,  4415,  4415,
    4415,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,  4547,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,  4547,   223,  3359,  1203,  1203,   867,   -96,   104,   105,
     106,   107,   -96,   -96,   -96,   -96,  3387,  3491,  3519,  3623,
     -96,   -96,  3651,  3755,  3783,  3887,  3915,  4019,  4047,  4151,
     -96,   -96,  1203,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,  4179,  4283,
      55,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,  4311,   138,   108,
     867,   -96,   126,   -96,   -96,   867,   -96
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  YareParser::yydefact_[] =
  {
         4,     0,     6,     1,     0,     0,     0,    78,    81,    80,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,     0,     2,    75,     7,     0,     0,     0,     5,
       0,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,    79,     0,    75,     0,     0,    47,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      82,    76,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,    64,    66,    60,     0,    58,    62,    68,    70,    72,
       0,    16,     0,     0,     0,     0,     0,     0,   144,   143,
       0,     0,    65,    67,    61,     0,    59,    63,    69,    71,
      73,     0,    17,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,     0,     0,   116,     0,     0,     0,     0,
      42,     0,   118,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    77,   115,
      93,    89,    98,   105,    95,   107,    88,    91,   110,   103,
      99,    96,   142,   141,   112,   111,   108,   109,   106,   104,
      86,    87,    90,    92,   102,   100,   101,    94,    97,   113,
     114,     3,    26,    28,    50,     9,    31,    32,    33,    24,
       8,    14,    27,    29,    51,    21,    34,    35,    36,    25,
      20,    15,   115,    87,     0,     0,    75,   117,     0,     0,
       0,     0,   138,   137,   140,   139,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   136,     0,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,    43,     0,     0,
      48,    38,    37,    39,    41,    19,    18,    23,    22,    12,
      13,    54,    55,    52,    53,    56,    57,     0,     0,     0,
      75,   135,     0,    45,    49,    75,    46
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  YareParser::yypgoto_[] =
  {
       -96,   -96,   -96,   -96,    -5,    85,    28
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  YareParser::yydefgoto_[] =
  {
        -1,     1,     2,     5,   141,   142,    60
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char YareParser::yytable_ninf_ = -83;
  const short int
  YareParser::yytable_[] =
  {
        59,   237,    62,   239,     3,   104,   198,   199,    96,    63,
      64,    65,    66,    67,    68,    69,    70,   111,    71,   112,
     114,     4,   115,    72,   116,    73,   117,   118,   120,   119,
     121,   179,     6,   180,   200,   233,   201,   234,   235,    94,
     236,   340,    61,   341,    95,    97,    98,    99,   100,   110,
      76,   107,   158,   101,   102,   159,   113,   238,   103,   240,
     106,   223,   108,   197,   109,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   139,    74,
     140,    75,   135,   218,   143,   144,   145,   136,   137,   221,
      76,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   196,   138,   226,   225,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   217,   105,   230,
     231,   219,   232,   222,   172,   242,   224,   243,   302,   227,
     228,   229,   325,   174,   244,   158,   245,   268,   159,   175,
     176,   177,   392,   390,   246,   327,   178,   247,   248,   303,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   249,   158,   306,
     307,   159,   308,   268,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   309,   297,   298,   299,   300,   171,   172,   312,   313,
     316,   317,   331,   332,   318,   319,   174,   371,   372,   373,
     374,   393,   175,   176,   177,   311,     7,     8,     9,    10,
      11,   333,    12,   334,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   335,   395,   321,     0,   323,   174,
       0,     0,     0,    23,     0,   175,   176,   177,     0,     0,
       0,     0,    24,    25,     0,   336,   337,   338,   339,     0,
     342,   343,   344,   345,   346,   347,   348,   349,     0,    26,
      27,     0,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     0,     0,     0,    50,    51,
       0,   -75,     0,     0,     0,     0,     0,   367,     0,     0,
       0,   370,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,     0,   -75,    54,   -75,    55,     0,     0,     0,
       0,    56,     0,    57,    58,     0,     0,     0,     0,     0,
       0,     0,   368,   369,    77,     0,     0,     0,     0,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,     0,
      86,     0,     0,     0,     0,    87,     0,    88,     0,     0,
     387,     0,     0,     0,     0,   394,     0,     0,     0,     0,
     396,     7,     8,     9,    10,    11,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    23,   155,
     156,   157,     0,   158,     0,     0,   159,    24,    25,     0,
       0,    89,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       0,     0,   155,    50,    51,     0,   158,   160,   161,   159,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     220,   168,   169,   170,   171,   172,     0,     0,     0,    54,
       0,    55,     0,     0,   174,     0,    56,     0,    57,    58,
     175,   176,   177,     7,     8,     9,    10,    11,     0,    12,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,   170,   171,   172,    24,
      25,     0,     0,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,   175,   176,   177,    26,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     0,     0,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     0,
      53,    54,     0,    55,     0,     0,     0,     0,    56,     0,
      57,    58,     7,     8,     9,    10,    11,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     0,     0,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
      54,   267,    55,     0,     0,     0,     0,    56,     0,    57,
      58,     7,     8,     9,    10,    11,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       0,     0,     0,    50,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,     0,    54,
     301,    55,     0,     0,     0,     0,    56,     0,    57,    58,
       7,     8,     9,    10,    11,     0,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     0,     0,
       0,   146,     0,     0,     0,     0,     0,    23,   153,     0,
       0,   155,     0,     0,     0,   158,    24,    25,   159,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,     0,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,     0,
       0,     0,    50,    51,     7,    91,     9,    92,     0,     0,
       0,     0,     0,     0,     0,    16,    17,     0,     0,    52,
       0,    22,     0,   168,   169,   170,   171,   172,    54,     0,
      55,    23,     0,     0,     0,    56,   174,    57,    58,     0,
      24,    25,   175,   176,   177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   192,   193,   194,     0,    51,     7,    91,
       9,    92,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     0,    52,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,   195,    56,
       0,    57,    58,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   213,   214,   215,
       0,    51,     7,    91,     9,    92,     0,     0,     0,     0,
       0,     0,     0,    16,    17,     0,     0,    52,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,   216,    56,     0,    57,    58,     0,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     0,     0,     0,     0,    51,     7,    91,     9,    92,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
       0,    52,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,    93,     0,    57,
      58,     0,    24,    25,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    26,
     155,   156,   157,     0,   158,     0,     0,   159,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,   324,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    52,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,   160,   161,
       0,    56,     0,    57,    58,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,   173,     0,     0,   174,     0,     0,     0,     0,
       0,   175,   176,   177,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,   175,   176,   177,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   241,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   161,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   160,   161,     0,     0,
       0,   175,   176,   177,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,   269,     0,     0,   175,
     176,   177,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,   304,     0,     0,   174,   160,   161,
       0,     0,     0,   175,   176,   177,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,   305,     0,     0,   174,     0,     0,     0,     0,
       0,   175,   176,   177,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,   310,     0,     0,   174,
     160,   161,     0,     0,     0,   175,   176,   177,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,   314,     0,     0,   174,     0,     0,
       0,     0,     0,   175,   176,   177,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,   315,     0,
       0,   174,   160,   161,     0,     0,     0,   175,   176,   177,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,   320,     0,     0,   174,
       0,     0,     0,     0,     0,   175,   176,   177,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   160,   161,   322,     0,     0,   175,
     176,   177,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,   326,     0,     0,   175,   176,   177,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   161,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   160,   161,   328,     0,
       0,   175,   176,   177,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,   329,     0,     0,   175,
     176,   177,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   160,   161,
     330,     0,     0,   175,   176,   177,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   174,     0,     0,   350,     0,
       0,   175,   176,   177,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     160,   161,   351,     0,     0,   175,   176,   177,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,     0,     0,   352,   174,     0,     0,
       0,     0,     0,   175,   176,   177,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   160,   161,   353,     0,     0,   175,   176,   177,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,     0,   354,     0,     0,   175,   176,   177,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   160,   161,   355,     0,     0,   175,
     176,   177,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,   356,     0,     0,   175,   176,   177,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   161,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   174,   160,   161,   357,     0,
       0,   175,   176,   177,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,   358,     0,     0,   175,
     176,   177,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,     0,     0,     0,   174,   160,   161,
     359,     0,     0,   175,   176,   177,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,   174,     0,     0,   360,     0,
       0,   175,   176,   177,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     160,   161,   361,     0,     0,   175,   176,   177,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
     362,     0,     0,   175,   176,   177,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,   160,   161,   363,     0,     0,   175,   176,   177,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,     0,   364,     0,     0,   175,   176,   177,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   160,   161,   365,     0,     0,   175,
     176,   177,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,   366,     0,     0,   175,   176,   177,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,
     -82,   -82,   -82,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -82,   -82,
       0,     0,     0,     0,     0,     0,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,     0,     0,
       0,     0,   -82,     0,     0,   174,   160,   161,     0,     0,
       0,   175,   176,   177,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
     375,     0,     0,   174,     0,     0,     0,     0,     0,   175,
     176,   177,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,   376,     0,     0,   174,   160,   161,
       0,     0,     0,   175,   176,   177,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,   377,     0,     0,   174,     0,     0,     0,     0,
       0,   175,   176,   177,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,   378,     0,     0,   174,
     160,   161,     0,     0,     0,   175,   176,   177,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,   379,     0,     0,   174,     0,     0,
       0,     0,     0,   175,   176,   177,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,   380,     0,
       0,   174,   160,   161,     0,     0,     0,   175,   176,   177,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,   381,     0,     0,   174,
       0,     0,     0,     0,     0,   175,   176,   177,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
     382,     0,     0,   174,   160,   161,     0,     0,     0,   175,
     176,   177,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,   383,     0,
       0,   174,     0,     0,     0,     0,     0,   175,   176,   177,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   161,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,   384,     0,     0,   174,   160,   161,     0,     0,
       0,   175,   176,   177,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
     385,     0,     0,   174,     0,     0,     0,     0,     0,   175,
     176,   177,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,     0,
     155,   156,   157,     0,   158,     0,     0,   159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     160,   161,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,   386,     0,     0,   174,   160,   161,
       0,     0,     0,   175,   176,   177,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,   388,   174,     0,     0,     0,     0,
       0,   175,   176,   177,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,   155,   156,   157,     0,   158,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   160,   161,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     160,   161,   389,     0,     0,   175,   176,   177,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
     391,     0,     0,   175,   176,   177,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,   155,   156,   157,     0,   158,     0,
       0,   159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,     0,     0,     0,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,   161,     0,     0,     0,   175,   176,   177,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,     0,     0,     0,     0,   175,   176,   177,   146,   147,
     148,   149,   150,   151,   152,   153,   154,     0,   155,   156,
     157,     0,   158,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,     0,   155,   156,   157,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,   146,   147,     0,     0,     0,     0,   152,   153,     0,
       0,   155,     0,     0,     0,   158,   160,   161,   159,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,     0,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,   175,
     176,   177,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,     0,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,   175,   176,   177,
       0,   166,   167,   168,   169,   170,   171,   172,     0,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
       0,     0,   175,   176,   177
  };

  /* YYCHECK.  */
  const short int
  YareParser::yycheck_[] =
  {
         5,    58,    37,    58,     0,     5,   101,   102,    13,    44,
      45,    46,    47,    48,    49,    50,    51,     4,    53,     6,
       4,    54,     6,    58,     4,    60,     6,     4,     4,     6,
       6,     4,    55,     6,     4,     4,     6,     6,     4,    11,
       6,     4,   111,     6,   118,   113,   118,   118,   118,    55,
     125,    23,    35,   118,   118,    38,    28,   114,   118,   114,
     118,     7,   118,   102,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,    50,   114,
      52,   116,   118,   102,    56,    57,    58,   118,   118,    94,
     125,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   118,     5,   119,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   118,   113,
       5,    93,   119,    95,   107,   115,    98,   115,   113,   101,
     102,   103,   118,   116,   115,    35,   115,   142,    38,   122,
     123,   124,     4,    88,   115,   119,    61,   115,   115,   113,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   115,    35,   113,
     113,    38,   113,   178,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   113,   174,   175,   176,   177,   106,   107,   113,   113,
     113,   113,   119,   119,   113,   113,   116,   113,   113,   113,
     113,   113,   122,   123,   124,   197,     3,     4,     5,     6,
       7,   119,     9,   119,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   119,   119,   218,    -1,   220,   116,
      -1,    -1,    -1,    30,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,    39,    40,    -1,   237,   238,   239,   240,    -1,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,    56,
      57,    -1,    59,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    -1,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,   326,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,   118,    -1,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324,   325,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      53,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,
     352,    -1,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,
     395,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    -1,    -1,    38,    39,    40,    -1,
      -1,   114,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    31,    85,    86,    -1,    35,    89,    90,    38,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,    -1,    -1,    -1,   111,
      -1,   113,    -1,    -1,   116,    -1,   118,    -1,   120,   121,
     122,   123,   124,     3,     4,     5,     6,     7,    -1,     9,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,   105,   106,   107,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,    56,    57,    -1,    59,
      -1,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,    -1,   113,    -1,    -1,    -1,    -1,   118,    -1,
     120,   121,     3,     4,     5,     6,     7,    -1,     9,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    59,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,    -1,    -1,   118,    -1,   120,
     121,     3,     4,     5,     6,     7,    -1,     9,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,
       3,     4,     5,     6,     7,    -1,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    30,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    39,    40,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    -1,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    85,    86,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    -1,    -1,   102,
      -1,    20,    -1,   103,   104,   105,   106,   107,   111,    -1,
     113,    30,    -1,    -1,    -1,   118,   116,   120,   121,    -1,
      39,    40,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    -1,    -1,   102,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,   117,   118,
      -1,   120,   121,    -1,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    15,    -1,    -1,   102,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,   117,   118,    -1,   120,   121,    -1,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    86,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    -1,
      -1,   102,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,   118,    -1,   120,
     121,    -1,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    56,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    10,    -1,    -1,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,   102,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    89,    90,
      -1,   118,    -1,   120,   121,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    58,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    89,    90,    -1,    -1,
      -1,   122,   123,   124,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    89,    90,
      -1,    -1,    -1,   122,   123,   124,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
      89,    90,    -1,    -1,    -1,   122,   123,   124,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    89,    90,    -1,    -1,    -1,   122,   123,   124,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    89,    90,   119,    -1,    -1,   122,
     123,   124,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    89,    90,   119,    -1,
      -1,   122,   123,   124,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    89,    90,
     119,    -1,    -1,   122,   123,   124,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,   122,   123,   124,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      89,    90,   119,    -1,    -1,   122,   123,   124,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    89,    90,   119,    -1,    -1,   122,   123,   124,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,   122,   123,   124,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    89,    90,   119,    -1,    -1,   122,
     123,   124,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    89,    90,   119,    -1,
      -1,   122,   123,   124,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,   119,    -1,    -1,   122,
     123,   124,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    89,    90,
     119,    -1,    -1,   122,   123,   124,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    -1,
      -1,   122,   123,   124,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      89,    90,   119,    -1,    -1,   122,   123,   124,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
     119,    -1,    -1,   122,   123,   124,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    89,    90,   119,    -1,    -1,   122,   123,   124,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,   119,    -1,    -1,   122,   123,   124,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    89,    90,   119,    -1,    -1,   122,
     123,   124,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,   119,    -1,    -1,   122,   123,   124,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    89,    90,    -1,    -1,
      -1,   122,   123,   124,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    89,    90,
      -1,    -1,    -1,   122,   123,   124,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
      89,    90,    -1,    -1,    -1,   122,   123,   124,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    89,    90,    -1,    -1,    -1,   122,   123,   124,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,    89,    90,    -1,    -1,    -1,   122,
     123,   124,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,    89,    90,    -1,    -1,
      -1,   122,   123,   124,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    89,    90,
      -1,    -1,    -1,   122,   123,   124,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      89,    90,   119,    -1,    -1,   122,   123,   124,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
     119,    -1,    -1,   122,   123,   124,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    90,    -1,    -1,    -1,   122,   123,   124,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    -1,    -1,    35,    89,    90,    38,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,    -1,
     103,   104,   105,   106,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
      -1,   101,   102,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  YareParser::yystos_[] =
  {
         0,   127,   128,     0,    54,   129,    55,     3,     4,     5,
       6,     7,     9,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    30,    39,    40,    56,    57,    59,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      85,    86,   102,   110,   111,   113,   118,   120,   121,   130,
     132,   111,    37,    44,    45,    46,    47,    48,    49,    50,
      51,    53,    58,    60,   114,   116,   125,    37,    44,    45,
      46,    47,    48,    49,    50,    51,    53,    58,    60,   114,
     116,     4,     6,   118,   132,   118,   130,   113,   118,   118,
     118,   118,   118,   118,     5,   118,   118,   132,   118,   118,
      55,     4,     6,   132,     4,     6,     4,     6,     4,     6,
       4,     6,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   132,
     132,   130,   131,   132,   132,   132,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    31,    32,    33,    35,    38,
      89,    90,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   113,   116,   122,   123,   124,   131,     4,
       6,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,    82,    83,    84,   117,   132,   102,   101,   102,
       4,     6,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,    82,    83,    84,   117,   132,   102,   132,
     102,   130,   132,     7,   132,   119,     5,   132,   132,   132,
     113,     5,   119,     4,     6,     4,     6,    58,   114,    58,
     114,    58,   115,   115,   115,   115,   115,   115,   115,   115,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   112,   130,   119,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   112,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   132,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   132,   119,   132,    10,   118,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   132,   132,   132,   132,
       4,     6,   132,   132,   132,   132,   132,   132,   132,   132,
     119,   119,   115,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   130,   132,   132,
     130,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   132,   115,   119,
      88,   119,     4,   113,   130,   119,   130
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
     355,    43,    45,    42,    47,    37,    94,   356,   357,   358,
      46,   123,   125,    59,    61,    44,    60,    63,    40,    41,
      33,   126,    62,    38,   124,    64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  YareParser::yyr1_[] =
  {
         0,   126,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  YareParser::yyr2_[] =
  {
         0,     2,     3,     6,     0,     2,     0,     1,     4,     4,
       4,     4,     5,     5,     4,     4,     3,     3,     5,     5,
       4,     4,     5,     5,     4,     4,     4,     4,     4,     4,
       2,     4,     4,     4,     4,     4,     4,     5,     5,     5,
       3,     5,     3,     5,     3,     7,     9,     2,     5,     7,
       4,     4,     5,     5,     5,     5,     5,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     0,     1,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     4,     4,
       4,     3,     3,     3,     3,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const YareParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMERIC", "VARIABLE", "CADENA", "ID",
  "WHILE", "DO_WHILE", "FOREACH", "ELIPSIS", "DO", "BREAK", "IF", "READ",
  "READP", "PRASCII", "PRINTN", "PRINT", "PUTS", "RAND", "EXPR_DIV",
  "EXPR_MAS", "EXPR_MAYOR", "EXPR_MAYORIGUAL", "EXPR_MENOR",
  "EXPR_MENORIGUAL", "EXPR_MENOS", "EXPR_MUL", "EXPR_IGUAL", "EXPR_NOT",
  "MOD_WORD", "_GT_", "_LT_", "INIT_RANDOM", "RANGE_RANDOM", "SWAP_ID_VAR",
  "SWAP_OP", "XOROP", "DEC", "INC", "DEC_CPP", "INC_CPP", "ID_ASIGNACION",
  "OP_ASIGN_ABR_MUL", "OP_ASIGN_ABR_DIV", "OP_ASIGN_ABR_MOD",
  "OP_ASIGN_ABR_MAS", "OP_ASIGN_ABR_MENOS", "OP_ASIGN_ABR_SHIFTLEFT",
  "OP_ASIGN_ABR_SHIFTRIGHT", "OP_ASIGN_ABR_AND", "OP_ASIGN_ABR_OR",
  "OP_ASIGN_ABR_POW", "PROC", "FUNCNAME", "CALL", "LETSET_ASSIGN", "TO",
  "MOVE", "PASCAL_ASSIGN", "MOV_ASM", "SUB_ASM", "ADD_ASM", "MUL_ASM",
  "ABS", "FACTORIAL", "SUMATORIA", "SQRT", "ACOS", "ASIN", "ATAN", "CEIL",
  "COS", "COSH", "EXP", "FLOOR", "LN", "SIN", "SINH", "TAN", "TANH",
  "FACE_HAPPY", "FACE_SAD", "FACE_NO", "PUSH", "POP", "IFX", "ELSE", "OR",
  "AND", "SHIFTRIGHT", "SHIFTLEFT", "ANDBITS", "ORBITS", "LT", "GT", "NE",
  "EQ", "LE", "GE", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'",
  "EXPR_ELEVADO", "NEGACION", "UMINUS", "'.'", "'{'", "'}'", "';'", "'='",
  "','", "'<'", "'?'", "'('", "')'", "'!'", "'~'", "'>'", "'&'", "'|'",
  "'@'", "$accept", "program", "funciones", "cuerpo", "stmt", "stmt_list",
  "expr", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const YareParser::rhs_number_type
  YareParser::yyrhs_[] =
  {
       127,     0,    -1,   128,   129,   110,    -1,   128,    54,    55,
     111,   131,   112,    -1,    -1,   129,   130,    -1,    -1,   113,
      -1,     4,   114,   132,   113,    -1,     4,    58,   132,   113,
      -1,    59,   132,    58,     4,    -1,    59,   132,    58,     6,
      -1,    61,     4,   115,   132,   113,    -1,    61,     6,   115,
     132,   113,    -1,     4,   116,   102,   132,    -1,     6,   116,
     102,   132,    -1,     4,    60,   132,    -1,     6,    60,   132,
      -1,    57,     4,   114,   132,   113,    -1,    57,     4,    58,
     132,   113,    -1,     6,   114,   132,   113,    -1,     6,    58,
     132,   113,    -1,    57,     6,   114,   132,   113,    -1,    57,
       6,    58,   132,   113,    -1,     4,   114,   117,   113,    -1,
       6,   114,   117,   113,    -1,     4,    37,     4,   113,    -1,
       6,    37,     4,   113,    -1,     4,    37,     6,   113,    -1,
       6,    37,     6,   113,    -1,   132,   113,    -1,     4,   114,
      82,   113,    -1,     4,   114,    83,   113,    -1,     4,   114,
      84,   113,    -1,     6,   114,    82,   113,    -1,     6,   114,
      83,   113,    -1,     6,   114,    84,   113,    -1,    17,   118,
     132,   119,   113,    -1,    16,   118,   132,   119,   113,    -1,
      18,   118,   132,   119,   113,    -1,   111,   131,   112,    -1,
      19,   118,     5,   119,   113,    -1,    19,     5,   113,    -1,
       7,   118,   132,   119,   130,    -1,     7,   132,   130,    -1,
      11,   130,     7,   118,   132,   119,   113,    -1,     9,   118,
     132,    10,   132,   115,     4,   119,   130,    -1,    12,   113,
      -1,    13,   118,   132,   119,   130,    -1,    13,   118,   132,
     119,   130,    88,   130,    -1,     4,    47,   132,   113,    -1,
       6,    47,   132,   113,    -1,    63,     4,   115,   132,   113,
      -1,    63,     6,   115,   132,   113,    -1,    62,     4,   115,
     132,   113,    -1,    62,     6,   115,   132,   113,    -1,    64,
       4,   115,   132,   113,    -1,    64,     6,   115,   132,   113,
      -1,     4,    48,   132,    -1,     6,    48,   132,    -1,     4,
      46,   132,    -1,     6,    46,   132,    -1,     4,    49,   132,
      -1,     6,    49,   132,    -1,     4,    44,   132,    -1,     6,
      44,   132,    -1,     4,    45,   132,    -1,     6,    45,   132,
      -1,     4,    50,   132,    -1,     6,    50,   132,    -1,     4,
      51,   132,    -1,     6,    51,   132,    -1,     4,    53,   132,
      -1,     6,    53,   132,    -1,    85,   132,    -1,    -1,   130,
      -1,   131,   130,    -1,     3,    -1,     6,    -1,     5,    -1,
       4,    -1,   102,   132,    -1,   120,   132,    -1,   121,   132,
      -1,    30,   132,    -1,   132,   101,   132,    -1,   132,   102,
     132,    -1,   132,    27,   132,    -1,   132,    22,   132,    -1,
     132,   103,   132,    -1,   132,    28,   132,    -1,   132,   104,
     132,    -1,   132,    21,   132,    -1,   132,   116,   132,    -1,
     132,    25,   132,    -1,   132,    33,   132,    -1,   132,   122,
     132,    -1,   132,    23,   132,    -1,   132,    32,   132,    -1,
     132,   106,   132,    -1,   132,   107,   132,    -1,   132,   105,
     132,    -1,   132,    31,   132,    -1,   132,   100,   132,    -1,
     132,    24,   132,    -1,   132,    99,   132,    -1,   132,    26,
     132,    -1,   132,    97,   132,    -1,   132,    98,   132,    -1,
     132,    29,   132,    -1,   132,    90,   132,    -1,   132,    89,
     132,    -1,   132,   123,   132,    -1,   132,   124,   132,    -1,
     118,   132,   119,    -1,    14,   118,   119,    -1,    15,   118,
       5,   119,    -1,    20,   118,   119,    -1,    86,    -1,    65,
     118,   132,   119,    -1,    68,   118,   132,   119,    -1,    69,
     118,   132,   119,    -1,    70,   118,   132,   119,    -1,    71,
     118,   132,   119,    -1,    72,   118,   132,   119,    -1,    73,
     118,   132,   119,    -1,    74,   118,   132,   119,    -1,    75,
     118,   132,   119,    -1,    76,   118,   132,   119,    -1,    77,
     118,   132,   119,    -1,    78,   118,   132,   119,    -1,    79,
     118,   132,   119,    -1,    80,   118,   132,   119,    -1,    81,
     118,   132,   119,    -1,    67,   118,   132,   115,   132,   119,
      -1,    66,   118,   132,   119,    -1,    39,   118,     6,   119,
      -1,    39,   118,     4,   119,    -1,    40,   118,     6,   119,
      -1,    40,   118,     4,   119,    -1,   132,    38,   132,    -1,
     132,    35,   132,    -1,     4,   125,   102,    -1,     4,   125,
     101,    -1,    56,    55,    -1
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
     186,   190,   196,   200,   206,   210,   218,   228,   231,   237,
     245,   250,   255,   261,   267,   273,   279,   285,   291,   295,
     299,   303,   307,   311,   315,   319,   323,   327,   331,   335,
     339,   343,   347,   351,   355,   358,   359,   361,   364,   366,
     368,   370,   372,   375,   378,   381,   384,   388,   392,   396,
     400,   404,   408,   412,   416,   420,   424,   428,   432,   436,
     440,   444,   448,   452,   456,   460,   464,   468,   472,   476,
     480,   484,   488,   492,   496,   500,   504,   508,   513,   517,
     519,   524,   529,   534,   539,   544,   549,   554,   559,   564,
     569,   574,   579,   584,   589,   594,   601,   606,   611,   616,
     621,   626,   630,   634,   638,   642
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  YareParser::yyrline_[] =
  {
         0,   239,   239,   251,   254,   258,   263,   267,   270,   273,
     276,   279,   282,   285,   288,   291,   294,   297,   300,   303,
     306,   309,   312,   315,   318,   321,   324,   327,   330,   333,
     336,   339,   340,   341,   342,   343,   344,   345,   348,   351,
     354,   357,   360,   363,   366,   369,   372,   375,   378,   381,
     384,   387,   390,   393,   396,   399,   402,   405,   408,   411,
     414,   417,   420,   423,   426,   429,   432,   435,   438,   441,
     444,   447,   450,   453,   456,   459,   463,   466,   472,   475,
     483,   486,   489,   492,   495,   498,   501,   504,   507,   510,
     513,   516,   519,   522,   525,   528,   531,   534,   537,   540,
     543,   546,   549,   552,   555,   558,   561,   564,   567,   570,
     573,   576,   579,   582,   585,   588,   591,   594,   597,   600,
     603,   606,   609,   612,   615,   618,   621,   624,   627,   630,
     633,   636,   639,   642,   645,   648,   651,   654,   657,   660,
     663,   666,   669,   672,   675,   678
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
       2,     2,     2,   120,     2,     2,     2,   105,   123,     2,
     118,   119,   103,   101,   115,   102,   110,   104,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   113,
     116,   114,   122,   117,   125,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   106,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   111,   124,   112,   121,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   107,   108,   109
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int YareParser::yyeof_ = 0;
  const int YareParser::yylast_ = 4724;
  const int YareParser::yynnts_ = 7;
  const int YareParser::yyempty_ = -2;
  const int YareParser::yyfinal_ = 3;
  const int YareParser::yyterror_ = 1;
  const int YareParser::yyerrcode_ = 256;
  const int YareParser::yyntokens_ = 126;

  const unsigned int YareParser::yyuser_token_number_max_ = 358;
  const YareParser::token_number_type YareParser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 5 "yare.y"
} // YL

/* Line 1136 of lalr1.cc  */
#line 3386 "yare.tab.c"


/* Line 1138 of lalr1.cc  */
#line 682 "yare.y"


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

void yyerror(char *s) {
	cout << s << ", probable antes de la línea %d.\n" << endl;
}

void freeNode(nodeType *p) {
	int i;
	if (!p) 
		return;
	if (p->type == typeOpr) {
		for (i = 0; i < p->opr.nops; i++) 
			freeNode(p->opr.op[i]);
	}
	free(p);
}

// The run method executing the AST nodes:
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
					return 0.0f;

				case YL::YareParser::token::PUTS: {
					if((spLoop < 0) || pilaLoop[spLoop]) {
						cout << p->opr.op[0]->con.cadena << endl;
					}
					return 0.0f;	
				}

				case YL::YareParser::token::CALL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						// cout << "Intentando ejecutar: " << p->opr.op[0]->id.identificador << endl;
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
						return sym[p->opr.op[0]->id.i] = run(p->opr.op[1]);	
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
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sqrt(run(p->opr.op[0]));
					return 0.0L;
				case YL::YareParser::token::ACOS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return acos(run(p->opr.op[0]));
					return 0.0L;
				case YL::YareParser::token::ASIN:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return asin(run(p->opr.op[0]));
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
						return 0.0f;
				case YL::YareParser::token::LN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(run(p->opr.op[0]) <= 0.0) {
							cerr << "Aviso: cuando x tiende a 0 se vuelve infinito ...\n";
							return 0.0f;
						}
						return log(run(p->opr.op[0]));
					} else
						return 0.0f;

				case YL::YareParser::token::SIN:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sin(run(p->opr.op[0]));
					else
						return 0.0f;

				case YL::YareParser::token::SINH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sinh(run(p->opr.op[0]));
					else
						return 0.0f;

				case YL::YareParser::token::TAN:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return tan(run(p->opr.op[0]));
					else
						return 0.0f;

				case YL::YareParser::token::TANH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return tanh(run(p->opr.op[0]));
					else
						return 0.0f;

				case YL::YareParser::token::SUMATORIA:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sumatoria((short)run(p->opr.op[0]), (short)run(p->opr.op[1]));
					else
						return 0.0f;

				case YL::YareParser::token::FACTORIAL:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return factorial((long)run(p->opr.op[0]));
					else
						return 0.0f;

				////// Código para la pila Virtual:
				case YL::YareParser::token::PUSH:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(pila == NULL) {
							pila = new Pila();
							// pila->mostrar();
							pila->add(run(p->opr.op[0]));
						} else {
							pila->add(run(p->opr.op[0]));
							// pila->mostrar();
						}
						return 0.0f;
					}
					return 0.0f;

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
					return 0.0f;
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
					return 0.0f;

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
					return 0.0f;

				case YL::YareParser::token::FACE_NO:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(p->opr.op[0]->type == typeId) {
							return sym[p->opr.op[0]->id.i] = 0.0f;
						} else if(p->opr.op[0]->type == typeVar) {
							if(vars == NULL) {
								cerr << "La variable '" << p->opr.op[0]->id.identificador << "' no se encuentra declarada.\n";
								exit(EXIT_FAILURE);
							} else {
								if(vars->isDefined(p->opr.op[0]->id.identificador)) {
									vars->getVarByIndex(vars->getIndex(p->opr.op[0]->id.identificador)).setLongValue(0.0f);
								}
							}
						}
					}
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
					return 0.0f;

				case YL::YareParser::token::READ:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						
						char _temp[100];
						char *_end;
						unsigned short _index = 0;
						unsigned char _c;
						// SHIT
						long double _resultado;
						
						while((_c = getchar()) != '\n') 
							_temp[_index++] = _c;
						
						_temp[_index] = '\0';
	
						_resultado = check(_temp, &_end);
						if(*_end != '\0') {
							return -1.0f;//(sym[p->opr.op[0]->id.i] = -1);
						} else {
							return _resultado; //(sym[p->opr.op[0]->id.i] = _resultado);
						}
					}

				case YL::YareParser::token::READP:
					
					if((spLoop < 0) || pilaLoop[spLoop]) {
						
						cout << p->opr.op[0]->con.cadena;

						char _temp[100];
						char *_end;
						unsigned short _index = 0;
						unsigned char _c;
						// SHIT
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
					return 0.0f;
				case YL::YareParser::token::PRASCII:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						std::cout << (char)getAscii(run(p->opr.op[0]));
					}
					return 0.0f;

				case YL::YareParser::token::FOREACH:
					std::cout << "Entra aquí ... " << std::endl;
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

					return 0.0f;
			}
			default:
					break;
	}
	return 0.0f;
}

long double validateInput(char *s, bool &result) {
    std::istringstream test(s);

    long double value;
    std::string rest;

    if (!(test >> value) || (test >> rest)) {
        result = false;
        return 0.0f;
    } else {
        result = true;
        return value;
    }
}

unsigned short int getAscii(long long valor) {
	/* PENDIENTE Ponerlo en forma sexy: */
	if((valor >= 0) && (valor <= 255))
		return valor;
	else
		return (valor % 255);
}

