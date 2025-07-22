#include <iostream>  // To use input/output like cout and cin  
using namespace std;  
  
// A 2D array to store the board's current state  
char board[3][3] = {  
    {'1', '2', '3'},  // Row 1  
    {'4', '5', '6'},  // Row 2  
    {'7', '8', '9'}   // Row 3  
};  
  
// Variables to track current player and their marker (X or O)  
char currentMarker;  
int currentPlayer;  
char player1Marker, player2Marker;  // Store fixed markers for both players  
  
// Function to print the current game board  
void drawBoard() {  
    cout << "\n";  
    cout << "-------------\n";  
    for (int i = 0; i < 3; i++) {  
        cout << "| ";  
        for (int j = 0; j < 3; j++) {  
            cout << board[i][j] << " | ";  
        }  
        cout << "\n-------------\n";  
    }  
    cout << "\n";  
}  
  
// Function to place the marker (X or O) at the selected slot  
bool placeMarker(int slot) {  
    int row = (slot - 1) / 3;  
    int col = (slot - 1) % 3;  
  
    if (board[row][col] != 'X' && board[row][col] != 'O') {  
        board[row][col] = currentMarker;  
        return true;  
    } else {  
        return false;  
    }  
}  
  
// Function to check if any player has won  
bool checkWin() {  
    for (int i = 0; i < 3; i++) {  
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])  
            return true;  
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])  
            return true;  
    }  
  
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])  
        return true;  
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])  
        return true;  
  
    return false;  
}  
  
int main() {  
    cout << "Welcome to the Tic Tac Toe Game!\n\n";  
  
    bool validInput = false;  
    while (!validInput) {  
        cout << "Player 1, choose your marker (Only 'X' or 'O', capital letters only): ";  
        cin >> currentMarker;  
  
        if (currentMarker == 'X' || currentMarker == 'O') {  
            validInput = true;  
        } else {  
            cout << " Invalid input! Only capital letters 'X' or 'O' are allowed.\n";  
        }  
    }  
  
    // Assign markers  
    player1Marker = currentMarker;  
    player2Marker = (player1Marker == 'X') ? 'O' : 'X';  
    currentPlayer = 1;  
  
    drawBoard();  
  
    int slotsFilled = 0;  
    bool gameWon = false;  
  
    while (slotsFilled < 9) {  
        int slot;  
        currentMarker = (currentPlayer == 1) ? player1Marker : player2Marker;  
  
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter a slot (1-9): ";  
        cin >> slot;  
  
        if (slot < 1 || slot > 9) {  
            cout << " Invalid slot! Try again.\n";  
            continue;  
        }  
  
        if (!placeMarker(slot)) {  
            cout << " That slot is already taken! Try another one.\n";  
            continue;  
        }  
  
        drawBoard();  
  
        if (checkWin()) {  
            cout << " Player " << currentPlayer << " wins the game!\n";  
            gameWon = true;  
            break;  
        }  
  
        currentPlayer = (currentPlayer == 1) ? 2 : 1;  
        slotsFilled++;  
    }  
  
    if (!gameWon) {  
        cout << "It's a draw! No one wins.\n";  
    }  
  
    return 0;  
}

