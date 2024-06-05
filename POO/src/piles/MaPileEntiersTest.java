package piles;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

//import static org.junit.jupiter.api.Assertions.*;

class MaPileEntiersTest {
    private MaPileEntiers p1;
    private MaPileEntiers p2;
    private MaPileEntiers p3;

    @BeforeEach
    void setUp() {
        p1 = new MaPileEntiers(10);
        p2 = new MaPileEntiers(9);
        p3 = new MaPileEntiers(2);
    }

    @AfterEach
    void tearDown() {
        p1 = null;
        p2 = null;
        p3 = null;
        System.gc();
    }

    /**
     * Test method for {@link MaPileEntiers#MaPileEntiers(int)}.
     */
    @Test
    void testMaPileEntiers() {
        Assertions.assertTrue(p1.size() == 0 && p1.capacity() == 10, "constructeur erreur");
    }

    @Test
    void isEmpty() {
        Assertions.assertTrue(p1.isEmpty(), "Erreur isEmpty");
        p1.add(0);
        Assertions.assertFalse(p1.isEmpty(), "Erreur isEmpty");
    }

    @Test
    void isFull() {
        int i = 0;
        Assertions.assertFalse(p1.isFull(), "erreur isFull");
        p1.add(i++);
        while (!p1.isFull())
            p1.add(i++);
        Assertions.assertTrue(p1.isFull(), "erreur isFull");
    }

    @Test
    void add() {
        int i = 1;
        Assertions.assertTrue(p1.add(i++), "erreur add");
        Assertions.assertEquals(1, p1.get(), "add erreur");
        while (!p1.isFull())
            p1.add(i++);
        Assertions.assertFalse(p1.add(i), "erreur add pile pleine");
    }

    @Test
    void remove() {
        Assertions.assertFalse(p1.remove(), "add erreur");
        p1.remove();
        Assertions.assertEquals(0, p1.size(), "add erreur");

        p1.add(1);
        p1.add(2);
        Assertions.assertTrue(p1.remove(), "add erreur");
        Assertions.assertEquals(1, p1.size(), "add erreur");
    }

    @Test
    void get() {
        p1.add(1);
        Assertions.assertEquals(1, p1.get(), "get erreur");
        p1.remove();
        Assertions.assertEquals(true, p1.isEmpty(), "get erreur");
        try {
            int v = p1.get();
        } catch (AssertionError e) {
            System.out.println("get d'une pile vide génère bien une "+e.toString());
        } catch (Exception e) {
            Assertions.fail("Erreur get, pas d'assertion avec pile vide");
        }
    }

    @Test
    void testToString() {
        Assertions.assertTrue(p1.toString().equals("[]"), "toString pile vide");
        p1.add(1);
        Assertions.assertTrue(p1.toString().equals("[1]"), "toString pile avec un élément");
        p1.add(2);
        Assertions.assertTrue(p1.toString().equals("[1, 2]"), "toString pile avec 2 éléments");
    }

    @Test
    void size() {
        Assertions.assertEquals(0, p1.size(), "size erreur");
        p1.add(1);
        Assertions.assertEquals(1, p1.size(), "size erreur");
    }

    @Test
    void capacity() {
        if (p1.capacity() != 10) {
            Assertions.fail("capacity erreur" + " p1 : " + p1 + " capacity : " + p1.capacity());
        }
        for (int i = 0; i < 5; i++) {
            p1.add(i);
        }
        if (p1.capacity() != 10)
            Assertions.fail("capacity erreur" + " p1 : " + p1 + " capacity : " + p1.capacity());
    }

    @Test
    void testEquals() {
        Integer entier = 3;
        if (p1.equals(entier))
            Assertions.fail("equals erreur" + " p1 : " + p1 + " entier : " + entier);

        if (!p1.equals(p2))
            Assertions.fail("equals erreur" + " p1 : " + p1 + " p2 : " + p2);

        for (int i = 1; i < 5; i++) {
            p1.add(i);
            p2.add(i);
        }
        if (!p1.equals(p2))
            Assertions.fail("equals erreur" + " p1 : " + p1 + " p2 : " + p2);
        p2.remove();
        if (p1.equals(p2))
            Assertions.fail("equals erreur" + " p1 : " + p1 + " p2 : " + p2);
        p2.add(-1);
        if (p1.equals(p2))
            Assertions.fail("equals erreur" + " p1 : " + p1 + " p2 : " + p2);
    }
}