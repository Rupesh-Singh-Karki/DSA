#include<iostream> 
#include<vector>
using namespace std;
void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    // Check for the same row
    while(y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    // Check for upper diagonal
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;

    // Check for lower diagonal
    while(x < n && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
        x++;
    }

    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    // Base case
    if(col == n) {
        addSolution(ans, board, n);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            // If placing the queen is safe
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            // Backtrack
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);

    return ans;
}