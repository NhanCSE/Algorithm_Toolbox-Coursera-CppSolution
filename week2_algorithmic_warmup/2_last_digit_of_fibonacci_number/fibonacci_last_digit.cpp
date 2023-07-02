#include <iostream>
using namespace std;



long long last_digit_a_fibonacci_fast(long long n) {
    // write your code here
    long long * newFibo = new long long[n+1];
    newFibo[0] = 0;
    newFibo[1] = 1;
    for(int i = 2; i <= n; i++)
        newFibo[i] = ((newFibo[i-1]%10) + (newFibo[i-2]%10))%10;
    long long result = newFibo[n];
    delete[] newFibo;
    return result;
    
}

long long get_fibonacci_last_digit_naive(long long n) {
    /*
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
    */
    long long fibo = last_digit_a_fibonacci_fast(n);
    long long result = fibo % 10;
    return result;

}

int main() {
    int n;
    std::cin >> n;
    //std::cout << fibonacci_fast(n) << std::endl;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
}
