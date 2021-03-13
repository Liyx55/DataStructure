
#ifndef Chain_
#define Chain_

#include<iostream>
#include<sstream>
#include<string>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;



template<class T>
class Chain : public linearList<T>
{
public:

    Chain(int initialCapacity = 10);
    //      chain(const chain<T>&);
    ~Chain();


    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

protected:
    void checkIndex(int theIndex) const;

    chainNode<T>* firstNode;
    chainNode<T>* lastNode;
    int listSize;
};

template<class T>
Chain<T>::Chain(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template<class T>
Chain<T>::~Chain()
{
    while (firstNode != NULL)
    {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
void Chain<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

}

template<class T>
T& Chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);


    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->element;
}

template<class T>
int Chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL &&
        currentNode->element != theElement)
    {

        currentNode = currentNode->next;
        index++;
    }


    if (currentNode == NULL)
        return -1;
    else
        return index;
}

template<class T>
void Chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);


    chainNode<T>* deleteNode;
    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        p->next = p->next->next;
        if (deleteNode = lastNode)
            lastNode = p;
    }
    listSize--;
    delete deleteNode;
}

template<class T>
void Chain<T>::insert(int theIndex, const T& theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (theIndex == 0)

        firstNode = new chainNode<T>(theElement, firstNode);
    if (listSize == 0)
        lastNode = firstNode;
    else
    {
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;


        p->next = new chainNode<T>(theElement, p->next);
        if (listSize == theIndex)
            lastNode = p->next;
    }
    listSize++;
}

template<class T>
void Chain<T>::output(ostream& out) const
{
    for (chainNode<T>* currentNode = firstNode;
        currentNode != NULL;
        currentNode = currentNode->next)
        out << currentNode->element << "  ";
}


template <class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
    x.output(out); return out;
}

/*
template<class T>
Chain<T>::Chain(const Chain<T>& theList)
{
   listSize = theList.listSize;

   if (listSize == 0)
   {
      firstNode = NULL;
      return;
   }


   ChainNode<T>* sourceNode = theList.firstNode;

   firstNode = new ChainNode<T>(sourceNode->element);

   sourceNode = sourceNode->next;
   ChainNode<T>* targetNode = firstNode;

   while (sourceNode != NULL)
   {
      targetNode->next = new ChainNode<T>(sourceNode->element);
      targetNode = targetNode->next;
      sourceNode = sourceNode->next;
   }
   targetNode->next = NULL;
}
*/

#endif
#pragma once
