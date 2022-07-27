#include <vector>
#include <iostream>
#include <string>
using namespace std;

std::string highestScoringWord(const std::string &str)
{
  string resultado;
  string palabra;
  int max=0;
  int current_word=0;
  for (int i=0; i <= str.size(); i++){
	if(str[i]==' '||i==str.size()){
		if(max==0 || max<current_word){
			max=current_word;
			resultado=palabra;
		}
		current_word=0;
		palabra="";
	}else{
		palabra+=str[i];
		current_word+= (int) str[i] - 96;
	}
  }
  return resultado;
}

int main()
{
	cout<<highestScoringWord("what time are we climbing up the volcano")<<endl;
	return 0;
}

