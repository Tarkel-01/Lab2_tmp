#include <iostream>
#include <cmath>
#include <string.h>
class Fraction {
private:
    int x;
    int y;
    static int Count;
public:
    Fraction() {
        x = 0;
        y = 1;
        Count++;
    }
    Fraction(int a1, int a2) {
        x = a1;
        y = a2;
        Count++;
    }
    void Print() {
        std::cout << x << '/' << y;
    }
    void reduce() {
        int tmp = gcd(x, y);
        x /= tmp;
        y /= tmp;
    }
    Fraction& operator+(const Fraction& T) {
        Fraction tmp = *this;
        tmp.x = x * T.y + T.x * y;
        tmp.y = y * T.y;
        tmp.reduce();
        return tmp;
    }
    Fraction& operator-(const Fraction& T) {
        Fraction tmp(-T.x, T.y);
        Count--;
        return *this + tmp;
    }
    Fraction& operator*(const Fraction& T) {
        Fraction tmp(x * T.x, y * T.y);
        Count--;
        tmp.reduce();
        return tmp;
    }
    Fraction& operator/(const Fraction& T) {
        Fraction tmp(T.y, T.x);
        Count--;
        return tmp * (*this);
    }
    static int GetCount();
    static void NextCount();
    static int gcd(int a1, int a2);
    static void printAsFraction(char* decimal_fraction);
    static void printAsFraction(double decimal_fraction);
};

int Fraction::Count = 0;

int Fraction::GetCount() {
    return Count;
}
void Fraction::NextCount() {
    Count++;
}
int Fraction::gcd(int a1, int a2) {
    int tmp;
    if (a1 > a2) {
        tmp = a1;
        a1 = a2;
        a2 = tmp;
    }
    while (a1 > 0) {
        tmp = a2;
        a2 = a1;
        a1 = tmp % a1;
    }
    return a2;
}
void Fraction::printAsFraction(char* decimal_fraction)
{
    int pos_dot = -1;
    bool checking = true;

    char* preDotsDigit = new char[strlen(decimal_fraction)];
    char* postDotsDigit = new char[strlen(decimal_fraction)];
    postDotsDigit[0] = '\0';
    for (int i = 0; i < strlen(decimal_fraction); i++)
    {
        if (decimal_fraction[i] == '.')
        {
            if (pos_dot != -1) {
                checking = false;
                break;
            }
            pos_dot = i;
        }
        else if (!(decimal_fraction[i] >= '0' && decimal_fraction[i] <= '9')) {
            checking = false;
            break;
        }
        else if (pos_dot == -1) {
            preDotsDigit[i] = decimal_fraction[i];
            preDotsDigit[i + 1] = '\0';
        }
        else {
            postDotsDigit[i - pos_dot - 1] = decimal_fraction[i];
            postDotsDigit[i - pos_dot] = '\0';
        }

    }
    if (!checking) {

        std::cout << "Wrong input!" << std::endl;
        return;
    }
    int y_ = pow(10, strlen(postDotsDigit));
    int x_ = atoi(preDotsDigit) * pow(10, strlen(postDotsDigit)) + atoi(postDotsDigit), tmp = y_;
    y_ /= gcd(y_, x_);
    x_ /= gcd(tmp, x_);
    std::cout << x_ << '/' << y_;
}
void Fraction::printAsFraction(double decimal_fraction) {
    int whole = decimal_fraction, ForPow = 0;
    while (decimal_fraction - whole > 0) {
        decimal_fraction *= 10;
        whole = decimal_fraction;
        ForPow++;
    }
    int x = whole, y = pow(10, ForPow), tmp = y;
    y /= gcd(y, x);
    x /= gcd(tmp, x);
    std::cout << x << '/' << y;

}
int main() {
    Fraction d1(1, 2), d2(1, 4);
    Fraction result = d1 + d2;
    Fraction::NextCount();

    result.Print();
    std::cout << std::endl;

    result = d1 - d2;
    result.Print();
    std::cout << std::endl;

    result = d1 * d2;
    result.Print();
    std::cout << std::endl;

    result = d1 / d2;
    result.Print();
    std::cout << std::endl;

    Fraction::printAsFraction(12.36);
    std::cout << std::endl;

    char a[] = "12.36";
    Fraction::printAsFraction(a);
    std::cout << std::endl;

    std::cout << Fraction::gcd(12, 36);
    std::cout << std::endl;

    std::cout << Fraction::GetCount();


    return 0;
}