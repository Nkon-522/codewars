#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <iterator>

using namespace std;

int sum_intervals(vector<pair<int, int>> intervals) {
  set<int> res;
  int tamanio=distance(begin(intervals),end(intervals));
  for(int i=0;i<tamanio;i++){
    for(int j=(intervals[i].first)+1;j<=intervals[i].second;j++){
      res.insert(j);
    }
  }
  return distance(begin(res),end(res));
}

int main()
{
  std::vector<std::pair<int, int>> intervals = {{1, 5}};
  intervals = {{1, 5}, {6, 10}};
  cout<<sum_intervals(intervals)<<endl;
  return 0;
}
