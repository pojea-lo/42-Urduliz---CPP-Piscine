#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span {

	private:
		std::vector<int> 	test;
		size_t				id;
		size_t				nelem;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &obj);
		~Span();

		int		getTest(size_t n) const;
		size_t	getId() const;
		size_t	getNelem() const;

		Span	&operator=(const Span &obj);
		int		&operator[](unsigned int n);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

};

#endif