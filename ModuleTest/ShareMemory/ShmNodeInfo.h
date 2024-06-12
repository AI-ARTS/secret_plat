

#pragma once
#include <strings.h>
using namespace std;

class ShmNodeInfo
{
public:
	ShmNodeInfo() : status(0), secKeyID(0)
	{
		bzero(clientID, sizeof(clientID));
		bzero(serverID, sizeof(serverID));
		bzero(secKey, sizeof(secKey));
	}

public:
	/* 秘钥状态：1可用，0不可用 */
	int status;
	/* 秘钥编号 */
	int secKeyID;
	/* 客户端ID，客户端的标识 */
	char clientID[12];
	/* 服务器ID，服务器的标识 */
	char serverID[12];
	/* 对称加密的秘钥 */
	char secKey[128];
};