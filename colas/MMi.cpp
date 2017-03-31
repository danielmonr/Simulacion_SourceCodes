#include <iostream>
#include <cmath>

using namespace std;

float fact(int n){
  return (n <= 1)? 1: n*fact(n-1);
}

float Po(int m, float l, float u){
  float res;
  float power = pow(l/u, m);
  float sum = 0;
  for (int i = 0; i < m; ++i){
    sum += (1/(fact(i)))*(pow((l/u), i));
  }
  res =((1/fact(m))*power*(m*u/(m*u-l)));
  res = res +sum;
  return 1/res;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Parameters arrivals units_served\n";
        exit(0);
    }
    float l, u;
    l = atof(argv[1]);
    u = atof(argv[2]);

    cout << "l = " << l << endl;
    cout << "u = " << u << endl;

    int m;
    while (1){
        cout << "servers" << endl;
        cin >> m;
        float p = Po(m,l,u);
        float L = ((l*u*pow(l/u,m)) / (fact(m-1)*(m*u-l)*(m*u-l)))*p + (l/u);

        cout << "L= " << L << endl;
        cout << "W= " << L/l << endl;
        cout << "Lq= " << L - (l/u) << endl;
        cout << "Wq= " << (L/l) - (1/u) << endl;
        cout << "p= " << l / (m*u) << endl;
        cout << "p0= " << Po(m,l,u) << endl;
    }

    return 1;
}
