#include <iostream>
#pragma once

template<class T>
class List {

private:
	List *Next;
	List *Previous;
	List *Head;
	int index;
public:
	T content;
	List() {
		Next = NULL;
		Previous = NULL;
		Head = NULL;
	}
	List(T entry) {
		Next = NULL;
		Previous = NULL;
		Head = this;
		index = 0;
		content = entry;
	}
	List(List* After, T entry) {
		Next = NULL;
		Previous = After;
		Head = After->Head;
		index = After->index + 1;
		content = entry;
	}
	List(List* After, List* Before, T entry) {
		Next = Before;
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
	void Insert(int id, T entry) {
		List* Current = Search_ID(id);
		Current->Next = new List(Current, Search_ID(id + 1), entry);
	}
	void Delete(int id) {
		if (id == 0) {
			List* Current = Head;
			if (Current->Next != NULL) {
				Current = Current->Next;
				Current->Previous = NULL;
				Current->Head = Current;
				Current->index = 0;
				delete Head;
				Head = Current;
				Current = Current->Next;
				while (Current != NULL) {
					Current->Head = Current->Previous->Head;
					Current->index = Current->Previous->index + 1;
					Current = Current->Next;
				}
			}
			else delete Head;
		}
		else {
			List* To_Delete = Search_ID(id);
			To_Delete->Previous->Next = To_Delete->Next;
			To_Delete->Next->Previous = To_Delete->Previous;
			List* Current = To_Delete->Previous;
			delete To_Delete;
			while (Current != NULL) {
				if (Current->index != 0) {
					Current->index = Current->Previous->index + 1;
				}
				Current = Current->Next;
			}
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
	List& operator[](int id) {
		List* Current = Head;
		while (Current != NULL) {
			if (Current->index == id) return *Current;
			Current = Current->Next;
		}
	}
	int Count() {
		List* Current = Head;
		int count = 0;
		while (Current != NULL) {
			count++;
			Current = Current->Next;
		}
		return count;
	}
private:
	List* Search_ID(int id) {
		List* Current = Head;
		while (Current != NULL) {
			if (Current->index == id) return Current;
			Current = Current->Next;
		}
	}
};