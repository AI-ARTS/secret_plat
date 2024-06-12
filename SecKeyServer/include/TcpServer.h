#pragma once
#include "TcpSocket.h"
using namespace std;

class TcpServer
{
public:
	/* 构造函数 */
	TcpServer();
	/* 析构函数 */
	~TcpServer();
	/* 服务器设置监听 */
	int setListen(unsigned short port);
	/* 等待并接受客户端的连接 */
	TcpSocket* acceptConn(int waitSeconds = 10000);
	/* 关闭监听文件描述符 */
	void closefd();

private:
	/* 监听文件描述符 */
	int m_lfd;
};