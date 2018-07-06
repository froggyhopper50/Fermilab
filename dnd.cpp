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

	int lvl;
	string racePlayer;
	string classPlayer;
	int proficiency;
	int passivePerception;

	int HPinit;
	int HPgain;
	int HPmax;
	int HPnow;
	int HPdice;
	int diceLeft;
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;

	int strMOD;
	int dexMOD;
	int conMOD;
	int intMOD;
	int wisMOD;
	int chaMOD;

	int strST;
	int dexST;
	int conST;
	int intST;
	int wisST;
	int chaST;

	int acro;
	bool acroP;
	int anim;
	bool animP;
	int arca;
	bool arcaP;
	int athl;
	bool athlP;
	int dece;
	bool deceP;
	int hist;
	bool histP;
	int insi;
	bool insiP;
	int inti;
	bool intiP;
	int inve;
	bool inveP;
	int medi;
	bool mediP;
	int natu;
	bool natuP;
	int perc;
	bool percP;
	int perf;
	bool perfP;
	int pers;
	bool persP;
	int reli;
	bool reliP;
	int slei;
	bool sleiP;
	int stea;
	bool steaP;
	int surv;
	bool survP;

	bool useLARM;
	bool useMARM;
	bool useHARM;
	bool useSHIELD;
	bool useSMW;
	bool useSRW;
	bool useMMW;
	bool useMRW;

	void shortRest()
	{
		string heal = "null";
		int diceUsed;
		int healing;
		bool healed = false;
		
		if (HPnow < HPmax && diceLeft > 0)
		{
		do
		{
			cout << "Expend hit dice to heal? (y/n)" << endl;
			cin >> heal;

			if (heal == "y")
			{
				do
				{
					cout << "How many hit dice will "
					     << "be used?" << endl;
					cin >> diceUsed;

					if (diceUsed <= diceLeft &&
					    diceUsed >= 0)
					{
						healing = diceUsed * (
							  rand()%HPdice
							  + 1);
						HPnow = HPnow + healing;
						if (HPnow > HPmax)
						{
							HPnow = HPmax;
						}
						cout << "Healed for "
						     << healing << endl;
						cout << "HP: "
						     << HPnow << endl;
						diceLeft =
						diceLeft - diceUsed;
						cout << diceLeft
						     << " hit dice remaining"
						     << endl;

						healed = true;
					}
					
					else
					{
						cout << "Invalid input!" 
						     << endl;
					}
				}
				while (healed == false);
				
			}

			else if (heal == "n")
			{
				cout << "No hit dice will be used to heal."
				     << endl;
			}

			else
			{
				cout << "Invalid input!" << endl;
				heal = "null";
			}
		}
		while (heal == "null");
		}

		else
		{
			if (HPnow == HPmax)
			{
				cout << "Already at max health!" << endl;
			}

			if (diceLeft == 0)
			{
				cout << "No more hit dice left!" << endl;
			}
		}
		return;
	}

	void damage(int dmg)
	{
		cout << "You took " << dmg << " points of damage!" << endl;
		HPnow = HPnow - dmg;
		if (HPnow < 0)
		{
			HPnow = 0;
		}
		cout << "HP: " << HPnow << endl;

		return;
	}
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
	while (statNum1 < 0 ||
	       statNum1 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum1;
	}

	cout << "Which stat will be dexterity? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum2;
	while (statNum2 == statNum1 || 
	       statNum2 < 0 || 
	       statNum2 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum2;
	}

	cout << "Which stat will be constitution? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum3;
	while (statNum3 == statNum2 || 
	       statNum3 == statNum1 || 
	       statNum3 < 0 || 
	       statNum3 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum3;
	}

	cout << "Which stat will be intelligence? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum4;
	while (statNum4 == statNum3 || 
	       statNum4 == statNum2 || 
	       statNum4 == statNum1 || 
	       statNum4 < 0 || 
	       statNum4 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum4;
	}

	cout << "Which stat will be wisdom? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum5;
	while (statNum5 == statNum4 || 
	       statNum5 == statNum3 || 
	       statNum5 == statNum2 || 
	       statNum5 == statNum1 || 
	       statNum5 < 0 || 
	       statNum5 > 5)
	{
		cout << "Invalid input! Please try again:" << endl;
		cin >> statNum5;
	}

	cout << "Which stat will be charisma? "
	     << "(Enter the number in parentheses next to the stat "
	     << "which you desire)" << endl;
	cin >> statNum6;
	while (statNum6 == statNum5 || 
	       statNum6 == statNum4 || 
	       statNum6 == statNum3 || 
	       statNum6 == statNum2 || 
	       statNum6 == statNum1 || 
	       statNum6 < 0 || 
	       statNum6 > 5)
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

void raceBonuses()
{
	string race = "none";

	do
	{
		cout << "Please enter the race of your character." << endl
		     << "Use a _ in the place of any spaces." << endl
		     << "For a list of races, type list:" << endl;
		cin >> race;

		if (race == "list")
		{
			cout << "PLAYABLE RACES " << "STR " << "DEX "
			     << "CON " << "INT " << "WIS " << "CHA" << endl;
			cout << "HUMAN          " << " +1 " << " +1 "
			     << " +1 " << " +1 " << " +1 " << " +1" << endl;
			cout << "MOUNTAIN_DWARF " << " +2 " << "--- "
			     << " +2 " << "--- " << "--- " << "---" << endl;
			cout << "WOOD_ELF       " << "--- " << " +2 "
			     << "--- " << "--- " << " +1 " << "---" << endl;
			cout << "TIEFLING       " << "--- " << "--- "
			     << "--- " << " +1 " << "--- " << " +2" << endl;
			cout << "STOUT_HALFLING " << "--- " << " +2 "
			     << " +1 " << "--- " << "--- " << "---" << endl;
			cout << "ORC            " << " +2 " << "--- "
			     << " +1 " << " -2 " << "--- " << "---" << endl;
			cout << "SAVAGE_GNOLL   " << " +2 " << "--- "
			     << "--- " << "--- " << " +1 " << "---" << endl;
			cout << "DRAGONBORN     " << " +2 " << "--- "
			     << "--- " << "--- " << "--- " << " +1" << endl;
			race = "none";
		}

		else if (race == "human" || 
			 race == "HUMAN")
		{
			player.racePlayer = "Human";
			player.strength++;
			player.dexterity++;
			player.constitution++;
			player.intelligence++;
			player.wisdom++;
			player.charisma++;
		}

		else if (race == "mountain_dwarf" || 
			 race == "MOUNTAIN_DWARF")
		{
			player.racePlayer = "Mountain Dwarf";
			player.strength = player.strength + 2;
			player.constitution = player.constitution + 2;
		}

		else if (race == "wood_elf" || 
			 race == "WOOD_ELF")
		{
			player.racePlayer = "Wood Elf";
			player.dexterity = player.dexterity + 2;
			player.wisdom++;
		}

		else if (race == "tiefling" || 
			 race == "TIEFLING")
		{
			player.racePlayer = "Tiefling";
			player.intelligence++;
			player.charisma = player.charisma + 2;
		}

		else if (race == "stout_halfling" || 
			 race == "STOUT_HALFLING")
		{
			player.racePlayer = "Stout Halfling";
			player.dexterity = player.dexterity + 2;
			player.constitution++;
		}

		else if (race == "orc" || 
			 race == "ORC")
		{
			player.racePlayer = "Orc";
			player.strength = player.strength + 2;
			player.constitution++;
			player.intelligence = player.intelligence - 2;
		}

		else if (race == "savage_gnoll" || 
			 race == "SAVAGE_GNOLL")
		{
			player.racePlayer = "Savage Gnoll";
			player.strength = player.strength + 2;
			player.wisdom++;
		}

		else if (race == "dragonborn" || 
			 race == "DRAGONBORN")
		{
			player.racePlayer = "Dragonborn";
			player.strength = player.strength + 2;
			player.charisma++;
		}

		else
		{
			cout << "Invalid input! Make sure to choose "
			     << "one of the listed races." << endl;
			race = "none";
		}
	}
	while (race == "none");

	return;
}

void setClass()
{
	string classType = "none";

	do
	{
		cout << "Please enter the class of your character." << endl
		     << "For a list of classes, type list:" << endl;
		cin >> classType;

		if (classType == "list")
		{
			cout << "PLAYABLE CLASSES" << endl;
			cout << "FIGHTER" << endl;
			
			cout << "For more information on a given class, "
			     << "type info_ followed by the class name." << endl
			     << "For example, for more information on "
			     << "the fighter class, enter:" << endl
			     << "info_fighter" << endl;

			classType = "none";
		}

		else if (classType == "fighter" || 
			 classType == "FIGHTER")
		{
			player.classPlayer = "Fighter";
		}

		else if (classType == "info_fighter" || 
			 classType == "info_FIGHTER")
		{
			cout << "A WELL ROUNDED HERO INTIMATELY FAMILIAR" <<
			endl << "WITH COMBAT. MASTER OF ALL TYPES OF    " <<
			endl << "WEAPONS AND ARMOR. EXTREMELY VERSATILE." <<
				endl;

			classType = "none";
		}

		else
		{
			cout << "Invalid input! Make sure to choose "
			     << "one of the listed classes." << endl;
			classType = "none";
		}
	}
	while (classType == "none");

	return;
}

void setFighter()
{
	player.HPinit = 10 + player.conMOD;
	player.HPgain = 6 + player.conMOD;
	player.HPdice = 10;
	player.diceLeft = player.lvl;

	player.useLARM = true;
	player.useMARM = true;
	player.useHARM = true;
	player.useSHIELD = true;

	player.useSMW = true;
	player.useSRW = true;
	player.useMMW = true;
	player.useMRW = true;

	player.strST = player.strMOD + player.proficiency;
	player.dexST = player.dexMOD;
	player.conST = player.conMOD + player.proficiency;
	player.intST = player.intMOD;
	player.wisST = player.wisMOD;
	player.chaST = player.chaMOD;	
	
	cout << "SKILLS" << endl
	     << "(#0) ACROBATICS"
	
	return;
}

void setHPmax()
{
	player.HPmax = player.HPinit + (player.HPgain * (player.lvl - 1));

	return;
}

void setModifiers()
{
	player.strMOD = (player.strength / 2) - 5;
	player.dexMOD = (player.dexterity / 2) - 5;
	player.conMOD = (player.constitution / 2) - 5;
	player.intMOD = (player.intelligence / 2) - 5;
	player.wisMOD = (player.wisdom / 2) - 5;
	player.chaMOD = (player.charisma / 2) - 5;
	
	return;
}

void setSkills()
{
	player.acro = player.dexMOD;
	if (player.acroP) {player.acro = player.acro + player.proficiency}
	player.anim = player.wisMOD;
	if (player.animP) {player.anim = player.anim + player.proficiency}
	player.arca = player.intMOD;
	if (player.arcaP) {player.arca = player.arca + player.proficiency}
	player.athl = player.strMOD;
	if (player.athlP) {player.athl = player.athl + player.proficiency}
	player.dece = player.chaMOD;
	if (player.deceP) {player.dece = player.dece + player.proficiency}
	player.hist = player.intMOD;
	if (player.histP) {player.hist = player.hist + player.proficiency}
	player.insi = player.wisMOD;
	if (player.insiP) {player.insi = player.insi + player.proficiency}
	player.inti = player.chaMOD;
	if (player.intiP) {player.inti = player.inti + player.proficiency}
	player.inve = player.intMOD;
	if (player.inveP) {player.inve = player.inve + player.proficiency}
	player.medi = player.wisMOD;
	if (player.mediP) {player.medi = player.medi + player.proficiency}
	player.natu = player.intMOD;
	if (player.natuP) {player.natu = player.natu + player.proficiency}
	player.perc = player.wisMOD;
	if (player.percP) {player.perc = player.perc + player.proficiency}
	player.perf = player.chaMOD;
	if (player.perfP) {player.perf = player.perf + player.proficiency}
	player.pers = player.chaMOD;
	if (player.persP) {player.pers = player.pers + player.proficiency}
	player.reli = player.intMOD;
	if (player.reliP) {player.reli = player.reli + player.proficiency}
	player.slei = player.dexMOD;
	if (player.sleiP) {player.slei = player.slei + player.proficiency}
	player.stea = player.dexMOD;
	if (player.steaP) {player.stea = player.stea + player.proficiency}
	player.surv = player.wisMOD;
	if (player.survP) {player.surv = player.surv + player.proficiency}
	
	return;
}

void setProf()
{
	player.proficiency = (player.lvl + 7) / 4;
	
	return;
}

void setPassivePerception()
{
	player.passivePerception = 10 + player.proficiency + player.wisMOD;
	
	return;
}


int main()
{
	cout << "Generating a stat array for a lvl 3 character..." << endl;

	string userInput;

	player.lvl = 3;
	rStatsPlayer();
	raceBonuses();
	setModifiers();
	setProf();
	setClass();

	if (player.classPlayer == "Fighter")
	{
		setFighter();
	}

	setHPmax();
	setSkills();
	player.HPnow = player.HPmax;
	setPassivePerception();

	cout << "Player: Lvl " << player.lvl << " " 
	     << player.classPlayer << endl;
	cout << "Race: " << player.racePlayer << endl;
	cout << "Hit Points: " << player.HPmax << endl;
	cout << "Hit Dice: " << player.diceLeft << "d" << player.HPdice << endl;
	cout << "Proficiency Bonus: " << player.proficiency << endl;
	cout << "Strength:     " << player.strength << 
		" (" << player.strMOD << ") " << "ST " << player.strST << endl;
	cout << "Dexterity:    " << player.dexterity << 
		" (" << player.dexMOD << ") " << "ST " << player.dexST << endl;
	cout << "Constitution: " << player.constitution <<
		" (" << player.conMOD << ") " << "ST " << player.conST << endl;
	cout << "Intelligence: " << player.intelligence <<
		" (" << player.intMOD << ") " << "ST " << player.intST << endl;
	cout << "Wisdom:       " << player.wisdom << 
		" (" << player.wisMOD << ") " << "ST " << player.wisST << endl;
	cout << "Charisma:     " << player.charisma <<
		" (" << player.chaMOD << ") " << "ST " << player.chaST << endl;
	cout << "Passive Perception: " << player.passivePerception << endl;

	srand((unsigned)time(NULL));

	do
	{
		cin >> userInput;
		if (userInput == "short_rest")
		{
			player.shortRest();
		}

		if (userInput == "damage")
		{
			player.damage(5);
		}
	}
	while (userInput != "exit");

	return 0;
}

