#include <iostream>
#include <vector>
#include "gaussJordan.h"

using namespace std;

int main() {

  vector<vector<long double>> A = {{20,7,9},{7,30,8},{9,8,30}};
  vector<long double> b = {16,38,38};
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