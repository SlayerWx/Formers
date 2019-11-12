#include "Zone_Structures.h"
Zone_Structures::Zone_Structures()
{
}
Zone_Structures::~Zone_Structures()
{
}
TileType Zone_Structures::getForm()
{
	return myForm;
}

void Zone_Structures::setForm(TileType myNewForm)
{
	myForm = myNewForm;
}
