#ifndef WINDOW_UTILITY_FUNCTIONS_HPP
#define WINDOW_UTILITY_FUNCTIONS_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

float intervalMap(float val, float fromMin, float fromMax, float toMin, float toMax);

std::string float_to_str(float value, int round);

#endif
