#!/bin/bash

while  getopts m:n:a: flag
do
	case "$flag" in
		m) maska=$OPTARG;;
		n) dni=$OPTARG;;
		a) file=$OPTARG;;
	esac
done
if [ -z "$maska" ]; 
then
	if [ -z "$MASKA_PLIKU" ]
	then
		echo "Podaj maskę: "
		read maska;
	else
		maska=$MASKA_PLIKU;
	fi
fi

if [ -z "$dni" ] ;
then
	if [ -z "$DNI_MODYFIKACJI" ]
	then
		echo "Podaj dni: "
		read dni;
	else
		dni=$DNI_MODYFIKACJI;
	fi
fi

if [ -z "$file" ];
then
	if [ -z "$TAR_FILE" ]
	then
		echo "Podaj nazwę tar: "
		read file;
	else
		file=$TAR_FILE;
	fi
fi
tar -czf $file $(find . -mtime "-$dni" -name "$maska") 
