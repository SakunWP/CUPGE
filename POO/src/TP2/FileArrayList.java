package TP2;

import java.util.ArrayList;

public class FileArrayList implements IFileNonBornee{

    public ArrayList<Double> file;
    public int compteur;
    public int premier;
    //public int dernier;

    public FileArrayList(){
        this.file= new ArrayList<>();
        this.compteur=0;
        this.premier=0;
        //this.dernier=0;
    }

    public FileArrayList(FileArrayList tab){
        this.file= new ArrayList<Double>(tab.file);
        this.compteur=tab.compteur;
        this.premier=tab.premier;
    }
    @Override
    public boolean add(double e) {
        compteur++;
        //dernier++;
        return file.add(e);
    }

    @Override
    public boolean remove() {
        if(isEmpty()){
            return false;
        }
        file.remove(this.premier);
        return true;

    }

    @Override
    public boolean isEmpty() {
        return file.isEmpty();
    }

    @Override
    public int size() {
        return this.file.size();
    }

    @Override
    public double get() {
        assert(this.isEmpty()==false);
        return file.get(premier);
    }

    @Override
    public String toString() {
        return file.toString();
    }

    public boolean equals(Object o){
        if(o==null){
            return false;
        }
        if(!(o instanceof FileArrayList)){
            return false;
        }
        FileArrayList newFile= (FileArrayList) o;
        boolean bool= true;
        if(this.size()!=newFile.size()){
            return false;
        }
        else{
            for(int i=0; i<this.size() && bool; i++){
                double n=this.get();
                double m=newFile.get();
                if(n!=m){
                    bool=false;
                }
                this.remove();
                newFile.remove();
                this.add(n);
                newFile.add(m);
            }
            return bool;
        }
    }
}
