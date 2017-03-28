#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

ifstream r_file;
ofstream w_file;
int i, l, N, M;

vector<float> floatFile(){
  vector<float> vf;
  string line;
  getline(r_file, line);
  while (getline(r_file, line)){
    vf.push_back(stof(line.substr(line.find(",")+1)));
  }
  return vf;
}

float desviacion(){
  float desv = (sqrt((13*M)+7))/(12*(M+1));
  return desv;
}

float pil(vector<float> v){
  float temp = v.at(i-1);
  float res = 0.0;
  for(int it = (i-1)+l; it < v.size(); it += l){
    //cout << "valor: " << v.at(it) << endl;
    res += temp * v.at(it);
    temp = v.at(it);
  }
  res = ((res)/(M+1)) - 0.25;
  return res;
}


int main(int argc, char* argv[]){
    cout << "./corr i l\n";
  i = (argc > 1)? atoi(argv[1]) : 3;
  l = (argc > 2)? atoi(argv[2]) : 5;
  r_file.open("floats.csv", ifstream::in);
  vector<float> v = floatFile();
  N = v.size();
  M = ((float)(N-(i+l)))/l;
  float d = desviacion();
  float p = pil(v);
  float z = p/d;
  cout << "i = " << i << "\nM = " << M << "\nl = " << l << "\nN = " << N << endl;
  cout << "\nDesviacion = " << d << endl;
  cout << "pil = " << p << endl;
  cout << "Z0 = " << z << endl;
  return 1;
}
