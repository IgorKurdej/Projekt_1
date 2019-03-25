#include "menu_service.h"

int main() 
{
	MenuService menu_service{};
	menu_service.main_menu();
	
	std::cin.get();
	return 0;
}