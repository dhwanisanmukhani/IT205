#include<iostream>
using namespace std;

template <typename E> class List
{
	private:
		void operator=(const List&){}
		List(const List&){}
	public:
		List(){}			//constructor
		virtual ~List(){}		//destructor
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
		int NumberOfElements() const { return currentSize; }		//returns number of elements in the list
		int CurrentLocation() const { return currentLocation; }		//returns current location
		const E& getData() const { return dataArray[currentLocation]; }	//returns the data at current location
		void setListLocationToStart() { currentLocation=0; }		//set current location to beginning
		void setListLocationToEnd() { currentLocation=currentSize-1; }	//set current location to end
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
			if(currentSize==0)
			{
				cout<<"Array is Empty"<<endl;
				return 0;
			}
			else
			{
			int i;
			E temp=dataArray[currentSize];
			for(i=currentLocation;i<currentSize-1;i++)
				dataArray[i]=dataArray[i+1];
			if(currentLocation==currentSize-1 && currentSize>1)
				currentLocation--;
			currentSize--;
			return temp;
			}
		}
		void clear()							//clears the contenets of array
		{
			currentLocation=0;
			currentSize=0;
			delete [] dataArray;
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
int main()
{
	arrayList <int> list1(5);
	list1.append(3);
	list1.append(5);
	list1.append(2);
	list1.append(1);
	list1.display();
	list1.setToNewLocation(1);
	list1.insert(2);
	list1.display();
	list1.previousElement();
	list1.remove();
	list1.display();
	list1.nextElement();
	list1.insert(6);
	list1.display();
	list1.clear();
	list1.insert(9);
	list1.display();
	return 0;
}
