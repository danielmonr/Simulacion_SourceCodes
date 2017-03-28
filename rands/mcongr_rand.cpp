#include <iostream>
#include <fstream>
#include <utility>


using namespace std;

ofstream w_file;
ifstream r_file;
int found = -1;
unsigned long root;
unsigned long coef;
unsigned long cons;
unsigned long mod;

unsigned long operation(unsigned long x){
  float divi = (coef*x + cons) / mod;
  //cout << "x:" << x << " a: " << coef << " c:" << cons << " m:" << mod <<" | " << divi << endl;
  return (coef*x + cons) % mod;
}

pair<int, unsigned long> readCSVLine(string line){
  pair<int, unsigned long> p;
  //cout << "entro";
  p.first = stoi(line.substr(0, line.find_first_of(",")));
  //cout << line.substr(line.find(", ")+2);
  p.second = stol(line.substr(line.find(", ")+2));
  return p;
}

int search(unsigned long n){
  //cout << "uhm";
  w_file.close();
  r_file.open("numbers.csv", ifstream::in);
  string line;
  pair<int, unsigned long> p;
  getline(r_file,line);
  //cout << "empezando while.\n";
  while(getline(r_file, line)){
    //cout << "linea: " << line << endl;
    p = readCSVLine(line);
    //cout << "leido: p.1: " << p.first << " | p.2: " << p.second << endl;
    if (n == p.second){
      //cout << "n:" << n << "p" << p.second << endl;
      //cout << "encontrado.\n";
      r_file.close();
      w_file.open("numbers.csv", ofstream::out | ofstream::app);
      return p.first;
    }
    //cout << "no encontrado.\n";
  }
  //cout << "else" << endl;
  r_file.close();
  w_file.open("numbers.csv", ofstream::out | ofstream::app);
  return -1;
}

int main(int argc, char* argv[]){
  cout << "expression: X0 a c m" << endl;
  root = (argc > 1)? atol(argv[1]) : 4;
  coef = (argc > 2)? atol(argv[2]) : 5;
  cons = (argc > 3)? atol(argv[3]) : 7;
  mod = (argc > 4)? atol(argv[4]) : 8;

  if(root >= mod || coef >= mod || mod < 0 || cons >= mod){
    cout << "Requisits not met.\n";
    return 0;
  }

  w_file.open("numbers.csv", ofstream::out | ofstream::trunc);
  w_file << "it, number\n";
  w_file << "0, " << root << "\n";
  ofstream f_file;
  f_file.open("floats.csv", ofstream::out | ofstream::trunc);
  f_file << "it,number\n";

  int cont = 1;
  unsigned long temp = root;


  while (found < 0){
    temp = operation(temp);
    found = search(temp);
    w_file << cont << ", " << temp << '\n';
    f_file << cont << "," << ((float)temp) / ((float)mod) << "\n";
    cont++;
  }

  cout << "Last number: " << temp << ";\nFisrt appearance: " << found << endl;
  cout << "Period: " << cont-found-1 << endl;
  /*
  string test = "12, 12345678912345";
  pair<int, unsigned long> ptest = readCSVLine(test);
  cout << "test 1: " << ptest.first << " | 2: " << ptest.second << endl;*/

  return 0;
}
