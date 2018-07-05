#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>

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

unit player;

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
	while (statNum1 < 0 || statNum1 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum1;
	}

	cout << "Which stat will be dexterity? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum2;
	while (statNum2 == statNum1 || statNum2 < 0 || statNum2 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum2;
	}

	cout << "Which stat will be constitution? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum3;
	while (statNum3 == statNum2 || statNum3 == statNum1 || statNum3 < 0 || statNum3 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum3;
	}

	cout << "Which stat will be intelligence? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum4;
	while (statNum4 == statNum3 || statNum4 == statNum2 || statNum4 == statNum1 || statNum4 < 0 || statNum4 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum4;
	}

	cout << "Which stat will be wisdom? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum5;
	while (statNum5 == statNum4 || statNum5 == statNum3 || statNum5 == statNum2 || statNum5 == statNum1 || statNum5 < 0 || statNum5 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum5;
	}

	cout << "Which stat will be charisma? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum6;
	while (statNum6 == statNum5 || statNum6 == statNum4 || statNum6 == statNum3 || statNum6 == statNum2 || statNum6 == statNum1 || statNum6 < 0 || statNum6 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum6;
	}

	player.strength = stats[statNum1];
	player.dexterity = stats[statNum2];
	player.constitution = stats[statNum3];
	player.intelligence = stats[statNum4];
	player.wisdom = stats[statNum5];
	player.charisma = stats[statNum6];

	return;
}

int main()
{
	cout << "Generating a stat array for a lvl 3 character..." << endl;

	rStatsPlayer();

	cout << "Strength:     " << player.strength << endl;
	cout << "Dexterity:    " << player.dexterity << endl;
	cout << "Constitution: " << player.constitution << endl;
	cout << "Intelligence: " << player.intelligence << endl;
	cout << "Wisdom:       " << player.wisdom << endl;
	cout << "Charisma:     " << player.charisma << endl;

	return 0;
}
