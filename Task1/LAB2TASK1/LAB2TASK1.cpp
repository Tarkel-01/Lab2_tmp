#pragma once 

#include"Matrix.h"
#include"Vector.h"

void  From2Din1D(Vector& v, Matrix& m) {
    int size = m.GetAmountOfElements() * m.GetAmountOfArrays(), now = 0;
    Vector tmp(size);
    for (int i = 0; i < m.GetAmountOfArrays(); i++)
        for (int j = 0; j < m.GetAmountOfElements(); j++, now++)
            tmp[now] = m.At(i, j);
    v = tmp;
}

int main() {
    Vector a;
    Matrix b(5, 3);
    
    b.FillForTask();
    b.Print();
    std::cout << std::endl;

    From2Din1D(a, b);
    std::cout << "[ " << a << " ]";
    return 0;
}