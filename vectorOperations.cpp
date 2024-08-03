#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;

void enterValues(vector<double>& v, int dim);
int dimensionOfVector(string dimension);

int main() {
    string dimension;
    int dim =3;
    int opertation;


/*     cout << "########## Operations on vertors ##########" << '\n';
    cout << "What's dimension are the vectors ? (2D /3D):" << '\n';
    do{
        cin >> dimension;
    }while ((dimension != "2D" && dimension != "3D") && (dimension != "2d" && dimension != "3d"));
    cout << "What operation do you want to perform ?" << '\n';
    cout << "1. Norm" << '\n' << "2. Saclar product" << '\n' << "3. Vectorial product (only for 3D) " << '\n';
    do{
        cin >> opertation;
    }while((opertation !=1 && opertation !=2 && opertation !=3) || (dimension == "2D" && opertation == 3)); */

    vector<double> v1;
    enterValues(v1, dim);
    
    for(int i=0; i<dim; i++){
        cout << v1[i] << " ";
    }

    return 0;
}

int dimensionOfVector(string dimension){
    return stoi(dimension);
}

void enterValues(vector<double>& v, int dim){ //enter values of the vector
    for(int i=0; i<dim; i++){
        double x;
        cin >> x;
        v.push_back(x);
    }
}


