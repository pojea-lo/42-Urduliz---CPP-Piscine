#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <class T>

void    easyfind(const T &t, const int &n) {

    try {
        for (size_t i = 0; i < (sizeof(t) / sizeof(int)); i++) {
            if (t[i] == n) {
                std::cout << "In the " << i << " possition we have the firs occurrence of " << n << std::endl;
                return;
            }
        }
        throw 1;
    }
    catch (int ex) {
        std::cout << "No coincidence!!" << std::endl;
    }
    return;

}

#endif
