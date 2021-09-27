#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

class Vector {
private:
    long double* array;
    int Length;
public:
    Vector() {
        this->array = new long double[0];
        Length = 0;
    }
    Vector(int Size) {
        this->array = new long double[Size];
        this->Length = Size;
        for (int i = 0; i < Length; i++)
            this->array[i] = 1;
    }
    Vector(const Vector& T) {
        this->Length = T.Length;
        this->array = new long double[T.Length];
        for (int i = 0; i < Length; i++)
            this->array[i] = T.array[i];
    }
    ~Vector() {
        delete[] this->array;
    }
    int GetLength() const {
        return this->Length;
    }

    Vector& operator++() {
        for (int i = 0; i < Length; i++)
            this->array[i]++;
        return *this;
    }

    Vector& operator++(int) {
        ++(*this);
        return *this;
    }

    Vector& operator--() {
        for (int i = 0; i < Length; i++)
            this->array[i]--;
        return *this;
    }
    Vector& operator--(int) {
        --(*this);
        return *this;
    }
    long double& operator[](int index) {
        return this->array[index];
    }
    Vector& operator=(const Vector& T) {
        if (this == &T)
            return *this;
        if (array) {
            delete[] array;
            array = nullptr;
        }
        this->Length = T.Length;
        this->array = new long double[T.Length];
        for (int i = 0; i < Length; i++)
            this->array[i] = T.array[i];
        return *this;
    }
    void Print() {
        for (int i = 0; i < this->Length; i++)
            std::cout << this->array[i] << ' ';
    }
    friend std::ostream& operator<< (std::ostream& out, const Vector& vector);
};
std::ostream& operator<< (std::ostream& out, const Vector& v)
{
    for (int i = 0; i < v.GetLength(); i++)
        out << std::setw(10) << v.array[i] << ' ';
    return out;
}