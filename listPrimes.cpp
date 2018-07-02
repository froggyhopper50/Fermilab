#include <iostream>
#include <cmath>

using namespace std;

//Tests if given integer is prime

bool isPrime(int x)
{
	for (int i=2; i<=x; i++)
	{
		if (x%i == 0 && i != x)
		{
			return false;
		}
		else if (i == x)
		{
			return true;
		}
	}
}

//Returns list of primes, number of primes, and sum of primes

int main()
{
	int primeThru;
	int totalNum = 0;
	int sum = 0;

	cout << "Listing all prime numbers through: " << endl;
	cin >> primeThru;

	for (int j=2; j<=primeThru; j++)
	{
		if (isPrime(j))
		{
			cout << j << " ";
			totalNum++;
			sum = sum + j;
		}
	}

	cout << "\nTotal number of primes: " << totalNum << endl;
	cout << "Sum: " << sum << endl;

	return 0;
}
