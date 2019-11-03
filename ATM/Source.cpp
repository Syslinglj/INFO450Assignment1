#include <iostream>
using namespace std;

int getAmount();
void getBills(int& one, int& five, int& ten, int& twenty, int& fifty, int& amount);

int main()
{
	int ones, fives, tens, twenties, fifties;
	int amount = 0;
	char a = 'Y';
	while (a == 'Y' || a == 'y')
	{
		int ones = 0, fives = 0, tens = 0, twenties = 0, fifties = 0;
		getBills(ones, fives, tens, twenties, fifties, amount); 
		if (amount < 1 || amount > 300)
		{
			cout << "You have requested too much, or entered a negative value." << endl;
			cout << "Please enter a new value." << endl;
		}
		else 
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

			//cout << "Your change will be " << fifties << " Fifties, " << twenties << " Twenties, " << tens << " Tens, " << fives << " Fives, " << ones << " Ones." << endl;
			cout << "Would you like to withdraw more? Y:N" << endl;
			cin >> a;
		}
	}
	cout << "Goodbye!" << endl;
}

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

int getAmount()
{
	int value;
	cout << "Please enter a withdrawal amount --> ";
	cin >> value;
	return value;
}
