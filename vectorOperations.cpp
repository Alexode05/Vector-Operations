#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
using namespace std;


int dimensionOfVector(string dimension);
void enterVects(vector<double>& v1, vector<double>& v2, int dim);
void enterValues(vector<double>& v, int dim);

double norm(vector<double>& v);
double dotProduct(vector<double>& v1, vector<double>& v2, int dim);
vector<double> crossProduct(vector<double>& v1, vector<double>& v2);
double angleBtwVects(vector<double>& v1, vector<double>& v2, int dim);
double aera2D(vector<double>& v1, vector<double>& v2);
/* double aera3D(vector<double>& v1, vector<double>& v2);
 */
int main() {
    string dimension;
    int dim;;
    int operation;
    vector<double> v1, v2, v3;
    const  double PI = 3.14159265358979323846;

    cout << "########## Operations on vertors ##########" << '\n';
    while(true){
        cout << "What's dimension are the vectors ? (2D /3D):" << '\n';
        do{
            cin >> dimension;
        }while ((dimension != "2D" && dimension != "3D") && (dimension != "2d" && dimension != "3d"));

        cout << "What operation do you want to perform ?" << '\n';
        cout << "1. Norm" << '\n' 
            << "2. Saclar product" << '\n' 
            << "3. Vectorial product (only in 3D) " << '\n'
            << "4. Angle between 2 vectors " << '\n'
            << "5. Area of the parallelogram built on 2 vectors " << '\n'
            << "6. Volume of the parallelepiped built on 3 vectors" << '\n';
        do{
            cin >> operation;
        }while((operation !=1 && operation !=2 && operation !=3 && operation !=4 && operation !=5 && operation !=6)
                || (dimension == "2D" && operation == 3) || (dimension == "2d" && operation == 3));

        dim = dimensionOfVector(dimension);
        switch (operation){
        case 1:
            cout << "Enter the values of the vector" << '\n';
            enterValues(v1, dim);

            cout << "The norm of the vector is: " << norm(v1) << '\n';
            break;
        
        case 2:
            enterVects(v1, v2, dim);

            cout << "The scalar product is: " <<  dotProduct(v1, v2, dim) <<  '\n';
            break;

        case 3:
            enterVects(v1, v2, dim);
            
            cout << "The vectorial product is: " << '\n';
            for(double value : crossProduct(v1, v2)){
                cout << "|" <<  value << "|" << '\n';
            }

            break;
        
        case 4:
            enterVects(v1, v2, dim);

            cout << "The angle between the 2 vectors is: "  << '\n';
            cout << "Rad:   " << angleBtwVects(v1, v2, dim) << '\n'
                << "Deg:    " << angleBtwVects(v1, v2, dim) * 180 / PI << '\n';
            break;
        
        case 5:
            enterVects(v1, v2, dim);
            if(dim == 2){
                cout << "The area of the parallelogram built on the 2 vectors is: " << aera2D(v1, v2) << '\n';
            }else{
/*                 cout << "The area of the parallelogram built on the 2 vectors is: " << aera3D(v1, v2) << '\n';
 */            }
            break; 

        case 6:
            break;
        default:
            break;
        }

        dim = 0;
        operation = 0;
        v1.clear();
        v2.clear(); 
        v3.clear();
    }

    return 0;
}

int dimensionOfVector(string dimension){
    return stoi(dimension);
}

void enterVects(vector<double>& v1, vector<double>& v2, int dim){
    cout << "Enter the values of the  1st vector: v1 =" << '\n';
    enterValues(v1, dim);
    cout << "Enter the values of the  2nd vector: v2 =" << '\n';
    enterValues(v2, dim);
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

double angleBtwVects(vector<double>& v1, vector<double>& v2, int dim){
    double cos_a = dotProduct(v1, v2, dim) / (norm(v1) * norm(v2));
    return acos(cos_a);
}

double aera2D(vector<double>& v1, vector<double>& v2){
    double x =v1[0]*v2[1] - v1[1]*v2[0];
    return abs(x);
}

/* double aera3D(vector<double>& v1, vector<double>& v2){
    return norm(crossProduct(v1, v2));
} */