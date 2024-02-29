// MP1- Jim's Dount Shop | Jaydin Rethmel | February 24, 2024
// Description- This program is a working calculator for cost and change due for Jim's Dount Shop.
// This program takes in 4 inputs including regular dounts, fancy dounts, apple fritters,
// as well as how much the customer pays. it will calculate the result of the code 

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Declaring taxrate which is a known constant
const double TAXRATE =  0.075;

int main() {

	// Initalizing the user inputs
	int    userRegularDounts  = 0;
	int    userFancyDounts    = 0;
	int    userAppleFritters  = 0;
	double userCustomerPays   = 0;

	// Initalizing the calculations varibles
	int   dozenRegular  = 0;
	int   dozenFancy    = 0;
	double customerOwes = 0;
	double totalRegular = 0;
	double totalFancy   = 0;
	double totalApple   = 0;

	// cout statements to ask which amount 
	// of dounts is being purchases
	cout << "Number of regular dounts ordered: ";
	cin  >> userRegularDounts;
	cout << "Number of fancy dounts ordered: ";
	cin  >> userFancyDounts;
	cout << "Number of apple fritters ordered: ";
	cin  >> userAppleFritters;
	cout << setprecision(2) << fixed;
	// the calculations to determine the amount it will
	// cost for the user's order

		// finding the amount of dozens that have been purchased

		dozenRegular      = userRegularDounts / 12;
		dozenFancy        = userFancyDounts   / 12;
		userRegularDounts = userRegularDounts % 12;
		userFancyDounts   = userFancyDounts   % 12;

		// calculations done to find the total cost

		totalRegular = (dozenRegular * 7.99) + (userRegularDounts * 0.75);
		totalFancy   = (dozenFancy * 8.49) + (userFancyDounts * .85);
		totalApple   = userAppleFritters * 1.50;

		customerOwes = (totalRegular + totalFancy + totalApple) * (1 + TAXRATE);
		

	// cout and cin statements to show the amount the customer owes
	// and to identify how much payed by the customer

	if (customerOwes < 0 || totalRegular < 0 || totalFancy < 0 || totalApple < 0) {
		cout << "False Input!";
		return 0;
	}
	cout << "Customer owes $" << customerOwes << "\n";
	cout << "Customer pays $";
	cin  >> userCustomerPays;
	if (userCustomerPays < customerOwes) {
		cout << "User does not have sufficent funds.";
		return 0;
	}

	// calculations to identify how much change is due as well
	// as find the exact change that needs to be returned
	
		   userCustomerPays = userCustomerPays - customerOwes;
	double customerStatic   = userCustomerPays;
		   userCustomerPays = userCustomerPays * 100;
		   userCustomerPays = round(userCustomerPays);

	// initalizing the varibles for the different change coins

	int Dollars  = 0;
	int Quarters = 0;
	int Dimes    = 0;
	int Nickels  = 0;
	int Pennies  = 0;

	// using the converted user customer pays varible we can figure out
	// other exact coins to hand back to the customer

	Dollars			 = (userCustomerPays / 100);
	userCustomerPays = userCustomerPays - (Dollars * 100);

	Quarters		 = userCustomerPays / 25;
	userCustomerPays = userCustomerPays - (Quarters * 25);

	Dimes			 = userCustomerPays / 10;
	userCustomerPays = userCustomerPays - ( Dimes * 10);

	Nickels			 = userCustomerPays / 5;
	userCustomerPays = userCustomerPays - ( Nickels * 5);

	Pennies		     = userCustomerPays;

	// cout if statements to print out what exact coin are due or if nothing is due as well as 
	// when to print certain periods and commas at approprate times

	if (Dollars >= 1 || Quarters >= 1 || Dimes >= 1 || Nickels >= 1 || Pennies >= 1) {
		cout << "Changed owed is $" << customerStatic << " - ";

		if (Dollars > 1) {
			cout << Dollars << " Dollars";
		}
		else if (Dollars == 1) {
			cout << Dollars << " Dollar";
		}
		if (Dollars >= 1) {
			if (Quarters >= 1 || Dimes >= 1 || Nickels >= 1 || Pennies >= 1) {
				cout << ", ";
			}
			else if (Quarters == 0 && Dimes == 0 && Nickels == 0 && Pennies == 0) {
				cout << ".";
			}
		}
		if (Quarters > 1) {
			cout << Quarters << " Quarters";
		}
		else if (Quarters == 1) {
			cout << Quarters << " Quarter";
		}
		if (Quarters >= 1) {
			if (Dimes >= 1 || Nickels >= 1 || Pennies >= 1) {
				cout << ", ";
			}
			else if (Dimes == 0 && Nickels == 0 && Pennies == 0) {
				cout << ".";
			}
		}
		if (Dimes > 1) {
			cout << Dimes << " Dimes";
		}
		else if (Dimes == 1) {
			cout << Dimes << " Dime";
		}
		if (Dimes >= 1) {
			if (Nickels >= 1 || Pennies >= 1) {
				cout << ", ";
			}
			else if (Nickels == 0 && Pennies == 0) {
				cout << ".";
			}
		}
		if (Nickels > 1) {
			cout << Nickels << " Nickels";
		}
		else if (Nickels == 1) {
			cout << Nickels << " Nickel";
		}
		if (Nickels >= 1) {
			if (Pennies >= 1) {
				cout << ", ";
			}
			else if ( Pennies == 0) {
				cout << ".";
			}
		}
		if (Pennies > 1) {
			cout << Pennies << " Pennies.";
		}
		else if (Pennies == 1) {
			cout << Pennies << " Penny.";
		}

	}

	// else statement to output excat pay
	else {
		cout << "Excat payment recieved - no changed owed.";
	}

	cout << "\n";
	return 0;

}