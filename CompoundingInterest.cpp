#include "CompoundingInterest.h"

CompoundingInterest::CompoundingInterest(){
	this->m_OriginalPrinciple = 0.0;
	//sets the Compound periods to monthy
	this->m_Compound = 12;
	this->m_DepositAmount = 0.0;
	this->m_Interest = 0.0;
	this->m_Years = 0;
}

void CompoundingInterest::SetPrinciple(double t_principle){
	this->m_OriginalPrinciple = t_principle;
}

void CompoundingInterest::SetCompound(int t_compound){
	this->m_Compound = t_compound;
}

void CompoundingInterest::SetDepositAmount(double t_depositAmount){
	this->m_DepositAmount = t_depositAmount;
}

void CompoundingInterest::SetInterest(double t_interest){
	this->m_Interest = t_interest;
}

void CompoundingInterest::SetYears(int t_years){
	this->m_Years = t_years;
}

int CompoundingInterest::GetYears() const{
	return this->m_Years;
}

double CompoundingInterest::GetEarnedInterest() const{
	return this->m_EarnedInterest;
}

double CompoundingInterest::CalculateYearlyInterestWithoutDeposits(int t_year){

	//converts percentage to decimal
	double interestRate = this->m_Interest / 100;

	//Calculates the compounding interest for a given lenght of time
	double compoundingInterest = (1 + (interestRate / this->m_Compound));

	//Multiplies the compounding interest by the compounding periods to get the annual compounded interest
	double annualCompoundingInterest = pow(compoundingInterest, this->m_Compound * t_year);

	//Calculates the earned interest for a given year
	this->m_EarnedInterest = (t_year == 1 ? (this->m_OriginalPrinciple * annualCompoundingInterest) - this->m_OriginalPrinciple
		: (this->m_OriginalPrinciple * annualCompoundingInterest) - this->m_CurrPrinciple);

	//Multiplies the compounded interest by the priciple to get yearly total
	this->m_CurrPrinciple = this->m_OriginalPrinciple * annualCompoundingInterest;

	return this->m_CurrPrinciple;
}

double CompoundingInterest::CalculateYearlyInterestWithDeposits(int t_year){

	//converts percentage to decimal
	double interestRate = this->m_Interest / 100;

	double monthlyInterest;

	double compoundingInterest;
	
	//Resets the earned interest to 0
	this->m_EarnedInterest = 0.0;

	//Iterate through the compounding periods to calculate the yearly interest
	for (unsigned int i = 0; i < this->m_Compound; i++) {

		//If its the first year set the principle to the original principle
		if (t_year == 1) {
			//Set the current principle to the original principle plus the deposit amount
			this->m_CurrPrinciple = this->m_OriginalPrinciple + m_DepositAmount;

			t_year = NULL;
		}
		//Otherwise add the deposite amount to the current principle
		else {
			this->m_CurrPrinciple += m_DepositAmount;
		}

		//Calculate the compounded interest
		compoundingInterest = interestRate / this->m_Compound;

		//Get the new priciple value
		monthlyInterest = this->m_CurrPrinciple * compoundingInterest;

		//Combine each months earned interest to get yearly earned interest
		this->m_EarnedInterest += monthlyInterest;

		this->m_CurrPrinciple += monthlyInterest;
	}

	return this->m_CurrPrinciple;
}
