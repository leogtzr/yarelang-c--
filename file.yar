rem Testing arrays in Yare
rem Leo Gtz R.

array(@a);

@a.put(1);
@a.put(2);
@a.put(3);

x to 0;

while(x < @a.size()) {
	printn(@a[x@+]);
}

puts("----------------\n");

@a.del(2);
@a.del(-1);

x to 0;

while(x < @a.size()) {
	printn(@a[x@+]);
}

.
