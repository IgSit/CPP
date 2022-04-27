#ifndef ZAD4SHAPEDRAWING_RECTANGLE_H
#define ZAD4SHAPEDRAWING_RECTANGLE_H

#include "shape.h"

namespace Shapes {

    class Rectangle: public Shape {
    public:
        Rectangle(int, int, int, int);
        virtual ~Rectangle();
        [[nodiscard]] bool isIn(int x, int y) const override;
        [[nodiscard]] int x() const;
        [[nodiscard]] int xTo() const;
        [[nodiscard]] int y() const;
        [[nodiscard]] int yTo() const;
    private:
        int x_, xTo_, y_, yTo_;


    };

} // Shapes

#endif //ZAD4SHAPEDRAWING_RECTANGLE_H
