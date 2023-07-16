#pragma once

class Event;

class BaseEventListener {
  public:
    BaseEventListener();
    virtual ~BaseEventListener();

    virtual void handle(const Event &event) = 0;
};
