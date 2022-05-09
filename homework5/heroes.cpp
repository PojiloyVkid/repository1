#include <iostream>
#include <cstdlib>

using namespace std;

class Hero
{
public:
	string name;
	int health;
	int strength;

	Hero(string name, int strength)
	{
		this->name = name;
		this->strength = strength;
		this->health = 5000;
	};

	void strike(Hero& otherHero)
	{
		srand(this->strength + this->health);
		int random_damage = static_cast<int>(rand());
		int damage = random_damage % 500;
		otherHero.health = otherHero.health - damage;
	}
};

int main()
{
	Hero Hero1("Spiderman", 500);
	Hero Hero2("Green Goblin", 500);

	while ((Hero1.health > 0) && (Hero2.health > 0))
	{
		if (Hero2.health > 0) Hero2.strike(Hero1); // злодеи обычно наносят удар первыми
		
		if (Hero1.health > 0)
		{
			if (Hero1.health > 0) Hero1.strike(Hero2); //он может дать сдачи только если жив)
			cout << Hero1.name << ": " << Hero1.health << endl;
		}
		else
		{
			cout << Hero1.name << " dead" << endl;
			break;
		}

		if (Hero2.health > 0)
			cout << Hero2.name << ": " << Hero2.health << endl;
		else
		{
			cout << Hero2.name << " dead" << endl;
			break;
		}
	}
}