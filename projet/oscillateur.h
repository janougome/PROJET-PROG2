
#pragma once
#include <vector>
#include <iostream>
#include "Vecteur.h"
#include <cmath>
class Oscillateur {
    
    private :
    
    Vecteur p;
    
    Vecteur v;
    
    double L;
    
    double m;
    
    double lambda;
    
    double g;
    
    
    public :
    
    Oscillateur ();
    
    Oscillateur ( Vecteur r, Vecteur o, double l, double k, double lam, double gr);
    
    ~Oscillateur() ;
    
    
    double getlambda() const ;
    
    
    double getmasse () const;
    
    double getLongeur() const;
    
    
    double getg() const ;
    
    
    
    Vecteur getvec()const;
    
    
    Vecteur getvit()const;
    
    void setlambda(double l);
    
    void setmasse(double ma);
    
    
    void setlongeur (double lo);
    
    
    void setg(double g1);
    
    
    
    
    /*Vecteur evolution  (double t) const;*/
    
    
    
    
};

std::ostream& operator<< (std::ostream& sortie , Oscillateur const& o);






