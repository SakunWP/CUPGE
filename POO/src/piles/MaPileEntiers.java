package piles;

public class MaPileEntiers implements IPileEntiers {

    // attributs
    protected int tab[];
    protected int taille;

    // Constructeur

    public MaPileEntiers(int capacite) {
        this.tab = new int[capacite];

    }

    public MaPileEntiers(MaPileEntiers p) {
        this.tab = new int[p.tab.length];
        this.taille = p.taille;
        for (int i = 0; i < p.taille; i++) {
            this.tab[i] = p.tab[i];
        }
    }

    @Override
    public boolean add(int val) {
        if (this.isFull()) {
            return false;
        }
        this.tab[this.taille] = val;
        this.taille++;
        return true;
    }



    @Override
    public boolean remove() {

        if (this.taille == 0) {
            return false;
        }
        this.taille--;
        return true;
    }



    @Override
    public int get() {
        assert (this.isEmpty() == false) ;
        return (this.tab[this.taille - 1]);

    }


    @Override
    public int size() {
        return (this.taille);

    }


    @Override
    public int capacity() {
        return (this.tab.length);
    }


    @Override
    public boolean isFull() {
        if (this.taille == this.tab.length) {
            return true;
        }
        return false;
    }


    @Override
    public boolean isEmpty() {
        if (this.size() == 0) {
            return true;
        }
        return false;
    }


    public String toString() {
        String str = "";
        if (isEmpty()) {
            str = "[]";
        } else {
            str = "[" + this.tab[0];
            for (int i = 1; i < this.taille; i++) {
                str = str + ", " + this.tab[i];
            }
            str = str + "]";
        }
        return str;
    }


    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        if (!(o instanceof MaPileEntiers)) {
            return false;
        }
        MaPileEntiers pile = (MaPileEntiers) o;
        boolean bool = true;
        if (pile.size()!= this.size()) {
            return false;
        }
        for (int i = 0; i < this.taille && bool; i++) {
            if(this.tab[i] != pile.tab[i])
                bool = false;
        }
        return bool;
    }
}









