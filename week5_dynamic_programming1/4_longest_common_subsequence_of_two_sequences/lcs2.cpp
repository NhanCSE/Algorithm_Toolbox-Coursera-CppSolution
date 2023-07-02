#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  int aLen = a.size();
  int bLen = b.size();

  int** table = new int*[aLen + 1];
  for(int i = 0; i <= aLen; i++) 
    table[i] = new int[bLen + 1];


  for(int i = 0; i <= aLen; i++) {
    for(int j = 0; j <= bLen; j++) {
      //Base case
      if(j == 0 || i == 0) table[i][j] = 0;
      //Detect the number in common => add the previous step (i-1, j-1) to 1
      else if(a[i - 1] == b[j - 1]) table[i][j] = table[i-1][j-1] + 1;
      //else do not detect, (i,j) get max value from(i-1, j) or (i, j-1)
      else table[i][j] = max(table[i-1][j], table[i][j-1]);
    }
  } 
  int result = table[aLen][bLen];
  //delete array
  for(int i = 0; i <= aLen; i++) 
    delete[] table[i];
  delete[] table;
  return result;
  
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
