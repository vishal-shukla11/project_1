#include <iostream>
#include <vector>

using namespace std;

// Function to print the board
void printBoard(const vector<vector<int> >& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(const vector<vector<int> >& board, int row, int col) {
    int N = board.size();

    // Check this row on the left side
    for (int i = 0; i < col; ++i)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; ++i, --j)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve the N-Queens problem
bool solveNQueensUtil(vector<vector<int> >& board, int col) {
    int N = board.size();
    if (col >= N)
        return true;

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place this queen in board[i][col]

            if (solveNQueensUtil(board, col + 1))
                return true;

            board[i][col] = 0; // If placing queen in board[i][col] doesn't lead to a solution, then remove queen
        }
    }

    return false; // If the queen cannot be placed in any row in this column col, return false
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(int N) {
    vector<vector<int> > board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printBoard(board);
    return true;
}

int main() {
    int N;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
