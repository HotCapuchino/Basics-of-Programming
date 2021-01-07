//#include <iostream>
#include "LinkedList.h"


using namespace std;
int main(void) {
	LinkedList<int> list(true, 2);
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	list.addElement(a);
	list.addElement(b);
	list.addElement(c);
	list.insertBeforeElement(d, c);
	list.printElems();
	list.removeElement(c);
	cout << "----\n";
	list.printElems();
	/*list.printAdresses();*/
	cout << "Hello!\n";
	system("pause");
	return 0;
}