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
	
	// The symbol table:
	long double sym[26];
	Variables *vars = NULL;
	Pila *pila = NULL;
	struct proc *procs = NULL;


/* Line 293 of lalr1.cc  */
#line 58 "yare.tab.c"


#include "yare.tab.h"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 67 "yare.tab.c"
/* Unqualified %code blocks.  */

/* Line 300 of lalr1.cc  */
#line 34 "yare.y"

	using std::endl;
	using std::cout;
	using std::cerr;

	static int yylex(YL::YareParser::semantic_type * yylval, YL::FlexScanner &scanner);
	
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



/* Line 300 of lalr1.cc  */
#line 122 "yare.tab.c"

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
#line 210 "yare.tab.c"

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
#line 221 "yare.y"
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
#line 233 "yare.y"
    {
		push_l_proc(&procs, (yysemantic_stack_[(6) - (3)].nameFunction), (yysemantic_stack_[(6) - (5)].nPtr));
}
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 236 "yare.y"
    {;}
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 240 "yare.y"
    { 
		run((yysemantic_stack_[(2) - (2)].nPtr));			/* Ejecutar los nodos */ 
		freeNode((yysemantic_stack_[(2) - (2)].nPtr)); 	/* Liberar los nodos */

	}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 245 "yare.y"
    {;}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 249 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, NULL, NULL); 
	}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 252 "yare.y"
    { 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 255 "yare.y"
    {		// x to 1 + 2; 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 258 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (4)].sIndex)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 261 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (4)].identificador)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 264 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 267 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 270 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 273 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 276 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 279 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 282 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 285 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 288 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 291 "yare.y"
    { 	// :x: to 1 + 2;
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 294 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 297 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 300 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, id((yysemantic_stack_[(4) - (1)].sIndex)));
	}
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 303 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, idS((yysemantic_stack_[(4) - (1)].identificador)));
	}
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 306 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 309 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 312 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 315 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 318 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(2) - (1)].nPtr); 
	}
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 321 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 322 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 323 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, id((yysemantic_stack_[(4) - (1)].sIndex))); }
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 324 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_HAPPY, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 325 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_SAD, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 326 "yare.y"
    { (yyval.nPtr) = opr(YL::YareParser::token::FACE_NO, 1, idS((yysemantic_stack_[(4) - (1)].identificador))); }
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 327 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINTN, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 330 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINT, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 333 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 336 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 339 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 342 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 345 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DO_WHILE, 2, (yysemantic_stack_[(7) - (2)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr));
	}
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 348 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::BREAK, 0);
	}
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 351 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 354 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 3, (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr), (yysemantic_stack_[(7) - (7)].nPtr)); 
	}
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 357 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 360 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 363 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 366 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 369 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 372 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 375 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 378 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 381 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 384 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 387 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 390 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 393 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 396 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 399 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 402 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 405 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 408 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 411 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 414 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 417 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 420 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 423 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 426 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 429 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUSH, 1, (yysemantic_stack_[(2) - (2)].nPtr));	
	}
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 432 "yare.y"
    {;}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 436 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(1) - (1)].nPtr); 
	}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 439 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, (yysemantic_stack_[(2) - (1)].nPtr), (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 445 "yare.y"
    {
		(yyval.nPtr) = con((yysemantic_stack_[(1) - (1)].valnum));
	}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 448 "yare.y"
    { 
		if(vars == NULL) {
			cout << "La variable '" << (yysemantic_stack_[(1) - (1)].identificador) << "' no ha sido declarada";
			exit(EXIT_FAILURE);
		} else {
			(yyval.nPtr) = idS((yysemantic_stack_[(1) - (1)].identificador));	
		}
	}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 456 "yare.y"
    {
		(yyval.nPtr) = conStr((yysemantic_stack_[(1) - (1)].cadena), typeCadena);
	}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 459 "yare.y"
    { 
		(yyval.nPtr) = id((yysemantic_stack_[(1) - (1)].sIndex)); 
	}
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 462 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::UMINUS, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 465 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 468 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 471 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 474 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 477 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 480 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 483 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 486 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 489 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 492 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 495 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 498 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 501 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 504 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 507 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 510 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 513 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 516 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 519 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 522 "yare.y"
    { 
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 525 "yare.y"
    {
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 528 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 531 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 534 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 537 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 540 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 543 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 546 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 549 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::AND, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 552 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OR, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 555 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ANDBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 558 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ORBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 561 "yare.y"
    {
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr);
	}
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 564 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RAND, 0);
	}
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 567 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::POP, 0);
	}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 570 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ABS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 573 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SQRT, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 576 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ACOS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 579 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ASIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 582 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 585 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CEIL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 588 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 591 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COSH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 594 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXP, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 597 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FLOOR, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 600 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::LN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 603 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 606 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SINH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 609 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 612 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 615 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SUMATORIA, 2, (yysemantic_stack_[(6) - (3)].nPtr), (yysemantic_stack_[(6) - (5)].nPtr));	
	}
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 618 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FACTORIAL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 621 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 624 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 627 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 630 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 633 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::XOROP, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 636 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RANGE_RANDOM, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 639 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 642 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 645 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CALL, 1, idS((yysemantic_stack_[(2) - (2)].nameFunction)));
	}
    break;



/* Line 690 of lalr1.cc  */
#line 1719 "yare.tab.c"
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
  const signed char YareParser::yypact_ninf_ = -92;
  const short int
  YareParser::yypact_[] =
  {
       -92,    10,   -36,   -92,   -18,   178,   -72,   -92,   786,   -92,
     891,   -78,   486,   -71,   -77,   -74,   -70,     9,   -66,   736,
     -65,   -64,    -9,    -3,   736,    -2,    11,    14,    15,   -63,
     -50,   -48,   -27,   -26,   -22,   -20,   -19,   -14,   -13,   -12,
     -11,   -10,    12,    13,    43,    49,   736,   -92,   736,   -92,
     486,   -92,   736,   736,   736,   -92,   762,   486,    19,   736,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
     570,   -55,   -91,    20,   736,   736,   736,   736,   736,   736,
     736,   736,   736,   736,   736,   653,     7,   736,    88,   -92,
     736,   736,   736,    16,   118,    51,    47,   -92,    55,    23,
      24,   -92,   -45,   -31,   866,    17,    53,    58,    61,    65,
      69,    76,    84,   736,   736,   736,   736,   736,   736,   736,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
    3666,    55,   -92,   308,   894,    55,    55,   736,   736,   736,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
     736,   736,   736,   736,   736,   736,   736,   736,   736,   736,
     736,   736,   736,   736,   -92,   736,   736,   736,   736,   397,
      87,    89,  3666,  3666,  3666,   998,  3666,  3666,  3666,  3666,
    3666,  1026,  3666,    90,    91,    92,    94,  1130,   736,   -92,
     -92,    96,    97,  3666,  3666,  3666,  1158,  3666,  3666,  3666,
    3666,  3666,  1262,  3666,    98,    99,   100,   101,  1290,   736,
    1394,    56,  1422,  1526,  1554,   -92,    82,   -92,   104,   113,
     114,   117,   736,   736,   736,   736,    27,   736,   736,   736,
     736,   736,   736,   736,   736,  1658,  1686,  1790,  1818,  1922,
    1950,  2054,  2082,  2186,  2214,  2318,  2346,  2450,  2478,  2582,
    2610,  2714,   -92,   -92,   -92,   318,   417,   239,   239,   239,
     239,   417,   318,   239,   -21,   239,   239,  3666,  3666,  3770,
    3826,   239,   239,   239,   239,   417,   417,   318,   318,   -21,
      59,    55,  3666,  3666,  3666,  3666,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,  3798,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,  3798,   486,   736,   486,
     102,   103,   125,   -92,   -92,   -92,   -92,  2742,  2846,  2874,
    2978,   -92,   -92,  3006,  3110,  3138,  3242,  3270,  3374,  3402,
    3506,   -92,   -92,   736,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,  3534,
     174,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,  3638,   152,   486,   -92,
     -92,   -92
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  YareParser::yydefact_[] =
  {
         4,     0,     6,     1,     0,     0,     0,    75,    78,    77,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     2,
      72,     7,     0,     0,     0,     5,     0,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,    78,    76,    82,     0,
       0,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    79,    73,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,    61,    63,    57,     0,    55,    59,    65,    67,
      69,     0,    16,     0,     0,     0,     0,     0,     0,   139,
     138,     0,     0,    62,    64,    58,     0,    56,    60,    66,
      68,    70,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    74,   112,    90,    86,    95,   102,    92,
     104,    85,    88,   107,   100,    96,    93,   137,   136,   109,
     108,   105,   106,   103,   101,    83,    84,    87,    89,    99,
      97,    98,    91,    94,   110,   111,     3,    26,    28,    47,
       9,    31,    32,    33,    24,     8,    14,    27,    29,    48,
      21,    34,    35,    36,    25,    20,    15,    72,     0,    72,
       0,     0,     0,   133,   132,   135,   134,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   131,     0,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,    42,     0,
      45,    37,    38,    40,    19,    18,    23,    22,    12,    13,
      51,    52,    49,    50,    53,    54,     0,     0,    72,   130,
      43,    46
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  YareParser::yypgoto_[] =
  {
       -92,   -92,   -92,   -92,    -5,   206,    -8
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  YareParser::yydefgoto_[] =
  {
        -1,     1,     2,     5,   132,   133,    56
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char YareParser::yytable_ninf_ = -1;
  const unsigned short int
  YareParser::yytable_[] =
  {
        55,   102,   105,   103,   106,   189,   190,    88,   222,   149,
       3,    98,   150,     4,    93,   107,   104,   108,   109,   111,
     110,   112,   224,   170,   191,   171,   192,   218,   220,   219,
     221,   321,     6,   322,    57,    87,    90,    89,   130,    91,
     131,   101,   188,    92,   134,   135,   136,    95,    99,   100,
     113,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   187,   114,   223,   115,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   208,   225,   210,
     162,   163,   212,   213,   214,   149,   116,   117,   150,   149,
     165,   118,   150,   119,   120,   211,   166,   167,   168,   121,
     122,   123,   124,   125,   209,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,    94,   216,   215,   126,   127,   227,   253,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   128,   282,   283,   284,
     285,   163,   129,   228,   253,   217,   165,    72,   229,   308,
     165,   230,   166,   167,   168,   231,   166,   167,   168,   232,
     296,     7,     8,     9,    10,    11,   233,    12,    13,    14,
      15,    16,    17,    18,   234,   287,   312,   288,   291,   292,
     293,   306,   294,    19,   297,   298,   301,   302,   303,   304,
     351,   352,    20,    21,   317,   318,   319,   320,   313,   323,
     324,   325,   326,   327,   328,   329,   330,   314,   315,    22,
      23,   316,    24,   353,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,   137,   138,   368,    46,    47,
     370,   143,   144,   169,     0,   146,     0,     0,     0,   149,
       0,     0,   150,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,    49,    50,     0,    51,     0,     0,     0,
       0,    52,     0,    53,    54,     0,     0,     0,     0,     0,
     349,     0,   348,     0,   350,     0,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,     0,   366,     0,     0,     0,     0,
       0,     0,     0,    19,     0,   157,   158,   159,   160,   161,
     162,   163,    20,    21,   146,     0,     0,     0,   149,     0,
     165,   150,     0,     0,     0,     0,   166,   167,   168,    22,
      23,     0,    24,   371,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     9,    10,    11,    48,    12,    13,    14,    15,
      16,    17,    18,     0,    50,   252,    51,     0,   161,   162,
     163,    52,    19,    53,    54,     0,     0,     0,     0,   165,
       0,    20,    21,   137,     0,   166,   167,   168,     0,     0,
     144,     0,     0,   146,     0,     0,     0,   149,    22,    23,
     150,    24,     0,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,     0,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     9,    10,    11,    48,    12,    13,    14,    15,    16,
      17,    18,     0,    50,   286,    51,     0,     0,     0,     0,
      52,    19,    53,    54,     0,   159,   160,   161,   162,   163,
      20,    21,     0,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,     0,   166,   167,   168,    22,    23,     0,
      24,     0,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,     0,     0,    46,    47,     0,     0,
       0,     0,     0,     7,    96,     9,    97,     0,     0,     0,
       0,     0,     0,    48,     0,    18,     0,     0,     0,     0,
       0,     0,    50,     0,    51,    19,     0,     0,     0,    52,
       0,    53,    54,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,   183,   184,   185,
       0,    47,     0,     0,     0,     0,     7,    96,     9,    97,
       0,     0,     0,     0,     0,     0,     0,    48,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,   186,    52,     0,    53,    54,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     204,   205,   206,     0,    47,     0,     0,     0,     0,     7,
      96,     9,    97,     0,     0,     0,     0,     0,     0,     0,
      48,    18,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,   207,    52,     0,    53,    54,
      20,    21,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    22,   146,   147,
     148,     0,   149,     0,     0,   150,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,     0,     0,     0,    47,    58,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    48,    67,     0,     0,     0,     0,    68,
       0,    69,     0,     0,     0,     0,   151,   152,     0,    52,
       0,    53,    54,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
     164,     0,     0,   165,     0,     0,     0,     0,     0,   166,
     167,   168,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,    70,   149,    71,     0,   150,
       0,     0,     0,     0,     0,     0,    72,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   226,
     146,   147,   148,    73,   149,     0,     0,   150,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,     0,    82,
       0,     0,     0,     0,    83,     0,    84,     0,     0,     0,
     151,   152,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   151,   152,
       0,     0,     0,   166,   167,   168,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
      85,     0,    86,     0,     0,   165,     0,     0,   254,     0,
       0,   166,   167,   168,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,   289,     0,     0,   165,
     151,   152,     0,     0,     0,   166,   167,   168,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,   290,     0,     0,   165,     0,     0,
       0,     0,     0,   166,   167,   168,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,   295,     0,
       0,   165,   151,   152,     0,     0,     0,   166,   167,   168,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,   299,     0,     0,   165,
       0,     0,     0,     0,     0,   166,   167,   168,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
     300,     0,     0,   165,   151,   152,     0,     0,     0,   166,
     167,   168,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,   305,     0,
       0,   165,     0,     0,     0,     0,     0,   166,   167,   168,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   151,   152,   307,     0,
       0,   166,   167,   168,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,   309,     0,     0,   166,
     167,   168,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   151,   152,
     310,     0,     0,   166,   167,   168,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,   311,     0,
       0,   166,   167,   168,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     151,   152,   331,     0,     0,   166,   167,   168,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
     332,     0,     0,   166,   167,   168,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,     0,     0,
     333,   165,   151,   152,     0,     0,     0,   166,   167,   168,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,     0,   334,     0,     0,   166,   167,   168,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   151,   152,   335,     0,     0,   166,
     167,   168,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,   336,     0,     0,   166,   167,   168,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   151,   152,   337,     0,
       0,   166,   167,   168,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,   338,     0,     0,   166,
     167,   168,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   151,   152,
     339,     0,     0,   166,   167,   168,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,   340,     0,
       0,   166,   167,   168,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     151,   152,   341,     0,     0,   166,   167,   168,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
     342,     0,     0,   166,   167,   168,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   151,   152,   343,     0,     0,   166,   167,   168,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,     0,   344,     0,     0,   166,   167,   168,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   151,   152,   345,     0,     0,   166,
     167,   168,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,   165,     0,     0,   346,     0,     0,   166,   167,   168,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   151,   152,   347,     0,
       0,   166,   167,   168,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
     354,     0,     0,   165,     0,     0,     0,     0,     0,   166,
     167,   168,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,   355,     0,     0,   165,   151,   152,
       0,     0,     0,   166,   167,   168,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,   356,     0,     0,   165,     0,     0,     0,     0,
       0,   166,   167,   168,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,   357,     0,     0,   165,
     151,   152,     0,     0,     0,   166,   167,   168,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,   358,     0,     0,   165,     0,     0,
       0,     0,     0,   166,   167,   168,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,   152,     0,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,   359,     0,
       0,   165,   151,   152,     0,     0,     0,   166,   167,   168,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,   360,     0,     0,   165,
       0,     0,     0,     0,     0,   166,   167,   168,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,   152,     0,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
     361,     0,     0,   165,   151,   152,     0,     0,     0,   166,
     167,   168,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,   362,     0,
       0,   165,     0,     0,     0,     0,     0,   166,   167,   168,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   146,   147,
     148,     0,   149,     0,     0,   150,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   151,   152,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,   363,     0,     0,   165,   151,   152,     0,     0,
       0,   166,   167,   168,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,     0,     0,     0,     0,
     364,     0,     0,   165,     0,     0,     0,     0,     0,   166,
     167,   168,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     0,
     146,   147,   148,     0,   149,     0,     0,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   152,     0,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,   365,     0,     0,   165,   151,   152,
       0,     0,     0,   166,   167,   168,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   165,     0,     0,   367,     0,
       0,   166,   167,   168,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,     0,   149,     0,     0,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   151,   152,     0,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     151,   152,   369,     0,     0,   166,   167,   168,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,     0,     0,   166,   167,   168,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   146,   147,   148,     0,
     149,     0,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   138,   139,   140,   141,   142,
     143,   144,   145,     0,   146,   147,   148,     0,   149,     0,
       0,   150,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,   152,   149,     0,     0,   150,
       0,     0,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   151,   152,     0,     0,     0,   166,   167,   168,
     153,   154,   155,   156,   157,     0,   159,   160,   161,   162,
     163,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,     0,     0,     0,     0,   166,   167,   168,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
       0,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,     0,     0,   166,   167,   168
  };

  /* YYCHECK.  */
  const short int
  YareParser::yycheck_[] =
  {
         5,     4,     4,     6,     6,    96,    97,    12,    53,    30,
       0,    19,    33,    49,     5,     4,    24,     6,     4,     4,
       6,     6,    53,     4,     4,     6,     6,     4,     4,     6,
       6,     4,    50,     6,   106,   113,   113,   108,    46,   113,
      48,    50,    97,   113,    52,    53,    54,   113,   113,   113,
     113,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,   113,   109,   113,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   109,    87,
     101,   102,    90,    91,    92,    30,   113,   113,    33,    30,
     111,   113,    33,   113,   113,     7,   117,   118,   119,   113,
     113,   113,   113,   113,    97,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   113,     5,   108,   113,   113,   110,   133,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   113,   165,   166,   167,
     168,   102,   113,   110,   169,   114,   111,   120,   110,   113,
     111,   110,   117,   118,   119,   110,   117,   118,   119,   110,
     188,     3,     4,     5,     6,     7,   110,     9,    10,    11,
      12,    13,    14,    15,   110,   108,   114,   108,   108,   108,
     108,   209,   108,    25,   108,   108,   108,   108,   108,   108,
     108,   108,    34,    35,   222,   223,   224,   225,   114,   227,
     228,   229,   230,   231,   232,   233,   234,   114,   114,    51,
      52,   114,    54,   108,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    16,    17,    83,    80,    81,
     108,    22,    23,    57,    -1,    26,    -1,    -1,    -1,    30,
      -1,    -1,    33,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,   108,    -1,    -1,    -1,
      -1,   113,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,
     308,    -1,   307,    -1,   309,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,   333,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    96,    97,    98,    99,   100,
     101,   102,    34,    35,    26,    -1,    -1,    -1,    30,    -1,
     111,    33,    -1,    -1,    -1,    -1,   117,   118,   119,    51,
      52,    -1,    54,   368,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    97,     9,    10,    11,    12,
      13,    14,    15,    -1,   106,   107,   108,    -1,   100,   101,
     102,   113,    25,   115,   116,    -1,    -1,    -1,    -1,   111,
      -1,    34,    35,    16,    -1,   117,   118,   119,    -1,    -1,
      23,    -1,    -1,    26,    -1,    -1,    -1,    30,    51,    52,
      33,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    97,     9,    10,    11,    12,    13,
      14,    15,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,
     113,    25,   115,   116,    -1,    98,    99,   100,   101,   102,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,
      -1,    -1,    -1,    -1,   117,   118,   119,    51,    52,    -1,
      54,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    80,    81,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,   106,    -1,   108,    25,    -1,    -1,    -1,   113,
      -1,   115,   116,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    81,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,   112,   113,    -1,   115,   116,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    81,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,   112,   113,    -1,   115,   116,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    51,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    81,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    97,    48,    -1,    -1,    -1,    -1,    53,
      -1,    55,    -1,    -1,    -1,    -1,    84,    85,    -1,   113,
      -1,   115,   116,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,   109,    30,   111,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    53,
      26,    27,    28,    32,    30,    -1,    -1,    33,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    84,    85,
      -1,    -1,    -1,   117,   118,   119,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     109,    -1,   111,    -1,    -1,   111,    -1,    -1,   114,    -1,
      -1,   117,   118,   119,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
      84,    85,    -1,    -1,    -1,   117,   118,   119,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,   111,    84,    85,    -1,    -1,    -1,   117,   118,   119,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,   111,    84,    85,    -1,    -1,    -1,   117,
     118,   119,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    84,    85,   114,    -1,
      -1,   117,   118,   119,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,   114,    -1,    -1,   117,
     118,   119,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    84,    85,
     114,    -1,    -1,   117,   118,   119,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,    -1,
      -1,   117,   118,   119,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      84,    85,   114,    -1,    -1,   117,   118,   119,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
     114,    -1,    -1,   117,   118,   119,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,    84,    85,    -1,    -1,    -1,   117,   118,   119,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,    -1,    -1,   117,   118,   119,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    84,    85,   114,    -1,    -1,   117,
     118,   119,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,   114,    -1,    -1,   117,   118,   119,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    84,    85,   114,    -1,
      -1,   117,   118,   119,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,   114,    -1,    -1,   117,
     118,   119,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    84,    85,
     114,    -1,    -1,   117,   118,   119,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,    -1,
      -1,   117,   118,   119,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      84,    85,   114,    -1,    -1,   117,   118,   119,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
     114,    -1,    -1,   117,   118,   119,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    84,    85,   114,    -1,    -1,   117,   118,   119,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,    -1,    -1,   117,   118,   119,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    84,    85,   114,    -1,    -1,   117,
     118,   119,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    -1,    -1,   114,    -1,    -1,   117,   118,   119,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    84,    85,   114,    -1,
      -1,   117,   118,   119,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    84,    85,
      -1,    -1,    -1,   117,   118,   119,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,   117,   118,   119,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
      84,    85,    -1,    -1,    -1,   117,   118,   119,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,   111,    84,    85,    -1,    -1,    -1,   117,   118,   119,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,   111,    84,    85,    -1,    -1,    -1,   117,
     118,   119,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,   111,    84,    85,    -1,    -1,
      -1,   117,   118,   119,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,   111,    84,    85,
      -1,    -1,    -1,   117,   118,   119,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,   114,    -1,
      -1,   117,   118,   119,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      84,    85,   114,    -1,    -1,   117,   118,   119,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    85,    30,    -1,    -1,    33,
      -1,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,    84,    85,    -1,    -1,    -1,   117,   118,   119,
      92,    93,    94,    95,    96,    -1,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  YareParser::yystos_[] =
  {
         0,   122,   123,     0,    49,   124,    50,     3,     4,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    15,    25,
      34,    35,    51,    52,    54,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    80,    81,    97,   105,
     106,   108,   113,   115,   116,   125,   127,   106,    32,    39,
      40,    41,    42,    43,    44,    45,    46,    48,    53,    55,
     109,   111,   120,    32,    39,    40,    41,    42,    43,    44,
      45,    46,    48,    53,    55,   109,   111,   113,   125,   108,
     113,   113,   113,     5,   113,   113,     4,     6,   127,   113,
     113,    50,     4,     6,   127,     4,     6,     4,     6,     4,
       6,     4,     6,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     127,   127,   125,   126,   127,   127,   127,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    26,    27,    28,    30,
      33,    84,    85,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   108,   111,   117,   118,   119,   126,
       4,     6,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,    77,    78,    79,   112,   127,    97,    96,
      97,     4,     6,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,    77,    78,    79,   112,   127,    97,
     127,     7,   127,   127,   127,   108,     5,   114,     4,     6,
       4,     6,    53,   109,    53,   109,    53,   110,   110,   110,
     110,   110,   110,   110,   110,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   107,   125,   114,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   127,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   127,   114,   113,   114,
     114,   114,   114,   114,   114,   114,   114,   127,   127,   127,
     127,     4,     6,   127,   127,   127,   127,   127,   127,   127,
     127,   114,   114,   110,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   125,   127,
     125,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   127,   114,    83,   114,
     108,   125
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
     345,   346,   347,   348,   349,   350,    43,    45,    42,    47,
      37,    94,   351,   352,   353,    46,   123,   125,    59,    61,
      44,    60,    63,    40,    41,    33,   126,    62,    38,   124,
      64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  YareParser::yyr1_[] =
  {
         0,   121,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  YareParser::yyr2_[] =
  {
         0,     2,     3,     6,     0,     2,     0,     1,     4,     4,
       4,     4,     5,     5,     4,     4,     3,     3,     5,     5,
       4,     4,     5,     5,     4,     4,     4,     4,     4,     4,
       2,     4,     4,     4,     4,     4,     4,     5,     5,     3,
       5,     3,     5,     7,     2,     5,     7,     4,     4,     5,
       5,     5,     5,     5,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     0,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     4,     4,     4,     3,     3,     3,     3,
       2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const YareParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMERIC", "VARIABLE", "CADENA", "ID",
  "WHILE", "DO_WHILE", "DO", "BREAK", "IF", "PRINTN", "PRINT", "PUTS",
  "RAND", "EXPR_DIV", "EXPR_MAS", "EXPR_MAYOR", "EXPR_MAYORIGUAL",
  "EXPR_MENOR", "EXPR_MENORIGUAL", "EXPR_MENOS", "EXPR_MUL", "EXPR_IGUAL",
  "EXPR_NOT", "MOD_WORD", "_GT_", "_LT_", "INIT_RANDOM", "RANGE_RANDOM",
  "SWAP_ID_VAR", "SWAP_OP", "XOROP", "DEC", "INC", "DEC_CPP", "INC_CPP",
  "ID_ASIGNACION", "OP_ASIGN_ABR_MUL", "OP_ASIGN_ABR_DIV",
  "OP_ASIGN_ABR_MOD", "OP_ASIGN_ABR_MAS", "OP_ASIGN_ABR_MENOS",
  "OP_ASIGN_ABR_SHIFTLEFT", "OP_ASIGN_ABR_SHIFTRIGHT", "OP_ASIGN_ABR_AND",
  "OP_ASIGN_ABR_OR", "OP_ASIGN_ABR_POW", "PROC", "FUNCNAME", "CALL",
  "LETSET_ASSIGN", "TO", "MOVE", "PASCAL_ASSIGN", "MOV_ASM", "SUB_ASM",
  "ADD_ASM", "MUL_ASM", "ABS", "FACTORIAL", "SUMATORIA", "SQRT", "ACOS",
  "ASIN", "ATAN", "CEIL", "COS", "COSH", "EXP", "FLOOR", "LN", "SIN",
  "SINH", "TAN", "TANH", "FACE_HAPPY", "FACE_SAD", "FACE_NO", "PUSH",
  "POP", "IFX", "ELSE", "OR", "AND", "SHIFTRIGHT", "SHIFTLEFT", "ANDBITS",
  "ORBITS", "LT", "GT", "NE", "EQ", "LE", "GE", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'^'", "EXPR_ELEVADO", "NEGACION", "UMINUS", "'.'", "'{'", "'}'",
  "';'", "'='", "','", "'<'", "'?'", "'('", "')'", "'!'", "'~'", "'>'",
  "'&'", "'|'", "'@'", "$accept", "program", "funciones", "cuerpo", "stmt",
  "stmt_list", "expr", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const YareParser::rhs_number_type
  YareParser::yyrhs_[] =
  {
       122,     0,    -1,   123,   124,   105,    -1,   123,    49,    50,
     106,   126,   107,    -1,    -1,   124,   125,    -1,    -1,   108,
      -1,     4,   109,   127,   108,    -1,     4,    53,   127,   108,
      -1,    54,   127,    53,     4,    -1,    54,   127,    53,     6,
      -1,    56,     4,   110,   127,   108,    -1,    56,     6,   110,
     127,   108,    -1,     4,   111,    97,   127,    -1,     6,   111,
      97,   127,    -1,     4,    55,   127,    -1,     6,    55,   127,
      -1,    52,     4,   109,   127,   108,    -1,    52,     4,    53,
     127,   108,    -1,     6,   109,   127,   108,    -1,     6,    53,
     127,   108,    -1,    52,     6,   109,   127,   108,    -1,    52,
       6,    53,   127,   108,    -1,     4,   109,   112,   108,    -1,
       6,   109,   112,   108,    -1,     4,    32,     4,   108,    -1,
       6,    32,     4,   108,    -1,     4,    32,     6,   108,    -1,
       6,    32,     6,   108,    -1,   127,   108,    -1,     4,   109,
      77,   108,    -1,     4,   109,    78,   108,    -1,     4,   109,
      79,   108,    -1,     6,   109,    77,   108,    -1,     6,   109,
      78,   108,    -1,     6,   109,    79,   108,    -1,    12,   113,
     127,   114,   108,    -1,    13,   113,   127,   114,   108,    -1,
     106,   126,   107,    -1,    14,   113,     5,   114,   108,    -1,
      14,     5,   108,    -1,     7,   113,   127,   114,   125,    -1,
       9,   125,     7,   113,   127,   114,   108,    -1,    10,   108,
      -1,    11,   113,   127,   114,   125,    -1,    11,   113,   127,
     114,   125,    83,   125,    -1,     4,    42,   127,   108,    -1,
       6,    42,   127,   108,    -1,    58,     4,   110,   127,   108,
      -1,    58,     6,   110,   127,   108,    -1,    57,     4,   110,
     127,   108,    -1,    57,     6,   110,   127,   108,    -1,    59,
       4,   110,   127,   108,    -1,    59,     6,   110,   127,   108,
      -1,     4,    43,   127,    -1,     6,    43,   127,    -1,     4,
      41,   127,    -1,     6,    41,   127,    -1,     4,    44,   127,
      -1,     6,    44,   127,    -1,     4,    39,   127,    -1,     6,
      39,   127,    -1,     4,    40,   127,    -1,     6,    40,   127,
      -1,     4,    45,   127,    -1,     6,    45,   127,    -1,     4,
      46,   127,    -1,     6,    46,   127,    -1,     4,    48,   127,
      -1,     6,    48,   127,    -1,    80,   127,    -1,    -1,   125,
      -1,   126,   125,    -1,     3,    -1,     6,    -1,     5,    -1,
       4,    -1,    97,   127,    -1,   115,   127,    -1,   116,   127,
      -1,    25,   127,    -1,   127,    96,   127,    -1,   127,    97,
     127,    -1,   127,    22,   127,    -1,   127,    17,   127,    -1,
     127,    98,   127,    -1,   127,    23,   127,    -1,   127,    99,
     127,    -1,   127,    16,   127,    -1,   127,   111,   127,    -1,
     127,    20,   127,    -1,   127,    28,   127,    -1,   127,   117,
     127,    -1,   127,    18,   127,    -1,   127,    27,   127,    -1,
     127,   101,   127,    -1,   127,   102,   127,    -1,   127,   100,
     127,    -1,   127,    26,   127,    -1,   127,    95,   127,    -1,
     127,    19,   127,    -1,   127,    94,   127,    -1,   127,    21,
     127,    -1,   127,    92,   127,    -1,   127,    93,   127,    -1,
     127,    24,   127,    -1,   127,    85,   127,    -1,   127,    84,
     127,    -1,   127,   118,   127,    -1,   127,   119,   127,    -1,
     113,   127,   114,    -1,    15,   113,   114,    -1,    81,    -1,
      60,   113,   127,   114,    -1,    63,   113,   127,   114,    -1,
      64,   113,   127,   114,    -1,    65,   113,   127,   114,    -1,
      66,   113,   127,   114,    -1,    67,   113,   127,   114,    -1,
      68,   113,   127,   114,    -1,    69,   113,   127,   114,    -1,
      70,   113,   127,   114,    -1,    71,   113,   127,   114,    -1,
      72,   113,   127,   114,    -1,    73,   113,   127,   114,    -1,
      74,   113,   127,   114,    -1,    75,   113,   127,   114,    -1,
      76,   113,   127,   114,    -1,    62,   113,   127,   110,   127,
     114,    -1,    61,   113,   127,   114,    -1,    34,   113,     6,
     114,    -1,    34,   113,     4,   114,    -1,    35,   113,     6,
     114,    -1,    35,   113,     4,   114,    -1,   127,    33,   127,
      -1,   127,    30,   127,    -1,     4,   120,    97,    -1,     4,
     120,    96,    -1,    51,    50,    -1
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
     184,   190,   194,   200,   208,   211,   217,   225,   230,   235,
     241,   247,   253,   259,   265,   271,   275,   279,   283,   287,
     291,   295,   299,   303,   307,   311,   315,   319,   323,   327,
     331,   335,   338,   339,   341,   344,   346,   348,   350,   352,
     355,   358,   361,   364,   368,   372,   376,   380,   384,   388,
     392,   396,   400,   404,   408,   412,   416,   420,   424,   428,
     432,   436,   440,   444,   448,   452,   456,   460,   464,   468,
     472,   476,   480,   484,   488,   490,   495,   500,   505,   510,
     515,   520,   525,   530,   535,   540,   545,   550,   555,   560,
     565,   572,   577,   582,   587,   592,   597,   601,   605,   609,
     613
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  YareParser::yyrline_[] =
  {
         0,   221,   221,   233,   236,   240,   245,   249,   252,   255,
     258,   261,   264,   267,   270,   273,   276,   279,   282,   285,
     288,   291,   294,   297,   300,   303,   306,   309,   312,   315,
     318,   321,   322,   323,   324,   325,   326,   327,   330,   333,
     336,   339,   342,   345,   348,   351,   354,   357,   360,   363,
     366,   369,   372,   375,   378,   381,   384,   387,   390,   393,
     396,   399,   402,   405,   408,   411,   414,   417,   420,   423,
     426,   429,   432,   436,   439,   445,   448,   456,   459,   462,
     465,   468,   471,   474,   477,   480,   483,   486,   489,   492,
     495,   498,   501,   504,   507,   510,   513,   516,   519,   522,
     525,   528,   531,   534,   537,   540,   543,   546,   549,   552,
     555,   558,   561,   564,   567,   570,   573,   576,   579,   582,
     585,   588,   591,   594,   597,   600,   603,   606,   609,   612,
     615,   618,   621,   624,   627,   630,   633,   636,   639,   642,
     645
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
       2,     2,     2,   115,     2,     2,     2,   100,   118,     2,
     113,   114,    98,    96,   110,    97,   105,    99,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   108,
     111,   109,   117,   112,   120,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   101,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   106,   119,   107,   116,     2,     2,     2,
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
      95,   102,   103,   104
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int YareParser::yyeof_ = 0;
  const int YareParser::yylast_ = 3945;
  const int YareParser::yynnts_ = 7;
  const int YareParser::yyempty_ = -2;
  const int YareParser::yyfinal_ = 3;
  const int YareParser::yyterror_ = 1;
  const int YareParser::yyerrcode_ = 256;
  const int YareParser::yyntokens_ = 121;

  const unsigned int YareParser::yyuser_token_number_max_ = 353;
  const YareParser::token_number_type YareParser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 5 "yare.y"
} // YL

/* Line 1136 of lalr1.cc  */
#line 3162 "yare.tab.c"


/* Line 1138 of lalr1.cc  */
#line 649 "yare.y"


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

					return 0.0f;
			}
			default:
					break;
	}
	return 0.0f;
}

