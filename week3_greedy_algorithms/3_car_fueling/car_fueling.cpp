#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int countRefill = 0;
    int currRefill = 0, lastRefill = 0;
    //Add 0 and dist as two fillstops
    vector<int> newStops(stops.size() + 2);
    newStops.push_back(0);
    for(int i = 0; i < stops.size(); i++) newStops.push_back(stops[i]);
    newStops.push_back(dist);

    int n = newStops.size();
    //if at starting point car have enough fuel so they do not need filling
    if(newStops[0] + tank >= dist) return 0;

    while(currRefill + 1 < n)
    {
        lastRefill = currRefill;
        //algorithms
        while(newStops[currRefill + 1] - newStops[lastRefill] <= tank && currRefill + 1 < n) currRefill++;
        if(currRefill == lastRefill) return -1;
        //check to ensure that the while loop out for the first condition
        if(currRefill + 1 < n) countRefill++;
        //check if currRefill == n - 2; or near that vakue
        if(newStops[currRefill] + tank >= dist) return countRefill++;
    }
    return countRefill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
