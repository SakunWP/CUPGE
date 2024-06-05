#! /bin/sh

if [ $# -ne 1]
then 
	echo "usage: erreur" >&2
	exit 1
fi
if [ ! -d "$1"]
then 
	echo "erreur">&2
	exit 2
fi

for fich in "$1"/*
do
	if[ - d "$fich"]
	then
		echo "$fich"
		"$0" "$fich"
	fi
done
exit 0
	
	