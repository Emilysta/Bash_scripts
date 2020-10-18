#!/bin/bash

day_number=$(LC_ALL=C date +'%u');
if [ $day_number -ne 6 -a $day_number -ne 7 ];
then
echo " Zapowiada sie pracowity dzien ";
else
echo " Milego weekendu"; 
fi
