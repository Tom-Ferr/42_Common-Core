
#include <iostream>
#if _STL
	#include <vector>
	#include <stack>
	namespace ft = std;
#else
	#include <vector.hpp>
	#include <stack.hpp>
#endif
int main() {
	ft::vector<int> vec(5ul, 33);
	// vec[0] = 132;
	// vec.push_back(42);
	// std::cout << vec.end() - vec.begin()<< std::endl;
	// ft::vector<int>::reverse_iterator rit = vec.rbegin();
	// // rit++;
	// std::cout << rit[5] << std::endl;

	std::cout << vec.max_size() << std::endl;

	return 0;
}
