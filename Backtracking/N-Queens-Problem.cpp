#include <iostream>
int n = 5;
bool board[5][5];

using namespace std;

bool isSafe(int row, int col) {
    for(int i = 0; i < col; i++) {
        if(board[row][i]) return false;
    }
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j]) return false;
    }
    for(int i = row, j = col; i < n && j >= 0; i++, j--) {
        if(board[i][j]) return false;
    } 
    return true;
}

bool solve(int col) {
    if(col == n) return true;
    for(int i = 0; i < n; i++) {
        if(isSafe(i, col)) {
            board[i][col] = 1;
            if(solve(col + 1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

// Super naive solution - n ^ 2 C n configurations
// We generate all possible configurations of 0 to n - 1. Then we iterate through the permutationsto check if queens don't capture
// Backtracking solution - Backtrack when we think the recursion tree is going to lead to a solution

int main() {
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) board[i][j] = false;
    // }
    if(solve(0) == false) cout<<"No Solution!";
    else {
        cout<<"The board for N queens problem : \n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) cout<<board[i][j]<<" ";
            cout<<"\n";
        }
    }
}

// The board for N queens problem : 
// 1 0 0 0 0 
// 0 0 0 1 0 
// 0 1 0 0 0 
// 0 0 0 0 1 
// 0 0 1 0 0
