#include <fstream>
#include <utility>
#include <vector>
#include <iostream>
#include "test.h"

using namespace std;

string file;
ifstream r_file;

vector<float> floatFile(){
  vector<float> vf;
  string line;
  getline(r_file, line);
  while (getline(r_file, line)){
    vf.push_back(stof(line.substr(line.find(",")+1)));
  }
  return vf;
}

vector<long> longFile(){
  vector<long> vl;
  string line;
  getline(r_file, line);
  while (getline(r_file, line)){
    vl.push_back(stol(line.substr(line.find(", ")+2)));
  }
  return vl;
}

int main(int argc, char* argv[]){
  file = (argc>1)? string(argv[1]) : "floats.csv";
  r_file.open(file, ifstream::in);
  vector<float> v = floatFile();
  Test<float>::test(v);
  return 0;
}
