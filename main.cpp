#include <iostream>
#include <vector>
#include "gauss.h"
#include "gaussJordan.h"
#include "quadroresposta.h"

using namespace std;

int main() {


  

  int n;
  long double a;


  while(1){
    cout<<"Digite o valor de n: ";
    cin >> n;
    cout<<"Digite o valor de a: ";
    cin >> a;

    vector<vector<long double>> C(n, vector<long double>(n));

    for (int i = 0; i<n; i++){
      for (int j = 0; j<n; j++){
        cout << "Digite o valor do termo C[" << i << "][" << j << "]: ";
        cin >> C[i][j];
      }
    }

    vector<long double> v(n);

    for (int i = 0; i<n; i++){
      cout << "Digite o valor do termo v[" << i << "]: ";
      cin >> v[i];
    }


    vector<long double> dGauss(n);
    vector<long double> aGauss(n);
    bool excecaoGauss;

    vector<long double> dGaussJordan(n);
    vector<long double> aGaussJordan(n);
    bool excecaoGaussJordan;

    try{

      dGauss = gauss::calculaD(n, C, v);
      excecaoGauss = 0;
      for (int i = 0; i<n; i++){
        aGauss[i] = dGauss[i]*a;
        cout << aGauss[i];
        cout << " ";
      }

    }catch(string s){
      excecaoGauss = 1;
    }

    try{

      dGaussJordan = gaussJordan::calculaD(n, C, v);
      excecaoGaussJordan = 0;
      for (int i = 0; i<n; i++){
        aGaussJordan[i] = dGaussJordan[i]*a;
      }

    }catch(string s){
      excecaoGaussJordan = 1;
    }


    

    cout << "\n";

/*imprimir as respostas
vetor dGauss tem os valores de d para o metodo de Gauss normal
vetor aGauss tem os valores das amplitudes
vetor dGaussJordan tem os valores de d para o metodo de gaussJordan
vetor aGaussJordan tem os valores das amplitudes para o metodo de GaussJordan

o booleano excecaoGauss diz se houve uma execao no metodo de Gauss normal
o booleano excecaoGaussJordan diz se houve uma execao no metodo de GaussJordan*/

    QuadroRespostaGauss(n, dGauss, aGauss, excecaoGauss);

    QuadroRespostaGaussJordan(n, dGaussJordan, aGaussJordan, excecaoGaussJordan);


    int res; 

    cout << "Voce deseja testar o metodo com outros valores? (1)SIM (2)NAO ";
    cin >> res;
    if (res == 2){
      break;
    }

    cout << "\n";
  }


  

}