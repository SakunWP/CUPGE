#!/bin/sh

#! /bin/sh

if [ $# -ne 1]
then 
	echo "usage: erreur" >&2
	exit 1
fi
if [ ! -d "$1" ]
then 
	echo "erreur">&2
	exit 2
fi


	