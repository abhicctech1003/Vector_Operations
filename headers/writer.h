#pragma once
#include <string>
#include <vector>
#include "vector3D.h"
namespace Geometry
{
    class Writer
    {
    public:
        // To write vector geometry to file
        void write(std::string &filePath,std::vector<GeomVector> &vectors);
    };
}