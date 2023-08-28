#include "xorgwrap.h"
#include <X11/Xlib.h>
#include <glog/logging.h>
#include <thread>

using namespace std;

XorgWrap::XorgWrap() {
	display = XOpenDisplay(NULL);
	if (display == NULL) {
		LOG(FATAL) << "Cannot open display";
	}
	root = DefaultRootWindow(display);

	XSelectInput(display, root, ButtonPressMask | ButtonReleaseMask | PointerMotionMask);

	// TODO: Event loop
	thread loop_thread([this] { this->event_thread(); });
	loop_thread.join();
	// https://www.unix.com/programming/124711-xlib-mouse-events-buttonpressmask.html
}

void XorgWrap::event_thread() {
	XEvent event;
	while (1) {
		// continue if no event
		if (XNextEvent(this->display, &event) == 0) {
			LOG(INFO) << "Got event";
		} else {
			LOG(FATAL) << "XNextEvent failed";
		}
	}
}
