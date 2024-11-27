#ifndef _MIA_POINT_H
#define _MIA_POINT_H

#include "general/math.hpp"

namespace mia
{
    class Point
    {
    public:
        Point(glm::vec2 position, glm::vec2 pivot = {0.0f, 0.0f});
        Point(float x = 0.0f, float y = 0.0f, float px = 0.0f, float py = 0.0f);

        // Attributes
        glm::vec2 position;
        glm::vec2 pivot;

        // Public methods
        glm::vec2 GetLocalPosition() const;
        void SetLocalPosition(glm::vec2 localPos);
        glm::mat3 GetMatrix() const;

        void Translate(float x, float y);
        void Translate(glm::vec2 value);
        void Scale(float x, float y);
        void Scale(glm::vec2 value);
        void Rotate(float angle);

    private:
        glm::mat3 GetLocalMatrix();
    };
}

#endif