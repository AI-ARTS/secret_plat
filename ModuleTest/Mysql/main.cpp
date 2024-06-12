

#include <iostream>
#include <cstring>
#include "MySQLOP.h"
using namespace std;

int main()
{
	MySQLOP db;
	bool ret = db.connectDB("127.0.0.1", "root", "Lbw_13999231708", "platform_data");
	if (ret == false) {
		cout << "database init error" << endl;
		exit(1);
	}

	ShmNodeInfo pNode;
	pNode.status = 0;
	pNode.secKeyID = 1;
	strcpy(pNode.clientID, "1001");
	strcpy(pNode.serverID, "1002");
	strcpy(pNode.secKey, "djadqwlejl1231n?/!dajlda");

	db.updateSecKeyID(2);
	db.writeSecKey(&pNode);

	return 0;
}