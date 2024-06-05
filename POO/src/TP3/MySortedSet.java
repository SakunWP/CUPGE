package TP3;
import java.util.*;
public class MySortedSet extends MyCompSet{
    public MySortedSet(){
        super();
    }

    public MySortedSet(MySortedSet set){
        super(set);
    }

    //@Override
    public boolean add(double value) {
        if (!contains(value)) {
            tab.add(value);
            Collections.sort(tab);
            return true;
        } else {
            return false;
        }
    }

    public MySortedSet union(MySortedSet set) {
        MySortedSet unionSet = new MySortedSet(this);
        for (double elem : set.tab) {
            unionSet.add(elem);
        }
        return unionSet;
    }

    public MySortedSet intersection(MySortedSet ens) {
        MySortedSet inter = new MySortedSet();
        int i = 0, j = 0;
        while (i < this.size() && j < ens.size()) {
            if (this.get(i) == ens.get(j)) {
                inter.add(this.get(i));
                i++;
                j++;
            } else if (this.get(i) < ens.get(j)) {
                i++;
            } else {
                j++;
            }
        }
        return inter;
    }

    public MySortedSet difference(MySortedSet otherSet) {
        MySortedSet result = new MySortedSet();
        int i = 0, j = 0;
        while (i < this.size() && j < otherSet.size()) {
            double thisVal = this.get(i);
            double otherVal = otherSet.get(j);
            if (thisVal < otherVal) {
                result.add(thisVal);
                i++;
            } else if (thisVal > otherVal) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        while (i < this.size()) {
            result.add(this.get(i));
            i++;
        }
        return result;
    }


    public boolean subset(MySortedSet otherSet) {
        int i = 0, j = 0;
        while (i < this.size() && j < otherSet.size()) {
            double thisVal = this.get(i);
            double otherVal = otherSet.get(j);
            if (thisVal < otherVal) {
                i++;
            } else if (thisVal > otherVal) {
                return false;
            } else {
                i++;
                j++;
            }
        }
        return j == otherSet.size();
    }

    public double nearest(double value) {
        int low = 0;
        int high = this.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            double midVal = this.get(mid);
            if (midVal < value) {
                low = mid + 1;
            } else if (midVal > value) {
                high = mid - 1;
            } else {
                return midVal;
            }
        }
        if (high < 0) {
            return this.get(low);
        } else if (low >= this.size()) {
            return this.get(high);
        } else {
            double lowVal = this.get(low);
            double highVal = this.get(high);
            if (Math.abs(value - lowVal) < Math.abs(value - highVal)) {
                return lowVal;
            } else {
                return highVal;
            }
        }
    }

    @Override
    public boolean equals(Object o) {
        return super.equals(o);
    }

    @Override
    public double get(int i) {
        assert((0<=i) && (i<super.size()));
        return super.get(i);
    }
}
