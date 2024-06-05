// Version 3/2/21

package myset;


import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class MySetTest {
    private MySet m1;
    private MySet m2;
    private MySet m3;

    /**
     * @throws java.lang.Exception
     */
    @BeforeEach
    void setUp() throws Exception {
        m1 = new MySet();
        m2 = new MySet();
        m3 = new MySet();
    }

    /**
     * @throws java.lang.Exception
     */
    @AfterEach
    void tearDown() throws Exception {
        m1 = null;
        m2 = null;
        m3 = null;
    }

    @Test
    void testMySet() {

        Assertions.assertEquals(0, m1.size(), "erreur constructeur");
    }

    @Test
    void testMySetMySet() {
        Assertions.assertEquals(0, m2.size(), "erreur de constructeur par copie d'un ensemble vide");
        m1.add(1.0);
        m2 = new MySet(m1);
        Assertions.assertEquals(1, m2.size(), "erreur de constructeur par copie");
        Assertions.assertTrue(m2.contains(1.0), "erreur de constructeur par copie");
    }

    @Test
    void testClear() {
        m1.clear();
        Assertions.assertEquals(0, m1.size(), "erreur clear ensemble vide");
        m1.add(12.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        m1.clear();
        Assertions.assertEquals(0, m1.size(), "erreur clear ensemble non vide");
    }

    @Test
    void testSize() {
        Assertions.assertEquals(0, m1.size(), "erreur size ensemble vide");
        m1.add(12.0);
        Assertions.assertEquals(1, m1.size(), "erreur size");
        m1.add(12.0);
        Assertions.assertEquals(1, m1.size(), "erreur size");
        m1.add(3.0);
        m1.add(10.0);
        Assertions.assertEquals(3, m1.size(), "erreur size");
    }

    @Test
    void testIsEmpty() {
        Assertions.assertTrue(m1.isEmpty(), "erreur isEmpty ensemble vide");
        m1.add(1.0);
        Assertions.assertFalse(m1.isEmpty(), "erreur isEmpty");
        m1.add(1.0);
        Assertions.assertFalse(m1.isEmpty(), "erreur isEmpty");
    }

    @Test
    void testAdd() {
        m1.add(1.0);
        Assertions.assertTrue(m1.contains(1.0), "erreur add");
        Assertions.assertFalse(m1.contains(0.0), "erreur add");
        m1.add(1.0);
        Assertions.assertEquals(1, m1.size(), "erreur add");
        m1.add(10.0);
        Assertions.assertEquals(2, m1.size(), "erreur add");
        m1.add(10.0);
        Assertions.assertEquals(2, m1.size(), "erreur add");
        m1.add(15.0);
        m1.add(15.0);
        Assertions.assertEquals(3, m1.size(), "erreur add");
        m1.add(12.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        Assertions.assertEquals(6, m1.size(), "erreur add");
    }

    @Test
    void testRemove() {
        Assertions.assertFalse(m1.remove(0.0), "erreur remove ensemble vide");
        m1.add(1.0);
        m1.add(2.0);
        Assertions.assertTrue(m1.remove(1.0), "erreur remove");
        Assertions.assertEquals(1, m1.size(), "erreur remove");
        Assertions.assertFalse(m1.remove(3.0), "erreur remove");
        Assertions.assertEquals(1, m1.size(), "erreur remove");
    }

    @Test
    void testContains() {
        Assertions.assertFalse(m1.contains(0.0), "erreur contains ensemble vide");
        m1.add(1.0);
        m1.add(2.0);
        Assertions.assertTrue(m1.contains(1.0), "erreur contains");
        Assertions.assertFalse(m1.contains(3.0), "erreur contains");
    }

    @Test
    void testRandom() {
        double v;
        try {
            v = m1.random();
            Assertions.fail("assertion non renvoyée, ensemble vide");
        } catch (AssertionError ae) {
            assert (true);
        }
        m1.add(1.0);
        m1.add(15.0);
        m1.add(15.0);
        m1.add(12.0);
        m1.add(8.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        v = m1.random();
        Assertions.assertTrue(m1.contains(v), "erreur random");

    }

    @Test
    void testToString() {
        Assertions.assertEquals("[]", m1.toString(), "erreur toString, ensemble vide");
        m1.add(1.0);
        Assertions.assertEquals("[1.0]", m1.toString(), "erreur toString");
        m1.add(2.0);
        Assertions.assertEquals("[1.0, 2.0]", m1.toString(), "erreur toString");
    }

    @Test
    void testEquals() {
        Assertions.assertFalse(m1.equals("toto"), "erreur equals classe");
        Assertions.assertFalse(m1.equals(null), "erreur equals null");
        Assertions.assertTrue(m1.equals(m2), "erreur equals ensembles vides");
        m1.add(1.0);
        Assertions.assertFalse(m1.equals(m2), "erreur equals");
        m1.add(2.0);
        m2.add(2.0);
        m2.add(1.0);
        Assertions.assertTrue(m1.equals(m2), "erreur equals");
        m1.add(3.0);
        Assertions.assertFalse(m1.equals(m2), "erreur equals");
    }
}