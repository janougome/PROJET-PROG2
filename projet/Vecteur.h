#pragma once
#include <vector>
#include <iostream>
#include <initializer_list>

typedef std::vector<double> coord;

class Vecteur {
    
    //attributs
    private :
    
    coord vec ;
    
    
    //méthodes
    public :
    
    //constructeur par défault
    Vecteur()=default;
    
    // constructeur qui initialise un vecteur nul
    Vecteur (size_t dim );
    
    // constructeur d'un vecteur 3D
    Vecteur ( double n,double p, double t);
    
    //constructeur: les valeurs d'une liste sont données aux coordonnnées de notre vecteur
    
    Vecteur (std::initializer_list <double> const& a);
    // accesseur dimension
    
    size_t getdim()const ;
    
    // accesseur coordonnée
    
    double getcoord (size_t n)const ;
    
    //ajouter une dimension au vecteur et une valeur pour cette dimension
    void augmente  (double x);
    
    //modifier la valeur d'une coordonnée du vecteur
    void set_coord( size_t w, double d);
    
    //affichage sur «cout» d'un objet Vecteur
    std::ostream& affiche (std::ostream& cout) const ;
    
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
    Vecteur operator+=(const Vecteur& autre);
    
    // opérateur interne soustraction -=
    Vecteur operator-=( Vecteur const& autre);
    
    //opérateur interne multiplication par scalaire *=
    Vecteur& operator*=(double scalaire);
    
    //Opérateurs de comparaison entre 2 Vecteurs == et !=
    bool operator==(const Vecteur& autre) const;
    
    bool operator!=(const Vecteur& autre) const;
    
    
    
    
    
};
//Surcharge externe d'opérateurs


//affiche Surcharge faite en externe, car on ne veut pas modifier la class ostream :
std::ostream& operator<<(std::ostream& sortie, const Vecteur& v);

//Addition. Externe car on crée une nouvelle instance :
const Vecteur operator+(Vecteur v1, const Vecteur& v2);

//soustraction: externe ( création nouvelle instance) :
const Vecteur operator-(Vecteur v1, const Vecteur& v2);

//Multiplication d'un scalaire à un Vecteur par la droite :
const Vecteur operator*(Vecteur v1, double scalaire);

//Multiplication d'un scalaire à un Vecteur par la gauche :
const Vecteur operator*(double x, const Vecteur& v);

//Opérateur du produit vectoriel :
const Vecteur operator^(Vecteur v1, const Vecteur& v2);

//Opérateur du produit scalaire
double operator*(Vecteur v1, const Vecteur& v2);

//Opérateur retournant l'opposé d'un Vecteur3D
Vecteur operator-(Vecteur& v1);
