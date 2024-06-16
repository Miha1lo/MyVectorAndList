

#include <iostream>
#include "MyVector.h"
#include "MyList.h"


int main()
{
	std::cout << "\n";
	std::cout << "******************************\n";
	std::cout << "VECTOR\n";
	std::cout << "******************************\n";
	std::cout << "\n";

	MyVector<int> testVector1(40);
	for (int i = 1; i <= 20; ++i) {
		testVector1.push_back(i);
	}

	testVector1.printData();
	std::cout << "Lenght: " << testVector1.getLength() << "\n";
	std::cout << "Capacity: " << testVector1.getCapacity() << "\n";

	std::cout << "******************************\n";

	testVector1.resize(10, std::nothrow);
	std::cout << "Lenght: " << testVector1.getLength() << "\n";
	std::cout << "Capacity: " << testVector1.getCapacity() << "\n";
	testVector1.printData();

	std::cout << "******************************\n";

	testVector1.resize(15, std::nothrow);
	std::cout << "Lenght: " << testVector1.getLength() << "\n";
	std::cout << "Capacity: " << testVector1.getCapacity() << "\n";
	testVector1.printData();

	/*
	MyVector<int> testVector2(10);
	for (int i = 21; i <= 30; ++i) {
		testVector2.push_back(i);
	}

	testVector2.printData();
	std::cout << "Lenght: " << testVector2.getLength() << "\n";
	std::cout << "Capacity: " << testVector2.getCapacity() << "\n";

	std::cout << "******************************\n";

	MyVector<int> resultVector = testVector1 + testVector2;

	resultVector.printData();
	std::cout << "Lenght: " << resultVector.getLength() << "\n";
	std::cout << "Capacity: " << resultVector.getCapacity() << "\n";

	std::cout << "******************************\n";

	resultVector.push_back(99);	//should get here message that vector full
	*/
	std::cout << "\n";
	std::cout << "******************************\n";
	std::cout << "LIST\n";
	std::cout << "******************************\n";
	std::cout << "\n";

	MyList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_front(0);
	list.push_front(-1);
	list.printList();				// Expacted result: -1 0 1 2 3

	list.pop_back();
	list.printList();				// Expacted result: -1 0 1 2

	list.pop_front();
	list.printList();				// Expacted result: 0 1 2

	MyList<int> list2(list);
	list2.printList();			// Expacted result: 0 1 2

	MyList<int> list3;
	list3.push_back(4);
	list3.push_back(5);
	list3 = list2;
	list3.printList();			// Expacted result: 0 1 2

}

