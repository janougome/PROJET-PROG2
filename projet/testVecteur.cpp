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
    
    
    
    
    // test avec les opérateurs
    
    // un vecteur en 3D :
    Vecteur v1(1.0, 2.0, -0.1);
    
    // un autre vecteur en 3D
    Vecteur v2(2.6, 3.5,  4.1);
    
    Vecteur v3(v1);  // copie de V1
    Vecteur v4(4);      // le vecteur nul en 4D
    
    cout << "Vecteur 1 : " << v1 << endl;
    cout << "Vecteur 2 : " << v2 << endl;
    cout << "Vecteur 4 : " << v4 << endl;
    
    cout << "Le vecteur 1 est ";
    if (v1 == v2) {
        cout << "égal au";
    } else {
        cout << "différent du";
    }
    cout << " vecteur 2," << endl << "et est ";
    if (v1 != v3) {
        cout << "différent du";
    } else {
        cout << "égal au";
    }
    cout << " vecteur 3." << endl;
    
    
    //On test l'operatuer d'addition qui implique le fonctionnement du +=
    
    
    
    
    
    
    
    
    // addition dans les deux sde deux vecteurs non nuls
    
    cout << v1 + v2 <<endl;
    
    
    
    cout <<v2+v1 << endl;
    
    
    
    
    // addition vecteur nul et non nul
    Vecteur nul (3);
    
    
    cout << v1 + nul << endl;
    
    
    
    // test soustraction 2 vecteurs non nuls
    
    cout << v1-v2 << endl;
    
    
    cout << v2-v1 << endl;
    
    
    
    //soustraction vecteur nul et non nul
    
    cout << v1-nul << endl;
    
    // vérification choix pour dimensions diff
    
    Vecteur p;
    
    p.augmente(2.0);
    p.augmente(2.0);
    cout << "p:" << p <<endl;
    
    cout << v1-p << endl;
    cout << p-v1 << endl;
    
    
    // ici on additionne un vecteur de dim 3 avec un vecteur de dim 2 donc par convention on aura un vecteur de dimension 2
    
    cout << p+v1 << endl;
    cout << v1+p << endl;
    
    //ici on additionne un vecteur de dim 2 avec un vecteur de dim 3 donc par convention on aura un vecteur de dimension 2
    
    //test opposé d'un vecteur
    
    cout << -v1 << endl;
    
    // addition opposé égal à soustraction
    
    
    
    //multiplication par un scalaire (3)
    
    cout << 3*v1 << endl;
    
    // produit scalaire entre 2 vecteurs
    
    cout << (v1^v2) << endl;
    
    // produit vectoriel entre 2 vecteurs
    
    cout << (v2^v1) << endl;
    
    // norme au carré de deux vecteurs
    
    cout << "||(1.0, 2.0, -0.1)||^2 = " << v1.norme2() << endl;
    cout << "||(2.6, 3.5, 4.1)||^2 = " << v2.norme2() << endl;
    
    
    return 0 ; }
