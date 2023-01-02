#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>

void    easyfind(std::vector<T> &t, const int &n) {

    try {
		typename std::vector<T>::iterator pos = std::find(t.begin(), t.end(), n);
        if (pos != t.end())   
            std::cout << "Yes" << std::endl;
        else
            throw 1;
    }
    catch (int ex) {
        td::cout << "No coincidence!!" << std::endl;
    }
    return;

}

#endif
