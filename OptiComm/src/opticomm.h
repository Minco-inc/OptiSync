#pragma once

#include <functional>
#include <string>
#include <evpp/tcp_server.h>
#include <vector>

using namespace std;

class OptiComm {
public:
	void start_server(string addr);
	void start_client(string addr);
	int thread_num = 4;
	vector<function<void(const evpp::TCPConnPtr& conn,
								 evpp::Buffer* msg)>> on_message;
	
private:
};
