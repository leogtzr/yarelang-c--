#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <limits>
#include "NanOrInfinity.h"
#include "ParsingException.h"
#include <cstdlib>
#include <ctime>

namespace MathFunctions {

	template<typename T>
	inline bool isinf(T value) {
		return value == std::numeric_limits<T>::infinity();
    }

    inline bool is_infinite(double x) {
        double y = x - x;
        return x == x && y != y;
    }

	inline bool isNan(double z) {
		return z != z;
    }

	/*
	 * Calcular el factorial de un número:
	 */
	double factorial(double value) {

		double res;
		int v = static_cast<int>(value);

		if (value != static_cast<double>(v) || (value < 0.0)) {
			throw ParsingException(-1, VALOR_ENTERO_ESPERADO_EN_FUNCION, "factorial");
		}

		res = v;
    	v--;
		while (v > 1) {
			res *= v;
			v--;
		}

		if (res == 0)
			res = 1.0;        // 0! is per definition 1
		return res;
	}

	inline double log_expr(double x) throw (NanOrInfinity) {

		long double result = log(x);
		if (!isinf(result) && !isNan(result) && !is_infinite(result)) {
				return result;
		} else {
			throw NanOrInfinity("Número fuera de dominio", x);
		}
	}

	inline long double math_acot(double x) {
		return ((M_PI / 2.0) - abs(atan(x)));
	}

	inline long double math_acosh(double x) throw(NanOrInfinity) {

		if(x >= 1.0) {
			long double result = log(x + sqrt((x * x) - 1.0));
			if (!isinf(result) && !isNan(result) && !is_infinite(result)) {
				return result;
			} else {
				throw NanOrInfinity("Fuera de dominio.", x);
			}
		} else {
			throw NanOrInfinity("Fuera de dominio.", x);
		}
	}
	/**
	   Calcula el signo de un valor dado */
	inline double sign(double value) {

		if (value > 0)
			return 1;
		if (value < 0)
			return -1;
		return 0;
	}

	inline double raiz(double x) throw (NanOrInfinity) {

        long double result = sqrt(x);
		if (!isinf(result) && !isNan(result) && !is_infinite(result)) {
			return result;
		} else {
			throw NanOrInfinity("Número fuera de dominio", x);
		}
	}

	inline long double math_acos(double x) throw (NanOrInfinity) {

		if(x >= -1.0 && x <= 1.0) {
			long double result = acos(x);
			if (!isinf(result) && !isNan(result) && !is_infinite(result)) {
				return result;
			} else {
				throw NanOrInfinity("Fuera de dominio para la función 'acos'", x);
			}
		} else {
			throw NanOrInfinity("Fuera de dominio para la función 'acos'", x);
		}
	}

	inline long double math_asech(double x) throw(NanOrInfinity) {

		if(fabs(x) < 0.00000000000001) {
			throw NanOrInfinity("Fuera de rango.", x);
		}
		if(x < 0.0) {
			throw NanOrInfinity("Fuera de rango.", x);
		}
		if(x < 0.00000000000001) {
			throw NanOrInfinity("Fuera de rango.", x);
		}

		return math_acosh(1.0 / x);
	}

	inline long double math_atan(double x) {

		if(fabs(x - 0.0) < std::numeric_limits<double>::epsilon()) {
			return 0.0;
		}
		return atan(x);
	}

	inline long double math_asinh(double x) {

		if(fabs(x - 0.0) < std::numeric_limits<double>::epsilon()) {
            return 0.0;
        }
		return log(x + sqrt((x * x) + 1.0));
	}

	inline long double math_atanh(double x) throw (NanOrInfinity) {

		if(fabs(x - 0.0) < std::numeric_limits<double>::epsilon()) {
			return 0.0;
		}
		
		if(fabs(x) >= 1.0) {
            throw NanOrInfinity("Fuera de dominio.", x);
		}
		long double y = (1.0 / 2.0) * log((1.0 + x) / (1.0 - x));
		if (!isinf(y) && !isNan(y) && !is_infinite(y)) {
            return y;
		} else {
            throw NanOrInfinity("Fuera de dominio.", x);
        }
	}

	inline long double math_acoth(double x) throw (NanOrInfinity) {

		if(abs(x) < 1.0) {
			throw NanOrInfinity("Fuera de dominio para la función 'acoth'", x);
		}
		return 0.5 * (log((x + 1.0)/x) - log((x - 1.0)/x));
	}

	inline double math_asin(double x) throw (NanOrInfinity) {

		/// XXX Warning.
		if(fabs(x - 0.0) < std::numeric_limits<double>::epsilon()) {
			return 0.0L;
		}
		if(x < -1.0 || x > 1.0) {
			throw NanOrInfinity("Fuera de dominio para la función 'asinh'", x);
		}

		long double result = asin(x);
		if (!isinf(result) && !isNan(result) && !is_infinite(result)) {
			return result;
		} else {
			throw NanOrInfinity("Número fuera de dominio", x);
		}
	}

	inline long double math_acsc(double x) throw (NanOrInfinity) {

		if(x <= 1.0 && x >= 1.0) {
			throw NanOrInfinity("Fuera de dominio para la función 'acoth'", x);
		}
		return math_asin(1.0 / x);
	}

	inline long double math_acsch(double x) throw (NanOrInfinity) {
		  //if(x != 0.0) {
		  //	return _asinh(1.0 / x);
		  //} else {
		  //  throw NanOrInfinity("Fuera de dominio para la función 'acsch'", x);
		  //}
			//if(x != 1.52656E-15)

		  //if(fabs(x) < 0.00000000000001) {
			/// XXX Warning.
		  if(fabs(x - 0.0) < std::numeric_limits<double>::epsilon()) {
			throw NanOrInfinity("Fuera de dominio.", x);
          }
		  return log(sqrt(1.0 + (1.0/(x * x))) + (1.0/x));
			//else
            //	throw NanOrInfinity("Fuera de dominio para la función 'acsch'", x);
	}

	inline long double math_asec(double x) throw(NanOrInfinity) {

		/*if(x >= -1.0 && x >= 1.0) {
			throw NanOrInfinity("Fura de dominio para la función 'asec'", x);
        }*/
		//return math_acos(1.0 / x);
		long double y = acos(1.0 / x);
		if (!isinf(y) && !isNan(y) && !is_infinite(y)) {
			return y;
		} else {
            throw NanOrInfinity("Valiendo asec", x);
        }
    	return y;
	}

	inline long double math_cot(double x) {

		long double result = 0.0;

		try {

			double b = (cos(2 * x) - 1.0);

			if(b == 0.0) {
				throw NanOrInfinity("Fuera de rango.", x);
			} else {

			}
			result = -(sin(2 * x)/b);
			return result;

		} catch (...) {
			throw NanOrInfinity("Fuera de rango.", x);
		}
	}

	inline long double math_coth(double x) throw (NanOrInfinity) {

    	// Código anterior, descomentar si hay problemas.
		//if(/*(x == M_PI) || (tanh(x) == 0.0) || */(fabs(x) < 0.00000000000001)) {
		// XXX Warning.
		if(fabs(x - 0.0) < std::numeric_limits<double>::epsilon()) {
			throw NanOrInfinity("Fuera de rango.", x);
		} else {
			return (1.0 / tanh(x));
		}
	}

	inline long double math_csc(double x) {
		
		 /*if(fabs(sin(x)) < 0.00000000000001) {
			 throw NanOrInfinity("Fuera de rango.", x);
		 } else {
			 return (1.0 / sin(x));
		 }*/

    	// Código anterior, descomentar si hay problemas.
		//if(fmod(fabs(x), M_PI) < 0.00000000000001) {
        // XXX Warning.
		if(fabs(fmod(fabs(x), M_PI) - 0.0) < std::numeric_limits<double>::epsilon()) {
			throw NanOrInfinity("Fuera de rango.", x);
		} else {
			return (1.0 / sin(x));
		}
	}

	inline long double math_csch(double x) {
		
		  // Código anterior, descomentar si hay problemas.
		 //if(/*(x == M_PI) || */(fabs(sinh(x)) < 0.00000000000001) || (fabs(x) < 0.00000000000001)) {
		 // XXX Warning.
		 if((fabs(sinh(x) - 0.0) < std::numeric_limits<double>::epsilon()) ||
			(fabs(x - 0.0) < std::numeric_limits<double>::epsilon())) {
			 throw NanOrInfinity("Fuera de rango.", x);
		 } else {
			 return (1.0 / sinh(x));
		 }
	}

	inline double math_log(double x) {

		if(fabs(x) < 0.0) {
            throw NanOrInfinity("Fuera de dominio.", x);
        }
		if(x > 0.0) {
			return log(x);
		} else {
            throw NanOrInfinity("Fuera de dominio.", x);
        }
	}

	inline long double math_log10(double x) {

		if(x < 0.0) {
		   throw NanOrInfinity("Fuera de rango.", x);
		} else if(x == 0.0 || fabs(x) < 0.00000000000001) {
			throw NanOrInfinity("Fuera de rango.", x);
		} else {
			return log10(x);
        }
	}

	inline long double math_log2(double x) {

		/*double intpart;
		double fract_part = modf(x, &intpart);*/
		// std::cout << "Parte fraccionaria[" << std::setprecision(15) << fract_part << "]Entero[" << intpart << "]" << std::endl;
		if(x < 0.0) {
		   throw NanOrInfinity("Fuera de rango.", x);
		} else if(x == 0.0 || fabs(x) < 0.00000000000001) {
			throw NanOrInfinity("Fuera de rango.", x);
		} else {
			return log(x) / log(2.0);
		}
	}

	inline long double math_sec(double x) {

		//return ((2.0 * cos(x)) / (cos(2.0 * x) + 1.0));
		if(fabs(cos(x)) < 0.00000000000001) {
			throw NanOrInfinity("Fuera de rango.", x);
		} else {
            return 1.0 / cos(x);
        }
	}

	inline long double math_sech(double x) {

		return ((2.0 * cosh(x)) / (cosh(2.0 * x) + 1.0));
	}

	inline long double math_sqrt(double x) {

		if(fabs(x) < 0.00000000000001) {
			return 0.0;
		}
		if(x > 0.0) {
			return sqrt(x);
		} else {
			throw NanOrInfinity("Fuera de rango.", x);
		}
	}

	inline long double math_tan(double x) {

		if(fmod(x, M_PI) == M_PI_2) {
			throw NanOrInfinity("Fuera de rango.", x);
		} else if(fabs(fmod(x, M_PI)) < 0.00000000000001) {
			return 0.0;
		} else {
            return tan(x);
        }
    }

	// Función que devuelve un número aleatorio entre 0 y 1.
	// Se hace la suposición de que ya se está randomizado.
	inline double rand_0_to_1(void) {

		return (double)rand() / (double)RAND_MAX;
	}

	inline double rand_between(double min, double max) {
		return ((double(rand()) / double(RAND_MAX)) * ((max + 1) - min)) + min;
	}

	inline int rand_int_between(int min, int max) {
		return min + (rand() % (int)(max - min + 1));
	}

    // XXX Solo para pruebas.
	inline double math_sin_test(double x) {
		double temp = sin(x);
		if(fabs(temp - 0.0) < std::numeric_limits<double>::epsilon()) {
            return 0;
        }
    	return temp;
	}

}

#endif
