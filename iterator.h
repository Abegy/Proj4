#ifndef ITERATOR_H
#define ITERATOR_H

#include "dnode.h"


template <class T>
class node_iterator{
   public:
  
		// defualt constructor
		node_iterator(Dnode<T> *init = NULL){current = init;}
		// now node_iterator can have access to t he head tail and the count.
		
		//overloaded operators for the node iterator
		T operator * (){return current -> data();}
		bool operator != (const node_iterator& other){return current != other.current;}
		bool operator == (const node_iterator& other){return current == other.current;}
		node_iterator operator ++(){current = current -> next(); return *this;}
		node_iterator operator ++(int){node_iterator original(*this);current = current -> next(); return original;}
		node_iterator operator --(){current = current -> previous(); return *this;}
		node_iterator operator --(int){node_iterator original(*this);current = current -> previous(); return original;}
	private:
		Dnode<T> *current;
		
};
#endif
