#include <iostream>
#include <vector>
#include <string>
#include<cstdlib>
#include <fstream>
using namespace std;

/*
Ejercicio #13
Elaborar una función "get_anagrams" que cuente con 1 parámetros, el primero para recibir una palabra y el segundo el nombre de un archivo, el programa debe devolver un vector con todas las palabras dentro del archivo que sean anagrama del primer parametro, cada palabra estará escrita en una línea del archivo.

vector<string> get_anagrams(string word, string filename);

Determinar el bigO del algoritmo que halla desarrollado.
*/

bool es_anagrama(string word, string palabra){
	if (word.size()!=palabra.size()){
		return false;
	}
	int contador[256]{};
	int i=0;
	for(int i=0; i<word.size();i++){
		contador[word[i]]++;
		contador[palabra[i]]--;
	}
	for(int i=0; i<word.size();i++){
		if(contador[word[i]]!=0){return false;}
	}
	return true;
}


vector<string> get_anagrams(string word, string filename) {
  vector<string> anagramas;
  ifstream archivo(filename);
  string palabra;
  while(getline(archivo,palabra)){
	if(es_anagrama(word, palabra)){
		anagramas.emplace_back(palabra);
	}
  }
  archivo.close();
  return anagramas;
}


/* 
Ejercicio #14
Elaborar una función "get_par_lejano" que lea un vector con valores aleatorios de doubles y que retorne un pair con los 1 valores que tengan la mayor diferencia entre 2 valores del vector (en valor absoluto), el programa debía ser lineal en el peor de los casos.

pair <double, double> get_par_lejano(const vector<double>& data);
*/

pair <double, double> get_par_lejano(const vector<double>& data) {
	double min,max,max_diff;
	min = data[0];
	max_diff=data[1]-min;
	for(int i=1;i<data.size();i++){
		if(max_diff<abs(data[i]-min)){
			max_diff=data[i]-min;
			max=data[i];
		}
		if(data[i]<min){
			min=data[i];
		}
	}
  return pair<double, double>{min,max};
}

int main(){
	vector<double> a ={1,2,90,10,110};
	pair<double,double> b = get_par_lejano(a);
	cout<<b.first<<" "<<b.second<<endl;
/*
	string str1 = "geeksforgeeks";
    string str2 = "forgeeksgeeks";
   
    // Function Call
    if (es_anagrama(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";*/
	return 0;
}

