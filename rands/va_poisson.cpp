#include <utility>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int l = 1;
int m = 1;
double eval;

ifstream r_file;
ofstream w_file;
ofstream w_file2;

double read(string line){
  return (stof(line.substr(line.find_first_of(",")+1)));
}

bool eval_linea(double i, double p){
  return ((p*i) < eval);
}

void evaluar(){
  int n = 0;
  double p = 1;
  string line;
  int cont = 0;
  while(getline(r_file, line)){
    double temp = read(line);
    w_file << n << "," << temp << ","<< p << "," << p*temp;
    if(eval_linea(temp, p)){
      w_file << ",A," << n << "\n";
      w_file2 << cont << "," << n << "\n";
      p = 1;
      n = 0;
      cont++;
    }
    else{
      w_file << ",R,0\n";
      p *= temp;
      n++;
    }
  }

}


int main(int argc, char* argv[]){
  int jumps;

  cout << "Ingrese lambda: ";
  cin >> l;
  cout << "Saltar cuantas lineas? ";
  cin >> jumps;

  r_file.open("floats.csv", ifstream::in);
  w_file.open("poisson.csv");
  w_file2.open("poisson_res.csv");
  w_file << "n,X,p,product,desicion,N\n";
  w_file2 << "it,arrivals\n";
  for(int i = 0; i <= jumps; ++i){
    string line;
    getline(r_file, line);
  }
  eval = exp(-l);
  evaluar();

  return 1;
}
