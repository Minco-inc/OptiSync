#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <evpp/tcp_conn.h>

#include "opticomm.h"

using namespace std;

void OptiComm::start_server(string addr) {
    evpp::EventLoop loop;
    evpp::TCPServer server(&loop, addr, "TCPEchoServer", this->thread_num);
    server.SetMessageCallback([this](const evpp::TCPConnPtr& conn, evpp::Buffer* msg) {
		for (unsigned long i = 0; i < this->on_message.size(); i++) {
			if (this->on_message[i] != NULL) {
				this->on_message[i](conn, msg);
			}
		}
    });
    server.SetConnectionCallback([](const evpp::TCPConnPtr& conn) {
        if (conn->IsConnected()) {
            LOG_INFO << "A new connection from " << conn->remote_addr();
        } else {
            LOG_INFO << "Lost the connection from " << conn->remote_addr();
        }
    });
    server.Init();
    server.Start();
    loop.Run();
}
