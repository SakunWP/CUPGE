package TP3;

import java.awt.Point;
import java.awt.Color;


import java.awt.Point;
import java.awt.Color;


public class ColoredRectangle extends Rectangle implements Comparable<ColoredRectangle>{

    public Color color;

    public ColoredRectangle(Point tl, Point br,Color c) {
        super(tl, br);
        this.color=c;
    }

    public float aire(ColoredRectangle rect){
        return(Math.abs(rect.topLeft.y - rect.bottomRight.y) * Math.abs(rect.bottomRight.x - rect.topLeft.x));
    }

    @Override
    public int compareTo(ColoredRectangle o) {
        int n=0;
        if(aire(this)>aire(o)){
            n=1;
        } else if (aire(this)<aire(o)) {
            n=-1;
        }
        else{
            n=0;
        }
        return n;
    }


    public void translate(int dx, int dy){
        super.translate(dx,dy);
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public boolean equals(Object o) {
        ColoredRectangle r = (ColoredRectangle) o;
        if (this.color==r.color && super.equals(r)==true){
            return true;
        }
        return false;
    }
}