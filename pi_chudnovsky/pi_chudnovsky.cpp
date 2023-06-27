//g++ pi_chudnovsky.cpp -o pi_chudnovsky -lgmpxx -lgmp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;

mpf_class sqrt_10005(int itera){
  mpf_class sqrta = 1;
    for (int i = 1;i < itera;i++){
        sqrta = (sqrta/2 + 10005/(2*sqrta));
    }
    return (sqrta);
}

mpf_class fac(unsigned long int infac) {
  mpf_class prod = 1;
  if (infac == 0 || infac == 1) {return 1;}
  for (mpz_class i = 1;i<(infac+1);i++){
    prod *= i;
  }
  return prod;
}

mpf_class sum_func(int q) {
  unsigned long int q_value = q;
  mpf_class numerator = fac(6*q_value) * (545140134*q_value + 13591409);
  mpf_class denominator = fac(3*q_value) * fac(q_value) * fac(q_value) * fac(q_value);
  mpz_class k = 262537412640768000;
  mpz_class x;
  if (denominator == 0) {
    return 0;
  }
  
  mpf_class y = numerator / denominator;
  mpz_pow_ui(x.get_mpz_t(), k.get_mpz_t(), q_value);
  y /= x;
  return y;
}

int main() {
  int iter = 0;
  cout << "How many iterations of the algorithm do you want to compute? : ";
  cin >> iter;
  int prec = 0;
  cout << "How many binary digits would you like to compute for each calculation : ";
  cin >> prec;
  mpf_set_default_prec(2*prec);
  mpf_class s = 0;
  mpf_init2(s.get_mpf_t(), 2*prec); 
  for (int j = 0;j<iter;j++) {
    mpf_class term = sum_func(j);
    if(j%2==1){
      s -= term;
    }
    else{
      s += term;
    }
  }
  mpf_class c = 426880 * sqrt_10005(iter);
  mpf_class result = c / s;
  cout << setprecision(prec) << result << endl;
  return 0;
} 