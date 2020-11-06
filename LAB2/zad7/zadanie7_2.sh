#!/bin/bash

nice -n 5 ./zadanie7.sh &
numerPid=$!;
nice -n 5 ./zadanie7.sh &
numerPid2=$!;
nice -n 5 ./zadanie7.sh &
numerPid3=$!;
nice -n 5 ./zadanie7.sh &
numerPid4=$!;

sleep 5
ps u $numerPid
ps u $numerPid2
ps u $numerPid3
ps u $numerPid4

sleep 5
renice 19 $numerPid
renice 19 $numerPid3

echo "zmiana liczby nice na 19 dla wykonujacych sie 2 skryptow i zmiana liczby zasobów"
sleep 10
ps u $numerPid
ps u $numerPid2
ps u $numerPid3
ps u $numerPid4

sleep 5
killall zadanie7.sh
# aby pokzac dzialanie liczby nice doprowadzam do sytuacji kiedy nasz procesor
# i jego rdzenie są zajęte w 100%, uruchamiam 4 takie same skrypty, które wypisują w nieskończoność tekst do pliku
# nastepnie zmieniam wartosc liczby nice dla dwóch z nich - na osobnych rdzeniach(sprawdzenie przez htop
# potem wyswietlam zuzycie procesora po zmianie
# mozna zobaczyc zmiane w proporcjach przyznania zasobow
# jak wcześniej procesy dostawały, każdy jednakowo po 50 % rdzenia, tak teraz te proporcje są zminione,
# procesy ze zmieniona liczba nice dostaja mniejsze zasoby
# a tym drugim przyznaje sie większe 
# uruchomienie z zadanym priorytetem: nice -n liczba nazwa_procesu
# zmiana priorytetu: renice liczba numerPID_procesu
# liczba ujemna jest dozwolona tylko dla użytkownika root, ponieważ 
# zwykły użytkownik nie może podwyższać priorytetu 
