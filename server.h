#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS


#include <WinSock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>


class Server {

private:
	WSADATA wsaData;
	SOCKET hServSock;
	SOCKADDR_IN servAddr;

	int clientLen;
	SOCKET hClientSock;
	SOCKADDR_IN clientAddr;


public:
	Server();
	std::string connectNameClient(std::string serverName);
	int receiveBettingClient();
	void sendCardClient(int cardNumber);
	void sendBettingClient(int bettingMoney);

};