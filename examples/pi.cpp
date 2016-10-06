#include "pi.h"

#include <iostream>
#include <chrono>
#include <fmrcxx/fmrcxx.h>

using namespace fmrcxx;

class Point {
public:
	Point(double x, double y) : x(x), y(y) {}
	Point(Point&& rhs) : x(rhs.x), y(rhs.y) {}
	bool isInsideUnitaryCircle() const noexcept {
		return (x * x + y * y) <= 1.0;
	}

	double x;
	double y;
};

double pi(unsigned long nbPoint) {
	Random<unsigned int> seedGenerator(std::chrono::system_clock::now().time_since_epoch().count());

	unsigned long nbPointInsideUnitaryCircle = Random<double>(seedGenerator.next(), 0, 1).zip<double>(Random<double>(seedGenerator.next(), 0, 1))
			.limit(nbPoint)
			.map<Point>([](Tuple<double&, double&>& tuple) { return Point(tuple.getKey(), tuple.getValue()); })
			.filter([](const Point& point) { return point.isInsideUnitaryCircle(); })
			.count();
	return 4 * ((double)nbPointInsideUnitaryCircle / nbPoint);
}
