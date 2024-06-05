#!/bin/bash

# Créer un répertoire temporaire
mkdir REP

# Créer un fichier liste.txt contenant la liste des noms de fichiers .txt et .sh du répertoire courant
ls | grep -E '\.txt$|\.sh$' > liste.txt

# Recopier le fichier correspondant au dernier nom de la liste dans REP
last_file=$(tail -n 1 liste.txt)
cp "$last_file" "$REP"

# Effacer le fichier liste.txt
rm liste.txt
