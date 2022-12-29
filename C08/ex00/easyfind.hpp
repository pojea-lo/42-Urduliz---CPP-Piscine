#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template <class T>

void    easyfind(const std::vector<T> &t, const int &n) {

    try {
        for (size_t i = 0; i < t.size(); i++) {
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
