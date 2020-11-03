#!/bin/bash
echo $$
sleep 5
ulimit -u 400
nice -n 19 ./zadanie8.sh &

echo Liczba procesow $(ps -u emilia | wc -l)
sleep 0.5
echo Liczba procesow $(ps -u emilia | wc -l)
sleep 0.5
echo Liczba procesow $(ps -u emilia | wc -l)
echo "Opanowanie sytuacji - zabijam wszystkie utworzone procesy"
pkill -9 -f "zadanie8.sh"

