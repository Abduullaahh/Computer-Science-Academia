#include"Person.h"

class student :public person
{
private:
	float cgpa;
public:
	student(string fn, string In, int Age, float Cgpa);
	void setcgpa(float CGPA);
	float getcgpa();
	void printst();
	void printstudent();
	~student();
};
