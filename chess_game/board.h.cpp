#ifndef BOARD_H
#define BOARD_H

#include "pieces.h.cpp"
#include <vector>

class Board {
private:
    vector<vector<Piece*>> board;

public:
    Board() {
        // Inisialisasi papan catur 8x8
        board.resize(8, vector<Piece*>(8, nullptr));
        setupBoard();
    }

    ~Board() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                delete board[i][j];
            }
        }
    }

    // Setup awal papan catur
    void setupBoard() {
        for (int i = 0; i < 8; ++i) {
            board[1][i] = new Pawn(BLACK);
            board[6][i] = new Pawn(WHITE);
        }
        board[0][0] = new Rook(BLACK);
        board[7][0] = new Rook(WHITE);
        board[0][7] = new Rook(BLACK);
        board[7][7] = new Rook(WHITE);
        board[0][4] = new King(BLACK);
        board[7][4] = new King(WHITE);
    }

    void printBoard() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j]) {
                    cout << board[i][j]->getSymbol() << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    bool movePiece(int startX, int startY, int endX, int endY) {
        if (board[startX][startY] && board[startX][startY]->isValidMove(startX, startY, endX, endY, board)) {
            // Pindahkan bidak
            board[endX][endY] = board[startX][startY];
            board[startX][startY] = nullptr;
            return true;
        }
        return false;
    }
};

#endif
