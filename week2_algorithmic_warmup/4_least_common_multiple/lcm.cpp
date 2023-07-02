#include <iostream>

//Answer is that lcm is a product of a b divided by thier gcd(a,b)
// lcm(a,b) = a*b/gcd(a,b);
long long GreatestCommonDivisor(long long a, long long b)
{
    while (a != 0 && b != 0)
    {
        if(a > b)
            a = a % b;
        else    
            b = b % a;
    }
    return a+b;
}
long long lcm_naive(long long a, long long b) {
  long long product = a*b;
  long long result = product/GreatestCommonDivisor(a, b);
  return result;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
