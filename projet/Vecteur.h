#include <vector>
#pragma once



typedef std::vector<double> coord;

class Vecteur {
    
    //attributs
    private :
    
    coord vec ;
    int dim ;
    
    //méthodes
    public :
    
    // constructeur qui initialise un vecteur nul
    Vecteur (int dim )
    
    // constructeur d'un vecteur 3D
    Vecteur ( double n,double p, double t)
    
    //constructeur: les valeurs d'une liste sont données aux coordonnnées de notre vecteur
    
    Vecteur (coord a );
    
    //ajouter une dimension au vecteur et une valeur pour cette dimension
    void augmente  (double x);
    
    //modifier la valeur d'une coordonnée du vecteur
    void set_coord ( int w, double d);
    
    //affichage sur «cout» d'un objet Vecteur
    void affiche () const ;
    
    //tester l'égalité de l'objet Vecteur courant à un autre objet similaire
    bool compare (Vecteur b) const ;
                
                
    //addition de deux vecteurs :
    
    Vecteur addition ( Vecteur b) const ;
    
    // on choisit par convention que c'est la dimension du premier vecteur qui l'emporte sur celle du deuxième, le vecteur c = a.addition(b) aura donc la dimension du vecteur a
    
    
    //la soustraction de deux vecteurs
    Vecteur soustraction ( Vecteur b ) const ;
    
    //opposé d'un vecteur
    Vecteur oppose() const ;
    
    //multiplication par un scalaire
    Vecteur mult(double a) const ;
    
    //produit scalaire de deux vecteurs
    
    double prod_scal (Vecteur b ) const ;
        
    //produit vectoriel de 2 vecteurs si ceux-ci sont de dimension 3
    Vecteur prod_vect (Vecteur b  ) const ;
    
    // calcul de la norme d'un vecteur
    double norme() const ;
    
    
    //calcul de la norme au carré d'un vecteur
    double norme2() const;
    
    //Surcharge interne d'opérateurs
    
    //opérateur interne addition +=
    Vecteur& Vecteur::operator+=(const Vecteur& autre);
    
    // opérateur interne soustraction -=
    Vecteur& Vecteur::operator-=(const Vecteur& autre)
    
    //opérateur interne multiplication par scalaire *=
    Vecteur& Vecteur::operator*=(scalaire);
    
    //Opérateurs de comparaison entre 2 Vecteurs == et !=
    bool Vecteur::operator==(const Vecteur& autre) const;
    
    bool Vecteur::operator!=(const Vecteur& autre) const;
    
    };

