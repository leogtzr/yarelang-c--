#ifndef _PROCEDURES_H
#define _PROCEDURES_H

#include <cstring>
#include <cstdlib>

struct proc {
	union nodeTypeTag *pNodos;
	/* nombreProc: El nombre del procedimiento, el identificador: proc $maximo$(params) {}*/
	char *nombreProc;
	/* Puntero al siguiente elemento: */
	struct proc *sig;
	/* La cantidad de argumentos de cada procedimiento */
	size_t n_arguments;
};

struct proc *new_proc(void) {
    return (struct proc *)malloc(sizeof(struct proc));
}

void push_l_proc(struct proc **inicio, char *nombreProc, union nodeTypeTag *pProc) {
    struct proc *nuevo = new_proc();

	nuevo->nombreProc = (char *)malloc(strlen(nombreProc) + 1);
    strcpy(nuevo->nombreProc, nombreProc);
	//nuevo->pNodos = malloc(sizeof(union *pFun));
	nuevo->pNodos = pProc;
    nuevo->sig = *inicio;
    *inicio = nuevo;
}

size_t modifyArgs(struct proc **inicio, char *s, size_t n) {

	struct proc *aux = *inicio;
	while(aux != NULL) {
		if(strcmp(aux->nombreProc, s) == 0) {
			aux->n_arguments = n;
			return n;
		}
		aux = aux->sig;
	}
	return 0;
}

int isEmptyProc(struct proc *inicio) {
    return (inicio == NULL);
}

short int buscarProc(struct proc *inicio, char *s) {
    struct proc *aux = inicio;
    while(aux != NULL) {
        if(strcmp(aux->nombreProc, s) == 0)
            return 1;
		aux = aux->sig;
    }
    return 0;
}

void pop_l_proc(struct proc **inicio) {
    struct proc *nuevo = new_proc();
    nuevo = *inicio;
    *inicio = (*inicio)->sig;
	free(nuevo->nombreProc);
	free(nuevo->pNodos);
    free(nuevo);
}

void liberarProcs(struct proc **inicio) {
    /* Primero checar que la pila no esté vacía */
    if(isEmptyProc(*inicio))
        return;
    /* Si no está vacía, utilizar un método para eliminar cada nodo */
    /* Eliminamos por la izquierda todos los nodos */
    while(!isEmptyProc(*inicio))
        pop_l_proc(&*inicio);
}

nodeTypeTag *getValueProc(struct proc *inicio, char *s) {
    struct proc *aux = inicio;

    while(aux != NULL) {
        if(strcmp(aux->nombreProc, s) == 0)
            return aux->pNodos;
        aux = aux->sig;
    }
    return NULL;
}

#endif
