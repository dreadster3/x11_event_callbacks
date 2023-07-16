#pragma once
#include "BaseEventListener.hpp"

#include <functional>
#include <iostream>

class Event;

template <typename T>
class EventListener : public BaseEventListener {
  public:
    EventListener(const std::function<void(const T &)> &handler) {
        _handler = handler;
    }

    ~EventListener() = default;

    void handle(const Event &event) override {
        auto casted_event = dynamic_cast<const T *>(&event);
        if (casted_event != nullptr) {
            _handler(*casted_event);
        }
    }

  private:
    std::function<void(const T &)> _handler;
};
