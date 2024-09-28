#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

enum Color { WHITE, BLACK };

class Piece {
protected:
    Color color;
    string symbol;

public:
    Piece(Color c, const string& s) : color(c), symbol(s) {}
    virtual ~Piece() {}
    
    Color getColor() const { return color; }
    string getSymbol() const { return symbol; }

    // Fungsi virtual untuk memeriksa validitas gerakan
    virtual bool isValidMove(int startX, int startY, int endX, int endY, vector<vector<Piece*>>& board) = 0;
};

// Kelas Pawn (Bidak)
class Pawn : public Piece {
public:
    Pawn(Color c) : Piece(c, (c == WHITE ? "P" : "p")) {}

    bool isValidMove(int startX, int startY, int endX, int endY, vector<vector<Piece*>>& board) override {
        int direction = (color == WHITE) ? -1 : 1;
        if (startX + direction == endX && startY == endY && !board[endX][endY]) {
            return true;  // Gerakan maju satu langkah
        }
        return false;
    }
};

// Kelas Rook (Benteng)
class Rook : public Piece {
public:
    Rook(Color c) : Piece(c, (c == WHITE ? "R" : "r")) {}

    bool isValidMove(int startX, int startY, int endX, int endY, vector<vector<Piece*>>& board) override {
        if (startX == endX || startY == endY) {
            for (int i = min(startX, endX) + 1; i < max(startX, endX); ++i) {
                if (board[i][startY] != nullptr) return false;  // Tidak boleh ada halangan di jalur
            }
            for (int j = min(startY, endY) + 1; j < max(startY, endY); ++j) {
                if (board[startX][j] != nullptr) return false;  // Tidak boleh ada halangan di jalur
            }
            return true;
        }
        return false;
    }
};

// Kelas King (Raja)
class King : public Piece {
public:
    King(Color c) : Piece(c, (c == WHITE ? "K" : "k")) {}

    bool isValidMove(int startX, int startY, int endX, int endY, vector<vector<Piece*>>& board) override {
        return (abs(endX - startX) <= 1 && abs(endY - startY) <= 1);
    }
};

#endif
