#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;


int dimensionOfVector(string dimension);
void enterValues(vector<double>& v, int dim);
double norm(vector<double>& v);

int main() {
    string dimension;
    int dim;;
    int operation;
    vector<double> v1, v2;

    cout << "########## Operations on vertors ##########" << '\n';
    cout << "What's dimension are the vectors ? (2D /3D):" << '\n';
    do{
        cin >> dimension;
    }while ((dimension != "2D" && dimension != "3D") && (dimension != "2d" && dimension != "3d"));
    cout << "What operation do you want to perform ?" << '\n';
    cout << "1. Norm" << '\n' << "2. Saclar product" << '\n' << "3. Vectorial product (only for 3D) " << '\n';
    do{
        cin >> operation;
    }while((operation !=1 && operation !=2 && operation !=3) || (dimension == "2D" && operation == 3));

    dim = dimensionOfVector(dimension);

    switch (operation){
    case 1:
        cout << "Enter the values of the vector" << '\n';
        enterValues(v1, dim);
        cout << "The norm of the vector is: " << norm(v1) << '\n';
        break;
    
    default:
        break;
    }
    
    
    /* for(int i=0; i<dim; i++){
        cout << v1[i] << " ";
    } */

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

double norm(vector<double>& v){
    double sum = 0.0;
    for( double value : v){
        sum += value*value;
    }
    return sqrt(sum);
}

