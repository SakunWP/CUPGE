#!/bin/sh

while [ $# -gt 0 ]
do
    if [ -f "$1" ] && [ -r "$1" ]
    then
        echo "Contenu de $1 :"
        cat "$1"
    else
        echo "$1 inaccessible"
    fi
    shift
done
