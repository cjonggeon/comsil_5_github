#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
	public:
		T data;
		Node *link;
		Node(T element) //생성자
		{
			data=element;
			link=NULL;
		}
};

template <class T>
class LinkedList
{
	protected:
		Node<T> *first;
		int current_size;
	public:
		LinkedList()
		{
			first=0;
			current_size=0;
		};
		int GetSize() { return current_size; };
		void Insert(T element);
		virtual bool Delete(T &element);
		void Print();
};

template <class T>
class Stack : public LinkedList<T> {
	public:
		Stack();

		virtual bool Delete(T &element);
};


template <class T>
void LinkedList<T>::Insert(T element)
{
	Node<T> *newnode=new Node<T> (element);
	newnode->link=first;
	first=newnode;
	current_size++;
}

template <class T>
bool LinkedList<T>::Delete(T &element)
{
	if (first==0)
		return false;
	
	Node<T> *current=first; //first부터 시작해 end node를 찾으러 갈 것
	Node<T> *previous=NULL;
	
	while (1)
	{
		if (current->link==0) //found end node: current가 6end node
		{
			if (previous) previous->link=current->link;
			else first=first->link; //previous가 없으면: first node가 end node였던것
			break;
		}
		previous=current;
		current=current->link;
	}

	element=current->data; //current
	delete current;

	current_size--;
	
	return true;
}

template <class T>
void LinkedList<T>::Print()
{
	if (current_size>0)
	{
		int sequence=1;
		Node<T> *current=first;
		while (current->link!=NULL)
		{
			cout<<"["<<sequence<<"|"<<current->data<<"]->";
			
			sequence++;
			current=current->link;
		}	
	
		cout<<"["<<sequence<<"|"<<current->data<<"]"<<endl;;
	}
}


template <class T>
Stack<T>::Stack() : LinkedList<T>() {
	this->first=0;
	this->current_size=0;
}


template <class T>
bool Stack<T>::Delete(T &element)
{
	if (this->first==0)
		return false;

	Node<T> *second=this->first->link;
	Node<T> *current=this->first;
	
	element=this->first->data;
	
	//first->link=second->link;
	this->first=second;
	delete current;

	this->current_size--;

	return true;
}
