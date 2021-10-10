
#include <iostream>
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
int main() {
	std::cout << _VERSION << std::endl;
	ft::map<int,int> mp;

	mp.insert(ft::make_pair(7,7));
	mp.insert(ft::make_pair(0,0));
	mp.insert(ft::make_pair(8,8));
	mp.insert(ft::make_pair(5,5));
	mp.insert(ft::make_pair(3,3));
	mp.insert(ft::make_pair(4,4));
	mp.insert(ft::make_pair(2,2));
	mp.insert(ft::make_pair(6,6));
	mp.insert(ft::make_pair(9,9));
	mp.insert(ft::make_pair(11,11));
	mp.insert(ft::make_pair(12,12));
	mp.insert(ft::make_pair(10,10));
	mp.insert(ft::make_pair(1,1));
	
	mp[10] = 10;
	mp[0] = 0;
	mp[18] = 18;
	mp[7] = 7;
	mp[15]= 15;
	mp[16] = 16;
	mp[30] = 30;
	mp[42] = 42;
	mp[25] = 25;
	mp[40] = 40;
	mp[60] = 60;
	mp[2] = 2;
	mp[1] = 1;
	mp[70] = 70;
	ft::map<int,int>::iterator it = mp.begin();
	ft::map<int,int>::iterator ite = mp.end();
	for (; it != ite; it++){
		std::cout << it->second << std::endl;
	}
	mp.clear();

	return 0;
}
