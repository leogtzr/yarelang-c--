#!/usr/bin/env bash

if [ -f "timeyare.txt" ]; then
	:> "timeyare.txt"
fi

:> "timeyare.txt"

iteraciones=1000
for((i = 0; i <= ${iteraciones}; i++)); do
	(time ./yare < ./file.yar) 2>&1 | grep -E "^real" | awk '{print $2}' | tr -d 's' |
	sed "s/^0m\(.*\)$/\1/" | 
	tee -a "timeyare.txt" 
done

result=$(cat timeyare.txt | awk '{suma += $1} END {print suma}')
echo -e "Resultado Yare: ${result}";
echo -e "Promedio: $(echo -e "${result}/${iteraciones}" | bc -l)";

