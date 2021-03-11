#include <vector>
#include <stdexcept>
#include <iostream>
#include "gaussJordan.h"

using namespace std;

vector<vector<long double>> gaussJordan::trocaColunaI(int n, int i, vector<vector<long double>> C, vector<long double> v) {

  vector<vector<long double>> D (n, vector<long double>(n));

  for (int j = 0; j < n; j++) {
    for (int k = 0; k < n; k++) {
      if (k == i) {
        D[j][k] = v[j];
      } else {
        D[j][k] = C[j][k];
      }
    }
  }

  return D;

}


long double gaussJordan::calculaDeterminante(int n, vector<vector<long double>> C) {

  long double det = 1;
  long double pivot;

  for (int k = 0; k <= n-1; k++) {
    if (C[k][k] == 0) {
      throw "C[k][k] igual a 0."s;
    }
    for (int i = 0; i <= n-1; i++) {
      if (i != k) {
        for (int j = k+1; j <= n-1; j++) {   
          C[i][j] -= C[i][k]*C[k][j]/C[k][k];
        }
        C[i][k] = 0;
      }
    }
    det *= C[k][k];
  }

  return det;

}

vector<long double> gaussJordan::calculaD(int n, vector<vector<long double>> C, vector<long double> v) {

  vector<long double> d (3,0);
  long double detC = calculaDeterminante(n, C);

  for (int i = 0; i < n; i++) {
    d[i] = calculaDeterminante(n, trocaColunaI(n, i, C, v))/detC;
  }

  return d;

}