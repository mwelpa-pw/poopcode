#include "vector3.hpp"
#include <cmath>
#include <iostream>

namespace l2
{

    Vector3::Vector3()
    {}

    Vector3::Vector3(double x, double y, double z)
    {
        // STAGE 1: Implement me!
        x == 0 ? v.x = 0 : v.x = x;
        y == 0 ? v.y = 0 : v.y = y;
        z == 0 ? v.z = 0 : v.z = z;

    }

    double Vector3::length() const
    {
        return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    void Vector3::mul(double a)
    {
        v.x = a * v.x;
        v.y = a * v.y;
        v.z = a * v.z;
    }

    Vector3 vector3_add(const Vector3& left, const Vector3& right) {
        Vector3 result;
        result.v.x = left.v.x + right.v.x;
        result.v.y = left.v.y + right.v.y;
        result.v.z = left.v.z + right.v.z;

        return result;
    }


    void vector3_print(const Vector3& ref) {
        std::cout << "x: " << ref.v.x << "\ny: " << ref.v.y << "\nz: " << ref.v.z << "\nlength: "<< ref.length() << std::endl;
    }

}  // namespace l2
