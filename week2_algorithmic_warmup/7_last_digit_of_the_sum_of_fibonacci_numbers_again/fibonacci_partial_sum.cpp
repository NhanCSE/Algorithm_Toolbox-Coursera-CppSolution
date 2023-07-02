#include <iostream>
#include <vector>
using std::vector;

//S(L,r) = F(r+2) - F(L+1)

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
    //long long sum = 1;


    n = n % pisanoPer;

    for(int i = 2; i <= n; i++)
    {
        temp = curr;
        curr = (prev + curr) % 10;
        prev = temp;
        //sum = (curr + sum) % 10;
    }

    return curr;
}

int get_fibonacci_partial_sum_naive(long long from, long long to) {
    int result;
    int right_last_digit = fibonacci_last_digit(to + 2);
    int left_last_digit = fibonacci_last_digit(from + 1);
    if(right_last_digit < left_last_digit) right_last_digit += 10;
    return right_last_digit - left_last_digit;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
