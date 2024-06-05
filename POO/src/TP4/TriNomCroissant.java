package TP4;



import java.util.Comparator;

public class TriNomCroissant implements Comparator<Personne> {

    /**
     * Si les deux personnes ont le même nom, on compare les prénoms
     *
     * @param o1 référence de la première personne
     * @param o2 référence de la seconde personne
     * @return négatif si o1 est avant dans l'ordre alphabétique, positif si après,
     * 0 si même nom et prénom
     */
    @Override
    public int compare(Personne o1, Personne o2) {
        if (o1.getNom().compareTo(o2.getNom()) == 0)
            return o1.getPrenom().compareTo(o2.getPrenom());
        return (o1.getNom()).compareTo(o2.getNom());
    }
}