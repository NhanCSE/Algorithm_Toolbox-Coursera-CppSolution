#include <iostream>
using namespace std;
//Return minimum coins trade from giving money
int get_change(int money) {
  //write your code here
  int mincoins = 0;
  int numcoin10 = 0, numcoin5 = 0, numcoin1 = 0;
  if(money >= 10)
  {
    numcoin10 = money / 10;
    money %= 10;
  }
  //cout << numcoin10 << " " << money << endl;
  if(money >= 5)
  {
    numcoin5 = money / 5;
    money %= 5;
  }
  //cout << numcoin5 << " " << money << endl;
  numcoin1 = money;
  mincoins = numcoin10 + numcoin1 + numcoin5;

  return mincoins;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
