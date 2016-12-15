#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cfloat>
#include <climits>

/*The Vector2d class is an object consisting of simply an x and
  y value. Certain operators are overloaded to make it easier
  for vector math to be performed.*/

class Vector2d {
public:
    /*The x and y values are public to give easier access for
      outside funtions. Accessors and mutators are not really
      necessary*/
    float x;
    float y;

    //Constructor assigns the inputs to x and y.
    Vector2d();
    Vector2d(float, float);

    /*The following operators simply return Vector2ds that
      have operations performed on the relative (x, y) values*/
    Vector2d operator+(const Vector2d&) const;
    Vector2d operator-(const Vector2d&) const;
    Vector2d operator*(const Vector2d&) const;
    Vector2d operator/(const Vector2d&) const;

    //Check if the Vectors have the same values.
    bool operator==(const Vector2d&) const;

    /*Check which Vectors are closer or further from the
      origin.*/
    bool operator>(const Vector2d&) const;
    bool operator<(const Vector2d&) const;
    bool operator>=(const Vector2d&) const;
    bool operator<=(const Vector2d&) const;

    //Negate both the x and y values.
    Vector2d operator-() const;

    //Apply scalar operations.
    Vector2d operator*(float) const;
    Vector2d operator/(float) const;

    //Product functions
    static float DotProduct(const Vector2d&, const Vector2d&);
    static float CrossProduct(const Vector2d&, const Vector2d&);

    //Returns the length of the vector from the origin.
    float Magnitude() const;

    //Return the unit vector of the input
    Vector2d Normal() const;

    //Return a vector perpendicular to the left.
    static Vector2d Perpendicular(const Vector2d&);

    //Return true if two line segments intersect.
    static bool Intersect(const Vector2d&, const Vector2d&, const Vector2d&, const Vector2d&);

    //Return the point where two lines intersect.
    static Vector2d GetIntersect(const Vector2d&, const Vector2d&, const Vector2d&, const Vector2d&);
};

#endif