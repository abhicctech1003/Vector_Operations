#pragma once
#include <cmath>
#include "point3D.h"
#include "matrix.h"

namespace Geometry
{
 class Plane;
    class GeomVector : public Point3D
    {
        public:
            GeomVector();
            GeomVector(double x, double y, double z);
            ~GeomVector();

            // isEqual for equality check
            bool operator == (const GeomVector &vec) const;           

            // magnitude
            double magnitude() const;                        

            // for normalisation
            GeomVector normalize() const;                     

            // to calculate dot product
            double dotProduct(const GeomVector &vec) const;        

            // to calculate cross Product
            GeomVector crossProduct(const GeomVector &vec) const;  

            // to calculate addition operartion
            GeomVector operator + (const GeomVector &vec) const;       

            // to calculate subtraction operartion
            GeomVector operator - (const GeomVector &vec) const;

            // to calculate multiplication operartion
            GeomVector operator * (const GeomVector &vec) const;

            // to calculate division operartion
            GeomVector operator / (const GeomVector &vec) const;

            // for setting lenght opeartion
            GeomVector setVectorLength(double newLength) const;

            // To add scalar opeartion
            GeomVector addScalar(double scalar) const;

            // For subtraction of scalar 
            GeomVector subtractScalar(double scalar) const;

            // For multiplication of scalar
            GeomVector multiplyScalar(double scalar) const;          

            // For division of scalar
            GeomVector divideScalar(double scalar) const;

            // To calculate distance between two vector
            double distanceBetweenVectors(const GeomVector &vec) const; 

            // To calculate distance between vector and plane
            double distanceBetweenVectorAndPlane(const Geometry::Plane &plane) const;

            // To calculate angle between vector 
            double angleBetweenVectors(const GeomVector &vec) const;   

            // To calculate angle between  vector and plane 
            double angleBetweenVectorAndPlane(const Geometry::Plane &plane) const;        

            // To calculate angle between vector and axis
            void angleBetweenVectorAndAxis() const;                
        
            // For matrix multiplication
            GeomVector multiplyMatrix(const LinearAlgebra::Matrix &matrix) const;

            // For calculationg projection vector
            GeomVector projectionOnVector(const GeomVector &otherVector) const;       

            // For calculating projection vector on plane
            GeomVector projectVectorOnPlane(const GeomVector &vector,const GeomVector &planeNormal) const; 

            // For dirction cosine
            void directionCosines() const;    

            // To calculate angle between vector and axis
            double angleBetweenVectorAndAxis(int axis) const;

    };
}
