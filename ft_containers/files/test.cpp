
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

	std::cout << "::::::::::::::: VECTOR :::::::::::::::" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::cout << "•••• Coplien ••••" << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "Test 1: Default Constructor" << std::endl;
			std::cout << std::endl;

			ft::vector<int>vec;

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;

			for (size_t i = 0; i < 1000; i++){
				vec.push_back(i);
			}
			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;

		}
		std::cout << std::endl;
		{
				std::cout << "Test 2: Fill Constructor" << std::endl;
				std::cout << std::endl;
			{
				std::cout << "no setted value" << std::endl;
				std::cout << std::endl;
				ft::vector<int>vec(10);

				std::cout << "pre capacity: " << vec.capacity() << std::endl;
				std::cout << "pre size: " << vec.size() << std::endl;
				std::cout << "----------------" << std::endl;

				for (size_t i = 0; i < 1000; i++)
				{
					vec.push_back(i);
				}
				std::cout << "post capacity: " << vec.capacity() << std::endl;
				std::cout << "post size: " << vec.size() << std::endl;
				std::cout << "----------------" << std::endl;
				std::cout << "value at zeroth: " << vec[0] << std::endl;
			}
			std::cout << std::endl;
			{
				int rand;

				std::cout << "with value" << std::endl;
				std::cout << std::endl;
				ft::vector<int>vec(10ul,42);

				std::cout << "pre capacity: " << vec.capacity() << std::endl;
				std::cout << "pre size: " << vec.size() << std::endl;
				std::cout << "----------------" << std::endl;

				for (size_t i = 0; i < 1000; i++)
				{
					vec.push_back(i);
				}
				std::cout << "post capacity: " << vec.capacity() << std::endl;
				std::cout << "post size: " << vec.size() << std::endl;
				std::cout << "----------------" << std::endl;
				std::cout << "value at zeroth: " <<  vec[0] << std::endl;
				std::cout << std::endl;

				std::cout << "Test 3: Range Constructor" << std::endl;
				std::cout << std::endl;

				ft::vector<int>::iterator itb = vec.begin();
				ft::vector<int>::iterator ite = vec.end();

				ft::vector<int>range(itb, ite);

				std::cout << "new vector capacity: " << range.capacity() << std::endl;
				std::cout << "new vector: " << range.size() << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from new: " << range[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				

				std::cout << "Test 4: Copy Constructor" << std::endl;
				std::cout << std::endl;

				ft::vector<int>cp(vec);

				std::cout << "original capacity: " << vec.capacity() << std::endl;
				std::cout << "copy capacity: " << cp.capacity() << std::endl;
				std::cout << "original size: " << vec.size() << std::endl;
				std::cout << "copy size: " << cp.size() << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from copy: " << cp[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				

				std::cout << "Test 5: Assign Overload" << std::endl;
				std::cout << std::endl;

				ft::vector<int>eq(3000);
				
				std::cout << "pre capacity: " << eq.capacity() << std::endl;
				std::cout << "pre size: " << eq.size() << std::endl;

				eq = vec;

				std::cout << "original capacity: " << vec.capacity() << std::endl;
				std::cout << "equalized capacity: " << eq.capacity() << std::endl;
				std::cout << "original size: " << vec.size() << std::endl;
				std::cout << "equalized size: " << eq.size() << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;
				rand = std::rand() % vec.size();
				std::cout << "Random element from original: " << vec[rand] << std::endl;
				std::cout << "Same position from equalized: " << eq[rand] << std::endl;
				std::cout << "----------------" << std::endl;

				std::cout << "Inserting 1000 more elements into Equalized vector" << std::endl;
				for (size_t i = 0; i < 1000; i++){
					eq.push_back(i);
				}
				std::cout << "post capacity: " << eq.capacity() << std::endl;
				std::cout << "post size: " << eq.size() << std::endl;
				std::cout << "----------------" << std::endl;
				std::cout << "Original vector should be as before" << std::endl;
				std::cout << "post capacity: " << eq.capacity() << std::endl;
				std::cout << "post size: " << eq.size() << std::endl;
			}
		}
	}
	std::cout << std::endl;
	std::cout << "•••• Iterators ••••" << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "Test 1: Assign elements with iterator" << std::endl;
			std::cout << std::endl;
			ft::vector<int> vec(1000);
			ft::vector<int>::iterator it;
			for (it = vec.begin(); it != vec.end(); it++){
				*it = std::rand() % vec.size();
			}
		
			int i;
			it = vec.begin();
			std::cout << "From begin:" << std::endl;
			std::cout << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << std::endl;

			it = vec.end();
			std::cout << "From end:" << std::endl;
			std::cout << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
		
			std::cout << "capacity: " << vec.capacity() << std::endl;
			std::cout << "size: " << vec.size() << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << "Test 2: Assign and read elements with reverse iterator" << std::endl;
			std::cout << std::endl;
			ft::vector<int> vec(1000);
			ft::vector<int>::reverse_iterator it;
			for (it = vec.rbegin(); it != vec.rend(); it++){
				*it = std::rand() % vec.size();
			}
			
			int i;
			it = vec.rbegin();
			std::cout << "From rbegin:" << std::endl;
			std::cout << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it + i) << std::endl;
			std::cout << "----------------" << std::endl;
			
			std::cout << std::endl;

			it = vec.rend();
			std::cout << "From rend:" << std::endl;
			std::cout << std::endl;

			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << *(it - i) << std::endl;
			std::cout << "----------------" << std::endl;
			
			std::cout << "capacity: " << vec.capacity() << std::endl;
			std::cout << "size: " << vec.size() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "•••• Capacity ••••" << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "Test 1: Max Size" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(1000);
			std::cout << vec.max_size() << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << "Test 2: Empty" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec;

			std::cout <<"Should return 1 as True: ";
			std::cout << vec.empty() << std::endl;
			
			vec.push_back(42);

			std::cout <<"Should return 0 as False: ";
			std::cout << vec.empty() << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << "Test 3: Resize to more" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(100ul, 42);

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;

			vec.resize(1000);

			std::cout << "last of veterans: " << vec[99] << std::endl;
			std::cout << "first of freshmen: " << vec[100] << std::endl;
			std::cout << "last of freshmen: " << vec[999] << std::endl;

			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << "Test 4: Resize to less" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(1000ul, 42);

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;

			vec.resize(100);

			std::cout << "last of veterans: " << vec[99] << std::endl;

			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << "Test 5: Reserve" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(100ul, 42);

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;

			vec.reserve(1000);

			std::cout << "last of element: " << vec[99] << std::endl;

			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "•••• Element Access ••••" << std::endl;
	std::cout << std::endl;
	{
		{
			std::cout << "Test 1: At" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(1000);
			for (size_t i = 0; i < vec.size(); i++){
				vec.at(i) = i;
			}
		
			int i;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << vec.at(i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << vec.at(i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << vec.at(i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << vec.at(i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << vec.at(i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << vec.at(i) << std::endl;
			std::cout << "----------------" << std::endl;
			i = std::rand() % vec.size();
			std::cout << "Random element: " << vec.at(i) << std::endl;
			std::cout << "----------------" << std::endl;

		}
		std::cout << std::endl;
		{
			std::cout << "Test 2: Out of Range" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(1000);
			for (size_t i = 0; i < vec.size(); i++){
				vec.at(i) = i;
			}

			try
			{
				vec.at(3000);
			}
			catch(std::exception & e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		{
			std::cout << "Test 3: Front" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(1000);
			ft::vector<int>::iterator it;
			for (size_t i = 0; i < vec.size(); i++){
				vec.at(i) = i;
			}

			std::cout << "Front of array is: " << vec.front() << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << "Test 3: Back" << std::endl;
			std::cout << std::endl;

			ft::vector<int> vec(1000);
			ft::vector<int>::iterator it;
			for (size_t i = 0; i < vec.size(); i++){
				vec.at(i) = i;
			}

			std::cout << "Back of array is: " << vec.back() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "•••• Modifiers ••••" << std::endl;
	std::cout << std::endl;
	{
		{

			std::cout << "Test 1 Push Back" << std::endl;
			std::cout << std::endl;

			ft::vector<int>vec;

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			for (size_t i = 0; i < 1000; i++){
				vec.push_back(i);
			}
			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << "Front of array is: " << vec.front() << std::endl;
			std::cout << "Back of array is: " << vec.back() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << std::endl;

			std::cout << "Test 2 Pop Back" << std::endl;
			std::cout << std::endl;

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << "Front of array is: " << vec.front() << std::endl;
			std::cout << "Back of array is: " << vec.back() << std::endl;
			std::cout << "----------------" << std::endl;
			for (size_t i = vec.size() - 1; i ; i--){
				vec.pop_back();
			}
			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << "Front of array is: " << vec.front() << std::endl;
			std::cout << "Back of array is: " << vec.back() << std::endl;
			std::cout << "----------------" << std::endl;
		}
		std::cout << std::endl;
		{
			std::cout << "Test 3 Insert: Single" << std::endl;
			std::cout << std::endl;

			ft::vector<int>vec;

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			ft::vector<int>::iterator it = vec.begin();
			it = vec.insert(it, 42);

			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << "Front of array is: " << vec.front() << std::endl;
			std::cout << "Back of array is: " << vec.back() << std::endl;
			std::cout << "----------------" << std::endl;

			for (size_t i = 0; i < 50; i++){
				it = vec.insert(it, i);
			}

			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << "Front of array is: " << vec.front() << std::endl;
			std::cout << "Back of array is: " << vec.back() << std::endl;
			std::cout << "----------------" << std::endl;
			
		}
		std::cout << std::endl;
		{
			std::cout << "Test 4 Insert: Fill" << std::endl;
			std::cout << std::endl;

			ft::vector<int>vec;

			std::cout << "pre capacity: " << vec.capacity() << std::endl;
			std::cout << "pre size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			ft::vector<int>::iterator it = vec.begin();
			vec.insert(it, 5, 42);

			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			std::cout << "Front of array is: " << vec.front() << std::endl;
			std::cout << "Back of array is: " << vec.back() << std::endl;
			std::cout << "----------------" << std::endl;

			it = vec.begin() + 2;
			
			vec.insert(it, 5, 21);

			std::cout << "post capacity: " << vec.capacity() << std::endl;
			std::cout << "post size: " << vec.size() << std::endl;
			std::cout << "----------------" << std::endl;

			for (size_t i = 0; i < vec.size(); i++){
				std::cout << vec[i] << ", ";
			}

			ft::vector<int>range;

			range.insert(range.begin(), vec.begin(), vec.end());

			for (size_t i = 0; i < vec.size(); i++){
				std::cout << range[i] << ", ";
			}
			
		}
	}

	return 0 ;
}
