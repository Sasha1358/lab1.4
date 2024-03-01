//Polynomial.h
#pragma once

class Polynomial {
private:
    int n;
    int* coefficients;

public:
    Polynomial();
    Polynomial(int n, int* coefficients);

    int getDegree() const;
    int getCoefficient(int index) const;
    void setCoefficient(int index, int value);

    void Init(int n, int* coefficients);
    void Read();
    void Display() const;
    const char* ToString() const;

    int evaluate(int x);
    Polynomial add(const Polynomial& other);
    Polynomial subtract(const Polynomial& other);
    Polynomial multiply(const Polynomial& other);
};