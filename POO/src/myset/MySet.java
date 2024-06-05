package myset;


import java.util.ArrayList;
import java.util.Random;
public class MySet {
    private int taille;
    private ArrayList<Double> tab;

    public MySet(){
        this.tab= new ArrayList<>();
    }

    public MySet(MySet set){
        this.taille= set.taille;
        this.tab= new ArrayList<Double>(set.tab);
    }
    public void add (double val){
        if(!this.tab.contains(val)){
            tab.add(val);
        }
    }
    public double get(int i){
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

    @Override
    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        if (!(o instanceof MySet)) {
            return false;
        }
        if (this.size() != ((MySet) o).size()) {
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
