/*
Criar programa que:
    solicita entradas do usuário com inteiros
    armazena-os em um vetor
    mostra na ordem digitada
    mostra o maior e menor
    imprime em oredem crscente
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{

    //Welcome message

    std::cout << "Hello! Welcome to Vector Sorter!" << endl << endl;
    std::cout << "Put the vector index max(or size):" << endl;

    //Getting users size vector information int index

    int index;

    std::cin >> index;

    std::vector<int> vec(index); //initialize int vector with user's index

    //Getting the integers values to push into vector
    std::cout << "Input " << vec.size() << " integers of vector(separated by blankspace):" << endl;

    for(int i = 0 ; i < index ; i++){std::cin >> vec[i];}  //inline for

    std::cout << "Your vector is: " << endl;

    for(int i = 0 ; i < index ; i++) {std::cout << vec[i] << " ";} //showing vector to user

    std::cout << endl;

    //Sorting and showing max and min elements

    std::sort (vec.begin(),vec.end()); //Sorting vector crescently

    std::cout << "Your max integer is: " << endl << *std::max_element(vec.begin(),vec.end()) << endl; //unnecessary, but elegant max_element

    std::cout << "Your min integer is: " << endl << *std::min_element(vec.begin(),vec.end()) << endl; //and min_element function

    std::cout << "Your vector sorted is:" << endl;

    for(int i=0; i< index; i++) {std::cout << vec[i] << " ";} //showing the sorted vector

    std::cout << endl;

    return 0;
}
