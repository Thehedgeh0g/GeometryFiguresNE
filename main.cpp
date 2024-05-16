#include <tuple>
#include <iostream>
#include <fstream>
#include "src/Figure/Factory/ShapeFactory.h"
#include "src/Figure/Canvas/CCanvas.h"
#include "src/Figure/Shapes/ICanvasDrawable.h"
#include "src/Figure/Service/ShapeService.h"
#include "src/Figure/ShapeController.h"

void PrintInstruction()
{
    std::cout << "data format:\n"
                 "rectangle {right_top_vertex.x} {right_top_vertex.y} {left_bottom_vertex.x} {left_bottom_vertex.y} {outline_color} {fill_color}\n"
                 "circle {center.x} {center.y} {radius} {outline_color} {fill_color}\n"
                 "triangle {vertex1.x} {vertex1.y} {vertex2.x} {vertex2.y} {vertex3.x} {vertex3.y} {outline_color} {fill_color}\n"
                 "line {vertex1.x} {vertex1.y} {vertex2.x} {vertex2.y} {outline_color}\n"
                 "To exit enter empty string\n";
}

void ParseArgs(int argc, char* argv[], std::string& inFilePath)
{
    if (argc != 2)
    {
        throw std::invalid_argument("Invalid arguments count\nUsage: <input_file_name>");
    }
    inFilePath = argv[1];
}

int main(int argc, char* argv[])
{
    PrintInstruction();
    ShapeService shapeService;

    std::string figureData;
    system("cls");
    std::string inFilePath;
    ParseArgs(argc, argv, inFilePath);
    std::ifstream inFile(inFilePath);
    ShapeController shapeController = {inFile, std::cout, shapeService};
    shapeController.ReadShapes();
    shapeController.PrintShapeWithMaxAreaInfo();
    shapeController.RenderShapes();

    return 0;
}
/*
 * rectangle 10.3 20.15 30.7 40.4 #ff0000 #00ff00
 * circle 2.5 3 1 #ff0000 #00ff00
 */