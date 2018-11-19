#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
  double R1, P1, R2, P2, R, P;
  cin >> R1 >> P1 >> R2 >> P2;
  R = R1*R2;
  P = P1+P2;
  
  double A, B;
  A = R*cos(P);
  B = R*sin(P);
  cout.setf(ios::fixed);
  cout << setprecision(2);

  if(A<0 && A>-0.005) A = 0.0;
  if(B<0 && B>-0.005) B = 0.0;
  if(B<=-0.005)
    cout << A << B << 'i' << endl;
  else
    cout << A << '+' << B << 'i' << endl;
  
  return 0;
}
