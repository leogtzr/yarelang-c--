%require "2.4.1"
%skeleton "lalr1.cc"

%defines
%define namespace "YL"
%define parser_class_name "BisonParser"
%parse-param { YL::FlexScanner &scanner }
%lex-param   { YL::FlexScanner &scanner }

%{
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

%}

%code requires {
	// Forward-declare the Scanner class; the Parser needs to be assigned a 
	// Scanner, but the Scanner can't be declared without the Parser
	namespace YL {
		class FlexScanner;
	}
}

%code {
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

/********************** Data types and var's ***********************/
%token NUMERIC
%token CADENA
%token STRING
%token VARIABLE
%token ID		// :id:

/********************** Sentences *********************************/
// Control structures and more:
%token WHILE	// @todo while|mientras
%token BREAK	// "break";
%token IF		// "si" | "if"
///////////////////////////// Simple sentences: //////////////////
%token PRINTN 		// @todo printn(expr), prints out the expression with new line
%token PRINT		// Without new line
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

%type <valnum> NUMERIC 
%type <cadena> CADENA
%type <str> STRING
%type <nPtr> expr
%type <nPtr> cuerpo
%type <nPtr> stmt
%type <nPtr> stmt_list
%type <sIndex> VARIABLE
%type <identificador> ID
%type <nameFunction> FUNCNAME

%nonassoc IFX
%nonassoc ELSE

%left OR
%left AND
%left GE LE EQ NE GT LT ORBITS ANDBITS SHIFTLEFT SHIFTRIGHT
%left '+' '-'
%left '*' '/'
%left '^'
%left EXPR_ELEVADO			// expr "elevado" expr <-> expr^expr 
%nonassoc UMINUS NEGACION 

%%

program:
	funciones cuerpo '.' {
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
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($4), $2);
	}
	| MOV_ASM VARIABLE ',' expr ';' {
		$$ = opr('=', 2, id($2), $4);
	}
	| MOV_ASM ID ',' expr ';' {
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($2), $4);
	}
	| VARIABLE '<''-' expr {
		$$ = opr('=', 2, id($1), $4);
	}
	| ID '<''-' expr {
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($1), $4);
	}
	| VARIABLE PASCAL_ASSIGN expr {
		$$ = opr('=', 2, id($1), $3);
	}
	| ID PASCAL_ASSIGN expr {
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($1), $3);
	}
	| LETSET_ASSIGN VARIABLE '=' expr ';' {
		$$ = opr('=', 2, id($2), $4); 
	}
	| LETSET_ASSIGN VARIABLE TO expr ';' {
		$$ = opr('=', 2, id($2), $4); 
	}
	| ID '=' expr ';'					{ 
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($1), $3); 
	}
	| ID TO expr ';'					{ 	// :x: to 1 + 2;
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($1), $3); 
	}
	| LETSET_ASSIGN ID '=' expr ';'					{ 
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($2), $4); 
	}
	| LETSET_ASSIGN ID TO expr ';'					{ 
		$$ = opr(YL::BisonParser::token::ID_ASIGNACION, 2, idS($2), $4); 
	}
	| VARIABLE '=' '?' ';' {
		$$ = opr(YL::BisonParser::token::INIT_RANDOM, 1, id($1));
	}
	| ID '=' '?' ';' {
		$$ = opr(YL::BisonParser::token::INIT_RANDOM, 1, idS($1));
	}
	| VARIABLE SWAP_OP VARIABLE ';' {
		$$ = opr(YL::BisonParser::token::SWAP_OP, 2, id($1), id($3));
	}
	| ID SWAP_OP VARIABLE ';' {
		$$ = opr(YL::BisonParser::token::SWAP_OP, 2, idS($1), id($3));
	}
	| VARIABLE SWAP_OP ID ';' {
		$$ = opr(YL::BisonParser::token::SWAP_OP, 2, id($1), idS($3));
	}
	| ID SWAP_OP ID ';' {
		$$ = opr(YL::BisonParser::token::SWAP_OP, 2, idS($1), idS($3));
	}
	| expr ';' 	{ 
		$$ = $1; 
	}
	| PRINTN '(' expr ')'';' {
		$$ = opr(YL::BisonParser::token::PRINTN, 1, $3); 
	}
	| PRINT '(' expr ')'';' {
		$$ = opr(YL::BisonParser::token::PRINT, 1, $3); 
	}
	| '{' stmt_list	'}'		{ 
		$$ = $2; 
	}
	| WHILE	'(' expr ')' stmt	{ 
		$$ = opr(YL::BisonParser::token::WHILE, 2, $3, $5); 
	}
	| BREAK ';' 		{
		$$ = opr(YL::BisonParser::token::BREAK, 0);
	}
	| IF '(' expr ')'	stmt %prec	IFX		{ 
		$$ = opr(YL::BisonParser::token::IF, 2, $3, $5); 
	}
	| IF '(' expr ')' stmt ELSE stmt	{ 
		$$ = opr(YL::BisonParser::token::IF, 3, $3, $5, $7); 
	}
	| VARIABLE OP_ASIGN_ABR_MAS expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MAS expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, idS($1), $3);
	}
	| ADD_ASM VARIABLE ',' expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, id($2), $4);
	}
	| ADD_ASM ID ',' expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MAS, 2, idS($2), $4);
	}
	| SUB_ASM VARIABLE ',' expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, id($2), $4);
	}
	| SUB_ASM ID ',' expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, idS($2), $4);
	}
	| MUL_ASM VARIABLE ',' expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, id($2), $4);
	}
	| MUL_ASM ID ',' expr ';' {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, idS($2), $4);
	}
	| VARIABLE OP_ASIGN_ABR_MENOS expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MENOS expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MENOS, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_MOD expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MOD, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MOD expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MOD, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_MUL expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_MUL expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_MUL, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_DIV expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_DIV, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_DIV expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_DIV, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_SHIFTRIGHT expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_SHIFTRIGHT expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_SHIFTRIGHT, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_AND expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_AND, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_AND expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_AND, 2, idS($1), $3);
	}
	| VARIABLE OP_ASIGN_ABR_POW expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_POW, 2, id($1), $3);
	}
	| ID OP_ASIGN_ABR_POW expr {
		$$ = opr(YL::BisonParser::token::OP_ASIGN_ABR_POW, 2, idS($1), $3);
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
	| VARIABLE							{ 
		$$ = id($1); 
	}
	| RAND '('')' 		{
		$$ = opr(YL::BisonParser::token::RAND, 0);
	}
	| DEC '(' ID ')' {
		$$ = opr(YL::BisonParser::token::DEC, 1, idS($3));
	}
	| DEC '(' VARIABLE ')' {
		$$ = opr(YL::BisonParser::token::DEC, 1, id($3));
	}
	| INC '(' ID ')' {
		$$ = opr(YL::BisonParser::token::INC, 1, idS($3));
	}
	| INC '(' VARIABLE ')' {
		$$ = opr(YL::BisonParser::token::INC, 1, id($3));
	}
	| expr XOROP expr {
		$$ = opr(YL::BisonParser::token::XOROP, 2, $1, $3);
	}
	| expr RANGE_RANDOM expr {
		$$ = opr(YL::BisonParser::token::RANGE_RANDOM, 2, $1, $3);
	}
	| expr '+' expr	{ 
		$$ = opr('+', 2, $1, $3); 
	}
	| '-' expr %prec UMINUS				{ 
		$$ = opr(YL::BisonParser::token::UMINUS, 1, $2); 
	}
	| '!' expr %prec NEGACION			{ 
		$$ = opr(YL::BisonParser::token::NEGACION, 1, $2); 
	}
	| '~' expr %prec NEGACION			{ 
		$$ = opr(YL::BisonParser::token::NEGACION, 1, $2); 
	}
	| EXPR_NOT expr %prec NEGACION		{ 
		$$ = opr(YL::BisonParser::token::NEGACION, 1, $2); 
	}
	| expr EXPR_MAS expr				{ 
		$$ = opr('+', 2, $1, $3); 
	}
	| expr '-' expr						{ 
		$$ = opr('-', 2, $1, $3); 
	}
	| expr EXPR_MENOS expr				{ 
		$$ = opr('-', 2, $1, $3); 
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
		$$ = opr(YL::BisonParser::token::LT, 2, $1, $3); 
	}
	| expr EXPR_MENOR expr				{ 
		$$ = opr(YL::BisonParser::token::LT, 2, $1, $3); 
	}
	| expr _LT_ expr					{ 
		$$ = opr(YL::BisonParser::token::LT, 2, $1, $3); 
	}
	| expr '>' expr						{ 
		$$ = opr(YL::BisonParser::token::GT, 2, $1, $3); 
	}
	| expr EXPR_MAYOR expr				{ 
		$$ = opr(YL::BisonParser::token::GT, 2, $1, $3); 
	}
	| expr _GT_ expr					{ 
		$$ = opr(YL::BisonParser::token::GT, 2, $1, $3); 
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
		$$ = opr(YL::BisonParser::token::GE, 2, $1, $3); 
	}
	| expr EXPR_MAYORIGUAL expr			{ 
		$$ = opr(YL::BisonParser::token::GE, 2, $1, $3); 
	}
	| expr LE expr						{ 
		$$ = opr(YL::BisonParser::token::LE, 2, $1, $3); 
	}
	| expr EXPR_MENORIGUAL expr			{ 
		$$ = opr(YL::BisonParser::token::LE, 2, $1, $3); 
	}
	| expr NE expr						{ 
		$$ = opr(YL::BisonParser::token::NE, 2, $1, $3); 
	}
	| expr EQ expr						{ 
		$$ = opr(YL::BisonParser::token::EQ, 2, $1, $3); 
	}
	| expr AND expr						{ 
		$$ = opr(YL::BisonParser::token::AND, 2, $1, $3); 
	}
	| expr OR expr						{ 
		$$ = opr(YL::BisonParser::token::OR, 2, $1, $3); 
	}
	| expr '&' expr						{ 
		$$ = opr(YL::BisonParser::token::ANDBITS, 2, $1, $3); 
	}
	| expr '|' expr						{ 
		$$ = opr(YL::BisonParser::token::ORBITS, 2, $1, $3); 
	}
	| '(' expr ')' 						{
		$$ = $2;
	}
	| CALL FUNCNAME {
		$$ = opr(YL::BisonParser::token::CALL, 1, idS($2));
	}
	;
%%

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
	
