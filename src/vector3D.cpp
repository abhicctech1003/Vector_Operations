#include <iostream>
#include "../headers/vector3D.h"
#include "../headers/plane.h"

Geometry ::GeomVector::GeomVector() : Point3D()
{

}

Geometry ::GeomVector::GeomVector(double x, double y, double z) : Point3D(x, y, z) 
{

}

Geometry::GeomVector ::GeomVector::~GeomVector() 
{

}

bool Geometry::GeomVector ::operator==(const GeomVector &other) const
{
    return ((other.x() == this->x()) && (other.y() == this->y()) && (other.z() == this->z()));
}

double Geometry::GeomVector::dotProduct(const GeomVector &other) const
{
    return (this->x() * other.x()) + (this->y() * other.y()) + (this->z() * other.z());
}

Geometry::GeomVector Geometry::GeomVector::crossProduct(const GeomVector &other) const
{
    double newX = (this->y() * other.z()) - (this->z() * other.y());
    double newY = (this->z() * other.x()) - (this->x() * other.z());
    double newZ = (this->x() * other.y()) - (this->y() * other.x());
    return GeomVector(newX, newY, newZ);
}

double Geometry::GeomVector::magnitude() const
{
    return sqrt(this->x() * this->x() + this->y() * this->y() + this->z() * this->z());
}

Geometry::GeomVector Geometry::GeomVector::normalize() const
{
    double mag = magnitude();
    return GeomVector(this->x() / mag, this->y() / mag, this->z() / mag);
}

Geometry::GeomVector Geometry::GeomVector::operator+(const GeomVector &other) const
{
    return GeomVector(this->x() + other.x(), this->y() + other.y(), this->z() + other.z());
}

Geometry::GeomVector Geometry::GeomVector::operator-(const GeomVector &other) const
{
    return GeomVector(this->x() - other.x(), this->y() - other.y(), this->z() - other.z());
}

Geometry::GeomVector Geometry::GeomVector::operator*(const GeomVector &other) const
{
    return GeomVector(this->x() * other.x(), this->y() * other.y(), this->z() * other.z());
}

Geometry::GeomVector Geometry::GeomVector::operator/(const GeomVector &other) const
{
    return GeomVector(this->x() / other.x(), this->y() / other.y(), this->z() / other.z());
}

Geometry::GeomVector Geometry::GeomVector::setVectorLength(double newLength) const
{
    return this->normalize().multiplyScalar(newLength);
}

Geometry::GeomVector Geometry::GeomVector::addScalar(double scalar) const
{
    return GeomVector(this->x() + scalar, this->y() + scalar, this->z() + scalar);
}

Geometry::GeomVector Geometry::GeomVector::subtractScalar(double scalar) const
{
    return GeomVector(this->x() - scalar, this->y() - scalar, this->z() - scalar);
}

Geometry::GeomVector Geometry::GeomVector::multiplyScalar(double scalar) const
{
    return GeomVector(this->x() * scalar, this->y() * scalar, this->z() * scalar);
}

Geometry::GeomVector Geometry::GeomVector::divideScalar(double scalar) const
{
    return GeomVector(this->x() / scalar, this->y() / scalar, this->z() / scalar);
}

double Geometry::GeomVector::distanceBetweenVectors(const GeomVector &other) const
{
    double dx = this->mX - other.x();
    double dy = this->mY - other.y();
    double dz = this->mZ - other.z();
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double Geometry::GeomVector::distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const
{
    double dX = x() - plane.pointOnPlane().x();
    double dY = y() - plane.pointOnPlane().y();
    double dZ = z() - plane.pointOnPlane().z();
    double dotProduct = dX * plane.normal().x() + dY * plane.normal().y() + dZ * plane.normal().z();
    double distance = std::abs(dotProduct) / plane.normal().magnitude();
    return distance;
}

double Geometry::GeomVector ::angleBetweenVectors(const GeomVector &other) const
{
    double dotProductResult = this->dotProduct(other);
    double magnitudeResult = magnitude() * other.magnitude();
    std::cout << "1: " << dotProductResult << "2: " << magnitudeResult << std::endl;
    double angleradians = acos(dotProductResult / magnitudeResult);
    // converting radians to degrees
    return angleradians * (180.0 / M_PI);
}

double Geometry::GeomVector::angleBetweenVectorAndPlane(const Geometry::Plane &plane) const
{
    // vector and plane's normal's dot product
    double dotProductResult = dotProduct(plane.normal());
    // vector and plane's normal's magnitude
    double vectorMagnitude = magnitude();
    double normalMagnitude = plane.normal().magnitude();

    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * normalMagnitude));
    // for converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}

void Geometry::GeomVector ::directionCosines() const
{
    double magnitudeResult = magnitude();
    double point1;
    double point2;
    double point3;
    // Check the magnitude is not zero to avoid division by 0
    if (magnitudeResult != 0.0)
    {
        point1 = std::acos(this->x() / magnitude()) * (180.0 / M_PI);
        point2 = std::acos(this->y() / magnitude()) * (180.0 / M_PI);
        point3 = std::acos(this->z() / magnitude()) * (180.0 / M_PI);
    }
    else
    {
        // For case of magnitude is zero
        point1 = point2 = point3 = 0.0;
    }
    std::cout << "point1 :" << point1 << "point2 :" << point2 << "point3 :" << point3 << std::endl;
}

Geometry::GeomVector Geometry::GeomVector::multiplyMatrix(const LinearAlgebra::Matrix &matrix) const
{
    double resultX = x() * matrix.element(0, 0) + y() * matrix.element(1, 0) + z() * matrix.element(2, 0);
    double resultY = x() * matrix.element(0, 1) + y() * matrix.element(1, 1) + z() * matrix.element(2, 1);
    double resultZ = x() * matrix.element(0, 2) + y() * matrix.element(1, 2) + z() * matrix.element(2, 2);
    return Geometry::GeomVector(resultX, resultY, resultZ);
}

Geometry::GeomVector Geometry::GeomVector::projectionOnVector(const GeomVector &otherVec) const
{
    double dotProductResult = dotProduct(otherVec);
    double denominator = otherVec.dotProduct(otherVec);

    if (std::abs(denominator) == 0)
    {
        return GeomVector();
    }

    double scalarValue = dotProductResult / denominator;
    return otherVec.multiplyScalar(scalarValue);
}

Geometry::GeomVector Geometry::GeomVector::projectVectorOnPlane(const GeomVector &vector, const GeomVector &planeNormal) const
{
    GeomVector projection = vector.projectionOnVector(planeNormal);
    GeomVector result = vector - projection;
    return result;
}

double Geometry::GeomVector::angleBetweenVectorAndAxis(int axis) const
{
    double dotProductResult = 0.0;
    double vectorMagnitude = magnitude();
    double axisMagnitude = 1.0;
 
    // x-axis calculation
    if (axis == 0)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = x();
    }

    // y-axis calculation
    else if (axis == 1)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = y();
    }

    // z-axis calculation
    else if (axis == 2)
    {
        if (vectorMagnitude == 0.0)
        {
            return 0.0;
        }
        dotProductResult = z();
    }
 
    double angleRadians = std::acos(dotProductResult / (vectorMagnitude * axisMagnitude));
    
    // converting radians to degrees
    return angleRadians * (180.0 / M_PI);
}