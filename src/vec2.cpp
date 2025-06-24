#include "vec2.h"
#include <cmath>


float vec2::Magnitude() const {
	return std::sqrt(x * x + y * y);
}
float vec2::Direction() const {
	return atan2(x, y);
}
