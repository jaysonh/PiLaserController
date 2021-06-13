#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace JUtils
{

	float map( float _v, float _inMin, float _inMax, float _outMin, float _outMax);
}

namespace JMath
{
	const float PI     =  3.1415926535;
	const float TWO_PI = 6.28318530718;
	const float DEG_TO_RAD = 0.017453292519943295769236907684886f;
}

namespace JString
{
	int splitStr(const std::string &txt, std::vector<std::string> &strs, char ch);
	int splitInt(const std::string &txt, std::vector<int> &strs,         char ch);
}
