package TP2;

// Version 14/05/2020


import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class FileArrayListTest {
    private FileArrayList f1;
    private FileArrayList f2;

    @BeforeEach
    void setUp() {
        f1 = new FileArrayList();
        f2 = new FileArrayList();
    }

    @AfterEach
    void tearDown() {
        f1 = null;
        f2 = null;
        System.gc();
    }

    @Test
    void testAdd() {
        f1.add(0);
        Assertions.assertEquals(0, f1.get(), "Erreur add");
        f1.add(1);
        Assertions.assertEquals(0, f1.get(), "Erreur add");
    }

    @Test
    void testRemove() {
        f1.add(0);
        f1.remove();
        Assertions.assertEquals(0, f1.size(), "Erreur remove");
        f1.add(0);
        f1.add(1);
        f1.remove();
        Assertions.assertEquals(1, f1.size(), "Erreur remove");
        Assertions.assertEquals(1, f1.get(), "Erreur remove");
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
        f1.add(1);
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
        Assertions.assertEquals(0, f1.get(), "Erreur get");
        f1.add(1);
        Assertions.assertEquals(0, f1.get(), "Erreur get");
        f1.remove();
        Assertions.assertEquals(1, f1.get(), "Erreur get");
        f1.add(0);
        Assertions.assertEquals(1, f1.get(), "Erreur get");
    }

    @Test
    void testToString() {
        Assertions.assertEquals("[]", f1.toString(), "Erreur toString");
        f1.add(0);
        Assertions.assertEquals("[0.0]", f1.toString(), "Erreur toString");
        f1.add(1);
        Assertions.assertEquals("[0.0, 1.0]", f1.toString(), "Erreur toString");
        f1.remove();
        Assertions.assertEquals("[1.0]", f1.toString(), "Erreur toString");
        f1.remove();
        Assertions.assertEquals("[]", f1.toString(), "Erreur toString");
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
        f2.add(1);
        Assertions.assertTrue(f1.equals(f2), "Erreur equals");
        f1.remove();
        f2.remove();
        Assertions.assertTrue(f1.equals(f2), "Erreur equals");
    }
}
