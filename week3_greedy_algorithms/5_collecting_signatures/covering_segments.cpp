#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
using std::vector;

struct Segment {
  int start, end;
};
//that is the condition to sort algorithm
//the point with the min start value will set at the first
bool startEarlier(Segment &a, Segment &b)  { return a.start < b.start; }

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  sort(segments.begin(), segments.end(), startEarlier);
  int n = segments.size();
  int* selected = new int[n];
  for(int i = 0; i < n; i++) selected[i] = 0;

  for(int i = 0; i < n; i++) {
    while(selected[i] && i < n) i++;
    if(i == n) break;
    selected[i] = 1;
    int endMin = segments[i].end;
    int j = i+1;
    if(j == n) {points.push_back(endMin); break;}
    while(selected[j] == 0 && segments[i].end >= segments[j].start && j < n) {
      if(segments[j].end < endMin)  endMin = segments[j].end;
      selected[j] = 1;
      j++;
    }
    if(j < n && selected[j] == 1) continue;
    points.push_back(endMin);
  }
  delete[] selected;
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }

  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  
  
  return 0;
}
