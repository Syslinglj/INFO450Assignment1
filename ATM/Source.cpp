#include <iostream>
using namespace std;

int getAmount();
void getBills(int& one, int& five, int& ten, int& twenty, int& fifty, int& amount);

int main()
{
	int ones = 0 , fives = 0, tens = 0, twenties = 0, fifties = 0;
	int amount = 0;
	char a = '\0';
	do
	{
		int ones = 0, fives = 0, tens = 0, twenties = 0, fifties = 0;
		getBills(ones, fives, tens, twenties, fifties, amount); //calls getBills() for the amount of bills from user request
		if (amount < 1 || amount > 300) // checks to make sure amount is valid
		{
			if (amount == 0) // ends if amount is zero
				break;
			cout << "You have requested too much, or entered a negative value." << endl;
			cout << "Please enter a new value." << endl;
			cout << "Would you like to try again? Y:N" << endl;
			cin >> a;
		}
		else // continues if amount is valid and prints out amount of bills if they are more than 0
		{
			cout << "You wanted to withdraw: " << amount << endl;
			if (fifties > 0)
				cout << "You have received " << fifties << " fifties." << endl;
			if (twenties > 0)
				cout << "You have received " << twenties << " twenties." << endl;
			if (tens > 0)
				cout << "You have received " << tens << " tens." << endl;
			if (fives > 0)
				cout << "You have received " << fives << " fives." << endl;
			if (ones > 0)
				cout << "You have received " << ones << " ones." << endl;

			cout << "Would you like to withdraw more? Y:N" << endl;
			cin >> a;
		}
	} while (a == 'Y' || a == 'y'); 
	cout << "Goodbye!" << endl;
}
// takes amount from getAmount() and counts bills 


void getBills(int& one, int& five, int& ten, int& twenty, int& fifty, int& amount)
{
	amount = getAmount();
	int value = amount;

	while (value >= 50)
	{
		fifty++;
		value -= 50;
	}
	while (value >= 20)
	{
		twenty++;
		value -= 20;
	}
	while (value >= 10)
	{
		ten++;
		value -= 10;
	}
	while (value >= 5)
	{
		five++;
		value -= 5;
	}
	while (value >= 1)
	{
		one++;
		value -= 1;
	}
}

int getAmount()// requests input from user
{
	int value;
	cout << "Please enter a withdrawal amount, or 0 to exit --> ";
	cin >> value;
	return value;
}
