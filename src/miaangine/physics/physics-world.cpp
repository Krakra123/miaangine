#include "physics-world.hpp"

#include <algorithm>

#include "core/engine-components.hpp"
#include "miaangine-global-constant.hpp"

namespace mia
{
    #pragma region Constructor_Destructor
    PhysicsWorld::PhysicsWorld():
        _gravity(Vector2<>(0.0, 9.81))
    {}

    PhysicsWorld::~PhysicsWorld()
    {}
    #pragma endregion

    #pragma region Public methods
    void PhysicsWorld::RegisterBody(Body *body)
    {
        _bodies.push_back(body);
    }

    void PhysicsWorld::RemoveBody(Body *body)
    {
        auto listenerIterator = std::find(_bodies.begin(), _bodies.end(), body);

        if (listenerIterator != _bodies.end())
        {
            _bodies.erase(listenerIterator);
        }
    }

    void PhysicsWorld::RegisterCollider(Collider *collider)
    {
        _colliders.push_back(collider);
    }

    void PhysicsWorld::RemoveCollider(Collider *collider)
    {
        auto listenerIterator = std::find(_colliders.begin(), _colliders.end(), collider);

        if (listenerIterator != _colliders.end())
        {
            _colliders.erase(listenerIterator);
        }
    }

    void PhysicsWorld::Step(double elapsedTime)
    {
        BodiesDynamicsHandle(elapsedTime);
        CollisionDetectionHandle();
    }
    #pragma endregion

    #pragma region Private methods
    void PhysicsWorld::BodiesDynamicsHandle(double elapsedTime)
    {
        for (Body *body : _bodies)
        {
            body->velocity() += body->force() / body->mass();

            body->master().position() += body->velocity() * elapsedTime;

            body->force() = Vector2<>::zero();
        }
    }
    void PhysicsWorld::CollisionDetectionHandle()
    {
        for (Collider *lCollider : _colliders)
        {
            for (Collider *rCollider : _colliders)
            {
                if (lCollider == rCollider) continue;

                bool result = (
                    lCollider->minX() <= rCollider->maxX() &&
                    lCollider->maxX() >= rCollider->minX() &&
                    lCollider->minY() <= rCollider->maxY() &&
                    lCollider->maxY() >= rCollider->minY()
                );

                lCollider->SetColliding(result);
                rCollider->SetColliding(result);
            }
        }
    }
    #pragma endregion
}