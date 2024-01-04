class person
{
private:
	string first_name;
	string last_name;

protected:
	int age;

public:
	person();
	person(string fN, string IN, int Age);
	void setfname(string);
	void setlname(string);
	void setage(int);
	string getfname();
	string getlname();
	int getage();
	void printInformation();
	~person();
};