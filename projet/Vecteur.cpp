//
//  main.cpp
//  vecteur
//
//  Created by  Jeannette Gommendy on 02/03/2018.
//  Copyright © 2018  Jeannette Gommendy. All rights reserved.
//
tdthfdffwttfygh
huhijoFDFGF

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Vecteur.h"

using namespace std ;

typedef vector<double> coord ;


Vecteur (int dim )
    
    
:  for (size_t i (0);i < dim;++1) {
        
        vec.push_back(0);
    
    
    {
}

    Vecteur ( double n,double p, double t) :
    
    vec.push_back(n);
    vec.push_back(p);
    vec.push_back(t);
    
    {}
    
    Vecteur (coord a ) :
    dim = a.size();
    for (size_t i (0);i < a.size();++1) {
        vec [i]= a [i];
        
    }
    {}
    
    
    
    
    //ajouter une dimension au vecteur et une valeur pour cette dimension
void Vecteur:: augmente  (double x) {
        
        dim += 1 ;
        vec.push_back(x);
        
    }
   
    //modifier la valeur d'une coordonnée du vecteur
   void Vecteur::  set_coord ( int w, double d) {
       
        
        if (w < vec.size() ) {
            
          vec [w] = d ;
            
        } else {
            
            cout << "impossible cette coordonnée n'existe pas" << endl;
        }
    }
    
    //affichage sur «cout» d'un objet Vecteur
    void Vecteur:: affiche () const {
        
        for (auto el : vec) {
            
            cout << el << " "  ;
            
        } 
    }
    
    //tester l'égalité de l'objet Vecteur courant à un autre objet similaire
    bool Vecteur:: compare  (Vecteur b) const {
        
        if (vec.size() == b.vec.size() ) {
            
          
                
            for (size_t i(0); i < vec.size(); ++i){
                    
                if (vec[i] != b.vec[i]) {
                        
                        //cout <<" les deux vecteurs ne sont pas  identiques" <<endl;
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
        c.vec.push_back( vec[0]*b.vec[1] - vec[1]*b.vec[0]);
    
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
            

    
