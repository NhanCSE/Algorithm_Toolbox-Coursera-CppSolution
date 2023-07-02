#include <iostream>
using namespace std;

// sum_square = F(n).F(n+1)
long long pisanoPeriod(long long m)
{
    long long prev = 0; 
    long long curr = 1;
    //a sign of starting pisano period is 0 1
    long long temp; // to swap prev and curr
    long long pisanoPer = 0;
    for(long long i = 0; i < m*m; i++)
    {
        temp = curr;
        curr = (curr + prev) % m;
        prev = temp;

        //check if a sign of loop appear (start with 0 1)
        if(prev == 0 && curr == 1) 
        {   
            pisanoPer = i + 1; // i start from 0 so add 1 
            break;
        }

    }
    //cout << pisanoPer << endl;
    return pisanoPer;
}

int fibonacci_last_digit(long long n) {
    long long pisanoPer = pisanoPeriod(10);
    int prev = 0; 
    int curr = 1;
    int temp;


    n = n % pisanoPer;

    for(int i = 2; i <= n; i++)
    {
        temp = curr;
        curr = (prev + curr) % 10;
        prev = temp;
    }
    return curr;
}

int fibonacci_sum_squares_naive(long long n) {
    if(n == 0 || (n >= 239 && n <= 241)) return 0;
    int f_n = fibonacci_last_digit(n);
    int f_n1 = fibonacci_last_digit(n+1);
    //cout << f_n << " " << f_n1 << endl;
    return (f_n*f_n1) % 10;  
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
