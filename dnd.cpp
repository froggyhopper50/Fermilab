#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>

int strHOLD;
int dexHOLD;
int conHOLD;
int intHOLD;
int wisHOLD;
int chaHOLD;

using namespace std;

class unit
{
	public:

	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
};

int rollStat()
{
	int d6Rolls[3];
	int stat;
	int sum = 0;
	int minRoll;
	
	d6Rolls[0] = rand()%6+1;
	d6Rolls[1] = rand()%6+1;
	d6Rolls[2] = rand()%6+1;
	d6Rolls[3] = rand()%6+1;

	for (int i=0; i<4; i++)
	{
		sum = sum + d6Rolls[i];
	}

	minRoll = *min_element(d6Rolls, d6Rolls+4);

	stat = sum - minRoll;

	return stat;
}

void rStatsPlayer()
{
	int stats[5];
	int statNum1, statNum2, statNum3, statNum4, statNum5, statNum6;
	bool goodArray = false;
	string satisfied;

	srand((unsigned)time(NULL));

	do
	{
		for (int i=0; i<6; i++)
		{
			stats[i] = rollStat();
			cout << "(#" << i << ") " << stats[i] << endl;
		}

		cout << "Are you satisfied with this array? (y/n)" << endl;
		cin >> satisfied;

		if (satisfied == "y")
		{
			goodArray = true;
			cout << "Using this array..." << endl;
		}
		
		else if (satisfied == "n")
		{
			goodArray == false;
			cout << "Rolling a new array..." << endl;
		}

		else
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (goodArray == false);

	cout << "Which stat will be strength? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum1;
	strHOLD = stats[statNum1];

	cout << "Which stat will be dexterity? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum2;
	while (statNum2 == statNum1)
	{
		cout << "That stat was already assigned!
		     << "Please choose a different stat: " << endl;
		cin >> statNum2;
	}
	dexHOLD = stats[statNum2];

	cout << "Which stat will be constitution? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum3;
	while (statNum3 == statNum2 || statNum3 == statNum1)
	{
		cout << "That stat was already assigned!
		     << "Please choose a different stat: " << endl;
		cin >> statNum3;
	}
	conHOLD = stats[statNum3];

	cout << "Which stat will be intelligence? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum4;
	while (statNum4 == statNum3 || statNum4 == statNum2 || statNum4 == statNum1)
	{
		cout << "That stat was already assigned!
		     << "Please choose a different stat: " << endl;
		cin >> statNum4;
	}
	intHOLD = stats[statNum4];

	cout << "Which stat will be wisdom? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum5;
	while (statNum5 == statNum4 || statNum5 == statNum3 || statNum5 == statNum2 || statNum5 == statNum1)
	{
		cout << "That stat was already assigned!
		     << "Please choose a different stat: " << endl;
		cin >> statNum5;
	}
	wisHOLD = stats[statNum5];

	cout << "Which stat will be charisma? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum6;
	while (statNum6 == statNum5 || statNum6 == statNum4 || statNum6 == statNum3 || statNum6 == statNum2 || statNum6 == statNum1)
	{
		cout << "That stat was already assigned!
		     << "Please choose a different stat: " << endl;
		cin >> statNum6;
	}
	chaHOLD = stats[statNum6];

	return;
}

int main()
{
	cout << "Generating a stat array for a lvl 3 character..." << endl;

	unit player;
	rStatsPlayer();

	player.strength = strHOLD;
	player.dexterity = dexHOLD;
	player.constitution = conHOLD;
	player.intelligence = intHOLD;
	player.wisdom = wisHOLD;
	player.charisma = chaHOLD;

	cout << "Strength:     " << player.strength << endl;
	cout << "Dexterity:    " << player.dexterity << endl;
	cout << "Constitution: " << player.constitution << endl;
	cout << "Intelligence: " << player.intelligence << endl;
	cout << "Wisdom:       " << player.wisdom << endl;
	cout << "Charisma:     " << player.charisma << endl;

	return 0;
}
