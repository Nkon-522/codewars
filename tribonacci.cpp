#include <iostream>
#include <vector>
using namespace std;

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result;
    if(n>distance(signature.begin(), signature.end())){
      result.emplace_back(signature[0]);
      result.emplace_back(signature[1]);
      result.emplace_back(signature[2]);
      n-=3;
      int indice=2;
      int contador=3;
      int valor=0;
      while(n--){
        valor=0;
        for(int i=0;i<contador;i++){
          valor+=result[indice-i];
      }
      result.emplace_back(valor);
      indice++;
      }
    }else{
      for(int i=0;i<n;i++){
        result.emplace_back(signature[i]);
      }
    }
    return result;
}

// version 2

std::vector<int> tribonacci_2(std::vector<int> signature, int n)
{
    signature.resize(n);
    int contador=3;
    int valor;
    for(int i=3; i<n;i++){
      valor=0;
      for(int j=1;j<=contador;j++){
        valor+=signature[i-j];
      }
      signature[i]=valor;
    }
    return signature;
}



int main()
{
  vector<int> resultado;
  std::vector<int> signature = { 1, 1, 1 };
  resultado=tribonacci_2(signature, 10);

  for(auto x:resultado){
    cout<<x<<" ";
  }
  cout<<endl;
  return 0;
}
