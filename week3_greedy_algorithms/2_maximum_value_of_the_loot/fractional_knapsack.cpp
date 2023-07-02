#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int n = values.size();
  vector<double> valPerWeight (n);
  for(int i = 0; i < n; i++)
    valPerWeight[i] = (double)values[i] / weights[i];
  int* selected = new int[n];
  for(int i = 0; i < n; i++) selected[i] = 0;
  int j = 0;
  while(capacity && j < n)
  {
    double maxVPW = 0;
    int imax = 0;
    for(int i = 0; i < n; i++)
      if(!selected[i] && valPerWeight[i] > maxVPW)
      {
        maxVPW = valPerWeight[i];
        imax = i; 
      }
    selected[imax] = 1;
    //if weights is smaller than capacity, then take all of them
    if(capacity >= weights[imax])
    {
      value += weights[imax] * valPerWeight[imax];
      capacity -= weights[imax];
    }
    //else hust take the capacity left
    else 
    {
      value += capacity * valPerWeight[imax];
      capacity = 0;
    }
    j++;
  }


  delete[] selected;
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);
  cout << fixed << setprecision(4) << optimal_value;

  return 0;
}
