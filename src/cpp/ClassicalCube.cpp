#include "ClassicalCube.hpp"

#include <iostream>

bool ClassicalCube::isSolved()
{
    for (const auto& face : faces)
    {
        Color firstColor = face[0];
        for (const auto& square : face)
        {
            if (square != firstColor)
            {
                return false;
            }
        }
    }
    return true;
}

void ClassicalCube::show() 
{
    // Top face
    std::cout << "          " << getColoredSquare(faces[0][0]) << " " << getColoredSquare(faces[0][1])<< " " << getColoredSquare(faces[0][2]) << std::endl;
    std::cout << "          " << getColoredSquare(faces[0][3]) << " " << getColoredSquare(faces[0][4])<< " " << getColoredSquare(faces[0][5]) << std::endl;
    std::cout << "          " << getColoredSquare(faces[0][6]) << " " << getColoredSquare(faces[0][7])<< " " << getColoredSquare(faces[0][8]) << std::endl;

    // Left, Front, Right, Back faces
    std::cout << " " << getColoredSquare(faces[1][0]) << " " << getColoredSquare(faces[1][1]) << " " << getColoredSquare(faces[1][2]);
    std::cout << " " << getColoredSquare(faces[2][0]) << " " << getColoredSquare(faces[2][1]) << " " << getColoredSquare(faces[2][2]);
    std::cout << " " << getColoredSquare(faces[3][0]) << " " << getColoredSquare(faces[3][1]) << " " << getColoredSquare(faces[3][2]);
    std::cout << " " << getColoredSquare(faces[4][0]) << " " << getColoredSquare(faces[4][1]) << " " << getColoredSquare(faces[4][2]) << std::endl;

    std::cout << " " << getColoredSquare(faces[1][3]) << " " << getColoredSquare(faces[1][4]) << " " << getColoredSquare(faces[1][5]);
    std::cout << " " << getColoredSquare(faces[2][3]) << " " << getColoredSquare(faces[2][4]) << " " << getColoredSquare(faces[2][5]);
    std::cout << " " << getColoredSquare(faces[3][3]) << " " << getColoredSquare(faces[3][4]) << " " << getColoredSquare(faces[3][5]);
    std::cout << " " << getColoredSquare(faces[4][3]) << " " << getColoredSquare(faces[4][4]) << " " << getColoredSquare(faces[4][5]) << std::endl;

    std::cout << " " << getColoredSquare(faces[1][6]) << " " << getColoredSquare(faces[1][7]) << " " << getColoredSquare(faces[1][8]);
    std::cout << " " << getColoredSquare(faces[2][6]) << " " << getColoredSquare(faces[2][7]) << " " << getColoredSquare(faces[2][8]);
    std::cout << " " << getColoredSquare(faces[3][6]) << " " << getColoredSquare(faces[3][7]) << " " << getColoredSquare(faces[3][8]);
    std::cout << " " << getColoredSquare(faces[4][6]) << " " << getColoredSquare(faces[4][7]) << " " << getColoredSquare(faces[4][8]) << std::endl;

    // Bottom face
    std::cout << "          " << getColoredSquare(faces[5][0]) << " " << getColoredSquare(faces[5][1])<< " " << getColoredSquare(faces[5][2]) << std::endl;
    std::cout << "          " << getColoredSquare(faces[5][3]) << " " << getColoredSquare(faces[5][4])<< " " << getColoredSquare(faces[5][5]) << std::endl;
    std::cout << "          " << getColoredSquare(faces[5][6]) << " " << getColoredSquare(faces[5][7])<< " " << getColoredSquare(faces[5][8]) << std::endl;
}

void rotateClockwise(std::array<Color, 9>& side) 
{
    std::swap(side[0], side[2]);
    std::swap(side[8], side[6]);
    std::swap(side[0], side[8]);
    std::swap(side[1], side[5]);
    std::swap(side[3], side[7]);
    std::swap(side[1], side[7]);
};

void rotateCounterClockwise(std::array<Color, 9>& side) 
{
    std::swap(side[0], side[6]);
    std::swap(side[1], side[3]);
    std::swap(side[2], side[0]);
    std::swap(side[5], side[1]);
    std::swap(side[8], side[2]);
    std::swap(side[7], side[5]);
};

// FINE
void ClassicalCube::F() 
{
    rotateClockwise(faces[2]);

    for (int i = 0; i < 3; ++i) 
    {
        std::swap(faces[0][6 + i], faces[3][3 * i]);
        std::swap(faces[5][i], faces[1][2 + 3 * i]);
    }
    for (int i = 0; i < 3; ++i) std::swap(faces[5][i], faces[0][8 - i]);
}

// Fine
void ClassicalCube::B() 
{
    rotateClockwise(faces[4]);

    for (int i = 0; i < 3; ++i) 
    {
        std::swap(faces[0][i], faces[3][2 + 3 * i]);
        std::swap(faces[1][3 * i], faces[5][6 + i]);
    }
    for (int i = 0; i < 3; ++i) std::swap(faces[3][2 + 3 * i], faces[1][3 * i]);
}

// Fine
void ClassicalCube::U() 
{
    rotateClockwise(faces[0]);

    for (int i = 0; i < 3; ++i) 
    {
        std::swap(faces[1][i], faces[2][i]);
        std::swap(faces[3][i], faces[4][i]);
    }
    for (int i = 0; i < 3; ++i) std::swap(faces[2][i], faces[4][i]);
}

// Fine
void ClassicalCube::D() 
{
    rotateClockwise(faces[5]);

    for (int i = 0; i < 3; ++i) 
    {
        std::swap(faces[4][6 + i], faces[3][6 + i]);
        std::swap(faces[3][6 + i], faces[2][6 + i]);
        std::swap(faces[2][6 + i], faces[1][6 + i]);
    }
}

// Fine
void ClassicalCube::R()
{
    rotateClockwise(faces[3]);

    for (int i = 0; i < 3; ++i) 
    {
        std::swap(faces[0][2 + 3 * i], faces[4][6 - 3 * i]);
        std::swap(faces[5][2 + 3 * i], faces[2][2 + 3 * i]);
    }
    for (int i = 0; i < 3; ++i) std::swap(faces[5][2 + 3 * i], faces[0][2 + 3 * i]);
}

// Fine
void ClassicalCube::L() 
{
    rotateClockwise(faces[1]);

    for (int i = 0; i < 3; ++i) 
    {
        std::swap(faces[0][3 * i], faces[2][3 * i]);
        std::swap(faces[5][3 * i], faces[4][8 - 3 * i]);
    }
    for (int i = 0; i < 3; ++i) std::swap(faces[5][3 * i], faces[0][3 * i]);
}

void ClassicalCube::FPrime()
{
    F();
    F();
    F();
}

void ClassicalCube::BPrime() 
{
    B(); 
    B(); 
    B();
}

void ClassicalCube::UPrime() 
{
    U();
    U();
    U();
}

void ClassicalCube::DPrime() 
{
    D();
    D();
    D();
}

void ClassicalCube::RPrime() 
{
    R();
    R();
    R();
}

void ClassicalCube::LPrime() 
{
    L();
    L();
    L();
}
