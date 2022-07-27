#include <iostream>
#include <vector>
#include <string>
using namespace std;
void check_around(bool& found, vector<vector<char>>board, int rows, int cols, 
    vector<vector<bool>>& visited, string word, string& palabra, int i, int j){
  visited[i][j]=true;
  palabra=palabra+board[i][j];
  if(palabra==word){found=true;return;}

  for(int ci=i-1;ci<=i+1 && ci<rows;ci++){
    for(int cj=j-1;cj<=j+1 && cj<cols;cj++){
      if(ci>=0 && cj>=0 && !visited[ci][cj]){
        if(word.length()>=palabra.length() && word.find(palabra+board[ci][cj]) != string::npos){
          check_around(found, board, rows, cols, visited, word, palabra, ci, cj);
        }
      }
    }
  }
  palabra.erase(palabra.length()-1);
  visited[i][j]=false;
}

bool check_word(const vector<vector<char> > &board, const string &word)
{
  vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
  string palabra="";
  bool found=false;
  int rows = distance(begin(board),end(board));
  int cols = distance(begin(board[0]), end(board[0]));
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols;j++){
      if(word[0]==board[i][j]){
        check_around(found, board, rows, cols, visited, word, palabra, i, j);
      }
    }
  }
  if (found){return true;}
  return false;
}

int main(){
 vector<vector<char> > test_board = {{'E','A','R','A'},
                                     {'N','L','E','C'},
                                     {'I','A','I','S'},
                                     {'B','Y','O','R'} };
vector<string> palabras = {"C","EAR","EARS","BAILER","RSCAREIOYBAILNEA", "CEREAL","ROBES","BAKER","CARS"};
for (auto x:palabras){
    bool result=check_word(test_board, x);
    cout<<x<<": "<<boolalpha<<result<<endl;
  }
return 0;
}




