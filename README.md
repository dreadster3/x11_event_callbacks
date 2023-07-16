# x11_event_callbacks
Small utility that runs as a background service and looks for X11 events.
Allows for the registration of handlers that respond when those events are triggered.
The initial purpose of this tool was to run scripts when a VM window is resized from the host.

## Supported Events
- Resize

## Add new handlers
To add new handlers simply call the `eventBus.registerListener`, a helper function that allows for the use of lambdas.'
**Note**: Make sure this is called before the main loop `eventBus.loop`, which contains the loop that looks for events.
```cpp
eventBus.registerListener<EventToListen>([command](const EventToListen &event) {
    std::cout << "Hello World" << std::end;
});
```
