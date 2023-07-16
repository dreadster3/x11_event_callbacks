#include <cstring>
#include <exception>
#include <iostream>
#include <string>

#include "EventBus.hpp"
#include "ResizeEvent.hpp"

void print_usage(char *argv[], std::ostream &out = std::cout) {
    out << "Usage: " << argv[0] << " <command>" << std::endl;
    out << "\t<command>  command to execute when screen size changes"
        << std::endl;
}

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0) {
            print_usage(argv);
            return 0;
        }
    }

    if (argc != 2) {
        print_usage(argv, std::cerr);
        return 1;
    }

    std::string command = argv[1];

    EventBus eventBus = EventBus();

    // Register a listener for the ResizeEvent
    eventBus.registerListener<ResizeEvent>([command](const ResizeEvent &event) {
        std::cout << "Screen resized to " << event.getWidth() << "x"
                  << event.getHeight() << std::endl;
        std::cout << "Executing command: " << command << std::endl;
        system(command.c_str());
    });

    // Loops looking for events while triggering the registered listeners
    try {
        eventBus.loop();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
