#include <iostream>
#include <stdlib.h>
#include <vector>

#include "ComplexNumbers.h"

using namespace std;


int main()
{
    std::cout << "Hello! Welcome to Complex Numbers Calculator" << endl << endl;
    ComplexNumbers<double> number_1;
    ComplexNumbers<double> number_2;
    ComplexNumbers<double> number_3;

    std::cout << "Lets get your complex numbers to calculate..." << endl << endl;
    std::cin >> number_1;
    std::cout << endl << endl;
    std::cin >> number_2;
    std::cout << endl << endl;

    std::cout << "Complex Number(1) is: " << number_1 << " and Complex Number(2) is: " << number_2 << endl << endl;

    //Summing complex values
    std::cout << "(1) + (2) is: ";
    number_3 = number_1 + number_2;
    std::cout << number_3 << endl;

    //Subtracting complex values
    std::cout << "(1) - (2) is: ";
    number_3 = number_1 - number_2;
    std::cout << number_3 << endl;

    //Multiplying complex values
    std::cout << "(1) * (2) is: ";
    number_3 = number_1 * number_2;
    std::cout << number_3 << endl;

    //Dividing complex values
    std::cout << "(1) / (2) is: ";
    number_3 = number_1 / number_2;
    std::cout << number_3 << endl;


    return 0;
}
