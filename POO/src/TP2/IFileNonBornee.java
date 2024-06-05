package TP2;

// Version 14/05/2020


public interface IFileNonBornee {
    /**
     * ajoute un élément en queue de filesi la file n'est pas pleine
     *
     * @param e référence de l'élément à ajouter
     * @return true si ok, false sinon
     */
    public boolean add(double e);

    /**
     * enleve l'élément en tête de file si la file n'est pas vide
     *
     * @return true si ok, false sinon
     */
    public boolean remove();

    /**
     * indique si la file est vide
     *
     * @return true si ok, false sinon
     */
    public boolean isEmpty();

    /**
     * retourne le nombre d'éléments stockés dans la file
     *
     * @return taille effective de la file
     */
    public int size();

    /**
     * retourne la référence de l'élément en tête de file si la file n'est pas vide,
     * sans l'enlever de la file
     *
     * @return référence de l'élément en tête de file
     * @throws
     */
    public double get();
}
