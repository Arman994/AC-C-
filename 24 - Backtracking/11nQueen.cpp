//Place N queens on an NxN chessboard such that no 2 queens can attack each other        TC = O(n!)        SP = O(nxn)

#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<char>> board) {
    int n = board.size();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "____________________\n";
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();

    //horizontal
    for(int j=0; j<n; j++) {
        if(board[row][j] == 'Q') {
            return false;
        }
    }

    //vertical
    for(int i=0; i<row; i++) { //i<row cause row keeps changing
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    //diagonal left
    for(int i=row, j=col; i>= 0 && j>=0; i--,j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    //diagonal right
    for(int i=row, j=col; i>=0 && j<n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    return true;

}

int nQueens(vector<vector<char>> board, int row) {
    int n = board.size();
    if(row == n) {
        printBoard(board);
        return 1;
    }

    int count = 0;
    for(int j=0; j<n; j++) {
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';
        }
    }

    return count; //no of possible solutions at each level
}

int main() {
    vector<vector<char>> board;
    int n = 5;

    for(int i=0; i<n; i++) {
        vector<char> newRow;
        for(int j=0; j<n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }
    
    int count = nQueens(board, 0);
    cout << "count : " << count << endl;
    return 0;
}