#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
using std::vector;
using std::string;
//My algorithm:
// We try to put all number to have equal digit
// If we have 589 and 56 then we add first letter of 56 to itself is '5'
// so 589 and 565
// arrage it from max to min and chose the number with index of old(havent add first letter)
// so 589-56 is the max number we can have from 2 given number


//First we have to find the max value in vecto and find how muc digit it have
int findMax(vector<string> a) {
  int max = stoi(a[0]);
  int countDigit = 0;
  for(int i = 0; i < a.size(); i++) {
    if(stoi(a[i]) > max) max = stoi(a[i]);
  }
  return max;
}
int countDigits(int a) {
  int countDigit = 0;
  while(a) {
    countDigit++;
    a /= 10;
  }
  return countDigit;
}

string largest_number(vector<string> a) {
  string result = "";
  //In this newInt vecto we save the value of value from old but add more digit if they are less than maxDigit
  vector<string> newInt (a.size());
  for(int i = 0; i < newInt.size(); i++) {
    newInt[i] = "";
    newInt[i] += a[i];
  }

  int maxDigit = countDigits(findMax(a));
  for(int i = 0; i < a.size(); i++) {
    int currDigit = countDigits(stoi(a[i]));
    while(currDigit != maxDigit) {
      newInt[i] += newInt[i][0];
      currDigit++;
    }
  }

  //Arrage index from max to min in newInt and take them to old vecto 
  int* selected = new int[a.size()];
  for(int i = 0; i < a.size(); i++) selected[i] = 0;
  for(int i = 0; i < a.size(); i++) {
    int maxNum = INT16_MIN;
    int iMax = 0;
    for(int j = 0; j < a.size(); j++) {
      if(stoi(newInt[j]) > maxNum && selected[j] == 0) {
        maxNum = stoi(newInt[j]);
        iMax = j;
      }
    }
    selected[iMax] = 1;
    result += a[iMax];
  }

  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
