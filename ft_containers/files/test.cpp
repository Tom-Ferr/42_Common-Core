
#include <iostream>
#if _STL
	# include <vector>
	# include <stack>
	# include <map>
	namespace ft = std;
#else
	# include <vector.hpp>
	# include <stack.hpp>
	# include <map.hpp>
#endif
int main() {
	ft::map<int,int> mp;

	// mp.insert(ft::make_pair(0,1));
	// mp.insert(ft::make_pair(1,2));
	// mp.insert(ft::make_pair(2,3));
	// mp.insert(ft::make_pair(3,4));
	// mp.insert(ft::make_pair(4,5));
	// mp.insert(ft::make_pair(5,6));
	// mp.insert(ft::make_pair(6,7));
	// mp.insert(ft::make_pair(7,8));
	// mp.insert(ft::make_pair(8,9));
	// mp.insert(ft::make_pair(9,10));
	// std::cout << mp.size() << std::endl;
	mp[10] = 10;
	mp[18] = 18;
	mp[7] = 7;
	mp[15]= 15;
	mp[16] = 16;
	mp[30] = 30;
	mp[25] = 25;
	mp[40] = 40;
	mp[60] = 60;
	mp[2] = 2;
	mp[1] = 1;
	mp[70] = 70;
	ft::map<int,int>::iterator it = mp.begin();
// std::cout << "here" << std::endl;
	for (int i = 0; i < 12; it++, i++){
		std::cout << it->second << std::endl;
	}


	return 0;
}
