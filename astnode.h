// Leo Gutiérrez Ramírez, leorocko13@hotmail.com

#ifndef ASTNODE_H_INCLUDED
#define ASTNODE_H_INCLUDED

#include "Variables.h"
#include "Arrays.h"
#include "Pila.hh"
#include "procs.h"

typedef enum { 
	typeCon, 
	typeId,			// Variable virtual a...z 
	typeVar, 		// Variable definida por el usuario :id: 
	typeArray,		// Tipo arreglo
	typeOpr, 
	typeCadena,
	typeCall
} nodeEnumType;

// constants
typedef struct {
	nodeEnumType type;		/* type of node */
	long double value;			/* value of constant */
	char cadena[1000];			/* value of constat string */
} conNodeType;

// identifiers
typedef struct {
	nodeEnumType type;		/* type of node */
	
	char i;
	/* FIXME Por ahora solo identificadores de no menos de 100 id's */
	char idArray[100];
	char identificador[100];
} idNodeType;

// operators 
typedef struct {
	nodeEnumType type;		/* type of node */
	int oper;			/* operator */
	short nops;			/* number of operands */
	union nodeTypeTag *op[5];	/* operands (expandable) */
} oprNodeType;

typedef union nodeTypeTag {
	nodeEnumType type;			/* type of node */
	conNodeType con;		/* constants */
	idNodeType id;			/* identifiers */
	oprNodeType opr;		/* operators */
} nodeType;

extern long double sym[26];
extern char opVar[4];
/*extern struct palabras *identificadores;*/
extern struct proc *procs;
extern struct cadenas *writeStrings;
extern struct _arrays *arreglos;
extern double val_temp;
// Gigantes: /
extern struct gigante *gigantes;
// Variables definidas por el usuario:
extern Variables *vars;
// Pila virtusal: 
extern Pila *pila;
// Arrays:
extern Arrays *arrays;

#endif
