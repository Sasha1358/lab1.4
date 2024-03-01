//source.cpp
#include "polynomial.h"
#include <iostream>
#include <cstring>

int main() {
    Polynomial poly1, poly2, result;
    int x;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enter the first polynomial\n";
        std::cout << "2. Display the first polynomial\n";
        std::cout << "3. Enter the second polynomial\n";
        std::cout << "4. Display the second polynomial\n";
        std::cout << "5. Add two polynomials\n";
        std::cout << "6. Subtract two polynomials\n";
        std::cout << "7. Multiply two polynomials\n";
        std::cout << "8. Evaluate a polynomial\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the first polynomial:\n";
            poly1.Read();
            break;
        case 2:
            std::cout << "First polynomial:\n";
            poly1.Display();
            break;
        case 3:
            std::cout << "Enter the second polynomial:\n";
            poly2.Read();
            break;
        case 4:
            std::cout << "Second polynomial:\n";
            poly2.Display();
            break;
        case 5:
            result = poly1.add(poly2);
            std::cout << "Sum of polynomials:\n";
            result.Display();
            break;
        case 6:
            result = poly1.subtract(poly2);
            std::cout << "Difference of polynomials:\n";
            result.Display();
            break;
        case 7:
            result = poly1.multiply(poly2);
            std::cout << "Product of polynomials:\n";
            result.Display();
            break;
        case 8:
            std::cout << "Enter the value of x to evaluate the polynomial: ";
            std::cin >> x;
            std::cout << "Result of evaluation: " << poly1.evaluate(x) << std::endl;
            break;
        case 0:
            std::cout << "Exiting the program\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}