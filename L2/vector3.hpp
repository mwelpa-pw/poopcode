#pragma once

namespace l2
{

class Vector3
{
   private:
    static constexpr int VECTOR_SIZE = 3;

    //struct v_represent {
        //double x, y, z;
        //double* T[3] = {&x, &y, &z};

    //};

    struct v_represent {
        union {
            struct { // tak musi byc bo wtedy x=T[0] itd ~~ Claude
                double x, y, z;
            };
            double T[3];
        };
    };

    using internal_representation = v_represent;  // STAGE 1: Define me!

    static_assert(sizeof(internal_representation) == sizeof(double) * 3,
                  "Your internal_representation structure has to be properly sized!");
    static_assert(alignof(internal_representation) == alignof(double),
                  "Your vector structure has to be aligned as double!");

   public:
    internal_representation v;

    Vector3();
    Vector3(double x, double y, double z);

    double length() const;
    void mul(double a);

    void vector3_add(const Vector3& left, const Vector3& right);
    void vector3_print(const Vector3& ref);
};

}  // namespace l2
