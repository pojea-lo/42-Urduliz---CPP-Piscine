#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

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
	Form			*forms[10];
	int				index = 0;
	int				nGrade;

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

//lancemos las posibilidades
	std::cout << "And now, what do you want to do?\n\nNOTE: Please, type only 1-13\n" << std::endl;
	while (reponse.compare("Exit") != 0) {

point2:
		std::cout << "1  - Exit\n2  - Up Bureaucrat Grade\n3  - Down Bureaucrat Grade\n4  - Create a ShrubberyCreationForm\n5  - Sign a ShrubberyCreationForm\n6  - Execute a ShrubberyCreationForm\n7  - Create a RobotomyRequestForm\n8  - Sign a RobotomyRequestForm\n9  - Execute a RobotomyRequestForm\n10 - Create a PresidentialPardonForm\n11 - Sign a PresidentialPardonForm\n12 - Execute a PresidentialPardonForm\n13 - Print all forms" << std::endl;
		std::cin >> reponse;

		if (checkReponse(reponse) == -1)
			goto point2;
		else
			nGrade = std::stoi(reponse);

		switch (nGrade) {
			case (1):
				std::cout << "\nby by...!!\n" << std::endl;
				for (int i = 0; i < index; i++)
					delete forms[i];
				reponse = "Exit";
				break;
		
			case (2):
point3:
				std::cout << "\nPlease type how much you want to promote " << one.getName() << ": ";
				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point3;
				else
					nGrade = std::stoi(reponse);

				one.UpGrade (nGrade);
				std::cout << "\nAfter the promotion: " << one << std::endl;
				break;
	
			case (3):
point4:
				std::cout << "\nPlease type how much you want to degrade " << one.getName() << ": ";
				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point4;
				else
					nGrade = std::stoi(reponse);

				one.DownGrade (nGrade);
				std::cout << "\nAfter the degradate: " << one << std::endl;
				break;
	
			case (4):
				try {
					if (index < 10) {
						forms[index] = new ShrubberyCreationForm();
						index++;
					}
					else
						throw 1;
				}
				catch (int ex) {
					if (ex == 1)
						std::cout << "Sorry but you work too much, you can't create more forms!!" << std::endl;
				goto point2;
				}
				break;
	
			case (5):
				std::cout << "\nI will try to sign a ShrubberyCreationForm. Please type the number: ";

				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point2;
				else
					nGrade = std::stoi(reponse);
				try {
					if (nGrade < index) {
						if (forms[nGrade]->getName().compare("ShrubberyCreationForm") == 0)
							one.beSigned(*forms[nGrade]);
						else
							throw 1;
					}
					else
						throw 2;
				}
				catch (int ex) {
					if (ex == 1)
						std::cout << "\nAre you sure that the form " << nGrade << " is ShrubberyCreationForm type??\n" << std::endl;
					else if (ex == 2)
						std::cout << "\nI'm sorry, but I can't find the form " << nGrade << " that you type!!\n" << std::endl;
				}	
				break;
	
			case (6):
				std::cout << "\nI will try to execute a ShrubberyCreationForm. Please type the number: ";

				std::cin >> reponse;
				if (checkReponse(reponse) == -1)
					goto point2;
				else
					nGrade = std::stoi(reponse);
				try {
					if (nGrade < index) {
						if (forms[nGrade]->getName().compare("ShrubberyCreationForm") == 0)
							forms[nGrade]->execute(one);
						else
							throw 1;
					}
					else
						throw 2;
				}
				catch (int ex) {
					if (ex == 1)
						std::cout << "\nAre you sure that the form " << nGrade << " is ShrubberyCreationForm type??\n" << std::endl;
					else if (ex == 2)
						std::cout << "\nI'm sorry, but I can't find the form " << nGrade << " that you type!!\n" << std::endl;
				}	
				break;
	

			case (13):
				std::cout << "\nNumber:      Type:" << std::endl;
				for (int i = 0; i < index; i++)
					std::cout << "  " << i << " -  " << forms[i]->getName() << std::endl;				 std::cout << std::endl;
				break;
					
			default:
				std::cout << "Please try again!!" << std::endl;
		}
	}

/*	Bureaucrat				one("Pablo", 25);
	ShrubberyCreationForm	*two = new ShrubberyCreationForm();

	std::cout << one << std::endl;
	std::cout << two << std::endl;

	one.beSigned(*two);
	two->execute(one);

	delete two;
*/





	return 0;
}
