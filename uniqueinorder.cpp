#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
  vector<T> resultado;
  for(auto it=iterable.begin(); it!=iterable.end(); it++){
	if(*(next(it)) != *it || (next(it)==iterable.end())){
		resultado.emplace_back(*it);
	}
  }
  return resultado;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
  vector<char> resultado;
  for(auto it=iterable.begin(); it!=iterable.end(); it++){
	if(*(next(it)) != *it || (next(it)==iterable.end())){
		resultado.emplace_back(*it);
	}
  }
  return resultado;
}
int main(){
	for (auto x:uniqueInOrder("AAAABBBCCDAABBB")){
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}
