#!/bin/sh

if [ $# -ne 1 ] && [ $# -ne 2 ]
then
	echo "Erreur : inverse.sh $1 $2"
else
	if [ $# -eq 2 ]
	then
		if [ -f "$1" -a -f "$2" ]
		then
			cat $1 > $2
		else
			echo "Erreur : les deux paramètres doivent être des fichiers existants"
		fi
	else
		echo "un seul paramètre"
		nblignes= `wc -l $1`
		echo $nblignes
		while [ $nblignes -ne 0]
		do
			nblignes=`expr $nblignes -1`
			echo $nblignes
		done
	fi
fi

