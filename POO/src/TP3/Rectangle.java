package TP3;



import java.awt.*;

public class Rectangle implements IRectangle {
    protected Point topLeft;
    protected Point bottomRight;

    public Rectangle(Point tl, Point br) {
        topLeft = new Point(tl);
        bottomRight = new Point(br);
    }

    public Rectangle(Rectangle r) {
        this.topLeft = new Point(r.getTopLeft());
        this.bottomRight = new Point(r.getBottomRight());
    }

    /**
     * déplacer les deux coins définissant le rectangle
     *
     * @param dx déplacement en x
     * @param dy déplacement en y
     */
    public void translate(int dx, int dy) {
        topLeft.translate(dx, dy);
        bottomRight.translate(dx, dy);
    }

    public String toString() {
        return "[" + topLeft + ", " + bottomRight + "]";
    }

    public Point getTopLeft() {
        return topLeft;
    }

    public Point getBottomRight() {
        return bottomRight;
    }

    public float perimetre() {
        return (Math.abs(this.topLeft.y - this.bottomRight.y) + Math.abs(this.bottomRight.x - this.topLeft.x)) * 2;
    }

    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (!(o instanceof Rectangle))
            return false;
        Rectangle r = (Rectangle) o;
        return this.perimetre() == r.perimetre();
    }
}