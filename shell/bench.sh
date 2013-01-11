#!/usr/bin/env bash

if [ -f "timeperl.txt" ]; then
	:> "timeperl.txt"
fi

:> "timeperl.txt"

iteraciones=1000
for((i = 0; i <= ${iteraciones}; i++)); do
	(time ./pl.pl) 2>&1 | grep -E "^real" | awk '{print $2}' | tr -d 's' |
	sed "s/^0m\(.*\)$/\1/" | 
	tee -a "timeperl.txt" 
done

result=$(cat timeperl.txt | awk '{suma += $1} END {print suma}')
echo -e "Resultado Perl: ${result}";
echo -e "Promedio: $(echo -e "${result}/${iteraciones}" | bc -l)";

