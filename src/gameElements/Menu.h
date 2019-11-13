#ifndef MENU_H
#define MENU_H
class Menu
{
	enum MenuOptions
	{
		Play, Controls, Credits, Exit
	};
public:
	Menu();
	~Menu();
	void Init();
	void Input();
	void Update();
	void Draw();
	int actualOption;
private:

};
#endif