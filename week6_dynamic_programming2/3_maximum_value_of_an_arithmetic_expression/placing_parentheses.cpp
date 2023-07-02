#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
using namespace std;
using std::vector;
using std::string;
using std::max;
using std::min;



long long get_maximum_value(const string &expression) {
  //write your code here
    int n = (expression.size() + 1) / 2; // Number of operands
    vector<vector<long long>> maxVal(n, vector<long long>(n, LLONG_MIN));
    vector<vector<long long>> minVal(n, vector<long long>(n, LLONG_MAX));

    // Initialize diagonal elements with operand values
    for (int i = 0; i < n; i++) {
        maxVal[i][i] = expression[2 * i] - '0';
        minVal[i][i] = expression[2 * i] - '0';
    }

    // Evaluate maximum and minimum values for all subexpressions
    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            for (int k = i; k < j; k++) {
                long long a = maxVal[i][k], b = maxVal[k + 1][j];
                long long c = minVal[i][k], d = minVal[k + 1][j];

                if (expression[2 * k + 1] == '+') {
                    maxVal[i][j] = max(maxVal[i][j], a + b);
                    minVal[i][j] = min(minVal[i][j], c + d);
                } else if (expression[2 * k + 1] == '-') {
                    maxVal[i][j] = max(maxVal[i][j], a - d);
                    minVal[i][j] = min(minVal[i][j], c - b);
                } else if (expression[2 * k + 1] == '*') {
                    long long prod1 = a * b;
                    long long prod2 = a * d;
                    long long prod3 = c * b;
                    long long prod4 = c * d;
                    maxVal[i][j] = max(maxVal[i][j], max(prod1, max(prod2, max(prod3, prod4))));
                    minVal[i][j] = min(minVal[i][j], min(prod1, min(prod2, min(prod3, prod4))));
                }
            }
        }
    
    }
    return maxVal[0][n - 1];

}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
