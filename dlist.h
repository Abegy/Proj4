
#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "iterator.h"
#include "dnode.h"
#include "cstdlib"


// foward decleraton for the dlist class
//class Dnode;
template<class T>
class dlist{
	public:
		typedef node_iterator<T> iterator;

		//defualt constructor
		 dlist();
		
		// The big 3;
		dlist(const dlist& other);
		~dlist();
		dlist& operator = (const dlist& other);

		// itterator functions
		iterator begin(){return iterator(head);}
		iterator end(){return iterator(NULL);}
		iterator r_begin(){return iterator(tail);}
		iterator r_end(){return iterator(NULL);}

		// functions for manipulating the list
		void rear_insert(T item);
		void front_insert(T item);
		void front_remove();
		void rear_remove();
		void remove(iterator it);
		void insert_before(iterator it, T item);
		void insert_after(iterator it, T item);
		void show();
		void reverse_show();
		int size();
	private:
		size_t count;
		Dnode<T>* head;
		Dnode<T>* tail;
};

#endif
#include "dlist.template"