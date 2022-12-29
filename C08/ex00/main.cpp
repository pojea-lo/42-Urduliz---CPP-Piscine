#include "easyfind.hpp"

int     main() {

    std::vector<int>     vector(5);
    vector = {1,2,3,4,5};
    int                  n1 = 3;
    int                  n2 = 7;
    int                  n3 = 5;

    std::cout << "The vector of ints is: ";
    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector[i] << "   ";
    std::cout << std::endl;

    std::cout << "\nTry to search: " << n1 << std::endl;;
    easyfind(vector, n1);

    std::cout << "\nTry to search: " << n2 << std::endl;
    easyfind(vector, n2);

    std::cout << "\nTry to search: " << n3 << std::endl;
    easyfind(vector, n3);

    return 0;
}