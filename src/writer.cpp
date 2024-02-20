#include <fstream>
#include <stdexcept>
#include <iostream>
#include "../headers/writer.h"

void Geometry ::Writer ::write(std::string &filePath,std::vector<GeomVector> &vectors)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        std::cout << "Error opening the file.!"<<std::endl;
    }

    
    for (const GeomVector &vector : vectors)
    {
        
        outFile<<0.0<<" "<<0.0<<" "<<0.0<<std::endl;
        outFile <<vector.x() << " " << vector.y() << " " << vector.z() << std::endl;
        
    }
    std::cout<<"Vector data written successfully..!"<<std::endl;
    
    outFile.close();
}
