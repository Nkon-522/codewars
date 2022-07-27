#include <iostream>
#include <vector>
using namespace std;

int countSmileys(std::vector<std::string> arr)
{
  int res=0;
  for(auto x:arr){
    if (
        (x.find(":")!= std::string::npos || x.find(";")!= std::string::npos) &&
        (x.find(")")!= std::string::npos || x.find("D")!= std::string::npos)
      ){
        if(x.length()==3){
          if(x.find("-")!= std::string::npos || x.find("~")!= std::string::npos){
            res++;
          }
        }
        else{
          res++;
        }
    }
  }
  return res;
}

int main(){
  vector<string>a={":D", ":~)", ";~)", ":)"};
  int resultado=countSmileys(a);
  cout<<resultado;
  return 0;
}
