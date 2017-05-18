#include <iostream>
#include <stack>
using namespace std;

void move(int n,stack<int>& source,stack<int>& target,stack<int>& auxiliary)
{
	if(n>0)
	{
		move(n-1,source,auxiliary,target);
		target.push(source.top());
		source.pop();
		move(n-1,auxiliary,target,source);
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	stack<int> a;
	stack<int> b;
	stack<int> c;
	for(int i=0;i<n;i++)
	{
		a.push(i+1);
	}
	move(n,a,c,b);
	for(int i=0;i<n;i++)
	{
		cout<<c.top()<<endl;
		c.pop();
	}
	return 0;
}