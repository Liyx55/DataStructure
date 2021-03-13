
#ifndef circularlistWithHeader_
#define circularlistWithHeader_

#include<iostream>
#include<sstream>
#include<string>
#include "chainNode.h"
#include "myExceptions.h"
#include "linearList.h"

using namespace std;

template<class T>
class circularListWithHeader : public linearList<T>
{
public:

	circularListWithHeader();
	bool empty() const { return listSize == 0; };
	T& get(int theIndex) const;

	int size() const { return listSize; }
	int indexOf(const T& theElement) const;
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
	void erase(int theIndex);
	void split();
	chainNode<T>* find(int theIndex) const;

protected:
	void checkIndex(int theIndex) const;

	chainNode<T>* headerNode;
	int listSize;
};

template<class T>
void circularListWithHeader<T>::split() {
	chainNode<T>* q = headerNode->next;
	while (q->next != headerNode) {
		q = q->next;
	}
	chainNode<T>* p = headerNode;
	while (q != p->next) {
		while (p->next->element % 2 != 0) {
			p = p->next;
		}
		while (q->element % 2 == 0) {
			q = q->prev;
		}
		if (q == p->next || p == q)
			break;
		int temp;
		temp = q->element;
		q->element = p->next->element;
		p->next->element = temp;
	}
	circularListWithHeader<T> a, b;
	chainNode<T>* t = headerNode;
	int i = 0, j = 0;
	while (t->next->element % 2 != 0) {
		a.insert(i++, t->next->element);
		t = t->next;
	}
	while (t->next != headerNode) {
		b.insert(j++, t->next->element);
		t = t->next;
	}
	cout << a << endl;
	cout << b << endl;
}



template<class T>
chainNode<T>* circularListWithHeader<T>::find(int theIndex) const
{
	chainNode<T>* p = headerNode;
	if (theIndex < listSize / 2)
	{
		for (int i = 0; i < theIndex; i++)
			p = p->next;
	}
	else
		for (int i = 0; i < listSize - theIndex + 1; i++)
			p = p->prev;
	return p;
}
template<class T>
T& circularListWithHeader<T> ::get(int theIndex) const
{
	chainNode<T>* p = headerNode;
	p = find(theIndex);
	p = p->next;

	return p->element;
}


template<class T>
circularListWithHeader<T> ::circularListWithHeader()
{
	headerNode = new chainNode<T>();
	headerNode->next = headerNode;
	headerNode->prev = headerNode;
	listSize = 0;
}

template<class T>
void circularListWithHeader<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

}

template<class T>
int circularListWithHeader<T>::indexOf(const T& theElement) const
{



	headerNode->element = theElement;


	chainNode<T>* currentNode = headerNode->next;
	int index = 0;
	while (currentNode->element != theElement)
	{

		currentNode = currentNode->next;
		index++;
	}


	if (currentNode == headerNode)
		return -1;
	else
		return index;
}

template<class T>
void circularListWithHeader<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}


	chainNode<T>* p = headerNode;
	chainNode<T>* s = new chainNode<T>(theElement);
	p = find(theIndex);

	s->next = p->next;
	s->prev = p;
	p->next = s;
	s->next->prev = s;

	listSize++;
}




template<class T>
void circularListWithHeader<T>::erase(int theIndex)
{

	chainNode<T>* p;
	chainNode<T>* q = headerNode;
	p = find(theIndex);
	q = p->next;
	p->next = q->next;
	q->next->prev = p;
	delete q;
	listSize--;
}

template<class T>
void circularListWithHeader<T>::output(ostream& out) const
{
	for (chainNode<T>* currentNode = headerNode->next;
		currentNode != headerNode;
		currentNode = currentNode->next)
		out << currentNode->element << "  ";
}


template <class T>
ostream& operator<<(ostream& out, const circularListWithHeader<T>& x)
{
	x.output(out); return out;
}

#endif