package TP4;



public class Personne implements Comparable<Personne> {
    /**
     * nom de la personne
     */
    protected String nom;
    /**
     * prenom de la personne
     */
    protected String prenom;
    /**
     * age de la personne
     */
    protected int age;

    /**
     * Constructeur
     *
     * @param n   nom
     * @param p   prenom
     * @param age age
     */
    public Personne(String n, String p, int age) {
        nom = n;
        prenom = p;
        this.age = age;
    }

    /**
     * Accesseur
     *
     * @return nom de la personne
     */
    public String getNom() {
        return nom;
    }

    /**
     * Accesseur
     *
     * @return prénom de la personne
     */
    public String getPrenom() {
        return prenom;
    }

    /**
     * Accesseur
     *
     * @return l'âge de la personne
     */
    public int getAge() {
        return this.age;
    }

    /**
     * @param p personne
     * @return > 0 si la personne courante a une priorité supérieure à celle passée
     * enparamètre, 0 si les priorités sont égales, <0 sinon
     */
    @Override
    public int compareTo(Personne p) {

        return (this.age - p.age);
    }

    /**
     * @return négatif si o1 est plus jeune, positif si plus âgé,
     * 0 si égalité
     */
    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (!(o instanceof Personne))
            return false;
        Personne p = (Personne) o;
        return this.nom.equals(p.nom) && this.prenom.equals(p.prenom) && this.age == p.age;
    }

    /**
     * @return ch de carac représentative de l'état d'une personne
     */
    public String toString() {
        return "[" + nom + " " + prenom + ", " + age + "]";
    }
}
