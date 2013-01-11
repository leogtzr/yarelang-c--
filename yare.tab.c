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
	#include "procs.h"
	// #include "Funciones.h"
	#include <cmath>
	#include <stack>
	
	// Needed 'usings'
	using std::stack;
	
	// The symbol table:
	long double sym[26];
	Variables *vars = NULL;
	struct proc *procs = NULL;
	std::stack<long double> pilaVirtual;



/* Line 293 of lalr1.cc  */
#line 61 "yare.tab.c"


#include "yare.tab.h"

/* User implementation prologue.  */


/* Line 299 of lalr1.cc  */
#line 70 "yare.tab.c"
/* Unqualified %code blocks.  */

/* Line 300 of lalr1.cc  */
#line 39 "yare.y"

	using std::endl;
	using std::cout;
	using std::cerr;

	static int yylex(YL::BisonParser::semantic_type * yylval, YL::FlexScanner &scanner);
	
	// Node Constants:
	nodeTypeTag *con(long double);
	
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
#line 123 "yare.tab.c"

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
#line 211 "yare.tab.c"

  /// Build a parser object.
  BisonParser::BisonParser (YL::FlexScanner &scanner_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg)
  {
  }

  BisonParser::~BisonParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  BisonParser::yy_symbol_value_print_ (int yytype,
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
  BisonParser::yy_symbol_print_ (int yytype,
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
  BisonParser::yydestruct_ (const char* yymsg,
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
  BisonParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  BisonParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  BisonParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  BisonParser::debug_level_type
  BisonParser::debug_level () const
  {
    return yydebug_;
  }

  void
  BisonParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  inline bool
  BisonParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  BisonParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  BisonParser::parse ()
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
#line 192 "yare.y"
    {
	exit(EXIT_SUCCESS);
}
    break;

  case 3:

/* Line 690 of lalr1.cc  */
#line 198 "yare.y"
    {
		push_l_proc(&procs, (yysemantic_stack_[(6) - (3)].nameFunction), (yysemantic_stack_[(6) - (5)].nPtr));
}
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 201 "yare.y"
    {;}
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 205 "yare.y"
    { 
		run((yysemantic_stack_[(2) - (2)].nPtr));			/* Ejecutar los nodos */ 
		freeNode((yysemantic_stack_[(2) - (2)].nPtr)); 	/* Liberar los nodos */
	}
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 209 "yare.y"
    {;}
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 213 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, NULL, NULL); 
	}
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 216 "yare.y"
    { 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 219 "yare.y"
    {		// x to 1 + 2; 
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 222 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (4)].sIndex)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 225 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (4)].identificador)), (yysemantic_stack_[(4) - (2)].nPtr));
	}
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 228 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 231 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 234 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 237 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (4)].nPtr));
	}
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 240 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 243 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 246 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 249 "yare.y"
    {
		(yyval.nPtr) = opr('=', 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 252 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 255 "yare.y"
    { 	// :x: to 1 + 2;
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr)); 
	}
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 258 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 261 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr)); 
	}
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 264 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::INIT_RANDOM, 1, id((yysemantic_stack_[(4) - (1)].sIndex)));
	}
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 267 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::INIT_RANDOM, 1, idS((yysemantic_stack_[(4) - (1)].identificador)));
	}
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 270 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 273 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 276 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::SWAP_OP, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 279 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::SWAP_OP, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 282 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(2) - (1)].nPtr); 
	}
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 285 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::PRINTN, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 288 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::PRINT, 1, (yysemantic_stack_[(5) - (3)].nPtr)); 
	}
    break;

  case 33:

/* Line 690 of lalr1.cc  */
#line 291 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr); 
	}
    break;

  case 34:

/* Line 690 of lalr1.cc  */
#line 294 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::WHILE, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 35:

/* Line 690 of lalr1.cc  */
#line 297 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::BREAK, 0);
	}
    break;

  case 36:

/* Line 690 of lalr1.cc  */
#line 300 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::IF, 2, (yysemantic_stack_[(5) - (3)].nPtr), (yysemantic_stack_[(5) - (5)].nPtr)); 
	}
    break;

  case 37:

/* Line 690 of lalr1.cc  */
#line 303 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::IF, 3, (yysemantic_stack_[(7) - (3)].nPtr), (yysemantic_stack_[(7) - (5)].nPtr), (yysemantic_stack_[(7) - (7)].nPtr)); 
	}
    break;

  case 38:

/* Line 690 of lalr1.cc  */
#line 306 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(4) - (1)].sIndex)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 39:

/* Line 690 of lalr1.cc  */
#line 309 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(4) - (1)].identificador)), (yysemantic_stack_[(4) - (3)].nPtr));
	}
    break;

  case 40:

/* Line 690 of lalr1.cc  */
#line 312 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 41:

/* Line 690 of lalr1.cc  */
#line 315 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 318 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 321 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 324 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(5) - (2)].sIndex)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 327 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(5) - (2)].identificador)), (yysemantic_stack_[(5) - (4)].nPtr));
	}
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 330 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 333 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 336 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MOD, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 339 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MOD, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 342 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 345 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 348 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_DIV, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 351 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_DIV, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 354 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 357 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 360 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_AND, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 363 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_AND, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 366 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_POW, 2, id((yysemantic_stack_[(3) - (1)].sIndex)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 369 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::OP_ASIGN_ABR_POW, 2, idS((yysemantic_stack_[(3) - (1)].identificador)), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 372 "yare.y"
    {;}
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 376 "yare.y"
    { 
		(yyval.nPtr) = (yysemantic_stack_[(1) - (1)].nPtr); 
	}
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 379 "yare.y"
    { 
		(yyval.nPtr) = opr(';', 2, (yysemantic_stack_[(2) - (1)].nPtr), (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 385 "yare.y"
    {
		(yyval.nPtr) = con((yysemantic_stack_[(1) - (1)].valnum));
	}
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 388 "yare.y"
    { 
		if(vars == NULL) {
			cout << "La variable '" << (yysemantic_stack_[(1) - (1)].identificador) << "' no ha sido declarada";
			exit(EXIT_FAILURE);
		} else {
			(yyval.nPtr) = idS((yysemantic_stack_[(1) - (1)].identificador));	
		}
	}
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 396 "yare.y"
    { 
		(yyval.nPtr) = id((yysemantic_stack_[(1) - (1)].sIndex)); 
	}
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 399 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::RAND, 0);
	}
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 402 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::DEC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 405 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::DEC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 408 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::INC, 1, idS((yysemantic_stack_[(4) - (3)].identificador)));
	}
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 411 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::INC, 1, id((yysemantic_stack_[(4) - (3)].sIndex)));
	}
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 414 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::XOROP, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 417 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::RANGE_RANDOM, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr));
	}
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 420 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 423 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::UMINUS, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 426 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 429 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 432 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::NEGACION, 1, (yysemantic_stack_[(2) - (2)].nPtr)); 
	}
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 435 "yare.y"
    { 
		(yyval.nPtr) = opr('+', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 438 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 441 "yare.y"
    { 
		(yyval.nPtr) = opr('-', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 81:

/* Line 690 of lalr1.cc  */
#line 444 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 82:

/* Line 690 of lalr1.cc  */
#line 447 "yare.y"
    { 
		(yyval.nPtr) = opr('*', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 83:

/* Line 690 of lalr1.cc  */
#line 450 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 84:

/* Line 690 of lalr1.cc  */
#line 453 "yare.y"
    { 
		(yyval.nPtr) = opr('/', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 456 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 459 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 462 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::LT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 465 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 468 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 471 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::GT, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 474 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 477 "yare.y"
    { 
		(yyval.nPtr) = opr('^', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 480 "yare.y"
    { 
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 483 "yare.y"
    {
		(yyval.nPtr) = opr('%', 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 486 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 489 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::GE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 492 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 495 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::LE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 498 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::NE, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 501 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::EQ, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 504 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::AND, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 507 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::OR, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 510 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::ANDBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 513 "yare.y"
    { 
		(yyval.nPtr) = opr(YL::BisonParser::token::ORBITS, 2, (yysemantic_stack_[(3) - (1)].nPtr), (yysemantic_stack_[(3) - (3)].nPtr)); 
	}
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 516 "yare.y"
    {
		(yyval.nPtr) = (yysemantic_stack_[(3) - (2)].nPtr);
	}
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 519 "yare.y"
    {
		(yyval.nPtr) = opr(YL::BisonParser::token::CALL, 1, idS((yysemantic_stack_[(2) - (2)].nameFunction)));
	}
    break;



/* Line 690 of lalr1.cc  */
#line 1419 "yare.tab.c"
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
  BisonParser::yysyntax_error_ (int, int)
  {
    return YY_("syntax error");
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char BisonParser::yypact_ninf_ = -60;
  const short int
  BisonParser::yypact_[] =
  {
       -60,     1,   -40,   -60,   -28,   172,   -59,   -60,   397,  1124,
     -46,   -27,   -20,   -16,    -9,    -7,   398,    -6,    27,    32,
      -4,   398,    -2,     3,     5,     8,   398,   -60,   334,   -60,
     398,   398,   398,   -60,   448,   334,    10,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   119,    36,    19,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     371,    43,   398,   -60,   398,   398,   398,    28,   -60,   -60,
     987,    21,    67,   -60,   -43,   -30,   476,    39,    40,    44,
      47,    49,    50,    51,    56,   987,   -60,   226,   557,   987,
     987,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   -60,   398,   398,   398,
     398,   398,   280,    60,    61,  1943,  1943,  1943,   638,  1943,
    1943,  1943,  1943,   666,  1943,    63,   747,   398,    64,    65,
    1943,  1943,  1943,   775,  1943,  1943,  1943,  1943,   856,  1943,
      66,   884,   398,   965,  1046,  1127,  1208,   -60,    80,    81,
      82,    83,   398,   398,   398,   398,    70,   398,   398,   398,
     398,   398,   398,   398,   398,   -60,   -60,   -60,  1943,  1943,
    1943,  1943,  1943,  1943,  1943,  1943,  1943,  1943,  1943,  1943,
    1943,  1971,  2080,  2161,  2161,  2161,  2161,    45,    45,  2181,
    2181,   584,   987,  1943,  1943,  1943,  1943,  1943,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,  2052,   -60,   -60,   -60,   -60,
     -60,   -60,  2052,   334,   334,    71,    76,   -60,   -60,   -60,
     -60,  1289,  1317,  1398,  1426,   -60,   -60,  1507,  1535,  1616,
    1644,  1725,  1753,  1834,  1862,   -60,    69,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   334,   -60
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned char
  BisonParser::yydefact_[] =
  {
         4,     0,     6,     1,     0,     0,     0,    63,    65,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,    60,     7,
       0,     0,     0,     5,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,    65,    64,
      77,     0,     0,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    61,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    52,    48,     0,    46,
      54,    56,    58,     0,    16,     0,     0,     0,     0,     0,
      51,    53,    49,     0,    47,    55,    57,    59,     0,    17,
       0,     0,     0,     0,     0,     0,     0,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,    62,   105,    84,    78,
      89,    96,    86,    98,    80,    82,    94,    90,    87,    72,
      71,   102,   101,    99,   100,    97,    95,    73,    79,    81,
      83,    91,    92,    85,    88,    93,   103,   104,     3,    26,
      28,    38,     9,    24,     8,    14,    27,    29,    39,    21,
      25,    20,    15,    60,    60,     0,     0,    68,    67,    70,
      69,     0,     0,     0,     0,    10,    11,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    36,    31,    32,    19,
      18,    23,    22,    12,    13,    42,    43,    40,    41,    44,
      45,    60,    37
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  BisonParser::yypgoto_[] =
  {
       -60,   -60,   -60,   -60,    -5,   114,    -8
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  BisonParser::yydefgoto_[] =
  {
        -1,     1,     2,     5,    86,    87,    34
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const signed char BisonParser::yytable_ninf_ = -1;
  const unsigned short int
  BisonParser::yytable_[] =
  {
        33,     3,    74,    75,    77,    78,     4,   162,    70,    79,
      80,    81,    82,    76,    83,    84,   123,   124,    85,     6,
     164,    35,    88,    89,    90,   138,   139,   158,   159,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   136,
     163,    62,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   151,   165,   153,    63,   154,   155,   156,    91,
      92,    93,    94,    95,    96,    97,    98,    64,    99,   100,
     101,    65,   102,   160,   161,   103,   235,   236,    66,    73,
      67,    71,   176,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   137,   203,
     204,   205,   206,   207,    72,   152,   157,   176,   112,   113,
     114,   115,     7,   167,   168,    68,    69,   261,   169,   215,
     117,   170,    15,   171,   172,   173,   118,   119,   120,   121,
     174,    16,   209,   210,   222,   213,   216,   217,   220,   122,
      17,    18,     0,   247,   231,   232,   233,   234,   248,   237,
     238,   239,   240,   241,   242,   243,   244,    19,   227,   228,
     229,   230,     0,     0,     0,     7,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,     0,     0,
       0,    26,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,   135,    30,     0,    31,    32,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
      19,    20,     0,    21,     0,    22,    23,    24,    25,     7,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,     0,     0,    26,     0,     0,     0,    16,     0,
       0,    27,    28,     0,    29,     0,   262,    17,    18,    30,
       0,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,    21,     0,    22,
      23,    24,    25,     7,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,     0,     0,    26,     0,
       0,     0,    16,     0,     0,     0,    28,   175,    29,     0,
       0,    17,    18,    30,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,    21,     0,    22,    23,    24,    25,     7,     0,     0,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
       0,     0,    26,     0,     0,     0,    16,     0,     0,     0,
      28,   208,    29,     0,     0,    17,    18,    30,     0,    31,
      32,     0,     0,     0,     7,     0,     0,    68,    69,     0,
       0,     0,    19,    20,    15,    21,     0,    22,    23,    24,
      25,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     7,    17,    18,    68,    69,    26,     0,     0,     0,
       0,    15,     0,     0,    28,     0,    29,     0,     0,    19,
      16,    30,     0,    31,    32,     0,    36,     0,     0,    17,
      18,     0,     0,    37,    38,    39,    40,    41,     0,    42,
      43,     0,    44,    26,     0,     0,    19,    45,     0,    46,
       0,     0,     0,     0,     0,     0,     0,   150,    30,     0,
      31,    32,    91,    92,    93,    94,    95,    96,    97,    98,
      26,    99,   100,   101,     0,   102,     0,     0,   103,     0,
      47,     0,    48,     0,     0,    30,     0,    31,    32,     0,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
     100,   101,     0,   102,     0,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   166,     0,     0,     0,
     116,     0,     0,   117,     0,   104,   105,     0,     0,   118,
     119,   120,   121,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,     0,     0,     0,     0,   118,   119,   120,
     121,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,   100,   101,     0,   102,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,     0,    99,   100,   101,
       0,   102,     0,     0,   103,     0,   104,   105,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,   177,     0,     0,   118,   119,
     120,   121,    91,    92,    93,    94,    95,    96,    97,    98,
     115,    99,   100,   101,     0,   102,     0,     0,   103,   117,
       0,     0,     0,     0,     0,   118,   119,   120,   121,     0,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
     100,   101,     0,   102,     0,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,     0,
     211,     0,     0,   117,     0,   104,   105,     0,     0,   118,
     119,   120,   121,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,   212,     0,
       0,   117,     0,     0,     0,     0,     0,   118,   119,   120,
     121,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,   100,   101,     0,   102,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,   100,
     101,     0,   102,     0,     0,   103,   104,   105,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,   214,
       0,     0,   117,     0,   104,   105,     0,     0,   118,   119,
     120,   121,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,   218,     0,     0,
     117,     0,     0,     0,     0,     0,   118,   119,   120,   121,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
     100,   101,     0,   102,     0,     0,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,     0,    99,   100,   101,
       0,   102,     0,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,   219,     0,
       0,   117,     0,   104,   105,     0,     0,   118,   119,   120,
     121,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,   221,     0,     0,   117,
       0,     0,     0,     0,     0,   118,   119,   120,   121,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,   100,
     101,     0,   102,     0,     0,   103,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,   100,   101,     0,   102,     0,     0,   103,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,   223,     0,     0,   118,   119,   120,   121,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
     100,   101,   117,   102,     0,     0,   103,     0,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,     0,   224,     0,     0,   118,   119,   120,
     121,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,   100,   101,    49,   102,     0,     0,   103,     0,     0,
      50,    51,    52,    53,    54,     0,    55,    56,     0,    57,
       0,     0,     0,     0,    58,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,   105,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,    60,     0,    61,
       0,     0,   117,     0,     0,   225,     0,     0,   118,   119,
     120,   121,    91,    92,    93,    94,    95,    96,    97,    98,
       0,    99,   100,   101,     0,   102,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,   117,     0,     0,   226,     0,     0,   118,
     119,   120,   121,    91,    92,    93,    94,    95,    96,    97,
      98,     0,    99,   100,   101,     0,   102,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,   100,   101,     0,   102,     0,     0,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,     0,
       0,   249,     0,     0,   117,     0,   104,   105,     0,     0,
     118,   119,   120,   121,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,   250,
       0,     0,   117,     0,     0,     0,     0,     0,   118,   119,
     120,   121,    91,    92,    93,    94,    95,    96,    97,    98,
       0,    99,   100,   101,     0,   102,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
     100,   101,     0,   102,     0,     0,   103,   104,   105,     0,
       0,     0,     0,     0,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,     0,
     251,     0,     0,   117,     0,   104,   105,     0,     0,   118,
     119,   120,   121,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,   252,     0,
       0,   117,     0,     0,     0,     0,     0,   118,   119,   120,
     121,    91,    92,    93,    94,    95,    96,    97,    98,     0,
      99,   100,   101,     0,   102,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,   100,
     101,     0,   102,     0,     0,   103,   104,   105,     0,     0,
       0,     0,     0,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,   253,
       0,     0,   117,     0,   104,   105,     0,     0,   118,   119,
     120,   121,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,   254,     0,     0,
     117,     0,     0,     0,     0,     0,   118,   119,   120,   121,
      91,    92,    93,    94,    95,    96,    97,    98,     0,    99,
     100,   101,     0,   102,     0,     0,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,     0,    99,   100,   101,
       0,   102,     0,     0,   103,   104,   105,     0,     0,     0,
       0,     0,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,   255,     0,
       0,   117,     0,   104,   105,     0,     0,   118,   119,   120,
     121,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,   256,     0,     0,   117,
       0,     0,     0,     0,     0,   118,   119,   120,   121,    91,
      92,    93,    94,    95,    96,    97,    98,     0,    99,   100,
     101,     0,   102,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,   100,   101,     0,
     102,     0,     0,   103,   104,   105,     0,     0,     0,     0,
       0,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,   257,     0,     0,
     117,     0,   104,   105,     0,     0,   118,   119,   120,   121,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,   258,     0,     0,   117,     0,
       0,     0,     0,     0,   118,   119,   120,   121,    91,    92,
      93,    94,    95,    96,    97,    98,     0,    99,   100,   101,
       0,   102,     0,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,     0,    99,   100,   101,     0,   102,
       0,     0,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,     0,   259,     0,     0,   117,
       0,   104,   105,     0,     0,   118,   119,   120,   121,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,   260,     0,     0,   117,     0,     0,
       0,     0,     0,   118,   119,   120,   121,    91,    92,    93,
      94,    95,    96,    97,    98,     0,    99,   100,   101,     0,
     102,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,    98,     0,    99,   100,   101,     0,   102,     0,
       0,   103,   104,   105,     0,     0,     0,     0,     0,     0,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
       0,   105,     0,     0,   118,   119,   120,   121,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,   118,   119,   120,   121,    91,    92,    93,    94,
      95,    96,    97,    98,     0,    99,   100,   101,     0,   102,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,    98,     0,    99,   100,   101,     0,   102,     0,     0,
     103,   104,   105,     0,     0,     0,     0,     0,     0,   106,
     107,   108,   109,   110,     0,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,     0,
       0,     0,     0,   118,   119,   120,   121,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,   117,     0,     0,     0,     0,
       0,   118,   119,   120,   121,    91,    92,    93,    94,    95,
      96,    97,    98,     0,    99,   100,   101,     0,   102,     0,
       0,   103,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,    98,     0,    99,   100,   101,     0,   102,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,   118,   119,   120,   121,   114,   115,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,   118,   119,   120,   121
  };

  /* YYCHECK.  */
  const short int
  BisonParser::yycheck_[] =
  {
         5,     0,     6,     7,     6,     7,    46,    50,    16,     6,
       7,     6,     7,    21,     6,     7,     6,     7,    26,    47,
      50,    80,    30,    31,    32,     6,     7,     6,     7,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      83,    87,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    83,    62,    82,    64,    65,    66,    14,
      15,    16,    17,    18,    19,    20,    21,    87,    23,    24,
      25,    87,    27,     6,     7,    30,     6,     7,    87,    47,
      87,    87,    87,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    72,   117,
     118,   119,   120,   121,    87,    72,    88,   122,    73,    74,
      75,    76,     3,    84,    84,     6,     7,    58,    84,   137,
      85,    84,    13,    84,    84,    84,    91,    92,    93,    94,
      84,    22,    82,    82,   152,    82,    82,    82,    82,    35,
      31,    32,    -1,    82,   162,   163,   164,   165,    82,   167,
     168,   169,   170,   171,   172,   173,   174,    48,    88,    88,
      88,    88,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    86,    87,    -1,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
      48,    49,    -1,    51,    -1,    53,    54,    55,    56,     3,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    22,    -1,
      -1,    79,    80,    -1,    82,    -1,   261,    31,    32,    87,
      -1,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    51,    -1,    53,
      54,    55,    56,     3,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    80,    81,    82,    -1,
      -1,    31,    32,    87,    -1,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    51,    -1,    53,    54,    55,    56,     3,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      80,    81,    82,    -1,    -1,    31,    32,    87,    -1,    89,
      90,    -1,    -1,    -1,     3,    -1,    -1,     6,     7,    -1,
      -1,    -1,    48,    49,    13,    51,    -1,    53,    54,    55,
      56,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    31,    32,     6,     7,    72,    -1,    -1,    -1,
      -1,    13,    -1,    -1,    80,    -1,    82,    -1,    -1,    48,
      22,    87,    -1,    89,    90,    -1,    29,    -1,    -1,    31,
      32,    -1,    -1,    36,    37,    38,    39,    40,    -1,    42,
      43,    -1,    45,    72,    -1,    -1,    48,    50,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,
      89,    90,    14,    15,    16,    17,    18,    19,    20,    21,
      72,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      83,    -1,    85,    -1,    -1,    87,    -1,    89,    90,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    50,    -1,    -1,    -1,
      82,    -1,    -1,    85,    -1,    59,    60,    -1,    -1,    91,
      92,    93,    94,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    91,    92,
      93,    94,    14,    15,    16,    17,    18,    19,    20,    21,
      76,    23,    24,    25,    -1,    27,    -1,    -1,    30,    85,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    85,    -1,    59,    60,    -1,    -1,    91,
      92,    93,    94,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    85,    -1,    59,    60,    -1,    -1,    91,    92,
      93,    94,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    85,    -1,    59,    60,    -1,    -1,    91,    92,    93,
      94,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    88,    -1,    -1,    91,    92,    93,    94,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    85,    27,    -1,    -1,    30,    -1,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    -1,    91,    92,    93,
      94,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    29,    27,    -1,    -1,    30,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    42,    43,    -1,    45,
      -1,    -1,    -1,    -1,    50,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    83,    -1,    85,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    91,    92,
      93,    94,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    91,
      92,    93,    94,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    -1,    -1,    30,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    85,    -1,    59,    60,    -1,    -1,
      91,    92,    93,    94,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    85,    -1,    59,    60,    -1,    -1,    91,
      92,    93,    94,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,
      94,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    85,    -1,    59,    60,    -1,    -1,    91,    92,
      93,    94,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    23,
      24,    25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    85,    -1,    59,    60,    -1,    -1,    91,    92,    93,
      94,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    91,    92,    93,    94,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    -1,    -1,    30,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      85,    -1,    59,    60,    -1,    -1,    91,    92,    93,    94,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    94,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    25,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    85,
      -1,    59,    60,    -1,    -1,    91,    92,    93,    94,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    23,    24,    25,    -1,
      27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    -1,    27,    -1,
      -1,    30,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    60,    -1,    -1,    91,    92,    93,    94,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,    25,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    24,    25,    -1,    27,    -1,    -1,
      30,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    -1,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    91,    92,    93,    94,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    23,    24,    25,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93,    94
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  BisonParser::yystos_[] =
  {
         0,    96,    97,     0,    46,    98,    47,     3,     6,     7,
       8,     9,    10,    11,    12,    13,    22,    31,    32,    48,
      49,    51,    53,    54,    55,    56,    72,    79,    80,    82,
      87,    89,    90,    99,   101,    80,    29,    36,    37,    38,
      39,    40,    42,    43,    45,    50,    52,    83,    85,    29,
      36,    37,    38,    39,    40,    42,    43,    45,    50,    52,
      83,    85,    87,    82,    87,    87,    87,    87,     6,     7,
     101,    87,    87,    47,     6,     7,   101,     6,     7,     6,
       7,     6,     7,     6,     7,   101,    99,   100,   101,   101,
     101,    14,    15,    16,    17,    18,    19,    20,    21,    23,
      24,    25,    27,    30,    59,    60,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    82,    85,    91,    92,
      93,    94,   100,     6,     7,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,    86,   101,    72,     6,     7,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
      86,   101,    72,   101,   101,   101,   101,    88,     6,     7,
       6,     7,    50,    83,    50,    83,    50,    84,    84,    84,
      84,    84,    84,    84,    84,    81,    99,    88,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,    81,    82,
      82,    82,    82,    82,    82,   101,    82,    82,    82,    82,
      82,    82,   101,    88,    88,    88,    88,    88,    88,    88,
      88,   101,   101,   101,   101,     6,     7,   101,   101,   101,
     101,   101,   101,   101,   101,    99,    99,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    58,    99
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  BisonParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,    43,    45,    42,    47,    94,   326,   327,   328,    46,
     123,   125,    59,    61,    44,    60,    63,    40,    41,    33,
     126,    62,    37,    38,   124
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  BisonParser::yyr1_[] =
  {
         0,    95,    96,    97,    97,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  BisonParser::yyr2_[] =
  {
         0,     2,     3,     6,     0,     2,     0,     1,     4,     4,
       4,     4,     5,     5,     4,     4,     3,     3,     5,     5,
       4,     4,     5,     5,     4,     4,     4,     4,     4,     4,
       2,     5,     5,     3,     5,     2,     5,     7,     4,     4,
       5,     5,     5,     5,     5,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     1,     2,     1,     1,     1,     3,     4,     4,     4,
       4,     3,     3,     3,     2,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const BisonParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NUMERIC", "CADENA", "STRING",
  "VARIABLE", "ID", "WHILE", "BREAK", "IF", "PRINTN", "PRINT", "RAND",
  "EXPR_DIV", "EXPR_MAS", "EXPR_MAYOR", "EXPR_MAYORIGUAL", "EXPR_MENOR",
  "EXPR_MENORIGUAL", "EXPR_MENOS", "EXPR_MUL", "EXPR_NOT", "MOD_WORD",
  "_GT_", "_LT_", "INIT_RANDOM", "RANGE_RANDOM", "SWAP_ID_VAR", "SWAP_OP",
  "XOROP", "DEC", "INC", "DEC_CPP", "INC_CPP", "ID_ASIGNACION",
  "OP_ASIGN_ABR_MUL", "OP_ASIGN_ABR_DIV", "OP_ASIGN_ABR_MOD",
  "OP_ASIGN_ABR_MAS", "OP_ASIGN_ABR_MENOS", "OP_ASIGN_ABR_SHIFTLEFT",
  "OP_ASIGN_ABR_SHIFTRIGHT", "OP_ASIGN_ABR_AND", "OP_ASIGN_ABR_OR",
  "OP_ASIGN_ABR_POW", "PROC", "FUNCNAME", "CALL", "LETSET_ASSIGN", "TO",
  "MOVE", "PASCAL_ASSIGN", "MOV_ASM", "SUB_ASM", "ADD_ASM", "MUL_ASM",
  "IFX", "ELSE", "OR", "AND", "SHIFTRIGHT", "SHIFTLEFT", "ANDBITS",
  "ORBITS", "LT", "GT", "NE", "EQ", "LE", "GE", "'+'", "'-'", "'*'", "'/'",
  "'^'", "EXPR_ELEVADO", "NEGACION", "UMINUS", "'.'", "'{'", "'}'", "';'",
  "'='", "','", "'<'", "'?'", "'('", "')'", "'!'", "'~'", "'>'", "'%'",
  "'&'", "'|'", "$accept", "program", "funciones", "cuerpo", "stmt",
  "stmt_list", "expr", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const BisonParser::rhs_number_type
  BisonParser::yyrhs_[] =
  {
        96,     0,    -1,    97,    98,    79,    -1,    97,    46,    47,
      80,   100,    81,    -1,    -1,    98,    99,    -1,    -1,    82,
      -1,     6,    83,   101,    82,    -1,     6,    50,   101,    82,
      -1,    51,   101,    50,     6,    -1,    51,   101,    50,     7,
      -1,    53,     6,    84,   101,    82,    -1,    53,     7,    84,
     101,    82,    -1,     6,    85,    72,   101,    -1,     7,    85,
      72,   101,    -1,     6,    52,   101,    -1,     7,    52,   101,
      -1,    49,     6,    83,   101,    82,    -1,    49,     6,    50,
     101,    82,    -1,     7,    83,   101,    82,    -1,     7,    50,
     101,    82,    -1,    49,     7,    83,   101,    82,    -1,    49,
       7,    50,   101,    82,    -1,     6,    83,    86,    82,    -1,
       7,    83,    86,    82,    -1,     6,    29,     6,    82,    -1,
       7,    29,     6,    82,    -1,     6,    29,     7,    82,    -1,
       7,    29,     7,    82,    -1,   101,    82,    -1,    11,    87,
     101,    88,    82,    -1,    12,    87,   101,    88,    82,    -1,
      80,   100,    81,    -1,     8,    87,   101,    88,    99,    -1,
       9,    82,    -1,    10,    87,   101,    88,    99,    -1,    10,
      87,   101,    88,    99,    58,    99,    -1,     6,    39,   101,
      82,    -1,     7,    39,   101,    82,    -1,    55,     6,    84,
     101,    82,    -1,    55,     7,    84,   101,    82,    -1,    54,
       6,    84,   101,    82,    -1,    54,     7,    84,   101,    82,
      -1,    56,     6,    84,   101,    82,    -1,    56,     7,    84,
     101,    82,    -1,     6,    40,   101,    -1,     7,    40,   101,
      -1,     6,    38,   101,    -1,     7,    38,   101,    -1,     6,
      36,   101,    -1,     7,    36,   101,    -1,     6,    37,   101,
      -1,     7,    37,   101,    -1,     6,    42,   101,    -1,     7,
      42,   101,    -1,     6,    43,   101,    -1,     7,    43,   101,
      -1,     6,    45,   101,    -1,     7,    45,   101,    -1,    -1,
      99,    -1,   100,    99,    -1,     3,    -1,     7,    -1,     6,
      -1,    13,    87,    88,    -1,    31,    87,     7,    88,    -1,
      31,    87,     6,    88,    -1,    32,    87,     7,    88,    -1,
      32,    87,     6,    88,    -1,   101,    30,   101,    -1,   101,
      27,   101,    -1,   101,    71,   101,    -1,    72,   101,    -1,
      89,   101,    -1,    90,   101,    -1,    22,   101,    -1,   101,
      15,   101,    -1,   101,    72,   101,    -1,   101,    20,   101,
      -1,   101,    73,   101,    -1,   101,    21,   101,    -1,   101,
      74,   101,    -1,   101,    14,   101,    -1,   101,    85,   101,
      -1,   101,    18,   101,    -1,   101,    25,   101,    -1,   101,
      91,   101,    -1,   101,    16,   101,    -1,   101,    24,   101,
      -1,   101,    75,   101,    -1,   101,    76,   101,    -1,   101,
      92,   101,    -1,   101,    23,   101,    -1,   101,    70,   101,
      -1,   101,    17,   101,    -1,   101,    69,   101,    -1,   101,
      19,   101,    -1,   101,    67,   101,    -1,   101,    68,   101,
      -1,   101,    60,   101,    -1,   101,    59,   101,    -1,   101,
      93,   101,    -1,   101,    94,   101,    -1,    87,   101,    88,
      -1,    48,    47,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  BisonParser::yyprhs_[] =
  {
         0,     0,     3,     7,    14,    15,    18,    19,    21,    26,
      31,    36,    41,    47,    53,    58,    63,    67,    71,    77,
      83,    88,    93,    99,   105,   110,   115,   120,   125,   130,
     135,   138,   144,   150,   154,   160,   163,   169,   177,   182,
     187,   193,   199,   205,   211,   217,   223,   227,   231,   235,
     239,   243,   247,   251,   255,   259,   263,   267,   271,   275,
     279,   280,   282,   285,   287,   289,   291,   295,   300,   305,
     310,   315,   319,   323,   327,   330,   333,   336,   339,   343,
     347,   351,   355,   359,   363,   367,   371,   375,   379,   383,
     387,   391,   395,   399,   403,   407,   411,   415,   419,   423,
     427,   431,   435,   439,   443,   447,   451
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  BisonParser::yyrline_[] =
  {
         0,   192,   192,   198,   201,   205,   209,   213,   216,   219,
     222,   225,   228,   231,   234,   237,   240,   243,   246,   249,
     252,   255,   258,   261,   264,   267,   270,   273,   276,   279,
     282,   285,   288,   291,   294,   297,   300,   303,   306,   309,
     312,   315,   318,   321,   324,   327,   330,   333,   336,   339,
     342,   345,   348,   351,   354,   357,   360,   363,   366,   369,
     372,   376,   379,   385,   388,   396,   399,   402,   405,   408,
     411,   414,   417,   420,   423,   426,   429,   432,   435,   438,
     441,   444,   447,   450,   453,   456,   459,   462,   465,   468,
     471,   474,   477,   480,   483,   486,   489,   492,   495,   498,
     501,   504,   507,   510,   513,   516,   519
  };

  // Print the state stack on the debug stream.
  void
  BisonParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  BisonParser::yy_reduce_print_ (int yyrule)
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
  BisonParser::token_number_type
  BisonParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,     2,     2,    92,    93,     2,
      87,    88,    73,    71,    84,    72,    79,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    82,
      85,    83,    91,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    75,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,    94,    81,    90,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    76,    77,    78
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int BisonParser::yyeof_ = 0;
  const int BisonParser::yylast_ = 2275;
  const int BisonParser::yynnts_ = 7;
  const int BisonParser::yyempty_ = -2;
  const int BisonParser::yyfinal_ = 3;
  const int BisonParser::yyterror_ = 1;
  const int BisonParser::yyerrcode_ = 256;
  const int BisonParser::yyntokens_ = 95;

  const unsigned int BisonParser::yyuser_token_number_max_ = 328;
  const BisonParser::token_number_type BisonParser::yyundef_token_ = 2;


/* Line 1136 of lalr1.cc  */
#line 5 "yare.y"
} // YL

/* Line 1136 of lalr1.cc  */
#line 2454 "yare.tab.c"


/* Line 1138 of lalr1.cc  */
#line 523 "yare.y"


// We have to implement the error function
void YL::BisonParser::error(const YL::BisonParser::location_type &loc, const std::string &msg) {
	std::cerr << "Error: " << msg << std::endl;
}

// Now that we have the Parser declared, we can declare the Scanner and implement
// the yylex function
#include "YareScanner.h"
static int yylex(YL::BisonParser::semantic_type * yylval, YL::FlexScanner &scanner) {
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
	free (p);
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

				case YL::BisonParser::token::WHILE: 
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

				case YL::BisonParser::token::BREAK:
					if(spLoop < 0)	{
						cerr << "\nWarning: break fuera de ciclo";
						return 0.0L;
					} else {
						return (pilaLoop[spLoop] = 0);
					}
				
				case YL::BisonParser::token::IF:
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

				case YL::BisonParser::token::PRINTN:
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

				case YL::BisonParser::token::PRINT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						// Check if the node is a virtual var:	
						cout.precision(16);
						if(p->opr.op[0]->type == typeId) 
							cout << sym[p->opr.op[0]->id.i] << endl;
						 else 
							cout << run(p->opr.op[0]) << endl;
						return 0.0L;
					}

				case YL::BisonParser::token::CALL:
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

				case YL::BisonParser::token::RAND:
					if((spLoop < 0) || pilaLoop[spLoop])
						return (long double)(rand() % 101);
					return 0.0L;

				case YL::BisonParser::token::XOROP:
					if((spLoop < 0) || pilaLoop[spLoop])
						return ((long long)run(p->opr.op[0]) ^ (long long)run(p->opr.op[1]));
					return 0.0L;

				case YL::BisonParser::token::RANGE_RANDOM:
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

				case YL::BisonParser::token::SWAP_OP:
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
				case YL::BisonParser::token::OP_ASIGN_ABR_MAS:
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

				case YL::BisonParser::token::OP_ASIGN_ABR_MENOS:
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

				case YL::BisonParser::token::OP_ASIGN_ABR_MOD:
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

				case YL::BisonParser::token::OP_ASIGN_ABR_SHIFTRIGHT:
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

				case YL::BisonParser::token::OP_ASIGN_ABR_AND:
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

				case YL::BisonParser::token::OP_ASIGN_ABR_SHIFTLEFT:
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

				case YL::BisonParser::token::OP_ASIGN_ABR_POW:
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
				case YL::BisonParser::token::OP_ASIGN_ABR_MUL:
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

				case YL::BisonParser::token::OP_ASIGN_ABR_DIV:
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

				case YL::BisonParser::token::INIT_RANDOM:
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
						}
					}
					return 0.0L;

				case YL::BisonParser::token::DEC:
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

				case YL::BisonParser::token::INC:
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

				case YL::BisonParser::token::INC_CPP:
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

				case YL::BisonParser::token::DEC_CPP:
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
				case YL::BisonParser::token::UMINUS:
					if((spLoop < 0) || pilaLoop[spLoop])
						return -run(p->opr.op[0]);
					return 0.0L;

				////// Creación de identificadores:
				case YL::BisonParser::token::ID_ASIGNACION:
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
					if((spLoop < 0) || pilaLoop[spLoop])
						return (long long)run(p->opr.op[0]) % (long long)run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::LT:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) < run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::GT:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) > run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::NEGACION:		// "no"|"not"|!|~
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return !run(p->opr.op[0]);
					return 0.0L;
				
				case YL::BisonParser::token::GE:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return run(p->opr.op[0]) >= run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::LE:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) <= run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::NE:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) != run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::EQ:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return run(p->opr.op[0]) == run(p->opr.op[1]);
					return 0.0L;
				
				case YL::BisonParser::token::AND:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) && run(p->opr.op[1]);
					return 0.0L;
			
				case YL::BisonParser::token::OR:
					if((spLoop < 0) || pilaLoop[spLoop])
						return run(p->opr.op[0]) || run(p->opr.op[1]);
					return 0.0L;
				
				case YL::BisonParser::token::ANDBITS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) & (long long)run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::ORBITS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) | (long long)run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::SHIFTLEFT:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) << (long long)run(p->opr.op[1]);
					return 0.0L;

				case YL::BisonParser::token::SHIFTRIGHT:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return (long long)run(p->opr.op[0]) >> (long long)run(p->opr.op[1]);
					return 0.0L;
			}
	}
}

void swap(nodeType *p) {
	int temp = sym[p->opr.op[0]->id.i];
	sym[p->opr.op[0]->id.i] = sym[p->opr.op[1]->id.i];
	sym[p->opr.op[1]->id.i] = temp;
}
	

