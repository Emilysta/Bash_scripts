#!/bin/bash

nice -n 5 ./zadanie7.sh &

numerPid=$!;
ps -l | grep "NI"
ps -lu emilia | grep "zadanie7.sh"
sleep 10
renice 10 $numerPid
echo "zmiana liczby nice na 10 dla wykonujacego sie skryptu"
ps -l | grep "NI"
ps -lu emilia | grep "zadanie7.sh"
sleep 10
kill -9 $numerPid
#aby pokzac dzialanie liczby nice musielibysmy doprowadzic do sytuacji kiedy nasz procesor
# jest ogromnie zajety
# np uruchomic licznik czasu przy wykonywaniu jakiegos ogromnego procesu i zobaczyc czas bez edycji nice
# i potem uruchomic ze zmieniona liczba nice i zobaczyć jaki jest czas wykonania takiego procesu

