#include <iostream>
using namespace std;

//S(n) = F(n+2) - 1

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


long long fibonacci_sum_naive(long long n) {
    long long pisanoPer = pisanoPeriod(10);
    long long prev = 0; 
    long long curr = 1;
    long long temp;
    //long long sum = 1;


    n = (n+2) % pisanoPer;

    for(int i = 2; i <= n; i++)
    {
        temp = curr;
        curr = (prev + curr) % 10;
        prev = temp;
        //sum = (curr + sum) % 10;
    }

    if(curr == 0) return 9;
    else return curr - 1; 
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
