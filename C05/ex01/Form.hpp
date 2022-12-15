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
		Form(const std::string _name, int _GradeToSign, int _GradeToExecute);
		Form(const Form &obj);
		~Form();

		Form			operator= (const Form &obj);

		std::string		getName() const;
		bool			getStatus() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		void			setStatus();
		void			setGradeToSign(int n);

		class		GradeTooHighException : public std::exception {

			public:
				const char *what() const throw() {
					return ("Grade too high for the form!!\n");
				}
		};

		class		GradeTooLowException : public std::exception {

			public:
				const char *what() const throw() {
					return ("Grade too low for the form!!\n");
				}
		};

};

std::ostream		&operator<< (std::ostream &os, const Form &obj);

#endif
