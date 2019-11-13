#ifndef MENU_H
#define MENU_H
namespace FormersMJ
{
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
		void UpdateControlsMenu();
		void Draw();
		void DrawControlsMenu();
		int actualOption;
		bool getIsControlMenu();
		void changeIsControlMenu();
	private:
		bool isControlMenu;
	};
}
#endif