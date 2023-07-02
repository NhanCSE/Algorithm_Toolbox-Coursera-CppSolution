#include <iostream>
using namespace std;
//Key algorithm is Pisano period
//We need to find the remainder WHEN N is divided by Pisano period of M
//and then find F(remainder) mod M = result
//Ex: F2019 mod 5, first pisanoperiod of 5 is 20, so find 2019 % 20 = 19
//then find F19 mod 5
//Every array of number when modulo with any int number is periodic, still with fibonacci
//This period is called Pisano Period and start with 0 and 1


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


long long get_fibonacci_huge_naive(long long n, long long m) {
    
    
    long long pisanoPer_m = pisanoPeriod(m);
    n = n % pisanoPer_m;
    //cout << n << endl;

    if(n == 0) return 0;
    else if (n == 1) return 1;

    //find fibonacci's pisano number
    long long prev = 0;
    long long curr = 1;
    for(int i = 0; i < n-1; i++)
    {
        long long temp = curr;
        curr = (curr + prev) % m;
        prev = temp;
    }
    return curr % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
