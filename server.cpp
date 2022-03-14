#include "server.h"

#define BUFSIZE 1024

Server::Server() {

	//윈속 사용
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	//소켓 사용
	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	// binding
	servAddr.sin_family = AF_INET;
	// ip
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//port
	servAddr.sin_port = htons(5555);

	bind(hServSock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	//listen
	listen(hServSock, 5);

	clientLen = sizeof(clientAddr);
	hClientSock = accept(hServSock, (SOCKADDR*)&clientAddr, &clientLen);
}

std::string Server::connectNameClient(std::string serverName) {
	int strLen = 0;
	char serverMessage[BUFSIZE] = "";
	char clientMessage[BUFSIZE] = "";
	std::strcpy(serverMessage, serverName.c_str());


	strLen = recv(hClientSock, clientMessage, BUFSIZE, 0);
	send(hClientSock, serverMessage, strLen, 0);

	std::string clientName(clientMessage);
	return clientName;
}

void Server::sendCardClient(int cardNumber) {
	char cardMessage[BUFSIZE] = "";
	
	std::string cardString = std::to_string(cardNumber);

	std::strcpy(cardMessage, cardString.c_str());

	int strLen = send(hClientSock, cardMessage, strlen(cardMessage), 0);

	return;
	
}

void Server::sendBettingClient(int bettingMoney) {
	char bettingMoneyMessage[BUFSIZE] = "";

	std::string bettingMoneyString = std::to_string(bettingMoney);

	std::strcpy(bettingMoneyMessage, bettingMoneyString.c_str());

	int strLen = send(hClientSock, bettingMoneyMessage, strlen(bettingMoneyMessage), 0);

	return;

}


int Server::receiveBettingClient() {

	int strLen = 0;
	int bettingMoney = 0;
	char bettingMoneyMessage[BUFSIZE] = "";
	
	strLen = recv(hClientSock, bettingMoneyMessage, BUFSIZE, 0);
	std::string bettingMoneyString(bettingMoneyMessage);

	bettingMoney = std::stoi(bettingMoneyString);
	
	return bettingMoney;
}

