#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
  int n = A.size();
  int totalSum = 0;

  for(int a: A) {
    totalSum += a;
  }

  if(totalSum % 3 != 0)
    return 0;

  int targetSum = totalSum / 3;

  vector<vector<int>> table (n+1, vector<int> (targetSum + 1, 0));

  //Base case
  table[0][0] = 1;

  for(int i = 1; i <= n; i++) {
    for(int j = 0; j <= targetSum; j++) {
      table[i][j] = table[i-1][j];
      if(A[i-1] <= j) {
        table[i][j] |= table[i-1][j-A[i-1]];
      }
    }
  }

  if(table[n][targetSum] == 0) 
    return 0;
  else return 1;


  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
