#pragma once
#include <iostream>
#include "CodecFactory.h"
#include "Codec.h"
#include "RequestCodec.h"
using namespace std;

class RequestFactory : public CodecFactory
{
public:
	RequestFactory(string encStr);
	RequestFactory(RequestInfo* info);
	Codec* createCodec() override;
	~RequestFactory();

private:
	bool m_flag;
	string m_encStr;
	RequestInfo* m_info;
};
