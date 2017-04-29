#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  if(argc > 1){
    cout << "not implemented\n";
  }
  int n;
  cout << "Enter number of categories: ";
  cin >> n;
  float* percentage = (float*)malloc(n*sizeof(float));
  float* res = (float*)malloc(n*sizeof(float));
  float* mtp = (float*)malloc(n*n*sizeof(float));
  cout << "Enter category's %:" << endl;
  for(int i = 0; i < n; ++i){
    cout << "[" << i << "]: ";
    cin >> percentage[i];
  }
  cout << "Enter mtp vals:\n";
  for (int i = 0; i < n; i++){
    for(int j = 0; j < n; ++j){
      cout << "[" << n*i << "][" << j << "]: ";
      cin >> mtp[(n*i)+j];
    }
  }

memcpy(res, percentage, n*sizeof(float));

  float* temp = (float*)malloc(n*sizeof(float));

  int it;
  cout << "Number of iterations? ";
  cin >> it;
  for(int its = 0; its < it; ++its){
    memset(temp, 0, n*sizeof(float));
    cout << "Results in iteration " << its+1 << ":\n[";
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        temp[i] += mtp[j*n+i]*res[j];
      }
      cout << temp[i] << " ";
    }
    cout << "]\n";
    memcpy(res, temp, n*sizeof(float));
  }
  free()
  free(mtp);
  free(percentage);
  return 1;
}
