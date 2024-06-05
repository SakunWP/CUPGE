package TP3;



import org.junit.jupiter.api.*;
import java.awt.*;

public class ColoredRectangleTest {

    private ColoredRectangle cr;

    @BeforeEach
    public void setUp() {
        cr = new ColoredRectangle(new Point(0, 0), new Point(10, 5), Color.RED);
    }

    @AfterEach
    public void tearDown() {
        cr = null;
        System.gc();
    }

    @Test
    public void testTranslate() {
        cr.translate(5, 2);
        Assertions.assertEquals(new Point(5, 2), cr.getTopLeft(), "Erreur translate - TopLeft");
        Assertions.assertEquals(new Point(15, 7), cr.getBottomRight(), "Erreur translate - BottomRight");
    }

    @Test
    public void testEquals() {
        ColoredRectangle cr2 = new ColoredRectangle(new Point(0, 0), new Point(10, 5), Color.RED);
        ColoredRectangle cr3 = new ColoredRectangle(new Point(0, 0), new Point(10, 5), Color.BLUE);

        Assertions.assertTrue(cr.equals(cr2), "Erreur equals - cr et cr2");
        Assertions.assertFalse(cr.equals(cr3), "Erreur equals - cr et cr3");
    }

    @Test
    public void testToString() {
        String expected = "[java.awt.Point[x=0,y=0], java.awt.Point[x=10,y=5]]";
        Assertions.assertEquals(expected, cr.toString(), "Erreur toString");
    }

    @Test
    public void testCompareTo() {
        ColoredRectangle cr4 = new ColoredRectangle(new Point(0, 0), new Point(5, 2), Color.RED);
        ColoredRectangle cr5 = new ColoredRectangle(new Point(0, 0), new Point(20, 10), Color.RED);

        Assertions.assertTrue(cr.compareTo(cr4) > 0, "Erreur compareTo - cr et cr4");
        Assertions.assertTrue(cr.compareTo(cr5) < 0, "Erreur compareTo - cr et cr5");
        Assertions.assertTrue(cr.compareTo(cr) == 0, "Erreur compareTo - cr et cr");
    }
}
