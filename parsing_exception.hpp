/**
   Excepci�n que maneja errores.
*/
#ifndef _PARSING_EXCEPTION_H
#define _PARSING_EXCEPTION_H

#include <cstdio>
/**
	La siguiente enumeraci�n guarda los posibles errores que
	se pueden generar en el an�lisis y evaluaci�n de una expresi�n */
enum Errores {
    ERROR_SINTAXIS_PARTE = 1,
    ERROR_SINTAXIS = 2,
    PARENTESIS_FALTANTE = 3,
    EXPRESION_VACIA = 4,
    PARTE_NO_ESPERADA = 5,
    FIN_INESPERADO_EXPRESION = 6,
    VALOR_ESPERADO = 7,
    OPERADOR_DESCONOCIDO = 101,
    FUNCION_DESCONOCIDA = 102,
    VARIABLE_DESCONOCIDA = 103,
    EXPRESION_DEMASIADA_LARGA = 200,
    DEFINICION_DE_VARIABLE_FALLIDA = 300,
    VALOR_ENTERO_ESPERADO_EN_FUNCION = 400,
    COMA_FALTANTE = 500,
    IDENTIFICADOR_COMO_PALABRA_RESERVADA = 600,
	ASIGNACION_DE_CONSTANTE = 605,
	FUERA_DOMINIO = 700,
	ERROR_LEYENDO_VAR_FILE = 701,
	DIVISION_POR_CERO = 702
};

class ParsingException {

    public:
		/* Constructores sobrecargados: */
        ParsingException(/*const int row, */const int col, int id = 2, ... ) {
            /* Basado en el id obtenemos un string que nos servir� para pasarlo
                al formato que necesita el vsnprintf */
			this->err_col = col;
			this->err_id = id;
			const char* msg_desc = msgdesc(id);
			va_list args;
			va_start(args, id);
			vsnprintf(msg, sizeof(msg) - 1, msg_desc, args);
            msg[sizeof(msg) - 1] = '\0';
            va_end(args);
        }

        inline int get_col(void) const {
            return err_col;         // Returns the column of the error
        }

        inline int get_id(void) const {
            return err_id;          // Returns the id of the error
        }

        inline char* get_msg(void) {
            return msg;             // Returns a pointer to the error msg
        }

    private:
        // El rengl�n donde fue encontrado el error:
        // int err_row;
        // La columna (position) donde fue encontrado el error:
        int err_col;
        // El identificador del error:
        int err_id;
        // El mensaje de error:
        char msg[255];
        // La descripci�n del error:
        const char* msgdesc(const int error_id) {
            switch (error_id) {
                // syntax errors
                case ERROR_SINTAXIS_PARTE:
                    return "Error de sintaxis en \"%s\"";

                case ERROR_SINTAXIS:
                    return "syntax error";

                case PARENTESIS_FALTANTE:
                    return "')' expected";

                case EXPRESION_VACIA:
                    return "Empty expression";

				case PARTE_NO_ESPERADA:
					return "unexpected expression \"%s\"";

				case FIN_INESPERADO_EXPRESION:
					return "expected expression";

				case VALOR_ESPERADO:
					return "value expected";

                case OPERADOR_DESCONOCIDO:
                    return "wrong operator %s";

                case FUNCION_DESCONOCIDA:
                    return "unknown function %s";

                case VARIABLE_DESCONOCIDA:
                    return "unknown variable %s";

                case EXPRESION_DEMASIADA_LARGA:
					return "expression too long";

                case DEFINICION_DE_VARIABLE_FALLIDA:
                    return "Defining variable failed";

				case VALOR_ENTERO_ESPERADO_EN_FUNCION:
                    return "Integer value expected in function %s";

                case IDENTIFICADOR_COMO_PALABRA_RESERVADA:
                    return "reserved word used as identifier '%s'";

                case ASIGNACION_DE_CONSTANTE:
					 return "cannot assign a value to const variable '%s' ";

				case FUERA_DOMINIO:
					return "out of domain for function";

				case ERROR_LEYENDO_VAR_FILE:
					return "Leyendo archivo de variables.";

				case DIVISION_POR_CERO:
                	return "/ by zero";
			}
            return "unknown error";
        }
};

#endif

