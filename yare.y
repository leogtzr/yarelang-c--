///////////////////// Yare /////////////////////////////
// Autor: Leo Gutiérrez Ramírez <leorocko13@hotmail.com>
///////////////////// Yare /////////////////////////////


%require "2.4.1"
%skeleton "lalr1.cc"

%defines
%define namespace "YL"
%define parser_class_name "YareParser"
%parse-param { YL::FlexScanner &scanner }
%lex-param   { YL::FlexScanner &scanner }

%{
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

	// The symbol table:
	long double sym[26];
	Variables *vars = NULL;
	Pila *pila = NULL;
	struct proc *procs = NULL;
	Arrays *arrays = NULL;
	char opVar[4];
%}

%code requires {
	namespace YL {
		class FlexScanner;
	}
}

%code {
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
	
}

%union {
	long double valnum;
	char cadena[1000];
	char sIndex;
	std::string *str;
	// Identificador:
	char identificador[100];
	char nameFunction[100];
	union nodeTypeTag *nPtr;
}

// ********************* Data types and var's ***********************/
%token NUMERIC
%token VARIABLE
%token CADENA
%token ID		// :id:
%token ARRAY_ID
%token ARRAY_ASSIGN			// @id
%token ARRAY_ADD_ELEMENT 	// @a.add(expr)
%token ARRAY_PUT			// @a.put(expr);
%token ARRAY_PUTFRONT		// @a.putfront(expr);
%token ARRAY_SIZE			// @a.size();
%token ARRAY_SHIT			// @a.size();
%token ARRAY_SORT			// @a.sort(true);
%token ARRAY_DEL 			// @a.del(expr);
%token ARRAY_FILL			// @a.fill(expr);
%token ARRAY_CLEAR			// @a.clear();
%token ARRAY_MIN			// @a.min();
%token ARRAY_MAX			// @a.max();
%token ARRAY_HEAD			// @a.head();
%token ARRAY_TAIL			// @a.tail();
%token ARRAY_AVERAGE			// @a.average();

// ******************** OPVAR TOKENS **********************************
%token OPVAR_OP
%token OPVAR_ADD 
%token OPVAR_SUB 
%token OPVAR_MUL 
%token OPVAR_DIV 
%token OPVAR_POW

// Clear vars:
%token CLEARVARS			// clearvars();

/// Arrays tokens:
%token ARRAY_C			// array_c(id_array);

/********************** Sentences *********************************/
// Control structures and more:
%token WHILE	// @todo while|mientras
%token DO_WHILE	// do stmt while();
%token FOREACH	// FOREACH
%token ELIPSIS
%token SYSTEM 	// system("cadena");
%token EXIT
%token DO 		// token DO para el ciclo while
%token BREAK	// "break";
%token IF		// "si" | "if"
%token READ
%token READP 	// read("holix");
%token PRASCII 	// prascii("holix");
///////////////////////////// Simple sentences: //////////////////
%token PRINTN 		// @todo printn(expr), prints out the expression with new line
%token PRINT		// Without new line
%token PUTS 		// PUTS sentence, to write strings to console.
%token PUTSN 		// PUTS sentence, to write strings to console.
%token RAND			// rand(expr);
///////////// Expressions operators with words //////////////////////////////
%token EXPR_DIV				// "entre"
%token EXPR_MAS				// "mas"
%token EXPR_MAYOR			// "mayor"
%token EXPR_MAYORIGUAL		// "mayorigual"
%token EXPR_MENOR			// "menor"
%token EXPR_MENORIGUAL		// "menorigual"
%token EXPR_MENOS			// "menos"
%token EXPR_MUL				// "por"
%token EXPR_IGUAL           // "igual"
%token EXPR_NOT				// "not" | "no"
%token MOD_WORD				// expr "mod" expr
//////////// Shell expressions operators (-lt) (-gt) ... ////////////////////
%token _GT_		// "-gt"	// DONE
%token _LT_		// "-lt"	// DONE
/////////// Math functions //////////////////////////////////////////////////
///////////////////    Miscellany  //////////////////////////////////////////
%token INIT_RANDOM				// :id:=? | a=?;
%token RANGE_RANDOM			// 123 ...? 78234, generate randon between this expressions.
%token SWAP_ID_VAR			// x <-> z | :x:<->x | :x:<->:z: | x<->:z:
%token SWAP_OP				// <->
%token XOROP				// xorop
////////////////// Incrementos y decrementos con funciones /////////////////
%token DEC				// dec(:x:) | dec(x)
%token INC				// inc(:x:) | inc(x)
%token DEC_CPP			// x-- | :x:--
%token INC_CPP			// x++ | :x:++
////////////////// Identificadores /////////////////////////////////////////
%token ID_ASIGNACION				// :id: = expr
///////////////// Operadores de asignación abreviados //////////////////////
%token OP_ASIGN_ABR_MUL 		// *=			// DONE!
%token OP_ASIGN_ABR_DIV 		// /=			// DONE!
%token OP_ASIGN_ABR_MOD 		// %=			// DONE
%token OP_ASIGN_ABR_MAS 		// +=			// DONE
%token OP_ASIGN_ABR_MENOS 		// -=			// DONE
%token OP_ASIGN_ABR_SHIFTLEFT 	// <<=			// DONE
%token OP_ASIGN_ABR_SHIFTRIGHT 	// >>=			// DONE
%token OP_ASIGN_ABR_AND 		// &=			// DONE
%token OP_ASIGN_ABR_OR 			// |=			// DONE
%token OP_ASIGN_ABR_POW 		// ^=			// DONE
/////////////// Procedimientos y funciones ////////////////////////////////
%token PROC					// proc $pedos$ {stmt's}
%token FUNCNAME				// $kjlaskjjldsjld$
%token CALL					// "call $proc$
////////////// Asignaciones flexibles ////////////////////////////////////
%token LETSET_ASSIGN		// (let x = expr) || (set x = expr)
%token TO /* Useful with: let|set x to 1+2; x to 1.245; etc.... */
%token MOVE 				// move 1 + 2 to x;
%token PASCAL_ASSIGN		// :x::=1+2; x := .4; DONE
///////////// ASSEMBLY EXPRESSIONS ///////////////////////////////////////
%token MOV_ASM					// mov x, expr; | mov :id:, expr DONE
%token SUB_ASM					// sub x, expr; | sub :id:, expr DONE
%token ADD_ASM					// add x, expr; | add :id:, expr DONE
%token MUL_ASM					// mul x, expr;	| mul :id:, expr DONE

//////////// Funciones trigonométricas //////////////////////////////////
%token ABS
%token FACTORIAL 
%token SUMATORIA
%token SQRT
%token ACOS
%token ASIN
%token ATAN
%token CEIL
%token COS
%token COSH
%token EXP
%token FLOOR
%token LN
%token SIN
%token SINH
%token TAN
%token TANH

///////////// Smileys

%token FACE_HAPPY		// :)
%token FACE_SAD			// :(
%token FACE_NO			// :|

/////////// FUNCIONES DE PILA ///////////////////////////////////////////
%token PUSH
%token POP
%token STACK_SIZE

%type <valnum> NUMERIC 
%type <nPtr> expr
%type <nPtr> cuerpo
%type <nPtr> stmt
%type <nPtr> stmt_list
%type <sIndex> VARIABLE
%type <identificador> ID
%type <identificador> ARRAY_ID
%type <cadena> CADENA
%type <nameFunction> FUNCNAME

%nonassoc IFX
%nonassoc ELSE

%left OR
%left AND
%left GE EXPR_MAYORIGUAL LE EXPR_MENORIGUAL EQ EXPR_IGUAL NE GT EXPR_MAYOR LT EXPR_MENOR _LT_ _GT_ ORBITS ANDBITS SHIFTLEFT SHIFTRIGHT
%left '+' EXPR_MAS '-' EXPR_MENOS
%left '*' EXPR_MUL '/' EXPR_DIV
%left '%' MOD_WORD
%left '^'
%left EXPR_ELEVADO			// expr "elevado" expr <-> expr^expr 
%nonassoc UMINUS NEGACION 

%%

program:
	funciones cuerpo '.' {
	if(vars != NULL) {
		delete(vars);
	}
	if(pila != NULL) {
		delete(pila);
	}
	if(arrays != NULL) {
		delete(arrays);
	}
	exit(EXIT_SUCCESS);
}
;

funciones:
	funciones PROC FUNCNAME '{' stmt_list '}' {
		push_l_proc(&procs, $3, $5);
}
| {;}
;

cuerpo:
	cuerpo stmt		{ 
		run($2);			/* Ejecutar los nodos */ 
		freeNode($2); 	/* Liberar los nodos */

	}
	| {;}
	;

stmt:
	';'	{ 
		$$ = opr(';', 2, NULL, NULL); 
	}	
	| VARIABLE '=' expr ';' { 
		$$ = opr('=', 2, id($1), $3); 
	}
	| VARIABLE TO expr ';' {		// x to 1 + 2; 
		$$ = opr('=', 2, id($1), $3); 
	}
	| MOVE expr TO VARIABLE {
		$$ = opr('=', 2, id($4), $2);
	}
	| MOVE expr TO ID {
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($4), $2);
	}
	| MOV_ASM VARIABLE ',' expr ';' {
		$$ = opr('=', 2, id($2), $4);
	}
	| MOV_ASM ID ',' expr ';' {
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($2), $4);
	}
	| VARIABLE '<''-' expr {
		$$ = opr('=', 2, id($1), $4);
	}
	| ID '<''-' expr {
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($1), $4);
	}
	| VARIABLE PASCAL_ASSIGN expr {
		$$ = opr('=', 2, id($1), $3);
	}
	| ID PASCAL_ASSIGN expr {
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($1), $3);
	}
	| LETSET_ASSIGN VARIABLE '=' expr ';' {
		$$ = opr('=', 2, id($2), $4); 
	}
	| LETSET_ASSIGN VARIABLE TO expr ';' {
		$$ = opr('=', 2, id($2), $4); 
	}
	| ID '=' expr ';'					{ 
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($1), $3); 
	}
	| ID TO expr ';'					{ 	// :x: to 1 + 2;
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($1), $3); 
	}
	| LETSET_ASSIGN ID '=' expr ';'					{ 
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($2), $4); 
	}
	| LETSET_ASSIGN ID TO expr ';'					{ 
		$$ = opr(YL::YareParser::token::ID_ASIGNACION, 2, idS($2), $4); 
	}
	| VARIABLE '=' '?' ';' {
		$$ = opr(YL::YareParser::token::INIT_RANDOM, 1, id($1));
	}
	| ID '=' '?' ';' {
		$$ = opr(YL::YareParser::token::INIT_RANDOM, 1, idS($1));
	}
	| VARIABLE SWAP_OP VARIABLE ';' {
		$$ = opr(YL::YareParser::token::SWAP_OP, 2, id($1), id($3));
	}
	| ID SWAP_OP VARIABLE ';' {
		$$ = opr(YL::YareParser::token::SWAP_OP, 2, idS($1), id($3));
	}
	| VARIABLE SWAP_OP ID ';' {
		$$ = opr(YL::YareParser::token::SWAP_OP, 2, id($1), idS($3));
	}
	| ID SWAP_OP ID ';' {
		$$ = opr(YL::YareParser::token::SWAP_OP, 2, idS($1), idS($3));
	}
	| expr ';' 	{ 
		$$ = $1; 
	}
	| VARIABLE '=' FACE_HAPPY ';'		{ $$ = opr(YL::YareParser::token::FACE_HAPPY, 1, id($1)); }
	| VARIABLE '=' FACE_SAD ';'			{ $$ = opr(YL::YareParser::token::FACE_SAD, 1, id($1)); }
	| VARIABLE '=' FACE_NO ';'			{ $$ = opr(YL::YareParser::token::FACE_NO, 1, id($1)); }
	| ID '=' FACE_HAPPY ';'		{ $$ = opr(YL::YareParser::token::FACE_HAPPY, 1, idS($1)); }
	| ID '=' FACE_SAD ';'			{ $$ = opr(YL::YareParser::token::FACE_SAD, 1, idS($1)); }
	| ID '=' FACE_NO ';'			{ $$ = opr(YL::YareParser::token::FACE_NO, 1, idS($1)); }
	| PRINTN '(' expr ')'';' {
		$$ = opr(YL::YareParser::token::PRINTN, 1, $3); 
	}
	| PRASCII '(' expr ')' ';' {
		$$ = opr(YL::YareParser::token::PRASCII, 1, $3);
	}
	| PRINT '(' expr ')'';' {
		$$ = opr(YL::YareParser::token::PRINT, 1, $3); 
	}
	| '{' stmt_list	'}'		{ 
		$$ = $2; 
	}
	| PUTS '(' CADENA ')' ';'		{
		$$ = opr(YL::YareParser::token::PUTS, 1, conStr($3, typeCadena));
	}
	| PUTS CADENA ';'		{
		$$ = opr(YL::YareParser::token::PUTS, 1, conStr($2, typeCadena));
	}
	| PUTSN '(' CADENA ')' ';'		{
		$$ = opr(YL::YareParser::token::PUTSN, 1, conStr($3, typeCadena));
	}
	| PUTSN CADENA ';'		{
		$$ = opr(YL::YareParser::token::PUTSN, 1, conStr($2, typeCadena));
	}
	| WHILE	'(' expr ')' stmt	{ 
		$$ = opr(YL::YareParser::token::WHILE, 2, $3, $5); 
	}
	| WHILE expr stmt	{ 
		$$ = opr(YL::YareParser::token::WHILE, 2, $2, $3); 
	}
	| DO stmt WHILE '(' expr ')'';' {
		$$ = opr(YL::YareParser::token::DO_WHILE, 2, $2, $5);
	}
	| FOREACH '(' expr ELIPSIS expr ',' VARIABLE ')' stmt {
		$$ = opr(YL::YareParser::token::FOREACH, 4, $3, $5, id($7), $9);
	}
	| BREAK ';' 			{
		$$ = opr(YL::YareParser::token::BREAK, 0);
	}
	| SYSTEM '(' CADENA ')'';' {
		$$ = opr(YL::YareParser::token::SYSTEM, 1, conStr($3, typeCadena));	
	}
	| EXIT '(' expr ')'';' {
		$$ = opr(YL::YareParser::token::EXIT, 1, $3);		
	}
	| IF '(' expr ')'	stmt %prec	IFX		{ 
		$$ = opr(YL::YareParser::token::IF, 2, $3, $5); 
	}
	| IF '(' expr ')' stmt ELSE stmt	{ 
		$$ = opr(YL::YareParser::token::IF, 3, $3, $5, $7); 
	}
	| VARIABLE OP_ASIGN_ABR_MAS expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MAS expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS($1), $3);
	}
	| ADD_ASM VARIABLE ',' expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, id($2), $4);
	}
	| ADD_ASM ID ',' expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MAS, 2, idS($2), $4);
	}
	| SUB_ASM VARIABLE ',' expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id($2), $4);
	}
	| SUB_ASM ID ',' expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS($2), $4);
	}
	| MUL_ASM VARIABLE ',' expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id($2), $4);
	}
	| MUL_ASM ID ',' expr ';' {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS($2), $4);
	}
	| VARIABLE OP_ASIGN_ABR_MENOS expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MENOS expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MENOS, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_MOD expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MOD expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MOD, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_SHIFTLEFT expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, id($1), $3);			
	}
	| ID OP_ASIGN_ABR_SHIFTLEFT expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT, 2, idS($1), $3);			
	}
	| VARIABLE OP_ASIGN_ABR_MUL expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MUL expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_MUL, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_DIV expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_DIV expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_DIV, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_SHIFTRIGHT expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_SHIFTRIGHT expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_AND expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_AND expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_AND, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_POW expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_POW expr {
		$$ = opr(YL::YareParser::token::OP_ASIGN_ABR_POW, 2, idS($1), $3);
	}
	| PUSH expr {
		$$ = opr(YL::YareParser::token::PUSH, 1, $2);	
	}
	| ARRAY_ID '[' expr ']' '=' expr ';' {
		$$ = opr(YL::YareParser::token::ARRAY_ASSIGN, 3, idA($1), $3, $6);
	}
	| ARRAY_C '(' ARRAY_ID ')' ';' {
		$$ = opr(YL::YareParser::token::ARRAY_C, 1, idA($3));
	}
	| ARRAY_ID '.' ARRAY_PUT '(' expr ')' ';' {
		$$ = opr(YL::YareParser::token::ARRAY_PUT, 2, idA($1), $5);
	}
	| ARRAY_ID '.' ARRAY_PUTFRONT '(' expr ')' ';' {
		$$ = opr(YL::YareParser::token::ARRAY_PUTFRONT, 2, idA($1), $5);
	}
	| ARRAY_ID '.' ARRAY_SORT '(' expr ')' ';' {
		$$ = opr(YL::YareParser::token::ARRAY_SORT, 2, idA($1), $5);
	}
	| ARRAY_ID '.' ARRAY_DEL '(' expr ')' ';' {
		$$ = opr(YL::YareParser::token::ARRAY_DEL, 2, idA($1), $5);
	}
	| ARRAY_ID '.' ARRAY_FILL '(' expr ')' ';' {
		$$ = opr(YL::YareParser::token::ARRAY_FILL, 2, idA($1), $5);
	}
	| ARRAY_ID '.' ARRAY_CLEAR '(' ')' ';' {
		$$ = opr(YL::YareParser::token::ARRAY_CLEAR, 1, idA($1));
	}
	| OPVAR_OP '=''+'';'					{ 
		$$ = opr(YL::YareParser::token::OPVAR_ADD, 0); 
	}
	| OPVAR_OP '=''-'';'	{ 
		$$ = opr(YL::YareParser::token::OPVAR_SUB, 0); 
	}
	| OPVAR_OP '=''*'';'	{ 
		$$ = opr(YL::YareParser::token::OPVAR_MUL, 0); 
	}
	| OPVAR_OP '=''/'';'	{ 
		$$ = opr(YL::YareParser::token::OPVAR_DIV, 0); 
	}
	| OPVAR_OP '=''^'';'	{ 
		$$ = opr(YL::YareParser::token::OPVAR_POW, 0); 
	}
	| CLEARVARS '(' ')' {
		$$ = opr(YL::YareParser::token::CLEARVARS, 0);
	}
	| {;}
	;

stmt_list:
	stmt { 
		$$ = $1; 
	}			
	| stmt_list stmt { 
		$$ = opr(';', 2, $1, $2); 
	}
	;

expr:
	NUMERIC {
		$$ = con($1);
	}
	| ID /* Devolver el ID */ { 
		if(vars == NULL) {
			cout << "La variable '" << $1 << "' no ha sido declarada";
			exit(EXIT_FAILURE);
		} else {
			$$ = idS($1);	
		}
	}
	| CADENA {
		$$ = conStr($1, typeCadena);
	}
	| VARIABLE							{ 
		$$ = id($1); 
	}
	| ARRAY_ID '[' expr ']' {
		$$ = opr(YL::YareParser::token::ARRAY_SHIT, 2, idA($1), $3);
	}
	| ARRAY_ID '.' ARRAY_SIZE '(' ')' {
		$$ = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA($1));
	}
	| ARRAY_ID '.' ARRAY_SIZE {
		$$ = opr(YL::YareParser::token::ARRAY_SIZE, 1, idA($1));
	}
	| ARRAY_ID '.' ARRAY_MIN '(' ')' {
		$$ = opr(YL::YareParser::token::ARRAY_MIN, 1, idA($1));
	}
	| ARRAY_ID '.' ARRAY_MAX '(' ')' {
		$$ = opr(YL::YareParser::token::ARRAY_MAX, 1, idA($1));
	}
	| ARRAY_ID '.' ARRAY_TAIL '(' ')' {
		$$ = opr(YL::YareParser::token::ARRAY_TAIL, 1, idA($1));
	}
	| ARRAY_ID '.' ARRAY_HEAD '(' ')' {
		$$ = opr(YL::YareParser::token::ARRAY_HEAD, 1, idA($1));
	}
	| ARRAY_ID '.' ARRAY_AVERAGE '(' ')' {
		$$ = opr(YL::YareParser::token::ARRAY_AVERAGE, 1, idA($1));
	}
	| '-' expr %prec UMINUS				{ 
		$$ = opr(YL::YareParser::token::UMINUS, 1, $2); 
	}
	| '!' expr %prec NEGACION			{ 
		$$ = opr(YL::YareParser::token::NEGACION, 1, $2); 
	}
	| '~' expr %prec NEGACION			{ 
		$$ = opr(YL::YareParser::token::NEGACION, 1, $2); 
	}
	| EXPR_NOT expr %prec NEGACION		{ 
		$$ = opr(YL::YareParser::token::NEGACION, 1, $2); 
	}
	| expr '+' expr	{ 
		$$ = opr('+', 2, $1, $3); 
	}
	| expr '-' expr						{ 
		$$ = opr('-', 2, $1, $3); 
	}
	| expr EXPR_MENOS expr				{ 
		$$ = opr('-', 2, $1, $3); 
	}
	| expr EXPR_MAS expr				{ 
		$$ = opr('+', 2, $1, $3); 
	}
	| expr '*' expr						{ 
		$$ = opr('*', 2, $1, $3); 
	}
	| expr EXPR_MUL expr				{ 
		$$ = opr('*', 2, $1, $3); 
	}
	| expr '/' expr						{ 
		$$ = opr('/', 2, $1, $3); 
	}
	| expr EXPR_DIV expr				{ 
		$$ = opr('/', 2, $1, $3); 
	}
	| expr '<' expr						{ 
		$$ = opr(YL::YareParser::token::LT, 2, $1, $3); 
	}
	| expr EXPR_MENOR expr				{ 
		$$ = opr(YL::YareParser::token::LT, 2, $1, $3); 
	}
	| expr _LT_ expr					{ 
		$$ = opr(YL::YareParser::token::LT, 2, $1, $3); 
	}
	| expr '>' expr						{ 
		$$ = opr(YL::YareParser::token::GT, 2, $1, $3); 
	}
	| expr EXPR_MAYOR expr				{ 
		$$ = opr(YL::YareParser::token::GT, 2, $1, $3); 
	}
	| expr _GT_ expr					{ 
		$$ = opr(YL::YareParser::token::GT, 2, $1, $3); 
	}
	| expr '^' expr						{ 
		$$ = opr('^', 2, $1, $3); 
	}
	| expr EXPR_ELEVADO expr			{ 
		$$ = opr('^', 2, $1, $3); 
	}
	| expr '%' expr						{ 
		$$ = opr('%', 2, $1, $3); 
	}
	| expr MOD_WORD expr {
		$$ = opr('%', 2, $1, $3); 
	}
	| expr GE expr						{ 
		$$ = opr(YL::YareParser::token::GE, 2, $1, $3); 
	}
	| expr EXPR_MAYORIGUAL expr			{ 
		$$ = opr(YL::YareParser::token::GE, 2, $1, $3); 
	}
	| expr LE expr						{ 
		$$ = opr(YL::YareParser::token::LE, 2, $1, $3); 
	}
	| expr EXPR_MENORIGUAL expr			{ 
		$$ = opr(YL::YareParser::token::LE, 2, $1, $3); 
	}
	| expr NE expr						{ 
		$$ = opr(YL::YareParser::token::NE, 2, $1, $3); 
	}
	| expr EQ expr						{ 
		$$ = opr(YL::YareParser::token::EQ, 2, $1, $3); 
	}
	| expr EXPR_IGUAL expr						{ 
		$$ = opr(YL::YareParser::token::EQ, 2, $1, $3); 
	}
	| expr AND expr						{ 
		$$ = opr(YL::YareParser::token::AND, 2, $1, $3); 
	}
	| expr OR expr						{ 
		$$ = opr(YL::YareParser::token::OR, 2, $1, $3); 
	}
	| expr '&' expr						{ 
		$$ = opr(YL::YareParser::token::ANDBITS, 2, $1, $3); 
	}
	| expr '|' expr						{ 
		$$ = opr(YL::YareParser::token::ORBITS, 2, $1, $3); 
	}
	| '(' expr ')' 						{
		$$ = $2;
	}
	| expr OPVAR_OP expr 					{ 
		// Comparaciones de operadores
			if(strcmp(opVar, "+") == 0) {
				$$ = opr('+', 2, $1, $3);
			} else if(strcmp(opVar, "-") == 0) {
				$$ = opr('-', 2, $1, $3);
			} else if(strcmp(opVar, "*") == 0) {
				$$ = opr('*', 2, $1, $3);
			} else if(strcmp(opVar, "/") == 0) {
				$$ = opr('/', 2, $1, $3);
			} else if(strcmp(opVar, "^") == 0) {
				$$ = opr('^', 2, $1, $3);
			} 
	}	
	| READ '('')' {
		$$ = opr(YL::YareParser::token::READ, 0);
	}
	| READP '(' CADENA ')' {
		$$ = opr(YL::YareParser::token::READP, 1, conStr($3, typeCadena));
	}
	| RAND '('')' 		{
		$$ = opr(YL::YareParser::token::RAND, 0);
	}
	| POP {
		$$ = opr(YL::YareParser::token::POP, 0);
	}
	| STACK_SIZE {
		$$ = opr(YL::YareParser::token::STACK_SIZE, 0);
	}
	| ABS '(' expr ')' {
		$$ = opr(YL::YareParser::token::ABS, 1, $3);	
	}
	| SQRT '(' expr ')' {
		$$ = opr(YL::YareParser::token::SQRT, 1, $3);	
	}
	| ACOS '(' expr ')' {
		$$ = opr(YL::YareParser::token::ACOS, 1, $3);	
	}
	| ASIN '(' expr ')' {
		$$ = opr(YL::YareParser::token::ASIN, 1, $3);	
	}
	| ATAN '(' expr ')' {
		$$ = opr(YL::YareParser::token::ATAN, 1, $3);	
	}
	| CEIL '(' expr ')' {
		$$ = opr(YL::YareParser::token::CEIL, 1, $3);	
	}
	| COS '(' expr ')' {
		$$ = opr(YL::YareParser::token::COS, 1, $3);	
	}
	| COSH '(' expr ')' {
		$$ = opr(YL::YareParser::token::COSH, 1, $3);	
	}
	| EXP '(' expr ')' {
		$$ = opr(YL::YareParser::token::EXP, 1, $3);	
	}
	| FLOOR '(' expr ')' {
		$$ = opr(YL::YareParser::token::FLOOR, 1, $3);	
	}
	| LN '(' expr ')' {
		$$ = opr(YL::YareParser::token::LN, 1, $3);	
	}
	| SIN '(' expr ')' {
		$$ = opr(YL::YareParser::token::SIN, 1, $3);	
	}
	| SINH '(' expr ')' {
		$$ = opr(YL::YareParser::token::SINH, 1, $3);	
	}
	| TAN '(' expr ')' {
		$$ = opr(YL::YareParser::token::TAN, 1, $3);	
	}
	| TANH '(' expr ')' {
		$$ = opr(YL::YareParser::token::TANH, 1, $3);	
	}
	| SUMATORIA '(' expr ',' expr ')' {
		$$ = opr(YL::YareParser::token::SUMATORIA, 2, $3, $5);	
	}
	| FACTORIAL '(' expr ')' {
		$$ = opr(YL::YareParser::token::FACTORIAL, 1, $3);	
	}
	| DEC '(' ID ')' {
		$$ = opr(YL::YareParser::token::DEC, 1, idS($3));
	}
	| DEC '(' VARIABLE ')' {
		$$ = opr(YL::YareParser::token::DEC, 1, id($3));
	}
	| INC '(' ID ')' {
		$$ = opr(YL::YareParser::token::INC, 1, idS($3));
	}
	| INC '(' VARIABLE ')' {
		$$ = opr(YL::YareParser::token::INC, 1, id($3));
	}
	| expr XOROP expr {
		$$ = opr(YL::YareParser::token::XOROP, 2, $1, $3);
	}
	| expr RANGE_RANDOM expr {
		$$ = opr(YL::YareParser::token::RANGE_RANDOM, 2, $1, $3);
	}
	| VARIABLE '@''-' {
		$$ = opr(YL::YareParser::token::DEC_CPP, 1, id($1)); 	
	}
	| VARIABLE '@''+' {
		$$ = opr(YL::YareParser::token::INC_CPP, 1, id($1)); 	
	}
	| CALL FUNCNAME {
		$$ = opr(YL::YareParser::token::CALL, 1, idS($2));
	}
	;
%%

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

		case typeArray:
			if(arrays != NULL) {

				if(arrays->isDefined(p->id.identificador) == false) {
					cerr << "El array '" << p->id.identificador << "' no está declarado\n";
					return 0.0L;	
				} else {
					// cout << "mmm" << p->id.identificador << "\n";
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
						cout << p->opr.op[0]->con.cadena;
					}
					return 0.0L;	
				}

				case YL::YareParser::token::PUTSN: {
					if((spLoop < 0) || pilaLoop[spLoop]) {
						cout << p->opr.op[0]->con.cadena << endl;
					}
					return 0.0L;	
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

				case YL::YareParser::token::SYSTEM:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						int ____x = system(p->opr.op[0]->con.cadena);
					}
					return 0.0f;

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
								arrays->add(*(new Array(p->opr.op[0]->id.identificador, 0.0L)));
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
