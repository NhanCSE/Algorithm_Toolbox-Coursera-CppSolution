#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &gold) {
  //write your code here
  int n = gold.size();
  //create the 2D table with all element = 0 
  //table is the maximum gold through ith-gold
  vector<vector<int>> table(n + 1, vector<int>(W + 1, 0));

  //i stand for ith-gold
  //w stand for the weight remaining if the bag get ith-gold
  for(int i = 1; i <= n; i++) {
    for(int w = 1; w <= W; w++) {
      //if ith-gold is not picked up, the table in i get value from previous i-1
      //and the weight is remain w 
      table[i][w] = table[i-1][w];
      //if bag can hold (i-1)th gold
      if(gold[i-1] <= w) {
        //when pick up a ith-gold the reimaining weight = w - currWeight = w - gold[i-1]
        int value = table[i - 1][w - gold[i - 1]] + gold[i-1];
        if(value > table[i][w]) //choose max value among new and old one
          table[i][w] = value;
      }
    }
  }
  return table[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
