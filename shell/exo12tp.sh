#!/bin/bash

# Vérification des arguments
if [[ $# -ne 3 ]]; then
    echo "Usage: $0 f_anglais.txt dico.txt f_français.txt"
    exit 1
fi


f_anglais=$1
dico=$2
f_francais=$3


declare -A dict
while read -r line; do
    key=${line%% *}   
    value=${line#* }  
    dict[$key]=$value
done < $dico


while read -r line; do
    words=($line)  
    for word in "${words[@]}"; do
        if [[ -n ${dict[$word]} ]]; then  
            printf "%s " "${dict[$word]}" >> $f_francais  
        else
            printf "%s " "$word" >> $f_francais 
        fi
    done
    printf "\n" >> $f_francais  
done < $f_anglais

echo "Traduction terminée."


