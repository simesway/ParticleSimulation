#include "UtilityFunctions.hpp"

float intervalMap(float val, float fromMin, float fromMax, float toMin, float toMax){
	return (val - fromMin) / (fromMax - fromMin) * (toMax - toMin) + toMin;
}

std::string float_to_str(float value, int round){
	int factor = std::pow(10,round);
	std::string string = std::to_string(std::round(value*factor)/factor);
	for(int i=0; i < 6-round; ++i)
		string.pop_back();
	return string;
}
