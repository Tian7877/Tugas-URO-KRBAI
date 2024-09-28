#include <iostream>
#include <vector>
#include <algorithm> // Untuk std::copy
#include <cstdlib>   // Untuk exit()

using namespace std;

class Matrix {
private:
    vector<vector<double>> mat; // Matriks disimpan sebagai vektor 2D
    int rows;
    int cols;

public:
    // Konstruktor untuk inisialisasi matriks dengan jumlah baris dan kolom
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(r, vector<double>(c, 0));
    }

    // Metode untuk mengisi nilai matriks
    void fillMatrix() {
        cout << "Masukkan elemen matriks " << rows << "x" << cols << ":\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Validasi input angka
                while (!(cin >> mat[i][j])) {
                    cout << "Input tidak valid. Masukkan angka lagi: ";
                    cin.clear(); // Reset kesalahan input
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buang input yang salah
                }
            }
        }
    }

    // Metode untuk mencetak matriks
    void printMatrix() const {
        for (const auto& row : mat) {
            for (const auto& elem : row) {
                cout << elem << " "; // Mencetak elemen tanpa format
            }
            cout << endl;
        }
    }

    // Penjumlahan matriks
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Ukuran matriks tidak cocok untuk penjumlahan." << endl;
            exit(EXIT_FAILURE);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    // Pengurangan matriks
    Matrix operator-(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Ukuran matriks tidak cocok untuk pengurangan." << endl;
            exit(EXIT_FAILURE);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    // Perkalian matriks dengan konstanta
    Matrix operator*(double scalar) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] * scalar;
            }
        }
        return result;
    }

    // Perkalian matriks antar matriks
    Matrix operator*(const Matrix& other) {
        if (cols != other.rows) {
            cout << "Ukuran matriks tidak cocok untuk perkalian." << endl;
            exit(EXIT_FAILURE);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // Transpose matriks
    Matrix transpose() {
        Matrix result(cols, rows); // Ukuran matriks hasil transpos
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }

    // Metode untuk menghitung determinan matriks 2x2
    double determinant() {
        if (rows != 2 || cols != 2) {
            cout << "Determinant hanya bisa dihitung untuk matriks 2x2." << endl;
            exit(EXIT_FAILURE);
        }
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    // Metode untuk rotasi matriks 90 derajat searah jarum jam
    Matrix rotate() {
        Matrix result(cols, rows); // Ukuran matriks hasil rotasi
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[j][rows - 1 - i] = mat[i][j];
            }
        }
        return result;
    }
};

int main() {
    int rows, cols;

    cout << "Masukkan jumlah baris dan kolom matriks: ";
    while (!(cin >> rows >> cols) || rows <= 0 || cols <= 0) {
        cout << "Input tidak valid. Masukkan lagi jumlah baris dan kolom yang benar: ";
        cin.clear(); // Reset kesalahan input
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Buang input yang salah
    }

    Matrix matrix1(rows, cols);
    matrix1.fillMatrix();

    cout << "Matriks 1:\n";
    matrix1.printMatrix();

    // Contoh penjumlahan
    Matrix matrix2(rows, cols);
    matrix2.fillMatrix();

    cout << "Matriks 2:\n";
    matrix2.printMatrix();

    // Menghitung penjumlahan
    Matrix sum = matrix1 + matrix2;
    cout << "Hasil Penjumlahan:\n";
    sum.printMatrix();

    // Menghitung pengurangan
    Matrix difference = matrix1 - matrix2;
    cout << "Hasil Pengurangan:\n";
    difference.printMatrix();

    // Menghitung determinan (jika matriks 2x2)
    if (rows == 2 && cols == 2) {
        cout << "Determinant Matriks 1: " << matrix1.determinant() << endl;
    }

    // Menghitung transpos
    Matrix transposed = matrix1.transpose();
    cout << "Matriks 1 Transpose:\n";
    transposed.printMatrix();

    // Menghitung rotasi
    Matrix rotated = matrix1.rotate();
    cout << "Matriks 1 setelah rotasi:\n";
    rotated.printMatrix();

    return 0;
}
