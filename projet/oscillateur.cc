#include <iostream>
#include <vector>
#include <cmath>
#include "oscillateur.h"

using namespace std;



// constructeur initialisant les attributs à 0
Oscillateur::Oscillateur () :
p(1), v(1), L(0), m(0), lambda(0), g(0)
{}

Oscillateur::Oscillateur ( Vecteur r, Vecteur o, double l, double k, double lam, double gr) :
p(r),v(o),L(l), m(k),lambda(lam), g(gr)
{}


double Oscillateur::getlambda() const{
    return lambda;
}

double Oscillateur::getmasse () const{
    return m;
}

double Oscillateur::getLongeur() const {
    return L;
}

double Oscillateur::getg() const {
    return g;
}

Vecteur Oscillateur::getvec()const  {
    return p;
}

Vecteur Oscillateur::getvit()const  {
    return v;
}

void Oscillateur::setlambda(double l) {
    lambda = l;
}

void Oscillateur::setmasse(double ma){
    m = ma;
}

void Oscillateur::setlongeur (double lo) {
    L = lo;
}

void Oscillateur::setg(double g1){
    g = g1;
}




/*Vecteur Oscillateur::evolution  (double t) const
 {
 
 return (-g/L*sin(p) -lambda/(m *(L*L))*v);
 
 
 }
 */



ostream& operator<< (ostream& sortie , Oscillateur const& o) {
    sortie << "#Oscillateur" << endl;
    for (size_t i(0) ; i < o.getvec().getdim() ; ++i) {
        sortie << o.getvec().getcoord(i);
    }
    sortie << "#parametres" << endl;
    for (size_t i(0) ; i < o.getvit().getdim() ; ++i) {
        sortie << o.getvit().getcoord(i);
    }
    sortie << "#vitesse"<< endl;
    return sortie;
}





