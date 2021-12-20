//
// Created by Think on 2021/5/20.
//
#ifndef LAB_MATRIX_H
#define LAB_MATRIX_H

#define MAXROWS 5
#define MAXCOLS 5

template<class T>
class Matrix {
private:
    T matrix[MAXROWS][MAXCOLS];
    int rows, cols;

public:
    Matrix();
    Matrix(int r, int c);

    int row();
    int col();
    void printMatrix();

    void setMatrix(T[] [MAXROWS]);
    void addMatrix(T[] [MAXCOLS]);
};

template<class T>
Matrix<T>::Matrix() {
    rows = MAXROWS;
    cols = MAXCOLS;
}

template<class T>
Matrix<T>::Matrix(int r, int c) {
    rows = r;
    cols = c;
}

template<class T>
int Matrix<T>::row() {
    return rows;
}

template<class T>
int Matrix<T>::col() {
    return cols;
}

template<class T>
void Matrix<T>::printMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<class T>
void Matrix<T>::setMatrix(T array[][MAXCOLS]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = array[i][j];
        }
    }
}


template<class T>
void Matrix<T>::addMatrix(T otherArray[][MAXCOLS]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] += otherArray[i][j];
        }
    }
}

#endif //LAB_MATRIX_H
