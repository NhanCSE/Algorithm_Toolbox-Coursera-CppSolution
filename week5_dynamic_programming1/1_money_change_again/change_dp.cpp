#include <iostream>
#include <vector>
using namespace std;

int moneyChange(vector<int>& typeCoin, int money) {
    //create a table
    vector<int> totalCoin (money + 1);
    for(int i = 0; i <= money; i++) 
        totalCoin[i] = INT16_MAX;
    //Base case
    totalCoin[0] = 0;

    for(int i = 1; i <= money; i++){
        for(int j = 0; j < typeCoin.size(); j++) {
            if(typeCoin[j] <= i) {
                //if we have 3 type coin 1 3 4 and money is 34
                //34 is combined by 30 + 1 coin 4 OR 33 + 1 coin 1 OR 31 + 1 coin 3
                //target is to find minimum among all scenarios leed to the combination
                int previousCoin = totalCoin[i - typeCoin[j]];
                if(previousCoin != INT16_MAX && previousCoin + 1 < totalCoin[i])
                    totalCoin[i] = previousCoin + 1;
            }
        }
    }
    if(totalCoin[money] == INT16_MAX) return -1; // unfound
    return totalCoin[money];
}

int get_change(int m) {
  vector<int> typeCoin = {1, 3, 4};
  return moneyChange(typeCoin, m);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
