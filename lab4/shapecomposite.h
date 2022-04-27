#ifndef ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
#define ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H

#include <memory>
#include "shape.h"
#include "shapeoperation.h"

namespace Shapes {

    class ShapeComposite : public Shape{
    public:
        ShapeComposite(const std::shared_ptr<Shape>&, const std::shared_ptr<Shape>&, ShapeOperation);
        ~ShapeComposite();
        [[nodiscard]] bool isIn(int x, int y) const override;
    private:
        std::shared_ptr<Shape> shape1_;
        std::shared_ptr<Shape> shape2_;
        ShapeOperation operation_;
    };


} // Shapes

#endif //ZAD4SHAPEDRAWING_SHAPECOMPOSITE_H
