#include "EventBus.hpp"

#include <X11/X.h>
#include <X11/Xlib.h>

#include "ResizeEvent.hpp"

class Event;

EventBus::EventBus() {
    _listeners = std::vector<std::shared_ptr<BaseEventListener>>();
}

EventBus::~EventBus() {}

void EventBus::postEvent(const Event &event) {
    for (auto &listener : _listeners) {
        listener->handle(event);
    }
}

void EventBus::loop() {
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        throw std::runtime_error("Cannot open display");
    }

    auto screen = DefaultScreen(display);
    auto root = RootWindow(display, screen);

    XWindowAttributes attr;
    XGetWindowAttributes(display, root, &attr);

    int currentWidth = attr.width;
    int currentHeight = attr.height;

    XSelectInput(display, root, StructureNotifyMask);

    while (true) {
        XEvent event;
        XNextEvent(display, &event);

        if (event.type == ConfigureNotify) {
            if (currentWidth != event.xconfigure.width ||
                currentHeight != event.xconfigure.height) {
                currentWidth = event.xconfigure.width;
                currentHeight = event.xconfigure.height;
                this->postEvent(ResizeEvent(currentWidth, currentHeight));
            }
        }
    }
}
