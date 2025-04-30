
class vector3d {
    float _x, _y, _z;
public:
    vector3d() : _x(0), _y(0), _z(0) {}
    
    vector3d& operator+=(const vector3d& other) {
        _x += other._x;
        _y += other._y;
        _z += other._z;
        return *this;
    }

    vector3d operator+(const vector3d& other) const { // funkcja nie może modyfikować stanu obiektu, na którym została wywołana
        vector3d result = *this;
        result += other;
        return result;
    }

    /* ... */
};

int main() {
    vector3d v1;

    return 0;
}