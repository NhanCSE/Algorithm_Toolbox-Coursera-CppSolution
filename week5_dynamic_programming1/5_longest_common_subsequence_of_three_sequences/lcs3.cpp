#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int m = a.size();
  int n = b.size();
  int o = c.size();

  int*** table = new int**[m + 1];
  for(int i = 0; i <= m; i++) {
    table[i] = new int*[n + 1];
    for(int j = 0; j <= n; j++) 
      table[i][j] = new int[o + 1];
  }

  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n ; j++) {
      for(int k = 0; k <= o; k++) {
        //base case
        if(i == 0 ||j == 0|| k == 0) table[i][j][k] = 0;
        else if(a[i-1] == b[j-1] && a[i-1] == c[k-1]) table[i][j][k] = table[i-1][j-1][k-1] + 1;
        else table[i][j][k] = max(max(table[i-1][j][k], table[i][j-1][k]), table[i][j][k-1]);
      }
    }

  }
  int result = table[m][n][o];


  for(int i = 0; i <= m; i++) {
    for(int j = 0; j <= n; j++) {
      delete[] table[i][j];
    }
    delete[] table[i];
  }
  delete[] table;

  return result;
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
