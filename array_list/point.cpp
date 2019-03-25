#include "point.h"


Point::Point() : x{ 0 }, y{ 0 } {}

Point::Point(double x, double y) : x{ x }, y{ y } {}

auto Point::get_x() const -> decltype(x) {
	return x;
}

auto Point::get_y() const -> decltype(x) {
	return y;
}

auto Point::set_x(double x) -> void {
	this->x = x;
}

auto Point::set_y(double y) -> void {
	this->y = y;
}

auto Point::operator==(const Point& rhs) -> bool {
	return x == rhs.x && y == rhs.y;
}

auto operator<<(std::ostream& out, const Point& p) -> std::ostream& {
	return out << "P = ( " << p.x << ", " << p.y << " )";
}