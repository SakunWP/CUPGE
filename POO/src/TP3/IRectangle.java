package TP3;


import java.awt.*;

public interface IRectangle {
    /**
     * déplacer les deux coins définissant le rectangle
     *
     * @param dx déplacement en x
     * @param dy déplacement en y
     */
    public void translate(int dx, int dy);

    /**
     * Accesseur du point haut gauche
     *
     * @return point haut gauche
     */
    public Point getTopLeft();

    /**
     * Accesseur du point bas droit
     *
     * @return point bas droit
     */
    public Point getBottomRight();

    /**
     * calcule et retourne le périmètre du rectangle
     *
     * @return périmètre du rectangle
     */
    public float perimetre();
}
