#include <iostream>
#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>

int main() {
	Poco::Net::DatagramSocket socket;
	Poco::Net::SocketAddress addr("127.0.0.1:1337");
	int seq = 1;
	int last_seq = 0;
	int number;
	std::cout << "Enter number of Fib: ";
	std::cin >> number;
	int data[2] = { seq, number };
	socket.sendTo(data, sizeof(int) * 2, addr);
	seq++;

	socket.receiveFrom(data, sizeof(int) * 2, addr);
	seq = data[0];
	number = data[1];
	if (last_seq < seq) {
		last_seq = seq;
	}
	std::cout << "Fib number = " << number << std::endl;

}