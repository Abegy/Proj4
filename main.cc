#include <iostream>
#include <fstream>
#include "swatches.h"
#include "dlist.h"

using namespace std; 

int main() 
{	
	dlist<Swatch> swatches;
	dlist<Swatch>::iterator it; 
	ifstream fin; 
	fin.open("swatches.txt"); 
	if (fin.fail())
	{
		cout << "Could not open input file." << endl; 
		return 1; 
	}
	Swatch tmp; 
	while (fin >> tmp)
	{
		int red = tmp.get_red(); 
		int green = tmp.get_green(); 
		int blue = tmp.get_blue(); 
		
		if ( (green >= red) && (green >= blue) ) // green is dominant
		{
			swatches.rear_insert(tmp); 
		}
		else if ( (red >= green) && (red>=blue) ) 
				// red is dominant
		{
			swatches.front_insert(tmp); 
		}
		else // blue is dominant
		{
		   it = swatches.begin();
		   for(int i = 0;i < swatches.size()/2;i++)
			++it; // loop moves iterator to the middle
		   if(swatches.size()%2 == 1){
			swatches.insert_before(it,tmp);
		   }
		   else{
			swatches.insert_after(it,tmp);
		   }
		}
	}
	fin.close(); 

	dlist<Swatch> copy(swatches); // make a copy
	
	// remove the front, back, and centermost swatch from the copy
	copy.front_remove(); 
	copy.rear_remove(); 
	it = copy.begin();
	for(int i =0; i < copy.size()/2; ++i)
		++it;
	if(copy.size()%2 ==1) ++it; // if list has a true middle
					// step up into it
	copy.remove(it);
	
	
	// output the original list frontwards
	for (dlist<Swatch>::iterator i=swatches.begin(); i != swatches.end(); ++i)
	{
		cout << *i << endl; 
	}
	
	cout << endl << endl; // some space
	
	// output the copy frontwards
	for (dlist<Swatch>::iterator i=copy.begin(); i != copy.end(); ++i)
	{
		cout << *i << endl; 
	}

	cout << endl << endl; // some space

	// output the original backwards
	for (dlist<Swatch>::iterator i=swatches.r_begin(); i != swatches.r_end(); --i)
	{
		cout << *i << endl; 
	}
	
	cout << endl << endl; // some space

	// destroy the original list by alternating between removal of first and 
	// last items.  Print each item as it is removed
	int counter=0; 
	while (swatches.size() > 0)
	{
		cout<<*swatches.begin()<<endl;
		swatches.front_remove();
		if(swatches.size() > 0){
		    cout<<*swatches.r_begin()<<endl;
		    swatches.rear_remove();
		}
	}

	cout << endl << endl; // some space

	// output the copy backwards
	for (dlist<Swatch>::iterator i=copy.r_begin(); i != copy.r_end(); --i)
	{
		cout << *i << endl; 
	}

	return 0; 
}
