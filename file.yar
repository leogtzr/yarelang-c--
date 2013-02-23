rem Testing arrays in Yare
rem Leo Gtz R.

array(@a);

while(x < 10) {
	@a.put(rand());
	x to x + 1;
}

x = 0;

while(x < @a.size()) {
	printn(@a[x@+]);
}

.
