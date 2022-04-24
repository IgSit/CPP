#include <iostream>

using namespace std;

#include "matrix.h"

TwoDimensionMatrix::TwoDimensionMatrix() : matrix() {
    for (auto & i : this->matrix) {
        for (int & j : i) {
            j = 0;
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(TwoDimensionMatrix const &twoDimensionMatrix) : matrix() {
    for (int i = 0; i < (int) size; ++i) {
        for (int j = 0; j < (int) size; ++j) {
            this->matrix[i][j] = twoDimensionMatrix.get(i, j);
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement matrixElement[size][size]) : matrix() {
    for (int i = 0; i < (int) size; ++i) {
        for (int j = 0; j < (int) size; ++j) {
            this->matrix[i][j] = matrixElement[i][j];
        }
    }
}

MatrixElement TwoDimensionMatrix::get(int i, int j) const {
    return matrix[i][j];
}

TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &array) {
    if (this == &array) return *this;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            this->matrix[i][j] = array[i][j];
        }
    }
    return *this;
}

std::istream &operator>>(std::istream &input, TwoDimensionMatrix &array) {
    for (auto & i : array.matrix) {
        for (int & j : i) {
            input >> j;
        }
    }
    return input;
}

std::ostream &operator<<(std::ostream& output, TwoDimensionMatrix const& array) {
    for (int i = 0; i < array.getSize(); ++i) {
        for (int j = 0; j < array.getSize(); ++j) {
            output << array.get(i, j) << " ";
        }
        output << "\n";
    }
    return output;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2) {
    size_t n = matrix1.getSize();
    TwoDimensionMatrix result;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.matrix[i][j] = matrix2.get(i, j) + matrix1.get(i, j);
        }
    }
    return result;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for (auto & i : matrix) {
        for (int & j : i) {
            j *= number;
        }
    }
    return reinterpret_cast<TwoDimensionMatrix &>(matrix);
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &array) const {
    TwoDimensionMatrix result;
    size_t n = array.getSize();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result.matrix[i][j] = this->matrix[i][j] && array.matrix[i][j];
        }
    }
    return result;
}

MatrixElement *TwoDimensionMatrix::operator[](size_t i) {
    return this->matrix[i];
}

const MatrixElement *TwoDimensionMatrix::operator[](size_t i) const {
    return matrix[i];
}

TwoDimensionMatrix::operator size_t() const {
    return size;
}
