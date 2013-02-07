# Construcción del número pi:
:suma: = 0x0;
i = 1;
while(i <= 1000000) {
	:suma: += (-1)^(i + 1)/(2 * i - 1);
	i@+;
}
:suma: *= 4;
puts("pi = ");
printn(:suma:);
.
