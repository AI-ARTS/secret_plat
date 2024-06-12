

#pragma once
#include <iostream>
using namespace std;

class Interface
{
public:
	Interface(string json);
	~Interface();

	/* 数据加密 */
	string encryptData(string data);
	/* 数据解密 */
	string decryptData(string data);

private:
	/* 加密使用的密钥 */
	string m_key;
};