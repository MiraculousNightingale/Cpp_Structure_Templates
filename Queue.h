#include <iostream>
#pragma once

#include <iostream>
#pragma once

template<class T>
class Queue {

private:
	Queue *Next;
	Queue *Previous;
	Queue *Head;
	int index;
public:
	T content;
	Queue() {
		Next = NULL;
		Previous = NULL;
		Head = NULL;
	}
	Queue(T entry) {
		Head = this;
		index = 0;
		content = entry;
	}
	Queue(Queue* After, T entry) {
		Previous = After;
		Head = After->Head;
		index = After->index + 1;
		content = entry;
	}
	Queue(Queue* After, Queue* Before, T entry) {
		Next = Before;
		Previous = After;
		Head = After->Head;
		index = After->index + 1;
		content = entry;
	}
	void Add(T entry) {
		if (Head == NULL) {
			Head = new Queue(entry);
		}
		else {
			Queue* Current = Head;
			while (Current->Next != NULL) {
				Current = Current->Next;
			}
			Current->Next = new Queue(Current, entry);
		}
	}
	void Insert(int id, T entry) {
		Queue* Current = Search_ID(id);
		Current->Next = new Queue(Current, Search_ID(id + 1), entry);
	}
	void Delete(int id) {
		if (id == 0) {
			Queue* Current = Head;
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
			Queue* To_Delete = Search_ID(id);
			To_Delete->Previous->Next = To_Delete->Next;
			To_Delete->Next->Previous = To_Delete->Previous;
			Queue* Current = To_Delete->Previous;
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
		Queue* Current = Head;
		cout << "Queue Output:\n";
		while (Current != NULL) {
			cout << Current->content << " ";
			Current = Current->Next;
		}
		cout << endl;
	}
	Queue& operator[](int id) {
		Queue* Current = Head;
		while (Current != NULL) {
			if (Current->index == id) return *Current;
			Current = Current->Next;
		}
	}
	int Count() {
		Queue* Current = Head;
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
	Queue* Search_ID(int id) {
		Queue* Current = Head;
		while (Current != NULL) {
			if (Current->index == id) return Current;
			Current = Current->Next;
		}
	}
};