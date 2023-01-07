#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;

class DynIntStack
{
	private:
		struct StackNode{
		int value; // Value in the node
		StackNode *next; // Pointer to the next node
		};
		StackNode *stackTop; // Pointer to the stack top
	public:
		DynIntStack() // constructor
		{stackTop = nullptr;} 
		~DynIntStack(); // Destucrtor
		
		//Stack list operations
		void push(int); // call push 
		void pop(int&); // call pop
		int top(); 
		bool isEmpty();
};

#endif

DynIntStack::~DynIntStack()
{
	StackNode *nodePtr=nullptr; //pointer to delete the node
	StackNode *nextNode=nullptr; 
	
	nodePtr = stackTop; 
	
	while(nodePtr!=nullptr) // while there elements in the stack
	{
		nextNode = nodePtr->next; // set nextNode to point the current node
		delete nodePtr; // advance stackTop to the next node
		nodePtr = nextNode; // deallocate memory occupied by nodePtr
	}
}

void DynIntStack::push(int num)
{
	StackNode *newNode = nullptr; // pointer to a new node
	
	newNode = new StackNode; // allocate a new node
	newNode->value = num; // and store num there
	
	// if there are no nodes in the list make newNode the first node
	if(isEmpty())
	{
		stackTop = newNode; // point top to new node
 		newNode->next = nullptr; // make the next node pointing to nullptr
	}
	else
	{
		newNode->next = stackTop; // insert newNode before top
		stackTop = newNode; // point to whereever newNode is pointing at
	}
}

void DynIntStack::pop(int& num)
{
	StackNode *temp = nullptr; // declare temporary pointer
	
	// First make sure the stack isn't empty
	if(isEmpty())
	{
		cout << "The stack is empty." << endl;
	}
	else // pop value off top of stack
	{
		num = stackTop->value; // let num hold the value pointed by stackTop
		temp = stackTop->next; // let pointer temp point to where stackTop->next
		delete stackTop; // delete stackTop
		stackTop = temp; // stackTop will point to where temp is pointing at
	}
}

int DynIntStack::top()
{
	// First make sure the stack isn't empty
	if(isEmpty())
	{
		cout << "The stack is empty." << endl; // display the stack is empty
	}
	else
	{
		return stackTop->value; // return the value pointer by stackTop
	}
}

bool DynIntStack::isEmpty()
{
	bool status;
	
	// First make sure the stack isn't stackTop
	if(!stackTop)
	status = true; //status is true
	else
	status = false; // status is false
	
	return status; // retrun status
}
