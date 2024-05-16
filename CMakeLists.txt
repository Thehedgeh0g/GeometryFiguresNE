cmake_minimum_required(VERSION 3.27)
project(GeometryFigures)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME}Test
        Tests/test.cpp
        src/Figure/Shapes/IShape.h
        src/Figure/Shapes/CLineSegment.cpp
        src/Figure/Shapes/CLineSegment.h
        src/Figure/Shapes/CPoint.cpp
        src/Figure/Shapes/CPoint.h
        src/Figure/Shapes/ISolidShape.h
        src/Figure/Shapes/CTriangle.cpp
        src/Figure/Shapes/CTriangle.h
        src/Figure/Common/DistanceCalculation.cpp
        src/Figure/Common/DistanceCalculation.h
        src/Figure/Shapes/CRectangle.cpp
        src/Figure/Shapes/CRectangle.h
        src/Figure/Shapes/CRectangle.h
        src/Figure/Shapes/CCircle.cpp
        src/Figure/Shapes/CCircle.h
        src/Figure/Factory/ShapeFactory.cpp
        src/Figure/Factory/ShapeFactory.h
        src/Figure/Shapes/FigureTypeEnum.h
        src/Figure/Common/ConvertColor.cpp
        src/Figure/Common/ConvertColor.h
        src/Figure/Exceptions/InvalidRectangleWidthHeightException.cpp
        src/Figure/Exceptions/InvalidRectangleWidthHeightException.h
        src/Figure/Exceptions/InvalidTriangleVertexCoords.cpp
        src/Figure/Exceptions/InvalidTriangleVertexCoords.h
        src/Figure/Exceptions/CollinearTriangleVertexCoordsException.cpp
        src/Figure/Exceptions/CollinearTriangleVertexCoordsException.h
        src/Figure/Exceptions/InvalidCircleRadiusException.cpp
        src/Figure/Exceptions/InvalidCircleRadiusException.h
        src/Figure/Exceptions/InvalidLineVertexCoordsException.cpp
        src/Figure/Exceptions/InvalidLineVertexCoordsException.h
        src/Figure/Common/ShapeToStringConverter.h
        src/Figure/Common/ShapeToStringConverter.cpp
        src/Figure/Canvas/CCanvas.h
        src/Figure/Shapes/ICanvasDrawable.h
)

target_link_libraries(${PROJECT_NAME}Test sfml-graphics gtest_main)
enable_testing()
add_test(NAME ${PROJECT_NAME}Test COMMAND ${PROJECT_NAME}Test)

add_executable(${PROJECT_NAME} main.cpp
        src/Figure/Shapes/IShape.h
        src/Figure/Shapes/CLineSegment.cpp
        src/Figure/Shapes/CLineSegment.h
        src/Figure/Shapes/CPoint.cpp
        src/Figure/Shapes/CPoint.h
        src/Figure/Shapes/ISolidShape.h
        src/Figure/Shapes/CTriangle.cpp
        src/Figure/Shapes/CTriangle.h
        src/Figure/Common/DistanceCalculation.cpp
        src/Figure/Common/DistanceCalculation.h
        src/Figure/Shapes/CRectangle.cpp
        src/Figure/Shapes/CRectangle.h
        src/Figure/Shapes/CCircle.cpp
        src/Figure/Shapes/CCircle.h
        src/Figure/Factory/ShapeFactory.cpp
        src/Figure/Factory/ShapeFactory.h
        src/Figure/Shapes/FigureTypeEnum.h
        src/Figure/Common/ConvertColor.cpp
        src/Figure/Common/ConvertColor.h
        src/Figure/Exceptions/InvalidRectangleWidthHeightException.cpp
        src/Figure/Exceptions/InvalidRectangleWidthHeightException.h
        src/Figure/Exceptions/CollinearTriangleVertexCoordsException.cpp
        src/Figure/Exceptions/CollinearTriangleVertexCoordsException.h
        src/Figure/Exceptions/InvalidCircleRadiusException.cpp
        src/Figure/Exceptions/InvalidCircleRadiusException.h
        src/Figure/Exceptions/InvalidLineVertexCoordsException.cpp
        src/Figure/Exceptions/InvalidLineVertexCoordsException.h
        src/Figure/Exceptions/InvalidTriangleVertexCoords.cpp
        src/Figure/Exceptions/InvalidTriangleVertexCoords.h
        src/Figure/Canvas/ICanvas.h
        src/Figure/Common/ShapeToStringConverter.cpp
        src/Figure/Common/ShapeToStringConverter.h
        src/Figure/Canvas/CCanvas.cpp
        src/Figure/Canvas/CCanvas.h
        src/Figure/Shapes/ICanvasDrawable.h
        src/Figure/ShapeController.cpp
        src/Figure/ShapeController.h
        src/Figure/Service/ShapeService.cpp
        src/Figure/Service/ShapeService.h
)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
