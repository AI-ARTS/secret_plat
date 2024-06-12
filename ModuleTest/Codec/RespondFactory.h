

#pragma once
#include <iostream>
#include "CodecFactory.h"
#include "RespondCodec.h"
using namespace std;

class RespondFactory : public CodecFactory
{
public:
	RespondFactory(string encStr);
	RespondFactory(RespondInfo* info);
	Codec* createCodec() override;
	~RespondFactory();

private:
	bool m_flag;
	string m_encStr;
	RespondInfo* m_info;
};
