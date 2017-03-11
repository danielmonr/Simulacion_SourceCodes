#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Test{
  public:
    static void test(vector<T> v);
};

template <class T>
void Test<T>::test(vector<T> v){
  ofstream w_file;
  w_file.open("test.csv", ofstream::out);
  w_file << "i, R, i/N, D+, D-\n";
  sort(v.begin(), v.end());
  double i = 1;
  double dm, dp;
  double DPmax = 0, DMmax = 0;
  for(auto item:v){
    dp = (i/v.size()) - item;
    dm = item - ((i-1)/v.size());
    DPmax = (dp > DPmax)? dp : DPmax;
    DMmax = (dm > DMmax)? dm : DMmax;
    w_file << i << ", " << item << ", " << i/v.size() << ", " << dp << ", " << dm << "\n";
    i++;
  }
  double D = (DPmax > DMmax)? DPmax : DMmax;
  cout << "D+ = " << DPmax << "; D- = " << DMmax << "; D = " << D << endl;
}
