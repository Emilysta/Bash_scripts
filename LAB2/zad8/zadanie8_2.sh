#!/bin/bash

ulimit -u 300
./zadanie8.sh &

echo "Liczba procesow:" $(ps -e | wc -l)
echo "Czekam"
sleep 1 
echo "Liczba procesow:" $(ps -e | wc -l)
echo "Czekam"
sleep 2
echo "Liczba procesow:" $(ps -e | wc -l)
echo "Opanowanie sytuacji - zabijam wszystkie utworzone procesy"
pkill -f "zadanie8.sh"
sleep 3
echo "Koncze prace"


