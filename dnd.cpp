//WORK IN PROGRESS D&D CHARACTER CREATOR
//REPLACE #include BELOW WITH INDIVIDUAL
//HEADERS OR PERSONAL FILE PATH
//LONG-TERM GOAL  : FIGHTER
//SHORT-TERM GOAL : ACTION SURGE, 2ND WIND

#include "/Users/jnken/Programs/stdc++.h"

using namespace std;

int rollD20()
{
	int roll;
	roll = (rand()%(20*100))/100 + 1;
	return roll;
}

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
	bool melee;
	bool shield;
	int hands;
	string fStyle;
	
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
	int anim;
	int arca;
	int athl;
	int dece;
	int hist;
	int insi;
	int inti;
	int inve;
	int medi;
	int natu;
	int perc;
	int perf;
	int pers;
	int reli;
	int slei;
	int stea;
	int surv;
	
	map<string, bool> skills;
	map<string, bool> profs;
	map<string, bool> inventory;
	
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
		int atkRoll;
		int toHit;
		bool miss = false;
		atkRoll = rollD20();
		toHit = atkRoll + strMOD;
		if (fStyle == "Archery" && melee == false)
		{
			cout << "Archery bonus!" << endl;
			toHit = toHit + 2;
		}
		if (atkRoll == 1)
		{
			cout << "Missed!" << endl;
			miss = true;
		}
		else if (atkRoll == 20)
		{
			cout << "Critical!" << endl;
			for (int i=1; i<=(atkDNum * 2); i++)
			{
			roll = (rand()%(atkDType*100)/100+1);
			if (roll <= 2 && fStyle == "Great Weapon" && 
			    hands == 2 && melee == true)
			{
				cout << "Great Weapon bonus!" << endl;
				roll = (rand()%(atkDType*100)/100+1);
			}
			atkdmg = atkdmg + roll;
			cout << roll << endl;
			}
		}
		else
		{
			cout << "Rolled " << toHit << " to hit!" << endl;
			for (int i=1; i<=atkDNum; i++)
			{
			roll = (rand()%(atkDType*100)/100+1);
			if (roll <= 2 && fStyle == "Great Weapon" && 
			    hands == 2 && melee == true)
			{
				cout << "Great Weapon bonus!" << endl;
				roll = (rand()%(atkDType*100)/100+1);
			}
			atkdmg = atkdmg + roll;
			cout << roll << endl;
			}
		}
		if (miss == false)
		{
			atkdmg = atkdmg + strMOD;
			if (fStyle == "Dueling" && hands == 1 && melee == true)
			{
				cout << "Dueling bonus!" << endl;
				atkdmg = atkdmg + 2;
			}
			cout << "Dealt " << atkdmg << " damage!" << endl;
		}

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

	void listInventory()
	{
		map<string, bool>::iterator pos;

		cout << "INVENTORY" << endl;

		for (pos = inventory.begin(); pos != inventory.end(); ++pos)
		{
			if (pos->first != "none" && pos->first != "nothing" &&
			    pos->second == true)
			{
				cout << "-" << pos->first << endl;
			}
		}
		
		return;
	}

	void status()
	{
	cout << "Player: Lvl " << lvl << " " 
	     << classPlayer;
	if (classPlayer == "Fighter")
	{
		cout << " (" << fStyle << ")" << endl;
	}
	else
	{
		cout << endl;
	}
	cout << "Race: " << racePlayer << endl;
	cout << "Hit Points: " << HPnow << "/" << HPmax << endl;
	cout << "Hit Dice: " << diceLeft << "d" << HPdice << endl;
	cout << "Weapon: " << weapon << " (" << atkDNum <<
		"d" << atkDType << ")" << endl;
	cout << "Armor: " << armor << endl;
	cout << "Armor Class: " << AC;
	if (shield)
	{
		cout << " (SHIELD)" << endl;
	}
	else
	{
		cout << endl;
	}
	cout << "Proficiency Bonus: " << proficiency << endl;
	cout << "Strength:     " << strength << 
		" (" << strMOD << ") " << "ST " << strST << endl;
	cout << "Dexterity:    " << dexterity << 
		" (" << dexMOD << ") " << "ST " << dexST << endl;
	cout << "Constitution: " << constitution <<
		" (" << conMOD << ") " << "ST " << conST << endl;
	cout << "Intelligence: " << intelligence <<
		" (" << intMOD << ") " << "ST " << intST << endl;
	cout << "Wisdom:       " << wisdom << 
		" (" << wisMOD << ") " << "ST " << wisST << endl;
	cout << "Charisma:     " << charisma <<
		" (" << chaMOD << ") " << "ST " << chaST << endl;
	cout << "Passive Perception: " << passivePerception << endl;
		
		return;
	}
};

unit player;

class armor
{
	public:
	
	int ACmod;
	bool adDex;
	string type;
	string name;

	void equip()
	{
		if (player.profs[type] && player.inventory[name])
		{
			player.AC = ACmod;
			if (player.fStyle == "Defense")
			{
				cout << "Defense bonus!" << endl;
				player.AC++;
			}
			if (adDex == true)
			{
				player.AC = player.AC + player.dexMOD;
			}
			if (player.shield == true)
			{
				player.AC = player.AC + 2;
			}
			if (name != "nothing")
			{
				cout << "Equipped!" << endl;
			}
			player.armor = name;
		}
		else
		{
			cout << "Cannot equip!" << endl;
		}

		return;
	}

	void get()
	{
		player.inventory[name] = true;
		if (name != "nothing")
		{
			cout << "You got " << name << "!" << endl;
		}

		return;
	}
};

class shld
{
	public:
	
	string name;
	
	void equip()
	{
		if (player.profs["SHIELD"] && player.inventory[name] &&
		    player.shield == false && player.hands < 2)
		{
			player.AC = player.AC + 2;
			player.shield = true;
			cout << "Equipped!" << endl;
		}
		else if (player.shield == true)
		{
			cout << "Shield already equipped!" << endl;
		}
		else if (player.hands == 2)
		{
			cout << "Already using both hands!" << endl;
		}
		else if (player.inventory[name] == false)
		{
			cout << "You don't have a shield!" << endl;
		}
		else
		{
			cout << "Cannot equip!" << endl;
		}

		return;
	}
	
	void remove()
	{
		if (player.shield == true)
		{
			player.AC = player.AC - 2;
			player.shield = false;
			cout << "Removed!" << endl;
		}
		else
		{
			cout << "No shield equipped!" << endl;
		}
	}

	void get()
	{
		player.inventory[name] = true;
		cout << "You got " << name << "!" << endl;
		
		return;
	}
};

shld shield;

class weapon
{
	public:
	
	int dType;
	int dNum;
	int hands;
	string type;
	bool melee;
	string name;

	void equip()
	{
		if (player.profs[type] && player.inventory[name])
		{
			player.atkDType = dType;
			player.atkDNum = dNum;
			player.hands = hands;
			player.melee = melee;
			if (name != "none")
			{
				cout << "Equipped!" << endl;
			}
			player.weapon = name;
			
			if (player.hands == 2 && player.shield == true)
			{
				shield.remove();
			}
		}
		else
		{
			cout << "Cannot equip!" << endl;
		}

		return;
	}

	void get()
	{
		player.inventory[name] = true;
		if (name != "none")
		{
			cout << "You got " << name << "!" << endl;
		}

		return;
	}
};

armor chain;
armor leather;
armor nothing;

weapon greatsword;
weapon battleaxe;
weapon longbow;
weapon lightCrossbow;
weapon handaxe;
weapon none;

void setArmors()
{
	chain.ACmod = 16;
	chain.adDex = false;
	chain.type = "HARM";
	chain.name = "chain";
	
	leather.ACmod = 11;
	leather.adDex = true;
	leather.type = "LARM";
	leather.name = "leather";
	
	nothing.ACmod = 0;
	nothing.adDex = true;
	nothing.type = "LARM";
	nothing.name = "nothing";
	
	return;
}

void setShields()
{
	shield.name = "shield";
	
	return;
}

void setWeapons()
{
	greatsword.dType = 6;
	greatsword.dNum = 2;
	greatsword.hands = 2;
	greatsword.type = "MMW";
	greatsword.melee = true;
	greatsword.name = "greatsword";
	
	battleaxe.dType = 8;
	battleaxe.dNum = 1;
	battleaxe.hands = 1;
	battleaxe.type = "MMW";
	battleaxe.melee = true;
	battleaxe.name = "battleaxe";

	longbow.dType = 8;
	longbow.dNum = 1;
	longbow.hands = 2;
	longbow.type = "MRW";
	longbow.melee = false;
	longbow.name = "longbow";
	
	lightCrossbow.dType = 8;
	lightCrossbow.dNum = 1;
	lightCrossbow.hands = 2;
	lightCrossbow.type = "SRW";
	lightCrossbow.melee = false;
	lightCrossbow.name = "light_crossbow";
	
	handaxe.dType = 6;
	handaxe.dNum = 1;
	handaxe.hands = 1;
	handaxe.type = "SMW";
	handaxe.melee = true;
	handaxe.name = "handaxe";
	
	none.dType = 0;
	none.dNum = 0;
	none.hands = 0;
	none.type = "SMW";
	none.melee = true;
	none.name = "none";
	
	return;
}

void equip()
{
	string equipThis;
	cout << "What are you equipping?" << endl;
	cin >> equipThis;
		
	if (equipThis == "chain" && player.armor != "chain")
		{
			chain.equip();
		}
	else if (equipThis == "chain" && player.armor == "chain")
		{
			cout << "Already equipped!" << endl;
		}
	else if (equipThis == "leather" && player.armor != "leather")
		{
			leather.equip();
		}
	else if (equipThis == "leather" && player.armor == "leather")
		{
			cout << "Already equipped!" << endl;
		}
	else if (equipThis == "shield")
		{
			shield.equip();
		}
	else if (equipThis == "greatsword" && player.weapon != "greatsword")
		{
			greatsword.equip();
		}
	else if (equipThis == "greatsword" && player.weapon == "greatsword")
		{
			cout << "Already equipped!" << endl;
		}
	else if (equipThis == "battleaxe" && player.weapon != "battleaxe")
		{
			battleaxe.equip();
		}
	else if (equipThis == "battleaxe" && player.weapon == "battleaxe")
		{
			cout << "Already equipped!" << endl;
		}
	else if (equipThis == "longbow" && player.weapon != "longbow")
		{
			longbow.equip();
		}
	else if (equipThis == "longbow" && player.weapon == "longbow")
		{
			cout << "Already equipped!" << endl;
		}
	else if (equipThis == "light_crossbow" && 
		 player.weapon != "light_crossbow")
		{
			lightCrossbow.equip();
		}
	else if (equipThis == "light_crossbow" && 
		 player.weapon == "light_crossbow")
		{
			cout << "Already equipped!" << endl;
		}
	else if (equipThis == "handaxe" && player.weapon != "handaxe")
		{
			handaxe.equip();
		}
	else if (equipThis == "handaxe" && player.weapon == "handaxe")
		{
			cout << "Already equipped!" << endl;
		}
	else
		{
			cout << "Invalid input!" << endl;
		}
		
	return;
}

void remove()
{
	string removeThis;
	cout << "What are you removing?" << endl;
	cin >> removeThis;
	
	if (removeThis == "shield")
	{
		shield.remove();
	}
	else
	{
		cout << "Invalid input!" << endl;
	}
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

	player.profs["LARM"] = true;
	player.profs["MARM"] = true;
	player.profs["HARM"] = true;
	player.profs["SHIELD"] = true;

	player.profs["SMW"] = true;
	player.profs["SRW"] = true;
	player.profs["MMW"] = true;
	player.profs["MRW"] = true;

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
			player.skills["acroP"] = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 1) 
		{
			player.skills["animP"] = true; 
			skilled1 = "yes";
		}
		
		else if (skill1 == 2) 
		{
			player.skills["athlP"] = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 3) 
		{
			player.skills["histP"] = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 4) 
		{
			player.skills["insiP"] = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 5) 
		{
			player.skills["intiP"] = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 6) 
		{
			player.skills["percP"] = true; 
			skilled1 = "yes";
		}

		else if (skill1 == 7) 
		{
			player.skills["survP"] = true; 
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
			player.skills["acroP"] = true; 
			skilled2 = "yes";
		}
		
		else if (skill2 == 1 && skill1 != skill2) 
		{
			player.skills["animP"] = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 2 && skill1 != skill2) 
		{
			player.skills["athlP"] = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 3 && skill1 != skill2)
		{
			player.skills["histP"] = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 4 && skill1 != skill2) 
		{
			player.skills["insiP"] = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 5 && skill1 != skill2) 
		{
			player.skills["intiP"] = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 6 && skill1 != skill2) 
		{
			player.skills["percP"] = true; 
			skilled2 = "yes";
		}

		else if (skill2 == 7 && skill1 != skill2) 
		{
			player.skills["survP"] = true; 
			skilled2 = "yes";
		}

		else 
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (skilled2 == "no");

	nothing.get();
	none.get();
	nothing.equip();
	none.equip();
	
	bool equipped = false;
	int choice;
	
	cout << "(#0) chain mail" << endl;
	cout << "(#1) leather armor, longbow" << endl;
	
	do
	{
		cout << "Enter the corresponding number in "
		     << "parentheses to receive one of the "
		     << "above: " << endl;
		cin >> choice;
		
		if (choice == 0) 
		{
			chain.get(); 
			equipped = true;
		}
		else if (choice == 1)
		{
			leather.get();
			longbow.get();
			equipped = true;
		}
		else 
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (equipped == false);
	
	equipped = false;
	
	cout << "(#0) battleaxe, shield" << endl;
	cout << "(#1) greatsword" << endl;
	
	do
	{
		cout << "Enter the corresponding number in "
		     << "parentheses to receive one of the "
		     << "above: " << endl;
		cin >> choice;
		
		if (choice == 0) 
		{
			battleaxe.get();
			shield.get();
			equipped = true;
		}
		else if (choice == 1)
		{
			greatsword.get();
			equipped = true;
		}
		else 
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (equipped == false);
	
	equipped = false;
	
	cout << "(#0) light crossbow" << endl;
	cout << "(#1) handaxe" << endl;
	
	do
	{
		cout << "Enter the corresponding number in "
		     << "parentheses to receive one of the "
		     << "above: " << endl;
		cin >> choice;
		
		if (choice == 0) 
		{
			lightCrossbow.get();
			equipped = true;
		}
		else if (choice == 1)
		{
			handaxe.get();
			equipped = true;
		}
		else 
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (equipped == false);
	
	equipped = false;
	
	cout << "(#0) dungeoneer's pack" << endl;
	cout << "(#1) explorer's pack" << endl;
	
	do
	{
		cout << "Enter the corresponding number in "
		     << "parentheses to receive one of the "
		     << "above: " << endl;
		cin >> choice;
		
		if (choice == 0) 
		{
			player.inventory["d_pack"] = true;
			cout << "You got d_pack!" << endl;
			equipped = true;
		}
		else if (choice == 1)
		{
			player.inventory["e_pack"] = true;
			cout << "You got e_pack!" << endl;
			equipped = true;
		}
		else 
		{
			cout << "Invalid input!" << endl;
		}
	}
	while (equipped == false);
	
	bool stylish = false;
	string style;

	do
	{
		cout << "Please select a fighting style." << endl
		     << "Use a _ in the place of any spaces." << endl
		     << "For a list of fighting styles, type list:" << endl;
		cin >> style;

		if (style == "list")
		{
			cout << "FIGHTING STYLE " << "BONUS" << endl;
			cout << "ARCHERY        " << "+2 to attack rolls with "
						  << "ranged weapons" << endl;
			cout << "DEFENSE        " << "+1 to armor class while "
						  << "wearing armor" << endl;
			cout << "DUELING        " << "+2 to damage rolls with "
						  << "one-handed melee weapons" 
						  << endl;
			cout << "GREAT WEAPON   " << "Reroll damage dice on an"
						  << " attack with a two-handed"
						  << " melee weapon if roll is "
						  << "1 or 2" << endl;
		}
		else if (style == "archery" || 
			 style == "ARCHERY")
		{
			player.fStyle = "Archery"; 
			stylish = true;
		}
		else if (style == "defense" || 
			 style == "DEFENSE")
		{
			player.fStyle = "Defense";
			stylish = true;
		}
		else if (style == "dueling" || 
			 style == "DUELING")
		{
			player.fStyle = "Dueling";
			stylish = true;
		}
		else if (style == "great_weapon" || 
			 style == "GREAT_WEAPON")
		{
			player.fStyle = "Great Weapon";
			stylish = true;
		}
		else
		{
			cout << "Invalid input! Make sure to choose "
			     << "one of the listed fighting styles." << endl;
		}
	}
	while (stylish == false);
	
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
	if (player.skills["acroP"]) 
	{
		player.acro = player.acro + player.proficiency;
	}
	player.anim = player.wisMOD;
	if (player.skills["animP"]) 
	{
		player.anim = player.anim + player.proficiency;
	}
	player.arca = player.intMOD;
	if (player.skills["arcaP"]) 
	{
		player.arca = player.arca + player.proficiency;
	}
	player.athl = player.strMOD;
	if (player.skills["athlP"]) 
	{
		player.athl = player.athl + player.proficiency;
	}
	player.dece = player.chaMOD;
	if (player.skills["deceP"]) 
	{
		player.dece = player.dece + player.proficiency;
	}
	player.hist = player.intMOD;
	if (player.skills["histP"]) 
	{
		player.hist = player.hist + player.proficiency;
	}
	player.insi = player.wisMOD;
	if (player.skills["insiP"]) 
	{
		player.insi = player.insi + player.proficiency;
	}
	player.inti = player.chaMOD;
	if (player.skills["intiP"]) 
	{
		player.inti = player.inti + player.proficiency;
	}
	player.inve = player.intMOD;
	if (player.skills["inveP"]) 
	{
		player.inve = player.inve + player.proficiency;
	}
	player.medi = player.wisMOD;
	if (player.skills["mediP"]) 
	{
		player.medi = player.medi + player.proficiency;
	}
	player.natu = player.intMOD;
	if (player.skills["natuP"]) 
	{
		player.natu = player.natu + player.proficiency;
	}
	player.perc = player.wisMOD;
	if (player.skills["percP"]) 
	{
		player.perc = player.perc + player.proficiency;
	}
	player.perf = player.chaMOD;
	if (player.skills["perfP"]) 
	{
		player.perf = player.perf + player.proficiency;
	}
	player.pers = player.chaMOD;
	if (player.skills["persP"]) 
	{
		player.pers = player.pers + player.proficiency;
	}
	player.reli = player.intMOD;
	if (player.skills["reliP"]) 
	{
		player.reli = player.reli + player.proficiency;
	}
	player.slei = player.dexMOD;
	if (player.skills["sleiP"]) 
	{
		player.slei = player.slei + player.proficiency;
	}
	player.stea = player.dexMOD;
	if (player.skills["steaP"]) 
	{
		player.stea = player.stea + player.proficiency;
	}
	player.surv = player.wisMOD;
	if (player.skills["survP"]) 
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
	setShields();
	setWeapons();

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
	player.status();

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
			equip();
		}
		
		if (userInput == "remove")
		{
			remove();
		}
		
		if (userInput == "status")
		{
			player.status();
		}

		if (userInput == "inventory")
		{
			player.listInventory();
		}
	}
	while (userInput != "exit");

	return 0;
}
