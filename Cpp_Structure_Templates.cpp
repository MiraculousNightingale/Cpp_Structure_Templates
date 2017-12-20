// Cpp_Structure_Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;

void main()
{
	// Queue Test
	cout << "\nQueue\n\n";
	Queue<int> myque;
	myque.Add(1);
	myque.Add(2);
	myque.Add(3);
	myque.Add(4);
	myque.Output();
	myque.Delete(0);
	myque.Output();
	myque.Delete(1);
	myque.Output();
	cout << "\nOutput and changes by id:\n";
	for (int i = 0; i < myque.Count(); i++) {
		myque[i].content = i + 10;
		cout << myque[i].content << " ";
	}
	cout << endl;
	cout << "After insertion...\n";
	myque.Insert(0, 15);
	myque.Output();
	for (int i = 0; i < myque.Count(); i++) {
		myque[i].content = i + 10;
	}
	for (int i = 0; i < 3; i++) {
		cout << myque.Pop() << " ";
	}
	cout << endl;
	system("pause");
	// Stack Test
	cout << "\nStack\n\n";
	Stack<int> mystack;
	mystack.Add(1);
	mystack.Add(2);
	mystack.Add(3);
	mystack.Add(4);
	mystack.Output();
	mystack.Delete(0);
	mystack.Output();
	mystack.Delete(1);
	mystack.Output();
	cout << "\nOutput and changes by id:\n";
	for (int i = 0; i < mystack.Count(); i++) {
		mystack[i].content = i + 10;
		cout << mystack[i].content << " ";
	}
	cout << endl;
	cout << "After insertion...\n";
	mystack.Insert(0, 15);
	mystack.Output();
	for (int i = 0; i < mystack.Count(); i++) {
		mystack[i].content = i + 10;
	}
	for (int i = 0; i < 3; i++) {
		cout << mystack.Pop() << " ";
	}
	cout << endl;
	system("pause");
	// List Test
	cout << "\n List\n\n";
	List<int> test;
	test.Add(1);
	test.Add(2);
	test.Add(3);
	test.Output();
	cout << "After insertion...\n";
	test.Insert(1, 10);
	test.Output();
	cout << "\nOutput by id:\n";
	for (int i = 0; i < test.Count(); i++) {
		cout << test[i].content << " ";
	}
	cout << "\nMake Changes by id:\n";
	for (int i = 0; i < test.Count(); i++) {
		test[i].content = i + 10;
	}
	for (int i = 0; i < test.Count(); i++) {
		cout << test[i].content << " ";
	}
	cout << endl;
	cout << "After Deletion...";
	test.Delete(1);
	cout << "\nOutput by id:\n";
	for (int i = 0; i < test.Count(); i++) {
		cout << test[i].content << " ";
	}
	cout << endl;
	system("pause");
}

