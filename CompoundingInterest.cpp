#include "CompoundingInterest.h"

CompoundingInterest::CompoundingInterest(){
	this->mOriginalPrinciple = 0.0;
	this->mCompound = 12;
	this->mDepositAmount = 0.0;
	this->mInterest = 0.0;
	this->mYears = 0;
}

void CompoundingInterest::SetPrinciple(double principle){
	this->mOriginalPrinciple = principle;
}

void CompoundingInterest::SetCompound(int compound){
	this->mCompound = compound;
}

void CompoundingInterest::SetDepositAmount(double depositAmount){
	this->mDepositAmount = depositAmount;
}

void CompoundingInterest::SetInterest(double interest){
	this->mInterest = interest;
}

void CompoundingInterest::SetYears(int years){
	this->mYears = years;
}

int CompoundingInterest::GetYears() const{
	return this->mYears;
}

double CompoundingInterest::GetEarnedInterest() const{
	return this->mEarnedInterest;
}

double CompoundingInterest::CalculateYearlyInterestWithoutDeposits(int year){

	//converts percentage to decimal
	double interestRate = this->mInterest / 100;

	//Calculates the compounding interest for a given lenght of time
	double compoundingInterest = (1 + (interestRate / this->mCompound));

	//Multiplies the compounding interest by the compounding periods to get the annual compounded interest
	double annualCompoundingInterest = pow(compoundingInterest, this->mCompound * year);


	this->mEarnedInterest = (year == 1 ? (this->mOriginalPrinciple * annualCompoundingInterest) - this->mOriginalPrinciple
		: (this->mOriginalPrinciple * annualCompoundingInterest) - this->mCurrPrinciple);

	//Multiplies the compounded interest by the priciple to get yearly total
	this->mCurrPrinciple = this->mOriginalPrinciple * annualCompoundingInterest;

	return this->mCurrPrinciple;
}

double CompoundingInterest::CalculateYearlyInterestWithDeposits(int year){

	//converts percentage to decimal
	double interestRate = this->mInterest / 100;

	double monthlyInterest;

	double compoundingInterest;

	this->mEarnedInterest = 0.0;

	//Iterate through the compounding periods to calculate the yearly interest
	for (unsigned int i = 0; i < this->mCompound; i++) {

		//If its the first year set the principle to the original principle
		if (year == 1) {
			//Set the current principle to the original principle plus the deposit amount
			this->mCurrPrinciple = this->mOriginalPrinciple + mDepositAmount;

			year = NULL;
		}
		//Otherwise add the deposite amount to the current principle
		else {
			this->mCurrPrinciple += mDepositAmount;
		}

		//Calculate the compounded interest
		compoundingInterest = interestRate / this->mCompound;

		//Get the new priciple value
		monthlyInterest = this->mCurrPrinciple * compoundingInterest;

		this->mEarnedInterest += monthlyInterest;

		this->mCurrPrinciple += monthlyInterest;
	}

	return this->mCurrPrinciple;
}
