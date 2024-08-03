#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;


int dimensionOfVector(string dimension);
void enterValues(vector<double>& v, int dim);
double norm(vector<double>& v);
double dotProduct(vector<double>& v1, vector<double>& v2, int dim);
vector<double> crossProduct(vector<double>& v1, vector<double>& v2);

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
    
    case 2:
        cout << "Enter the values of the  1st vector: v1 =" << '\n';
        enterValues(v1, dim);
        cout << "Enter the values of the  2nd vector: v2 =" << '\n';
        enterValues(v2, dim);
        cout << "The scalar product is: " <<  dotProduct(v1, v2, dim) <<  '\n';
        break;
    case 3:
        cout << "Enter the values of the  1st vector: v1 =" << '\n';
        enterValues(v1, dim);
        cout << "Enter the values of the  2nd vector: v2 =" << '\n';
        enterValues(v2, dim);
        
        cout << "The vectorial product is: " << '\n';
        for(double value : crossProduct(v1, v2)){
            cout << "|" <<  value << "|" << '\n';
        }
        break;
    default:
        break;
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

double norm(vector<double>& v){
    double sum = 0.0;
    for( double value : v){
        sum += value*value;
    }
    return sqrt(sum);
}

 double dotProduct(vector<double>& v1, vector<double>& v2, int dim){
    double sum = 0.0;
    for(int i=0; i<dim; i++){
        sum += (v1[i] * v2[i]);
    }
    return sum;
}

vector<double> crossProduct(vector<double>& a, vector<double>& b){
    vector<double> result;
    result.push_back(a[1]*b[2] - a[2]*b[1]);
    result.push_back(a[2]*b[0] - a[0]*b[2]);
    result.push_back(a[0]*b[1] - a[1]*b[0]);
    return result;
}