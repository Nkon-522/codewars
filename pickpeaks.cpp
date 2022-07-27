#include<iostream>
#include<vector>
using namespace std;

struct PeakData {
  vector<int> pos, peaks;
};


PeakData pick_peaks(const std::vector<int> &v) {
  PeakData result;
  int tamanio=distance(v.begin(),v.end());
  for(int i=1;i<tamanio-1;i++){
    if(v[i]>v[i+1] && v[i]>v[i-1]){
      result.peaks.emplace_back(v[i]);result.pos.emplace_back(i);
    }else if(v[i]==v[i+1] && v[i]>v[i-1]){
      int indice=i;
      while(i<tamanio-2 && v[i]==v[i+1]){i++;}
      if(v[i]>v[i+1]){
          result.peaks.emplace_back(v[indice]);result.pos.emplace_back(indice);
      }
      
    }
  }
  return result;
}

int main(){
  PeakData a = pick_peaks(std::vector<int> {3, 2, 3,3, 3});  
  cout<<"peaks: ";
  for(auto x:a.peaks)cout<<x<<" ";
  cout<<endl<<"pos: ";
  for(auto x:a.pos)cout<<x<<" ";
  cout<<endl;
  return 0;
}
