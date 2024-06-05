package TP4;


import java.util.ArrayList;

public class FileChaineeGen<E> implements IFileGen<E> {

    // inner classe
    protected class Cellule {
        E valeur;
        Cellule suivant;

        Cellule(E e) {
            valeur = e;
            suivant = null;
        }
    }

        //attributs de la classe FileChaineeGen
        protected Cellule premier;
        protected Cellule dernier;
        private int taille;

        //constructeur de la classe FileChaineeGen
        public FileChaineeGen() {
            this.taille=0;
            this.premier=null;
            this.dernier=null;
        }

        /**
         * ajouter un élément à la fin de la file
         *
         * @param e référence de l'élément à ajouter
         * @return true si ok, false sinon
         */
        @Override
        public boolean add(E e) {
            Cellule nc= new Cellule(e);
            if(isEmpty()){
                premier=nc;
                dernier=nc;
                taille++;
            }
            else{
                this.dernier.suivant=nc;
                dernier=nc;
                taille++;
            }
            return true;
        }

        /**
         * supprime un élément de la file
         *
         * @return true si enlevé, false sinon
         */
        @Override
        public boolean remove() {
            if(isEmpty()){
                return false;
            }
            else{
                Cellule suiv= this.premier.suivant;
                if (suiv==null){
                    premier=null;
                    dernier=null;
                    taille--;
                }else {
                    premier = this.premier.suivant;
                    taille--;
                }
                return true;
            }

        }

        /**
         * vérifie si la liste est vide
         *
         * @return true si vide, false sinon
         */
        @Override
        public boolean isEmpty() {
            return(premier==null && dernier==null); //ou taille==0
        }

        /**
         * @return la taille de la file
         */
        @Override
        public int size() {
            return taille;
        }

        /**
         * retourne l'élément en tête de file s'il existe
         * si liste vide, un assert est déclenché
         *
         * @return l'élément s'il existe
         */
        @Override
        public E get() {
            assert(!isEmpty());
            return this.premier.valeur;
        }

        /**
         * fonction qui teste l'égalité de deux files
         *
         * @param obj file dont on teste l'égalité avec la file courante
         * @return true si égales, false sinon
         */
        @Override
        public boolean equals(Object obj) {
            if(obj ==null){
                return false;
            }
            if(getClass()!=obj.getClass()){
                return false;
            }
            FileChaineeGen<E> o= (FileChaineeGen<E>) obj;
            if(this.size()!=o.size()){
                return false;
            }
            else{
                boolean bool=true;
                for(int i=0; i<size() && bool;i++){
                    Cellule comp=o.premier;
                    Cellule thiscomp=this.premier;
                    if(!(thiscomp.valeur.equals(comp.valeur))){
                        bool=false;
                    }
                    o.remove();
                    this.remove();
                    o.add(comp.valeur);
                    this.add(thiscomp.valeur);
                }
                return bool;
            }
        }

        /**
         * méthode qui crée une collection qui contient les références des éléments de la file
         *
         * @return collection d'éléments de la file
         */
        protected ArrayList<E> fileToArrayList() {
            ArrayList<E> tab= new ArrayList<E>();
            for(int i=0; i<size(); i++){
                tab.add(this.premier.valeur);
                premier=this.premier.suivant;
            }
            return tab;
        }

        /**
         * @return la chaine de caractères représentative des éléments de la file
         */
        public String toString() {
            String str= "";
            if(isEmpty()){
                str= "[]";
            }
            else{
                E n= this.premier.valeur;
                str= "[" + n;
                remove();
                add(n);
                for(int i=1; i<size();i++){
                    E m= this.premier.valeur;
                    str=str+ " " + m;
                    remove();
                    add(m);
                }
                str=str+"]";
            }
            return str;
        }

    }

