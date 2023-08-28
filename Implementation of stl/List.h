/*this is part of stl list implimention.
some information about std list:
Lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence,
List containers are implemented as doubly-linked lists; 
Doubly linked lists can store each of the elements they contain in different and unrelated storage locations
. The ordering is kept internally by the association to each element of a link to the element preceding it and a link to the element following it.
*/
#pragma once
#include <iostream>
template <class T>
class List
{
protected://for inherititance such round list, etc.
	template <class T>//you can also impliment it with stuck, but I prefer using inner class
	class Node {
	public:
		T data;
		Node<T>* prev;
		Node<T>* next;
		Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
	};
	Node <T>* head;
	Node<T>* tail;//You can also use only head, but when I use tail the time complexy of part of the function decrease
	int size;
public:
	class Iterator {//nested class itrator, using to iterate through the list
	private:
		Node<T>* current;
	public:
		Iterator(Node<T>* node) : current(node) {}
		Iterator& operator++() {
			current = current->next;
			return *this;
		}

		Iterator& operator--() {
			current = current->prev;
			return *this;
		}

		T& operator*() const {
			return current->data;
		}

		bool operator==(const Iterator& other) const {
			return current == other.current;
		}

		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}
	};
	List() : head(nullptr), tail(nullptr), size(0) {}
	List(const List<T>& l)//copy constructor
	{
		size = l.getSize();
			Node<T>* src, * trg;
			if (l.head == nullptr)//if l is empty
				head =tail= nullptr;
			else
			{
				head = new Node<T>((l.head)->data);
				src = l.head;
				trg = head;
				while (src->next != nullptr)
				{
					trg->next = new Node<T>((src->next)->data);
					src = src->next;
					trg = trg->next;
				}
				tail = src;
			}
	}
	virtual ~List() {
		clear();
	}

	List<T>& operator=(const List<T>& x){//assigment operator:copies all the elements from another list object into the list
		if (this != x) {
			clear();

			size = x.size;
			Node<T>* src, * trg;
			if (x.head == nullptr) {
				head = tail = nullptr;
			}
			else {
				head = new Node<T>((x.head)->data);
				src = x.head;
				trg = head;
				while (src->next != nullptr) {
					trg->next = new Node<T>((src->next)->data);
					src = src->next;
					trg = trg->next;
				}
				tail = src;
			}
		}
		return *this;
	}

	List<T>& operator=(List<T>&& x) {//moves the elements from another list object into the container
		if (this != x) {
			clear();

			head = x.head;
			tail = x.tail;
			size = x.size;

			x.head = nullptr;
			x.tail = nullptr;
			x.size = 0;
		}
		return *this;
	}
	//copies the elements from an initializer list into the container
	List<T>& operator=(const std::initializer_list<T>& il) {
		clear();
		for (const auto& val : il) {
			push_back(val);
		}
		return *this;
	}
	//Adds a new element at the end of the list container, after its current last element. The content of val is copied (or moved) to the new element.
	void push_back(const T& val) {
		if (head == __nullptr)
		{
			head = new Node<T>(val);
			tail = head;
		}
		else
		{
			tail->next = new Node<T>(val);
			tail = tail->next;
		}
		size++;
	}
	void pop_back() {//Removes the last element in the list container, effectively reducing the container size by one.
		if (!empty()) {
			if (head == tail) { // Only one element in the list
				delete tail;
				head = nullptr;
				tail = nullptr;
			}
			else {
				Node<T>* temp = tail;
				tail = tail->prev;
				tail->next = nullptr;
				delete temp;
			}
			size--;
		}
	}
	size_t getSize() const {
		return size;
	}

	bool empty() const {
		return size == 0;
	}
	void clear() {
		while (head != nullptr) {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}

		tail = nullptr;
		size = 0;
	}
	void pop_front() {//Removes the first element in the list container, effectively reducing its size by one.
		if (!empty())
		{
			if (head == tail) { // Only one element in the list
				delete tail;
				head = nullptr;
				tail = nullptr;
			}
			else {
				Node<T>* temp = head;
				head = head->next;
				head->prev = nullptr;
				delete temp;
			}
			size--;

		}
	}
	void push_front(const T& val)
	{
		if (head == nullptr)
		{
			head = new Node<T>(val);
			tail = head;
		}
		else
		{
			head->prev = new Node<T>(val);
			head = head->prev;
		}
		size++;
	}
	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		return Iterator(nullptr);
	}
	//the function assign:Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly.
	void assign(int n, const T& val)//in this versionthe new contents are n elements, each initialized to a copy of val.
	{
		clear();
		size = n;
		for (size_t i = 0; i < n; ++i) {
			push_back(val);
		}
	}
	void assign(std::initializer_list<T> il) {//the new contents are copies of the values passed as initializer list, in the same order.
		clear();
		for (const auto& value : il) {
			push_back(value);
		}
	}
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last) {
		clear();
		while (first != last) {
			push_back(*first);
			++first;
		}
	}
	/*Exchanges the content of the container by the content of x, which is another list of the same type. Sizes may differ.

After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.*/
	void swap(List& x)
	{
		List<T> help(x);
		x = *this;
		*this = help;
	}
};


