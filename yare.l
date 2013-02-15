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
	#include <cstring>

	void append_char(char *s, char c) {
    	unsigned int length = strlen(s);
    	s[length] = c;
    	s[length + 1] = '\0';
	}

	void remove_first_char(char *s) {
    	memmove(s, s + 1, strlen(s));
	}

	void remove_last_char(char *s) {
    	s[strlen(s) - 1] = '\0';
	}

	// Opvar:
	extern char opVar[4];
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
	return YL::YareParser::token::NUMERIC;
}

[a-zA-Z] 				{
						// TODO Revisar esto con calma
	if(isupper(*yytext))
		lexema->sIndex = tolower(*yytext) - 'a';
	else
		lexema->sIndex = *yytext - 'a';
	return YL::YareParser::token::VARIABLE;
}

:["'0-9 _#@a-zA-Z\t\+\-\.\^\|\(\)\\/]+: 	{
	strcpy(lexema->identificador, yytext);
	for(unsigned _i_ = 0; _i_ < strlen(lexema->identificador); _i_++)
		if(isalpha(lexema->identificador[_i_]) && isupper(lexema->identificador[_i_]))
			lexema->identificador[_i_] = tolower(lexema->identificador[_i_]);
	return YL::YareParser::token::ID;
}

[$].+[$]	{
	strcpy(lexema->nameFunction, yytext);
	lexema->nameFunction[strlen(lexema->nameFunction)] = '\0';
	return YL::YareParser::token::FUNCNAME;
}

0[xX][0-9a-fA-F]+	{
	lexema->valnum = strtold(yytext, NULL);
	return YL::YareParser::token::NUMERIC;
}

[.][.][.]([.]+)?[?] {
	// 676 ...? 8729834, expr ...? expr
	return YL::YareParser::token::RANGE_RANDOM;
}

[pP][rR][oO][cC] {
	return YL::YareParser::token::PROC;
}

[cC][aA][lL][lL] {
	return YL::YareParser::token::CALL;
}

[pP][rR][iI][nN][tT][nN]	{
	return YL::YareParser::token::PRINTN;
}

[pP][rR][iI][nN][tT] {
	return YL::YareParser::token::PRINT;
}

[pP][uU][tT][sS] {
	return YL::YareParser::token::PUTS;	
}

[iI][nN][cC] {
	return YL::YareParser::token::INC;
}

[dD][eE][cC] {
	return YL::YareParser::token::DEC;
}

[lLsS][eE][tT] {
	return YL::YareParser::token::LETSET_ASSIGN;
}

[tT][oO] {
	return YL::YareParser::token::TO;
}

[mM][oO][vV][eE] {
	return YL::YareParser::token::MOVE;
}

[mM][oO][vV] {
	// mov x, 1 + 2;
	return YL::YareParser::token::MOV_ASM;
}

[aA][dD][dD] {
	// dd x, 1+ 2 * 3;
	return YL::YareParser::token::ADD_ASM;
}

[sS][uU][bB] {
	// add x, 1+ 2 * 3;
	return YL::YareParser::token::SUB_ASM;
}

[mM][uU][lL] {
	// mul x, 2;
	return YL::YareParser::token::MUL_ASM;
}

[wW][hH][iI][lL][eE] {
	return YL::YareParser::token::WHILE;
}

[iI][fF] {
	return YL::YareParser::token::IF;
}

[eE][lL][sS][eE] {
	return YL::YareParser::token::ELSE;
}

[bB][rR][eE][aA][kK] {
	return YL::YareParser::token::BREAK;
}

[rR][aA][nN][dD] {
	return YL::YareParser::token::RAND;
}

[xX][oO][rR] {
	return YL::YareParser::token::XOROP;
}

[Mm][oO][dD] {
	return YL::YareParser::token::MOD_WORD;
}

[nN][oO][tT]? /* Expressions with WORDS */	{
	return YL::YareParser::token::EXPR_NOT;
}

[cC][oO][nN][sS][tT][.][a-zA-Z0-9]+ {	
	char *__elemento = strtok(yytext, ".");
	__elemento = strtok(NULL, ".");

	for(unsigned i = 0; i < N_CONST; i++) {
		if(strcmp(__elemento, consts[i].const_str) == 0) {
			lexema->valnum  = consts[i].value;
			return YL::YareParser::token::NUMERIC; 
		}
	}
	cerr << "Error, constante no identificada 'const." << __elemento << "'\n";
	exit(EXIT_FAILURE);
}

"<->" {
	return YL::YareParser::token::SWAP_OP;
}

">="	{
	// Greater or equal:
	return YL::YareParser::token::GE;
}

"<=" {
	// Less or equal:
	return YL::YareParser::token::LE;
}

"==" {
	// Equal:
	return YL::YareParser::token::EQ;
}

"!=" {
	// Not equal:
	return YL::YareParser::token::NE;
}

"&&" {
	return YL::YareParser::token::AND;
}

"||" {
	return YL::YareParser::token::OR;
}

[oO][rR]	 {
	return YL::YareParser::token::OR;
}

[aA][nN][dD] {
	return YL::YareParser::token::AND;
}

"-eq" {
	// Equal shell operator ==
	return YL::YareParser::token::EQ;
}

"-neq" {
	// Not equal shell operator !=
	return YL::YareParser::token::NE;
}

"-lt" {
	//  Less shell operator <
	return YL::YareParser::token::_LT_;
}

"-gt" {
	//  Great shell operator >
	return YL::YareParser::token::_GT_;
}

"<<" {
	return YL::YareParser::token::SHIFTLEFT;
}

">>" {					
	return YL::YareParser::token::SHIFTRIGHT; 
}

"+=" {
	return YL::YareParser::token::OP_ASIGN_ABR_MAS;
} 

"-=" {
	return YL::YareParser::token::OP_ASIGN_ABR_MENOS;
}

"*=" {
	return YL::YareParser::token::OP_ASIGN_ABR_MUL;
}

"/=" {
	return YL::YareParser::token::OP_ASIGN_ABR_DIV;
}

"%=" {
	return YL::YareParser::token::OP_ASIGN_ABR_MOD;
}

"<<=" {
	return YL::YareParser::token::OP_ASIGN_ABR_SHIFTLEFT;
}

">>=" {
	return YL::YareParser::token::OP_ASIGN_ABR_SHIFTRIGHT;
}

"&=" {
	return YL::YareParser::token::OP_ASIGN_ABR_AND;
}

"^=" {
	return YL::YareParser::token::OP_ASIGN_ABR_POW;
}

":=" {
	return YL::YareParser::token::PASCAL_ASSIGN;
}

[mM][eE][nN][oO][rR] {
	// "menor"
	return YL::YareParser::token::EXPR_MENOR;
}

[mM][eE][nN][oO][rR][iI][gG][uU][aA][lL] {
	// "menorigual"
	return YL::YareParser::token::EXPR_MENORIGUAL;
}

[mM][aA][yY][oO][rR] {
	// "mayor"
	return YL::YareParser::token::EXPR_MAYOR;
}

[mM][aA][yY][oO][rR][iI][gG][uU][aA][lL] {
	// "mayorigual"
	return YL::YareParser::token::EXPR_MAYORIGUAL;
}

[iI][gG][uU][aA][lL] {
	return YL::YareParser::token::EXPR_IGUAL;	
}

[mM][aA][sS] {
	return YL::YareParser::token::EXPR_MAS;	
}

[mM][eE][nN][oO][sS] {
	return YL::YareParser::token::EXPR_MENOS;		
}

[pP][oO][rR] {
	return YL::YareParser::token::EXPR_MUL;			
}

[eE][nN][tT][rR][eE] {
	return YL::YareParser::token::EXPR_DIV;			
}

[eE][lL][eE][vV][aA][dD][oO] {
	return YL::YareParser::token::EXPR_ELEVADO;
}

[aA][bB][sS] {
	return YL::YareParser::token::ABS;	
}

[sS][qQ][rR][tT]					{
	return YL::YareParser::token::SQRT;
}

[aA][cC][oO][sS] {
	return YL::YareParser::token::ACOS;	
}

[aA][sS][iI][nN]	{
	return YL::YareParser::token::ASIN;	
}

[aA][tT][aA][nN]	{
	return YL::YareParser::token::ATAN;	
}

[cC][eE][iI][lL]	{
	return YL::YareParser::token::CEIL;	
}

[cC][oO][sS]		{
	return YL::YareParser::token::COS;	
}

[cC][oO][sS][hH]	{
	return YL::YareParser::token::COSH;	
}

[eE][xX][pP]		{
	return YL::YareParser::token::EXP;		
}

[fF][lL][oO][oO][rR]	{
	return YL::YareParser::token::FLOOR;
}

[lL][nN]	{
	return YL::YareParser::token::LN;
}

[sS][iI][nN]	{
	return YL::YareParser::token::SIN;
}

[sS][iI][nN][hH]	{
	return YL::YareParser::token::SINH;
}

[tT][aA][nN]	{
	return YL::YareParser::token::TAN;
}

[tT][aA][nN][hH]	{
	   return YL::YareParser::token::TANH;
}

[fF][aA][cC][tT][oO][rR][iI][aA][lL]	{
	return YL::YareParser::token::FACTORIAL;
}

[sS][uU][mM][aA][tT][oO][rR][iI][aA]	{
	return YL::YareParser::token::SUMATORIA;
}

[pP][uU][sS][hH] {
	return YL::YareParser::token::PUSH;	
}

[pP][oO][pP] {
	return YL::YareParser::token::POP;	
}

":)"	{
	return YL::YareParser::token::FACE_HAPPY;
}

":("	{
	return YL::YareParser::token::FACE_SAD;
}

":|"	{
	return YL::YareParser::token::FACE_NO;
}

\"([^\\\"]|\\.)*\"  {
	// std::cout << "String found: '" << yytext << "'" << endl;
	char *string_final = (char *)malloc(strlen(yytext) + 1);
	string_final[0] = '\0';
    unsigned i;

    bool upper = false;
    bool lower = false;

    for(i = 0; yytext[i] != '\0'; i++) {
        if(yytext[i] == '\\') {
            switch(yytext[i + 1]) {
                case 'n':
                    append_char(string_final, '\n');
                    i++;
                    break;
                case 't':
                    append_char(string_final, '\t');
                    i++;
                    break;
                case 's':
                    append_char(string_final, ' ');
                    i++;
                    break;
                case 'b':
                    append_char(string_final, '\b');
                    i++;
                    break;
                case 'r':
                    append_char(string_final, '\r');
                    i++;
                    break;
                case 'f':
                    append_char(string_final, '\f');
                    i++;
                    break;
                case 'q':
                    append_char(string_final, '"');
                    i++;
                case '\\':
                	append_char(string_final, '\\');
                	i++;
                case 'u':
                	upper = true;
                	i++;
                    break;

                case 'l':
                	lower = true;
                	i++;
                    break;

                default:
                    if(isdigit(yytext[i + 1]) == true) {
                        unsigned n_newline = yytext[i + 1] - '0';
                        unsigned _k = 0;
                        for(_k = 0; _k < n_newline; _k++)
                            append_char(string_final, '\n');
                            i++;
                    }
            }
        } else {
            if(upper && isalpha(yytext[i])) {
            	append_char(string_final, toupper(yytext[i]));
            	upper = false;
            } else if (lower && isalpha(yytext[i])){
            	append_char(string_final, tolower(yytext[i]));
            	lower = false;
            } else {
            	append_char(string_final, yytext[i]);
            }
        }
    }
    
    remove_first_char(string_final);
    remove_last_char(string_final);

    strncpy(lexema->cadena, string_final, strlen(string_final) + 1);

	return YL::YareParser::token::CADENA;
}

#.*\n				{;}		/* Comentarios tipo shell, perl, python, etc */
\/\/.*\n			{;}		/* Comentarios estilo C++ */
"rem".*\n			{;}		/* Comentarios estilo basic */
"::".*\n			{;}		/* Comentarios estilo batch */
"--".*\n			{;}		/* Comentarios estilo SQL */

[-(*)<>@=+/;{}.:?"^%!~,&\$]|[\[]|[\]] 	{
	return *yytext;
}

[ \t]			{;}
[\n] { ; }

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
