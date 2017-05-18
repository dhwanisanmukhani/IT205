#include <iostream>
#include <math.h>
using namespace std;

class vect2
{
private:
		double x,y;
  	string s;
public:
	const double& getx(){
		return x;
	}
	const double& gety(){
		return y;
	}
	void setx(const double& a){
		x=a;
	}
	void sety(const double& b){
		y=b;
	}
	vect2(double a, double b):x(a), y(b){
	}
	vect2& operator+=(const vect2& v)
	{
		x = x + v.x;
		y = y + v.y;
    return *this;
	}
  friend vect2 operator+(vect2 lhs, const vect2& rhs){
		lhs += rhs;
    return lhs;
  }
	vect2& operator-=(const vect2& v)
	{
		x=x-v.getx();
		y=y-v.gety();
		return *this;
	}
  void norm(){
    return sqrt(pow(x,2)+pow(y,2));
  }
	vect2 unit_vec()
	{
		float a=norm();
		vect2 unitv(x/a,y/b);
		return unitv;
	}
};

int main()
{
	return 0;
}