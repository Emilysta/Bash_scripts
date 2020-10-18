#!/bin/bash

tar -cvzf $3 $(find . -mtime "$2" -name "$1") > wynik_tar.txt
