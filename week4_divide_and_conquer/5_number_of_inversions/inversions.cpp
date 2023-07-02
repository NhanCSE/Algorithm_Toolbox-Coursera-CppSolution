#include <iostream>
#include <vector>

using std::vector;

long long merge(vector<int> &a, vector<int> &temp, size_t left, size_t mid, size_t right) {
  long long inversionCount = 0;
  long long i, j, hasMerged;
  
  i = left;
  j = mid;
  hasMerged = left;

  while((i <= mid - 1) && (j <= right)) {
    if(a[i] <= a[j]) {
      temp[hasMerged++] = a[i++];
    }
    else {
      temp[hasMerged++] = a[j++];
      inversionCount += (mid-i);
    }
  }

  while(i < mid) temp[hasMerged++] = a[i++];
  while(j <= right) temp[hasMerged++] = a[j++];
  for(i = left; i <= right; i++) a[i] = temp[i];
  return inversionCount;
}


long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if(left < right) {
    long long mid = (left + right) / 2;
    number_of_inversions += get_number_of_inversions(a, b, left, mid);
    number_of_inversions += get_number_of_inversions(a, b, mid + 1, right);
    number_of_inversions += merge(a, b, left, mid + 1, right);
    return number_of_inversions;
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
