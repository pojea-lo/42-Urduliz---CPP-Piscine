#include "Fixed.hpp"
#include "Point.hpp"

int	main() {
	
	float	x = 0;
	float	y = 0;
	Point	A;
	Point	B;
	Point	C;
	Point	P;

	std::cout << "Let`s see if a point is inside a triangle defined by us" << std::endl;
	std::cout << "Enter the first vertex of the triangle:\nX: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	A.setX(x);
	A.setY(y);
	std::cout << "The second vertex:\nX: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	B.setX(x);
	B.setY(y);
	std::cout << "The last vertex of the triangle:\nX: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	C.setX(x);
	C.setY(y);
	std::cout << "The point to controle:\nX: ";
	std::cin >> x;
	std::cout << "Y: ";
	std::cin >> y;
	P.setX(x);
	P.setY(y);
	std::cout << A << std::endl;
	std::cout << "And the point is......";

//Two equal vertex
	if (A == B || A == C || B == C) {
		std::cout << "Sorry, but two vertex are equal!!" << std::endl;
		return 0;
	}

	if (bsp(A, B, C, P))
		std::cout << "INSIDE!!!" << std::endl;
	else
		std::cout << "OUTSIDE!!!" << std::endl;

	return 0;
}
