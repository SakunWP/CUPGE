package TP2;

import piles.MaPileEntiers;

import static java.lang.Math.max;

public class FileCirculaire implements IFileBornee {
    public double tab[];
    public int taille;

    public int premier;
    public int dernier;

    public FileCirculaire(int taille){
        this.tab= new double[taille];
        //this.taille=0;
        this.dernier=0;
        this.premier=0;
    }

    public FileCirculaire(FileCirculaire fc){
        this.taille= fc.taille;
        this.tab= new double[fc.tab.length];
        for(int i=0; i<fc.taille; i++){
            this.tab[i]=fc.tab[i];
        }

    }
    @Override
    public boolean isFull() {
        if(this.taille==this.tab.length){
            return true;
        }
        else{
            return false;
        }
    }

    @Override
    public int capacity() {
        return this.tab.length;
    }

    @Override
    public boolean add(double e) {
        if(this.isFull()){
            return false;
        }
        else{
            taille++;
            this.dernier=(this.dernier+1)%this.taille;
            //if(++this.dernier==this.tab.length){
                //dernier=0;
            //}
            this.tab[dernier]=e;
            return true;
        }
    }

    @Override
    public boolean remove() {
        if(this.isEmpty()){
            return false;
        }
        else{
            this.premier=(this.premier+1)%this.taille;
            taille--;
            //if(this.premier++==this.tab.length){
                //premier=0;
            //}
            return true;
        }
    }

    @Override
    public boolean isEmpty() {
        return (this.taille==0);
    }

    @Override
    public int size() {
        return this.taille;
    }

    @Override
    public double get() {
        assert (this.isEmpty()==false);
        return(this.tab[this.premier]);

    }

    public String toString(){
        String str="";
        if(this.isEmpty()){
            str="[]";
        }
        else{
            str= "[" + this.tab[premier];
            for(int i=premier+1; i<this.taille; i++){
                str=str + ", "+ this.tab[i];
            }
            str =str+ "]";
        }
        return str;
    }


    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        if (!(o instanceof FileCirculaire)) {
            return false;
        }
        FileCirculaire file = (FileCirculaire) o;
        boolean bool = true;
        if (file.size()!= this.size()) {
            return false;
        }
        for(int i=this.premier; i<this.dernier; i++){
            double n= this.get();
            double m= file.get();
            if(n!=m){
                return false;
            }
            this.remove();
            file.remove();
            this.add(n);
            file.add(m);
        }
        return true;
    }
}
