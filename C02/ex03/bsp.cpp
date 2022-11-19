#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const A, Point const B, Point const C, Point const P) {

	Fixed	W1;
	Fixed	W2;
	Point	D;
	Point	E;

	D = (Point &)B - (Point &)A;
	E = (Point &)C - (Point &)A;

//rectangle triangle
	if (D.getX() == 0)
		D.setX(0.002f);
	if (D.getY() == 0)
		D.setY(0.002f);
	if (E.getX() == 0)
		E.setX(0.002f);
	if (E.getY() == 0)
		E.setY(0.002f);

	W1 = (E.getX() * (A.getY() - P.getY()) + E.getY() * (P.getX() - A.getX())) / ((D.getX() * E.getY()) - (D.getY() * E.getX()));
	W2 = (P.getY() - A.getY() - (W1 * D.getY())) / E.getY();

/*	std::cout << "La D: " << D << std::endl;
	std::cout << "La E: " << E << std::endl;
	std::cout << "La W1: " << W1 << std::endl;
	std::cout << "La W2: " << W2 << std::endl;
	std::cout << W1 + W2 << std::endl;
*/	if (W1 > 0 && W2 > 0 && (W1 + W2) < 1)
		return (true);
	return (false);
}
