package greg;
import java.util.GregorianCalendar;
public class Personne implements Comparable<Personne> {

    protected String nom;
    protected GregorianCalendar date;

    public Personne(String nm, int j, int m, int a){
        this.nom= nm;
        this.setDate(j,m,a);
    }

    public boolean equals (Object o){
        if(o==null){
            return false;
        }
        if (!(o instanceof Personne)){
            return false;
        }
        Personne p = (Personne) o;
        return this.date.equals(p.date);
    }

    private void setDate(int j, int m, int a) throws IllegalArgumentException{
            if(a<=1900){
                throw new IllegalArgumentException("Année incorecte");
            }
            if(m<0 || m>12){
                throw new IllegalArgumentException("Mois incorecte");
            }
            if(j<1 || j>nbJours(a,m)){
                throw new IllegalArgumentException("Jour incorecte");
            }
            this.date= new GregorianCalendar(a,m-1,j);
        }




    @Override
    public int compareTo(Personne o) {
        if(this.date.equals(o.date)){
            return 0;
        }
        if(this.date.before(o.date)){
            return 1;
        }
        else{
            return -1;
        }
    }

    public String toString(){
        return "[" + this.nom + " " + this.date.getTime()+ "]";
    }

    private boolean bissextile(int an){
        return false;
    }

    private int nbJours(int an, int m){
        return 0;
    }


}
