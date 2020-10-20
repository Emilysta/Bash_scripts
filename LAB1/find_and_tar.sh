#!/bin/bash
# dwukropek oznacza argument np. wartość, która jest do wpisania przy danej opcji
# jeśli wpiszemy ij: oznacza to, że opcja 'i' nie potrzebuje wpisania żadnych dodatkowych wartości.
# w tym przypadku opcja 'j' wymaga dodkowego argumentu np. liczby albo ciągu znakow, 
# aby ustawić odpowiednią wartość zmiennej w skrypcie 
while  getopts m:n:a: flaga
do
	case "$flaga" in
		m) maska=$OPTARG;;
		n) dni=$OPTARG;;
		a) plik=$OPTARG;;
	esac
done
if [ -z "$maska" ]; 
then
	if [ -z "$MASKA_FINDTAR" ]
	then
		echo "Podaj maskę: "
		read maska;
	else
		maska=$MASKA_FINDTAR;
	fi
fi

if [ -z "$dni" ] ;
then
	if [ -z "$DNI_FINDTAR" ]
	then
		echo "Podaj dni: "
		read dni;
	else
		dni=$DNI_FINDTAR;
	fi
fi

if [ -z "$file" ];
then
	if [ -z "$NAZWA_FINDTAR" ]
	then
		echo "Podaj nazwę archiwum: "
		read plik;
	else
		plik=$NAZWA_FINDTAR;
	fi
fi
tar -czf "$plik" $(find . -mtime "-$dni" -name "$maska") 
