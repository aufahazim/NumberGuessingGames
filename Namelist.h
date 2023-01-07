#ifndef NAMELIST_H
#define NAMELIST_H

#include<iostream> 
#include<string>

using namespace std;

template <class T>
class ListNode
{
	public:
		T PlayerName;
		ListNode<T> *next;
		
		ListNode (T nodeValue)
		{
			PlayerName = nodeValue; next = nullptr;	
			
		} 
};

template <class T>
class Namelist
{
	private:
	    ListNode<T> *head;
	public:
		Namelist()
		{ head = nullptr; }
		~Namelist();
		
		void appendNode(T);
		void displayList() const;
		T searchnode(T);
};

template <class T>
void Namelist<T> :: displayList() const
{
	ListNode<T> *nodePtr;
	
	nodePtr=head;
	cout <<"head -> ";
	while(nodePtr)
	{
		cout << nodePtr -> PlayerName << " -> ";
		nodePtr = nodePtr-> next;
	}
	cout << "NULL" << endl;
}

template <class T>
void Namelist<T>::appendNode (T newName)
{
	ListNode<T> *newNode;
	ListNode<T> *nodePtr;
	
	newNode = new ListNode<T> (newName);
	
    if (!head)
     head = newNode;
    else
    {
    	nodePtr = head;
    	while (nodePtr->next)
		 nodePtr = nodePtr->next;
		 
		nodePtr->next = newNode;
	}
}
template <class T>
Namelist<T> :: ~Namelist()
{
	ListNode<T> *nodePtr;
	ListNode<T> *nextNode;
	
	nodePtr = head;
	
	while(nodePtr!=nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	
}

template <class T>
T Namelist<T>::searchnode(T name)
{
	bool found = false;
	ListNode<T> *nodePtr;
	nodePtr = head;
	
	while (nodePtr != nullptr )
	{
		if(nodePtr->PlayerName == name)
		{
			return nodePtr->PlayerName;
			found = true;
		}
		else
		{
			nodePtr = nodePtr->next;
		}
 	}
 	if(!found)
 	{
 		cout << "Null" << endl;
	}
 
}
#endif


