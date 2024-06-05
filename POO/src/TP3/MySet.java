package TP3;




import java.util.ArrayList;
import java.util.Random;
public class MySet {
    public int taille;
    public ArrayList<Double> tab;

    public MySet(ArrayList<Double> V){
        this.taille=V.size();
        this.tab= new ArrayList<Double>(V);
    }
    public MySet(){
        this.taille=0;
        this.tab= new ArrayList<Double>(0);
    }

    public MySet(MySet set){
        this.taille= set.taille;
        this.tab= new ArrayList<Double>(set.tab);
    }
    public boolean add (double val){
        if(!this.tab.contains(val)){
            tab.add(val);
        }
        return false;
    }
    public double get(int i){
        assert(this.isEmpty()==false);
        return tab.get(i);
    }
    public int size(){
        return this.tab.size();
    }
    public boolean isEmpty(){
        if(this.tab.isEmpty()){
            return true;
        }
        return false;
    }
    public boolean remove(double val){
        if(!this.tab.contains(val)){
            return false;
        }
        else{
            this.tab.remove(val);
            return true;
        }
    }
    public boolean contains(double x){
        if(this.tab.contains(x)){
            return true;
        }
        return false;
    }
    public String toString(){
        return tab.toString();
    }
    public void clear(){
        tab.clear();
    }
    public double random(){
        if(tab.isEmpty()){
            return (69);
        }
        Random r = new Random();
        int indice= r.nextInt(tab.size());
        return tab.get(indice);
    }

    //@Override
    //public boolean equals(Object o) {
        //if (o == null) {
            //return false;
        //}
        //if (!(o instanceof myset.MySet)) {
            //return false;
        //}
        //if (this.size() != ((myset.MySet) o).size()) {
            //return false;
        //}
        //for (double value : this.tab) {
            //if (!((myset.MySet) o).contains(value)) {
                //return false;
            //}
        //}
        //return true;
    //}


    public boolean equals(Object o) {
        if ((o == null) || (!(o instanceof MySet)) || (this.size() != ((MySet) o).size())){
            return false;
        }
        for (double value : this.tab) {
            if (!((MySet) o).contains(value)) {
                return false;
            }
        }
        return true;
    }
}

