package TP3;

// Version 14/05/2020



import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.awt.*;

class RectangleTest {
    Rectangle r1;
    Rectangle r2;
    Rectangle r3;

    @BeforeEach
    void setUp() {
        r1 = new Rectangle(new Point(0, 10), new Point(20, 0));
        r2 = new Rectangle(new Point(10, 10), new Point(30, 0));
        r3 = new Rectangle(new Point(10, 20), new Point(40, 10));
    }

    @AfterEach
    void tearDown() {
        r1 = null;
        r2 = null;
        r3 = null;
        System.gc();
    }

    @Test
    public void Rectangle() {
        r2 = new Rectangle(r1);
        Assertions.assertEquals(r1.getTopLeft(), r2.getTopLeft());
        Assertions.assertEquals(r1.getBottomRight(), r2.getBottomRight());
    }

    @Test
    void translate() {
        Point br = new Point(r1.getBottomRight());
        Point tl = new Point(r1.getTopLeft());
        r1.translate(2, 3);
        Assertions.assertEquals(tl.x + 2, r1.getTopLeft().x, "Erreur translate");
        Assertions.assertEquals(r1.getTopLeft().y, tl.y + 3, "Erreur translate");
        Assertions.assertEquals(r1.getBottomRight().x, br.x + 2, "Erreur translate");
        Assertions.assertEquals(r1.getBottomRight().y, br.y + 3, "Erreur translate");
    }

    @Test
    void getTopLeft() {
        Assertions.assertEquals(new Point(0, 10), r1.getTopLeft(), "Erreur topLeft");
    }

    @Test
    void getBottomRight() {
        Assertions.assertEquals(new Point(20, 0), r1.getBottomRight(), "Erreur getBottomRight");
    }

    @Test
    void perimetre() {
        Assertions.assertTrue(60.0 == r1.perimetre(), "erreur de test de surface");
    }

    @Test
    void testEquals() {
        Assertions.assertTrue(r1.equals(r2), "Erreur equals");
        Assertions.assertFalse(r1.equals(r3), "Erreur equals");
    }
}
