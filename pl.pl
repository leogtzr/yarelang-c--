#!/usr/bin/env perl
my $suma = 0.0;
my $i = 1;
while($i <= 1000000) {
        $suma += (-1)**($i + 1)/(2 * $i - 1);
        $i++;
}
$suma *= 4.0;
print($suma . "\n");
