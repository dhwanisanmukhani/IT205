#include <iostream> //http://quiz.geeksforgeeks.org/binary-search-tree-set-2-delete/
using namespace std;

template <typename E>
class node							//Class node
{
public:
	E data;
	node *nextElement;
	node()
	{
		data=0, nextElement=NULL;	
	}
};

template <typename E> 
class List
{
	private:
		void operator=(const List&){}
		List(const List&){}
	public:
		List(){}					//constructor
		virtual ~List(){}				//destructor
		virtual int NumberOfElements() const=0;		//Return number of elements in the list
		virtual int CurrentLocation() const=0;		//Return the current location of the element
		virtual const E& getData() const=0;		//Return the data of current element
		virtual void clear() =0;			//clear all data from the list
		virtual void insert(const E& Data)=0;		//Insert data in list at current location
		virtual void append(const E& Data)=0;		//Insert data at the end of list
		virtual E remove()=0;				//Delete the data at current location
		virtual void setListLocationToStart()=0;	//Set the current location to the start of the list
		virtual void setListLocationToEnd()=0;		//Set the current location to the end of the list
		virtual void previousElement()=0;		//Set current location to the element on the left side
		virtual void NextElement()=0;			//Set current location to the element on the right side
		virtual void setToNewLocation(int location)=0;	//Set current location to a new location
};

template <typename E>
class linkList : public List<E> 
{
private:
	node<E>* firstElement; 
	node<E>* lastElement; 
	node<E>* currentElement;
	int sizeOfList;
public:
	linkList()
	{
		firstElement=lastElement=currentElement=new node<E>;
		sizeOfList=0;
	}
	~linkList() 						//destructor
	{
		node<E>* temp;
		for(currentElement=firstElement;currentElement!=NULL;currentElement=temp)
		{
			temp=currentElement->nextElement;
			delete currentElement;
			currentElement=NULL;
		}
	}
	int NumberOfElements() const 		//Number of elements				
	{
		return sizeOfList;
	}
	int CurrentLocation() const				//Current location index
	{
		node<E>* head;
		int i=1;
		head=firstElement;
		while(head!=currentElement)
		{
			i++;
			head=head->nextElement;
		}
		return i;
	}
	const E& getData() const 				//Value of the current location node
	{
		return currentElement->data;
	}
	void clear() 							//Clear the linked list
	{
		node<E>* temp;
		for(currentElement=firstElement;currentElement!=NULL;currentElement=temp)
		{
			temp=currentElement->nextElement;
			delete currentElement;
			currentElement=NULL;
		}
	}
	void insert(const E& Data)				//Insert a node at current location
	{
		node<E> *temp;
		node<E> *n;
		temp=new node<E>;
		n=new node<E>;
		if(CurrentLocation()==1)
		{
			if(sizeOfList==0)
			{
				firstElement->data=Data;
				lastElement=firstElement;
			}
			else
			{
				n->data=Data;
				n->nextElement=firstElement;
				firstElement=n;
			}
		}
		else
		{
			temp=firstElement;
			while(temp->nextElement!=currentElement)
			{
				temp=temp->nextElement;
			}
			n->data=Data;
			n->nextElement=temp->nextElement;
			temp->nextElement=n;
			currentElement=n;
		}
		sizeOfList++;
	}
	void append(const E& Data)			//Add a node at last
	{
		node<E> *n;
		n=new node<E>;
		n->nextElement=NULL;
		n->data=Data;
		if(sizeOfList==0)
		{
			firstElement->data=Data;
			lastElement=firstElement;
		}
		else
		{
			lastElement->nextElement=n;
			lastElement=n;
		}
		sizeOfList++;
	}
	E remove()					//Remove node at current location
	{
		node<E> *temp,*ret;
		ret=new node<E>;
		ret=firstElement;
		temp=new node<E>;
		temp=firstElement;
		if(sizeOfList == 0)
		{
			cout<<"Empty";
		}
		else
		{
			firstElement=firstElement->nextElement;
			temp->nextElement=NULL;
		}
		sizeOfList--;	
		return ret->data;	
	}
	void setListLocationToStart()			//Current nod is set to the first node
	{
		currentElement=firstElement;
	}
	void setListLocationToEnd()			//Current node is set to the last node
	{
		currentElement=lastElement;
	}
	void previousElement()				//Current node is set to the previous node
	{
		node<E> *temp;
		temp=new node<E>;
		temp=firstElement;
		if(currentElement==firstElement)
		{
			cout<<"Not possible"<<endl;
			return;
		}
		while(temp->nextElement!=currentElement)
		{
			temp=temp->nextElement;
		}
		currentElement=temp;
	}
	void NextElement()				//Current node is set to next node
	{
		node<E> *temp;
		temp=new node<E>;
		temp=currentElement;
		if(currentElement==lastElement)
		{
			cout<<"Not possible"<<endl;
			return;
		}
		currentElement=temp->nextElement;
	}
	void setToNewLocation(int location)		//Current location is set to the given location
	{
		node<E> *temp;
		temp=new node<E>;
		temp=firstElement;
		for(int i=1;i<location;i++)
		{
			temp=temp->nextElement;
		}
		currentElement=temp;
	}
	void display()					//Display list
	{
		node<E> *temp;
		temp=new node<E>;
		temp=firstElement;
		for(int i=1;i<=sizeOfList;i++)
		{
			cout<<temp->data<<" ";
			temp=temp->nextElement;
		}
		cout<<endl;
	}
};

template <typename E>
class Queue
{
private:
	void operator = (const Queue&) {}
	Queue(const Queue&) {}
public:
	Queue() {}
	virtual ~Queue() {}
	virtual void insert(const E& Data) = 0;
	virtual E remove() = 0;
	virtual int length() const = 0;
	virtual const E& firstElement() const = 0;
	virtual void clearQueue() = 0;
};

template <typename E>
class QueueLinkList : public Queue<E>
{
private:
	int size;
	linkList<E>* QueueArray;
public:
	QueueLinkList()
	{
		QueueArray = new linkList<E>();
	}
	~QueueLinkList()
	{
		delete QueueArray;
	}
	void insert(const E& Data)
	{
		QueueArray->append(Data);
	}
	E remove()
	{
		return QueueArray->remove();
	}
	int length() const
	{
		return QueueArray->NumberOfElements();
	}
	const E& firstElement() const
	{
		QueueArray->setListLocationToStart();
		return QueueArray->getData();
	}
	void clearQueue()
	{
		QueueArray->clear();
	}
	void display()
	{
		QueueArray->display();
	}
};

int main()
{
	QueueLinkList<int> q;
	q.insert(10);
	q.insert(20);
	q.display();
	/*int a=q.length();
	cout<<a<<endl;
	a=q.firstElement();
	cout<<a<<endl;
	a=q.remove();
	cout<<a<<endl;
	q.display();
	a=q.length();
	cout<<a<<endl;*/
	q.clearQueue();
	return 0;
}