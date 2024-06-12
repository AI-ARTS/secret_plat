

#include "RespondFactory.h"
#include "RespondCodec.h"
#include <string>
using namespace std;

RespondFactory::RespondFactory(string encStr)
{
	m_flag = false;
	m_encStr = encStr;
}

RespondFactory::RespondFactory(RespondInfo* info)
{
	m_flag = true;
	m_info = info;
}

Codec* RespondFactory::createCodec()
{
	Codec* codec = nullptr;
	if (m_flag) {
		codec = new RespondCodec(m_info);
	} else {
		codec = new RespondCodec(m_encStr);
	}
	return codec;	
}

RespondFactory::~RespondFactory()
{
}
