#include "optisync.h"
#include "evpp/tcp_conn.h"
#include "xorgwrap.h"

void OptiSync::init_server(OptiComm* comm) {
	comm->on_message.push_back([](const evpp::TCPConnPtr& conn, evpp::Buffer* msg) {
		// TODO: parse message
	});

	XorgWrap xorg;

}
