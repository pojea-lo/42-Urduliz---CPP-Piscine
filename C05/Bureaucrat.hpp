#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat {

	private:
		std::string		Name;
		size_t			Grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string _Name, size_t Grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();

		Bureaucrat		&operator=(const Bureaucrat &obj);

		std::string		getName();
		void			setName(std::string _Name);
		size_t			getGrade();
		void			setGrade(size_t _Grade);

		void			UpGrade();
		void			DownGrade();

		void			GradeTooHighException();
		void			gradeTooLowException();

};

#endif
