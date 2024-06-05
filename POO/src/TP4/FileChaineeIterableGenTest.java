package TP4;



import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Iterator;

class FileChaineeIterableGenTest {
    FileChaineeIterableGen<Personne> fpp;

    @BeforeEach
    void setUp() {
        fpp = new FileChaineeIterableGen<>();
    }

    @AfterEach
    void tearDown() {
        fpp = null;
        System.gc();
    }

    @Test
    void iterator() {
        Personne pap;
        fpp.add(new Personne("Schmit", "Bob", 9));
        fpp.add(new Personne("Dupond", "Jean", 4));
        fpp.add(new Personne("Durand", "Georges", 8));
        fpp.add(new Personne("Schmit", "Mary", 3));
        fpp.add(new Personne("Martin", "Julie", 6));
        fpp.add(new Personne("Dupont", "Jules", 2));
        fpp.add(new Personne("Dupont", "Jojo", 7));
        fpp.add(new Personne("Martin", "Jacques", 5));
        fpp.add(new Personne("Schmit", "John", 2));
        fpp.add(new Personne("Schmit", "Angie", 1));

        System.out.println("utilisation de l'iterateur naturel (ordre d'ajout) : ");
        Iterator<Personne> it = fpp.iterator();
        while (it.hasNext()) {
            pap = it.next();
            System.out.println(pap);
        }
        System.out.println("utilisation de l'iterateur age decroissant : ");
        it = (fpp.iteratorComparator(new TriAgeCroissant()));
        while (it.hasNext()) {
            pap = it.next();
            System.out.println(pap);
        }
        System.out.println("utilisation de l'iterateur nom croissant : ");
        it = (fpp.iteratorComparator(new TriNomCroissant()));
        while (it.hasNext()) {
            pap = it.next();
            System.out.println(pap);
        }
        System.out.println("Résultat de toString : " + fpp);
    }
}