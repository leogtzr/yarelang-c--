/* Leo Gutiérrez Ramírez */
#include <stdio.h>
#include "estructuras.h"
#include "yare.tab.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mymath.h"
#include "data_types.h"
#include "giantslist.h"
#include "gigantesops.h"

#define STACK_SIZE 		100

void swap(nodeType *p);
unsigned short int getAscii(long long);
int i_pila = 0;
void ver_pila(short);
short __i__stack__;
double _temp_swap;
double recibido;
double _temp_swap_id_var_;
double _temp_swap_var_id_;
double _temp_concatenate_digits;
char str_concatena_[100];
long _exit_return_;
/* La variable índice que controla la pila */
short spLoop = -1;
/* FIXME Ver si es conveniente una pila de 100 elementos o más */
short pilaLoop[100] = {0};

/* Devuelve un long double si se ha convertido bien, sino se
   debe de checar si end finaliza en '\0'
   Si finaliza en '/0' la conversión se hizo correctamente, sino ha
   ocurrido un error */
long double check(char *s, char **end) {
    long double temp = strtold(s, end);
    return temp;
}

long double run(nodeType *p) {
	if (!p) 
		return 0.0f;
	switch(p->type) {

		case typeCon:
			return p->con.value;

		case typeCadena:
			if((spLoop < 0) || pilaLoop[spLoop]) {
				/*printf("%s", p->con.cadena);*/
			}
			return (double)strlen(p->con.cadena);

		case typeId:
			return sym[p->id.i];

		case typeVar:
			if(buscar(identificadores, p->id.identificador))	
				return getValue(identificadores, p->id.identificador);
			else
				return 0.0f;
		
		/*case typeStrlen:
			return (double)strlen(p->con.cadena);*/

		case typeSystem:
			if((spLoop < 0) || pilaLoop[spLoop])
				system(p->con.cadena);
			return 0.0f;

		case typeOpr:
			switch(p->opr.oper) {

				case WHILE: 
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

					return 0.0f;
				
				case DO:
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

				case IF:
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
					return 0.0f;

				case PRINT: 
					if((spLoop < 0) || pilaLoop[spLoop])
						printf("%lf", run(p->opr.op[0]));
					return 0.0f;

				case PRINTN:
					if((spLoop < 0) || pilaLoop[spLoop])
						if(p->opr.op[0]->type == typeId) {
							printf("[%lf]\n", sym[p->opr.op[0]->id.i]);
						} else {
							printf("%lf\n", run(p->opr.op[0]));
						}

					return 0.0f;

				case PUTS:
					if((spLoop < 0) || pilaLoop[spLoop])
						printf("%s", p->opr.op[0]->con.cadena);
					return 0.0f;

				case RAND:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						srand((unsigned)time(NULL));
						printf("%d\n", rand());
					}
					return 0.0f;

				case READ:
					/* Try to open a file with "random" name :p */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						freopen("jkhsahjksad 67asdjhga ad", "r", stdin);
						char _temp[100];
						char *_end;
						unsigned short _index = 0;
						unsigned char _c;
						/* SHIT */
						long double _resultado;
						
						while((_c = getchar()) != '\n') 
							_temp[_index++] = _c;
						
						_temp[_index] = '\0';
	
						_resultado = check(_temp, &_end);
						if(*_end != '\0') {
							/* TODO PENDIENTE */
							return (sym[p->opr.op[0]->id.i] = -1);
						} else {
							/* ASIGNAR A LA VARIABLE */
							/* TODO PENDIENTE */
							return (sym[p->opr.op[0]->id.i] = _resultado);
						}
					}
					return 0.0f;

				case STRLEN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						/*printf("Pasa sobre [%s]\n", p->opr.op[0]->con.cadena);*/
	
						return strlen(p->opr.op[0]->con.cadena);
						return run(p->opr.op[0]);
					}
					 else 
						return 0.0f;

				case ';':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						run(p->opr.op[0]);
						return run(p->opr.op[1]);
					} else 
						return 0.0f;

				case '=':
					/* TODO PENDIENTE */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = run(p->opr.op[1]);	/* PEDOS */
					}
					return 0.0f;

				case SWAP:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						swap(p);
					}
					return 0.0f;

				case LETSET:
					/* TODO PENDIENTE */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = run(p->opr.op[1]);
					} else {
						return 0.0f;
					}

				case ASIGNACION_PASCAL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = run(p->opr.op[1]);
					}
					return 0.0f;

				case MOVE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[1]->id.i] = run(p->opr.op[0]);
					}
					return 0.0f;

				case MOVASM:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = run(p->opr.op[1]);
					}
					return 0.0f;

				case ADDASM:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						sym[p->opr.op[0]->id.i] += run(p->opr.op[1]);
						return sym[p->opr.op[0]->id.i];
					}
					return 0.0f;
				
				case SUBASM:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						sym[p->opr.op[0]->id.i] -= run(p->opr.op[1]);
						return sym[p->opr.op[0]->id.i];
					}
					return 0.0f;
				
				case INITRAND:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = rand() % 100; 
					}
					return 0.0f;

				case FACE_HAPPY:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = 1; 
					}
					return 0.0f;

				case FACE_SAD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = -1;
					}
					return 0.0f;
				
				case FACE_NO:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = 0;
					}
					return 0.0f;
				
				case INCR:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i]++;
					}
					return 0.0f;

				case DECR:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i]--;
					}
					return 0.0f;

				case UMINUS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return -run(p->opr.op[0]);
					}
					return 0.0f;

				case NEGACION:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return !run(p->opr.op[0]);
					}
					return 0.0f;

				case '+':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) + run(p->opr.op[1]);
					}
					return 0.0f;

				case '-':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) - run(p->opr.op[1]);
					}
					return 0.0f;

				case '*':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) * run(p->opr.op[1]);
					}
					return 0.0f;

				case '/':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) / run(p->opr.op[1]);
					}
					return 0.0f;
				
				case '^':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return pow(run(p->opr.op[0]), run(p->opr.op[1]));
					}
					return 0.0f;

				case '%':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return (long)run(p->opr.op[0]) % (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case '<':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) < run(p->opr.op[1]);
					}
					return 0.0f;

				case '>':
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) > run(p->opr.op[1]);
					}
					return 0.0f;
				
				case XOROP:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return (long)run(p->opr.op[0]) ^ (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case GE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) >= run(p->opr.op[1]);
					}
					return 0.0f;

				case LE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) <= run(p->opr.op[1]);
					}
					return 0.0f;

				case NE:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) != run(p->opr.op[1]);
					}
					return 0.0f;

				case EQ:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) == run(p->opr.op[1]);
					}
					return 0.0f;
				
				case AND:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) && run(p->opr.op[1]);
					}
					return 0.0f;

				case ANDBITS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return (long)run(p->opr.op[0]) & (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case OR:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]) || run(p->opr.op[1]);
					}
					return 0.0f;

				case ORBITS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return (long)run(p->opr.op[0]) | (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case SHIFTLEFT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return (long)run(p->opr.op[0]) << (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case SHIFTRIGHT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return (long)run(p->opr.op[0]) >> (long)run(p->opr.op[1]);
					}
					return 0.0f;

				/* Operadores de asignación */
				case ASIGN_ADD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] += run(p->opr.op[1]);
					}
					return 0.0f;
			
				case ASIGN_SUB:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] -= run(p->opr.op[1]);
					}
					return 0.0f;

				case ASIGN_MUL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] *= run(p->opr.op[1]);
					}
					return 0.0f;

				case ASIGN_DIV:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] /= run(p->opr.op[1]);
					}
					return 0.0f;

				case ASIGN_MOD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] % (long)run(p->opr.op[1]);
					}
					return 0.0f;
				
				case ASIGN_POW:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = pow(sym[p->opr.op[0]->id.i], run(p->opr.op[1]));
					}
					return 0.0f;

				case ASIGN_SHIFTLEFT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] << (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case ASIGN_SHIFTRIGHT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] >> (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case ASIGN_AND:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] & (long)run(p->opr.op[1]);
					}
					return 0.0f;

				case ASIGN_OR:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] | (long)run(p->opr.op[1]);
					}
					return 0.0f;

				/* Operadores variables */
				case OPVAR_ADD:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "+");
					}
					return 0.0f;

				case OPVAR_SUB:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "-");
					}
					return 0.0f;

				case OPVAR_MUL:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "*");
					}
					return 0.0f;

				case OPVAR_DIV:	
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "/");
					}
					return 0.0f;

				case OPVAR_POW:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						strcpy(opVar, "^");
					}
					return 0.0f;

				case _ASIGNACION_:
					/* Primero hay que buscar si el ID está, si sí está hay que modificar el valor
						basado en el string id */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
	
						} else {
							/* Sino está hay que crear la variable en la tabla de símbolos y ponerle un valor */
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _READ_:
					/* Try to open a file with random name :p */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						freopen("jkhsahjksad 67asdjhga ad", "r", stdin);
						char __temp[100];
						char *__end;
						unsigned short __index = 0;
						unsigned char __c;
						long double __resultado;
						
						while((__c = getchar()) != '\n') 
							__temp[__index++] = __c;
						
						__temp[__index] = '\0';
	
						__resultado = check(__temp, &__end);
						
						if(*__end != '\0') {
							/* Algo fue mal, ponemos en la variable un -1 */ 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, -1); 
						} else {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, (int)__resultado); 
						}
					}
					return 0.0f;

				case _INITRAND_:
					/* Si está solo asignamos: */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, rand() % 100);
						} else {
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, rand() % 100);
						}
					}
					return 0.0f;
				
				/* Smileys con identificadores */
				case _FACE_HAPPY_:
					/* Si está solo asignamos: */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 1);
						} else {
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 1);
						}
					}
					return 0.0f;
	
				case _FACE_SAD_:
					/* Si está solo asignamos: */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, -1);
						} else {
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, -1);
						}
					}
					return 0.0f;

				case _FACE_NO_:
					/* Si está solo asignamos: */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 0);
						} else {
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 0);
						}
					}
					return 0.0f;
				/* Asignaciones abreviadas para identificadores */
				case _ASIGN_ADD_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								getValue(identificadores, p->opr.op[0]->id.identificador) + run(p->opr.op[1]));
						}
					}
					return 0.0f;
				
				case _ASIGN_SUB_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								getValue(identificadores, p->opr.op[0]->id.identificador) - run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ASIGN_MUL_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								getValue(identificadores, p->opr.op[0]->id.identificador) * run(p->opr.op[1]));
						}
					}
					return 0.0f;
					
				case _ASIGN_DIV_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								getValue(identificadores, p->opr.op[0]->id.identificador) / run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ASIGN_MOD_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								(long)getValue(identificadores, p->opr.op[0]->id.identificador) % (long)run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ASIGN_SHIFTLEFT_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								(long)getValue(identificadores, p->opr.op[0]->id.identificador) << (long)run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ASIGN_SHIFTRIGHT_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								(long)getValue(identificadores, p->opr.op[0]->id.identificador) >> (long)run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ASIGN_AND_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								(long)getValue(identificadores, p->opr.op[0]->id.identificador) & (long)run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ASIGN_OR_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								(long)getValue(identificadores, p->opr.op[0]->id.identificador) | (long)run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ASIGN_PASCAL_:
					/* Primero hay que buscar si el ID está, si sí está hay que modificar el valor
						basado en el string id */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
	
						} else {
							/* Sino está hay que crear la variable en la tabla de símbolos y ponerle un valor */
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						}
					}
					return 0.0f;
					
				case _LETSET_:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _MOVE_:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[1]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[1]->id.identificador); 
							return asignar(&identificadores, p->opr.op[1]->id.identificador, run(p->opr.op[0]));
						} else {
							return asignar(&identificadores, p->opr.op[1]->id.identificador, run(p->opr.op[0]));
						}
					}
					return 0.0f;

				case _MOVASM_:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _ADDASM_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								getValue(identificadores, p->opr.op[0]->id.identificador) + run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case _SUBASM_:
					/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							push_r(&identificadores, p->opr.op[0]->id.identificador); 
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						} else {
							/* Solo modificar el valor */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 
								getValue(identificadores, p->opr.op[0]->id.identificador) - run(p->opr.op[1]));
						}
					}
					return 0.0f;

					case _SWAP_:	
					if((spLoop < 0) || pilaLoop[spLoop]) {
						_temp_swap = getValue(identificadores, p->opr.op[0]->id.identificador);	
						asignar(&identificadores, p->opr.op[0]->id.identificador, 
							getValue(identificadores, p->opr.op[1]->id.identificador));
						asignar(&identificadores, p->opr.op[1]->id.identificador, _temp_swap);
					}
						return 0.0f;	
				
					case _INCR_:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
								push_r(&identificadores, p->opr.op[0]->id.identificador); 
								return asignar(&identificadores, p->opr.op[0]->id.identificador, 1);
							} else {
								return asignar(&identificadores, p->opr.op[0]->id.identificador, 
									getValue(identificadores, p->opr.op[0]->id.identificador) + 1); 
							}	
						}
						return 0.0f;

					case _DECR_:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
								push_r(&identificadores, p->opr.op[0]->id.identificador); 
								return asignar(&identificadores, p->opr.op[0]->id.identificador, 1);
							} else {
								return asignar(&identificadores, p->opr.op[0]->id.identificador, 
									getValue(identificadores, p->opr.op[0]->id.identificador) - 1); 
							}
						}
						return 0.0f;

					case _ASIGN_POW_:	
						/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
						if((spLoop < 0) || pilaLoop[spLoop]) {
							if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
								push_r(&identificadores, p->opr.op[0]->id.identificador); 
								return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							} else {
								/* Solo modificar el valor */
								return asignar(&identificadores, p->opr.op[0]->id.identificador, 
									pow(getValue(identificadores, p->opr.op[0]->id.identificador), run(p->opr.op[1])));
							}
						}
						return 0.0f;

					case _SWAP_ID_VAR_:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							_temp_swap_id_var_ = getValue(identificadores, p->opr.op[0]->id.identificador);	
							asignar(&identificadores, p->opr.op[0]->id.identificador, sym[p->opr.op[1]->id.i]);
							sym[p->opr.op[1]->id.i] = _temp_swap_id_var_;
						}
						return 0.0f;
					
					case _SWAP_VAR_ID_:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							_temp_swap_var_id_ = sym[p->opr.op[0]->id.i];
							sym[p->opr.op[0]->id.i] = getValue(identificadores, p->opr.op[1]->id.identificador);
							return asignar(&identificadores, p->opr.op[1]->id.identificador, _temp_swap_var_id_);
						}
						return 0.0f;

					case CONCATENATE_DIGITS_ID:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							sprintf(str_concatena_, "%lf%lf", 
								getValue(identificadores, p->opr.op[0]->id.identificador), run(p->opr.op[1]));
							return asignar(&identificadores, p->opr.op[0]->id.identificador, atoi(str_concatena_));
						}
						return 0.0f;
					
					/* Sentencias */
					case BREAK:
						if(spLoop < 0)	{
							puts("\nWarning: break fuera de ciclo");
							return 0.0f;
						} else {
							return (pilaLoop[spLoop] = 0);
						}
					
					case FOR_MENOS:						
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] -= run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop - 1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] -= run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_MAS:
						spLoop++;
						pilaLoop[spLoop] = 1;
	
						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] += run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop - 1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] += run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_MUL:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] *= run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop - 1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] *= run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_DIV:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] /= run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop - 1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] /= run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_POW:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = pow(sym[p->opr.op[0]->id.i], run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop-1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = pow(sym[p->opr.op[0]->id.i], run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						}

						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_MOD:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] % (long)run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop-1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] % (long)run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_SHIFTLEFTF:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] << (long)run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop-1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] << (long)run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_SHIFTRIGHT:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(spLoop == 0) {
							for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] >> (long)run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						} else if(spLoop > 0) {
						for(sym[p->opr.op[0]->id.i] = run(p->opr.op[1]); (pilaLoop[spLoop-1] && pilaLoop[spLoop]) && run(p->opr.op[2]); 
								sym[p->opr.op[0]->id.i] = (long)sym[p->opr.op[0]->id.i] >> (long)run(p->opr.op[3])) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case ABS:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							return (long long)abs(run(p->opr.op[0]));
						}
						return 0.0f;

					case FACTORIAL:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							return (long long)factorial(run(p->opr.op[0]));
						}
						return 0.0f;

					case SUMATORIA:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							return (long long)sumatoria(run(p->opr.op[0]), run(p->opr.op[1]));
						}
						return 0.0f;

					case CALL:
						/* Comprobar que exista yylval.nameFunction */
						if((spLoop < 0) || pilaLoop[spLoop]) {
							if(buscarFuncion(idFunciones, yylval.nameFunction)) {
								return run(getValueFunction(idFunciones, yylval.nameFunction));
							} else {
								fprintf(stderr, "Error, no existe una función [%s]\n", yylval.nameFunction);
							}	
						}
						return 0.0f;

					case EXIT:
						/* FIXME */
						if((spLoop < 0) || pilaLoop[spLoop]) {
							liberarFunciones(&idFunciones);
							liberar(&identificadores);
							_exit_return_ = run(p->opr.op[0]);
							freeNode(p);
							exit(_exit_return_);
						}
						return 0.0f;

					case FOREACH:
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

					case FOR_MENOS_ID:						
						/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										getValue(identificadores, p->opr.op[0]->id.identificador) - run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_MAS_ID:
						/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										getValue(identificadores, p->opr.op[0]->id.identificador) + run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;
					
					case FOR_MUL_ID:
						spLoop++;
						pilaLoop[spLoop] = 1;
						
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										getValue(identificadores, p->opr.op[0]->id.identificador) * run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;
					
					case FOR_DIV_ID:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										getValue(identificadores, p->opr.op[0]->id.identificador) / run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_POW_ID:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										pow(getValue(identificadores, p->opr.op[0]->id.identificador), run(p->opr.op[3])) )) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;
					
					case FOR_MOD_ID:
						spLoop++;
						pilaLoop[spLoop] = 1;
						
						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										(long)getValue(identificadores, p->opr.op[0]->id.identificador) % (long)run(p->opr.op[3]) )) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;

						return 0.0f;

					case FOR_SHIFTLEFTF_ID:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										(long)getValue(identificadores, p->opr.op[0]->id.identificador) << (long)run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;

					case FOR_SHIFTRIGHT_ID:
						spLoop++;
						pilaLoop[spLoop] = 1;

						if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
							fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
							return 0.0f;
						} else {
							/* Solo modificar el valor */
							asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
							for(; run(p->opr.op[2]); 
									asignar(&identificadores, p->opr.op[0]->id.identificador, 
										(long)getValue(identificadores, p->opr.op[0]->id.identificador) >> (long)run(p->opr.op[3]))) {
								run(p->opr.op[4]);
							}
						}
						pilaLoop[spLoop] = 0;
						spLoop--;
						return 0.0f;
					
					case INCR_FUNC_VAR:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							return ++sym[p->opr.op[0]->id.i];
						}
						return 0.0f;

					case INCR_FUNC_ID:
						/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
						if((spLoop < 0) || pilaLoop[spLoop]) {
							if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
								fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
								return 0.0f;
							} else {
								/* Solo modificar el valor */
								return asignar(&identificadores, p->opr.op[0]->id.identificador, 
									getValue(identificadores, p->opr.op[0]->id.identificador) + 1);
							}
						}
						return 0.0f;

					case DECR_FUNC_VAR:
						if((spLoop < 0) || pilaLoop[spLoop]) {
							return --sym[p->opr.op[0]->id.i];
						}
						return 0.0f;

					case DECR_FUNC_ID:
						/* TODO Primero ver si se encuentra la variable, sino crearla y asignarle el valor */
						if((spLoop < 0) || pilaLoop[spLoop]) {
							if(buscar(identificadores, p->opr.op[0]->id.identificador) == 0) {
								fprintf(stderr, "\nError, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
								return 0.0f;
							} else {
								/* Solo modificar el valor */
								return asignar(&identificadores, p->opr.op[0]->id.identificador, 
									getValue(identificadores, p->opr.op[0]->id.identificador) - 1);
							}
						}
						return 0.0f;

				case UNLESS:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if (!run(p->opr.op[0]))
							run(p->opr.op[1]);
						return 0.0f;
					}
					return 0.0f;

				case SQRT:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return sqrt(run(p->opr.op[0]));
					}
					return 0.0f;

				case SYSTEM:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						return run(p->opr.op[0]);
					}
					return 0.0f;

				case DECLARE:
					/* Primero hay que buscar si el ID está, si sí está hay que modificar el valor
						basado en el string id */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							fprintf(stdout, "Aviso: variable ya declarada\n");	
							return 0.0f;
						} else {
							/* Sino está hay que crear la variable en la tabla de símbolos y ponerle un valor */
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, 0);
						}
					}
					return 0.0f;

				case DECLARE_AND_ASSIGN:	
					/* Primero hay que buscar si el ID está, si sí está hay que modificar el valor
						basado en el string id */
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
							fprintf(stdout, "\tError, redeclaración de la variable '%s'\n", p->opr.op[0]->id.identificador);
							return 0.0f;	
						} else {
							/* Sino está hay que crear la variable en la tabla de símbolos y ponerle un valor */
							push_r(&identificadores, p->opr.op[0]->id.identificador);
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						}
					}

				case INITIALIZE_IDENTIFIER:
					if((spLoop < 0) || pilaLoop[spLoop]) { 
						if(buscar(identificadores, p->opr.op[0]->id.identificador)) { 
							fprintf(stdout, "\tError, redeclaración de la variable '%s'\n", p->opr.op[0]->id.identificador);
							return 0.0f;	
						} else {
							push_r(&identificadores, p->opr.op[0]->id.identificador);

							/* FIXME Si el tipo de dato es booleano, solo permitir que */
				
							/*asignarTipo(&identificadores, p->opr.op[0]->id.identificador, p->opr.op[0]->tipoDato); */
							return asignar(&identificadores, p->opr.op[0]->id.identificador, run(p->opr.op[1]));
						}
					}
					return 0.0f;

				case PAR:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						/* PENDIENTE: Paridad */
						/*return !(ex(p->opr.op[0]) & 1);*/
						return 0.0f;
					}
					return 0.0f;
				
				case PRASCII:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						switch(p->opr.op[0]->type) {
							case typeCon:
								putchar(getAscii(p->opr.op[0]->con.value));
								return 0.0f;
							case typeId:
								putchar(getAscii(sym[p->opr.op[0]->id.i]));
								return 0.0f;
							case typeVar:
								if(buscar(identificadores, p->opr.op[0]->id.identificador))	
									putchar(getAscii(getValue(identificadores, p->opr.op[0]->id.identificador)));
								else
									{
										fprintf(stderr, "Error, variable '%s' no encontrada.\n", p->opr.op[0]->id.identificador);
										return 0.0f;
									}

							case typeOpr:
								putchar(getAscii(run(p->opr.op[0])));
								return 0.0f;
							case typeCadena:
								putchar(getAscii(strlen(p->opr.op[0]->con.cadena)));
								return 0.0f;
						}
					}
					return 0.0f;

				case ACOS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return acos(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case ASIN:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return asin(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case ATAN:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return atan(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case CEIL:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return ceil(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case COS:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return cos(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case COSH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return cosh(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case EXP:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return exp(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case FLOOR:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return floor(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case LN:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(run(p->opr.op[0]) <= 0.0) {
							fprintf(stderr, "Aviso: cuando x tiende a 0 se vuelve infinito ...\n");
							return 0.0f;
						}
						return log(run(p->opr.op[0]));
					} else
						return 0.0f;
				
				case SIN:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sin(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case SINH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return sinh(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case TAN:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return tan(run(p->opr.op[0]));
					else
						return 0.0f;
				
				case TANH:
					if((spLoop < 0) || pilaLoop[spLoop]) 
						return tanh(run(p->opr.op[0]));
					else
						return 0.0f;

				/* Pila virtual */
				case PUSH:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						switch(p->opr.op[0]->type) {
							case typeCon:
								if(i_pila < STACK_SIZE) {
									pila[++i_pila] = run(p->opr.op[0]);
								} else {
									fprintf(stderr, "Error, pila llena.\n");
									return -1.0f;
								}
								/*printf("%lf\n", run(p->opr.op[0]));*/
								break;
							case typeId:
								if(i_pila < STACK_SIZE) {
									pila[++i_pila] = sym[p->opr.op[0]->id.i];
									return 0.0f;
								} else {
									fprintf(stderr, "Error, pila llena.\n");
									return -1.0f;
								}
							case typeCadena:
								if(i_pila < STACK_SIZE) {
									pila[++i_pila] = strlen(p->opr.op[0]->con.cadena);
									return 0.0f;
								} else {
									fprintf(stderr, "Error, pila llena.\n");
									return -1.0f;
								}
	
							case typeVar:
								if(i_pila < STACK_SIZE) {
									if(buscar(identificadores, p->opr.op[0]->id.identificador))	{
										pila[i_pila++] = getValue(identificadores, p->opr.op[0]->id.identificador);
										return 0.0f;
									} else {
										fprintf(stderr, "Error, variable '%s' no encontrada.\n", p->opr.op[0]->id.identificador); 
										return 0.0f;
									}
								} else {
									fprintf(stderr, "Error, pila llena.\n");
									return -1.0f;
								}
							default:			/* Cualquier otra expresión */
								if(i_pila < STACK_SIZE) {
									pila[i_pila++] = run(p->opr.op[0]);
								} else {
									fprintf(stderr, "Error, pila llena.\n");
									return -1.0f;
								}	
						}
					}
					return 0.0f;
				
				case VER_PILA:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(i_pila > 0) {
							ver_pila(i_pila);
						}
					}
						return 0.0f;
				
				case POP_EMPTY:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(i_pila > 0) {
							i_pila--;
							return pila[i_pila];
						} else {
							fprintf(stderr, "Error, pila vacía.\n");
							return -1.0f;
						}
					}
					return 0.0;

				case POP_VAR:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(i_pila > 0) {
							i_pila--;
							printf("Se busca a la variable '%c'\n", 'a' + p->opr.op[0]->id.i);
							sym[p->opr.op[0]->id.i] = pila[i_pila];
							return sym[p->opr.op[0]->id.i];
							
						} else {
							fprintf(stderr, "Error, pila vacía\n");
							return -1.0f;
						}
					}
					return 0.0f;
				
				case POP_ID:
					if((spLoop < 0) || pilaLoop[spLoop]) {
						if(i_pila > 0) {
							i_pila--;
							if(buscar(identificadores, p->opr.op[0]->id.identificador)) {
								return asignar(&identificadores, p->opr.op[0]->id.identificador, pila[i_pila]);
							} else {
								fprintf(stderr, "Error, identificador '%s' no encontrado.\n", p->opr.op[0]->id.identificador);
								return 0.0f;
							}
						} else {
							fprintf(stderr, "Error, pila vacía\n");
							return -1.0f;
						}
					}
				

				/* Arrays: */
				case DECLARE_ARRAY:
					/*printf("Se intenta declarar el array '%s', con %d elementos\n", 
						p->opr.op[0]->id.idArray, (int)ex(p->opr.op[1]));*/
					/*	create_array(&arreglos, p->opr.op[0]->id.idArray, (int)ex(p->opr.op[1]));*/
					/*printf("array(%s,%ld)\n", p->opr.op[0]->id.idArray, (long)ex(p->opr.op[1]));*/
					create_array(&arreglos, p->opr.op[0]->id.idArray, (long)run(p->opr.op[1]));
					/*ver_arreglos(arreglos);*/
					return 0.0f;

				case ARRAY_POS:
					/*printf("Dicho array tiene una longitud de %d\n", 
						getMaxSize(arreglos, p->opr.op[0]->id.idArray));*/

					if(buscarArray(arreglos, p->opr.op[0]->id.idArray) == 0) {
						fprintf(stderr, "Error, array '%s' no encontrado.\n", p->opr.op[0]->id.idArray);
						return 0.0f;
					}					
					
					if((int)run(p->opr.op[1]) >= getMaxSize(arreglos, p->opr.op[0]->id.idArray)) {
						fprintf(stderr, "Error, %d sobrepasa el tamaño del array '%s'\n",
							(int)run(p->opr.op[1]), p->opr.op[0]->id.idArray); 
						return -1.0f;
								
					}				

					double *_mierda = (double *)getElement(arreglos, p->opr.op[0]->id.idArray, (long)run(p->opr.op[1]));
					return _mierda[(int)run(p->opr.op[1])];

				case ARRAY_SIMPLE_ASIGN:
					/*printf("'%s'[%d] = %lf\n", p->opr.op[0]->id.idArray, (int)ex(p->opr.op[1]), 
						ex(p->opr.op[2]));*/
					/*asign_array(&arreglos, p->opr.op[0]->id.idArray, (unsigned)ex(p->opr.op[1]),
						ex(p->opr.op[2]));*/
					if(buscarArray(arreglos, p->opr.op[0]->id.idArray) == 0) {
						fprintf(stderr, "Error, array '%s' no encontrado.\n", p->opr.op[0]->id.idArray);
						return 0.0f;
					}					
					
					double *_mierda_2 = (double *)asign_array(&arreglos, p->opr.op[0]->id.idArray, (unsigned)run(p->opr.op[1]), 123);	
					((double *)asign_array(&arreglos, p->opr.op[0]->id.idArray, (unsigned)run(p->opr.op[1]), 123))[0] = 13;
					_mierda_2[(unsigned)run(p->opr.op[1])] = run(p->opr.op[2]);

					return 0.0f;
			}
		}
}

void swap(nodeType *p) {
	int temp = sym[p->opr.op[0]->id.i];
	sym[p->opr.op[0]->id.i] = sym[p->opr.op[1]->id.i];
	sym[p->opr.op[1]->id.i] = temp;
}

unsigned short int getAscii(long long valor) {
	/* PENDIENTE Ponerlo en forma sexy: */
	if((valor >= 0) && (valor <= 255))
		return valor;
	else
		return (valor % 255);
}

void ver_pila(short index) {
	unsigned i = 0;
	putchar('{');
	putchar('\n');
	for(i = 0; i < index; i++) {
		printf("\t%5d: %lf\n", i + 1, pila[i]);
	}
	putchar('}');
	putchar('\n');
}
