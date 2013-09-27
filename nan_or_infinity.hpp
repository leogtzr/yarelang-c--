#ifndef NANORINFINITY_H
#define NANORINFINITY_H

#include <exception>
/**
 * Excepción que es lanzada cuando se da un resultado de NAN o Infinito.
 */
 /* NAN significa Not a Number.
	Valores NAN son usados para identificar elementos de punto flotante
	que están indefinidos o que no son representables, por ejemplo la raíz
	de un número negativo, o 0/0 */
class NanOrInfinity : public std::exception {

        public:

			/* Constructores: */
			NanOrInfinity(const char* mensaje) : mensaje(mensaje) {}

            NanOrInfinity(const char* mensaje, double wrongNumber) :
                mensaje(mensaje),
                wrongNumber(wrongNumber) {
			}

			/* Getters: */
            inline const char* what() const throw () {
				return mensaje;
			}
			inline const double getWrongNumber(void) const {
                return wrongNumber;
            }

		private:

            const char* mensaje;
            double wrongNumber;
};

#endif

