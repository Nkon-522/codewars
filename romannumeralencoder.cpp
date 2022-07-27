#include <iostream>
using namespace std;

#include <string>
std::string solution(int number){
  string resultado="";
  for(int i=0; i<number/1000; i++){resultado+='M';}
  number=number%1000;
  if(number>=900){resultado=resultado+"CM";number-=900;}
  else if(number>=400 && number<=500){resultado=resultado+"CD";number-=400;}
  else{
    for(int i=0; i<number/500; i++){resultado+='D';}
    number=number%500;
    for(int i=0; i<number/100; i++){resultado+='C';}
    number=number%100;
  }
  if(number>=90){resultado=resultado+"XC";number-=90;}
  else if(number>=40 && number<=50){resultado=resultado+"XL";number-=40;}
  else{
    for(int i=0; i<number/50; i++){resultado+='L';}
    number=number%50;
    for(int i=0; i<number/10; i++){resultado+='X';}
    number=number%10;
  }
  if(number>=9){resultado=resultado+"IX";}
  else if(number==4){resultado=resultado+"IV";}
  else{
    for(int i=0; i<number/5; i++){resultado+='V';}
    number=number%5;
    for(int i=0; i<number; i++){resultado+='I';}
  }
  return resultado;
}
#include <map>
std::string solution2(int number) {
    const std::map<int, std::string> bases = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    std::string rnum("");
    cout<<bases.crbegin()->first<<endl;
    for (auto it = bases.crbegin(); it != bases.crend(); ) {
        if (number >= it->first) {
            number -= it->first;
            rnum += it->second;
        } else {
            it++;
        }
    }
    
    return rnum;
}

int main()
{
  cout<<solution(182)<<endl;
cout<<solution2(182)<<endl;
  return 0;
}
