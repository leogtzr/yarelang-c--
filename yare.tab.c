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
	unsigned int lineno = 0;


/* Line 293 of lalr1.cc  */
#line 59 "yare.tab.c"


#include "yare.tab.h"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 68 "yare.tab.c"
/* Unqualified %code blocks.  */

/* Line 300 of lalr1.cc  */
#line 35 "yare.y"

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

	void swap(nodeType *p);
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
#line 124 "yare.tab.c"

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
#line 212 "yare.tab.c"

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
#line 214 "yare.y"
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
#line 226 "yare.y"
    {
		push_l_proc(&procs, (yysemantic_stack_[(6) - (3)].nameFunction), (yysemantic_stack_[(6) - (5)].nPtr));
}
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 229 "yare.y"
    {;}
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 233 "yare.y"
    { 
		run((yysemantic_stack_[(2) - (2)].nPtr));			/* Ejecutar los nodos */ 
		freeNode((yysemantic_stack_[(2) - (2)].nPtr)); 	/* Liberar los nodos */

	}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 238 "yare.y"
    {;}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 242 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, NULL, NULL); 
	}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 245 "yare.y"
    { 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 248 "yare.y"
    {		// x to 1 + 2; 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 251 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (4)].sIndex)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 254 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (4)].identificador)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 257 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 260 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 263 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 266 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 269 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 272 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 275 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 278 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 281 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 284 "yare.y"
    { 	// :x: to 1 + 2;
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 287 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 290 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 293 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, id((yysemantic_stack_[(4) - (1)].sIndex)));
	}
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 296 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INIT_RANDOM, 1, idS((yysemantic_stack_[(4) - (1)].identificador)));
	}
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 299 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 302 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 305 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 308 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 311 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(2) - (1)].nPtr); 
	}
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 314 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINTN, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 317 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PRINT, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 320 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 323 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(5) - (3)].cadena), typeCadena));
	}
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 326 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUTS, 1, conStr((yysemantic_stack_[(3) - (2)].cadena), typeCadena));
	}
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 329 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::WHILE, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 332 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::BREAK, 0);
	}
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 335 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 338 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::IF, 3, (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr), (yysemantic_stack_[(7) - (7)].nPtr)); 
	}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 341 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 344 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 347 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 350 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 353 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 356 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 359 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 362 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 365 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 368 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 371 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 374 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 377 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 380 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));			
	}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 383 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 386 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 389 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 392 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 395 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 398 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 401 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 404 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 407 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 410 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 413 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::PUSH, 1, (yysemantic_stack_[(2) - (2)].nPtr));	
	}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 416 "yare.y"
    {;}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 420 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(1) - (1)].nPtr); 
	}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 423 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, (yysemantic_stack_[(2) - (1)].nPtr), (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 429 "yare.y"
    {
		(yyval.nPtr) = con((yysemantic_stack_[(1) - (1)].valnum));
	}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 432 "yare.y"
    { 
		if(vars == NULL) {
			cout << "La variable '" << (yysemantic_stack_[(1) - (1)].identificador) << "' no ha sido declarada";
			exit(EXIT_FAILURE);
		} else {
			(yyval.nPtr) = idS((yysemantic_stack_[(1) - (1)].identificador));	
		}
	}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 440 "yare.y"
    {
		(yyval.nPtr) = conStr((yysemantic_stack_[(1) - (1)].cadena), typeCadena);
	}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 443 "yare.y"
    { 
		(yyval.nPtr) = id((yysemantic_stack_[(1) - (1)].sIndex)); 
	}
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 446 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::UMINUS, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 449 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 452 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 455 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 458 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 461 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 464 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 467 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 470 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 473 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 476 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 479 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 482 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 485 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 488 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 491 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 494 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 497 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 500 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 503 "yare.y"
    { 
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 506 "yare.y"
    {
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 509 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 512 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 515 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 518 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 521 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::NE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 524 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 527 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::AND, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 530 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::OR, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 533 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ANDBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 536 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::YareParser::token::ORBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 539 "yare.y"
    {
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr);
	}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 542 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RAND, 0);
	}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 545 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::POP, 0);
	}
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 548 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ABS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 551 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SQRT, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 554 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ACOS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 557 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ASIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 560 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::ATAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 563 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CEIL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 566 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COS, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 569 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::COSH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 572 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::EXP, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 575 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FLOOR, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 578 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::LN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 581 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SIN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 584 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SINH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 587 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TAN, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 590 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::TANH, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 593 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::SUMATORIA, 2, (yysemantic_stack_[(6) - (3)].nPtr), (yysemantic_stack_[(6) - (5)].nPtr));	
	}
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 596 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::FACTORIAL, 1, (yysemantic_stack_[(4) - (3)].nPtr));	
	}
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 599 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 602 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 605 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 608 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 611 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::XOROP, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 614 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::RANGE_RANDOM, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 617 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::DEC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 620 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::INC_CPP, 1, id((yysemantic_stack_[(3) - (1)].sIndex))); 	
	}
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 623 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 626 "yare.y"
    {
		(yyval.nPtr) = opr(YL::YareParser::token::CALL, 1, idS((yysemantic_stack_[(2) - (2)].nameFunction)));
	}
    break;



/* Line 690 of lalr1.cc  */
#line 1661 "yare.tab.c"
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
  const signed char YareParser::yypact_ninf_ = -76;
  const short int
  YareParser::yypact_[] =
  {
       -76,    28,   -33,   -76,   -17,   257,   -69,   -76,   188,   -76,
     786,   -75,   -68,   -72,   -71,   -67,    13,   -66,   730,   -65,
     -61,   -14,    -3,   730,    -2,     1,     2,     8,   -60,   -59,
     -58,   -44,   -30,   -28,   -24,   -23,   -22,   -13,   -11,   -10,
      -9,    -7,    -6,    14,    17,   730,   -76,   730,   -76,   511,
     -76,   730,   730,   730,   -76,   756,   511,    15,   730,   730,
     730,   730,   730,   730,   730,   730,   730,   730,   730,   584,
     -53,   -74,    16,   730,   730,   730,   730,   730,   730,   730,
     730,   730,   730,   730,   657,    31,   730,   -76,   730,   730,
     730,    21,   120,    45,    44,   -76,   228,    19,    20,   -76,
     -41,   -39,   856,    55,    56,    65,    66,    67,    68,    69,
      71,   730,   730,   730,   730,   730,   730,   730,   730,   730,
     730,   730,   730,   730,   730,   730,   730,   730,  3544,   228,
     -76,   365,   884,   228,   228,   730,   730,   730,   730,   730,
     730,   730,   730,   730,   730,   730,   730,   730,   730,   730,
     730,   730,   730,   730,   730,   730,   730,   730,   730,   730,
     730,   -76,   730,   730,   730,   730,   438,    74,    76,  3544,
    3544,  3544,   984,  3544,  3544,  3544,  3544,  3544,  1012,  3544,
      77,  1112,   730,   -76,   -76,    78,    79,  3544,  3544,  3544,
    1140,  3544,  3544,  3544,  3544,  3544,  1240,  3544,    80,  1268,
     730,  1368,  1396,  1496,  1524,   -76,    81,   -76,    82,    83,
      85,    86,   730,   730,   730,   730,    23,   730,   730,   730,
     730,   730,   730,   730,   730,  1624,  1652,  1752,  1780,  1880,
    1908,  2008,  2036,  2136,  2164,  2264,  2292,  2392,  2420,  2520,
    2548,  2648,   -76,   -76,   -76,  3544,  3544,  3544,  3544,  3544,
    3544,  3544,  3544,  3841,    72,    72,  3544,  3544,  3572,  3700,
      72,    72,    72,    72,  3722,  3722,  3822,  3822,  3841,   910,
     228,  3544,  3544,  3544,  3544,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,  3672,   -76,   -76,   -76,   -76,   -76,   -76,  3672,
     511,   511,    84,    93,    94,   -76,   -76,   -76,   -76,  2676,
    2776,  2804,  2904,   -76,   -76,  2932,  3032,  3060,  3160,  3188,
    3288,  3316,  3416,   -76,   -76,   730,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   110,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,  3444,   511,   -76,
     -76
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  YareParser::yydefact_[] =
  {
         4,     0,     6,     1,     0,     0,     0,    68,    71,    70,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     2,    65,
       7,     0,     0,     0,     5,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,    71,    69,    75,     0,     0,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    72,
      66,     0,     0,    73,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,    54,
      56,    50,     0,    48,    52,    58,    60,    62,     0,    16,
       0,     0,     0,   130,   129,     0,     0,    55,    57,    51,
       0,    49,    53,    59,    61,    63,     0,    17,     0,     0,
       0,     0,     0,     0,     0,    35,     0,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    67,   103,    82,   131,    87,    94,    84,
      96,    78,    80,    92,    88,    85,   128,   127,   100,    99,
      97,    98,    95,    93,    76,    77,    79,    81,    91,    89,
      90,    83,    86,   101,   102,     3,    26,    28,    40,     9,
      24,     8,    14,    27,    29,    41,    21,    25,    20,    15,
      65,    65,     0,     0,     0,   124,   123,   126,   125,     0,
       0,     0,     0,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   122,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      36,    38,    31,    32,    34,    19,    18,    23,    22,    12,
      13,    44,    45,    42,    43,    46,    47,     0,    65,   121,
      39
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  YareParser::yypgoto_[] =
  {
       -76,   -76,   -76,   -76,    -5,   132,    -8
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  YareParser::yydefgoto_[] =
  {
        -1,     1,     2,     5,   130,   131,    55
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char YareParser::yytable_ninf_ = -1;
  const unsigned short int
  YareParser::yytable_[] =
  {
        54,   100,   103,   101,   104,   105,   107,   106,   108,   212,
      96,   214,   109,     4,   110,   102,   183,   184,    91,   167,
     185,   168,   186,   208,   210,   209,   211,   303,     3,   304,
       6,    56,    86,    99,    87,    88,    89,   128,   182,   129,
      90,    93,    97,   132,   133,   134,    98,   111,   112,   113,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   181,   213,   114,   215,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   199,   115,   201,   116,
     202,   203,   204,   117,   118,   119,   135,   136,   137,   138,
     139,   140,   141,   142,   120,   143,   121,   122,   123,   146,
     124,   125,   147,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      92,   126,   200,   205,   127,   206,   243,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   207,   271,   272,   273,   274,    71,   217,
     218,   243,   154,   155,   156,   157,   158,   159,   160,   219,
     220,   221,   222,   223,   282,   224,   276,   162,   277,   280,
     283,   284,   287,   163,   164,   165,   332,   348,   166,   294,
     295,   296,   289,   297,   298,   333,   334,     0,     0,     0,
       0,     0,     0,     0,   299,   300,   301,   302,     0,   305,
     306,   307,   308,   309,   310,   311,   312,    57,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      64,    65,     0,    66,     0,     0,     0,     0,    67,     0,
      68,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,     0,     0,     0,   146,     0,     0,   147,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,   330,   331,     0,    19,    20,
       0,    69,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,    21,    22,   347,    23,     0,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   162,     0,     0,     0,     0,     0,   163,
     164,   165,     0,   350,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,    48,    49,     0,    50,
       0,     0,     0,     0,    51,     0,    52,    53,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    22,     0,    23,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,     0,     0,    47,     0,     0,     0,
      18,     0,     0,     0,     0,    49,   242,    50,     0,    19,
      20,     0,    51,     0,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    22,     0,    23,
       0,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,    47,
       0,     0,     0,    18,     0,     0,     0,     0,    49,   275,
      50,     0,    19,    20,     0,    51,     0,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,     0,    23,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     7,    94,     9,
      95,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    47,     0,     0,     0,    18,     0,     0,     0,
       0,    49,     0,    50,     0,    19,    20,     0,    51,     0,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    46,
       7,    94,     9,    95,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,    47,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
     180,    51,     0,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    46,     7,    94,     9,    95,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,    47,     0,
       0,     0,    18,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,   198,    51,     0,    52,    53,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,    21,   143,
     144,   145,     0,   146,     0,     0,   147,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
       0,    47,    73,    74,    75,    76,    77,    78,    79,    80,
       0,    81,     0,     0,   148,   149,    82,    51,    83,    52,
      53,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,     0,     0,     0,   163,   164,   165,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,    84,
       0,    85,     0,     0,     0,     0,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,   216,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,   148,   149,     0,   146,     0,     0,
     147,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   148,   149,     0,     0,     0,   163,   164,   165,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,   244,     0,     0,   163,   164,   165,   135,   136,
     137,   138,   139,   140,   141,   142,   160,   143,   144,   145,
       0,   146,     0,     0,   147,   162,     0,     0,     0,     0,
       0,   163,   164,   165,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,   278,     0,     0,   162,
     148,   149,     0,     0,     0,   163,   164,   165,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,   279,     0,     0,   162,     0,     0,
       0,     0,     0,   163,   164,   165,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,   281,     0,     0,   162,   148,   149,
       0,     0,     0,   163,   164,   165,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,   285,     0,     0,   162,     0,     0,     0,     0,
       0,   163,   164,   165,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,   286,     0,     0,   162,   148,   149,     0,     0,
       0,   163,   164,   165,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
     288,     0,     0,   162,     0,     0,     0,     0,     0,   163,
     164,   165,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   148,   149,   290,     0,     0,   163,
     164,   165,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   162,     0,     0,   291,     0,     0,   163,   164,   165,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   148,   149,   292,     0,     0,   163,   164,   165,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,   293,     0,     0,   163,   164,   165,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     148,   149,   313,     0,     0,   163,   164,   165,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
     314,     0,     0,   163,   164,   165,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,   315,   162,   148,   149,
       0,     0,     0,   163,   164,   165,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,   316,     0,
       0,   163,   164,   165,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   148,   149,   317,     0,
       0,   163,   164,   165,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,   318,     0,     0,   163,
     164,   165,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   148,   149,   319,     0,     0,   163,
     164,   165,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   162,     0,     0,   320,     0,     0,   163,   164,   165,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   148,   149,   321,     0,     0,   163,   164,   165,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,   322,     0,     0,   163,   164,   165,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   162,
     148,   149,   323,     0,     0,   163,   164,   165,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
     324,     0,     0,   163,   164,   165,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   162,   148,   149,
     325,     0,     0,   163,   164,   165,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,   326,     0,
       0,   163,   164,   165,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   148,   149,   327,     0,
       0,   163,   164,   165,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,   328,     0,     0,   163,
     164,   165,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   148,   149,   329,     0,     0,   163,
     164,   165,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,   335,     0,
       0,   162,     0,     0,     0,     0,     0,   163,   164,   165,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,   336,     0,
       0,   162,   148,   149,     0,     0,     0,   163,   164,   165,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,   337,     0,     0,   162,
       0,     0,     0,     0,     0,   163,   164,   165,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,   338,     0,     0,   162,
     148,   149,     0,     0,     0,   163,   164,   165,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,   339,     0,     0,   162,     0,     0,
       0,     0,     0,   163,   164,   165,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,   340,     0,     0,   162,   148,   149,
       0,     0,     0,   163,   164,   165,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,   341,     0,     0,   162,     0,     0,     0,     0,
       0,   163,   164,   165,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
       0,     0,     0,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,   342,     0,     0,   162,   148,   149,     0,     0,
       0,   163,   164,   165,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
     343,     0,     0,   162,     0,     0,     0,     0,     0,   163,
     164,   165,   135,   136,   137,   138,   139,   140,   141,   142,
       0,   143,   144,   145,     0,   146,     0,     0,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,     0,     0,
       0,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
     344,     0,     0,   162,   148,   149,     0,     0,     0,   163,
     164,   165,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,   345,     0,
       0,   162,     0,     0,     0,     0,     0,   163,   164,   165,
     135,   136,   137,   138,   139,   140,   141,   142,     0,   143,
     144,   145,     0,   146,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,     0,     0,     0,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,   346,     0,
       0,   162,   148,   149,     0,     0,     0,   163,   164,   165,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,     0,   349,     0,     0,   163,   164,   165,   135,   136,
     137,   138,   139,   140,   141,   142,     0,   143,   144,   145,
       0,   146,     0,     0,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,     0,     0,     0,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,     0,     0,   162,
       0,   149,     0,     0,     0,   163,   164,   165,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,   163,   164,   165,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,   144,   145,     0,   146,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   136,   137,   138,   139,   140,
     141,   142,     0,   143,   144,   145,     0,   146,     0,     0,
     147,     0,     0,     0,     0,     0,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,     0,     0,     0,   146,
     148,   149,   147,     0,     0,     0,     0,     0,   150,   151,
     152,   153,   154,     0,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,   163,   164,   165,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,     0,     0,   162,     0,     0,     0,     0,
       0,   163,   164,   165,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,   163,   164,   165,   135,   136,   137,   138,
     139,   140,   141,   142,     0,   143,     0,     0,     0,   146,
       0,     0,   147,     0,     0,   135,   136,   137,   138,   139,
     140,   141,   142,     0,     0,     0,     0,     0,   146,     0,
       0,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   159,   160,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,     0,   163,   164,   165,   159,   160,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,     0,
       0,     0,   163,   164,   165
  };

  /* YYCHECK.  */
  const short int
  YareParser::yycheck_[] =
  {
         5,     4,     4,     6,     6,     4,     4,     6,     6,    50,
      18,    50,     4,    46,     6,    23,    90,    91,     5,     4,
       4,     6,     6,     4,     4,     6,     6,     4,     0,     6,
      47,   100,   107,    47,   102,   107,   107,    45,    91,    47,
     107,   107,   107,    51,    52,    53,   107,   107,   107,   107,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,   103,   107,   103,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,   107,    86,   107,
      88,    89,    90,   107,   107,   107,    14,    15,    16,    17,
      18,    19,    20,    21,   107,    23,   107,   107,   107,    27,
     107,   107,    30,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     107,   107,    91,   102,   107,     5,   131,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   108,   162,   163,   164,   165,   114,   104,
     104,   166,    90,    91,    92,    93,    94,    95,    96,   104,
     104,   104,   104,   104,   182,   104,   102,   105,   102,   102,
     102,   102,   102,   111,   112,   113,   102,    77,    56,   108,
     108,   108,   200,   108,   108,   102,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   212,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    -1,    -1,    -1,    -1,    50,    -1,
      52,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,   290,   291,    -1,    31,    32,
      -1,   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,    48,    49,   315,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,   105,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    -1,   348,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,   102,
      -1,    -1,    -1,    -1,   107,    -1,   109,   110,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,   100,   101,   102,    -1,    31,
      32,    -1,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,   100,   101,
     102,    -1,    31,    32,    -1,   107,    -1,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    -1,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,   100,    -1,   102,    -1,    31,    32,    -1,   107,    -1,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    75,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
     106,   107,    -1,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    -1,    75,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,   106,   107,    -1,   109,   110,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    48,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    91,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    45,    -1,    -1,    78,    79,    50,   107,    52,   109,
     110,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,   103,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    50,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    78,    79,    -1,    27,    -1,    -1,
      30,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    78,    79,    -1,    -1,    -1,   111,   112,   113,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,   112,   113,    14,    15,
      16,    17,    18,    19,    20,    21,    96,    23,    24,    25,
      -1,    27,    -1,    -1,    30,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,
      78,    79,    -1,    -1,    -1,   111,   112,   113,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    78,    79,
      -1,    -1,    -1,   111,   112,   113,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,   105,    78,    79,    -1,    -1,
      -1,   111,   112,   113,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    78,    79,   108,    -1,    -1,   111,
     112,   113,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,   112,   113,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    78,    79,   108,    -1,    -1,   111,   112,   113,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,   112,   113,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      78,    79,   108,    -1,    -1,   111,   112,   113,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,   112,   113,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   104,   105,    78,    79,
      -1,    -1,    -1,   111,   112,   113,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,   112,   113,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    78,    79,   108,    -1,
      -1,   111,   112,   113,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
     112,   113,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    78,    79,   108,    -1,    -1,   111,
     112,   113,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,   108,    -1,    -1,   111,   112,   113,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    78,    79,   108,    -1,    -1,   111,   112,   113,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,   112,   113,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      78,    79,   108,    -1,    -1,   111,   112,   113,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,    -1,    -1,   111,   112,   113,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    78,    79,
     108,    -1,    -1,   111,   112,   113,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   108,    -1,
      -1,   111,   112,   113,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    78,    79,   108,    -1,
      -1,   111,   112,   113,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,   108,    -1,    -1,   111,
     112,   113,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    78,    79,   108,    -1,    -1,   111,
     112,   113,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    78,    79,    -1,    -1,    -1,   111,   112,   113,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,   105,
      78,    79,    -1,    -1,    -1,   111,   112,   113,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,   102,    -1,    -1,   105,    78,    79,
      -1,    -1,    -1,   111,   112,   113,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,   105,    78,    79,    -1,    -1,
      -1,   111,   112,   113,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,   111,
     112,   113,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
     102,    -1,    -1,   105,    78,    79,    -1,    -1,    -1,   111,
     112,   113,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,   102,    -1,
      -1,   105,    78,    79,    -1,    -1,    -1,   111,   112,   113,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,   108,    -1,    -1,   111,   112,   113,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    79,    -1,    -1,    -1,   111,   112,   113,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,
      78,    79,    30,    -1,    -1,    -1,    -1,    -1,    86,    87,
      88,    89,    90,    -1,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,    27,
      -1,    -1,    30,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  YareParser::yystos_[] =
  {
         0,   116,   117,     0,    46,   118,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    22,    31,
      32,    48,    49,    51,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    91,    99,   100,
     102,   107,   109,   110,   119,   121,   100,    29,    36,    37,
      38,    39,    40,    41,    42,    43,    45,    50,    52,   103,
     105,   114,    29,    36,    37,    38,    39,    40,    41,    42,
      43,    45,    50,    52,   103,   105,   107,   102,   107,   107,
     107,     5,   107,   107,     4,     6,   121,   107,   107,    47,
       4,     6,   121,     4,     6,     4,     6,     4,     6,     4,
       6,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   121,   121,
     119,   120,   121,   121,   121,    14,    15,    16,    17,    18,
      19,    20,    21,    23,    24,    25,    27,    30,    78,    79,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   102,   105,   111,   112,   113,   120,     4,     6,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     106,   121,    91,    90,    91,     4,     6,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   106,   121,
      91,   121,   121,   121,   121,   102,     5,   108,     4,     6,
       4,     6,    50,   103,    50,   103,    50,   104,   104,   104,
     104,   104,   104,   104,   104,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   101,   119,   108,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   101,   102,   102,   102,   102,
     102,   102,   121,   102,   102,   102,   102,   102,   102,   121,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   121,
     121,   121,   121,     4,     6,   121,   121,   121,   121,   121,
     121,   121,   121,   108,   108,   104,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     119,   119,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   121,    77,   108,
     119
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
      43,    45,    42,    47,    37,    94,   345,   346,   347,    46,
     123,   125,    59,    61,    44,    60,    63,    40,    41,    33,
     126,    62,    38,   124,    64
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  YareParser::yyr1_[] =
  {
         0,   115,   116,   117,   117,   118,   118,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  YareParser::yyr2_[] =
  {
         0,     2,     3,     6,     0,     2,     0,     1,     4,     4,
       4,     4,     5,     5,     4,     4,     3,     3,     5,     5,
       4,     4,     5,     5,     4,     4,     4,     4,     4,     4,
       2,     5,     5,     3,     5,     3,     5,     2,     5,     7,
       4,     4,     5,     5,     5,     5,     5,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     0,     1,     2,     1,     1,
       1,     1,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const YareParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMERIC", "VARIABLE", "CADENA", "ID",
  "WHILE", "BREAK", "IF", "PRINTN", "PRINT", "PUTS", "RAND", "EXPR_DIV",
  "EXPR_MAS", "EXPR_MAYOR", "EXPR_MAYORIGUAL", "EXPR_MENOR",
  "EXPR_MENORIGUAL", "EXPR_MENOS", "EXPR_MUL", "EXPR_NOT", "MOD_WORD",
  "_GT_", "_LT_", "INIT_RANDOM", "RANGE_RANDOM", "SWAP_ID_VAR", "SWAP_OP",
  "XOROP", "DEC", "INC", "DEC_CPP", "INC_CPP", "ID_ASIGNACION",
  "OP_ASIGN_ABR_MUL", "OP_ASIGN_ABR_DIV", "OP_ASIGN_ABR_MOD",
  "OP_ASIGN_ABR_MAS", "OP_ASIGN_ABR_MENOS", "OP_ASIGN_ABR_SHIFTLEFT",
  "OP_ASIGN_ABR_SHIFTRIGHT", "OP_ASIGN_ABR_AND", "OP_ASIGN_ABR_OR",
  "OP_ASIGN_ABR_POW", "PROC", "FUNCNAME", "CALL", "LETSET_ASSIGN", "TO",
  "MOVE", "PASCAL_ASSIGN", "MOV_ASM", "SUB_ASM", "ADD_ASM", "MUL_ASM",
  "ABS", "FACTORIAL", "SUMATORIA", "SQRT", "ACOS", "ASIN", "ATAN", "CEIL",
  "COS", "COSH", "EXP", "FLOOR", "LN", "SIN", "SINH", "TAN", "TANH",
  "PUSH", "POP", "IFX", "ELSE", "OR", "AND", "SHIFTRIGHT", "SHIFTLEFT",
  "ANDBITS", "ORBITS", "LT", "GT", "NE", "EQ", "LE", "GE", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'^'", "EXPR_ELEVADO", "NEGACION", "UMINUS", "'.'",
  "'{'", "'}'", "';'", "'='", "','", "'<'", "'?'", "'('", "')'", "'!'",
  "'~'", "'>'", "'&'", "'|'", "'@'", "$accept", "program", "funciones",
  "cuerpo", "stmt", "stmt_list", "expr", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const YareParser::rhs_number_type
  YareParser::yyrhs_[] =
  {
       116,     0,    -1,   117,   118,    99,    -1,   117,    46,    47,
     100,   120,   101,    -1,    -1,   118,   119,    -1,    -1,   102,
      -1,     4,   103,   121,   102,    -1,     4,    50,   121,   102,
      -1,    51,   121,    50,     4,    -1,    51,   121,    50,     6,
      -1,    53,     4,   104,   121,   102,    -1,    53,     6,   104,
     121,   102,    -1,     4,   105,    91,   121,    -1,     6,   105,
      91,   121,    -1,     4,    52,   121,    -1,     6,    52,   121,
      -1,    49,     4,   103,   121,   102,    -1,    49,     4,    50,
     121,   102,    -1,     6,   103,   121,   102,    -1,     6,    50,
     121,   102,    -1,    49,     6,   103,   121,   102,    -1,    49,
       6,    50,   121,   102,    -1,     4,   103,   106,   102,    -1,
       6,   103,   106,   102,    -1,     4,    29,     4,   102,    -1,
       6,    29,     4,   102,    -1,     4,    29,     6,   102,    -1,
       6,    29,     6,   102,    -1,   121,   102,    -1,    10,   107,
     121,   108,   102,    -1,    11,   107,   121,   108,   102,    -1,
     100,   120,   101,    -1,    12,   107,     5,   108,   102,    -1,
      12,     5,   102,    -1,     7,   107,   121,   108,   119,    -1,
       8,   102,    -1,     9,   107,   121,   108,   119,    -1,     9,
     107,   121,   108,   119,    77,   119,    -1,     4,    39,   121,
     102,    -1,     6,    39,   121,   102,    -1,    55,     4,   104,
     121,   102,    -1,    55,     6,   104,   121,   102,    -1,    54,
       4,   104,   121,   102,    -1,    54,     6,   104,   121,   102,
      -1,    56,     4,   104,   121,   102,    -1,    56,     6,   104,
     121,   102,    -1,     4,    40,   121,    -1,     6,    40,   121,
      -1,     4,    38,   121,    -1,     6,    38,   121,    -1,     4,
      41,   121,    -1,     6,    41,   121,    -1,     4,    36,   121,
      -1,     6,    36,   121,    -1,     4,    37,   121,    -1,     6,
      37,   121,    -1,     4,    42,   121,    -1,     6,    42,   121,
      -1,     4,    43,   121,    -1,     6,    43,   121,    -1,     4,
      45,   121,    -1,     6,    45,   121,    -1,    74,   121,    -1,
      -1,   119,    -1,   120,   119,    -1,     3,    -1,     6,    -1,
       5,    -1,     4,    -1,    91,   121,    -1,   109,   121,    -1,
     110,   121,    -1,    22,   121,    -1,   121,    90,   121,    -1,
     121,    91,   121,    -1,   121,    20,   121,    -1,   121,    92,
     121,    -1,   121,    21,   121,    -1,   121,    93,   121,    -1,
     121,    14,   121,    -1,   121,   105,   121,    -1,   121,    18,
     121,    -1,   121,    25,   121,    -1,   121,   111,   121,    -1,
     121,    16,   121,    -1,   121,    24,   121,    -1,   121,    95,
     121,    -1,   121,    96,   121,    -1,   121,    94,   121,    -1,
     121,    23,   121,    -1,   121,    89,   121,    -1,   121,    17,
     121,    -1,   121,    88,   121,    -1,   121,    19,   121,    -1,
     121,    86,   121,    -1,   121,    87,   121,    -1,   121,    79,
     121,    -1,   121,    78,   121,    -1,   121,   112,   121,    -1,
     121,   113,   121,    -1,   107,   121,   108,    -1,    13,   107,
     108,    -1,    75,    -1,    57,   107,   121,   108,    -1,    60,
     107,   121,   108,    -1,    61,   107,   121,   108,    -1,    62,
     107,   121,   108,    -1,    63,   107,   121,   108,    -1,    64,
     107,   121,   108,    -1,    65,   107,   121,   108,    -1,    66,
     107,   121,   108,    -1,    67,   107,   121,   108,    -1,    68,
     107,   121,   108,    -1,    69,   107,   121,   108,    -1,    70,
     107,   121,   108,    -1,    71,   107,   121,   108,    -1,    72,
     107,   121,   108,    -1,    73,   107,   121,   108,    -1,    59,
     107,   121,   104,   121,   108,    -1,    58,   107,   121,   108,
      -1,    31,   107,     6,   108,    -1,    31,   107,     4,   108,
      -1,    32,   107,     6,   108,    -1,    32,   107,     4,   108,
      -1,   121,    30,   121,    -1,   121,    27,   121,    -1,     4,
     114,    91,    -1,     4,   114,    90,    -1,   121,    15,   121,
      -1,    48,    47,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  YareParser::yyprhs_[] =
  {
         0,     0,     3,     7,    14,    15,    18,    19,    21,    26,
      31,    36,    41,    47,    53,    58,    63,    67,    71,    77,
      83,    88,    93,    99,   105,   110,   115,   120,   125,   130,
     135,   138,   144,   150,   154,   160,   164,   170,   173,   179,
     187,   192,   197,   203,   209,   215,   221,   227,   233,   237,
     241,   245,   249,   253,   257,   261,   265,   269,   273,   277,
     281,   285,   289,   293,   297,   300,   301,   303,   306,   308,
     310,   312,   314,   317,   320,   323,   326,   330,   334,   338,
     342,   346,   350,   354,   358,   362,   366,   370,   374,   378,
     382,   386,   390,   394,   398,   402,   406,   410,   414,   418,
     422,   426,   430,   434,   438,   442,   444,   449,   454,   459,
     464,   469,   474,   479,   484,   489,   494,   499,   504,   509,
     514,   519,   526,   531,   536,   541,   546,   551,   555,   559,
     563,   567,   571
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  YareParser::yyrline_[] =
  {
         0,   214,   214,   226,   229,   233,   238,   242,   245,   248,
     251,   254,   257,   260,   263,   266,   269,   272,   275,   278,
     281,   284,   287,   290,   293,   296,   299,   302,   305,   308,
     311,   314,   317,   320,   323,   326,   329,   332,   335,   338,
     341,   344,   347,   350,   353,   356,   359,   362,   365,   368,
     371,   374,   377,   380,   383,   386,   389,   392,   395,   398,
     401,   404,   407,   410,   413,   416,   420,   423,   429,   432,
     440,   443,   446,   449,   452,   455,   458,   461,   464,   467,
     470,   473,   476,   479,   482,   485,   488,   491,   494,   497,
     500,   503,   506,   509,   512,   515,   518,   521,   524,   527,
     530,   533,   536,   539,   542,   545,   548,   551,   554,   557,
     560,   563,   566,   569,   572,   575,   578,   581,   584,   587,
     590,   593,   596,   599,   602,   605,   608,   611,   614,   617,
     620,   623,   626
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
       2,     2,     2,   109,     2,     2,     2,    94,   112,     2,
     107,   108,    92,    90,   104,    91,    99,    93,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   102,
     105,   103,   111,   106,   114,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,   113,   101,   110,     2,     2,     2,
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
      85,    86,    87,    88,    89,    96,    97,    98
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int YareParser::yyeof_ = 0;
  const int YareParser::yylast_ = 3954;
  const int YareParser::yynnts_ = 7;
  const int YareParser::yyempty_ = -2;
  const int YareParser::yyfinal_ = 3;
  const int YareParser::yyterror_ = 1;
  const int YareParser::yyerrcode_ = 256;
  const int YareParser::yyntokens_ = 115;

  const unsigned int YareParser::yyuser_token_number_max_ = 347;
  const YareParser::token_number_type YareParser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 5 "yare.y"
} // YL

/* Line 1136 of lalr1.cc  */
#line 3089 "yare.tab.c"


/* Line 1138 of lalr1.cc  */
#line 630 "yare.y"


// We have to implement the error function
void YL::YareParser::error(const YL::YareParser::location_type &loc, const std::string &msg) {
	std::cerr << "Error :'(    -> [" << msg << "]" << lineno << std::endl;
	
}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
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

		case typeCadena:
			/*if((spLoop < 0) || pilaLoop[spLoop]) {
				printf("%s", p->con.cadena);
			}*/
			return 0.0L; //(double)strlen(p->con.cadena);

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
		
		/*case typeStrlen:
			return (double)strlen(p->con.cadena);*/

		case typeSystem:
			/*if((spLoop < 0) || pilaLoop[spLoop])
				system(p->con.cadena);*/
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
					// PENDIENTE Verificar que funcione:
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
			}
			default:
					break;
	}
	return 0.0f;
}

void swap(nodeType *p) {
	int temp = sym[p->opr.op[0]->id.i];
	sym[p->opr.op[0]->id.i] = sym[p->opr.op[1]->id.i];
	sym[p->opr.op[1]->id.i] = temp;
}
	

