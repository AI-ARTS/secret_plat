#include <iostream>
#include <ClientOP.h>
using namespace std;

int main()
{
	ClientOP op("config.json");
	while (true)
	{
		int ret = op.showMenu();
		switch (ret)
		{
		case 1:
			op.secKeyConsult();
			break;
		case 2:
			op.secKeyCheck();
			break;
		case 3:
			op.secKeyCancel();
			break;
		case 4:
			op.secKeyView();
			break;
		case 0:
			cout << "  Bye!" << endl;
			exit(0);
		default:
			break;
		}
	}
	exit(0);
}
