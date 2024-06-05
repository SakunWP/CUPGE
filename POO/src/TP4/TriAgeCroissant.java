package TP4;


import java.util.Comparator;

public class TriAgeCroissant implements Comparator<Personne> {
    /**
     * Compare l'âge des deux personnes
     *
     * @param o1 référence de la première personne
     * @param o2 référence de la seconde personne
     * @return négatif si o1 est plus jeune, positif si plus âgé,
     * 0 si égalité
     */
    @Override
    public int compare(Personne o1, Personne o2) {
        return (o2.getAge()) - (o1.getAge());
    }
}