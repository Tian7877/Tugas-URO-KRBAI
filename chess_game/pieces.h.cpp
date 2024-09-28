#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <vector>
#include <string>

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
        // Implementasi aturan gerakan bidak
        int direction = (color == WHITE) ? -1 : 1;
        if (startX + direction == endX && startY == endY && !board[endX][endY]) {
            return true;  // Gerakan maju satu langkah
        }
        // Tambahkan aturan promosi, capture diagonal, dan en passant
        return false;
    }
};

// Kelas Rook (Benteng)
class Rook : public Piece {
public:
    Rook(Color c) : Piece(c, (c == WHITE ? "R" : "r")) {}

    bool isValidMove(int startX, int startY, int endX, int endY, vector<vector<Piece*>>& board) override {
        if (startX == endX || startY == endY) {
            // Tambahkan logika validasi jalur kosong
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
        // Aturan gerakan raja
        return (abs(endX - startX) <= 1 && abs(endY - startY) <= 1);
    }
};

// Kelas Queen, Knight, Bishop, dan lainnya dapat ditambahkan dengan cara yang mirip.

#endif
