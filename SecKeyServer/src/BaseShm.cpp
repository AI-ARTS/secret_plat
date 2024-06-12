#include "BaseShm.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const char RandX = 'x';
BaseShm::BaseShm(int key)
{
	getShmID(key, 0, 0);
}

BaseShm::BaseShm(int key, int size)
{
	getShmID(key, size, IPC_CREAT | 0664);
}

BaseShm::BaseShm(string name)
{
	key_t key = ftok(name.c_str(), RandX);
	getShmID(key, 0, 0);
}

BaseShm::BaseShm(string name, int size)
{
	key_t key = ftok(name.c_str(), RandX);
	getShmID(key, size, IPC_CREAT | 0664);
}

void* BaseShm::mapShm()
{
	m_shmAddr = shmat(m_shmID, nullptr, 0);
	if (m_shmAddr == (void*)-1) {
		return nullptr;
	}
	return m_shmAddr;
}

int BaseShm::unmapShm()
{
	int ret = shmdt(m_shmAddr);
	return ret;
}

int BaseShm::delShm()
{
	int ret = shmctl(m_shmID, IPC_RMID, nullptr);
	return ret;
}

BaseShm::~BaseShm()
{
}

int BaseShm::getShmID(key_t key, int shmSize, int flag)
{
	// 需要传入什么呢？
	// key：用于标识共享内存段的键值，可以是一个唯一的整数值。
    // size：指定需要创建或获取的共享内存段的大小。
    // shmflg：指定共享内存的访问权限和操作选项，例如读写权限、创建新段等

	cout << "share memory size: " << shmSize << endl;
	m_shmID = shmget(key, shmSize, flag);
	cout << "m_shmID = " << m_shmID << endl;
	if (m_shmID == -1 && errno != EEXIST) {
		perror("shmget error");
	}	
	return m_shmID;
}