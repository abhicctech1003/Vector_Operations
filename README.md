# Project using computational geometry
# Vector3D, Plane and matrix Classes

This C++ program  inherits from a `Point3D` class, and a `Plane` class to implements a `Vector3D` class. The `Vector3D` class provides various methods for vector operations using computational geometry, while the `Plane` class offers methods for plane operations.

## Vector3D Class

### Methods:

- `double dotProduct(const Vector3D &other) const`: It Calculates the dot product of two vectors.
- `Vector3D crossProduct(const Vector3D &other) const`: It Computes the cross product of two vectors.
- `Vector3D add(const Vector3D &other) const`: It Performs vector addition.
- `double magnitude() const`: It Computes the magnitude of the vector.
- `Vector3D normalize() const`: It Normalizes the vector.
- `bool isEqual(const Vector3D &other) const`: It Checks if two vectors are equal.
- `Vector3D addScalar(double scalar) const`: It Adds a scalar to the vector.
- `Vector3D scalarMultiplication(double scalar) const`: It Performs scalar multiplication on the vector.
- `double angleBetween(const Vector3D &other) const`: It Calculates the angle between two vectors.
- `double angleWithAxis(int axis) const`: It Calculates the angle of the vector with respect to a specified axis.
- `double distanceBetweenVectors(const Vector3D &other) const`: It Computes the distance between two vectors.
- `Vector3D projection(const Vector3D &onto) const`: It Computes the projection of the vector onto another vector.
- `Vector3D directionCosines() const`: It Computes the direction cosines of the vector.
- `Vector3D subtractScalar(double scalar) const`: It Subtracts a scalar from the vector.
- `Vector3D scalarDivision(double scalar) const`: It Divides the vector by a scalar.
- `Vector3D setLength(double newLength) const`: It Sets the length of the vector to a specified value.

## Plane Class

### Methods:

- `double dotProduct(const Vector3D &other) const`: It Calculates the dot product of the plane's normal vector with another vector.
- `Vector3D crossProduct(const Vector3D &other) const`: It Computes the cross product of the plane's normal vector with another vector.
- `Vector3D add(const Vector3D &other) const`: It Performs vector addition with the plane's normal vector.
- `double magnitude() const`: It Computes the magnitude of the plane's normal vector.
- `Vector3D normalize() const`: It Normalizes the plane's normal vector.
- `bool isEqual(const Vector3D &other) const`: It Checks if the plane's normal vector is equal to another vector.
- `Vector3D addScalar(double scalar) const`: It Adds a scalar to the plane's normal vector.
- `Vector3D scalarMultiplication(double scalar) const`: It Multiplies the plane's normal vector by a scalar.
- `double angleBetween(const Vector3D &other) const`: It Calculates the angle between the plane's normal vector and another vector.
- `double angleWithAxis(int axis) const`: It Calculates the angle of the plane's normal vector with respect to a specified axis.
- `double distanceBetweenVectors(const Vector3D &other) const`: It Computes the distance between the plane's normal vector and another vector.
- `Vector3D projection(const Vector3D &onto) const`: It Computes the projection of the plane's normal vector onto another vector.
- `Vector3D directionCosines() const`: It Computes the direction cosines of the plane's normal vector.
- `Vector3D subtractScalar(double scalar) const`: It Subtracts a scalar from the plane's normal vector.
- `Vector3D scalarDivision(double scalar) const`: It Divides the plane's normal vector by a scalar.
- `Vector3D setLength(double newLength) const`: It Sets the length of the plane's normal vector to a specified value.
- `double planeVectorAngle(const Vector3D &vec) const`: It Computes the angle between the plane and another vector.
- `double planeVectorDistance(const Vector3D &vec) const`: It Computes the distance between the plane and another vector.


## Matrix Class

### Methods:

- `Matrix(double a, double b, double c, double d, double e, double f, double g, double h, double i)`: It creates new matrix.
- `double element(int row, int col) const`: It access matrix elements.


## Usage

1. Clone the repository to your local machine.
2. Compile the program using your preferred C++ compiler.
3. Run the compiled program to execute vector and plane operations.


![Dot_Product](![Screenshot (65)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/3bf9ea50-464b-4a8b-9419-22e5a9f0617a)
)
![crossProduct](![Screenshot (66)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/10f9a651-9468-4725-a48a-a7f1e34b71b3)
)
![Vector_Scalar_substraction](![Screenshot (67)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/11de9670-93e2-4688-8741-73435bb3cc69)
)
![vector_scalar_multiplication](![Screenshot (68)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/c7598700-8163-4398-b9db-18764a237db2)
)
![vector_scalar_division](![Screenshot (69)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/94a35fb3-7cad-4115-b4de-04e544a6023f)
)
![vector_matrix_multiplication](![Screenshot (70)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/8d8e3566-1e83-4f3d-a6b3-4b47191e8ca6)
)
![Vector_addition](![Screenshot (71)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/50556b10-6278-4538-93ea-5815fe999930)
)
![setLength_Vector](![Screenshot (72)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/c2920b1e-5b0f-46de-b64c-dd9395e8a256)
)
![scalarAddition_Vetcor](![Screenshot (73)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/1e1e4b0f-d41e-4423-a5d9-0adda69de21a)
)
![ProjectionVector](![Screenshot (74)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/ce2639ba-b887-44a3-aca0-01e21467f61e)
)
![ProjectionPlane](![Screenshot (75)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/1c0aa188-fa75-4971-bd44-1199bbf6a357)
)
![normalised_Vector1](![Screenshot (76)](https://github.com/abhicctech1003/Vector_Operations/assets/158149347/47297e39-c97f-48d4-93ec-5e638e4f5dea)
)

