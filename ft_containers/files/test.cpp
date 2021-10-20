
#include <iostream>
#include <sstream>
#if _STL
	# include <vector>
	# include <stack>
	# include <map>
	# define _VERSION "STL version"
	namespace ft = std;
#else
	# include <vector.hpp>
	# include <stack.hpp>
	# include <map.hpp>
	# define _VERSION "FT version"
#endif
int main(int argc, char *argv[]) {
	if(argc < 2 || argc > 3)
		return (std::cout << "Please, insert a number as argument" << std::endl, 1);

	std::string s(argv[1]);
	std::stringstream d(s);
	int seed;
	d >> seed;
	std::srand(seed);

	std::cout << "************ ";
	std::cout << _VERSION ;
	std::cout << " ************" << std::endl;
	std::cout << std::endl;

	// #include <vector_test.cpp>
	// #include <stack_test.cpp>
	#include <map_test.cpp>
	// #include <set_test.cpp>
	
	return 0 ;
}
