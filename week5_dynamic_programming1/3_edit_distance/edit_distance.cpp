#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

using std::string;

int findMin(int x, int y, int z) {
  return min(min(x, y), z);
}

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int str1Len = str1.length();
  int str2Len = str2.length();
  //create table
  int** table = new int*[str1Len + 1];
  for(int i = 0; i <= str1Len; i++) 
    table[i] = new int[str2Len + 1];

  for(int i = 0; i <= str1Len; i++) {
    for(int j = 0; j <= str2Len; j++) {
      //Base case: first element from row 0 and comlumn 0 is equal to there column or row respectively
      if(i == 0) table[i][j] = j;
      else if(j == 0) table[i][j] = i;
      //if the previous character of two string is equal, then table in (i, j) is euql to there previous (i-1, j-1)
      else if(str1[i - 1] == str2[j - 1]) table[i][j] = table[i - 1][j - 1];
      else table[i][j] = 1 + findMin(table[i][j - 1], // Insert
                                    table[i - 1][j], // Delete
                                    table[i - 1][j - 1]); // Replace by 
    }
  }
  int result = table[str1Len][str2Len];
  //delete array
  for(int i = 0; i <= str1Len; i++)
    delete[] table[i];
  delete[] table;
  return result;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
