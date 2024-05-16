//
// Created by flipd on 19.04.2024.
//
#include <gtest/gtest.h>
#include "../src/Figure/Shapes/CPoint.h"
#include "../src/Figure/Shapes/CTriangle.h"
#include "../src/Figure/Exceptions/CollinearTriangleVertexCoordsException.h"
#include "../src/Figure/Shapes/CCircle.h"
#include "../src/Figure/Exceptions/InvalidCircleRadiusException.h"
#include "../src/Figure/Shapes/CLineSegment.h"
#include "../src/Figure/Exceptions/InvalidLineVertexCoordsException.h"
#include "../src/Figure/Shapes/CRectangle.h"
#include "../src/Figure/Exceptions/InvalidRectangleWidthHeightException.h"
#include "../src/Figure/Exceptions/InvalidTriangleVertexCoords.h"
#include "../src/Figure/Factory/ShapeFactory.h"
#include "../src/Figure/Common/ConvertColor.h"

TEST(CTriangleTest, CanNotCreateTriangleWithCollinearPoints)
{
    CPoint vertex1(0, 0);
    CPoint vertex2(1, 1);
    CPoint vertex3(2, 2);

    ASSERT_THROW(CTriangle triangle
        (
            vertex1,
            vertex2,
            vertex3,
            0xFF0000,
            0x00FF00
        ),
                 CollinearTriangleVertexCoordsException
    );
}

TEST(CTriangleTest, CanNotCreateTriangleWithIdentPoints)
{
    CPoint vertex1(0, 0);
    CPoint vertex2(2, 2);

    ASSERT_THROW(CTriangle triangle
        (
            vertex1,
            vertex1,
            vertex2,
            0xFF0000,
            0x00FF00
        ),
                 InvalidTriangleVertexCoords
    );

    ASSERT_THROW(CTriangle triangle
        (
            vertex1,
            vertex2,
            vertex1,
            0xFF0000,
            0x00FF00
        ),
                 InvalidTriangleVertexCoords
    );

    ASSERT_THROW(CTriangle triangle
        (
            vertex1,
            vertex2,
            vertex2,
            0xFF0000,
            0x00FF00
        ),
                 InvalidTriangleVertexCoords
    );

    ASSERT_THROW(CTriangle triangle
        (
            vertex1,
            vertex1,
            vertex1,
            0xFF0000,
            0x00FF00
        ),
                 InvalidTriangleVertexCoords
    );
}

TEST(CTriangleTest, SuccessfullCreateTriangle)
{
    CPoint vertex1(0, 0);
    CPoint vertex2(1, 0);
    CPoint vertex3(2, 2);

    ASSERT_NO_THROW(CTriangle triangle
        (
            vertex1,
            vertex2,
            vertex3,
            0xFF0000,
            0x00FF00
        )
    );
}

TEST(CCircleTest, CanNotCreateCirlceWithNegativeRadius)
{
    ASSERT_THROW(CCircle circle
        (
            CPoint(0, 0),
            -5.0,
            0xFF0000,
            0x00FF00
        ),
                 InvalidCircleRadiusException
    );
}

TEST(CCircleTest, CanNotCreateCirlceWithZeroRadius)
{
    ASSERT_THROW(CCircle circle
        (
            CPoint(0, 0),
            0.0,
            0xFF0000,
            0x00FF00
        ),
                 InvalidCircleRadiusException
    );
}

TEST(CCircleTest, SuccessfullCreateCirlceWithPositiveRadius)
{
    ASSERT_NO_THROW(CCircle circle
        (
            CPoint(0, 0),
            5.0,
            0xFF0000,
            0x00FF00
        )
    );
}

TEST(CLineTest, CanNotCreateLineWithSameStartAndEndPoints)
{
    ASSERT_THROW(CLineSegment line
        (
            CPoint(0, 0),
            CPoint(0, 0),
            0xFF0000
        ),
                 InvalidLineVertexCoordsException
    );
}

TEST(CLineTest, SuccessfullCreateLineWithDifferentStartAndEndPoints)
{
    ASSERT_NO_THROW(CLineSegment line
        (
            CPoint(0, 0),
            CPoint(1, 1),
            0xFF0000
        )
    );
}

TEST(CLineTest, CanNotCreateRectangleWithZeroWidthOrHeight)
{
    ASSERT_THROW(CRectangle rectangle
        (
            CPoint(0, 0),
            0,
            32,
            0xFF0000,
            0xFF0000
        ),
                 InvalidRectangleWidthHeightException
    );

    ASSERT_THROW(CRectangle rectangle
        (
            CPoint(0, 0),
            2,
            0,
            0xFF0000,
            0xFF0000
        ),
                 InvalidRectangleWidthHeightException
    );
}

TEST(CLineTest, CanNotCreateRectangleWithNegativeWidthOrHeight)
{
    ASSERT_THROW(CRectangle rectangle
        (
            CPoint(0, 0),
            -2,
            32,
            0xFF0000,
            0xFF0000
        ),
                 InvalidRectangleWidthHeightException
    );

    ASSERT_THROW(CRectangle rectangle
        (
            CPoint(0, 0),
            2,
            -2,
            0xFF0000,
            0xFF0000
        ),
                 InvalidRectangleWidthHeightException
    );
}

TEST(CLineTest, SuccessfullCreateRectangle)
{
    ASSERT_NO_THROW(CRectangle rectangle
        (
            CPoint(0, 0),
            0xFF0000,
            0xFF0000,
            2,
            32
        )
    );
}

TEST(FigureParserTest, CorrectCircleCreation)
{
    ShapeFactory figureParser;
    std::string circleData = "circle 1 2 3 0xcf00aaff 0xcf00aaff";
    ASSERT_NO_THROW(figureParser.CreateShape(circleData));
}

TEST(FigureParserTest, IncorrectCircleRadius)
{
    ShapeFactory figureParser;
    std::string incorrectCircleData = "circle 1 2 -3 0xcf00aaff 0xcf00aaff";
    ASSERT_THROW(figureParser.CreateShape(incorrectCircleData), InvalidCircleRadiusException);
}

TEST(FigureParserTest, CorrectRectangleCreation)
{
    ShapeFactory figureParser;
    std::string rectangleData = "rectangle 1 2 3 4 0xcf00aaff 0xcf00aaff";
    ASSERT_NO_THROW(figureParser.CreateShape(rectangleData));
}

TEST(FigureParserTest, IncorrectRectangleWidthHeight)
{
    ShapeFactory figureParser;
    std::string incorrectRectangleData = "rectangle 1 2 -3 4 0xcf00aaff 0xcf00aaff";
    ASSERT_THROW(figureParser.CreateShape(incorrectRectangleData), InvalidRectangleWidthHeightException);
}

TEST(FigureParserTest, CorrectTriangleCreation)
{
    ShapeFactory figureParser;
    std::string triangleData = "triangle 1 1 3 5 0 0 0xcf00aaff 0xcf00aaff";
    ASSERT_NO_THROW(figureParser.CreateShape(triangleData));
}

TEST(FigureParserTest, CollinearTriangleVertices)
{
    ShapeFactory figureParser;
    std::string collinearTriangleData = "triangle 1 1 2 2 3 3 0xcf00aaff 0xcf00aaff";
    ASSERT_THROW(figureParser.CreateShape(collinearTriangleData), CollinearTriangleVertexCoordsException);
}

TEST(FigureParserTest, IncorrectTriangleVertices)
{
    ShapeFactory figureParser;
    std::string incorrectTriangleData = "triangle 1 1 1 1 1 1 0xcf00aaff 0xcf00aaff";
    ASSERT_THROW(figureParser.CreateShape(incorrectTriangleData), InvalidTriangleVertexCoords);
}

TEST(FigureParserTest, CorrectLineCreation)
{
    ShapeFactory figureParser;
    std::string lineData = "line 1 1 3 1 0xcf00aaff 0xcf00aaff";
    ASSERT_NO_THROW(figureParser.CreateShape(lineData));
}

TEST(FigureParserTest, SameStartAndEndPoints)
{
    ShapeFactory figureParser;
    std::string samePointsLineData = "line 1 1 1 1 0xcf00aaff";
    ASSERT_THROW(figureParser.CreateShape(samePointsLineData), InvalidLineVertexCoordsException);
}

TEST(ColorParserTest, ParseColorCode_InvalidColorCodeCharacters)
{
    std::string invalidColorCode = "#GG0000";
    ASSERT_THROW(ConvertColor::ConvertColor::ParseColorCode(invalidColorCode), std::invalid_argument);
}

TEST(ColorParserTest, ColorCodeToString_ValidColor)
{
    uint32_t color = 0xcf00aaff;
    std::string expectedColorCode = "0xcf00aaff";
    ASSERT_EQ(ConvertColor::ColorCodeToString(color), expectedColorCode);
}

TEST(ColorParserTest, ColorCodeToString_InvalidColor)
{
    uint32_t color = 0xcf00aaff;
    ASSERT_EQ(ConvertColor::ColorCodeToString(color), "0xcf00aaff");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
