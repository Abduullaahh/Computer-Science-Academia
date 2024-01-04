#include<iostream>
#include"Person.h"
#include"Student.h"
#include"Faculty.h"

using namespace std;

person::person()
{
	last_name = "";
	age = 0;
	cout << "person() called" << endl;
}
person::person(string fN, string IN, int Age)
{
	first_name = fN;
	last_name = IN;
	age = Age;
	cout << "person(string,string,int) called" << endl;

}

void person::setfname(string fname)

{

	first_name = fname;

}

void person::setlname(string Iname)

{
	last_name = Iname;
}
void person::setage(int Age)
{
	age = Age;

}
string person::getfname()
{
	return first_name;
}
string person::getlname()
{
	return last_name;
}
int person::getage()
{
	return age;
}
void person::printInformation()
{
	cout << getfname() << "";
	cout << getlname() << " is";
	cout << getage() << " years old " << endl;
}
person::~person()
{

	cout << "~person() called" << endl;

}

faculty::faculty(string fn, string In, int age, int cCount, int ttel) :person(fn, In, age)
{
	ccount = cCount;
	dtele = ttel;
	cout << "faculty(string,string,int,int,int) called" << endl;
}
void faculty::setccount(int coursec)
{
	ccount = coursec;
}
void faculty::setdtele(int tel)
{
	dtele = tel;
}
int faculty::getccount()
{
	return ccount;
}
int faculty::getdtele()
{
	return dtele;
}
void faculty::printfac()
{

	cout << getfname() << endl;
	cout << getlname() << endl;
	cout << getage() << endl;
	cout << getccount() << endl;
	cout << getdtele() << endl;

}

void faculty::printfaculty()

{

	cout << "Faculty Member name: " << getfname() << " ";
	cout << getlname() << ", Age: ";
	cout << getage() << ",Number of courses: ";
	cout << getccount() << ", Ext. ";
	cout << getdtele() << endl;//“Faculty Member name: Richard Karp, Age: 45, Number of courses: 2, Ext. 420”
}
faculty::~faculty()
{

	cout << "~faculty() called" << endl;

}


student::student(string fn, string In, int Age, float Cgpa) :person(fn, In, Age)
{
	cgpa = Cgpa;
	cout << "student(string,string,int,float) called" << endl;
}
void student::setcgpa(float CGPA)
{
	cgpa = CGPA;
}
float student::getcgpa()
{
	return cgpa;
}
student::~student()
{
	cout << "~student() called" << endl;
}
void student::printst()
{
	cout << getfname() << endl;
	cout << getlname() << endl;
	cout << getage() << endl;
	cout << getcgpa() << endl;
}

void student::printstudent()
{
	cout << getfname() << " ";
	cout << getlname() << " is ";
	cout << getage() << " years old, his cgpa is ";
	cout << getcgpa() << endl;
}

int main()
{
	student obj1("Tea", "Thompson",22,3.91);//student(string fn,string In,int Age,float Cgpa");
	faculty obj2("Richard", "Karp", 45, 2, 420);// faculty(string fn,string In,int age,int ccount,int ttel);
	obj1.printst();
	obj2.printfac();
	obj1.printstudent();
	obj2.printfaculty();
	system("pause");
}