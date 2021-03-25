#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <vector>
#include "gauss.h"

using namespace std;





long double gauss::calculaDeterminante(int n, vector<vector<long double>> C){
  for (int k = 0; k<(n-1) ; k++){
    for (int i = k+1; i<n; i++){
      if (C[k][k] == 0){
        throw "Divisao por zero."s;
      }
      long double m = -(C[i][k]/C[k][k]);
      C[i][k] = 0;
      for (int j = k+1; j<n; j++){
        C[i][j] += m*(C[k][j]);
      }
      
      
    }
  }

  /*for (int i = 0; i<n; i++){
    for (int j = 0; j<n; j++){
      cout << C[i][j];
      cout << " ";
    }
  }*/

  
  long double result = 1.0;
  for (int i = 0; i<n; i++){
    result *= C[i][i];
  }

  return result;

}



vector<long double> gauss::calculaD(int n, vector<vector<long double>> C, vector<long double> v){
  long double detC = calculaDeterminante(n, C);
  vector<long double> x(n);

  for (int i = 0; i<n; i++){

    vector<vector<long double>> D(n, vector<long double>(n));
    for (int j = 0; j<n; j++){

      for (int k = 0; k<n; k++){
        if (k!=i){
          D[j][k] = C[j][k];
        }else{
          D[j][k] = v[j];
        }
      }

    }

    x[i] = (calculaDeterminante(n, D))/(detC);

  }

  return x;
  
}