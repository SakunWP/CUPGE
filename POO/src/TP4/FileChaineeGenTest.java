package TP4;


import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FileChaineeGenTest {
    private FileChaineeGen<Double> f1;
    private FileChaineeGen<Double> f2;

    @BeforeEach
    void setUp() throws Exception {
        f1 = new FileChaineeGen<Double>();
        f2 = new FileChaineeGen<Double>();
    }

    @AfterEach
    void tearDown() throws Exception {
        f1 = null;
        f2 = null;
        System.gc();
    }

    @Test
    void testAdd() {
        f1.add(0.);
        assertTrue(f1.get() == 0.0, "Erreur add");
        f1.add(1.);
        assertTrue(f1.get() == 0.0, "Erreur add");
        f1.add(2.);
        assertTrue(f1.get() == 0.0, "Erreur add");
        f1.remove();
        assertTrue(f1.get() == 1.0, "Erreur add");
        f1.remove();
        assertTrue(f1.get() == 2.0, "Erreur add");
    }

    @Test
    void testRemove() {
        f1.add(0.);
        f1.remove();
        assertTrue(f1.size() == 0, "Erreur remove");
        f1.add(0.);
        f1.add(1.);
        f1.remove();
        assertTrue(f1.size() == 1, "Erreur remove");
        assertTrue(f1.get() == 1, "Erreur remove");
    }

    @Test
    void testIsEmpty() {
        assertTrue(f1.isEmpty(), "Erreur isEmpty");
        f1.add(0.);
        assertFalse(f1.isEmpty(), "Erreur isEmpty");
        f1.remove();
        assertTrue(f1.isEmpty(), "Erreur isEmpty");
    }

    @Test
    void testSize() {
        assertTrue(f1.size() == 0, "Erreur size");
        f1.add(0.);
        assertTrue(f1.size() == 1, "Erreur size");
        f1.add(1.);
        assertTrue(f1.size() == 2, "Erreur size");
        f1.remove();
        assertTrue(f1.size() == 1, "Erreur size");
        f1.remove();
        assertTrue(f1.size() == 0, "Erreur size");
    }

    @Test
    void testGet() {
        try {
            f1.get();
            fail("Erreur get, pas d'assertion avec file vide");
        } catch (AssertionError ignored) {

        }
        f1.add(0.);
        assertTrue(f1.get() == 0., "Erreur get");
        f1.add(1.);
        assertTrue(f1.get() == 0., "Erreur get");
        f1.remove();
        f1.add(0.);
        assertTrue(f1.get() == 1., "Erreur get");
    }

    @SuppressWarnings("unlikely-arg-type")
    @Test
    void testEqualsObject() {
        assertFalse(f1.equals(null), "Erreur equals");
        assertFalse(f1.equals("hello"), "Erreur equals");
        assertTrue(f1.equals(f2), "Erreur equals");
        f1.add(0.);
        assertFalse(f1.equals(f2), "Erreur equals");
        f1.add(1.);
        f2.add(0.);
        f2.add(1.);
        System.out.println(f1.toString() + f2.toString());
        assertTrue(f1.equals(f2), "Erreur equals");
        f1.remove();
        f2.remove();
        assertTrue(f1.equals(f2), "Erreur equals");
    }

}
