//
//  testVecteur.cpp
//  vecteur
//
//  Created by  Jeannette Gommendy on 02/03/2018.
//  Copyright © 2018  Jeannette Gommendy. All rights reserved.
//

#include <iostream>

#include "Vecteur.h"

using namespace std ;

int main () {
    

Vecteur vect1;
Vecteur vect2;
Vecteur vect3;

/* Cette partie
 * (1) pourrait être écrite autrement, par exemple avec des
 *     manipulateurs (set_coord) ;
 * (2) sera revue dans 2 semaines (constructeurs, surcharge des opérateurs).
 */
// v1 = (1.0, 2.0, -0.1)
vect1.augmente(1.0); vect1.augmente(0.0); vect1.augmente(-0.1);
vect1.set_coord(1, 2.0); // pour tester set_coord()

// v2 = (2.6, 3.5,  4.1)
vect2.augmente(2.6); vect2.augmente(3.5); vect2.augmente(4.1);

vect3 = vect1;

cout << "Vecteur 1 : ";
vect1.affiche();
cout << endl;

cout << "Vecteur 2 : ";
vect2.affiche();
cout << endl;

cout << "Le vecteur 1 est ";
if (vect1.compare(vect2)) {
    cout << "égal au";
} else {
    cout << "différent du";
}
cout << " vecteur 2," << endl << "et est ";
if (not vect1.compare(vect3)) {
    cout << "différent du";
} else {
    cout << "égal au";
}
cout << " vecteur 3." << endl;


//On test l'operatuer d'addition qui implique le fonctionnement du +=

// addition de deux vecteurs non nuls

cout << "(" ;
vect1.affiche();
cout << ")" << " + " << "(" ;
vect2.affiche();
cout << ")"<< " = " << "(";
vect1.addition(vect2).affiche();
cout << ")"  << endl;


cout << "(" ;
vect2.affiche();
cout << ")" << " + " << "(" ;
vect1.affiche();
cout << ")"<< " = " << "(";
vect2.addition(vect1).affiche();
cout << ")"  << endl;


// addition vecteur nul et non nul
Vecteur nul;
nul.augmente(0.0);
nul.augmente(0.0);
nul.augmente(0.0);

cout << "(" ;
vect1.affiche();
cout << ")" << " + " << "(" ;
nul.affiche();
cout << ")"<< " = " << "(";
vect1.addition(nul).affiche();
cout << ")"  << endl;

// test soustraction 2 vecteurs non nuls

cout << "(" ;
vect1.affiche();
cout << ")" << " - " << "(" ;
vect2.affiche();
cout << ")"<< " = " << "(";
vect1.soustraction(vect2).affiche();
cout << ")"  << endl;

cout << "(" ;
vect2.affiche();
cout << ")" << " - " << "(" ;
vect1.affiche();
cout << ")"<< " = " << "(";
vect2.soustraction(vect1).affiche();
cout << ")"  << endl;


//soustraction vecteur nul et non nul

cout << "(" ;
vect1.affiche();
cout << ")" << " - " << "(" ;
nul.affiche();
cout << ")"<< " = " << "(";
vect1.soustraction(nul).affiche();
cout << ")"  << endl;


// vérification choix pour dimensions diff

Vecteur p;

p.augmente(2.0);
p.augmente(2.0);

cout << "(" ;
vect1.affiche();
cout << ")" << " - " << "(" ;
p.affiche();
cout << ")"<< " = " << "(";
vect1.soustraction(p).affiche();
cout << ")"  << endl;

// ici on additionne un vecteur de dim 3 avec un vecteur de dim 2 donc par convention on aura un vecteur de dimension 3 ( mais on ne sait pas comment est calculée la troisième coordonnée)

cout << "(" ;
p.affiche();
cout << ")" << " - " << "(" ;
vect1.affiche();
cout << ")"<< " = " << "(";
p.soustraction(vect1).affiche();
cout << ")"  << endl;

//ici on additionne un vecteur de dim 2 avec un vecteur de dim 3 donc par convention on aura un vecteur de dimension 2

//test opposé d'un vecteur

vect1.oppose().affiche();
cout<<endl;

// addition opposé égal à soustraction

cout << "(" ;
vect1.affiche() ;
cout << ")" ;
cout << " +  (" ;
vect2.oppose().affiche();
cout << ") =   (" ;
vect1.addition(vect2.oppose()).affiche();
cout << ")" <<endl;

//multiplication par un scalaire (3)

cout <<" 3 * " ;
vect1.affiche();
cout << " = " ;
vect1.mult(3).affiche();
cout << endl;

// produit scalaire entre 2 vecteurs

cout << "(" ;
vect1.affiche();
cout << ")" << " * " << "(" ;
vect2.affiche();
cout << ")"<< " = " << "(";
cout << vect1.prod_scal(vect2);
cout << ")"  << endl;

// produit vectoriel entre 2 vecteurs

cout << "(" ;
vect1.affiche();
cout << ")" << " ^ " << "(" ;
vect2.affiche();
cout << ")"<< " = " << "(";
vect1.prod_vect(vect2).affiche();
cout << ")"  << endl;

// norme au carré de deux vecteurs

cout << "||(1.0, 2.0, -0.1)||^2 = " << vect1.norme2() << endl;
cout << "||(2.6, 3.5, 4.1)||^2 = " << vect2.norme2() << endl;

    return 0 ; }
    

