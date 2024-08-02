#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;

class Vector{
    
}

int main() {
    string dimension;
    int opertation;


    cout << "########## Operations on vertors ##########" << '\n';
    cout << "What's dimension are the vectors ? (2D/3D):" << '\n';
    do{
        cin >> dimension;
    }while (dimension != "2D" && dimension != "3D");
    cout << "What operation do you want to perform ?" << '\n';
    cout << "1. Norm" << '\n' << "2. Saclar product" << '\n' << "3. Vectorial product (only for 3D) " << '\n';
    do{
        cin >> opertation;
    }while(opertation !=1 && opertation !=2 && opertation !=3 || (dimension == "2D" && opertation == 3));

    return 0;
}

