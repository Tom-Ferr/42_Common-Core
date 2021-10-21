/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:12:10 by tde-cama          #+#    #+#             */
/*   Updated: 2021/10/21 17:12:10 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TEST_CPP
# define SET_TEST_CPP

std::cout << "::::::::::::::: SET :::::::::::::::" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
    {
        std::cout << "•••• Coplien ••••" << std::endl;
	    std::cout << std::endl;
        {

            std::cout << "Test 1: Default Constructor" << std::endl;
			std::cout << std::endl;

            ft::set<int> mp;

            std::cout << "before: " << std::endl;

            std::cout << "size: " << mp.size() << std::endl;

            for (int i = 0; i < 10; i++)
            {
                mp.insert(std::rand() % 100) ;
            }

            std::cout << "after: " << std::endl;
            std::cout << "deafault: " << mp.size() << std::endl;
            for (ft::set<int>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                std::cout << *it  << ", " ;
            }

			std::cout << std::endl;
			std::cout << std::endl;
            {

                std::cout << "Test 2: Range Constructor" << std::endl;
                std::cout << std::endl;
                std::cout << "range: " << mp.size() << std::endl;

                ft::set<int> range(mp.begin(), mp.end());

                 for (ft::set<int>::iterator it = range.begin(); it != range.end(); it++)
            {
                std::cout << *it  << ", " ;
            }
            }
            std::cout << std::endl;
            std::cout << std::endl;
            {
                std::cout << "Test 3: Copy Constructor" << std::endl;
                std::cout << std::endl;
                std::cout << "copy: " << mp.size() << std::endl;

                ft::set<int> cp(mp);

            for (ft::set<int>::iterator it = cp.begin(); it != cp.end(); it++)
            {
                std::cout << *it  << ", " ;
            }
            }
            std::cout << std::endl;
            std::cout << std::endl;
            {
                std::cout << "Test 4: Assign Overload" << std::endl;
                std::cout << std::endl;

                ft::set<int> as;

                as = mp;

                for (ft::set<int>::iterator it = as.begin(); it != as.end(); it++)
                {
                    std::cout << *it  << ", " ;
                }
            }
        }

        std::cout << std::endl;
        std::cout << std::endl;

      std::cout << "•••• Iterator ••••" << std::endl;
	    std::cout << std::endl;
        {
            ft::set<int> mp;

            for (int i = 0; i < 10; i++)
            {
                 mp.insert(std::rand() % 100) ;
            }

             std::cout << "Test 1: Normal Iterator" << std::endl;
			std::cout << std::endl;

            for (ft::set<int>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                std::cout << *it  << ", " ;
            }

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Test 2: Reverse Iterator" << std::endl;
			std::cout << std::endl;
          
            for (ft::set<int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++)
            {
                std::cout << *it  << ", " ;
            }

        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "•••• Capacity ••••" << std::endl;
	    std::cout << std::endl;
        {
           std::cout << "Test 1: Empty" << std::endl;
			std::cout << std::endl;

			ft::set<int> mp;

			std::cout <<"Should return 1 as True: ";
			std::cout << mp.empty() << std::endl;
			
			  mp.insert(42) ;

			std::cout <<"Should return 0 as False: ";
			std::cout << mp.empty() << std::endl;

			std::cout << "Test 2: Max Size" << std::endl;
			std::cout << std::endl;
			std::cout << mp.max_size() << std::endl;

        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "•••• Modifiers ••••" << std::endl;
	    std::cout << std::endl;
	    std::cout << std::endl;
        {
            {
                std::cout << "Test 1: Insert Single" << std::endl;
	            std::cout << std::endl;

                ft::set<int> mp;

                for (int i = 0; i < 12; i++){
                   int n = std::rand() % 100;
                   mp.insert(n);
                }
                for (ft::set<int>::iterator it = mp.begin(); it != mp.end(); it++) {
                    std::cout << *it  << ", " ;
                }

                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Test 2: Insert Hint" << std::endl;
	            std::cout << std::endl;
	            std::cout << std::endl;

                ft::set<int>::iterator here;
                here = mp.insert(++mp.begin(),42);

                for (ft::set<int>::iterator it = mp.begin(); it != mp.end(); it++) {
                    std::cout << *it  << ", " ;
                }

                
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Test 3: Insert Range" << std::endl;
	            std::cout << std::endl;
	            std::cout << std::endl;

                ft::set<int> range;

                ft::set<int>::iterator itb = mp.begin();
                ft::set<int>::iterator ite = mp.end();

                range.insert(++itb, --ite);

                for (ft::set<int>::iterator it = ++range.begin(); it != range.end(); it++) {
                    std::cout << *it  << ", " ;
                }

                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Test 4: Erase Iterator" << std::endl;
	            std::cout << std::endl;
	            std::cout << std::endl;
                mp.erase(here);
                for (ft::set<int>::iterator it = mp.begin(); it != mp.end(); it++) {
                std::cout << *it  << ", " ;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Test 5: Erase value" << std::endl;
	            std::cout << std::endl;
	            std::cout << std::endl;
                int key = *mp.begin();
                mp.erase(key);
                for (ft::set<int>::iterator it = mp.begin(); it != mp.end(); it++) {
                std::cout << *it  << ", " ;
                }
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Test 6: Erase Range" << std::endl;
	            std::cout << std::endl;
	            std::cout << std::endl;
                ft::set<int>::iterator err = mp.begin();
                err++;
                mp.erase(err, mp.end());
                for (ft::set<int>::iterator it = mp.begin(); it != mp.end(); it++) {
                std::cout << *it  << ", " ;
                }
            }
            {
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Test 7: Swap" << std::endl;
	            std::cout << std::endl;
	            std::cout << std::endl;

                ft::set<int> mp_a;
                ft::set<int> mp_b;
                
                for (int i = 0; i < 7; i++){
                   int n = std::rand() % 100;
                   mp_a.insert(n);
                }
                for (int i = 0; i < 3; i++){
                   int n = std::rand() % 100;
                   mp_b.insert(n);
                }

                std::cout << "before swap:" << std::endl;
                std::cout << "A:" << std::endl;
                for (ft::set<int>::iterator it = mp_a.begin(); it != mp_a.end(); it++) {
                    std::cout << *it  << ", " ;
                }
                std::cout << std::endl;
                std::cout << "B:" << std::endl;
                for (ft::set<int>::iterator it = mp_b.begin(); it != mp_b.end(); it++) {
                    std::cout << *it  << ", " ;
                }
                std::cout << std::endl;

                mp_a.swap(mp_b);

                std::cout << "after swap:" << std::endl;
                std::cout << "A:" << std::endl;
                for (ft::set<int>::iterator it = mp_a.begin(); it != mp_a.end(); it++) {
                    std::cout << *it  << ", " ;
                }
                std::cout << std::endl;
                std::cout << "B:" << std::endl;
                for (ft::set<int>::iterator it = mp_b.begin(); it != mp_b.end(); it++) {
                    std::cout << *it  << ", " ;
                }
                std::cout << std::endl;

                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Test 8: Clear" << std::endl;
	            std::cout << std::endl;
	            std::cout << std::endl;
                
                std::cout << "before clear: size of A = " << mp_a.size() << std::endl;
                std::cout << "before clear: size of B = " << mp_b.size() << std::endl;

                mp_a.clear();
                mp_b.clear();

                std::cout << "after clear: size of A = " << mp_a.size() << std::endl;
                std::cout << "after clear: size of B = " << mp_b.size() << std::endl;
            }
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "•••• Operations ••••" << std::endl;
	    std::cout << std::endl;
	    std::cout << std::endl;
        {
            std::cout << std::endl;
            std::cout << "Test 1: Find" << std::endl;
	        std::cout << std::endl; 

            ft::set<int> mp_a;
                
            for (int i = 0; i < 100; i++){
               int n = std::rand() % 100;
               mp_a.insert(n);
            }
            mp_a.insert(42);
            
            ft::set<int>::iterator it;
            it = mp_a.find(42);
            
            std::cout << "found: "<< *it << std::endl;

            std::cout << std::endl;
            std::cout << "Test 2: Count" << std::endl;
	        std::cout << std::endl; 

            mp_a.insert(42);
            mp_a.insert(42);
            mp_a.insert(42);
            mp_a.insert(42);
            std::cout << "there is "<< mp_a.count(42) << " element with 42 as key" << std::endl;

            std::cout << std::endl;
            std::cout << "Test 3: Lower Bound" << std::endl;
	        std::cout << std::endl; 

             std::cout << "lower bound of 42 is "<< *mp_a.lower_bound(42) << std::endl;

            std::cout << std::endl;
            std::cout << "Test 4: Upper Bound" << std::endl;
	        std::cout << std::endl; 

             std::cout << "upper bound of 42 is "<< *mp_a.upper_bound(42) << std::endl;

            std::cout << std::endl;
            std::cout << "Test 5: Equal Range" << std::endl;
	        std::cout << std::endl; 

            ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> p = mp_a.equal_range(42);

            std::cout << "equal range of 42 is "<< *p.first << ", " << *p.second << std::endl;
        }

         std::cout << std::endl;
		std::cout << "•••• Non-Member ••••" << std::endl;
		std::cout << std::endl;
		
			std::cout << std::endl;

			ft::set<int> small;
			ft::set<int> big;

			for (size_t i = 0; i < 50; i++)
			{
				big.insert(std::rand());
			}
			for (size_t i = 0; i < 10; i++)
			{
				big.insert(std::rand());
			}
			
			if (big == big)
				std::cout << "equal overload ok" << std::endl;
			if (big != small)
				std::cout << "non equal overload ok" << std::endl;
			if (big > small)
				std::cout << "bigger than overload ok" << std::endl;
			if (small < big)
				std::cout << "smaller than overload ok" << std::endl;
			if (big >= big && big >= small)
				std::cout << "bigger or equal overload ok" << std::endl;
			if (small <= small && small <= big)
				std::cout << "smaller or equal overload ok" << std::endl;

			std::cout << std::endl;
        
    }


#endif