#ifndef MY_MATH_H
#define MY_MATH_H

/* mymath.h 
	Contiene algunas funciones matemáticas importantes que se utilizarán
	en el intérprete 
*/

unsigned long long factorial(short n) {
    if(n <= 1)
        return 1;
    unsigned long long r = 1;
    unsigned short i;
    for(i = 1; i <= n; i++)
        r *= i;
    return r;
}

unsigned long long sumatoria(int start, int end) {
	unsigned long r = 0;
	unsigned i;
	for(i = start; i <= end; i++)
		r += i;	
	return r;
}

#endif
