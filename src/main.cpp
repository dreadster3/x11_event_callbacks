#include <X11/X.h>
#include <X11/Xlib.h>
#include <iostream>
#include <string>

int main() {
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        std::cerr << "Error: cannot open display" << std::endl;
        return 1;
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

        std::string path =
            "/home/dreadster/Documents/projects/local/x11_event_callbacks";

        std::string script_name = "fix_bar_background.sh";

        std::string script_path = path + "/" + script_name;

        if (event.type == ConfigureNotify) {
            if (currentWidth != event.xconfigure.width ||
                currentHeight != event.xconfigure.height) {
                currentWidth = event.xconfigure.width;
                currentHeight = event.xconfigure.height;

                system(script_path.c_str());
            }
        }
    }
}
