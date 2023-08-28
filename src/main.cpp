#include "opticomm.h"
#include "optisync.h"

int main() {
	OptiComm comm;

	OptiSync sync;
	sync.init_server(&comm);

	comm.start_server("0.0.0.0:9099");
}
