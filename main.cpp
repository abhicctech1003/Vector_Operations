#include <iostream>
#include <vector>
#include <string>
#include "./headers/vector3D.h"
#include "./headers/writer.h"
#include "./headers/matrix.h"
#include "./headers/plane.h"

int main()
{
    int choice;
    double x, x1;
    double y, y1;
    double z, z1;

    std::cout << "Enter your choice for vector operation: " << std::endl
              << "1. For equality check: " << std::endl
              << "2. For magnitude of vector:" << std::endl
              << "3. To find normalized vector : " << std::endl
              << "4. To Set new VectorLength :" << std::endl
              << "5. For Scalar Vector Addition: " << std::endl
              << "6. For Scalar Vector Substraction: " << std::endl
              << "7. For Scalar Vector Multiplication :" << std::endl
              << "8. For Scalar Vector Division :" << std::endl
              << "9. For Addition vectors: " << std::endl
              << "10. For DotProduct vectors: " << std::endl
              << "11. For CrossProduct vectors: " << std::endl
              << "12. For direction Cosines of vector:" << std::endl
              << "13. For Multiply vector with matrix:" << std::endl
              << "14. For distance between two vectors:" << std::endl
              << "15. For distance between vector and plane" << std::endl
              << "16. For angle between two vectors : " << std::endl
              << "17. For angle between vector and plane: " << std::endl
              << "18. For projection vector : " << std::endl
              << "19. For projection plane " << std::endl
              << "20. For Angle between vector and axis";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::cout << "Enter Value of X, Y, Z for point:" << std::endl;
        std::cin >> x >> y >> z;

        std::cout << "Enter Value of X, Y, Z for point:" << std::endl;
        std::cin >> x1 >> y1 >> z1;

        Geometry::GeomVector a(x, y, z);
        Geometry::GeomVector b(x1, y1, z1);
        if (a == b)
        {
            std::cout << "Two vectors are equal." << std::endl;
        }
        else
        {
            std::cout << "Two vectors are not equal." << std::endl;
        }
    }
    break;
    case 2:
    {
        std::cout << "Enter Value of X, Y, Z for point:" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);
        std::cout << "Magnitude of 2 vector is : " << a.magnitude() << std::endl;
    }
    break;

    case 3:
    {
        std::cout << "Enter Value of X, Y, Z for point:" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        
        Geometry::GeomVector result = a.normalize();
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlotFile.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 4:
    {
        int newLength;
        std::cout << "Enter Value of X, Y, Z for point:" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);

        std::cout << "Enter new length for calculation " << std::endl;
        std::cin >> newLength;
        Geometry::GeomVector result = a.setVectorLength(newLength);

        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }

    case 5:
    {
        int scalarValue;
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter integer value" << std::endl;
        std::cin >> scalarValue;

        Geometry::GeomVector result = a.addScalar(scalarValue);
        std::vector<Geometry::GeomVector> vectors;
        
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 6:
    {
        int scalarValue;
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter integer value" << std::endl;
        std::cin >> scalarValue;

        Geometry::GeomVector result = a.subtractScalar(scalarValue);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;
    case 7:
    {
        int scalarValue;
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter integer value" << std::endl;
        std::cin >> scalarValue;

        Geometry::GeomVector result = a.multiplyScalar(scalarValue);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 8:
    {
        int scalarValue;
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter integer value" << std::endl;
        std::cin >> scalarValue;

        Geometry::GeomVector result = a.divideScalar(scalarValue);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 9:
    {
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector b(x1, y1, z1);

        Geometry::GeomVector result = a + b;
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(b);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 10:
    {
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector b(x1, y1, z1);

        double result = a.dotProduct(b);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(b);
        std::cout << "dot product is " << result << std::endl;
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 11:
    {
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector b(x1, y1, z1);

        Geometry::GeomVector result = a.crossProduct(b);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(b);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 12:
    {
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);
        a.directionCosines();
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
    }
    break;

    case 13:
    {
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        double s, b, c, d, e, f, g, h, i;
        std::cout << "Enter the elements of the 3 x 3 matrix: ";
        std::cin >> s >> b >> c >> d >> e >> f >> g >> h >> i;
        LinearAlgebra::Matrix matrix(s, b, c, d, e, f, g, h, i);

        Geometry::GeomVector result = a.multiplyMatrix(matrix);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlot.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 14:
    {
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter x,y and z value for vector2" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector b(x1, y1, z1);

        double result = a.distanceBetweenVectors(b);
        std::cout << "Distance between two vectors is " << result << std::endl;
    }
    break;

    case 15:
    {
        double x2;
        double y2;
        double z2;
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter x,y and z value for normal" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector normal(x1, y1, z1);

        std::cout << "Enter 3 coordinates for point" << std::endl;
        std::cin >> x2 >> y2 >> z2;
        Geometry::Point3D point(x2, y2, z2);

        Geometry::Plane plane(normal, point);
        double result = a.distanceBetweenVectorAndPlane(plane);
        std::cout << "Distance between vector and plane is " << result << std::endl;
    }
    break;

    case 16:
    {

        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter x,y and z value for normal" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector b(x1, y1, z1);

        double result = a.angleBetweenVectors(b);
        std::cout << "Angle between two vectors is " << result << std::endl;
    }
    break;

    case 17:
    {
        double x2;
        double y2;
        double z2;
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter x,y and z value for normal" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector normal(x1, y1, z1);

        std::cout << "Enter 3 coordinates for point" << std::endl;
        std::cin >> x2 >> y2 >> z2;
        Geometry::Point3D point(x2, y2, z2);

        Geometry::Plane plane(normal, point);
        double result = a.angleBetweenVectorAndPlane(plane);
        std::cout << "angle between vector and plane is " << result << std::endl;
    }
    break;

    case 18:
    {
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter x,y and z value for normal" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector b(x1, y1, z1);

        Geometry::GeomVector result = a.projectionOnVector(b);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(b);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlotFile.txt";
        writer.write(filepath, vectors);
    }
    break;

    case 19:
    {
        double x2;
        double y2;
        double z2;
        std::cout << "Enter Value of X, Y, Z  for Vector 1 :" << std::endl;
        std::cin >> x >> y >> z;
        Geometry::GeomVector a(x, y, z);

        std::cout << "Enter x,y and z value for normal" << std::endl;
        std::cin >> x1 >> y1 >> z1;
        Geometry::GeomVector normal(x1, y1, z1);

        Geometry::GeomVector result = a.projectVectorOnPlane(a, normal);
        std::vector<Geometry::GeomVector> vectors;
        vectors.push_back(a);
        vectors.push_back(normal);
        vectors.push_back(result);
        Geometry::Writer writer;
        std::string filepath = "output/GnuPlotFile.txt";
        writer.write(filepath, vectors);
    }
    break;
    case 20:
        {
            std::cout << "Enter x, y, z value for vector1" << std::endl;
            std::cin >> x >> y >> z;
            Geometry::GeomVector a(x, y, z);
            double result;
            int value;
            std::cout << "enter int value 0, 1 or 2" << std::endl;
            std::cin >> value;
            result = a.angleBetweenVectorAndAxis(value);
        }
        break;
    default:
        break;
    }
    return 0;
}