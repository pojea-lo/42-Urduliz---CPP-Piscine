#include "RPN.hpp"

int     main(int argc, char **argv) {

    if (argc != 2) {

        std::cout << "Error: Bad number of arguments!!" << std::endl;
        return 1;
    }
    else {
      
        RPN     neu(argv[1]);

		neu.ft_print();
    }   

    return 0;
}
