#include <iostream>

long long gcd_naive(long long a, long long b) {
  while(a != 0 && b != 0)
  {
    if(a > b) a = a % b;
    else b = b % a;
  }
  return a + b;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
