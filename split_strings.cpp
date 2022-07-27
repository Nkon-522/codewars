#include <iostream>
#include <vector>
using namespace std;

vector<string> solution(const string &s)
{
	vector<string> resultado;
	string letras;
	for (int i=0; i<s.size(); i+=2){
		if (i+2 <= s.size()){
			letras=s.substr(i,2);	
		}else{
			letras=s[i];
			letras+='_';
		}
		resultado.emplace_back(letras);
	}
	return resultado;
}

int main(){
	for(auto &s:solution("abc")){
		cout<<s<<" ";
	}
	cout<<endl;
	return 0;	
}
