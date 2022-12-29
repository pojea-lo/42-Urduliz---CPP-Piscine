#include "mutantstack.cpp"

#include <list>

int main() {

    MutantStack<int>    mstack;

//Llenamos el stack
    std::cout << "\n________________MY-STACK___________________\n" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "\nIn this point the top of MY stack was: " << mstack.top() << ", and the size: " << mstack.size() << std::endl;
    
    mstack.pop();
    
    std::cout << "\nAfter erase one, the top of MY stack was: " << mstack.top() << ", and the size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "It: " << *it << ", and ite: " << *ite << std::endl;
    ++it;
    --it;
    std::cout << "It: " << *it << ", and ite: " << *ite << std::endl;

    std::cout << "\nAnd now, MY stack is: ";

    while (it != ite) {
        std::cout << *it << "   ";
        ++it;
    }
    std::cout << std::endl;


    MutantStack<int>::reverse_iterator itr = mstack.rbegin();
    MutantStack<int>::reverse_iterator iter = mstack.rend();
    
    --iter;
    std::cout << "Itr: " << *itr << ", and iter: " << *iter << std::endl;
    ++itr;
    --itr;
    std::cout << "Itr: " << *itr << ", and iter: " << *iter << std::endl;

    ++iter;
    std::cout << "\nAnd now, MY stack is: ";

    while (itr != iter) {
        std::cout << *itr << "   ";
        ++itr;
    }
    std::cout << std::endl;


//Hacemos lo mismo con el stack std:
    std::cout << "\n_______________STD-STACK___________________\n" << std::endl;
    
    std::stack<int>    s(mstack);
    std::list<int>     st;

    st.push_back(5);
    st.push_back(17);
    std::cout << "\nIn this point the top of STD stack was: " << st.back() << ", and the size: " << st.size() << std::endl;
    
    st.pop_back();
    
    std::cout << "\nAfter erase one, the top of STD stack was: " << st.back() << ", and the size: " << st.size() << std::endl;
    
    st.push_back(3);
    st.push_back(5);
    st.push_back(737);
    st.push_back(0);

    std::list<int>::iterator its = st.begin();
    std::list<int>::iterator ites = st.end();
    ++its;
    --its;

    std::cout << "\nAnd now, STD stack is: ";

    while (its != ites) {
        std::cout << *its << "   ";
        ++its;
    }
    std::cout << std::endl;
    
    return 0;
}