
%{
	#include "yare.tab.h"
	#include "YareScanner.h"
	#include "constantes.h"
	// XXX  #include "astnode.h"
	#include <cstring>
	#include <cctype>
	#include <cstdlib>
	#include <iostream>
	#include <cstdio>

	// Opvar:
	extern char opVar[4];
	// Número de línea:
	extern unsigned int lineno;
	// variable buffer temporal para manejo de strings.
	char buf[100];
	// Acumula los caracteres de escape
	char *str_scapes;			/* Puntero para ir acumulando caracteres de escape */
	using std::endl;
	using std::cout;
	using std::cerr;

%}
%x STRING
%x IN_COMMENT

%option yyclass="FlexScanner" noyywrap c++ 
%option yylineno 

%%

[0-9]+([.][0-9]+)? 	{
	lexema->valnum = strtold(yytext, NULL);
	return YL::BisonParser::token::NUMERIC;
}

[a-zA-Z] 				{
						/* TODO Revisar esto con calma */
	if(isupper(*yytext))
		lexema->sIndex = tolower(*yytext) - 'a';
	else
		lexema->sIndex = *yytext - 'a';
	return YL::BisonParser::token::VARIABLE;
}

:["'0-9 _#@a-zA-Z\t\+\-\.\^\|\(\)\\/]+: 	{
	strcpy(lexema->identificador, yytext);
	for(unsigned _i_ = 0; _i_ < strlen(lexema->identificador); _i_++)
		if(isalpha(lexema->identificador[_i_]) && isupper(lexema->identificador[_i_]))
			lexema->identificador[_i_] = tolower(lexema->identificador[_i_]);
	return YL::BisonParser::token::ID;
}

[$].+[$]	{
	strcpy(lexema->nameFunction, yytext);
	lexema->nameFunction[strlen(lexema->nameFunction)] = '\0';
	return YL::BisonParser::token::FUNCNAME;
}

0[xX][0-9a-fA-F]+	{
	lexema->valnum = strtold(yytext, NULL);
	return YL::BisonParser::token::NUMERIC;
}

[.][.][.]([.]+)?[?] {
	// 676 ...? 8729834, expr ...? expr
	return YL::BisonParser::token::RANGE_RANDOM;
}

[pP][rR][oO][cC] {
	return YL::BisonParser::token::PROC;
}

[cC][aA][lL][lL] {
	return YL::BisonParser::token::CALL;
}

[pP][rR][iI][nN][tT][nN]	{
	return YL::BisonParser::token::PRINTN;
}

[pP][rR][iI][nN][tT] {
	return YL::BisonParser::token::PRINT;
}

[iI][nN][cC] {
	return YL::BisonParser::token::INC;
}

[dD][eE][cC] {
	return YL::BisonParser::token::DEC;
}

[lLsS][eE][tT] {
	return YL::BisonParser::token::LETSET_ASSIGN;
}

[tT][oO] {
	return YL::BisonParser::token::TO;
}

[mM][oO][vV][eE] {
	return YL::BisonParser::token::MOVE;
}

[mM][oO][vV] {
	// mov x, 1 + 2;
	return YL::BisonParser::token::MOV_ASM;
}

[aA][dD][dD] {
	// dd x, 1+ 2 * 3;
	return YL::BisonParser::token::ADD_ASM;
}

[sS][uU][bB] {
	// add x, 1+ 2 * 3;
	return YL::BisonParser::token::SUB_ASM;
}

[mM][uU][lL] {
	// mul x, 2;
	return YL::BisonParser::token::MUL_ASM;
}

[wW][hH][iI][lL][eE] {
	return YL::BisonParser::token::WHILE;
}

[iI][fF] {
	return YL::BisonParser::token::IF;
}

[eE][lL][sS][eE] {
	return YL::BisonParser::token::ELSE;
}

[bB][rR][eE][aA][kK] {
	return YL::BisonParser::token::BREAK;
}

[rR][aA][nN][dD] {
	return YL::BisonParser::token::RAND;
}

[xX][oO][rR] {
	return YL::BisonParser::token::XOROP;
}

[Mm][oO][dD] {
	return YL::BisonParser::token::MOD_WORD;
}

[nN][oO][tT]? /* Expressions with WORDS */	{
	return YL::BisonParser::token::EXPR_NOT;
}

[cC][oO][nN][sS][tT][.][a-zA-Z]+ {	
	char *__elemento = strtok(yytext, ".");
	__elemento = strtok(NULL, ".");

	for(unsigned i = 0; i < N_CONST; i++) 
		if(strcmp(__elemento, consts[i].const_str) == 0) {
			lexema->valnum  = consts[i].value;
			return YL::BisonParser::token::NUMERIC; 
		} else {
		cerr << "Error, constante no identificada 'const." << __elemento << "'\n";
		exit(EXIT_FAILURE);
	}
}

"<->" {
	return YL::BisonParser::token::SWAP_OP;
}

">="	{
	// Greater or equal:
	return YL::BisonParser::token::GE;
}

"<=" {
	// Less or equal:
	return YL::BisonParser::token::LE;
}

"==" {
	// Equal:
	return YL::BisonParser::token::EQ;
}

"!=" {
	// Not equal:
	return YL::BisonParser::token::NE;
}

"&&" {
	return YL::BisonParser::token::AND;
}

"||" {
	return YL::BisonParser::token::OR;
}

[oO][rR]	 {
	return YL::BisonParser::token::OR;
}

[aA][nN][dD] {
	return YL::BisonParser::token::AND;
}

"-eq" {
	// Equal shell operator
	return YL::BisonParser::token::EQ;
}

"-neq" {
	// Not equal shell operator
	return YL::BisonParser::token::NE;
}
"-lt" {
	//  Less shell operator
	return YL::BisonParser::token::_LT_;
}

"<<" {
	return YL::BisonParser::token::SHIFTLEFT;
}

">>" {					
	return YL::BisonParser::token::SHIFTRIGHT; 
}

"+=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_MAS;
} 

"-=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_MENOS;
}

"*=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_MUL;
}

"/=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_DIV;
}

"%=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_MOD;
}

"<<=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_SHIFTLEFT;
}

">>=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_SHIFTRIGHT;
}

"^=" {
	return YL::BisonParser::token::OP_ASIGN_ABR_POW;
}

":=" {
	return YL::BisonParser::token::PASCAL_ASSIGN;
}

[mM][eE][nN][oO][rR] {
	// "menor"
	return YL::BisonParser::token::EXPR_MENOR;
}

[mM][eE][nN][oO][rR][iI][gG][uU][aA][lL] {
	// "menorigual"
	return YL::BisonParser::token::EXPR_MENORIGUAL;
}

[mM][aA][yY][oO][rR] {
	// "mayor"
	return YL::BisonParser::token::EXPR_MAYOR;
}

[mM][aA][yY][oO][rR][iI][gG][uU][aA][lL] {
	// "mayorigual"
	return YL::BisonParser::token::EXPR_MAYORIGUAL;
}

[eE][lL][eE][vV][aA][dD][oO] {
	return YL::BisonParser::token::EXPR_ELEVADO;
}

\"	{ BEGIN	STRING; 
	str_scapes = buf; 
}
<STRING>\\n			{ 
	*str_scapes++ = '\n'; 
}
<STRING>\\t			{ 
	*str_scapes++ = '\t'; 
}
<STRING>\\s			{ 
	*str_scapes++ = ' ';  
}
<STRING>\\b			{ 
	*str_scapes++ = '\b'; 
}
<STRING>\\r			{ 
	*str_scapes++ = '\r'; 
}
<STRING>\\f			{ 
	*str_scapes++ = '\f'; 
}
<STRING>\\q			{ 
	*str_scapes++ = '"'; 
}
<STRING>\\[0-9]		{ 
	/* Caracteres de escape numéricos para saltos de línea */
	for(int _ii = 0; _ii < (*(yytext + 1) - '0'); _ii++) 
		*str_scapes++ = '\n';	
}
<STRING>\"			{
	*str_scapes = 0;
	BEGIN 0; 
	/* REGRESAR EL STRING Y ASIGNARLO AQUÍ */
	strcpy(lexema->cadena, buf);
	return YL::BisonParser::token::CADENA;
}
<STRING>\n			{ 
	cout << "Cadena invalida" << endl;
	exit(EXIT_FAILURE);
}

#.*\n				{;}		/* Comentarios tipo shell, perl, python, etc */
\/\/.*\n			{;}		/* Comentarios estilo C++ */
"rem".*\n			{;}		/* Comentarios estilo basic */
"::".*\n			{;}		/* Comentarios estilo batch */
"--".*\n			{;}		/* Comentarios estilo SQL */

[-(*)<>@=+/;{}.:?"^%!~,&\$]|[\[]|[\]] 	{
	return *yytext;
}

[ \t\n]			;


<INITIAL>{
     "/*"              BEGIN(IN_COMMENT);
     }
     <IN_COMMENT>{
     "*/"      BEGIN(INITIAL);
     [^*\n]+   // eat comment in chunks
     "*"       // eat the lone star
     \n        yylineno++;
}

.		{ cout << "Caracter desconocido: '" << yytext << '\'' << endl; }

%%


