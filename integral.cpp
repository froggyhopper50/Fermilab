#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//This program uses a Toy Monte Carlo to integrate any continuous function,
//returning a result typically within a thousandth of the actual value. In using
//a Toy Monte Carlo, this program is able to integrate functions that cannot
//normally be integrated by hand. Declare the function you would like to
//integrate in terms of z within the double f() macro below according to the
//following format:
//
//double f(double z)
//{
//	double output;
//	output = [insert function here];
//	return output;
//}
//
//The user will define the bounds over which the function is to be integrated
//while the program is running.
//
//CODED BY JAMES KENNEDY

//Defines the function to be integrated

double f(double z)
{
	double output;
	output = sin(exp(z));
	return output;
}

//Determines the function maximum

double fMaximum(double xLBound, double xUBound)
{
	double fMax = 0.;

	for (int j=0; j<1000000; j++)
	{
		double a;

		a = (rand()%1000001)/1000000.*(xUBound - xLBound) + xLBound;

		if (f(a) > fMax)
		{
			fMax = f(a);
		}
	}

	return fMax;
}

//Determines the function minimum

double fMinimum(double xLBound, double xUBound)
{
	double fMin = 0.;

	for (int j=0; j<1000000; j++)
	{
		double a;

		a = (rand()%1000001)/1000000.*(xUBound - xLBound) + xLBound;

		if (f(a) < fMin)
		{
			fMin = f(a);
		}
	}

	return fMin;
}

//Integrates that part of the function which is above the x axis

double integrateAbove(double xLBound, double xUBound)
{
	srand((unsigned)time(NULL));

	double underCurve = 0.;
	double totalPts = 0.;
	double posIntegral;

	double fMax = 0.;

	fMax = fMaximum(xLBound, xUBound);

	cout << "The function max is " << fMax << endl;

	for (int i=0; i<100000000; i++)
	{
		double x;
		double y;

		x = (rand()%1000001)/1000000.*(xUBound - xLBound) + xLBound;
		y = (rand()%1000001)/1000000.*fMax;

		if (y <= f(x))
		{
			if (y >= 0)
			{
				underCurve++;
			}
		}

		totalPts++;
	}

	posIntegral = (underCurve/totalPts)*(xUBound-xLBound)*fMax;
	
	return posIntegral;
}

//Integrates that part of the function which is below the x axis

double integrateBelow(double xLBound, double xUBound)
{
	srand((unsigned)time(NULL));

	double underCurve = 0.;
	double totalPts = 0.;
	double negIntegral;

	double fMin = 0.;

	fMin = fMinimum(xLBound, xUBound);

	cout << "The function min is " << fMin << endl;

	for (int i=0; i<100000000; i++)
	{
		double x;
		double y;

		x = (rand()%1000001)/1000000.*(xUBound - xLBound) + xLBound;
		y = (rand()%1000001)/1000000.*fMin;

		if (y >= f(x))
		{
			if (y <= 0)
			{
				underCurve++;
			}
		}

		totalPts++;
	}

	negIntegral = (underCurve/totalPts)*(xUBound - xLBound)*fMin;

	return negIntegral;
}

//Calculates the total integral

double integrate()
{
	double posInt;
	double negInt;
	double totalInt;
	double xUB, xLB;

	cout << "Please enter the lower x bound:" << endl;
	cin >> xLB;
	cout << "Please enter the upper x bound:" << endl;
	cin >> xUB;

	posInt = integrateAbove(xLB, xUB);
	negInt = integrateBelow(xLB, xUB);

	totalInt = posInt + negInt;

	return totalInt;
}

//Returns the total integral to the user

int main()
{
	double integral;

	integral = integrate();

	cout << "The integral of the function is " << integral << endl;

	return 0;
}
