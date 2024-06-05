#!/bin/bash

# Récupération de la date courante
date=$(date -R)

# Conversion de la date en français
case $date in
  *Mon*) jour="Lundi" ;;
  *Tue*) jour="Mardi" ;;
  *Wed*) jour="Mercredi" ;;
  *Thu*) jour="Jeudi" ;;
  *Fri*) jour="Vendredi" ;;
  *Sat*) jour="Samedi" ;;
  *Sun*) jour="Dimanche" ;;
esac

mois=$(echo $date | cut -d ' ' -f 3)

case $mois in
  Jan) mois="Janvier" ;;
  Feb) mois="Février" ;;
  Mar) mois="Mars" ;;
  Apr) mois="Avril" ;;
  May) mois="Mai" ;;
  Jun) mois="Juin" ;;
  Jul) mois="Juillet" ;;
  Aug) mois="Août" ;;
  Sep) mois="Septembre" ;;
  Oct) mois="Octobre" ;;
  Nov) mois="Novembre" ;;
  Dec) mois="Décembre" ;;
esac

annee=$(echo $date | cut -d ' ' -f 4)
heure=$(echo $date | cut -d ' ' -f 5)

# Affichage de la date convertie
echo "$jour $(echo $date | cut -d ' ' -f 2) $mois $annee $heure"
