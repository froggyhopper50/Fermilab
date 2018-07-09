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
	string armor;
	int AC;
	string weapon;
	int atkDType;
	int atkDNum;
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
		int healing = 0;
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
					int roll;

					if (diceUsed <= diceLeft &&
					    diceUsed >= 0)
					{
						for (int i=1; i<=diceUsed; i++)
						{
						roll = (rand()%(HPdice*100)/100
							+1);
						healing = healing+roll+conMOD;
						cout << roll << endl;
						}
						cout << "Total Healing: "
						     << healing << endl;
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

	void attack()
	{
		int atkdmg = 0;
		int roll;
		for (int i=1; i<=atkDNum; i++)
		{
		roll = (rand()%(atkDType*100)/100+1);
		atkdmg = atkdmg + roll;
		cout << roll << endl;
		}
		atkdmg = atkdmg + strMOD;
		cout << "Total Damage: "
		     << atkdmg << endl;
		cout << "Dealt " << atkdmg << " damage!" << endl;

		return;
	}

	void longRest()
	{
		HPnow = HPmax;
		diceLeft = diceLeft + lvl/2;

		if (diceLeft > lvl)
		{
			diceLeft = lvl;
		}

		cout << "You feel well-rested." << endl;
		cout << "HP: " << HPnow << endl;
		cout << "Hit Dice: " << diceLeft << endl;
		
		return;
	}

	void equip()
	{
		string equipThis;
		cout << "What are you equipping?" << endl;
		cin >> equipThis;
		
		if (equipThis == "chain" && armor != "chain")
		{
			chain.equip();
		}
		else if (equipThis == "chain" && armor == "chain")
		{
			cout << "Already equipped!" << endl;
		}
		else if (equipThis == "greatsword" && weapon != "greatsword")
		{
			greatsword.equip();
		}
		else if (equipThis == "greatsword" && weapon == "greatsword")
		{
			cout << "Already equipped!" << endl;
		}
		else
		{
			cout << "Invalid input!" << endl;
		}
		
		return;
	}
	
	void status()
	{
	cout << "Player: Lvl " << player.lvl << " " 
	     << player.classPlayer << endl;
	cout << "Race: " << player.racePlayer << endl;
	cout << "Hit Points: " << player.HPmax << endl;
	cout << "Hit Dice: " << player.diceLeft << "d" << player.HPdice << endl;
	cout << "Weapon: " << player.weapon << " (" << player.atkDNum <<
		"d" << player.atkDType << ")" << endl;
	cout << "Armor: " << player.armor << endl;
	cout << "Armor Class: " << player.AC << endl;
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
		
		return;
	}
};

unit player;

class armor
{
	public:
	
	int ACmod;
	bool adDex;
	bool isLARM;
	bool isMARM;
	bool isHARM;
	string name;

	void equip()
	{
		if (isLARM == player.useLARM ||
		    isMARM == player.useMARM ||
		    isHARM == player.useHARM)
		{
			player.AC = ACmod;
			if (adDex == true)
			{
				player.AC = player.AC + player.dexMOD;
			}
			cout << "Equipped!" << endl;
			player.armor = name;
		}
		else
		{
			cout << "Cannot equip!" << endl;
		}

		return;
	}
};

class weapon
{
	public:
	
	int dType;
	int dNum;
	bool isSMW;
	bool isSRW;
	bool isMMW;
	bool isMRW;
	string name;

	void equip()
	{
		if (isSMW == player.useSMW ||
		    isSRW == player.useSRW ||
		    isMMW == player.useMMW ||
		    isMRW == player.useMRW)
		{
			player.atkDType = dType;
			player.atkDNum = dNum;
			cout << "Equipped!" << endl;
			player.weapon = name;
		}
		else
		{
			cout << "Cannot equip!" << endl;
		}
		return;
	}
};

armor chain;
armor none;

weapon greatsword;
weapon none;

void setArmors()
{
	chain.ACmod = 16;
	chain.adDex = false;
	chain.isLARM = false;
	chain.isMARM = false;
	chain.isHARM = true;
	chain.name = "chain";
	
	none.ACmod = 0;
	none.adDex = true;
	none.isLARM = true;
	none.isMARM = true;
	none.isHARM = true;
	none.name = "none";
	
	return;
}

void setWeapons()
{
	greatsword.dType = 6;
	greatsword.dNum = 2;
	greatsword.isSMW = false;
	greatsword.isSRW = false;
	greatsword.isMMW = true;
	greatsword.isMRW = false;
	greatsword.name = "greatsword";
	
	none.dType = 0;
	none.dNum = 0;
	none.isSMW = true;
	none.isSRW = true;
	none.isMMW = true;
	none.isMRW = true;
	none.name = "none";
	
	return;
}

int rollStat()
{
	int d6Rolls[3];
	int stat;
	int sum = 0;
	int minRoll;
	
	d6Rolls[0] = (rand()%600)/100+1;
	d6Rolls[1] = (rand()%600)/100+1;
	d6Rolls[2] = (rand()%600)/100+1;
	d6Rolls[3] = (rand()%600)/100+1;

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
	     << "(#0) ACROBATICS" << endl
	     << "(#1) ANIMAL HANDLING" << endl
	     << "(#2) ATHLETICS" << endl
	     << "(#3) HISTORY" << endl
	     << "(#4) INSIGHT" << endl
	     << "(#5) INTIMIDATION" << endl
	     << "(#6) PERCEPTION" << endl
	     << "(#7) SURVIVAL" << endl;
	
	string skilled1 = "no";
	string skilled2 = "no";
	int skill1;
	int skill2;
	
	do
	{
		cout << "Pick one of the above skills. To select "
		     << "a skill, enter the number in parentheses"
		     << " next to the desired skill:"
		     << endl;
		cin >> skill1;
		
		if (skill1 == 0) 
		{
			player.acroP = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 1) 
		{
			player.animP = true; 
			skilled1 = "yes";
		}
		
		else if (skill1 == 2) 
		{
			player.athlP = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 3) 
		{
			player.histP = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 4) 
		{
			player.insiP = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 5) 
		{
			player.intiP = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 6) 
		{
			player.percP = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 7) 
		{
			player.survP = true; 
			skilled1 = "yes";
		}

		else 
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (skilled1 == "no");
	
	do
	{
		cout << "Pick a second skill. To select a skill, "
		     << "enter the number in parentheses next to "
		     << "the desired skill:"
		     << endl;
		cin >> skill2;
		
		if (skill2 == 0 && skill1 != skill2) 
		{
			player.acroP = true; 
			skilled2 = "yes";
		}
		
		else if (skill2 == 1 && skill1 != skill2) 
		{
			player.animP = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 2 && skill1 != skill2) 
		{
			player.athlP = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 3 && skill1 != skill2)
		{
			player.histP = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 4 && skill1 != skill2) 
		{
			player.insiP = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 5 && skill1 != skill2) 
		{
			player.intiP = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 6 && skill1 != skill2) 
		{
			player.percP = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 7 && skill1 != skill2) 
		{
			player.survP = true; 
			skilled2 = "yes";
		}

		else 
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (skilled2 == "no");

	none.equip();
	none.equip();
	
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

void clearSkills()
{
	player.acroP = false;
	player.animP = false;
	player.arcaP = false;
	player.athlP = false;
	player.deceP = false;
	player.histP = false;
	player.insiP = false;
	player.intiP = false;
	player.inveP = false;
	player.mediP = false;
	player.natuP = false;
	player.percP = false;
	player.perfP = false;
	player.persP = false;
	player.reliP = false;
	player.sleiP = false;
	player.steaP = false;
	player.survP = false;
	
	return;
}

void setSkills()
{
	player.acro = player.dexMOD;
	if (player.acroP) 
	{
		player.acro = player.acro + player.proficiency;
	}
	player.anim = player.wisMOD;
	if (player.animP) 
	{
		player.anim = player.anim + player.proficiency;
	}
	player.arca = player.intMOD;
	if (player.arcaP) 
	{
		player.arca = player.arca + player.proficiency;
	}
	player.athl = player.strMOD;
	if (player.athlP) 
	{
		player.athl = player.athl + player.proficiency;
	}
	player.dece = player.chaMOD;
	if (player.deceP) 
	{
		player.dece = player.dece + player.proficiency;
	}
	player.hist = player.intMOD;
	if (player.histP) 
	{
		player.hist = player.hist + player.proficiency;
	}
	player.insi = player.wisMOD;
	if (player.insiP) 
	{
		player.insi = player.insi + player.proficiency;
	}
	player.inti = player.chaMOD;
	if (player.intiP) 
	{
		player.inti = player.inti + player.proficiency;
	}
	player.inve = player.intMOD;
	if (player.inveP) 
	{
		player.inve = player.inve + player.proficiency;
	}
	player.medi = player.wisMOD;
	if (player.mediP) 
	{
		player.medi = player.medi + player.proficiency;
	}
	player.natu = player.intMOD;
	if (player.natuP) 
	{
		player.natu = player.natu + player.proficiency;
	}
	player.perc = player.wisMOD;
	if (player.percP) 
	{
		player.perc = player.perc + player.proficiency;
	}
	player.perf = player.chaMOD;
	if (player.perfP) 
	{
		player.perf = player.perf + player.proficiency;
	}
	player.pers = player.chaMOD;
	if (player.persP) 
	{
		player.pers = player.pers + player.proficiency;
	}
	player.reli = player.intMOD;
	if (player.reliP) 
	{
		player.reli = player.reli + player.proficiency;
	}
	player.slei = player.dexMOD;
	if (player.sleiP) 
	{
		player.slei = player.slei + player.proficiency;
	}
	player.stea = player.dexMOD;
	if (player.steaP) 
	{
		player.stea = player.stea + player.proficiency;
	}
	player.surv = player.wisMOD;
	if (player.survP) 
	{
		player.surv = player.surv + player.proficiency;
	}
	
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

	srand((unsigned)time(NULL));

	string userInput;

	setArmors();
	setWeapons();
	clearSkills();

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
	cout << "Weapon: " << player.weapon << " (" << player.atkDNum <<
		"d" << player.atkDType << ")" << endl;
	cout << "Armor: " << player.armor << endl;
	cout << "Armor Class: " << player.AC << endl;
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

		if (userInput == "attack")
		{
			player.attack();
		}

		if (userInput == "long_rest")
		{
			player.longRest();
		}
		
		if (userInput == "equip")
		{
			player.equip();
		}
		
		if (userInput == "status")
		{
			player.status();
		}
	}
	while (userInput != "exit");

	return 0;
}
