#include "client.h"

#define BUFSIZE 1024

Client::Client() {
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons(5555);

	connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr));
}


std::string Client::connectNameServer(std::string clientName) {

	char ClientMessage[BUFSIZE] = "";
	char ServerMessage[BUFSIZE] = "";
	std::strcpy(ClientMessage, clientName.c_str());

	int strLen = send(hSocket, ClientMessage, strlen(ClientMessage), 0);

	strLen = recv(hSocket, ServerMessage, BUFSIZE - 1, 0);
	std::string serverName(ServerMessage);
	ClientMessage[strLen] = 0;

	return serverName;
}

int Client::receiveCardServer() {
	int strLen = 0;
	int cardNumber = 0;
	char cardNumberMessage[BUFSIZE] = "";

	strLen = recv(hSocket, cardNumberMessage, BUFSIZE, 0);
	std::string cardNumberString(cardNumberMessage);

	cardNumber = std::stoi(cardNumberString);

	return cardNumber;
}

int Client::receiveBettingServer() {
	int strLen = 0;
	int bettingMoney = 0;
	char bettingMoneyMessage[BUFSIZE] = "";

	strLen = recv(hSocket, bettingMoneyMessage, BUFSIZE, 0);
	std::string bettingMoneyString(bettingMoneyMessage);

	bettingMoney = std::stoi(bettingMoneyString);

	return bettingMoney;
}

void Client::sendBettingServer(int bettingMoney) {
	char bettingMoneyMessage[BUFSIZE] = "";
	
	std::string bettingMoneyString = std::to_string(bettingMoney);

	std::strcpy(bettingMoneyMessage, bettingMoneyString.c_str());

	int strLen = send(hSocket, bettingMoneyMessage, strlen(bettingMoneyMessage), 0);

	return ;
}
void Client::disconnectServer() {

	closesocket(hSocket);
	WSACleanup();
}