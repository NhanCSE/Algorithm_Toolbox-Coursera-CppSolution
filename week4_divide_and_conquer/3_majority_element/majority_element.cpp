#include <algorithm>
#include <iostream>
#include <vector>
//#include <chrono>
using namespace std;
using std::vector;


// First way solving problem TimeComplexity = O(nlogn)
// with input 7
// 1 2 2 3 2 4 2
//Time = 10356 millis

/*
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  sort(a.begin(), a.end());
  int mid = (left + right) / 2;
  while((mid <= right) && a[left] != a[mid]) {
    left++;
    mid++;
  }
  if(mid <= right) return 1;
  return -1;
}
*/


/*The second way with 0(n)*/
//Time is 6876 millis

// this fuinction only return the true major if there exist more than n/2 time
// else it will return wrong
// so in next fuction we will check if cand = findMajorCandidate > n/2 
// if true then actually exist major else -1 
int findMajorCandidate(vector<int> &a) {
  int majorIndex = 0, count = 1;
  int n = a.size();
  for(int i = 0; i < n; i++) {
    if(a[majorIndex] == a[i]) count++;
    else count--;
    if(count == 0) {
      majorIndex = i;
      count = 1;
    }
  }
  return a[majorIndex];
}


int get_majority_element(vector<int> &a, int left, int right) {
  //array have 1 element
  if (left == right) return -1;
  int count = 0;
  int cand = findMajorCandidate(a);
  for(int i = 0; i < right; i++) {
    if(a[i] == cand) count++;
  }
  if(count > right/2) return 1;
  else return -1;
}




int main() {
  //start timer
  //auto start = chrono::high_resolution_clock::now();

  //Program
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';


  //end timer
  //auto end = chrono::high_resolution_clock::now();
  //auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
  //cout << "Exe time = " << duration.count() << " millisec" <<endl;



}
