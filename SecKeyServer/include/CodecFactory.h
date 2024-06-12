#pragma once
#include "Codec.h"

class CodecFactory
{
public:
	virtual Codec* createCodec() = 0;
	virtual ~CodecFactory() {};
};
