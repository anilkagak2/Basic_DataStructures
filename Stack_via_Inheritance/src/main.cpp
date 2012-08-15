// use the stack class

#include <iostream>
#include "../include/stack.h"
using namespace std;

int main()
{
	Stack s;
	s.push(4);
	s.push(5);
	s.push(7);

	cout << s.topEle() << endl;

	s.push(3);
	cout << s.topEle() << endl;

	s.push(1);

	s.pop();
	cout << s.topEle() << endl;
	s.pop();
	s.pop();
	cout << s.topEle() << endl;

	cout << s.isEmpty() << endl;
	s.pop();
	s.pop();
	cout << s.isEmpty() << endl;

	return 0;
}
