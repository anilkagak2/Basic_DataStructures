// use the singly linked list

#include <iostream>
#include "../include/sll.h"
using namespace std;

int main()
{
	SLL s;
	s.insert(0,2);
	s.insert(1,8);
	s.insert(2,7);
	s.insert(1,3);
	s.insert(3,5);

	s.print();
	cout << endl;

	s.delete_node(5);
	s.delete_node(3);
	s.print();
	cout << s.isEmpty() << endl;
	cout << "search " << s.search(7) << endl;
	return 0;
}
