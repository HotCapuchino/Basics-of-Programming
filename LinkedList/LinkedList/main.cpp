#include "LinkedList.h"


using namespace std;
int main(void) {
	/*LinkedList<int> list(true, 2);
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
	list.printElems();*/
	/*list.printAdresses();*/

	// Задача Иосифа Флавия

	cout << "Enter amount of soldiers in Iosif Squad!: ";
	int warriors_amount;
	while (true) {
		cin >> warriors_amount;
		if (!cin.fail() && warriors_amount > 2) break;
		cout << "Amount of soldiers should be positive and there should be more than 2 soldiers! Try again!\n";
	} 
	cout << "Enter the gap: ";
	int kill_gap;
	while (true) {
		cin >> kill_gap;
		if (!cin.fail() && kill_gap < warriors_amount && kill_gap > 0) break;
		cout << "Gap should be positive and less than warriors amount!Try again!\n";
	}
	LinkedList<int> iosif_squad(true, warriors_amount);
	int* soldiers = new int[warriors_amount];
	for (size_t i = 0; i < warriors_amount; i++) {
		soldiers[i] = i + 1;
		iosif_squad.addElement(soldiers[i]);
	}
	iosif_squad.printElems();
	cout << "------\n";
	LinkedListElem<int>* current_elem = iosif_squad.getStart();
	//
	cout << "initial size: " << iosif_squad.getSize() << endl;
	while (iosif_squad.getSize() > 1) {
		for (size_t i = 0; i < kill_gap; i++) {
			current_elem = current_elem->getNext();
		}
		int currentElem_data = current_elem->getData();
		current_elem = current_elem->getNext();
		iosif_squad.removeElement(currentElem_data);
		cout << "removed: " << currentElem_data << endl;
		cout << "After removing:\n";
		iosif_squad.printElems();
		cout << "------------------\n";
	}
	cout << "Iosif should pick number: (" << iosif_squad.getStart()->getData() << ") in order not to be killed.";
	system("pause");
	return 0;
}
