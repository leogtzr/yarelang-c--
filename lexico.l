/* Leo Gutiérrez Ramírez, leorocko13@hotmail.com */
%{
	#include <stdlib.h>
	#include "estructuras.h"
	#include "constantes.h"
	#include "y.tab.h"
	extern char opVar[4];
	extern unsigned int lineno;
	char buf[100];
	char *str_scapes;			/* Puntero para ir acumulando caracteres de escape */
%}
%x STRING

%%

%option yylineno;

[a-zA-Z] 				{
						/* TODO Revisar esto con calma */
						if(isupper(*yytext))
							yylval.sIndex = tolower(*yytext) - 'a';
						else
							yylval.sIndex = *yytext - 'a';
						return VARIABLE;
					}
[0-9]+([.][0-9]+)? 	{
						yylval.iValue = strtod(yytext, NULL);
						return INTEGER;
}

[0-9]+([.][0-9]+)?[gG]	 {
		/* Cortar la 'g' */
		yytext[strlen(yytext) - 1] = '\0';		
		strcpy(yylval.cadena_gigante, yytext);
		return GIGANTE;
}

[cC][oO][nN][sS][tT][.][a-zA-Z]+ {	
									char *__elemento = strtok(yytext, ".");
									__elemento = strtok(NULL, ".");

									unsigned i;
									for(i = 0; i < N_CONST; i++) 
										if(strcmp(__elemento, consts[i].const_str) == 0) {
											yylval.iValue = consts[i].value;
											return INTEGER;
										}
									fprintf(stderr, "Error, constante no identificada 'const.%s'\n", __elemento);
									exit(EXIT_FAILURE);
								}

0[xX][0-9a-fA-F]+	{
							yylval.iValue = atof(yytext);
						return INTEGER;
					}

[$].+[$]	{
						strcpy(yylval.nameFunction, yytext);
						yylval.nameFunction[strlen(yylval.nameFunction)] = '\0';
						return FUNCNAME;
}

:["'0-9 _#@a-zA-Z\t\+\-\.\^\|\(\)\\/]+: 	{
							unsigned _i_;
							strcpy(yylval.identificador, yytext);
							for(_i_ = 0; _i_ < strlen(yylval.identificador); _i_++)
								if(isalpha(yylval.identificador[_i_]) && isupper(yylval.identificador[_i_]))
									yylval.identificador[_i_] = tolower(yylval.identificador[_i_]);
							return ID;
						}
@[a-zA-Z\t:0-9_]+ {
							
							unsigned _i_;
							strcpy(yylval.idArray, yytext);
							for(_i_ = 0; _i_ < strlen(yylval.idArray); _i_++)
								if(isalpha(yylval.idArray[_i_]) && isupper(yylval.idArray[_i_]))
									yylval.idArray[_i_] = tolower(yylval.idArray[_i_]);
							return ID_ARRAY;

}

[gG][.][0-9]+([.][0-9]+)?[.][gG] {
	/* Detección de gigantes: */
	/* Cortando los caracteres sobrantes: */
	*yytext++;
	*yytext++;
	yytext[strlen(yytext) - 1] = '\0';
	yytext[strlen(yytext) - 1] = '\0';
	unsigned _i_;
	strcpy(yylval.idgigante, yytext);
	for(_i_ = 0; _i_ < strlen(yylval.idgigante); _i_++)
		if(isalpha(yylval.idgigante[_i_]) && isupper(yylval.idgigante[_i_]))
			yylval.idgigante[_i_] = tolower(yylval.idgigante[_i_]);
	/*printf("Gigante detectado '%s'-'%d'\n", yylval.idgigante, strlen(yylval.idgigante));*/
	return ID_GIGANTE;
}

\"					{ BEGIN	STRING; str_scapes = buf; }
<STRING>\\n			{ *str_scapes++ = '\n'; }
<STRING>\\t			{ *str_scapes++ = '\t'; }
<STRING>\\s			{ *str_scapes++ = ' ';  }
<STRING>\\b			{ *str_scapes++ = '\b'; }
<STRING>\\r			{ *str_scapes++ = '\r'; }
<STRING>\\f			{ *str_scapes++ = '\f'; }
<STRING>\\q			{ *str_scapes++ = '"'; }
<STRING>\\[0-9]		{ 
					int _ii;
					/* Caracteres de escape numéricos para saltos de línea */
					for(_ii = 0; _ii < (*(yytext + 1) - '0'); _ii++) 
						*str_scapes++ = '\n';	
}
<STRING>\"			{
						*str_scapes = 0;
						BEGIN 0; 
						/* REGRESAR EL STRING Y ASIGNARLO AQUÍ */
						strcpy(yylval.cadena, buf);
						return CADENA;
					}
<STRING>\n			{ printf("Error, Invalid string at line: %d\n", lineno + 1); exit(EXIT_FAILURE);	}
<STRING>.			{ *str_scapes++ = *yytext; }

"/*"				{comment();}	/* Comentarios */
#.*\n				{;}		/* Comentarios tipo shell, perl, python, etc */
\/\/.*\n			{;}		/* Comentarios estilo C++ */
"rem".*\n			{;}		/* Comentarios estilo basic */
"::".*\n			{;}		/* Comentarios estilo batch */
"--".*\n			{;}		/* Comentarios estilo SQL */

[-(*)<>@=+/;{}.:?"^%!~,&\$]|[\[]|[\]] 	{
									return *yytext;
					}

[aA][rR][rR][aA][yY]				return ARRAY;
":="								return ASIGNACION_PASCAL;
"<-"								return ASIGNACION_PASCAL;
([lL][eE][tT])|([sS][eE][tT])		return LETSET;
[tT][hH][eE][nN]					return IFTHEN;
([eE][nN][Dd])|([dD][oO][nN][eE])	return IFEND;

"-lt"								return _LT_;
"-gt"								return _GT_;
">=" 								return GE;
"-ge"								return GE;
"<->"								return SWAP;
"<=" 								return LE;
"-le"								return LE;
"==" 								return EQ;
"-eq"								return EQ;
"!=" 								return NE;
"-ne"								return NE;
"&&"								return AND;
"||"								return OR;
"<<"								return SHIFTLEFT;
">>" 								return SHIFTRIGHT; 

[mM][aA][sS]						return EXPR_MAS;
[mM][eE][nN][oO][sS]				return EXPR_MENOS;
[eE][nN][tT][rR][eE]				return EXPR_DIV;
[sS][oO][bB][rR][eE]				return EXPR_DIV;
[pP][oO][rR]						return EXPR_MUL;
[nN][oO][tT]?						return EXPR_NOT;
[eE][lL][eE][vV][aA][dD][oO]		return EXPR_ELEVADO;
[mM][eE][nN][oO][rR]				return EXPR_MENOR;
[mM][aA][yY][oO][rR]				return EXPR_MAYOR;
[mM][eE][nN][oO][rR][qQ][uU][eE]	return EXPR_MENORQUE;
[mM][aA][yY][oO][rR][qQ][uU][eE]	return EXPR_MAYORQUE;

[xX][oO][rR]						return XOROP;

"+="								return ASIGN_ADD;
"-="								return ASIGN_SUB;
"*="								return ASIGN_MUL;
"/="								return ASIGN_DIV;
"^="								return ASIGN_POW;
"%="								return ASIGN_MOD;
"<<="								return ASIGN_SHIFTLEFT;
">>="								return ASIGN_SHIFTRIGHT;
"&="								return ASIGN_AND;
"|="								return ASIGN_OR;
".="								return CONCATENATE_DIGITS;
":)"								return FACE_HAPPY;
":("								return FACE_SAD;
":|"								return FACE_NO;

[pP][rR][oO][cC]					return PROC;
[eE][xX][iI][tT]					return EXIT;
[fF][oO][rR]						return FOR;
[cC][aA][lL][lL]					return CALL;
[uU][nN][lL][eE][sS][sS] 			return UNLESS;
[aA][nN][dD]						return AND;
[oO][rR]							return OR;
[fF][oO][rR][eE][aA][cC][hH]		return FOREACH;
[Ii][nN][cC][rR]					return INCREMENTAR;
[dD][eE][cC][rR]					return DECREMENTAR;
[dD][eE][cC][lL][aA][rR][eE]		return DECLARE;
[fF][uU][nN][cC][tT][iI][oO][nN]	return FUNCTION;
[iI][nN][tT]						return INT_TYPE;
[dD][eE][cC][iI][mM][aA][lL]		return DECIMAL_TYPE;
[bB][oO][oO][lL]					return BOOL_TYPE;
([vV][oO][iI][dD])|([eE][mM][pP][tT][yY])	return VOID;
'&'									return ANDBITS;
'|'									return ORBITS;
"_@_"								return OPVAR;
[wW][hH][iI][lL][eE] 				return WHILE;
[dD][oO]							return DO;
[Ii][fF] 							return IF;
[eE][lL][sS][eE] 					return ELSE;
[rR][eE][aA][dD]					return READ;
([pP][rR][iI][nN][tT])|([sS][aA][yY]) 	return PRINT;
[pP][aA][rR]						return PAR;
([pP][rR][iI][nN][tT][Nn]) 			return PRINTN;
[aA][bB][sS]						return ABS;
[Pp][rR][aA][sS][cC][iI][iI]		return PRASCII;
[fF][aA][cC][tT][oO][rR][iI][aA][lL]	return FACTORIAL;
[sS][uU][mM][aA][tT][oO][rR][iI][aA]	return SUMATORIA;
[rR][aA][nN][dD]					return RAND;
[bB][rR][eE][aA][kK]				return BREAK;
[pP][uU][tT][sS]					return PUTS;
[sS][tT][rR][lL][eE][nN] 			return STRLEN;
[aA][dD][dD]						return ADDASM;
[sS][uU][bB]						return SUBASM;
[mM][oO][vV][eE]					return MOVE;
[aA][sS][sS][iI][gG][nN]			return MOVE;
[tT][oO]							return TO;
[mM][oO][vV]						return MOVASM;

[sS][qQ][rR][tT]					return SQRT;
[aA][cC][oO][sS]					return ACOS;
[aA][sS][iI][nN]					return ASIN;
[aA][tT][aA][nN]					return ATAN;
[cC][eE][iI][lL]					return CEIL;
[cC][oO][sS]						return COS;
[cC][oO][sS][hH]					return COSH;
[eE][xX][pP]						return EXP;
[fF][lL][oO][oO][rR]				return FLOOR;
[lL][nN]							return LN;
[sS][iI][nN]						return SIN;
[sS][iI][nN][hH]					return SINH;
[tT][aA][nN]						return TAN;
[tT][aA][nN][hH]					return TANH;
[sS][yY][sS][tT][eE][mM]			return SYSTEM;

[pP][uU][sS][hH]					return PUSH;
[vV][eE][rR][pP][iI][lL][aA]		return VER_PILA;
[pP][oO][pP]						return POP;

[.][.][.]([.]+)?					return ELIPSIS;

[dD][eE][cC][lL][aA][rR][eE][_][gG]		return DECLARE_G;	/* declare_g(...); */

[ \t] 				;
[\n]					{ lineno++; }
.	{
				char __linea[40];
				sprintf(__linea, "Carácter desconocido en la línea %d\n", lineno + 1);
				fputs(__linea, stdout);

				/* FIXME Decidir si se va a continuar o al error parar todo */
				
				/*yyerror(__linea);*/
	}

%%

comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0);
/*		putchar(c);*/

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	/*if (c != 0)
		putchar(c1);*/
}

int yywrap(void) {
	return 1;
}
