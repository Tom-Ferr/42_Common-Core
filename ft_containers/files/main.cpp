
#include <iostream>
#include <iomanip> 
#include <sstream>
#include <ctime>
#ifdef _LINUX
	# include <cstdlib>
	# include <typeinfo>
	# define nullptr NULL
#endif
#ifdef _STL
	# include <vector>
	# include <stack>
	# include <map>
	# include <set>
	# define _VERSION "STL version"
	namespace ft = std;
#else
	# include <vector.hpp>
	# include <stack.hpp>
	# include <map.hpp>
	# include <set.hpp>
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
	
	clock_t start = clock();
	#include <vector_test.cpp>
	#include <stack_test.cpp>
	#include <map_test.cpp>
	#include <set_test.cpp>
	clock_t end = clock();

	std::cout << std::endl;

	 double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    std::cout << "Time taken by program is : " << *std::fixed 
         << time_taken << std::setprecision(5);
    std::cout << " sec " << std::endl;


	
	return 0 ;
}
