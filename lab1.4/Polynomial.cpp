// Polynomial.cpp
#include "polynomial.h"
#include <iostream>
#include <cstring>
#include <sstream>

Polynomial::Polynomial() : n(0), coefficients(nullptr) {}

Polynomial::Polynomial(int n, int* coefficients) : n(n) {
    this->coefficients = new int[n + 1];
    std::memcpy(this->coefficients, coefficients, sizeof(int) * (n + 1));
}

int Polynomial::getDegree() const {
    return n;
}

int Polynomial::getCoefficient(int index) const {
    if (index >= 0 && index <= n) {
        return coefficients[index];
    }
    else {
        return 0;
    }
}

void Polynomial::setCoefficient(int index, int value) {
    if (index >= 0 && index <= n) {
        coefficients[index] = value;
    }
}

void Polynomial::Init(int n, int* coefficients) {
    this->n = n;
    delete[] this->coefficients;
    this->coefficients = new int[n + 1];
    std::memcpy(this->coefficients, coefficients, sizeof(int) * (n + 1));
}

void Polynomial::Read() {
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> n;

    int* newCoefficients = new int[n + 1];

    std::cout << "Enter the coefficients from a0 to an separated by spaces: ";
    for (int i = 0; i <= n; ++i) {
        std::cin >> newCoefficients[i];
    }

    Init(n, newCoefficients);

    delete[] newCoefficients;  // Release memory allocated for temporary coefficients array
}


void Polynomial::Display() const {
    std::cout << "P(x) = " << coefficients[0];
    for (int i = 1; i <= n; ++i) {
        std::cout << " + " << coefficients[i] << "*x^" << i;
    }
    std::cout << std::endl;
}

const char* Polynomial::ToString() const {
    std::string result = "P(x) = " + std::to_string(coefficients[0]);
    for (int i = 1; i <= n; ++i) {
        result += " + " + std::to_string(coefficients[i]) + "*x^" + std::to_string(i);
    }
    // Creating a copy of the string and returning a pointer to const char
    return _strdup(result.c_str());
}

int Polynomial::evaluate(int x) {
    int result = 0;
    int power = 1;
    for (int i = 0; i <= n; ++i) {
        result += coefficients[i] * power;
        power *= x;
    }
    return result;
}

// додавання
Polynomial Polynomial::add(const Polynomial& other) {
    int maxDegree = std::max(n, other.n);
    int* resultCoefficients = new int[maxDegree + 1];

    for (int i = 0; i <= maxDegree; ++i) {
        resultCoefficients[i] = getCoefficient(i) + other.getCoefficient(i);
    }

    Polynomial result(maxDegree, resultCoefficients);
    delete[] resultCoefficients;

    return result;
}

// віднімання
Polynomial Polynomial::subtract(const Polynomial& other) {
    int maxDegree = std::max(n, other.n);
    int* resultCoefficients = new int[maxDegree + 1];

    for (int i = 0; i <= maxDegree; ++i) {
        resultCoefficients[i] = getCoefficient(i) - other.getCoefficient(i);
    }

    Polynomial result(maxDegree, resultCoefficients);
    delete[] resultCoefficients;

    return result;
}

// множення
Polynomial Polynomial::multiply(const Polynomial& other) {
    int resultDegree = n + other.n;
    int* resultCoefficients = new int[resultDegree + 1];

    for (int i = 0; i <= resultDegree; ++i) {
        resultCoefficients[i] = 0;
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= other.n; ++j) {
            resultCoefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    Polynomial result(resultDegree, resultCoefficients);
    delete[] resultCoefficients;

    return result;
}
