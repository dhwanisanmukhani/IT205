#include <iostream>
using namespace std;

template <typename E> class List
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
		virtual void insert(const E& data)=0;		//Insert data in list at current location
		virtual void append(const E& data)=0;		//Insert data at the end of list
		virtual E remove()=0;				//Delete the data at current location
		virtual void setListLocationToStart()=0;	//Set the current location to the start of the list
		virtual void setListLocationToEnd()=0;		//Set the current location to the end of the list
		virtual void previousElement()=0;		//Set current location to the element on the left side
		virtual void nextElement()=0;			//Set current location to the element on the right side
		virtual void setToNewLocation(int location)=0;	//Set current location to a new location
};

template <typename E> class arrayList:public List<E>
{
	private:
		int arraySize;					//Maximum size of list
		int currentSize;				//Number of data elements stored
		int currentLocation;				//location pointer of the list
		E* dataArray;					//Array for storing data
	public:
		arrayList(int size)				//Constructor to create arrayList
		{
			arraySize=size;
			currentSize=currentLocation=0;
			dataArray=new E[arraySize];
		}
		~arrayList()					//Destructor
		{
			delete [] dataArray;
		}
		int NumberOfElements() const 				//returns number of elements in the list
		{
			return currentSize;
		}		
		int CurrentLocation() const 				//returns current location
		{	
			return currentLocation;
		}		
		const E& getData() const 					//returns the data at current location
		{
			return dataArray[currentLocation];
		}	
		void setListLocationToStart() 				//set current location to beginning
		{ 
			currentLocation=0; 
		}		
		void setListLocationToEnd() 				//set current location to end
		{ 
			currentLocation=currentSize-1; 
		}	
		void previousElement() 						//set current location to previous element
		{
			if(currentLocation!=0)
				currentLocation--;
		}	
		void nextElement()						//set current location to next element
		{
			if(currentLocation<currentSize-1)
				currentLocation++;
		}
		void setToNewLocation(int location) 				//set current location to given location
		{
			if(location>=0 && location<currentSize)
				currentLocation=location;
		}
		void insert(const E& data)					//insert data at current location
		{
			if(currentSize==arraySize)
				cout<<"Array is Full.. Can't insert more data"<<endl;
			else
			{
				int i;
				for(i=currentSize-1;i>=currentLocation;i--)
					dataArray[i+1]=dataArray[i];
				dataArray[currentLocation]=data;
				currentSize++;
			}
		}
		void append(const E& data)					//insert data at the end of array
		{
			if(currentSize==arraySize)
				cout<<"Array is Full..Can't insert more data"<<endl;
			else
			{
				dataArray[currentSize]=data;
				currentSize++;
			}
		}
		E remove()							//remove data element at current location
		{
			E temp = dataArray[0];
			if(currentSize==0)
			{
				cout<<"Array is Empty"<<endl;
				return 0;
			}
			else
			{
				for(int i=0;i<currentSize-1;i++)
				{
					dataArray[i] = dataArray[i+1];
				}
				dataArray[currentSize-1] = 0;
				currentSize--;
			}
			return temp;
		}
		void clear()							//clears the contenets of array
		{
			delete dataArray;
			currentLocation=0;
			currentSize=0;
			dataArray=new E[arraySize];
		}
		void display()							//display array elements
		{
			int i;
			for(i=0;i<currentSize;i++)
				cout<<dataArray[i]<<" ";
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
	virtual const E& FirstElement() const = 0;
	virtual void clearQueue() = 0;
};

template <typename E>
class QueueArrayList : public Queue<E>
{
private:
	int maximumSize;
	int firstElement;
	int lastElement;
	arrayList<E>* QueueArray;
public:
	QueueArrayList(int size)
	{
		maximumSize = size;
		QueueArray = new arrayList<E>(size);
		firstElement = lastElement = 0;
	}
	~QueueArrayList()
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
	const E& FirstElement() const
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
	QueueArrayList<int> q(5);
	q.insert(10);
	q.insert(20);
	q.display();
	int a=q.length();
	cout<<a<<endl;
	a=q.FirstElement();
	cout<<a<<endl;
	a=q.remove();
	cout<<a<<endl;
	q.display();
	a=q.length();
	cout<<a<<endl;
	q.clearQueue();
	return 0;
}