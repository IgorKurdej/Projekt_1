#pragma once

#include "list.h"
#include "point.h"

class MenuService
{
private:

	ArrayList<Point> points;

	static int  print_menu();
	void option1();
	void option2();
	void option3();
	void option4() const;
	void option5();
	void option6();
	void option7() const;
public:
	void main_menu();
};

auto operator<<(std::ostream& out, const ArrayList<Point>& p)->std::ostream&;

