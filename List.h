#include <iostream>
#pragma once

template<class T>
class List {

private:
	List *Next = NULL;
	List *Previous = NULL;
	List *Head = NULL;
	int index;
public:
	T content;
	List() {}
	List(T entry) {
		Head = this;
		index = 0;
		content = entry;
	}
	List(List* After, T entry) {
		Previous = After;
		Head = After->Head;
		index = After->index + 1;
		content = entry;
	}
	void Add(T entry) {
		if (Head == NULL) {
			Head = new List(entry);
		}
		else {
			List* Current = Head;
			while (Current->Next != NULL) {
				Current = Current->Next;
			}
			Current->Next = new List(Current, entry);
		}
	}
	void Output() {
		List* Current = Head;
		cout << "List Output:\n";
		while (Current != NULL) {
			cout << Current->content << " ";
			Current = Current->Next;
		}
		cout << endl;
	}
};