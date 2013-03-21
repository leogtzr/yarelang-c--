# El resultado del factorial es almacenado en la variable global r
proc $factorial$ {
	if(a mayor 1) {
		r *= a;
		a@-;
		call $factorial$;
    }
}

r = 1;
a = 5;

call $factorial$;
puts("Factorial de 5!: ");
printn(r);

.