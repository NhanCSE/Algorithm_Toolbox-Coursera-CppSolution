#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int remainder = n;
  int i = 1;
  while(remainder > 0)
  {
    remainder -= i;
    summands.push_back(i);
    i++;
  }
  if(remainder == 0) return summands;
  //when remainder < 0 there appear in vecto a unneccessary i and current i is i + 1.
  //vetor start at 0 so to access last positive element we have to access with index i - 3
  //current i is i + 1 so we have to minus i by 1 before adding to reaminder
  //ex: 9-> 1 2 3 -1 so oldRemain = currenti + newRemain = 4 - 1 = 3
  //so 3 + oldRemain = 6 is the answer for last positive element
  summands[i-3] += ((i - 1) + remainder);
  summands.resize(i-2);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
