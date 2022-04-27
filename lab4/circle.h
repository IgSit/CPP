#ifndef ZAD4SHAPEDRAWING_CIRCLE_H
#define ZAD4SHAPEDRAWING_CIRCLE_H

#include "shape.h"

namespace Shapes {

    class Circle : public Shape{
    public:
        Circle(int, int, int);
        ~Circle();
        [[nodiscard]] bool isIn(int x, int y) const override;
        [[nodiscard]] int x() const;
        [[nodiscard]] int y() const;
        [[nodiscard]] int getRadius() const;
    private:
        int x_;
        int y_;
        int radius_;
    };

} // Shapes

#endif //ZAD4SHAPEDRAWING_CIRCLE_H
