/* A Bison parser, made by GNU Bison 2.5.  */

/* Skeleton interface for Bison LALR(1) parsers in C++
   
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

/* C++ LALR(1) parser skeleton written by Akim Demaille.  */

#ifndef PARSER_HEADER_H
# define PARSER_HEADER_H

/* "%code requires" blocks.  */

/* Line 35 of lalr1.cc  */
#line 28 "yare.y"

	namespace YL {
		class FlexScanner;
	}



/* Line 35 of lalr1.cc  */
#line 51 "yare.tab.h"


#include <string>
#include <iostream>
#include "stack.hh"
#include "location.hh"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Line 35 of lalr1.cc  */
#line 5 "yare.y"
namespace YL {

/* Line 35 of lalr1.cc  */
#line 83 "yare.tab.h"

  /// A Bison parser.
  class YareParser
  {
  public:
    /// Symbol semantic values.
#ifndef YYSTYPE
    union semantic_type
    {

/* Line 35 of lalr1.cc  */
#line 82 "yare.y"

	long double valnum;
	char cadena[1000];
	char sIndex;
	std::string *str;
	// Identificador:
	char identificador[100];
	char nameFunction[100];
	union nodeTypeTag *nPtr;



/* Line 35 of lalr1.cc  */
#line 109 "yare.tab.h"
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;
    /// Tokens.
    struct token
    {
      /* Tokens.  */
   enum yytokentype {
     NUMERIC = 258,
     VARIABLE = 259,
     CADENA = 260,
     ID = 261,
     WHILE = 262,
     BREAK = 263,
     IF = 264,
     PRINTN = 265,
     PRINT = 266,
     PUTS = 267,
     RAND = 268,
     EXPR_DIV = 269,
     EXPR_MAS = 270,
     EXPR_MAYOR = 271,
     EXPR_MAYORIGUAL = 272,
     EXPR_MENOR = 273,
     EXPR_MENORIGUAL = 274,
     EXPR_MENOS = 275,
     EXPR_MUL = 276,
     EXPR_IGUAL = 277,
     EXPR_NOT = 278,
     MOD_WORD = 279,
     _GT_ = 280,
     _LT_ = 281,
     INIT_RANDOM = 282,
     RANGE_RANDOM = 283,
     SWAP_ID_VAR = 284,
     SWAP_OP = 285,
     XOROP = 286,
     DEC = 287,
     INC = 288,
     DEC_CPP = 289,
     INC_CPP = 290,
     ID_ASIGNACION = 291,
     OP_ASIGN_ABR_MUL = 292,
     OP_ASIGN_ABR_DIV = 293,
     OP_ASIGN_ABR_MOD = 294,
     OP_ASIGN_ABR_MAS = 295,
     OP_ASIGN_ABR_MENOS = 296,
     OP_ASIGN_ABR_SHIFTLEFT = 297,
     OP_ASIGN_ABR_SHIFTRIGHT = 298,
     OP_ASIGN_ABR_AND = 299,
     OP_ASIGN_ABR_OR = 300,
     OP_ASIGN_ABR_POW = 301,
     PROC = 302,
     FUNCNAME = 303,
     CALL = 304,
     LETSET_ASSIGN = 305,
     TO = 306,
     MOVE = 307,
     PASCAL_ASSIGN = 308,
     MOV_ASM = 309,
     SUB_ASM = 310,
     ADD_ASM = 311,
     MUL_ASM = 312,
     ABS = 313,
     FACTORIAL = 314,
     SUMATORIA = 315,
     SQRT = 316,
     ACOS = 317,
     ASIN = 318,
     ATAN = 319,
     CEIL = 320,
     COS = 321,
     COSH = 322,
     EXP = 323,
     FLOOR = 324,
     LN = 325,
     SIN = 326,
     SINH = 327,
     TAN = 328,
     TANH = 329,
     FACE_HAPPY = 330,
     FACE_SAD = 331,
     FACE_NO = 332,
     PUSH = 333,
     POP = 334,
     IFX = 335,
     ELSE = 336,
     OR = 337,
     AND = 338,
     SHIFTRIGHT = 339,
     SHIFTLEFT = 340,
     ANDBITS = 341,
     ORBITS = 342,
     LT = 343,
     GT = 344,
     NE = 345,
     EQ = 346,
     LE = 347,
     GE = 348,
     EXPR_ELEVADO = 349,
     NEGACION = 350,
     UMINUS = 351
   };

    };
    /// Token type.
    typedef token::yytokentype token_type;

    /// Build a parser object.
    YareParser (YL::FlexScanner &scanner_yyarg);
    virtual ~YareParser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

  private:
    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Generate an error message.
    /// \param state   the state where the error occurred.
    /// \param tok     the lookahead token.
    virtual std::string yysyntax_error_ (int yystate, int tok);

#if YYDEBUG
    /// \brief Report a symbol value on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_value_print_ (int yytype,
					 const semantic_type* yyvaluep,
					 const location_type* yylocationp);
    /// \brief Report a symbol on the debug stream.
    /// \param yytype       The token type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    virtual void yy_symbol_print_ (int yytype,
				   const semantic_type* yyvaluep,
				   const location_type* yylocationp);
#endif


    /// State numbers.
    typedef int state_type;
    /// State stack type.
    typedef stack<state_type>    state_stack_type;
    /// Semantic value stack type.
    typedef stack<semantic_type> semantic_stack_type;
    /// location stack type.
    typedef stack<location_type> location_stack_type;

    /// The state stack.
    state_stack_type yystate_stack_;
    /// The semantic value stack.
    semantic_stack_type yysemantic_stack_;
    /// The location stack.
    location_stack_type yylocation_stack_;

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    /// Internal symbol numbers.
    typedef unsigned char token_number_type;
    /* Tables.  */
    /// For a state, the index in \a yytable_ of its portion.
    static const short int yypact_[];
    static const signed char yypact_ninf_;

    /// For a state, default reduction number.
    /// Unless\a  yytable_ specifies something else to do.
    /// Zero means the default is an error.
    static const unsigned char yydefact_[];

    static const short int yypgoto_[];
    static const short int yydefgoto_[];

    /// What to do in a state.
    /// \a yytable_[yypact_[s]]: what to do in state \a s.
    /// - if positive, shift that token.
    /// - if negative, reduce the rule which number is the opposite.
    /// - if zero, do what YYDEFACT says.
    static const unsigned short int yytable_[];
    static const signed char yytable_ninf_;

    static const short int yycheck_[];

    /// For a state, its accessing symbol.
    static const unsigned char yystos_[];

    /// For a rule, its LHS.
    static const unsigned char yyr1_[];
    /// For a rule, its RHS length.
    static const unsigned char yyr2_[];

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif

#if YYDEBUG
    /// A type to store symbol numbers and -1.
    typedef signed char rhs_number_type;
    /// A `-1'-separated list of the rules' RHS.
    static const rhs_number_type yyrhs_[];
    /// For each rule, the index of the first RHS symbol in \a yyrhs_.
    static const unsigned short int yyprhs_[];
    /// For each rule, its source line number.
    static const unsigned short int yyrline_[];
    /// For each scanner token number, its symbol number.
    static const unsigned short int yytoken_number_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /* Debugging.  */
    int yydebug_;
    std::ostream* yycdebug_;
#endif

    /// Convert a scanner token number \a t to a symbol number.
    token_number_type yytranslate_ (int t);

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg        Why this token is reclaimed.
    /// \param yytype       The symbol type.
    /// \param yyvaluep     Its semantic value.
    /// \param yylocationp  Its location.
    inline void yydestruct_ (const char* yymsg,
			     int yytype,
			     semantic_type* yyvaluep,
			     location_type* yylocationp);

    /// Pop \a n symbols the three stacks.
    inline void yypop_ (unsigned int n = 1);

    /* Constants.  */
    static const int yyeof_;
    /* LAST_ -- Last index in TABLE_.  */
    static const int yylast_;
    static const int yynnts_;
    static const int yyempty_;
    static const int yyfinal_;
    static const int yyterror_;
    static const int yyerrcode_;
    static const int yyntokens_;
    static const unsigned int yyuser_token_number_max_;
    static const token_number_type yyundef_token_;

    /* User arguments.  */
    YL::FlexScanner &scanner;
  };

/* Line 35 of lalr1.cc  */
#line 5 "yare.y"
} // YL

/* Line 35 of lalr1.cc  */
#line 393 "yare.tab.h"



#endif /* ! defined PARSER_HEADER_H */
