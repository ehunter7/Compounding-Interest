#pragma once
#include <math.h>

class CompoundingInterest{
private:
	double mOriginalPrinciple;
	double mCurrPrinciple;
	int mCompound;
	double mDepositAmount;
	double mInterest;
	double mEarnedInterest;
	int mYears;

public:

	CompoundingInterest();

	void SetPrinciple(double  principle);
	void SetCompound(int compound);
	void SetDepositAmount(double depositAmount);
	void SetInterest(double interest);
	void SetYears(int years);

	int GetYears() const;
	double GetEarnedInterest() const;

	double CalculateYearlyInterestWithoutDeposits(int year);
	double CalculateYearlyInterestWithDeposits(int year);

};

