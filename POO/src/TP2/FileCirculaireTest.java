package TP2;



import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class FileCirculaireTest {
    private FileCirculaire f1;
    private FileCirculaire f2;

    @BeforeEach
    void setUp() throws Exception {
        f1 = new FileCirculaire(5);
        f2 = new FileCirculaire(5);
    }

    @AfterEach
    void tearDown() throws Exception {
        f1 = null;
        f2 = null;
        System.gc();
    }

    @Test
    void testAdd() {
        f1.add(0);
        Assertions.assertEquals(0, f1.get(), "Erreur add");
        f1.remove();
        f1.add(1);
        f1.remove();
        f1.add(2);
        f1.remove();
        f1.add(3);
        f1.remove();
        f1.add(4);
        Assertions.assertEquals(4, f1.get(), "Erreur add");
        f1.add(5);
        Assertions.assertEquals(4, f1.get(), "Erreur add");
        f1.add(6);
        f1.add(7);
    }

    @Test
    void testRemove() {
        Assertions.assertFalse(f1.remove(), "erreur remove file vide");
        f1.add(0);
        Assertions.assertTrue(f1.remove(), "erreur remove");
        Assertions.assertEquals(0, f1.size(), "Erreur remove");
        f1.add(1);
        f1.add(2);
        f1.add(3);
        f1.add(4);
        f1.remove();
        f1.add(5);
        f1.remove();
        Assertions.assertEquals(3, f1.get(), "Erreur remove");
        f1.add(6);
        f1.remove();
        f1.remove();
        f1.remove();
        f1.remove();
        f1.remove();
        Assertions.assertEquals(0, f1.size(), "Erreur remove");
    }

    @Test
    void testIsEmpty() {
        Assertions.assertTrue(f1.isEmpty(), "Erreur isEmpty");
        f1.add(0);
        Assertions.assertFalse(f1.isEmpty(), "Erreur isEmpty");
        f1.remove();
        Assertions.assertTrue(f1.isEmpty(), "Erreur isEmpty");
    }

    @Test
    void testSize() {
        Assertions.assertEquals(0, f1.size(), "Erreur size");
        f1.add(0);
        Assertions.assertEquals(1, f1.size(), "Erreur size");
        f1.remove();
        f1.add(1);
        f1.remove();
        f1.add(2);
        Assertions.assertEquals(1, f1.size(), "Erreur size");
        f1.remove();
        f1.add(3);
        f1.remove();
        f1.add(4);
        f1.add(5);
        f1.add(6);
        f1.add(7);
        System.out.println("f1 : "+f1);
        Assertions.assertEquals(4, f1.size(), "Erreur size");
        f1.remove();
        Assertions.assertEquals(3, f1.size(), "Erreur size");
        f1.remove();
        Assertions.assertEquals(2, f1.size(), "Erreur size");
        f1.remove();
        Assertions.assertEquals(1, f1.size(), "Erreur size");
        f1.remove();
        Assertions.assertEquals(0, f1.size(), "Erreur size");
    }

    @Test
    void testGet() {
        try {
            f1.get();
            Assertions.fail("Erreur get, pas d'assertion avec file vide");
        } catch (AssertionError ignored) {
        }
        f1.add(0);
        Assertions.assertEquals(0.0, f1.get(), "Erreur get");
        f1.add(1);
        Assertions.assertEquals(0.0, f1.get(), "Erreur get");
        f1.remove();
        Assertions.assertEquals(1.0, f1.get(), "Erreur get");
        f1.add(0);
        Assertions.assertEquals(1.0, f1.get(), "Erreur get");
    }

    @Test
    void testIsFull() {
        Assertions.assertFalse(f1.isFull(), "Erreur isFull");
        f1.add(1.0);
        Assertions.assertFalse(f1.isFull(), "Erreur isFull");
        double i = 2.0;
        while (!f1.isFull())
            f1.add(i);
        Assertions.assertTrue(f1.isFull(), "Erreur isFull");
    }

    @Test
    void testCapacity() {
        Assertions.assertEquals(f1.capacity(), 5);
    }

    @Test
    void testToString() {
        Assertions.assertTrue(f1.toString().equals("[]"), "Erreur toString");
        f1.add(0);
        Assertions.assertTrue(f1.toString().equals("[0.0]"), "Erreur toString");
        f1.add(1);
        Assertions.assertTrue(f1.toString().equals("[0.0, 1.0]"), "Erreur toString");
        f1.remove();
        Assertions.assertTrue(f1.toString().equals("[1.0]"), "Erreur toString");
        f1.remove();
        Assertions.assertTrue(f1.toString().equals("[]"), "Erreur toString");
    }

    @SuppressWarnings("unlikely-arg-type")
    @Test
    void testEqualsObject() {
        Assertions.assertFalse(f1.equals(null), "Erreur equals");
        Assertions.assertFalse(f1.equals("hello"), "Erreur equals");
        Assertions.assertTrue(f1.equals(f2), "Erreur equals");
        f1.add(0);
        Assertions.assertFalse(f1.equals(f2), "Erreur equals");
        f1.add(1);
        f2.add(0);
        f2.add(0);
        f2.add(1);
        f2.remove();
        Assertions.assertTrue(f1.equals(f2), "Erreur equals");
        f1.remove();
        f2.remove();
        Assertions.assertTrue(f1.equals(f2), "Erreur equals");
        f1.add(2);
        f1.add(3);
        f2.add(3);
        f2.add(2);
        Assertions.assertFalse(f1.equals(f2), "Erreur equals");
    }

}
