#include <iostream>
#include <fstream>
#include <string>

std::string	ft_replace(std::string buffer, std::string s1, std::string s2) {
	
	std::string		newstr = "";
	std::string		bufferup = "";
	int				ls1 = s1.length();
	int				lbuffer = buffer.length();
	size_t			pos = buffer.find(s1);

	while (pos < buffer.length()) {

		bufferup = buffer;
		buffer.erase (0, pos + ls1);
		bufferup.erase (pos, lbuffer - pos);
		newstr.append(bufferup);
		newstr.append(s2);
		pos = buffer.find(s1);
	}
	return (newstr);
}

int	main(void) {

	std::string		resp = "";
	std::string		s1 = "";
	std::string		s2 = "";
	std::string		allfile = "";
	std::string		buffer = "";
	std::string		line = "";
	bool			op = false;

//bucle de lectura del nombre del archivo
	initial:
	std::cout << "Please type file name to work: ";
	std::cin >> resp;
	std::ifstream file(resp);
	while (!op) {

		if (file.is_open())
			op = true;
		
		else {
			std::cout << "Open error\n";
			goto initial;
		}
  	}

//bucle de introduccion de cadenas a reemplazar
	std::cout << "Please type now the string to find: ";
	std::cin >> s1;
	std::cout << "Please type now the string to replace: ";
	std::cin >> s2;

//bucle de analisis del texto
	while(getline(file,line)){
        buffer += line + "\n";
    }

	if (buffer.find(s1) < buffer.length()) {
		allfile = ft_replace(buffer, s1, s2);
		std::cout << "\nThe new text is *************************************************\n\n";
		std::cout << allfile << std::endl;
		std::cout << "*****************************************************************\n";
	}
	else {
		std::cout << "\nThere's no coincidence\n";
		std::cout << "The original text is ********************************************\n\n";
		std::cout << buffer << std::endl;
		std::cout << "*****************************************************************\n";
	}
	return 0;
}
