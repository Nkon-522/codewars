#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool largest(string a, string b){return (a.length() < b.length());}

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k){
      string resultado;
      int n = distance(strarr.begin(), strarr.end());
      if (n==0 || k>n || k<=0) return "";
      auto maximo=max_element(begin(strarr),end(strarr), largest);
      if(maximo==begin(strarr)){
        resultado=*maximo + *(next(maximo));
      }
      else if(maximo==end(strarr)){
        resultado=*maximo + *(prev(maximo));
      }
      else{
        if(largest( *(next(maximo)) , *(prev(maximo)) )){
          resultado=*maximo + *(prev(maximo));
        }else{
          resultado=*maximo + *(next(maximo));
        }
      }
      return resultado;
    }

    static std::string longestConsec2(std::vector<std::string> &strarr, int k){
      string resultado="";
      
      int n = distance(strarr.begin(), strarr.end());
      //string a="";
      string b="";
      if (n==0 || k>n || k<=0) return ""; 
      for(int i=0;i<k;i++){
          resultado+=strarr[i];
      }
      for (int i=0; i+k<n; i++){
        //a="";
        b="";
        for(int j=i;j<i+k;j++){
          //a+=strarr[j];
          b+=strarr[j+1];
        }
        //cout<<"a: "<<a<<endl;
        //cout<<"b: "<<b<<endl;
        if(resultado.length()<b.length()){
          resultado=b;
        }
      }
      return resultado;
    }
};

int main(){
  vector<string> strarr = {"tree", "foling", "trashy", "blue", "abcdef", "uvwxyz" };
  int k = 2;
  string resultado=LongestConsec::longestConsec2(strarr, k);
  cout<<resultado<<endl;
  return 0;
}
