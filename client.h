#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <WinSock2.h>
#include <string>

class Client {

private:
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

public:
	Client();
	std::string receiveNameServer();
	void sendNameServer(std::string clientName);
	int receiveCardServer();
	int receiveBettingServer();
	void sendBettingServer(int bettingMoney);
	void disconnectServer();
};