#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>

void    easyfind(const std::vector<T> &t, const int &n) {

    try {
        auto pos = std::find(t.begin(), t.end(), n);
        if (pos != t.end())   
            std::cout << "Yes" << std::endl;
        else
            throw 1;
    }
    catch (int ex) {
        std::cout << "No coincidence!!" << std::endl;
    }
    return;

}

#endif
