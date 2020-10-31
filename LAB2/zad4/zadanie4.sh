#!/bin/bash

mknod potok p

gnome-terminal -e "./zadanie4_2.sh &" --window-with-profile=new
gnome-terminal -e "./zadanie4_3.sh &" --window-with-profile=new
gnome-terminal -e "cat potok &" --window-with-profile=new
gnome-terminal -e "cat potok &" --window-with-profile=new
cat > potok
