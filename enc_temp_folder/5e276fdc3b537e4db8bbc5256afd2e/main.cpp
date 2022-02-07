#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

#include "CompoundingInterest.h"

using namespace std;

//Function declarations
void DisplayInputHeader();
void GetUserInput(CompoundingInterest& t_tmp);
void DisplayHeader(string t_condition);
void displayCalculations(CompoundingInterest& t_tmp, int t_index, string t_condition);

int main() {
	
	//Declares to object
	CompoundingInterest* InterestCalculations;

	//Set the 
	char proceed;

	do {

		//Allocates new memory for object
		InterestCalculations = new CompoundingInterest;

		//clears the console
		system("clear");

		//Displays the user input header
		DisplayInputHeader();

		//Prompts and gathers users input
		GetUserInput(*InterestCalculations);
		
		//New line for readability
		cout << endl;

		//Hold until the user presses a button to continue
		system("pause");

		//New line for readability
		cout << endl;

		//Displays the reports header
		DisplayHeader("without");

		//Loops through the number of years the user entered and get the amount based on that year.
		for (unsigned int i = 1; i <= InterestCalculations->GetYears(); i++) {
			displayCalculations(*InterestCalculations, i, "without");
		}

		//New line for readability 
		cout << endl;

		//Displays the reports header
		DisplayHeader("with");

		//Loops through the number of years the user entered and get the amount based on that year.
		for (unsigned int i = 1; i <= InterestCalculations->GetYears(); i++) {
			displayCalculations(*InterestCalculations, i, "with");
		}

		//Prompts the user to enter their choice to retry or exit
		cout << "Enter 'y' to continue or 'q' to quite: ";
		cin >> proceed;

		//Clears the stream to allow user to enter more information
		cin.ignore(1000, '\n');

		//Deletes the allocated memory for reuse
		delete InterestCalculations;

		//If user enter y to proceed 
	} while (tolower(proceed) == 'y');

	return 0;
}

void DisplayInputHeader() {

	cout << setfill('~') << setw(31) << " " << endl;
	cout << setfill('~') << setw(10) << " ";
	cout << "Data Input" << " ";
	cout << setfill('~') << setw(10) << " " << endl;
}

void GetUserInput(CompoundingInterest& t_tmp){

	//Shuttle used to convert user input
	string shuttle;

	cout << "Initial Investment Amount: ";
	getline(cin, shuttle);

	//If user enters a dollar sign remove it
	shuttle.erase(remove(shuttle.begin(), shuttle.end(), '$'), shuttle.end());

	//converts the string to a double and sets it in the object
	t_tmp.SetPrinciple(stod(shuttle));


	cout << "Monthly Deposits: ";
	getline(cin, shuttle);

	//If user enters a dollar sign remove it
	shuttle.erase(remove(shuttle.begin(), shuttle.end(), '$'), shuttle.end());

	//converts the string to a double and sets it in the object
	t_tmp.SetDepositAmount(stod(shuttle));

	cout << "Annual Interest: ";
	getline(cin, shuttle);

	//If user enters a percentage sign remove it
	shuttle.erase(remove(shuttle.begin(), shuttle.end(), '%'), shuttle.end());

	//converts the string to a double and sets it in the object
	t_tmp.SetInterest(stod(shuttle));

	cout << "Number of years: ";
	cin >> shuttle;

	//converts the string to an int and sets it in the object
	t_tmp.SetYears(stoi(shuttle));

	
}

void DisplayHeader(string t_condition) {

	if (t_condition == "with") {

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

void displayCalculations(CompoundingInterest& t_tmp, int t_index, string t_condition) {

	double shuttle = (t_condition == "with" ? t_tmp.CalculateYearlyInterestWithDeposits(t_index) :
		t_tmp.CalculateYearlyInterestWithoutDeposits(t_index));

	string tmpstr = to_string(shuttle);

	cout << setw(5) << setfill(' ') << t_index << setw(11) << setfill(' ') << "$ "
		<< fixed << setprecision(2) << shuttle;
	 cout << setw(25 - tmpstr.length()) << right <<  "$ "
		<< fixed << setprecision(2) << t_tmp.GetEarnedInterest() << endl;
}
