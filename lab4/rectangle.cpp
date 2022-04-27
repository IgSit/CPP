#include "rectangle.h"

namespace Shapes {
    Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) {
        this->x_ = xFrom;
        this->xTo_ = xTo;
        this->y_ = yFrom;
        this->yTo_ = yTo;
    }

    Rectangle::~Rectangle() = default;

    bool Rectangle::isIn(int x, int y) const {
        return this->x_ <= x && x <= this->xTo_ && this->y_ <= y && y <= this->yTo_;
    }

    int Rectangle::x() const {
        return x_;
    }

    int Rectangle::xTo() const {
        return xTo_;
    }

    int Rectangle::y() const {
        return y_;
    }

    int Rectangle::yTo() const {
        return yTo_;
    }
} // Shapes