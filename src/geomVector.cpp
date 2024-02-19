#include "../headers/geomVector.h"
#include "../headers/point3D.h"
#include <cmath>
#include <iostream>

geomVector::geomVector(point3D v1, point3D v2, point3D v3, point3D v4)
{
    mV1 = v1;
    mV2 = v2;
    mV3 = v3;
    mV4 = v4;
}

geomVector ::~geomVector()
{

}

void geomVector::sVectorV1(point3D v1)
{
    mV1 = v1;
}

void geomVector ::sVectorV2(point3D v2)
{
    mV2 = v2;
}

void geomVector ::sVectorV3(point3D v3)
{
    mV2 = v3;
}

void geomVector ::sVectorV4(point3D v4)
{
    mV2 = v4;
}

point3D geomVector::vector1()
{
    return mV1;
}

point3D geomVector ::vector2()
{
    return mV2;
}

point3D geomVector ::vector3()
{
    return mV2;
}

point3D geomVector ::vector4()
{
    return mV2;
}

void geomVector ::print(point3D a)
{
    std::cout << a.x() << " " << a.y() << " " << a.z();
}

geomVector :: geomVector ()
{

}
// coordinates of A and B to make vector AB

//Calculation for dot product
double geomVector ::dotProduct(point3D v1, point3D v2, point3D v3, point3D v4)
{
    int result = 0;
    double vec1X = v2.x() - v1.x();
    double vec1Y = v2.y() - v1.y();
    double vec1Z = v2.z() - v1.z();

    double vec2X = v4.x() - v3.x();
    double vec2Y = v4.y() - v3.y();
    double vec2Z = v4.z() - v3.z();

    result = vec1X * vec2X + vec1Y * vec2Y + vec1Z * vec2Z;
    return result;
}


//Calculation for cross product
point3D geomVector::crossProduct(point3D v1, point3D v2, point3D v3, point3D v4)
{
    double vec1X = v2.x() - v1.x();
    double vec1Y = v2.y() - v1.y();
    double vec1Z = v2.z() - v1.z();

    double vec2X = v4.x() - v3.x();
    double vec2Y = v4.y() - v3.y();
    double vec2Z = v4.z() - v3.z();

    double result_x = vec1Y * vec2Z - vec1Z * vec2Y;
    double result_y = vec1Z * vec2X - vec1X * vec2Z;
    double result_z = vec1X * vec2Y - vec1Y * vec2X;
    return point3D(result_x, result_y, result_z);
}


//Calculation for vector addition
point3D geomVector::vectorAddition(point3D v1, point3D v2, point3D v3, point3D v4)
{
    double vec1X = v2.x() - v1.x();
    double vec1Y = v2.y() - v1.y();
    double vec1Z = v2.z() - v1.z();

    double vec2X = v4.x() - v3.x();
    double vec2Y = v4.y() - v3.y();
    double vec2Z = v4.z() - v3.z();

    double x = vec1X + vec2X;
    double y = vec1Y + vec2Y;
    double z = vec1Z + vec2Z;
    return point3D(x, y, z);
}

//Calculation for vector magnitude
double geomVector::vectorMagnitude(point3D v1, point3D v2)
{
    double magnitude = sqrt(pow(v2.x() - v1.x(), 2) + pow(v2.y() - v1.y(), 2) + pow(v2.z() - v1.z(), 2));
    return magnitude;
}


//Calculation for vector normalization
point3D geomVector::vectorNormalized(point3D v1, point3D v2)
{
    double x = v2.x() - v1.x();

    double y = v2.y() - v1.x();

    double z = v2.z() - v1.x();

    double magnitude = sqrt(x * x + y * y + z * z);

    double nX = x / magnitude;
    double nY = y / magnitude;
    double nZ = z / magnitude;

    return point3D(nX, nY, nZ);
}

// Calculation to check equlity for vector
bool geomVector::isEqual(point3D v1, point3D v2, point3D v3, point3D v4)
{
    double x1 = v2.x() - v1.x();
    double y1 = v2.y() - v1.y();
    double z1 = v2.z() - v1.z();

    double x2 = v4.x() - v3.x();
    double y2 = v4.y() - v3.y();
    double z2 = v4.z() - v3.z();

    if (x1 == x2 && y1 == y2 && z1 == z2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Calculation for addition scalar
point3D geomVector::addScalar(point3D v1, point3D v2, double scalar)
{
    double X = v2.x() - v1.x() + scalar;
    double Y = v2.y() - v1.y() + scalar;
    double Z = v2.z() - v1.z() + scalar;

    return point3D(X, Y, Z);
}

//Calculation for vector scalar multiplication
point3D geomVector::vectorScalarMultiplication(point3D v1, point3D v2, double scalar)
{

    double X = v2.x() - v1.x() * scalar;
    double Y = v2.y() - v1.y() * scalar;
    double Z = v2.z() - v1.z() * scalar;

    return point3D(X, Y, Z);
}

//Calculation for angle between vectors
double geomVector::angleBetweenVectors(point3D v1, point3D v2, point3D v3, point3D v4)
{

    double dot = dotProduct(v1, v2, v3, v4);

    double x1 = v2.x() - v1.x();
    double y1 = v2.y() - v1.y();
    double z1 = v2.z() - v1.z();

    double x2 = v4.x() - v3.x();
    double y2 = v4.y() - v3.y();
    double z2 = v4.z() - v3.z();

    point3D nVec1(x1, y1, z1);
    point3D nVec2(x2, y2, z2);

    double magnitude = vectorMagnitude(nVec1, nVec2);

    return acos(dot / magnitude) * 180.0 / M_PI;
}

//Calculation for distance between vectors
double geomVector::distanceBetweenVectors(point3D v1, point3D v2, point3D v3, point3D v4)
{
    double x1 = v2.x() - v1.x();
    double y1 = v2.y() - v1.y();
    double z1 = v2.z() - v1.z();

    double x2 = v4.x() - v3.x();
    double y2 = v4.y() - v3.y();
    double z2 = v4.z() - v3.z();

    double d1 = x2 - x1;
    double d2 = y2 - y1;
    double d3 = z2 - z1;

    double formula = d1 * d1 + d2 * d2 + d3 * d3;

    double Distance = sqrt(formula);

    return Distance;
}

//Calculation for scalar subtraction
point3D geomVector ::subtractScalar(point3D v1, point3D v2, double scalar)
{
    double X = v2.x() - v1.x() - scalar;
    double Y = v2.y() - v1.y() - scalar;
    double Z = v2.z() - v1.z() - scalar;

    return point3D(X, Y, Z);
}

//Calculation for vector scalar division
point3D geomVector::vectorScalarDivision(point3D v1, point3D v2, point3D v3, point3D v4, double scalar)
{
    double X = v2.x() - v1.x() / scalar;
    double Y = v2.y() - v1.y() / scalar;
    double Z = v2.z() - v1.z() / scalar;

    return point3D(X, Y, Z);
}

//Calculation to find angle between plane and vector
double geomVector ::angleBetweenPlaneandVector(plane normal, point3D v1, point3D v2)
{

    double dot = dotProduct(v1, v2, normal.gVector1(), normal.gVector2());

    double x1 = v2.x() - v1.x();
    double y1 = v2.y() - v1.y();
    double z1 = v2.z() - v1.z();

    point3D nVec1(x1, y1, z1);

    double x2 = normal.gVector2().x() - normal.gVector1().x();
    double y2 = normal.gVector2().y() - normal.gVector1().y();
    double z2 = normal.gVector2().z() - normal.gVector1().z();

    point3D nVec2(x2, y2, z2);

    double magnitude = vectorMagnitude(nVec1, nVec2);
    double angle = acos(dot / magnitude) * 180 / M_PI;
    return angle;
}

//Calculation for direction of cosines
void geomVector ::directionCosines(point3D v1, point3D v2, point3D v3, point3D v4)
{
    double x1 = v2.x() - v1.x();
    double y1 = v2.y() - v1.y();
    double z1 = v2.z() - v1.z();

    double magnitude1 = vectorMagnitude(v1, v2);

    std ::cout << " Direction Cosine of X is " << x1 / magnitude1 << std ::endl;

    std ::cout << " Direction Cosine of Y is " << y1 / magnitude1 << std ::endl;

    std ::cout << " Direction Cosine of Z is " << z1 / magnitude1 << std ::endl;
}


//Calculation to set lenght of vector
double geomVector ::setLength(point3D v1, point3D v2, double length)
{

    point3D normal = vectorNormalized(v1, v2);

    double magnitude = sqrt(pow(normal.x(), 2) + pow(normal.y(), 2) + pow(normal.z(), 2));

    double newLength = magnitude * length;

    return newLength;
}

