#include <iostream>
#include <cassert>

using namespace std;

class Node{
private:
	int data;
	Node* next;
public:
	Node(int _data=0, Node* _next=NULL){
		data = _data;
		next = _next;
	}
	~Node(){
		if(next)delete next;
		next = NULL;
	}
	int get_data(){
		return data;
	}
	Node* get_next(){
		return next;
	}
	void set_data(int _data){
		data = _data;
	}
	void set_next(Node* _next){
		next = _next;
	}
};

class SingleLinkedList{
private:
	Node* root;
	int sz;
public:
	SingleLinkedList(){
		root = NULL;
		sz = 0;
	}
	~SingleLinkedList(){
		if(root)delete root;
		root = NULL;
	}
	Node* get_root(){
		return root;
	}
	int get_size(){
		return sz;
	}
	void insert(int data, int pos=0){
		assert(pos>=0 && pos<=sz);
		// Creating node
		Node* new_node = new Node(data, root);

		if(pos==0){
			root = new_node;
		}
		else{
			Node* itr = root;
			int idx = 1;
			while(idx<pos){
				itr = itr->get_next();
				idx++;
			}
			new_node->set_next(itr->get_next());
			itr->set_next(new_node);
		}
		sz++;
		display();
	}
	void erase(int pos){
		assert(pos>=1 && pos<=sz);
		Node* itr = root;
		int idx=1;
		if(pos==1){
			root = root->get_next();
			itr->set_next(NULL);
			delete itr;
		}
		else{
			while(idx<pos-1){
				itr = itr->get_next();
				idx++;
			}
			Node* tmp = itr->get_next();
			itr->set_next(tmp->get_next());
			delete tmp;			
		}
		sz--;
		display();
	}
	void display(){
		Node* itr = root;
		while(itr){
			cout<<itr->get_data()<<" -> ";
			itr = itr->get_next();
		}
		cout<<endl;
	}
	void swap(int p1,int p2)
	{
		if(p1>p2)
		{
			swap(p1,p2);	
		}
		assert(p1>=1 && p1<sz);
		assert(p2>=1 && p2<sz);
		if(p1==1)
		{
			Node* new_node;
			Node* itr;
			Node* new_node2;
			itr=root;
			new_node=root;
			new_node2=root->get_next();
			int idx=1;
			while(idx<p2-1)
			{
				cout<<"1"<<endl;
				itr=itr->get_next();
				idx++;
			}
			cout<<"2"<<endl;
			root=itr->get_next();
			cout<<"3"<<endl;
			root->set_next(new_node2);
			cout<<"4"<<endl;
			new_node->set_next(itr->get_next()->get_next());
			itr->set_next(new_node);
			cout<<"6"<<endl;
		}
	}
};

int main(){
	SingleLinkedList ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.insert(4);
	//ll.erase(4);
	//ll.erase(1);
	//ll.erase(2);
	ll.swap(1,3);
	return 0;
}