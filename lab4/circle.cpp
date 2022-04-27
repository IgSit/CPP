#include "circle.h"
#include <cmath>

namespace Shapes {
    Circle::Circle(int x, int y, int radius) {
        x_ = x;
        y_ = y;
        radius_ = radius;
    }

    bool Circle::isIn(int x, int y) const {
        return sqrt(pow((x_ - x), 2) + pow((y_ - y), 2)) <= radius_;
    }

    int Circle::x() const {
        return x_;
    }

    int Circle::y() const {
        return y_;
    }

    int Circle::getRadius() const {
        return radius_;
    }

    Circle::~Circle() = default;
} // Shapes