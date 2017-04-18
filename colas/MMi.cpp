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

float cost(int m, float l, float w, float Cs, float Cw){
  return (Cs*m) + (l*w*Cw);
}

float single(float l, float u){
  cout << "\n\tl =" << l<< "; u = " << u << endl;
  float w = 1/(u-l);
  cout << "\tL = " << l/(u-l) << endl;
  cout << "\tW = " << w << endl;
  cout << "\tLq = " << l*l/(u*(u-l)) << endl;
  cout << "\tWq = " << l/(u*(u-l)) << endl;
  cout << "\tp = " << l/u << endl;
  cout << "\tp0 = " << 1- (l/u) << endl;
  return w;
}

void single_eval(float l, float u){
  int option;
  float min_cost;
  float temp_cost;
  float Cs, Cw;
  cout << "Cost of one clerk: " << endl;
  cin >> Cs;
  cout << "Cost of Wait: " << endl;
  cin >> Cw;
  int k = 1;
  cout << "How many clerks? (0 to calculate better option.) ";
  cin >> option;
  switch (option) {
    case 0:
      while(u*k < l)
        k++;
      cout << "Minimum number of clerks: " << k << endl;
      min_cost = cost(k, l, single(l, u*k), Cs, Cw);
      k++;
      while (cost(k, l, single(l, u*k), Cs, Cw) < min_cost) {
        min_cost = cost(k, l, single(l, u*k), Cs, Cw);
        cout << "K => " << k << '\t';
        cout << "\tCost =" <<  min_cost << "\n";
        k++;
      }
      cout << "\nMin cost = " << min_cost << " for k = " << k-1 << endl << endl;
      break;
    default:
      cout << "Cost for " << option << " clerks = " << cost(option, l, single(l, u*option), Cs, Cw) << ".\n";
      break;
  }
}

void multiple(int m, float l, float u){
  float p = Po(m,l,u);
  float L = ((l*u*pow(l/u,m)) / (fact(m-1)*(m*u-l)*(m*u-l)))*p + (l/u);

  cout << "L= " << L << endl;
  cout << "W= " << L/l << endl;
  cout << "Lq= " << L - (l/u) << endl;
  cout << "Wq= " << (L/l) - (1/u) << endl;
  cout << "p= " << l / (m*u) << endl;
  cout << "p0= " << Po(m,l,u) << endl;
}

void multiple_eval(m, l, u){
  cout << "Multiple eval:\n";
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
    //while (1){
        cout << "servers" << endl;
        cin >> m;
        switch (m) {
          case 0:
            all_eval(l, u);
            break;
          case 1:
            single_eval(l,u);
            break;
          default:
            multiple(m, l, u);
            break;
        }

    //}

    return 1;
}
