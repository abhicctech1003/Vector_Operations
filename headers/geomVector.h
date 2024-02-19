#pragma once
#include "point3D.h"
#include "plane.h"

class geomVector
{
    public:
        geomVector ();
        geomVector(point3D v1, point3D v2,point3D v3 , point3D v4);
        ~geomVector();

        void print(point3D a);

        void sVectorV1(point3D v1);

        void sVectorV2(point3D v2);

        void sVectorV3(point3D v3);

        void sVectorV4(point3D v4);

        point3D vector1();
        point3D vector2();
        point3D vector3();
        point3D vector4();
    
        void vectorsFormed(point3D v1, point3D v2,point3D v3 , point3D v4);

        double dotProduct(point3D v1, point3D v2,point3D v3 , point3D v4);

        point3D crossProduct(point3D v1, point3D v2,point3D v3 , point3D v4);

        point3D vectorAddition(point3D v1, point3D v2,point3D v3 , point3D v4);

        double vectorMagnitude(point3D v1, point3D v2);

        point3D vectorNormalized(point3D v1, point3D v2);

        bool isEqual(point3D v1, point3D v2,point3D v3 , point3D v4);

        point3D addScalar(point3D v1 , point3D v2 , double scalar);

        point3D vectorScalarMultiplication(point3D v1, point3D v2 , double scalar);

        double angleBetweenVectors(point3D v1, point3D v2,point3D v3 , point3D v4);

        double distanceBetweenVectors(point3D v1, point3D v2,point3D v3 , point3D v4);

        point3D subtractScalar(point3D v1 , point3D v2 , double scalar);

        point3D vectorScalarDivision(point3D v1, point3D v2,point3D v3 , point3D v4 , double scalar);

        double angleBetweenPlaneandVector(plane normal , point3D v1 , point3D v2 );

        void directionCosines(point3D v1, point3D v2,point3D v3 , point3D v4);

        double setLength(point3D v1 , point3D v2 , double lenght);


    private:
        point3D mV1;
        point3D mV2;
        point3D mV3;
        point3D mV4;
};