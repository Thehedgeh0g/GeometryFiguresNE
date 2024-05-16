//
// Created by flipd on 10.05.2024.
//

#include <stdexcept>
#include <algorithm>
#include "ShapeService.h"
#include "../Factory/ShapeFactory.h"

void ShapeService::ConstructShape(const std::string& line)
{
    std::shared_ptr shape = ShapeFactory::CreateShape(line);

    if (shape == nullptr)
    {
        throw std::runtime_error("Unknown shape");
    }

    m_shapes.emplace_back(shape);
}

std::shared_ptr<IShape> ShapeService::GetShapeWithMaxArea() const
{
    if (m_shapes.empty())
    {
        return nullptr;
    }

    auto maxAreaShape = *std::max_element(m_shapes.begin(), m_shapes.end(),
                                          [](const auto& a, const auto& b) { return a->GetArea() < b->GetArea(); });

    return maxAreaShape;
}

std::shared_ptr<IShape> ShapeService::GetShapeWithMinPerimeter() const
{
    if (m_shapes.empty())
    {
        return nullptr;
    }

    auto minPerimeterShape = *std::min_element(m_shapes.begin(), m_shapes.end(),
                                               [](const auto& a, const auto& b) {
                                                   return a->GetPerimeter() < b->GetPerimeter();
                                               });

    return minPerimeterShape;
}

void ShapeService::RenderShapes()
{
    auto window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode({WIDTH_WINDOW, HEIGHT_WINDOW}),
        TITLE_WINDOW);
    m_canvas = std::make_shared<CCanvas>(window);

    while (window->isOpen())
    {
        sf::Event event = window->pollEvent();
        if (event.is<sf::Event::Closed>())
        {
            window->close();
        }
        window->clear(sf::Color::White);

        for (auto const& shape: m_shapes)
        {
            shape->Draw(m_canvas);
        }
        window->display();
    }
}
