#pragma once

#include "Event.hpp"

class ResizeEvent : public Event {
  public:
    ResizeEvent(int width, int height);
    virtual ~ResizeEvent();

    int getWidth() const;
    int getHeight() const;

  private:
    int _width;
    int _height;
};
