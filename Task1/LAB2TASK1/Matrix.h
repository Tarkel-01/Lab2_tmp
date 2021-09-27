#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

class Matrix {
private:
    long double** matrix;
    int AmountOfArrays;
    int AmountOfElements;
public:
    Matrix(const int AmountOfArrays_, const int AmountOfElements_) {
        AmountOfArrays = AmountOfArrays_;
        AmountOfElements = AmountOfElements_;
        matrix = new long double* [AmountOfArrays];
        for (int i = 0; i < AmountOfArrays; i++)
            matrix[i] = new long double[AmountOfElements] {1};
    }
    ~Matrix() {
        for (int i = 0; i < AmountOfArrays; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    Matrix& operator++() {
        for (int i = 0; i < AmountOfArrays; i++)
            for (int j = 0; j < AmountOfElements; j++)
                this->matrix[i][j]++;
        return *this;
    }
    Matrix& operator++(int) {
        ++(*this);
        return *this;
    }

    Matrix& operator--() {
        for (int i = 0; i < AmountOfArrays; i++)
            for (int j = 0; j < AmountOfElements; j++)
                this->matrix[i][j]--;
        return *this;
    }
    Matrix& operator--(int) {
        --(*this);
        return *this;
    }

    int GetAmountOfArrays() {
        return AmountOfArrays;
    }
    int GetAmountOfElements() {
        return AmountOfElements;
    }
    long double At(int i, int j) {
        return matrix[i][j];
    }
    void SetAt(int i, int j, long double value) {
        matrix[i][j] = value;
    }
    void Print() {
        using namespace std;
        cout.precision(4);
        cout << fixed;
        for (int i = 0; i < AmountOfArrays; i++)
        {
            for (int j = 0; j < AmountOfElements; j++)
                cout << setw(10) << matrix[i][j];
            cout << endl;
        }
    }
    void FillForTask() {
        for (int i = 0; i < AmountOfArrays; i++)
            for (int j = 0; j < AmountOfElements; j++)
                matrix[i][j] = sin(i - j) + cos(i + j);
    }
};