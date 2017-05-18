#include <iostream>   //http://quiz.geeksforgeeks.org/binary-search-tree-set-2-delete/
using namespace std;
template <typename E>
class BinaryTreeNode //: public BinNode<E>
{
	E value; 						// The node’s value
	BinaryTreeNode * leftChild; 	// Pointer to left child
	BinaryTreeNode * rightChild; 	// Pointer to right child
public :
	BinaryTreeNode()							//default constructor
	{
		leftChild = rightChild = NULL; 
	}
	BinaryTreeNode(E e, BinaryTreeNode* l = NULL, BinaryTreeNode* r = NULL)		//constructor
	{ 
		value = e; 
		leftChild = l; 
		rightChild = r;
	}
	~BinaryTreeNode() 															// Destructor
	{ 
		delete leftChild; 
		delete rightChild; 
	}	
						
	E& getValue() 				// Functions to return the value and key
	{
		return value; 
	}														
	void setValue(const E& e) 	// Functions to set the value and key
	{
		value = e;
	} 										
	inline BinaryTreeNode* left() 	// Functions to return the left children
	{ 
		return leftChild; 
	}
	void setLeft(BinaryTreeNode<E>* b) 	// Functions to set the left children
	{ 
		leftChild = b; 
	}
	inline BinaryTreeNode* right() 	// Functions to return the right children
	{ 
		return rightChild; 
	}
	void setRight(BinaryTreeNode<E>* b)	// Functions to set the right children
	{ 
		rightChild = b; 
	}					
	bool isLeaf()			// Return true if it is a leaf, false otherwise 
	{ 
		return (leftChild == NULL) && (rightChild == NULL); 
	}
};
	
BinaryTreeNode<int>* root = NULL;	
BinaryTreeNode<int>* parent(BinaryTreeNode<int>* b)
	{
		BinaryTreeNode<int>* y;
		BinaryTreeNode<int>* x;
		y = NULL;
		x = root;
		while (x != NULL && x != b)
		{
			y = x;
			if(x->getValue() > b->getValue())
				x = x->left();
			else
				x = x->right();
		}
		return y;
	}
int insert(int key)
{
	BinaryTreeNode<int>* b ;
	BinaryTreeNode<int>* y;
	BinaryTreeNode<int>* x;
	b = new BinaryTreeNode<int>;
	b->setValue(key);
	y = NULL;
	if(root == NULL)
	{
		root=new BinaryTreeNode<int>;
		root->setValue(key);
	}
	else
	{
		x = root;
	while (x != NULL)
	{
		y = x;
		if(x->getValue() > b->getValue())
		{
			x = x->left();
		}
		else
		{
			x = x->right();
		}
			
	}
	if (b->getValue() < y->getValue())
	{
		y->setLeft(b);
	}
	else
		y->setRight(b);
	}
	return 0;
}
void transplant(BinaryTreeNode<int>* u,BinaryTreeNode<int>* v)
{
	BinaryTreeNode<int>* a;
	BinaryTreeNode<int>* b;
	BinaryTreeNode<int>* c;
	c = parent(u);
	if (c == NULL)
	{	
		root->setRight(v->right());
		root->setLeft(v->left());
	}
	else if (u == parent(u)->right() )
	{
		a = parent(u);
		a->setRight(v);
	}
	else
	{
		b = (parent(u));
		b->setLeft(v);		
	}
}

BinaryTreeNode<int>* treeMin(BinaryTreeNode<int>* b)
{
	BinaryTreeNode<int>* y;
	BinaryTreeNode<int>* x;
	x = b;
	while(x != NULL)
	{
		y = x;
		x = x->left();
	}
	return y;
}

BinaryTreeNode<int>* search(int k)
{
	BinaryTreeNode<int>* x;
	x = root;
	while(x != NULL && x->getValue() != k)
	{
		if(k < x->getValue())
			x = x->left();
		else x = x->right();
	}
	return x;
}

void Delete(int key)
{
	BinaryTreeNode<int>* b;
	BinaryTreeNode<int>* y;
	BinaryTreeNode<int>* m;
	BinaryTreeNode<int>* n;
	y = NULL;
	if (root == NULL)
	{
		cout<<"ERROR"<<endl;
		return;
	}
	else 
	{
		b = search(key);
	}
	if(b->left() == NULL)
	{
		transplant(b,b->right());
	}
	else if( b->right() == NULL )
	{
		transplant(b,b->left());
	}
	// else if((b->left() == NULL) && (b->right() == NULL))
	// {
	// 	if (b == (parent(b))->right() )
	// 		(parent(b))->setRight(NULL);
	// 	else
	// 		(parent(b))->setLeft(NULL);
	// }
	else
	{
		y = treeMin(b->right());
		
		if (parent(y) != b)
		{
			transplant(y,y->right());
			y->setRight(b->right());
			m = parent(b->right());
			m = y;
		}
		transplant(b,y);
		y->setLeft(b->left());
	} 
}
void InOrderTravelser(BinaryTreeNode<int>* x)
{
	if (x== NULL)
		return;
	else
	{
		InOrderTravelser(x->left());
		cout<<x->getValue()<<" ";
		InOrderTravelser(x->right());
	}
}

void PreOrderTravelser(BinaryTreeNode<int>* x)
{
	if (x == NULL);
	else
	{
		int i = x->getValue();
		cout<<i<<" ";
		PreOrderTravelser(x->left());
		PreOrderTravelser(x->right());
	}
}
void PostOrderTravelser(BinaryTreeNode<int>* x)
{
	if (x == NULL);
	else
	{
		PostOrderTravelser(x->left());
		PostOrderTravelser(x->right());
		cout << x->getValue() << " ";
	}
}

int main()
{
	insert(10);
	insert(5);
	insert(15);
	insert(3);
	insert(4);
	insert(2);
	insert(7);
	insert(1);
	insert(9);
	insert(8);
	insert(6);
	insert(18);
	insert(13);
	insert(11);
	insert(14);
	insert(12);
	insert(16);
	insert(17);
	insert(20);
	insert(19);
	BinaryTreeNode<int>* x;
	x = parent(root->left());
	cout<<x->getValue()<<endl;
	InOrderTravelser(root);
	cout<<endl;
	Delete(18);
	InOrderTravelser(root);
	cout<<endl;
	Delete(3);
	InOrderTravelser(root);
	cout<<endl;
}
