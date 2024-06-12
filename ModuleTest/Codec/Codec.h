
#pragma once
#include <iostream>
#include <string>

class Codec
{
public:
	virtual std::string encodeMsg() = 0;
	virtual void* decodeMsg() = 0;
	virtual ~Codec() {};
};
