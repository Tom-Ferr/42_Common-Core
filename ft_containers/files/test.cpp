
#include <iostream>
#if _STL
	# include <vector>
	# include <stack>
	namespace ft = std;
#else
	# include <vector.hpp>
	# include <stack.hpp>
#endif
int main() {
	ft::vector<int> vec(5ul, 33);
	vec[0] = 132;
	vec.push_back(42);
	std::cout << vec.end() - vec.begin()<< std::endl;
	ft::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << std::endl;
	}


	return 0;
}
