#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

struct funciones {
	nodeType *pNodos;
	/* nombreFuncion:
		El nombre de la función, el identificador:
		function $maximo$(params) {}
	*/
	char *nombreFuncion;
	/* Puntero al siguiente elemento: */
	struct funciones *sig;
	/* La cantidad de argumentos de cada función */
	size_t n_arguments;
};

struct funciones *new_fun(void) {
    return malloc(sizeof(struct funciones));
}

void push_l_funcion(struct funciones **inicio, char *nombreFuncion, nodeType *pFun) {
    struct funciones *nuevo = new_fun();
    
	nuevo->nombreFuncion = malloc(strlen(nombreFuncion) + 1);
    strcpy(nuevo->nombreFuncion, nombreFuncion);
	
	nuevo->pNodos = malloc(sizeof(*pFun));
	nuevo->pNodos = pFun;

    nuevo->sig = *inicio;
    *inicio = nuevo;
}

size_t modifyArgs(struct funciones **inicio, char *s, size_t n) {
	
	struct funciones *aux = *inicio;
	while(aux != NULL) {
		if(strcmp(aux->nombreFuncion, s) == 0) {
			aux->n_arguments = n;
			return n;
		}
		aux = aux->sig;
	}
	return 0;
}

int isEmptyFunction(struct funciones *inicio) {
    return (inicio == NULL);
}

short int buscarFuncion(struct funciones *inicio, char *s) {
    struct funciones *aux = inicio;
    while(aux != NULL) {
        if(strcmp(aux->nombreFuncion, s) == 0)
            return 1;
		aux = aux->sig;
    }
    return 0;
}

void pop_l_fun(struct funciones **inicio) {
    struct funciones *nuevo = new_fun();
    nuevo = *inicio;
    *inicio = (*inicio)->sig;
	free(nuevo->nombreFuncion);
	free(nuevo->pNodos);
    free(nuevo);
}

void liberarFunciones(struct funciones **inicio) {
    /* Primero checar que la pila no esté vacía */
    if(isEmptyFunction(*inicio))
        return;
    /* Si no está vacía, utilizar un método para eliminar cada nodo */
    /* Eliminamos por la izquierda todos los nodos */
    while(!isEmptyFunction(*inicio))
        pop_l_fun(&*inicio);
}

nodeType *getValueFunction(struct funciones *inicio, char *s) {
    struct funciones *aux = inicio;

    while(aux != NULL) {
        if(strcmp(aux->nombreFuncion, s) == 0)
            return aux->pNodos;
        aux = aux->sig;
    }
    return NULL;
}

#endif
