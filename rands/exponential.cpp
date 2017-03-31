#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

ifstream r_file;
ofstream w_file;
ofstream w_file2;
vector<double> vals;

double read(string line){
  return (stof(line.substr(line.find_first_of(",")+1)));
}

double calc(double ui, int a){
  return (-(log(1-ui)/a));
}

void process(int a){
  string line;
  int cont = 1;
  double ui;
  while(getline(r_file, line)){
    ui = read(line);
    w_file << cont << "," << ui << "," << calc(ui, a) << "\n";
    vals.push_back(calc(ui,a));
    cont++;
  }
  cout << "N= " << cont-1 << endl;
}

double maxi(){
  double max = vals.at(0);
  for (auto item:vals){
    max = (item > max)? item : max;
  }
  return max;
}

double mini(){
  double min = vals.at(0);
  for (auto item:vals){
    min = (item < min)? item : min;
  }
  return min;
}

int freq(double d, double u){
  int cont = 0;
  for (auto item:vals){
    cont += (item < u && item >= d)? 1 : 0;
  }
  return cont;
}

void clases(){
  double min = mini();
  double max = maxi();
  double class_u = ((max - min)/20);
  for(int bin = 1; bin < 21; ++bin){
    w_file2 << bin << "," << class_u*bin << "," << freq(class_u*bin-1, class_u*bin) << "\n";
  }
}

int main(int argc, char* argv[]){
  cout << "./expo a\n";

  int a = (argc > 1)? atoi(argv[1]) : 3;

  r_file.open("floats.csv");
  w_file.open("expo.csv");
  w_file2.open("expo_classes.csv");

  string line;
  getline(r_file, line);

  process(a);
  clases();

  r_file.close();
  w_file.close();
  w_file2.close();



  return 1;
}
