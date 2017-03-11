#include <iostream>
#include <string>
#include <fstream>
#include <utility>

#define MAX_N 15

using namespace std;

long rootn;
int N;
int found = 0;
ofstream w_file;
ifstream r_file;

long truncate(long num){
  //cout << "num: " << num << " => " << to_string(num).length() << endl;
  if(to_string(num).length() <= N)
    return num;

  string s = to_string(num);
  s = (s.length()%2 == 0)? s.substr(1, s.length()-2) : s.substr(0, s.length()-1);
  return truncate(stol(s));
}

long generate(long num){
  long r = num*num;
  return truncate(r);
}

pair<int, long> readCSVLine(string line){
  pair<int, long> p;
  //cout << "entro";
  p.first = stoi(line.substr(0, line.find_first_of(",")));
  //cout << line.substr(line.find(", ")+2);
  p.second = stol(line.substr(line.find(", ")+2));
  return p;
}

int search(long n){
  //cout << "uhm";
  w_file.close();
  r_file.open("numbers.csv", ifstream::in);
  string line;
  pair<int, long> p;
  getline(r_file,line);
  while(getline(r_file, line)){
    p = readCSVLine(line);
    if (n == p.second){
      //cout << "n:" << n << "p" << p.second << endl;
      r_file.close();
      w_file.open("numbers.csv", ofstream::out | ofstream::app);
      return p.first;
    }
  }
  //cout << "else" << endl;
  r_file.close();
  w_file.open("numbers.csv", ofstream::out | ofstream::app);
  return 0;
}

int main(int argc, char* argv[]){
  rootn = (argc > 1)? atol(argv[1]) : 5497;
  cout << "root:" << rootn << endl;
  N = to_string(rootn).length();
  cout << "N:" << N << endl;
  long n_num = rootn;
  int cont = 0;
  w_file.open("numbers.csv", ofstream::out | ofstream::trunc);
  w_file << "it, number\n";
  w_file << "0, " << n_num << "\n";
  while(found == 0){
    cont++;
    n_num = generate(n_num);
    found = search(n_num);
    w_file << cont << ", " << n_num << "\n";
  }

  cout << "Last number: " << n_num << ";\nFisrt appearance: " << found << endl;
  cout << "Period: " << cont-found << endl;
  return 1;
}
