//g++ pi_basel.cpp -o pi_basel -lgmpxx -lgmp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;

mpf_class recipsq(int x){
  return (1/(pow(x, 2)));
}
 
int main() {
  int iter = 0;
  cout << "How many iterations of the series do you want to compute? : ";
  cin >> iter;
  int prec = 0;
  cout << "How many digits would you like to compute for each calculation : ";
  cin >> prec;
  mpf_set_default_prec(2*prec);
  mpf_class basel = 0;
  mpf_init2(basel.get_mpf_t(), 2*prec); 
  for (int i = 1;i < iter;i++){
    basel += recipsq(i);
  }
  cout << setprecision(prec) << sqrt(basel*6) << endl;
  return 0;
} 