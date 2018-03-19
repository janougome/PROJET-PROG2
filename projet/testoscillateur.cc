#include <iostream>

#include "oscillateur.h"

using namespace std;

int main ()
{
    Oscillateur o(Vecteur ({1.0,2.0}), Vecteur({3.0,4.0}), 1.0,1.0, 1.0,1.0);
    cout << o << endl;
    
    return 0;
}


