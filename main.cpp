#include <iostream>
#include <vector>
#include "gaussJordan.h"

using namespace std;

int main() {

  vector<vector<long double>> A = {{10,1,1},{1,10,1},{1,1,10}};
  vector<long double> b = {12,12,12};
  vector<long double> x;

  try {
    x = gaussJordan::calculaD(3, A, b);
    for (int i = 0; i <= 2; i++) {
      cout << x[i] << "\n";
    }
    cout << "\n";
  } catch (string s) {
    cout << s;
  }

}