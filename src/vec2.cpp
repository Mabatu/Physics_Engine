#include "vec2.h"
#include <cmath>
#include <stdio.h>


float vec2::Magnitude() const {
	return std::sqrt(x * x + y * y);
}
float vec2::Direction() const {
	return atan2(x, y);
}
void vec2::Print() const {
	printf("(%f,%f)\n", x, y);
}
