#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Form {

	private:
		const std::string		name;
		bool					status;
		const int				GradeToSign;
		const int				GradeToExecute;

	public:
		Form();
		Form(const std::string _name, const int _GradeToSign, const int _GradeToExecute);
		Form(const Form &obj);
		~Form();

		Form			operator= (const Form &obj);

		std::string		getName() const;
		bool			getStatus() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			setStatus();

		class		GradeTooHighException : public std::exception {

			public:
				const char *what() const throw() {
					return ("Gradee too high for the form!! I put you the maximum possible");
				}
		};

		class		GradeTooLowException : public std::exception {

			public:
				const char *what() const throw() {
					return ("Gradee too low for the form!! I put you the minimum possible");
				}
		};

};

std::ostream		&operator<< (std::ostream &os, const Form &obj);

#endif
