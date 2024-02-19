#include <iostream>
#include <fstream>
#include "headers/point3D.h"
#include "headers/geomVector.h"
using namespace std;

point3D inputPoint(const string &prompt)
{
    double x, y, z;
    cout << prompt << endl;
    cout << "Enter x coordinate: ";
    cin >> x;
    cout << "Enter y coordinate: ";
    cin >> y;
    cout << "Enter z coordinate: ";
    cin >> z;
    return point3D(x, y, z);
}

int main()
{
    // Instance creation of geomVector
    geomVector vector3d; 

    int choice;
    cout << "Enter your choice:" << endl;
    cout << "1. For Dot Product:" << endl;
    cout << "2. For Cross Product:" << endl;
    cout << "3. For Vector Magnitude:" << endl;
    cout << "4. For Vector Normalized:" << endl;
    cout << "5. For Is Equal:" << endl;
    cout << "6. For Add Scalar:" << endl;
    cout << "7. For Vector Scalar Multiplication:" << endl;
    cout << "8. For Angle Between Vectors:" << endl;
    cout << "9. For Distance Between Vectors:" << endl;
    cout << "10. For Subtract Scalar:" << endl;
    cout << "11. For Vector Scalar Division:" << endl;
    cout << "12. For Angle Between Plane and Vector:" << endl;
    cout << "13. For Direction Cosines:" << endl;

    cin >> choice;

    point3D v1, v2, v3, v4;

    ofstream input1("input1.txt");

    ofstream input2("input2.txt");

    ofstream out("path.txt");

    // Taking input for the vector points
    cout << "Enter coordinates for vector 1:" << endl;

    switch (choice)
    {
    case 1:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Input for Vector 3");
        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Input for Vector 4");
        cout << "Dot Product is: " << vector3d.dotProduct(v1, v2, v3, v4) << endl;
        break;
    }

    case 2:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        input1 << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Input for Vector 3");
        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Input for Vector 4");
        input2 << v3.x() << " " << v3.y() << " " << v3.z() << " " << v4.x() << " " << v4.y() << " " << v4.z() << " " << endl;
        point3D ans = vector3d.crossProduct(v1, v2, v3, v4);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl;
        break;
    }

    case 3:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        cout << "Vector Magnitude is: " << vector3d.vectorMagnitude(v1, v2) << endl;
        break;
    }

    case 4:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        input1 << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vector3d.vectorNormalized(v1, v2);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl;
        break;
    }

    case 5:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        cout << "Is Equal: " << (vector3d.isEqual(v1, v2, v3, v4) ? "true" : "false") << endl;
        break;
    }

    case 6:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        input1 << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vector3d.addScalar(v1, v2, 5);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl; 
        break;
    }

    case 7:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        input1 << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vector3d.vectorScalarMultiplication(v1, v2, 7);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl; 
        break;
    }
    case 8:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        cout << "Angle Between Vectors: " << vector3d.angleBetweenVectors(v1, v2, v3, v4) << endl;
        break;
    }

    case 9:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        cout << "Distance Between Vectors: " << vector3d.distanceBetweenVectors(v1, v2, v3, v4) << endl;
        break;
    }

    case 10:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        input1 << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        point3D ans = vector3d.subtractScalar(v1, v2, 5);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl; 
        break;
    }

    case 11:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        input1 << v1.x() << " " << v1.y() << " " << v1.z() << " " << v2.x() << " " << v2.y() << " " << v2.z() << " " << endl;
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Input for Vector 3");
        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Input for Vector 4");
        input2 << v3.x() << " " << v3.y() << " " << v3.z() << " " << v4.x() << " " << v4.y() << " " << v4.z() << " " << endl;
        point3D ans = vector3d.vectorScalarDivision(v1, v2, v3, v4, 5);
        out << ans.x() << " " << ans.y() << " " << ans.z() << " " << 0 << " " << 0 << " " << 0 << " " << endl; 
        break;
    }

    case 12:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        cout << "Angle Between Plane and Vector is: " << vector3d.angleBetweenPlaneandVector(plane(), v1, v2) << endl;
        break;
    }

    case 13:
    {
        v1 = inputPoint("Input for Vector 1");
        cout << "Enter coordinates for vector 2:" << endl;
        v2 = inputPoint("Input for Vector 2");
        cout << "Enter coordinates for vector 3:" << endl;
        v3 = inputPoint("Input for Vector 3");
        cout << "Enter coordinates for vector 4:" << endl;
        v4 = inputPoint("Input for Vector 4");
        vector3d.directionCosines(v1, v2, v3, v4);
        break;
    }

    default:
        cout << "Invalid choice given!" << endl;
    }

    return 0;
}
