#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <cmath>
#include "Vecteur.h"

using namespace std ;



// constructeur qui initialise un vecteur nul
Vecteur::Vecteur (size_t dim ) {
    for (size_t i (0) ; i < dim ; ++i) {
        
        augmente(0.0);
        
    }
    
}


// constructeur d'un vecteur 3D
Vecteur::Vecteur (double n,double p, double t)
{
    
    augmente(n);
    augmente(p);
    augmente(t);
    
    
    
}

//constructeur: les valeurs d'une liste sont données aux coordonnnées de notre vecteur

Vecteur::Vecteur(initializer_list<double> const& a)



{}




// accesseur dimension
size_t Vecteur::getdim() const{
    return vec.size();
    
}

// accesseur coordonnées

double Vecteur::getcoord (size_t n) const {
    return vec[n];
}


//ajouter une dimension au vecteur et une valeur pour cette dimension
void Vecteur:: augmente  (double x) {
    
    
    vec.push_back(x);
    
}

//modifier la valeur d'une coordonnée du vecteur
void Vecteur::set_coord( size_t w, double d) {
    
    
    if (w < vec.size() ) {
        
        vec [w] = d ;
        
    } else {
        
        cout << "impossible cette coordonnée n'existe pas" << endl;
    }
}

//affichage sur «cout» d'un objet Vecteur
ostream& Vecteur::affiche (ostream& cout) const {
    
    for (auto el : vec) {
        
        cout << el << " "  ;
        
    }
    return cout;
}

//tester l'égalité de l'objet Vecteur courant à un autre objet similaire
bool Vecteur::compare  (Vecteur b) const {
    
    if (vec.size() == b.getdim()) {
        
        
        
        for (size_t i(0); i < vec.size(); ++i){
            
            if (vec[i] != b.vec[i]) {
                
                //cout <<" les deux vecteurs ne sont pas identiques" <<endl;
                return false;
            }
            
            
            
        }
        
        //cout << " les deux vecteur sont identiques. " << endl;
        return true;
        
    } else {
        
        cout <<" ces deux vecteurs n'ont pas la même dimension " << endl;
        return false;
    }
    
    
    
    
}
//==================================================================================
//Surcharge interne d'opérateurs

// opérateur interne addition

Vecteur Vecteur::operator+=(const Vecteur& autre){
    Vecteur o;
    
    for (size_t i(0) ; i < fmin(vec.size(),autre.vec.size()) ; ++i){
        o.vec.push_back(vec[i] + autre.vec[i]);
    }
    return o;
}

// opérateur interne soustraction
Vecteur Vecteur::operator-=(Vecteur const& autre){
    Vecteur o;
    
    for (size_t i(0) ; i < fmin(vec.size(),autre.vec.size()) ; ++i){
        o.vec.push_back(vec[i] - autre.vec[i]);
    }
    return o;
}

//opérateur interne multiplication par scalaire à droite
Vecteur& Vecteur::operator*=(double scalaire){
    for (size_t i(0) ; i < vec.size(); ++i){
        vec[i] *= scalaire;
    }
    return *this;
}

//Opérateurs de comparaison entre 2 Vecteurs
bool Vecteur::operator==(const Vecteur& autre) const{
    for (size_t i(0) ; i < fmin(vec.size(),autre.getdim()) ; ++i){
        if(vec[i] != autre.getcoord(i)) {
            return false;
        }
    }
    return true;
}

// true si égalité

bool Vecteur::operator!=(const Vecteur& autre) const{
    return (not(*this==autre));
}// true si différence

//==================================================================================
//Surcharge externe d'opérateurs


//affiche Surcharge faite en externe, car on ne veut pas modifier la class ostream :
ostream& operator<<(ostream& cout, const Vecteur& v){
    return v.affiche(cout);
}
//----------------------------------------------------------------------------------
//Addition. Externe car on crée une nouvelle instance :
const Vecteur operator+(Vecteur v1, const Vecteur& v2){
    Vecteur u(v1+=v2);
    return u;
}
//----------------------------------------------------------------------------------
//Soustraction. Même raison :
const Vecteur operator-(Vecteur v1, const Vecteur& v2){
    Vecteur u(v1-=v2);
    return u;
    
}
//----------------------------------------------------------------------------------
//Multiplication d'un scalaire à un Vecteur à droite  :
const Vecteur operator*(Vecteur v1, double scalaire){
    
    v1*=scalaire;
    return v1;
}
//----------------------------------------------------------------------------------
//Multiplication d'un scalaire à un Vecteur par la gauche :
const Vecteur operator*(double x, const Vecteur& v){
     return v*x;
}
//----------------------------------------------------------------------------------
//Opérateur du produit vectoriel :
const Vecteur operator^(Vecteur a, const Vecteur& b){
    
    
    if ( (a.getdim()== 3 )and (b.getdim() == 3)){
        
        Vecteur c(a.getcoord(1)*b.getcoord(2)-a.getcoord(2)*b.getcoord(1),a.getcoord(2)*b.getcoord(0) - a.getcoord(0)*b.getcoord(2),a.getcoord(0)*b.getcoord(1) - a.getcoord(1)*b.getcoord(0));
        
        
        return c;
        
    } else {
        if (a.getdim()==b.getdim()) {
            
            cout << "impossible, ces deux vecteurs sont de même dimension différente de 3 mais le produit vectoriel est défini que pour la dimension 3" << endl;
            
        } else {
            cout << "impossible, ces deux vecteurs sont de dimensions différentes" << endl;
        }
    }
}



//----------------------------------------------------------------------------------
//Opérateur du produit scalaire
double operator*(Vecteur v1, const Vecteur& v2){
    
    double x(0);
    for (size_t i(0) ; i < fmin(v1.getdim(),v2.getdim()) ; ++i){
        x += v1.getcoord(i)*v2.getcoord(i);
    }
    return x;
}
//----------------------------------------------------------------------------------
//Opérateur retournant l'opposé d'un Vecteur
Vecteur operator-( Vecteur& v1){
    
    
    v1 = (-1)*v1;
    
    
    
    return v1;
}





//addition de deux vecteurs :
Vecteur Vecteur:: addition ( Vecteur b) const {
    Vecteur c;
    for (size_t i(0) ; i < fmin(vec.size(),b.vec.size()) ; ++i){
        c.vec.push_back(vec[i] + b.vec[i]);
        
    }
    return c ;
    // on choisit par convention que c'est la plus petite dimension des deux vecteurs qui déterminera
}

//la soustraction de deux vecteurs
Vecteur Vecteur:: soustraction ( Vecteur b ) const {
    Vecteur c;
    
    for (size_t i(0) ; i < fmin(vec.size(),b.vec.size()) ; ++i){
        c.vec.push_back(vec[i] - b.vec[i]);
        
    }
    return c ;
}

//opposé d'un vecteur
Vecteur Vecteur:: oppose() const {
    Vecteur b;
    for (size_t i(0) ; i < vec.size(); ++i) {
        b.vec.push_back (- vec[i]);
    }
    return b;
}

//multiplication par un scalaire
Vecteur Vecteur:: mult(double a) const {
    Vecteur b;
    for (size_t i(0) ; i < vec.size(); ++i){
        
        b.vec.push_back( vec[i] * a );
    }
    return b;
    
}

//produit scalaire de deux vecteurs

double Vecteur:: prod_scal (Vecteur b ) const {
    double x(0);
    for (size_t i(0) ; i < fmin(vec.size(),b.vec.size()) ; ++i){
        x += vec[i]*b.vec[i];
    }
    return x;
}

//produit vectoriel de 2 vecteurs si ceux-ci sont de dimension 3
Vecteur Vecteur:: prod_vect (Vecteur b  ) const {
    
    
    Vecteur c ;
    
    
    if ( (vec.size()== 3 )and (b.vec.size() == 3)){
        
        c.vec.push_back(vec[1]*b.vec[2]-vec[2]*b.vec[1]);
        c.vec.push_back(vec[2]*b.vec[0] - vec[0]*b.vec[2]);
        c.vec.push_back(vec[0]*b.vec[1] - vec[1]*b.vec[0]);
        
    } else {
        if ( vec.size()==b.vec.size()) {
            
            cout << "impossible, ces deux vecteurs sont de même dimension différente de 3 mais le produit vectoriel est défini que pour la dimension 3" << endl;
            
        } else {
            cout << "impossible, ces deux vecteurs sont de dimensions différentes" << endl;
            
        }
        
    }
    
}


// calcul de la norme d'un vecteur
double Vecteur:: norme() const {
    
    double x(0.0);
    for (size_t i(0) ; i < vec.size() ; ++i) {
        
        x += vec[i]*vec[i];
    }
    return sqrt(x) ;
    
}

//calcul de la norme au carré d'un vecteur
double Vecteur::  norme2() const{
    
    double x(0.0) ;
    for (size_t i(0) ; i < vec.size() ; ++i) {
        
        x += vec[i]*vec[i];
    }
    return x;
}


