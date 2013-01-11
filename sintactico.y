/* Leo Gutiérrez Ramírez, leorocko13@hotmail.com */

/* PENDIENTES:
	Códigos de errores (Quizás ... ).
	Otras bases.
	Ver que funcione las sentencias de resetear y eliminar variables 
	Variables de entorno? (Viabilidad)
	Trabajo con archivo.
	Opcionalidad de paréntesis en sentencias.
	Función cmp.
*/

/* Que los paréntesis en los push y pops no sean forzosos. 
	Realizar una función cmp var|id,var|id,varResult(-1|0|1)	
*/
/* Pensar si es factible la sentencia continue */
/* Cambiar las tablas de símbolos a double
	Tener cuidado con los operadores a nivel de bits */
/* Más comentarios */
/* PRINTASCII */

%{
	#include	<stdio.h>
	#include	<stdlib.h>
	#include	<stdarg.h>
	#include	"estructuras.h"
	#include 	<string.h>
	#include 	"data_types.h"
	#include 	"write_fun_strs.h"
	#include 	"arreglos.h"
	
	/* prototypes */
	nodeType *opr(int oper, unsigned short nops, ...);
	nodeType *id(char i);
	nodeType *idS(char *s);
	nodeType *idWithType(char *s, short type);
	nodeType *con(double value);
	nodeType *conStr(char value[], short type);
	nodeType *idArray(char value[]);
	void freeNode(nodeType *p);
	void yyerror(char *s); 
	/* TODO Cambiar por una lista de identificadores */
	double sym[26]; /* symbol table for virtual vars */
	char opVar[4];
	struct palabras *identificadores = NULL;
	struct funciones *idFunciones = NULL;
	struct cadenas *writeStrings = NULL;
	struct _arrays *arreglos = NULL;
	double pila[100];
	unsigned int lineno;
	size_t argsInFunction = 0;
	double val_temp;
	/* Gigantes: */
	struct gigante *gigantes = NULL;
%} 

%union { 
	double iValue; 		/* integer value */
	char sIndex;		/* symbol table index */ 
	char cadena[1000];
	char cadena_gigante[1000];

	/* Id: */
	char identificador[100];
	/* El string que guarda el array */
	char idArray[100];
	char idgigante[100];
	char nameFunction[100];
	nodeType *nPtr; 	/* node pointer */
	short type_int;
}; 

%token <iValue> INTEGER
%token <sIndex> VARIABLE
%token <nameFunction> FUNCNAME;
%token <cadena> CADENA 
%token <identificador> ID
%token <idgigante> ID_GIGANTE
%token <idArray> ID_ARRAY
%token <cadena_gigante> GIGANTE		/* 12863678128368717623.877812387967912936716723123 */
/********** TIPOS DE DATOS ************** */
%token <type_int> INT_TYPE 
%token <type_int> DECIMAL_TYPE 
%token <type_int> BOOL_TYPE
/********** TIPOS DE DATOS ************** */

%token WHILE 
%token IF 
%token PRINT 
%token RAND 
%token INITRAND 
%token INCR 
%token DECR 
%token DO 
%token READ 
%token ASIGNACION_PASCAL 
%token LETSET 
%token TO 
%token MOVE 
%token MOVASM 
%token ADDASM
%token SUBASM 
%token SWAP 
%token SHIFTLEFT 
%token SHIFTRIGHT 
%token PUTS 
%token STRLEN 
%token _SWAP_ID_VAR_ 
%token _SWAP_VAR_ID_ 
%token IFTHEN 
%token IFEND
%token PRINTN	/* Agrega un caracter de nueva línea al final */
%token PRASCII
%token DECLARE
%token DECLARE_AND_ASSIGN
%token FUNCTION
%token PAR

/* Operadores de asignación abreviados */
%token ASIGN_ADD 
%token ASIGN_SUB 
%token ASIGN_MUL 
%token ASIGN_DIV 
%token ASIGN_MOD 
%token ASIGN_SHIFTLEFT 
%token ASIGN_SHIFTRIGHT 
%token ASIGN_AND 
%token ASIGN_OR 
%token ASIGN_POW 
%token XOROP

/* tokens para asignaciones abreviadas para los identificadores */
%token _ASIGN_ADD_ 
%token _ASIGN_SUB_ 
%token _ASIGN_MUL_ 
%token _ASIGN_DIV_ 
%token _ASIGN_MOD_ 
%token _ASIGN_SHIFTLEFT_ 
%token _ASIGN_SHIFTRIGHT_ 
%token _ASIGN_AND_ 
%token _ASIGN_OR_
%token _ASIGN_PASCAL_ _LETSET_ _ASIGN_POW_

/* Opvar tokens: */
%token OPVAR 
%token OPVAR_ADD 
%token OPVAR_SUB 
%token OPVAR_MUL 
%token OPVAR_DIV 
%token OPVAR_POW 

/* Smileys */
%token FACE_HAPPY 
%token FACE_SAD 
%token FACE_NO 
%token _FACE_HAPPY_ 
%token _FACE_SAD_ 
%token _FACE_NO_

/* Elipsis: */
%token ELIPSIS			/*  ....... */

/* Pila virtual */
%token PUSH			/* push(1.22324) | push(a) | push(:id:) | push(expr) */
%token VER_PILA 	/* verpila(); */
%token POP 			/* pop() | pop(a) | pop(ID) */
%token POP_EMPTY	/* pop | pop() */
%token POP_ID		/* pop(:z:) */
%token POP_VAR		/* pop(x) */

/* Tokens para trabajar con tipos de datos */
%token INITIALIZE_IDENTIFIER

/* Tokens relacionados con la gramática */ 
%token FUNCION PROC 

/* Asignaciones para identificadores */
%token _ASIGNACION_	_READ_ _INITRAND_ CONCATENATE_DIGITS CONCATENATE_DIGITS_ID CONCATENATE_DIGITS_VAR

/* Move y mnemonicos en ensamblador para identificadores: */
%token _MOVE_ 
%token _MOVASM_ 
%token _ADDASM_ 
%token _SUBASM_ 
%token _SWAP_

/* Incrementos y decrementos con identificadores */
%token _INCR_ _DECR_

/* Operadores tipo shell */
%token _GT_ _LT_ 
%token BREAK 
%token CALL
%token EXIT	/* Sentencia para salir del programa */
%token INCR_FUNC_ID		/* Incrementar el valor de un identificador */
%token INCR_FUNC_VAR	/* Incrementar el valor de una variable */
%token DECR_FUNC_ID		/* Decrementar el valor de un identificador */
%token DECR_FUNC_VAR	/* Decrementar el valor de una variable */
%token INCREMENTAR		/* Token incr(var|id) para lex */
%token DECREMENTAR		/* Token decr(var|id) para lex */
%token UNLESS			/* Unless de perl */
/* FOR, para variables e identificadores */
%token FOR 
%token FOREACH		/* Sentencia foreach for(expr... expr, v) {...} */
%token FOREACH_ID	/* Sentencia foreach for(expr... expr, v) {...} */
%token FOR_MENOS FOR_MENOS_ID
%token FOR_MAS FOR_MAS_ID 
%token FOR_MUL FOR_MUL_ID 
%token FOR_DIV FOR_DIV_ID
%token FOR_POW FOR_POW_ID
%token FOR_MOD FOR_MOD_ID 
%token FOR_SHIFTLEFTF FOR_SHIFTLEFTF_ID
%token FOR_SHIFTRIGHT FOR_SHIFTRIGHT_ID
%token FOR_OR FOR_OR_ID
%token FOR_AND FOR_AND_ID
/* Math functions */
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

%token VOID
%token SYSTEM	/* system("command") */

/* Array shits */
%token ARRAY
%token DECLARE_ARRAY	/* Utilizado para crear el array en el archivo interprete.c */
%token ARRAY_POS
%token ARRAY_SIMPLE_ASIGN	/* array[expr] = expr; */

/* Expresiones aritméticas con palabras: */
%token EXPR_MAS
%token EXPR_MENOS
%token EXPR_DIV
%token EXPR_MUL
%token EXPR_NOT
%token EXPR_ELEVADO
%token EXPR_MENOR
%token EXPR_MAYOR
%token EXPR_MENORQUE
%token EXPR_MAYORQUE

/* Trabajo con gigantes: */
%token DECLARE_G	/* declare_g(g.example.g, 1.32462387234867); */

%nonassoc IFX
%nonassoc ELSE

%left OR
%left AND
%left GE LE EQ NE '>' '<' ANDBITS ORBITS
%left '+' '-'
%left '*' '/'
%left '^'
%left EXPR_ELEVADO
%nonassoc UMINUS NEGACION 

%type <nPtr> stmt 
%type <nPtr> expr 
%type <nPtr> stmt_list 
%type <type_int> type_specifier
/* Estos tokens nos sirven para la función write, ir acumulando */

%%

program:
	funciones fun_declaration cuerpo '.'	{ 
			liberar(&idFunciones); 
			liberar(&identificadores); 
			liberar_array(&arreglos);
			liberar_gigantes(&gigantes);
			exit(EXIT_SUCCESS); 
	}
	;

funciones:
	funciones PROC FUNCNAME '{' stmt_list '}' {
			push_l_funcion(&idFunciones, $3, $5);
	}
	| {;}	/* NULL, no se hace nada */
	;

type_specifier: 
	INT_TYPE { 
		$$ = INT;
		argsInFunction++; 
	}
	| DECIMAL_TYPE {
		$$ = DECIMAL;
		argsInFunction++;
	}
	| BOOL_TYPE {
		$$ = BOOL;
		argsInFunction++;
	}
	;

fun_declaration: 
	FUNCTION FUNCNAME '(' params ')' '{' stmt_list '}' {
		printf("function declaration: %s-%d\n", $2, argsInFunction);
	}
	| {;}
	;

params: 
	param_list 
	| VOID 
	| {;
		/* Con esto hacemos que la función pueda interpretarse así:
		function $algo$() {stmt_list}		*/
	}
	;

param_list: 
	param_list ',' param
    | param 
	;

param: 
	type_specifier ID { 
			printf("El tipo fue... %d, para el ID = '%s'\n", $1, $2);
	}
	| type_specifier ID '[' ']'
	;

cuerpo:
	cuerpo stmt		{ 
		run($2);			/* Ejecutar los nodos */ 
		freeNode($2); 	/* Liberar los nodos */
	}
	| /* NULL */
	;

stmt:
	';'									{ $$ = opr(';', 2, NULL, NULL); }
	| expr ';' 							{ $$ = $1; }
	| ARRAY ID '[' expr ']'';'			{ printf("Array detected...\n"); $$ = NULL;}
	| PRINT	'(' expr ')'';' 			{ $$ = opr(PRINT, 1, $3); }
	| PRINTN '(' expr ')'';' 			{ $$ = opr(PRINTN, 1, $3); }
	| RAND	expr ';'					{ $$ = opr(RAND, 1, $2); }
	| READ '(' VARIABLE ')'';'			{ $$ = opr(READ, 1, id($3)); }
	| READ '(' ID ')'';'				{ $$ = opr(_READ_, 1, idS($3)); }
	| PUTS '(' CADENA ')'';'			{ $$ = opr(PUTS, 1, conStr($3, typeCadena)); }
	| BREAK ';'							{ $$ = opr(BREAK, 0); }
	| EXIT '(' expr ')' ';'				{ $$ = opr(EXIT, 1, $3); }
	| PRASCII '(' expr ')'';'			{ $$ = opr(PRASCII, 1, $3); }
	| type_specifier ID '=' expr ';'	{ 
		 			$$ = opr(INITIALIZE_IDENTIFIER, 2, idWithType($2, $1), $4); 
										}
	| VARIABLE '=' expr ';' 			{ 
							/* Buscar si ya está definida la variable, sino hay que
								crearla con el valor de la expresión.
							Sino hay que sobreescribir con el valor de dicha expresión */
							$$ = opr('=', 2, id($1), $3); 
										}
	| ID '=' expr ';'					{ $$ = opr(_ASIGNACION_, 2, idS($1), $3); }
	| ID_ARRAY '[' expr ']' '=' expr ';'{ 
			$$ = opr(ARRAY_SIMPLE_ASIGN, 3, idArray($1), $3, $6); 
	}
	| VARIABLE '=' '?'';'				{ $$ = opr(INITRAND, 1, id($1)); }
	| ID '=' '?'';'						{ $$ = opr(_INITRAND_, 1, idS($1)); }
	| VARIABLE '=' FACE_HAPPY ';'		{ $$ = opr(FACE_HAPPY, 1, id($1)); }
	| VARIABLE '=' FACE_SAD ';'			{ $$ = opr(FACE_SAD, 1, id($1)); }
	| VARIABLE '=' FACE_NO ';'			{ $$ = opr(FACE_NO, 1, id($1)); }
	/* Asignación de smileys ahora para identificadores: */
	| ID '=' FACE_HAPPY ';'			{ $$ = opr(_FACE_HAPPY_, 1, idS($1)); }
	| ID '=' FACE_SAD ';'			{ $$ = opr(_FACE_SAD_, 1, idS($1)); }
	| ID '=' FACE_NO ';'			{ $$ = opr(_FACE_NO_, 1, idS($1)); }
	| VARIABLE ASIGN_ADD expr ';'		{ $$ = opr(ASIGN_ADD, 2, id($1), $3); }
	| VARIABLE ASIGN_SUB expr ';'		{ $$ = opr(ASIGN_SUB, 2, id($1), $3); }
	| VARIABLE ASIGN_MUL expr ';'       { $$ = opr(ASIGN_MUL, 2, id($1), $3); } 
	| VARIABLE ASIGN_DIV expr ';'		{ $$ = opr(ASIGN_DIV, 2, id($1), $3); }
	| VARIABLE ASIGN_MOD expr ';'		{ $$ = opr(ASIGN_MOD, 2, id($1), $3); }
	| VARIABLE ASIGN_POW expr ';'		{ $$ = opr(ASIGN_POW, 2, id($1), $3); }
	| VARIABLE ASIGN_SHIFTLEFT expr ';'	{ $$ = opr(ASIGN_SHIFTLEFT, 2, id($1), $3); }
	| VARIABLE ASIGN_SHIFTRIGHT expr ';'{ $$ = opr(ASIGN_SHIFTRIGHT, 2, id($1), $3); }
	| VARIABLE ASIGN_AND expr ';'		{ $$ = opr(ASIGN_AND, 2, id($1), $3); }
	| VARIABLE ASIGN_OR expr ';'		{ $$ = opr(ASIGN_OR, 2, id($1), $3); }
	| VARIABLE ASIGNACION_PASCAL expr ';' { $$ = opr(ASIGNACION_PASCAL, 2, id($1), $3); }
/* Asignaciones abreviadas para identificadores */
	| ID ASIGN_ADD expr ';'				{ $$ = opr(_ASIGN_ADD_, 2, idS($1), $3); }
	| ID ASIGN_SUB expr ';'				{ $$ = opr(_ASIGN_SUB_, 2, idS($1), $3); }
	| ID ASIGN_MUL expr ';'				{ $$ = opr(_ASIGN_MUL_, 2, idS($1), $3); }
	| ID ASIGN_DIV expr ';'				{ $$ = opr(_ASIGN_DIV_, 2, idS($1), $3); }
	| ID ASIGN_MOD expr ';'				{ $$ = opr(_ASIGN_MOD_, 2, idS($1), $3); }
	| ID ASIGN_SHIFTLEFT expr ';'		{ $$ = opr(_ASIGN_SHIFTLEFT_, 2, idS($1), $3); }
	| ID ASIGN_SHIFTRIGHT expr ';'		{ $$ = opr(_ASIGN_SHIFTRIGHT_, 2, idS($1), $3); }
	| ID ASIGN_AND expr ';'				{ $$ = opr(_ASIGN_AND_, 2, idS($1), $3); }
	| ID ASIGN_OR expr ';'				{ $$ = opr(_ASIGN_OR_, 2, idS($1), $3); }
	| ID ASIGNACION_PASCAL expr ';'		{ $$ = opr(_ASIGN_PASCAL_, 2, idS($1), $3); }
	| ID ASIGN_POW expr ';'				{ $$ = opr(_ASIGN_POW_, 2, idS($1), $3); }
	| LETSET VARIABLE '=' expr ';'		{ $$ = opr(LETSET, 2, id($2), $4); }
	| LETSET VARIABLE TO expr ';'		{ $$ = opr(LETSET, 2, id($2), $4); }
/* LETSET para identificadores */
	| LETSET ID '=' expr ';'			{ $$ = opr(_LETSET_, 2, idS($2), $4); } 
	| LETSET ID TO expr ';'				{ $$ = opr(_LETSET_, 2, idS($2), $4); } 
	| MOVE expr TO VARIABLE ';'			{ $$ = opr(MOVE, 2, $2, id($4)); }
	/* MOVE para identificadores: */
	| MOVE expr TO ID ';'				{ $$ = opr(_MOVE_, 2, $2, idS($4)); }
	| MOVASM VARIABLE ',' expr ';'		{ $$ = opr(MOVASM, 2, id($2), $4); }
	| ADDASM VARIABLE ',' expr ';'		{ $$ = opr(ADDASM, 2, id($2), $4); }
	| SUBASM VARIABLE ',' expr ';'		{ $$ = opr(SUBASM, 2, id($2), $4); }
/*	Asignaciones en assembly */
	| MOVASM ID ',' expr ';'			{ $$ = opr(_MOVASM_, 2, idS($2), $4); }
	| ADDASM ID ',' expr ';'			{ $$ = opr(_ADDASM_, 2, idS($2), $4); }
	| SUBASM ID ',' expr ';'			{ $$ = opr(_SUBASM_, 2, idS($2), $4); }
	| VARIABLE SWAP VARIABLE ';'		{ $$ = opr(SWAP, 2, id($1), id($3)); }
	| ID SWAP ID ';'					{ $$ = opr(_SWAP_, 2, idS($1), idS($3)); }
/* SWAPS ID con VAR y VAR con ID */
	| ID SWAP VARIABLE ';'				{ $$ = opr(_SWAP_ID_VAR_, 2, idS($1), id($3)); }
	| VARIABLE SWAP ID ';'				{ $$ = opr(_SWAP_VAR_ID_, 2, id($1), idS($3)); }
	| OPVAR '=''+'';'					{ $$ = opr(OPVAR_ADD, 0); }
	| OPVAR '=''-'';'					{ $$ = opr(OPVAR_SUB, 0); }
	| OPVAR '=''*'';'					{ $$ = opr(OPVAR_MUL, 0); }
	| OPVAR '=''/'';'					{ $$ = opr(OPVAR_DIV, 0); }
	| OPVAR '=''^'';'					{ $$ = opr(OPVAR_POW, 0); }
	| OPVAR '=' EXPR_ELEVADO ';'		{ $$ = opr(OPVAR_POW, 0); }
	| VARIABLE '+''@'';'				{ $$ = opr(INCR, 1, id($1)); }
	| VARIABLE '-''@'';'				{ $$ = opr(DECR, 1, id($1)); }
/* Incrementos y decrementos */        
	| ID '+''@'';'						{ $$ = opr(_INCR_, 1, idS($1)); } 
	| ID '-''@'';'						{ $$ = opr(_DECR_, 1, idS($1)); } 
	| WHILE	'(' expr ')' stmt			{ $$ = opr(WHILE, 2, $3, $5); }
/* FOR Con variables */
	| FOR VARIABLE '=' expr ',' expr ',''-'expr stmt { $$ = opr(FOR_MENOS, 5, id($2), $4, $6, $9, $10); } 
	| FOR VARIABLE '=' expr ',' expr ',''+'expr '{' stmt_list '}' { $$ = opr(FOR_MAS, 5, id($2), $4, $6, $9, $11); } 
	| FOR VARIABLE '=' expr ',' expr ',''*'expr stmt { $$ = opr(FOR_MUL, 5, id($2), $4, $6, $9, $10); } 
	| FOR VARIABLE '=' expr ',' expr ',''/'expr stmt { $$ = opr(FOR_DIV, 5, id($2), $4, $6, $9, $10); } 
	| FOR VARIABLE '=' expr ',' expr ',''^'expr stmt { $$ = opr(FOR_POW, 5, id($2), $4, $6, $9, $10); } 
	| FOR VARIABLE '=' expr ',' expr ',' EXPR_ELEVADO expr stmt { $$ = opr(FOR_POW, 5, id($2), $4, $6, $9, $10); } 
	| FOR VARIABLE '=' expr ',' expr ',''%'expr stmt { $$ = opr(FOR_MOD, 5, id($2), $4, $6, $9, $10); } 
	| FOR VARIABLE '=' expr ',' expr ','SHIFTLEFT expr stmt { $$ = opr(FOR_SHIFTLEFTF, 5, id($2), $4, $6, $9, $10); } 
	| FOR VARIABLE '=' expr ',' expr ','SHIFTRIGHT expr stmt { $$ = opr(FOR_SHIFTRIGHT, 5, id($2), $4, $6, $9, $10); }
	| FOREACH '(' expr ELIPSIS expr ',' VARIABLE ')' stmt { $$ = opr(FOREACH, 4, $3, $5, id($7), $9); }
/* FOR Con identificadores */
	| FOR ID '=' expr ',' expr ',''-'expr stmt { $$ = opr(FOR_MENOS_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ',''+'expr stmt { $$ = opr(FOR_MAS_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ',''*'expr stmt { $$ = opr(FOR_MUL_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ',''/'expr stmt { $$ = opr(FOR_DIV_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ',''^'expr stmt { $$ = opr(FOR_POW_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ',' EXPR_ELEVADO expr stmt { $$ = opr(FOR_POW_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ',''%'expr stmt { $$ = opr(FOR_MOD_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ','SHIFTLEFT expr stmt { $$ = opr(FOR_SHIFTLEFTF_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOR ID '=' expr ',' expr ','SHIFTRIGHT expr stmt { $$ = opr(FOR_SHIFTRIGHT_ID, 5, idS($2), $4, $6, $9, $10); } 
	| FOREACH '(' expr ELIPSIS expr ',' ID ')' stmt { $$ = opr(FOREACH_ID, 4, $3, $5, idS($7), $9); }
	| IF '(' expr ')'	stmt %prec	IFX	{ $$ = opr(IF, 2, $3, $5); }
	| UNLESS '(' expr ')'	stmt %prec	IFX	{ $$ = opr(UNLESS, 2, $3, $5); }
	| IF '(' expr ')' stmt ELSE stmt	{ $$ = opr(IF, 3, $3, $5, $7); }
	| '{' stmt_list	'}'					{ $$ = $2; }
	| '{''}'							{ $$ = NULL; }
	| IFTHEN stmt_list IFEND			{ $$ = $2; }
	| DO stmt WHILE '(' expr ')'';' { $$ = opr(DO, 2, $2, $5); }
	| DO IFTHEN stmt_list IFEND WHILE '(' expr ')'';' { $$ = opr(DO, 2, $3, $7); }
/* Operador de concatenación de digitos */
	| ID CONCATENATE_DIGITS expr ';'	{ $$ = opr(CONCATENATE_DIGITS_ID, 2, idS($1), $3); }
	| VARIABLE CONCATENATE_DIGITS expr ';'	{ $$ = opr(CONCATENATE_DIGITS_VAR, 2, id($1), $3); }
	| SYSTEM '(' CADENA ')'';'			{ $$ = opr(SYSTEM, 1, conStr($3, typeSystem)); }
	| PUSH '(' expr ')'';'				{ $$ = opr(PUSH, 1, $3); }
	| VER_PILA '('')'';'				{ $$ = opr(VER_PILA, 0); }
	| DECLARE '(' ID ')'';'				{ $$ = opr(DECLARE, 1, idS($3)); }
	| DECLARE '(' ID ',' expr ')'';'	{ $$ = opr(DECLARE_AND_ASSIGN, 2, idS($3), $5); }
	| ARRAY '(' ID_ARRAY ',' expr ')'';' {	
			/* Declaración de un array */
			$$ = opr(DECLARE_ARRAY, 2, idArray($3), $5); 
	}
	| DECLARE '(' ID ',' type_specifier ',' expr ')'';' {
		/*printf("Tipo para esta shit %d\n", $5);*/
		$$ = NULL;
	}
	/* Trabajo con gigantes */
	| DECLARE_G '(' ID_GIGANTE ',' GIGANTE ')'';' 	{ printf("[declare_g(%s, %s);]\n", $3, $5); 
		$$ = NULL;
	} 
	| POP '(' ID ')'';'					{ $$ = opr(POP_ID, 1, idS($3)); } 
	| POP '(' VARIABLE ')'';'			{ $$ = opr(POP_VAR, 1, id($3)); }
	;
	
stmt_list:
	stmt								{ $$ = $1; }			
	|	stmt_list stmt					{ $$ = opr(';', 2, $1, $2); }
	;

expr:
	INTEGER								{ $$ = con($1); }
	| ID								{ 
	
		/*ver_palabras(identificadores);	*/
		$$ = idS($1); 
		if(!buscar(identificadores, $1)) {
			fprintf(stdout, "Error, variable '%s' no declarada\n", $1);
		}		

	 }
	| CADENA							{ $$ = conStr($1, typeCadena); }
	| ID_ARRAY '[' expr ']'				{ $$ = opr(ARRAY_POS, 2, idArray($1), $3); }
	| PAR '(' expr ')'					{ $$ = opr(PAR, 1, $3); }
	| VARIABLE							{ $$ = id($1); }
	| '-' expr %prec UMINUS				{ $$ = opr(UMINUS, 1, $2); }
	| '!' expr %prec NEGACION			{ $$ = opr(NEGACION, 1, $2); }
	| '~' expr %prec NEGACION			{ $$ = opr(NEGACION, 1, $2); }
	| EXPR_NOT expr %prec NEGACION		{ $$ = opr(NEGACION, 1, $2); }
	| expr '+' expr						{ $$ = opr('+', 2, $1, $3); }
	| expr EXPR_MAS expr				{ $$ = opr('+', 2, $1, $3); }
	| expr '-' expr						{ $$ = opr('-', 2, $1, $3); }
	| expr EXPR_MENOS expr				{ $$ = opr('-', 2, $1, $3); }
	| expr '*' expr						{ $$ = opr('*', 2, $1, $3); }
	| expr EXPR_MUL expr				{ $$ = opr('*', 2, $1, $3); }
	| expr '/' expr						{ $$ = opr('/', 2, $1, $3); }
	| expr EXPR_DIV expr				{ $$ = opr('/', 2, $1, $3); }
	| expr '<' expr						{ $$ = opr('<', 2, $1, $3); }
	| expr EXPR_MENOR expr				{ $$ = opr('<', 2, $1, $3); }
	| expr _LT_ expr					{ $$ = opr('<', 2, $1, $3); }
	| expr '>' expr						{ $$ = opr('>', 2, $1, $3); }
	| expr EXPR_MAYOR expr				{ $$ = opr('>', 2, $1, $3); }
	| expr _GT_ expr					{ $$ = opr('>', 2, $1, $3); }
	| expr '^' expr						{ $$ = opr('^', 2, $1, $3); }
	| expr EXPR_ELEVADO expr			{ $$ = opr('^', 2, $1, $3); }
	| expr '%' expr						{ $$ = opr('%', 2, $1, $3); }
	| expr GE expr						{ $$ = opr(GE, 2, $1, $3); }
	| expr EXPR_MAYORQUE expr			{ $$ = opr(GE, 2, $1, $3); }
	| expr LE expr						{ $$ = opr(LE, 2, $1, $3); }
	| expr EXPR_MENORQUE expr			{ $$ = opr(LE, 2, $1, $3); }
	| expr NE expr						{ $$ = opr(NE, 2, $1, $3); }
	| expr EQ expr						{ $$ = opr(EQ, 2, $1, $3); }
	| expr AND expr						{ $$ = opr(AND, 2, $1, $3); }
	| expr OR expr						{ $$ = opr(OR, 2, $1, $3); }
	| expr '&' expr						{ $$ = opr(ANDBITS, 2, $1, $3); }
	| expr '|' expr						{ $$ = opr(ORBITS, 2, $1, $3); }
	| expr XOROP expr					{ $$ = opr(XOROP, 2, $1, $3); }
	| expr SHIFTLEFT expr				{ $$ = opr(SHIFTLEFT, 2, $1, $3); }
	| expr SHIFTRIGHT expr				{ $$ = opr(SHIFTRIGHT, 2, $1, $3); }	/* OPVARS */
	| STRLEN '(' CADENA ')'				{ $$ = opr(STRLEN, 1, conStr($3, typeCadena)); }
	| ABS '(' expr ')'					{ $$ = opr(ABS, 1, $3); }
	| FACTORIAL '(' expr ')'			{ $$ = opr(FACTORIAL, 1, $3); }
	| SUMATORIA '(' expr ',' expr ')'	{ $$ = opr(SUMATORIA, 2, $3, $5); }
	| SQRT '(' expr ')'					{ $$ = opr(SQRT, 1, $3); }
	| ACOS '(' expr ')'					{ $$ = opr(ACOS, 1, $3); }
	| ASIN '(' expr ')'					{ $$ = opr(ASIN, 1, $3); }
	| ATAN '(' expr ')'					{ $$ = opr(ATAN, 1, $3); }
	| CEIL '(' expr ')'					{ $$ = opr(CEIL, 1, $3); }
	| COS '(' expr ')'					{ $$ = opr(COS, 1, $3); }
	| COSH '(' expr ')'					{ $$ = opr(COSH, 1, $3); }
	| EXP '(' expr ')'					{ $$ = opr(EXP, 1, $3); }
	| LN '(' expr ')'					{ $$ = opr(LN, 1, $3); }
	| FLOOR '(' expr ')'				{ $$ = opr(FLOOR, 1, $3); }
	| SIN '(' expr ')'					{ $$ = opr(SIN, 1, $3); }
	| SINH '(' expr ')'					{ $$ = opr(SINH, 1, $3); }
	| TAN '(' expr ')'					{ $$ = opr(TAN, 1, $3); }
	| TANH '(' expr ')'					{ $$ = opr(TANH, 1, $3); }
	| CALL FUNCNAME 					{ $$ = opr(CALL, 0); }
	| INCREMENTAR '(' VARIABLE ')'		{ $$ = opr(INCR_FUNC_VAR, 1, id($3)); } 
	| INCREMENTAR '(' ID ')'			{ $$ = opr(INCR_FUNC_ID, 1, idS($3)); } 
	| DECREMENTAR '(' VARIABLE ')'		{ $$ = opr(DECR_FUNC_VAR, 1, id($3)); } 
	| DECREMENTAR '(' ID ')'			{ $$ = opr(DECR_FUNC_ID, 1, idS($3)); } 
	| expr OPVAR expr 					{ 
					/* Comparaciones de operadores */
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
	| '(' expr ')'						{ $$ = $2; }
	;
%%

nodeType *con(double value) {
	nodeType *p;
	/* allocate node */
	if((p = malloc(sizeof(conNodeType))) == NULL)
		yyerror("Memoria insuficiente para este programa.");
	/* copy information */
	p->type = typeCon;
	p->con.value = value;
	return p;
}

nodeType *conStr(char valueString[], short type) {
	nodeType *p;
	if((p = malloc(sizeof(conNodeType))) == NULL) {
		yyerror("Memoria insuficiente para este programa.");
	}
	/* Asignamos el tipo */
	p->type = type;
	strcpy(p->con.cadena, valueString);
	return p;
}

nodeType *idArray(char valueString[]) {
	nodeType *p;
	/* allocate node */
	if((p = malloc(sizeof(idNodeType))) == NULL) {
		yyerror("Memoria insuficiente para este programa.");
	}
	/* copy information */
	p->type = typeArray; 
	/* Copiar el id */
	strcpy(p->id.idArray, valueString);
	return p;
}

nodeType *id(char i) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(idNodeType))) == NULL)
		yyerror("Memoria insuficiente para este programa.");
	/* copy information */
	p->type = typeId;
	p->id.i = i;
	return p;
}

nodeType *idS(char *s) {

	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(idNodeType))) == NULL)
		yyerror("Memoria insuficiente para este programa.");
	/* copy information */
	p->type = typeVar;
	/* Copiar el id: */
	strcpy(p->id.identificador, s);
	return p;
}

nodeType *idWithType(char *s, short data_type) {
	nodeType *p;

	if((p = malloc(sizeof(nodeType))) == NULL)
		yyerror("Memoria insuficiente para este programa.");
	/* copy information */
	p->type = typeVar;	
	/* Copiar el id: */
	strcpy(p->id.identificador, s);
	/* Ponerle el tipo de dato */
	p->tipoDato = data_type; 
	return p;
}

nodeType *opr(int oper, unsigned short nops, ...) {
	va_list ap;
	nodeType *p;
	size_t size;
	int i;
	/* allocate node */
	size = sizeof(oprNodeType) + (nops - 1) * sizeof(nodeType*);
	if ((p = malloc(size)) == NULL)
		yyerror("Memoria insuficiente para este programa.");
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

char *getExtension(char s[]) {

    char *respaldo = malloc(strlen(s) + 1);
    char *elemento = strtok(s, ".");

    while(elemento != NULL) {
        strncpy(respaldo, elemento, strlen(elemento) + 1);
        elemento = strtok(NULL, ".");
    }

    return respaldo;
}

void yyerror(char *s) {
	fprintf(stdout, "%s, probable antes de la línea %d.\n", s, lineno + 1);
}

int main(int argc, char **argv) {

	char *_respaldo = NULL;
	if(argc > 1) {
		
		_respaldo = malloc(strlen(argv[1]) + 1);
		strncpy(_respaldo, argv[1], strlen(argv[1]) + 1);
		stdin = fopen(argv[1], "r");

		if(strlen(argv[1]) <= 3) {
			fprintf(stderr, "'%s' debe tener una extensión \"yar\"\n", argv[1]);
			exit(EXIT_FAILURE);
		} else if(strcmp(getExtension(argv[1]), "yar") != 0) {
			fprintf(stderr, "'%s' debe tener una extensión \"yar\"\n", argv[1]);
			exit(EXIT_FAILURE);
		}	

		if(stdin == NULL) {
			fprintf(stderr, "Error abriendo archivo [%s]\n", _respaldo);
			free(_respaldo);
			exit(EXIT_FAILURE);
		}
	} else {
		/* PENDIENTE Realizar una función about */
		printf("\nyare\tv1.0\n\n");
		return EXIT_SUCCESS;
	}

	srand(time(NULL));
	yyparse();
	free(_respaldo);
	return EXIT_SUCCESS;
}

