#pragma once
#include <functional>
#include <memory>
#include <vector>

#include "EventListener.hpp"

class Event;
class BaseEventListener;

class EventBus {
  public:
    EventBus();
    ~EventBus();

    template <typename T>
    void registerListener(EventListener<T> &listener) {
        static_assert(std::is_base_of<Event, T>::value,
                      "T must be derived from Event");

        _listeners.push_back(&listener);
    }

    template <typename T>
    void registerListener(const std::function<void(const T &)> &handler) {
        static_assert(std::is_base_of<Event, T>::value,
                      "T must be derived from Event");

        _listeners.push_back(std::make_shared<EventListener<T>>(handler));
    }

    template <typename T>
    void unregisterListener(const EventListener<T> &listener) {
        static_assert(std::is_base_of<Event, T>::value,
                      "T must be derived from Event");

        _listeners.erase(
            std::remove(_listeners.begin(), _listeners.end(), listener),
            _listeners.end());
    }

    void postEvent(const Event &event);

    void loop();

  private:
    std::vector<std::shared_ptr<BaseEventListener>> _listeners;
};
