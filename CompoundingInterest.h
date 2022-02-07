#pragma once
#include <math.h>

class CompoundingInterest{
private:

	//Member attributes
	double m_OriginalPrinciple;
	double m_CurrPrinciple;
	int m_Compound;
	double m_DepositAmount;
	double m_Interest;
	double m_EarnedInterest;
	int m_Years;

public:

	//Default constructors
	CompoundingInterest();

	//Modifiers

	// ################################################################
	// @par Name
	// SetPrinciple
	// @purpose
	// Sets the member attribute m_OriginalPrinciple
	// @param [in]:
	// type double as the principle
	// @return
	// void
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	void SetPrinciple(double  t_principle);

	// ################################################################
	// @par Name
	// SetCompound
	// @purpose
	// Sets the member attribute m_Compound
	// @param [in]:
	// type int as the compound
	// @return
	// void	
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	void SetCompound(int t_compound);

	// ################################################################
	// @par Name
	// SetDepositAmount
	// @purpose
	// Sets the member attribute m_DespositAmount
	// @param [in]:
	// Type double as the deposited amount
	// @return
	// void
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	void SetDepositAmount(double t_depositAmount);

	// ################################################################
	// @par Name
	// SetInterest
	// @purpose
	// Sets the member attribute m_Interest
	// @param [in]:
	// type double as the interest amount
	// @return
	// void
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	void SetInterest(double t_interest);

	// ################################################################
	// @par Name
	// SetYears
	// @purpose
	// Sets the member attribute m_Years
	// @param [in]:
	// type int as the years to report
	// @return
	// void
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	void SetYears(int t_years);

	// ################################################################
	// @par Name
	// CalculateYearlyInterestWithoutDeposits
	// @purpose
	// Calculates the yearly amounts with monthly compounding interest without an additional deposits
	// @param [in]:
	// type int as the current year to calculate
	// @return
	// type double as the end of year amount
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	double CalculateYearlyInterestWithoutDeposits(int t_year);

	// ################################################################
	// @par Name
	// CalculateYearlyInterestWithDeposits
	// @purpose
	// Calculates the yearly amounts with monthly compounding interest with additional deposits
	// @param [in]:
	// type int as the current year to calculate
	// @return
	// type double as the end of year amount
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	double CalculateYearlyInterestWithDeposits(int t_year);

	//Accessors

	// ################################################################
	// @par Name
	// GetYears
	// @purpose
	// gets the amount of years entered by user to be used when iterating through years
	// @param [in]:
	// none
	// @return
	// type int os the years entered by user
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	int GetYears() const;

	// ################################################################
	// @par Name
	// GetEarnedInterest
	// @purpose
	// Gets the total earned interest for the year
	// @param [in]:
	// none
	// @return
	// type double as the
	// @par References
	// none
	// @par Notes
	// none
	// ################################################################
	double GetEarnedInterest() const;
};

