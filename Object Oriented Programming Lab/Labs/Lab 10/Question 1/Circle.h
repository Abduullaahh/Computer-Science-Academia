#include"Point.h"

class Circle
{
private:
	Point center;
	float radius;
public:
	//Constructor
	Circle(int x, int y, float r);
	//Function to print radius
	void print();
	//Destructor
	~Circle();
};