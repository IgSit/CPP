//
// Created by igsit on 27.04.22.
//

#include "shapecomposite.h"

namespace Shapes {
    ShapeComposite::ShapeComposite(const std::shared_ptr <Shape>& s1, const std::shared_ptr <Shape>& s2, ShapeOperation operation) {
        shape1_ = s1;
        shape2_ = s2;
        operation_ = operation;
    }

    ShapeComposite::~ShapeComposite() = default;

    bool ShapeComposite::isIn(int x, int y) const {
        /*
         * Oczywiście to sprawdzenie nie powinno tak wyglądać, bo możemy tylko dwa kształty porównać, bez
         * struktury kształtów. Rozwiązaniem byłoby stworzenie 3 tablic: intersected, included i excluded.
         * Wtedy sprawdzanie isIn polegałoby na:
         *     - dodaniu kształtów do odp tablic zależnie od operacji
         *     - liniowym przejściu po wszystkich tablicach (musi należeć do wszystkich z intersected,
         *     jakichkolwiek z included i do żadnej z excluded)
         *
         * ALE:
         *   stworzenie std::shared_ptr<Shape> intersected[] powoduje, że nadchodzi Białe Zimno,
         *   mleko krowom kwaśnieje, dzieci rodzą się chrome i w ogóle, no nie da się, więc dałem sobie
         *   z tym spokój, szkoda nerwów na to
         */
        switch (operation_) {
            case ShapeOperation::SUM:
                return (*shape1_).isIn(x, y) || (*shape2_).isIn(x, y);
            case ShapeOperation::INTERSECTION:
                return (*shape1_).isIn(x, y) && (*shape2_).isIn(x, y);
            case ShapeOperation::DIFFERENCE:
                return (*shape1_).isIn(x, y) && !(*shape2_).isIn(x, y);
        }
    }
} // Shapes