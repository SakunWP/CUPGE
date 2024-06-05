package TP4;


import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;

public class FileChaineeIterableGen<E extends Comparable<E>> extends FileChaineeGen<E> implements Iterable<E> {
    /**
     * constructeur
     */
    public FileChaineeIterableGen() {
        super();
    }

    /**
     * crée une nouvelle instance d'itérateur, permettant au client e parcourir
     * les données de la file dans son ordre naturel (du premier au dernier élément)
     *
     * @return itérateur permettant de parcourir la file
     */
    @Override
    public Iterator<E> iterator() {
        return new FileIterator();
    }

    /**
     * inner class mettant en oeuvre un iterateur "ordre naturel"
     */
    protected class FileIterator implements Iterator<E> {
        /**
         * instantané des données de la file
         */
        ArrayList<E> dataIterator;
        /**
         * index courant du parcours des données
         */
        int index = 0;

        /**
         * constructeur de l'inner class, crée et remplit dataIterator
         * dans l'ordre naturel de parcours, du premier au dernier
         */
        protected FileIterator() {
            this.dataIterator = new ArrayList<>();
            Cellule courant = premier;
            while(courant!=null){
                dataIterator.add(courant.valeur);
                courant= courant.suivant;
            }
        }

        /**
         * @return true s'il reste des éléments à parcourir, false sinon
         */
        @Override
        public boolean hasNext() {
            if (this.index<this.dataIterator.size()){
                return true;
            } else{
                return false;
            }
        }

        /**
         * Positionne l'index sur le suivant et retourne l'élément courant
         *
         * @return l'élément courant
         */
        @Override
        public E next() {
            assert(hasNext());
            E elem= dataIterator.get(index);
            index++;
            return elem;
        }
    }

    /**
     * Retourne un itérateur pour parcourir les données dans un ordre défini par un
     * Comparator sans modifier l'ordre de la liste de départ
     *
     * @param comp instance de Comparator utilisé pour trier les données
     * @return iterator de données
     */
    public Iterator<E> iteratorComparator(Comparator<E> comp) {
        return new IteratorComparator(comp);
    }

    /**
     * inner classe pour mettre en oeuvre un itérateur basé sur un comparateur
     */
    protected class IteratorComparator implements Iterator<E> {
        /**
         * instantané des données de la file selon le comparateur
         */
        protected ArrayList<E> instantData;
        /**
         * index courant du parcours des données
         */
        protected int index;

        /**
         * Constructeur avec choix du type de parcours au moment de la création
         * de l'itérateur
         *
         * @param comp référence du type de parcours
         */
        protected IteratorComparator(Comparator<E> comp) {
            instantData= new ArrayList<>();
            Cellule elemCourant= premier;
            while(elemCourant!=null){
                instantData.add(elemCourant.valeur);
                elemCourant= elemCourant.suivant;
            }
            instantData.sort(comp);
        }

        /**
         * @return true s'il reste des éléments à parcourir, false sinon
         */
        @Override
        public boolean hasNext() {
            if (this.index<this.instantData.size()){
                return true;
            } else{
                return false;
            }
        }

        /**
         * Positionne l'index sur le suivant et retourne l'élément courant
         *
         * @return l'élément courant
         */
        @Override
        public E next() {
            assert(hasNext());
            E elem= instantData.get(index);
            index++;
            return elem;
        }
    }
}