package TP3;



import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MyCompSetTest {
    private MyCompSet m1;
    private MyCompSet m2;
    @BeforeEach
    void setUp() {
        m1 = new MyCompSet();
        m2 = new MyCompSet();
    }

    @AfterEach
    void tearDown() {
        m1 = null;
        m2 = null;
        System.gc();
    }

    @Test
    void compareTo() {
        m1.add(0.1);
        Assertions.assertTrue(m1.compareTo(m2) >= 1, "erreur m1 > m2 val très petites");
        m2.add(0.01);
        Assertions.assertTrue(m1.compareTo(m2) >= 1, "erreur m1 > m2 val très petites");
        m2.add(0.2);
        Assertions.assertTrue(m1.compareTo(m2) <= -1, "erreur m1 < m2 val très petites");
    }
}
