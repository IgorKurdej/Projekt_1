#include "menu_service.h"


int MenuService::print_menu()
{
	int choice;

	std::cout << "-----------------------------------------------------\n";
	std::cout << "1. Dodawanie na koniec listy" << std::endl;
	std::cout << "2. Dodawanie na listy punktow na koniec" << std::endl;
	std::cout << "3. Usuwanie punktu z pozycji" << std::endl;
	std::cout << "4. Wyszukiwanie punktu" << std::endl;
	std::cout << "5. Ile razy wystepuje podany punkt" << std::endl;
	std::cout << "6. Przesun elementy w prawo" << std::endl;
	std::cout << "7. Wypisz liste" << std::endl;
	std::cout << "8. Zakoncz" << std::endl;
	std::cout << "Wybor: ";
	std::cin >> choice; std::cin.get();
	std::cout << "-----------------------------------------------------\n";
	return choice;
}

void MenuService::option1()
{
	std::cout << "Podaj punkt, ktory chcesz dodac na koniec" << std::endl;

	std::cout << "Wspolrzedna x: ";
	double x;
	std::cin >> x; std::cin.get();
	
	std::cout << "Wspolrzedna y: ";
	double y;
	std::cin >> y; std::cin.get();

	points += Point{ x, y };
}

void MenuService::option2()
{
	int counter;
	std::cout << "Podaj ile punktow chesz wstawic: ";
	std::cin >> counter; std::cin.get();

	ArrayList<Point> my_points;

	for (auto i = 0; i < counter; ++i) {
		
		std::cout << "Wspolrzedna x: ";
		double x;
		std::cin >> x; std::cin.get();

		std::cout << "Wspolrzedna y: ";
		double y;
		std::cin >> y; std::cin.get();

		my_points.insert(my_points.count(), Point{ x, y });
	}
	points.insert_list(points.count(), my_points);
	
}

void MenuService::option3()
{
	int choice;
	std::cout << "Z ktorej pozycji chcesz usunac punkt: ";
	std::cin >> choice; std::cin.get();

	points.remove(choice);
}

void MenuService::option4() const
{
	std::cout << "Jakiego punktu szukasz \n";

	std::cout << "Wspolrzedna x: ";
	double x;
	std::cin >> x; std::cin.get();

	std::cout << "Wspolrzedna y: ";
	double y;
	std::cin >> y; std::cin.get();

	points.search(Point{ x, y });
}

void MenuService::option5()
{
	std::cout << "Wspolrzedna x: ";
	double x;
	std::cin >> x; std::cin.get();

	std::cout << "Wspolrzedna y: ";
	double y;
	std::cin >> y; std::cin.get();

	points.frequency(Point{ x,y });
}

void MenuService::option6()
{
	int choice;
	std::cout << "O ile miejsc chce przesunac ilste: ";
	std::cin >> choice; std::cin.get();

	points = points >> choice;
}

void MenuService::option7() const
{
	std::cout << points << std::endl;
}

auto operator<<(std::ostream& out, const ArrayList<Point>& p)->std::ostream& {
	for (auto i = 0; i < p.count(); ++i) {
		out << "P = ( " << p[i].get_x() << ", " << p[i].get_y() << " )\n";
	}
	return out;
}


void MenuService::main_menu()
{
	do
	{
		switch (print_menu())
		{
		case 1:
			option1();
			break;
		case 2:
			option2();
			break;
		case 3:
			option3();
			break;
		case 4:
			option4();
			break;
		case 5:
			option5();
			break;
		case 6:
			option6();
			break;
		case 7:
			option7();
			break;
		case 8:
			break;
		default:
			std::cout << "Nie ma takiej opcji" << std::endl;
		}
	} while (print_menu() != 8);
}


