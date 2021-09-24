#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

namespace ft {
	template<typename T>
	class vector<T>
	{
	public:
		typedef _Alloc allocator_type;
 		typedef
		__gnu_cxx::__normal_iterator
		< const_pointer, vector > const_iterator;
 		typedef
		_Tp_alloc_type::const_pointer const_pointer;
 		typedef
		_Tp_alloc_type::const_reference const_reference;
 		typedef std::reverse_iterator
		< const_iterator > const_reverse_iterator;
 		typedef ptrdiff_t difference_type;
 		typedef
		__gnu_cxx::__normal_iterator
		< pointer, vector > iterator;
 		typedef _Tp_alloc_type::pointer pointer;
 		typedef _Tp_alloc_type::reference reference;
 		typedef std::reverse_iterator
		< iterator > reverse_iterator;
 		typedef size_t size_type;
 		typedef _Tp value_type;

		vector ();
		vector (const allocator_type &__a);
		vector (size_type __n);
		vector (size_type __n, const value_type &__value, const allocator_type &__a=allocator_type());
		vector (const vector &__x);
		vector (vector &&__x);
		vector (initializer_list< value_type > __l, const allocator_type &__a=allocator_type())
		template<typename _InputIterator > vector (_InputIterator __first, _InputIterator __last, const allocator_type &__a=allocator_type());
		~vector ();
		void assign (size_type __n, const value_type &__val);
		template<typename _InputIterator > void assign (_InputIterator __first, _InputIterator __last);
		void assign (initializer_list< value_type > __l);
		reference at (size_type __n);
		const_reference at (size_type __n) const;
		reference back ();
		const_reference back () const;
		iterator begin ();
		const_iterator begin () const;
		size_type capacity () const;
		const_iterator cbegin () const;
		const_iterator cend () const;
		void clear ();
		const_reverse_iterator crbegin () const;
		const_reverse_iterator crend () const;
		_Tp * data ();
 		const _Tp * data () const;
		template<typename... _Args> iterator emplace (iterator __position, _Args &&...__args);
 		template<typename... _Args> void emplace_back (_Args &&...__args);
		bool empty () const;
		iterator end ();
		const_iterator end () const;
		iterator erase (iterator __position);
		iterator erase (iterator __first, iterator __last);
		reference front ();
		const_reference front () const;
		iterator insert (iterator __position, const value_type &__x);
		iterator insert (iterator __position, value_type &&__x);
		void insert (iterator __position, initializer_list< value_type > __l);
		void insert (iterator __position, size_type __n, const value_type &__x);
		template<typename _InputIterator > void insert (iterator __position, _InputIterator __first, _InputIterator __last);
		size_type max_size () const
		vector & operator= (const vector &__x);
		vector & operator= (vector &&__x);
		vector & operator= (initializer_list< value_type > __l);
		reference operator[] (size_type __n);
		const_reference operator[] (size_type __n) const;
		void pop_back ();
		void push_back (const value_type &__x);
 		void push_back (value_type &&__x);
		reverse_iterator rbegin ();
		const_reverse_iterator rbegin () const;
		reverse_iterator rend ();
		const_reverse_iterator rend () const;
		void reserve (size_type __n);
		void resize (size_type __new_size);
		void resize (size_type __new_size, const value_type &__x);
		void shrink_to_fit ();
		size_type size () const;
		void swap (vector &__x);
	protected:
		_Tp_alloc_type::pointer _M_allocate (size_t __n);
		template<typename _ForwardIterator > pointer _M_allocate_and_copy (size_type __n, _ForwardIterator __first, _ForwardIterator __last);
		template<typename _InputIterator > void _M_assign_aux (_InputIterator __first, _InputIterator __last, std::input_iterator_tag);
		template<typename _ForwardIterator > void _M_assign_aux (_ForwardIterator __first, _ForwardIterator __last, std::forward_iterator_tag);
		template<typename _Integer > void _M_assign_dispatch (_Integer __n, _Integer __val, __true_type);
		template<typename _InputIterator > void _M_assign_dispatch (_InputIterator __first, _InputIterator __last, __false_type);
		size_type _M_check_len (size_type __n, const char *__s) const;
		void _M_deallocate (typename _Tp_alloc_type::pointer __p, size_t __n);
		void _M_default_append (size_type __n);
		void _M_default_initialize (size_type __n);
		void _M_erase_at_end (pointer __pos);
		void _M_fill_assign (size_type __n, const value_type &__val);
		void _M_fill_initialize (size_type __n, const value_type &__value);
		void _M_fill_insert (iterator __pos, size_type __n, const value_type &__x);
		_Tp_alloc_type & _M_get_Tp_allocator ();
		const _Tp_alloc_type & _M_get_Tp_allocator () const;
		template<typename _Integer > void _M_initialize_dispatch (_Integer __n, _Integer __value, __true_type);
		template<typename _InputIterator > void _M_initialize_dispatch (_InputIterator __first, _InputIterator __last, __false_type);
		template<typename... _Args> void _M_insert_aux (iterator __position, _Args &&...__args);
		template<typename _Integer > void _M_insert_dispatch (iterator __pos, _Integer __n, _Integer __val, __true_type);
		template<typename _InputIterator > void _M_insert_dispatch (iterator __pos, _InputIterator __first, _InputIterator __last, __false_type);
		void _M_range_check (size_type __n) const;
		template<typename _InputIterator > void _M_range_initialize (_InputIterator __first, _InputIterator __last, std::input_iterator_tag);
		template<typename _ForwardIterator > void _M_range_initialize (_ForwardIterator __first, _ForwardIterator __last, std::forward_iterator_tag);
		template<typename _InputIterator > void _M_range_insert (iterator __pos, _InputIterator __first, _InputIterator __last, std::input_iterator_tag);
		template<typename _ForwardIterator > void _M_range_insert (iterator __pos, _ForwardIterator __first, _ForwardIterator __last, std::forward_iterator_tag);
		allocator_type get_allocator () const;

		_Vector_impl _M_impl;
	};
}
#endif
