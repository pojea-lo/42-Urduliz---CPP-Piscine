#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class	Bureaucrat {

	private:
		const std::string	Name;
		int					Grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string _Name, int Grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat();

		Bureaucrat		&operator=(const Bureaucrat &obj);

		std::string	getName() const;
		int			getGrade() const;
		void		setGrade(int _Grade, std::string str);

		void		UpGrade(int n);
		void		DownGrade(int n);
		void		beSigned(Form &obj);
		void		signForm(Form &obj);

		class		GradeTooHighException : public std::exception {
			
			public:
				const char *what() const throw() {
					return ("Grade too high for the bureaucrat!! I put you the maximum possible");
				}
		};
		class		GradeTooLowException : public std::exception {
			
			public:
				const char *what() const throw() {
					return ("Grade too low for the bureaucrat!! I put you the minimum possible");
				}
		};

};

std::ostream	&operator<< (std::ostream &os, const Bureaucrat &obj);

#endif
