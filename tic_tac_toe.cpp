#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int n = 3;
vector<vector<char>> board(n,vector<char>(n,' '));
char A = 'o';
char B = 'x';

void print(vector<vector<char>> &board){
    for(int i = 0;i < board[0].size();i++){
        for(int j = 0;j < board[0].size();j++){
            cout <<"|" <<board[i][j];
        }
        cout << "|"<<endl;
        
    }
}
bool isvalidpos(vector<vector<char>>&board,int row,int col){
    if(row >= n || row < 0 || col >= n || col < 0){
        return false;
    }
    if(board[row][col] != ' ') return false;

    return true;
}

bool row_check(char choice,int row,int col){
    int i = 0;
    
    while(i < n){
        if(board[i][col] != choice) return false;
        i++;
    }
    return true;

}
bool col_check(char choice,int row,int col){
   int j = 0;
   while(j < n){
        if(board[row][j] != choice) return false;
        j++;
    }
    return true;
}
bool d_check(char choice,int row,int col){
    int i = 0;
    int j = 0;
    //diagonal check
     if((row == col) || (row + col == n-1)){
      while(i != n && j != n){
        if(board[i][j] != choice) return false;
        i++;
        j++;
      }

     return true;
    }
 
    return false;
}
bool iswin(char choice,int row,int col){
 
     if(row_check(choice,row,col) || col_check(choice,row,col) || d_check(choice,row,col)){
        return true;
     }
    return false;
}

void solve(vector<vector<char>>& board){
    int turns = 0;
    int OR;
    int OC;
    int XR;
    int XC;
    while(true){

    cout << "Enter row and col for A: ";
    cin >> OR >> OC;
    while(!isvalidpos(board,OR,OC)){
        cout << "Enter valid row and col for A: ";
        cin >> OR >> OC;
    }
    board[OR][OC] = 'o';
    turns++;
     print(board);
     if(iswin('o',OR,OC)){
        cout << "A wins";
        return;
     }

     if(turns == 9) break;
    
    cout << "Enter row and col for B: ";
    cin >> XR >> XC;
     while(!isvalidpos(board,XR,XC)){
        cout << "Enter valid row and col for B: ";
        cin >> XR >> XC;
    }
    
    board[XR][XC] = 'x';
    turns++;
    print(board);
    if(iswin('x',XR,XC)){
        cout << "B wins";
        return;
    }
    
    
    
    }

    cout << "game drawn"<<endl;




}
int main(){
    
    

    print(board);
    
    solve(board);
    
}