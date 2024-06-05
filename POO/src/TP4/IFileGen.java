package TP4;


public interface IFileGen<E> {
    /**
     * ajoute un élément en queue de filesi la file n'est pas pleine
     *
     * @param e référence de l'élément à ajouter
     * @throws RuntimeException exception levée si la file est pleine
     */
    public boolean add(E e);

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
     * @throws assertion si file vide
     */
    public E get();
}