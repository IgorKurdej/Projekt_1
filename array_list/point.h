#ifndef POINT_H
#define POINT_H

#include "libs.h"

class Point {
	double x;
	double y;
public:
	Point();
	Point(double x, double y);

	auto get_x() const -> decltype(x);
	auto get_y() const -> decltype(x);
	auto set_x(double x) -> void;
	auto set_y(double y) -> void;

	auto operator==(const Point& rhs) -> bool;

	friend auto operator<<(std::ostream& out, const Point& p)->std::ostream&;
};

#endif // !POINT_H