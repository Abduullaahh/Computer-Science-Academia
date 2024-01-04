#include"Person.h"
class faculty :public person
{
private:
	int ccount;
	int dtele;
public:
	faculty()
	{

	}
	faculty(string fn, string In, int age, int ccount, int ttel);
	void setccount(int coursec);
	void setdtele(int tel);
	int getccount();
	int getdtele();
	void printfac();
	void printfaculty();
	~faculty();
};
