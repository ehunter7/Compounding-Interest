#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

#include "CompoundingInterest.h"



using namespace std;


void DisplayInputHeader();
void GetUserInput(CompoundingInterest& tmp);
void DisplayHeader(string condition);
void displayCalculations(CompoundingInterest& tmp, int index, string condition);

int main() {

	CompoundingInterest* tmp;

	tmp = new CompoundingInterest;

	char proceed = 'y';

	while (tolower(proceed) == 'y') {

		tmp = new CompoundingInterest;

		system("clear");

		DisplayInputHeader();

		

		GetUserInput(*tmp);
		
		cout << endl;

		system("pause");

		cout << endl;

		DisplayHeader("without");

		for (unsigned int i = 1; i <= tmp->GetYears(); i++) {
			displayCalculations(*tmp, i, "without");
		}

		//New line for readability 
		cout << endl;
		DisplayHeader("with");

		for (unsigned int i = 1; i <= tmp->GetYears(); i++) {
			displayCalculations(*tmp, i, "with");
		}

		cout << "Enter 'y' to continue or 'q' to quite: ";
		cin >> proceed;

		cin.ignore(1000, '\n');

		delete tmp;
	}

	return 0;
}

void DisplayInputHeader() {
	cout << setfill('~') << setw(31) << " " << endl;
	cout << setfill('~') << setw(10) << " ";
	cout << "Data Input" << " ";
	cout << setfill('~') << setw(10) << " " << endl;
}

void GetUserInput(CompoundingInterest& tmp){
	string shuttle;



	cout << "Initial Investment Amount: ";
	getline(cin, shuttle);

	shuttle.erase(remove(shuttle.begin(), shuttle.end(), '$'), shuttle.end());

	tmp.SetPrinciple(stod(shuttle));


	cout << "Monthly Deposits: ";
	getline(cin, shuttle);

	shuttle.erase(remove(shuttle.begin(), shuttle.end(), '$'), shuttle.end());

	tmp.SetDepositAmount(stod(shuttle));

	cout << "Annual Interest: ";
	getline(cin, shuttle);

	shuttle.erase(remove(shuttle.begin(), shuttle.end(), '%'), shuttle.end());

	tmp.SetInterest(stod(shuttle));

	cout << "Number of years: ";
	cin >> shuttle;

	tmp.SetYears(stoi(shuttle));

	
}

void DisplayHeader(string condition) {

	if (condition == "with") {

		cout  << setfill(' ') << setw(56) << "Balance and Interest With Additional Monthly Deposits" << endl;
	}
	else {
		cout << setfill(' ') << setw(58) << "Balance and Interest Without Additional Monthly Deposits" << endl;

	}
	cout << setfill('~') << setw(60) << " " << endl;

	cout << setfill(' ') << setw(2) << " " << "Year" << setfill(' ') << setw(5) << " " << "Year End Balance"
		<< setfill(' ') << setw(5) << " " << "Year End Earned Interest" <<  endl;

	cout << setfill('~') << setw(60) << " " << endl;
}

void displayCalculations(CompoundingInterest& tmp, int index, string condition) {

	double shuttle = (condition == "with" ? tmp.CalculateYearlyInterestWithDeposits(index) :
		tmp.CalculateYearlyInterestWithoutDeposits(index));

	string tmpstr = to_string(shuttle);

	cout << setw(5) << setfill(' ') << index << setw(11) << setfill(' ') << "$ "
		<< fixed << setprecision(2) << shuttle;
	 cout << setw(25 - tmpstr.length()) << right <<  "$ "
		<< fixed << setprecision(2) << tmp.GetEarnedInterest() << endl;

}
