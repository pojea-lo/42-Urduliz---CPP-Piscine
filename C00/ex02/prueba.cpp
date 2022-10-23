#include <iostream>
#include <vector>
#include <time.h>

int	main(void) {

	int const			v[] = {90,2,3,4};
	size_t const		v_size(sizeof(v) / sizeof(int));
	std::vector<int>	prueba(v, v + v_size);

	time_t				now;
	struct				tm *local = localtime(&now);

	time(&now); ctime(&now);

	std::cout << "[" << local->tm_year + 1900 << local->tm_mon + 1 << local->tm_mday;
	std::cout << "_" << (local->tm_hour * 3600) + (local->tm_min * 60) + (local->tm_sec) << "]" << std::endl;


	std::cout << "Sizeof v: " << sizeof (v) << std::endl;
	std::cout << "El v: " << v << std::endl;
	std::cout << "Y la suma con v: " << v + v_size << std::endl;

/*	for(int i = 0; i < prueba.size(); i++) {

		std::cout << "Valores del vector: " << prueba[i] << std::endl;
		std::cout << "Valores del v_size: " << v_size << std::endl;
		std::cout << "Valores de la suma: " << v[i] + v_size << std::endl;
	}
*/

	return(0);
}
