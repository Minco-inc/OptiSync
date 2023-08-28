#pragma once

#include <X11/Xlib.h>

class XorgWrap {
public:
	XorgWrap();

private:
	Display* display;
	Window root;
	void event_thread();
};
