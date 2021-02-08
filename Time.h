#pragma once
#include <ctime>

inline double YearFrac(time_t a_t) {
	constexpr double SecY = 365.25 * 86400.0;
	return 1970.0 + double(a_t)/SecY;
}
