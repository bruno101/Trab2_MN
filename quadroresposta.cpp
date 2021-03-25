#include <iostream>
#include <vector>
#include "quadroresposta.h"
using namespace std;

void QuadroRespostaGauss(int n, vector<long double> dGauss, vector<long double> aGauss, bool excecaoGauss){
	cout << "\n---- MÉTODOS DE GAUSS ----\n" << endl;
    if(excecaoGauss){
      cout << "Houve exceção, uma divisão por zero." << endl;
    } else {
      cout << "Deslocamentos: " << "d = (";
      for(int i = 0; i < n;  i++){
        if(i == n - 1){
          cout << dGauss[i] << ")";
        } else{
          cout << dGauss[i] << ", ";
        }
      }
      cout << endl;
      cout << "Amplitudes = (";
      for(int i = 0; i < n;  i++){
        if(i == n - 1){
          cout << aGauss[i] << ")";
        } else {
           cout << aGauss[i] << ", ";
        }
      }
      cout << endl;
    }
}

void QuadroRespostaGaussJordan(int n, vector<long double> dGaussJordan, vector<long double> aGaussJordan, bool excecaoGaussJordan){
	cout << "\n---- MÉTODOS DE GAUSS-JORDAN ----\n" << endl;
    if(excecaoGaussJordan){
      cout << "Houve exceção, uma divisão por zero." << endl;
    } else {
      cout << "Deslocamentos: " << "d = (";
      for(int i = 0; i < n;  i++){
        if(i == n - 1){
          cout << dGaussJordan[i] << ")";
        } else {
           cout << dGaussJordan[i] << ", ";
        }
      }
      cout << endl;
      cout << "Amplitudes = (";
      for(int i = 0; i < n;  i++){
        if(i == n - 1){
          cout << aGaussJordan[i] << ")";
        } else {
          cout << aGaussJordan[i] << ", ";
        }
      }
      cout << endl << endl;
    }
}