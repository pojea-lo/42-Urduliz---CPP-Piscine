#include "Bureaucrat.hpp"
#include "Form.hpp"

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
			std::cout << "\nSorry, but you can try only with numbers!!\n" << std::endl;
			return -1;
		}
		else if (ex == 1) {
			std::cout << "\nEy, type only possitie numbers!!\n" << std::endl;
			return -1;
		}
		else if (ex == 2) {
			std::cout << "\nBuffff, you are very powerfull!! Try again with smaller numbers please!!\n" << std::endl;
			return -1;
		}
	}

	return 0;
}

int	main() {

	std::string		reponse;
	std::string		reponse1;
	std::string		reponse2;
	int				nGrade;
	int				nGrade1;

//creamos al burocrata
	std::cout << "Hello, you are going to create your own Bureaucrat.\n\nPlease, type your Name: ";
	std::cin >> reponse;
	Bureaucrat 		one(reponse, 150);
	std::cout << "\nGRADE NOTE: The grade must be between 1 (max) & 150 (min). Let's see what's happend if you put another!!\n" << std::endl;
	point1:
	std::cout << "And now your grade: ";
	std::cin >> reponse;

	if (checkReponse(reponse) == -1)
		goto point1;
	else
		nGrade = std::stoi(reponse);

	one.setGrade(nGrade, "new");
	std::cout << "\nAt first: " << one << std::endl; 

//creamos el formulario
	std::cout << "And now, you are going to create your own Form." << std::endl;
	std::cout << "\nGRADE NOTE: The grade must be between 1 (max) & 150 (min). Let's see what's happend if you put another!!\n" << std::endl;
	
	std::cout << "Please, type his Name: ";
	std::cin >> reponse;
	
	point2:
	std::cout << "The minimum range to signed: ";
	std::cin >> reponse1;
	if (checkReponse(reponse1) == -1)
		goto point2;
	else
		nGrade = std::stoi(reponse1);

	point3:
	std::cout << "The minimum range to executed: ";
	std::cin >> reponse2;
	if (checkReponse(reponse2) == -1)
		goto point3;
	else
		nGrade1 = std::stoi(reponse2);

	Form	two(reponse, nGrade, nGrade1);

	std::cout << two << std::endl;

//lancemos las posibilidades
	std::cout << "And now, what do you want to do?\n\nNOTE: Please, type only 1-2-3-4\n" << std::endl;
	while (reponse.compare("Exit") != 0) {

		point4:
		std::cout << "1 - Exit\n2 - Up Bureaucrat Grade\n3 - Down Bureaucrat Grade\n4 - Sign the form created" << std::endl;
		std::cin >> reponse;

		if (checkReponse(reponse) == -1)
			goto point4;
		else
			nGrade = std::stoi(reponse);

		switch (nGrade) {
			case (1):
				std::cout << "\nby by...!!\n" << std::endl;
				reponse = "Exit";
				break;
			case (2):
				std::cout << "\nPlease type how much you want to promote " << one.getName() << ": ";
				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point4;
				else
					nGrade = std::stoi(reponse);

				one.UpGrade (nGrade);
				std::cout << "\nAfter the promotion: " << one << std::endl;
				break;
			case (3):
				std::cout << "\nPlease type how much you want to degrade " << one.getName() << ": ";
				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point2;
				else
					nGrade = std::stoi(reponse);

				one.DownGrade (nGrade);
				std::cout << "\nAfter the degradate: " << one << std::endl;
				break;
			case (4):
				two.beSigned(one);
				break;
			default:
				std::cout << "Please try again!!" << std::endl;
		}
	}

	return 0;
}
