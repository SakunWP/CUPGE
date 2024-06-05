package TP3;

import java.util.ArrayList;

public class MyCompSet extends MySet implements Comparable<MyCompSet>{

    public MyCompSet() {
        super();
    }

    public MyCompSet(MyCompSet set){
        super(set);
    }

    public double sum(){
        double s=0.0;
        for(int i=0 ;i<this.size(); i++){
            s=s+ this.tab.get(i);
        }
        return s;
    }

    @Override
    public int compareTo(MyCompSet o) {
        if(this.sum()<o.sum()){
            return -1;
        }
        return 1;
    }
}
