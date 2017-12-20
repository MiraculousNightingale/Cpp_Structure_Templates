#include <iostream>
#pragma once

template<class T>
class Stack {

private:
	Stack *Next = NULL;
	Stack *Head = NULL;
	int index;
public:
	T content;
	Stack() {}
	Stack(T entry) {
		Head = this;
		index = 0;
		content = entry;
	}
	Stack(Stack* Before, T entry) {
		Head = this;
		Next = Before;
		index = 0;
		content = entry;
		Stack* Current = Next;
		for (int Indexator = 1; Current != NULL; Indexator++) {
			Current->index = Indexator;
			Current = Current->Next;
		}
	}
	Stack(Stack* After, Stack* Before, T entry) {
		Next = Before;
		Head = After->Head;
		index = After->index + 1;
		content = entry;
		Stack* Current = Head;
		for (int Indexator = 0; Current != NULL; Indexator++) {
			Current->index = Indexator;
			Current = Current->Next;
		}
	}
	void Add(T entry) {
		if (Head == NULL) {
			Head = new Stack(entry);
		}
		else {
			Stack* Current = Head;
			Current = new Stack(Current, entry);
			Head = Current;
		}
	}
	void Insert(int id, T entry) {
		Stack* Current = Search_ID(id);
		Current->Next = new Stack(Current, Search_ID(id + 1), entry);
	}
	void Delete(int id) {
		if (id == 0) {
			Stack* Current = Head;
			if (Current->Next != NULL) {
				Current = Current->Next;
				Current->Head = Current;
				delete Head;
				Head = Current;
				for (int Indexator = 0; Current != NULL; Indexator++) {
					Current->index = Indexator;
					Current->Head = Head;
					Current = Current->Next;
				}
			}
			else delete Head;
		}
		else {
			Stack* To_Delete = Search_ID(id);
			Search_ID(id - 1)->Next = To_Delete->Next;
			delete To_Delete;
			Stack* Current = Head;
			for (int Indexator = 0; Current != NULL; Indexator++) {
				Current->index = Indexator;
				Current = Current->Next;
			}
		}
	}
	void Output() {
		Stack* Current = Head;
		cout << "Stack Output:\n";
		while (Current != NULL) {
			cout << Current->content << " ";
			Current = Current->Next;
		}
		cout << endl;
	}
	Stack& operator[](int id) {
		Stack* Current = Head;
		while (Current != NULL) {
			if (Current->index == id) return *Current;
			Current = Current->Next;
		}
	}
	int Count() {
		Stack* Current = Head;
		int count = 0;
		while (Current != NULL) {
			count++;
			Current = Current->Next;
		}
		return count;
	}
	T Pop() {
		T popped_value = Head->content;
		Delete(0);
		return popped_value;
	}
	T Peek() {
		return Head->content;
	}
private:
	Stack* Search_ID(int id) {
		Stack* Current = Head;
		while (Current != NULL) {
			if (Current->index == id) return Current;
			Current = Current->Next;
		}
	}
};