#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Boss.h"
#include "GameName.h"
#include "Points.h"


void Boss::hitBoss()
{
	char buttonToClick[] = { 'a', 'A', 'b', 'B', 'C', 'c', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'i', 'I', 'j', 'J', 'h', 'H' };
	char button;
	int c;
	while (hp >= 0 && breastplate >= 0)
	{
		system("cls");
		c = rand() % + 20;
		std::cout << "Boss hp: " << hp;
		std::cout << "\nBoss breastplate: " << breastplate;
		button = _getch();
		if(button == buttonToClick[c])
		{
			if (hp <= 0)
			{
				breastplate -= 4;
			}
			else if (breastplate <= 0)
			{
				hp -= 2;
			}
			else
			{
				breastplate -= 4;
				hp -= 2;
			}
		}
		else
		{
			std::cout << "Boss hp + 10"; hp += 10;
			std::cout << "Boss breastplate + 10"; breastplate += 10;
		}
	}
	sendWin();

}

void Boss::sendWin()
{
	NameGame message;
	Points addPoint;
	message.wonMessage();
	addPoint.addPoint(20000);
}