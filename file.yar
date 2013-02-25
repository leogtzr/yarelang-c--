rem Testing arrays in Yare
rem Leo Gtz R.

array(@a);

@a.put(8);
@a.put(-1);
@a.put(45);
@a.put(-45);

x to 0;
while(x < @a.size) {
	printn(@a[x@+]);
}

@a.putfront(1 + 2 * 3);

putsn("--------------------");

x to 0;
while(x < @a.size) {
	printn(@a[x@+]);
}

.
