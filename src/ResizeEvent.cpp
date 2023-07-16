#include "ResizeEvent.hpp"

ResizeEvent::ResizeEvent(int width, int height)
    : _width(width), _height(height) {}

ResizeEvent::~ResizeEvent() {}

int ResizeEvent::getWidth() const { return _width; }

int ResizeEvent::getHeight() const { return _height; }
