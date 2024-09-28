#include <iostream>
#include "board.h.cpp"

int main() {
    Board board;
    string move;
    int startX, startY, endX, endY;
    bool isWhiteTurn = true;

    cout << "Permainan Catur Sederhana\n";
    cout << "Format input gerakan: 'startX startY endX endY'\n";
    
    while (true) {
        board.printBoard();
        cout << (isWhiteTurn ? "Putih" : "Hitam") << "'s turn. Masukkan gerakan: ";
        cin >> startX >> startY >> endX >> endY;
        
        if (board.movePiece(startX, startY, endX, endY)) {
            isWhiteTurn = !isWhiteTurn;
        } else {
            cout << "Gerakan tidak valid. Coba lagi.\n";
        }

        // Tambahkan pengecekan check, checkmate, atau promosi
    }

    return 0;
}
