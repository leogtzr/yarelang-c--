rem Testing arrays in Yare
rem Leo Gtz R.

/*array(@a);

while(x < 10) {
	@a.put(rand());
	x to x + 1;
}

x = 0;

while(x < @a.size()) {
	printn(@a[x@+]);
}*/

while(x < 10) {
	push(x);
	printn(x);
	set x to x + 1;
}

puts("Size: ");
printn(stacksize);

set x to stacksize;

while(x > 0) {
	printn(pop);
	set x to stacksize;	
}

.
