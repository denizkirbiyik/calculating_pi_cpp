//g++ pi_leibniz.cpp -o pi_leibniz -lgmpxx -lgmp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;

double recip(int x){
  return ((pow(-1, x))/(2*x+1));
}

int main() {
  int iter = 0;
  mpf_class leibniz = 1;
  cout << "How many iterations of the series do you want to compute? : ";
  cin >> iter;
  int prec = 0;
  cout << "How many digits would you like to compute for each calculation : ";
  cin >> prec;
  mpf_set_default_prec(prec);
  mpf_class pi = 0;
  mpf_init2(pi.get_mpf_t(), prec);
  for (int i = 1;i < iter;i++){
    leibniz += recip(i);
  }
  cout << setprecision(prec) << (leibniz*4) << endl;
  return 0;
}
