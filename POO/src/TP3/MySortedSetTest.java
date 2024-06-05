// Version 14/05/2020
package TP3;

import org.junit.jupiter.api.Assertions;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

/**
 * @author gaildrat
 *
 */
class MySortedSetTest {
    private MySortedSet m1;
    private MySortedSet m2;
    private MySortedSet m3;
    private MySortedSet m4;

    /**
     * Tout créer
     */
    @BeforeEach
    void setUp() throws Exception {
        m1 = new MySortedSet();
        m2 = new MySortedSet();
        m3 = new MySortedSet();
        m4 = new MySortedSet();
    }

    /**
     * Tout libérer
     */
    @AfterEach
    void tearDown() throws Exception {
        m1 = null;
        m2 = null;
        m3 = null;
        m4 = null;
        System.gc();
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#add(double)}.
     */
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
        Assertions.assertEquals(3.0, m1.get(1), "erreur add");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#get(int)}.
     */
    @Test
    void testGet() {
        try {
            m1.get(0);
            Assertions.fail("assertion non renvoyée, get ensemble vide");
        } catch (AssertionError ae) {
            assert (true);
        }
        m1.add(4.0);
        Assertions.assertEquals(4.0, m1.get(0), "erreur get du premier élément");
        m1.add(15.0);
        m1.add(12.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        Assertions.assertEquals(15.0, m1.get(5), "erreur get du dernier élément");
        Assertions.assertEquals(3.0, m1.get(0), "erreur get du premier élément");
        Assertions.assertEquals(4.0, m1.get(1), "erreur get du premier élément");
        try {
            m1.get(-1);
            Assertions.fail("assertion non renvoyée, index incorrect");
        } catch (AssertionError ae) {
            assert (true);
        }
        try {
            m1.get(m1.size());
            Assertions.fail("assertion non renvoyée, index incorrect");
        } catch (AssertionError ae) {
            assert (true);
        }
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#MySortedSet()}.
     */
    @Test
    void testMySortedSet() {
        Assertions.assertEquals(0, m1.size(), "erreur constructeur");
        Assertions.assertTrue(m1.isEmpty(), "erreur constructeur");

        m1.add(3.0);
        m1.add(2.0);
        m2 = new MySortedSet(m1);
        Assertions.assertTrue(m1.get(0) == m2.get(0) && m1.get(1) == m2.get(1) && m1.size() == m2.size(),
                "erreur constructeur par copie");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#union(ensembles.ensemblesHeritage2020.MySortedSet)}.
     */
    @Test
    void testUnion() {
        m2 = new MySortedSet(m1);

        m3 = m1.union(m2);
        Assertions.assertTrue(m3.isEmpty(), "union erreur m1 et m2 vides");

        for (int i = 6; i > 0; i = i - 2) {
            m1.add((double) i);
        }
        m2.add(2.0);
        m3 = m1.union(m2);
        Assertions.assertTrue(m3.equals(m1), "union erreur m2 inclus dans m1");
        m2.add(3.0);
        m3 = m1.union(m2);
        Assertions.assertFalse(m3.equals(m1), "union erreur m2 non inclus dans m1");
        m1.add(3.0);
        Assertions.assertTrue(m3.equals(m1), "union erreur m3 est égal à m1 après add dans m1");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#intersection(ensembles.ensemblesHeritage2020.MySortedSet)}.
     */
    @Test
    void testIntersection() {
        m2 = new MySortedSet(m1);

        m3 = m1.intersection(m2);
        Assertions.assertTrue(m3.isEmpty(), "intersection erreur m1 et m2 vides");

        for (int i = 6; i > 0; i = i - 2) {
            m1.add((double) i);
        }
        m2.add(3.0);
        m3 = m1.intersection(m2);
        Assertions.assertTrue(m3.isEmpty(), "intersection erreur intersection vide : m1 :" + m1 + " m2 : " + m2);
        m2.add(2.0);
        m3 = m1.intersection(m2);
        // il ne reste qu'un seul élément
        Assertions.assertTrue(m3.get(0) == 2.0, "intersection erreur intersection non vide");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#difference(ensembles.ensemblesHeritage2020.MySortedSet)}.
     */
    @Test
    void testDifference() {
        m2 = new MySortedSet(m1);

        m1 = m1.difference(m2);
        Assertions.assertTrue(m1.isEmpty(), "difference erreur m1 et m2 vides");
        for (int i = 6; i > 0; i = i - 2) {
            m1.add((double) i);
        }
        m2.add(3.0);
        m1 = m1.difference(m2);
        System.out.println(m1);
        System.out.println(m2);
        Assertions.assertTrue(m1.equals(m1), "difference erreur intersection vide");
        m2.add(2.0);
        m1 = m1.difference(m2);
        Assertions.assertTrue(m1.toString().equals("[4.0, 6.0]"), "difference erreur intersection non vide");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#subset(ensembles.ensemblesHeritage2020.MySortedSet)}.
     */
    @Test
    void testSubset() {
        m2 = new MySortedSet(m1);

        Assertions.assertTrue(m1.subset(m2), "subset erreur m1 et m2 vides");

        for (int i = 6; i > 0; i = i - 2) {
            m1.add((double) i);
        }
        m2.add(2.0);
        Assertions.assertTrue(m1.subset(m2), "subset erreur m2 sous-ensemble de m1");
        m2.add(3.0);
        Assertions.assertFalse(m1.subset(m2), "subset erreur m2 non sous-ensemble de m1");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySortedSet#nearest(double)}.
     */
    @Test
    void testNearest() {
        m1.add(1.0);
        m1.add(15.0);
        m1.add(15.0);
        m1.add(12.0);
        m1.add(8.0);
        m1.add(8.0);
        m1.add(3.0);
        m1.add(10.0);
        Assertions.assertEquals(1.0, m1.nearest(1.0), "nearest erreur 1");
        Assertions.assertEquals(15.0, m1.nearest(15.0), "nearest erreur 15");
        Assertions.assertEquals(15.0, m1.nearest(14.0), "nearest erreur 14");
        Assertions.assertEquals(8.0, m1.nearest(7.0), "nearest erreur 7");
        Assertions.assertEquals(1.0, m1.nearest(0.0), "nearest erreur 0");
        Assertions.assertEquals(15.0, m1.nearest(22.0), "nearest erreur 22");
    }

    /**
     * Test method for {@link ensembles.ensemblesHeritage2020.MySet#clear()}.
     */
    @Test
    void testClear() {
        Assertions.assertTrue(m1.isEmpty());
        m1.add(1.0);
        m1.add(10.0);
        m1.clear();
        Assertions.assertEquals(0, m1.size(), "clear erreur");
    }

    /**
     * Test method for {@link ensembles.ensemblesHeritage2020.MySet#size()}.
     */
    @Test
    void testSize() {
        Assertions.assertEquals(0, m1.size(), "size erreur");
        m1.add(1.0);
        Assertions.assertEquals(1, m1.size(), "size erreur après add");
        m1.add(10.0);
        Assertions.assertEquals(2, m1.size(), "size erreur après add");
        m1.remove(10.0);
        Assertions.assertEquals(1, m1.size(), "size erreur après remove");
    }

    /**
     * Test method for {@link ensembles.ensemblesHeritage2020.MySet#isEmpty()}.
     */
    @Test
    void testIsEmpty() {
        Assertions.assertTrue(m1.isEmpty(), "empty erreur");
        m1.add(1.0);
        Assertions.assertFalse(m1.isEmpty(), "empty erreur après add");
    }

    /**
     * Test method for {@link ensembles.ensemblesHeritage2020.MySet#remove(double)}.
     */
    @Test
    void testRemove() {
        Assertions.assertFalse(m1.remove(1.0), "remove erreur ensemble vide");
        m1.add(1.0);
        Assertions.assertTrue(m1.remove(1.0), "remove erreur après add de 1.0");
        Assertions.assertFalse(m1.remove(10.0), "remove erreur après remove de 10.0 absent");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySet#contains(double)}.
     */
    @Test
    void testContains() {
        Assertions.assertFalse(m1.contains(1.0), "contains erreur ensemble vide");
        m1.add(1.0);
        Assertions.assertTrue(m1.contains(1.0), "contains erreur après add de 1.0");
        Assertions.assertFalse(m1.contains(10.0), "contains erreur après remove de 10.0 absent");
    }

    /**
     * Test method for {@link ensembles.ensemblesHeritage.MySet#random()}.
     */
//	@Test
//	void testRandom() {
//		m1.add(1.0);
//		Assertions.assertTrue(m1.random() == 1.0, "random erreur");
//		try {
//			m1.remove(1.0);
//			double v = m1.random();
//		} catch (Error e) {
//			System.out.println("test de random d'un ensemble vide doit bien générer une assertion");
//		}
//	}

    /**
     * Test method for {@link ensembles.ensemblesHeritage2020.MySet#toString()}.
     */
    @Test
    void testToString() {
        Assertions.assertEquals("[]", m1.toString(), "toString vide");
        m1.add(2.0);
        Assertions.assertEquals("[2.0]", m1.toString(), "toString avec 1 élément");
        m1.add(1.0);
        m1.add(1.5);
        Assertions.assertEquals("[1.0, 1.5, 2.0]", m1.toString(), "toString avec 3 éléments");
        m1.remove(1.0);
        Assertions.assertEquals("[1.5, 2.0]", m1.toString(), "toString avec 2 éléments");
    }

    /**
     * Test method for
     * {@link ensembles.ensemblesHeritage2020.MySet#equals(Object)}.
     */
    @Test
    void testEqualsMySet() {
        System.out.println("m1 égal à m2 : " + m1.equals(m2));
        Assertions.assertTrue(m1.equals(m2), "equals erreur" + " p1 : " + m1 + " p2 : " + m2);

        for (int i = 1; i < 5; i++) {
            m1.add((double) i);
            m2.add((double) i);
        }
        Assertions.assertTrue(m1.equals(m2), "equals erreur" + " p1 : " + m1 + " p2 : " + m2);
        m2.remove(1.0);
        Assertions.assertFalse(m1.equals(m2), "equals erreur" + " p1 : " + m1 + " p2 : " + m2);
        m2.add(-1.0);
        Assertions.assertFalse(m1.equals(m2), "equals erreur" + " p1 : " + m1 + " p2 : " + m2);
    }
}