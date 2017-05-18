#include <iostream>
#include <math.h>
using namespace std;

template <typename E>
class BinaryHeap
{
private:
	E* heap;
	int maxsize;
	int number;
public:
	BinaryHeap(E* e, int max, int num)
	{
		e = new E[max];
		heap = e;
		maxsize = max;
		number = num;
	}
	//~BinaryHeap(){};
	int sizeOfHeap() 
	{
		return number; 
	}
//Check if the given position is a leaf node 
	bool LeafNode(int pos) 
	{
		if(pos >= ceil(number/2) && pos <= number - 1)
		{
			return true;
	 	}	
		else
		{
		 	return false; 
		}
	}
// returns the position of right child 
	int rightChildNode(int pos) 
	{
		return 2*pos +2;
	}
// returns the position of left child 
	int leftChildNode(int pos) 
	{
		return 2*pos +1;
	}
//
	int parent(int pos)
	{
		if(pos >= number)
		{
			cout<<"ERROR"<<endl;
			return 0;
		}
		return ceil(pos-1)/2;
	}
	void insert(const E& element)
	{
		if(sizeOfHeap() == maxsize)
			cout <<"ERROR" <<endl;
		else
		{
			heap[number] = element;
			number++;
			int pos = number -1;
			while(pos != 0 && heap[parent(pos)] < heap[pos])
			{
				E temp = heap[pos];
				heap[pos] = heap[parent(pos)]; 
				heap[parent(pos)] = temp;
				pos = parent(pos);
			}
		}
	}
	E remove(int pos)
	{
		if(number == 0)
		{
			cout<<"ERROR"<<endl;
			return -1;
		}
		else
		{
			E temp;
			temp = heap[pos];
			heap[pos] = heap[number-1];
			heap[number-1] = 0;
			number--;
			heapify(pos);
			return temp;
		}
	}
	void heapify(int pos)
	{
		E large;
		if((2*pos)+2 < number)
		{
			if(heap[(2* pos) +1] > heap[(2* pos) +2])
			{
				large = (2* pos) +1;
			}
			else
			{
				large = (2* pos) +2;
			}
			if(heap[pos] < heap[large])
			{
				E temp = heap[pos];
				heap[pos] = heap[large];
				heap[large] = temp;
				heapify(large);
			}
		}
	}
	void display()
	{
		for(int i = 0; i < number; i++)
		{
			cout <<heap[i]<<" ";
		}
		cout <<endl;
	}
};
int main()
{
	int* e;
	BinaryHeap<int> list(e, 10, 0);
	list.insert(3);
	list.insert(1);
	list.insert(2);
	list.insert(4);
	list.insert(5);
	list.display();
	cout<<"Size: "<<list.sizeOfHeap()<<endl;
	int temp = list.remove(0);
	cout<<"New : ";
	list.display();
	return 0;
}