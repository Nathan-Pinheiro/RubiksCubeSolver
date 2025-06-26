#include "OptimizedCube.hpp"

#include <iostream>

std::vector<Color> MIDDLES = {WHITE, GREEN, RED, BLUE, ORANGE, YELLOW};

std::vector<std::pair<Color, Color>> EDGES = 
{
    std::make_pair(WHITE, GREEN),
    std::make_pair(RED, WHITE),
    std::make_pair(WHITE, BLUE),
    std::make_pair(ORANGE, WHITE),
    std::make_pair(RED, GREEN),
    std::make_pair(BLUE, RED),
    std::make_pair(ORANGE, BLUE),
    std::make_pair(GREEN, ORANGE),
    std::make_pair(GREEN, YELLOW),
    std::make_pair(YELLOW, RED),
    std::make_pair(BLUE, YELLOW),
    std::make_pair(YELLOW, ORANGE),
};

std::vector<std::tuple<Color, Color, Color>> CORNERS = 
{
    std::make_tuple(GREEN, WHITE, RED),
    std::make_tuple(RED, WHITE, BLUE),
    std::make_tuple(BLUE, WHITE, ORANGE),
    std::make_tuple(ORANGE, WHITE, GREEN),
    std::make_tuple(GREEN, YELLOW, RED),
    std::make_tuple(RED, YELLOW, BLUE),
    std::make_tuple(BLUE, YELLOW, ORANGE),
    std::make_tuple(ORANGE, YELLOW, GREEN),
};

OptimizedCube::OptimizedCube()
{
    middles = {0, 1, 2, 3, 4, 5};
    edges = 
    {
        std::make_pair(0, 0),
        std::make_pair(1, 0),
        std::make_pair(2, 0),
        std::make_pair(3, 0),
        std::make_pair(4, 1),
        std::make_pair(5, 1),
        std::make_pair(6, 1),
        std::make_pair(7, 1),
        std::make_pair(8, 0),
        std::make_pair(9, 0),
        std::make_pair(10, 0),
        std::make_pair(11, 0),
    };

    corners = 
    {
        std::make_pair(0, 0),
        std::make_pair(1, 1),
        std::make_pair(2, 2),
        std::make_pair(3, 1),
        std::make_pair(4, 1),
        std::make_pair(5, 2),
        std::make_pair(6, 1),
        std::make_pair(7, 0),
    };
}

bool OptimizedCube::isSolved()
{
    for (size_t i = 0; i < middles.size(); ++i)
    {
        if (middles[i] != i) return false;
    }

    for (size_t i = 0; i < edges.size(); ++i)
    {
        if (edges[i].first != i || edges[i].second != 0) return false; 
    }

    for (size_t i = 0; i < corners.size(); ++i)
    {
        if (corners[i].first != i || corners[i].second != 0) return false;
    }

    return true;
}

Color getEdgeColor(std::pair<int, int> edgeIndex, int face)
{
    std::pair<Color, Color> edge = EDGES[edgeIndex.first];
    if (edgeIndex.second == face) return edge.first;
    else return edge.second;
}

Color getCornerColor(std::pair<int, int> cornerIndex, int face)
{
    std::tuple<Color, Color, Color> corner = CORNERS[cornerIndex.first];

    if (cornerIndex.second == face) return std::get<0>(corner);
    else if ((cornerIndex.second + 1) % 3 == face) return std::get<1>(corner);
    else return std::get<2>(corner);
}

void OptimizedCube::show() 
{
    // Top face
    std::cout << "          " << getColoredSquare(getCornerColor(corners[3], 2)) << " " << getColoredSquare(getEdgeColor(edges[3], 1))<< " " << getColoredSquare(getCornerColor(corners[2], 0)) << std::endl;
    std::cout << "          " << getColoredSquare(getEdgeColor(edges[0], 0)) << " " << getColoredSquare(MIDDLES[middles[0]])<< " " << getColoredSquare(getEdgeColor(edges[2], 0)) << std::endl;
    std::cout << "          " << getColoredSquare(getCornerColor(corners[0], 1)) << " " << getColoredSquare(getEdgeColor(edges[1], 1))<< " " << getColoredSquare(getCornerColor(corners[1], 2)) << std::endl;

    // Left, Front, Right, Back faces
    std::cout << " " << getColoredSquare(getCornerColor(corners[3], 0)) << " " << getColoredSquare(getEdgeColor(edges[0], 1))<< " " << getColoredSquare(getCornerColor(corners[0], 0));
    std::cout << " " << getColoredSquare(getCornerColor(corners[0], 2)) << " " << getColoredSquare(getEdgeColor(edges[1], 0))<< " " << getColoredSquare(getCornerColor(corners[1], 1));
    std::cout << " " << getColoredSquare(getCornerColor(corners[1], 0)) << " " << getColoredSquare(getEdgeColor(edges[2], 1))<< " " << getColoredSquare(getCornerColor(corners[2], 2));
    std::cout << " " << getColoredSquare(getCornerColor(corners[2], 1)) << " " << getColoredSquare(getEdgeColor(edges[3], 0))<< " " << getColoredSquare(getCornerColor(corners[3], 1)) << std::endl;

    std::cout << " " << getColoredSquare(getEdgeColor(edges[7], 1)) << " " << getColoredSquare(MIDDLES[middles[1]]) << " " << getColoredSquare(getEdgeColor(edges[4], 0));
    std::cout << " " << getColoredSquare(getEdgeColor(edges[4], 1)) << " " << getColoredSquare(MIDDLES[middles[2]]) << " " << getColoredSquare(getEdgeColor(edges[5], 0));
    std::cout << " " << getColoredSquare(getEdgeColor(edges[5], 1)) << " " << getColoredSquare(MIDDLES[middles[3]]) << " " << getColoredSquare(getEdgeColor(edges[6], 0));
    std::cout << " " << getColoredSquare(getEdgeColor(edges[6], 1)) << " " << getColoredSquare(MIDDLES[middles[4]]) << " " << getColoredSquare(getEdgeColor(edges[7], 0)) << std::endl;

    std::cout << " " << getColoredSquare(getCornerColor(corners[7], 2)) << " " << getColoredSquare(getEdgeColor(edges[8], 0))<< " " << getColoredSquare(getCornerColor(corners[4], 1));
    std::cout << " " << getColoredSquare(getCornerColor(corners[4], 0)) << " " << getColoredSquare(getEdgeColor(edges[9], 1))<< " " << getColoredSquare(getCornerColor(corners[5], 2));
    std::cout << " " << getColoredSquare(getCornerColor(corners[5], 1)) << " " << getColoredSquare(getEdgeColor(edges[10], 0))<< " " << getColoredSquare(getCornerColor(corners[6], 1));
    std::cout << " " << getColoredSquare(getCornerColor(corners[6], 0)) << " " << getColoredSquare(getEdgeColor(edges[11], 1))<< " " << getColoredSquare(getCornerColor(corners[7], 0)) << std::endl;

    // Bottom face
    std::cout << "          " << getColoredSquare(getCornerColor(corners[4], 2)) << " " << getColoredSquare(getEdgeColor(edges[9], 0))<< " " << getColoredSquare(getCornerColor(corners[5], 0)) << std::endl;
    std::cout << "          " << getColoredSquare(getEdgeColor(edges[8], 1)) << " " << getColoredSquare(MIDDLES[middles[5]])<< " " << getColoredSquare(getEdgeColor(edges[10], 1)) << std::endl;
    std::cout << "          " << getColoredSquare(getCornerColor(corners[7], 1)) << " " << getColoredSquare(getEdgeColor(edges[11], 0))<< " " << getColoredSquare(getCornerColor(corners[6], 2)) << std::endl;
}

void OptimizedCube::F() 
{
    // Swap corners
    std::swap(corners[1], corners[0]);
    std::swap(corners[0], corners[4]);
    std::swap(corners[4], corners[5]);

    corners[0].second = (corners[0].second + 1) % 3;
    corners[1].second = (corners[1].second + 2) % 3;
    corners[5].second = (corners[5].second + 2) % 3;
    corners[4].second = (corners[4].second + 1) % 3;

    // Swap edges
    std::swap(edges[4], edges[9]);
    std::swap(edges[9], edges[5]);
    std::swap(edges[5], edges[1]);
    
    edges[1].second = (edges[3].second + 1) % 2;
    edges[5].second = (edges[2].second + 1) % 2;
    edges[8].second = (edges[1].second + 1) % 2;
    edges[4].second = (edges[0].second + 1) % 2;
}

void OptimizedCube::FPrime() 
{

}

void OptimizedCube::B() 
{

}

void OptimizedCube::BPrime() 
{

}

void OptimizedCube::U() 
{
    // Swap corners
    std::swap(corners[0], corners[1]);
    std::swap(corners[1], corners[2]);
    std::swap(corners[2], corners[3]);

    corners[3].second = (corners[3].second + 1) % 3;
    corners[2].second = (corners[2].second + 1) % 3;
    corners[1].second = (corners[1].second + 2) % 3;
    corners[0].second = (corners[0].second + 2) % 3;

    // Swap edges
    std::swap(edges[0], edges[1]);
    std::swap(edges[1], edges[2]);
    std::swap(edges[2], edges[3]);

    edges[3].second = (edges[3].second + 1) % 2;
    edges[2].second = (edges[2].second + 1) % 2;
    edges[1].second = (edges[1].second + 1) % 2;
    edges[0].second = (edges[0].second + 1) % 2;
}

void OptimizedCube::UPrime()
{
    
}

void OptimizedCube::D() 
{

}

void OptimizedCube::DPrime() 
{

}

void OptimizedCube::R() 
{

}

void OptimizedCube::RPrime() 
{

}

void OptimizedCube::L() 
{

}

void OptimizedCube::LPrime() 
{

}