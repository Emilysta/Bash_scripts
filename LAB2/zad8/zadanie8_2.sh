#!/bin/bash

echo $$
sleep 5
ulimit -u 400
nice -n 19 ./zadanie8.sh &
liczba=$(ps -e | wc -l)
echo Liczba procesow $liczba
echo "Czekam"
sleep 0.5
liczba=$(ps -e | wc -l)
echo Liczba procesow $liczba
echo "Czekam"
sleep 0.5
liczba=$(ps -e | wc -l)
echo Liczba procesow $liczba
echo "Opanowanie sytuacji - zabijam wszystkie utworzone procesy"
pkill -9 -f zadanie8.sh
echo "Koncze prace"
