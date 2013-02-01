#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <cmath>

// Constants number:
#define N_CONST     9

struct constantes {
    const char *const_str;
    double value;
// TODO Pueden agregarse más constantes, lo único que hay que hacer es
// modificarse la constante simbólica (N_CONST) por el número
// de constantes en la estructura */
} consts[] = {
    {"pi", M_PI},
    {"e", M_E},
    {"log2e", M_LOG2E},
    {"log10e", M_LOG10E},
    {"ln2", M_LN2},
    {"ln10", M_LN10},
    {"sqrt2", M_SQRT2},
    {"sqrt3", 1.732050807568877293527446341505},
    {"sqrt5", 2.236067977499789696409173668731}
};

#endif
