#!/bin/bash
tresc_plik="tresc.txt";
adres="adresy.txt";
while read line; do
tresc+=$line;
done < $tresc_plik
zip zalaczniki.zip $(find . -name "spec*.pdf");
while read line; do
	echo "$tresc" | mail -s "Zapytanie do Panstwa firmy" -A zalaczniki.zip $line;
done < $adres

