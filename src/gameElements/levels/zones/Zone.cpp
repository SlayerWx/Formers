#include "Zone.h"
Zone::Zone()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 13; j++)
		{
		cantPlates[i][j] = 0;
		}
	}
}

Zone::~Zone()
{
}

void Zone::Init() {}
void Zone::Update() {}
void Zone::Draw() {}