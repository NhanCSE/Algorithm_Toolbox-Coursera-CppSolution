#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
/*
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}
*/
int findPivot(vector<int>& a, int start, int end) {

  int firstKey = a[start];
  int k = start + 1;
  while((k <= end) && a[k] == firstKey) k++;
  if(k > end) return -1;

  if(a[k] > firstKey) return k;
  else return start;
}


int Patition(vector<int>& a, int start, int end, int pivot) {
  int left = start, right = end;
  while(left <= right) {
    while(a[left] < pivot) left++;
    while(a[right] >= pivot) right--;
    if(left < right) swap(a[left], a[right]);
  }
  return left;
}

void randomized_quick_sort(vector<int> &a, int l, int r){
  int pivot;
  int pivotIndex, patitionPoint;
  pivotIndex = findPivot(a, l, r);
  if(pivotIndex != -1) {
    pivot = a[pivotIndex];
    patitionPoint = Patition(a, l, r, pivot);
    randomized_quick_sort(a, l, patitionPoint - 1);
    randomized_quick_sort(a, patitionPoint, r);
  }
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
