#include <iostream>
#include <vector>
#include <algorithm>
//find the way to make 1 to n using given operator
//this problem is +1, x3, x4
using namespace std;
using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  vector<int> table(n+1);
  for(int i = 0; i <= n; i++) table[i] = 0;

  //Base case
  table[1] = 1;
  
  for(int i = 1; i <= n; i++) {
    if(table[i] != 0) {
      //first condition is to assure the next step is not out of range
      //second condition is check whether the next step is full-filled 
      //last condition is check when the next step is apllied then choose the minimum access by adding the previous by 1 
      if((i + 1 <= n) && (table[i + 1] == 0 || table[i + 1] > table[i] + 1)) {
        table[i + 1] = table[i] + 1;
      }
      if((i * 2 <= n) && (table[i * 2] == 0|| table[i * 2] > table[i] +1)) {
        table[i * 2] = table[i] + 1;
      }
      if((i * 3 <= n) && (table[i * 3] == 0 || table[i * 3] > table[i] + 1)) {
        table[i * 3] = table[i] + 1;
      }     
    }
  }
  

  while(n >= 1) {
    //append n to vector
    sequence.push_back(n);
    //if the table[n] is made of previuos step plus 1
    //made of n - 1
    if(table[n] == table[n - 1] + 1)
      n--;
    //made of n / 2
    else if(n % 2 == 0 && (table[n] == table[n / 2] + 1))
      n /= 2;
    //made of n / 3
    else if(n % 3 == 0 && (table[n] == table[n / 3] + 1))
      n /= 3;
  }
  //reverse the vector to get the result
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
