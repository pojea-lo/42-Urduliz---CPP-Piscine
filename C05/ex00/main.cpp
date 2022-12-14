#include "Bureaucrat.hpp"

int	checkReponse(std::string str) {

	long int	result;

	try {
//controlosi todo lo que me meten son números o signos - +
		for (size_t i = 0; i < str.length(); i++) {
			if ((str[i] < 48 || str[i] > 57) && (str[i] != 43 && str[i] != 45))
				throw 0;
		}
//controlo si me meten un número muy grande
		if (str.length() > 9)
			throw 2;

		result = std::stoi(str);

//controlo si me meten números negativos
		if (result < 0)
			throw 1;
	}
	catch (int ex) {
		if (ex == 0) {
			std::cout << "Sorry, but you can try only with numbers!!" << std::endl;
			return -1;
		}
		else if (ex == 1) {
			std::cout << "Ey, type only possitie numbers!!" << std::endl;
			return -1;
		}
		else if (ex == 2) {
			std::cout << "Buffff, you are very powerfull!! Try again with smaller numbers please!!" << std::endl;
			return -1;
		}
	}

	return 0;
}

int	main() {

	std::string		reponse;
	int				nGrade;

	std::cout << "Hello, you are going to create your own Bureaucrat.\nPlease, type your Name: ";
	std::cin >> reponse;
	Bureaucrat 		one(reponse, 150);
	std::cout << "GRADE NOTE: The grade must be between 1 (max) & 150 (min). Let's see what's happend if you put another!!" << std::endl;
	point1:
	std::cout << "And now your grade: ";
	std::cin >> reponse;

	if (checkReponse(reponse) == -1)
		goto point1;
	else
		nGrade = std::stoi(reponse);

	one.setGrade(nGrade, "new");
	std::cout << "At first: " << one << std::endl; 

	std::cout << "And now, what do you want to do?\nNOTE: Please, type only 1-2-3" << std::endl;
	while (reponse.compare("Exit") != 0) {

		point2:
		std::cout << "1 - Exit\n2 - Up Grade\n3 - Down Grade" << std::endl;
		std::cin >> reponse;

		if (checkReponse(reponse) == -1)
			goto point2;
		else
			nGrade = std::stoi(reponse);

		switch (nGrade) {
			case (1):
				std::cout << "by by...!!" << std::endl;
				reponse = "Exit";
				break;
			case (2):
				std::cout << "Please type how much you want to promote " << one.getName() << ": ";
				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point2;
				else
					nGrade = std::stoi(reponse);

				one.UpGrade (nGrade);
				std::cout << "After the promotion: " << one << std::endl;
				break;
			case (3):
				std::cout << "Please type how much you want to degrade " << one.getName() << ": ";
				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point2;
				else
					nGrade = std::stoi(reponse);

				one.DownGrade (nGrade);
				std::cout << "After the degradate: " << one << std::endl;
				break;
			default:
				std::cout << "Please try again!!" << std::endl;
		}
	}

	return 0;
}
