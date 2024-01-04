//Abdullah Tahir
//Roll : 21l-5419 , Section : 1J
//PF Assignment # 1 , Question#2

#include<iostream>
using namespace std;

int main()
{
	double HourlyWage, NumberofHours, GrossSalary, WithHoldingTax, Deduction, Netpay;
	cout << "Enter Hourly Wage=" << endl;
	cin >> HourlyWage;
	cout << "Enter number of hours worked=" << endl;
	cin >> NumberofHours;
	GrossSalary = HourlyWage * NumberofHours;
	cout << "Withholding Tax=" << endl;
	cin >> WithHoldingTax;
	Deduction = (GrossSalary / 100) * WithHoldingTax;
	Netpay = GrossSalary - Deduction;
	cout << "Net pay is=" << Netpay << endl;
	return 0;
}