#include <vector>

using namespace std;

class gaussJordan {

private:
  static vector<vector<long double>> trocaColunaI(int n, int i, vector<vector<long double>> C, vector<long double> v);
  static long double calculaDeterminante(int n, vector<vector<long double>> C);

public:
  static vector<long double> calculaD(int n, vector<vector<long double>> C, vector<long double> v);

};