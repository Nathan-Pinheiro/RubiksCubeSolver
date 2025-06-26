#pragma once

#include <array>
#include <string>
#include <iostream>
#include <cstring>

#include "RubiksCube.hpp"

const std::array<std::array<Color, 9>, 6> SOLVED_CUBE = {{
    {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
    {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
    {RED, RED, RED, RED, RED, RED, RED, RED, RED},
    {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
    {ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE},
    {YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
}};

class ClassicalCube : public RubiksCube
{
    private:
        std::array<std::array<Color, 9>, 6> faces;

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

    public:
        ClassicalCube() 
        {
            faces = SOLVED_CUBE;
        }

        inline void show() override 
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

        inline void F() override 
        {
            rotateClockwise(faces[2]);

            for (int i = 0; i < 3; ++i) 
            {
                std::swap(faces[0][6 + i], faces[3][3 * i]);
                std::swap(faces[5][i], faces[1][2 + 3 * i]);
            }
            for (int i = 0; i < 3; ++i) std::swap(faces[5][i], faces[0][8 - i]);
        }
        inline void FPrime() override { F(); F(); F(); }

        inline void B() override 
        {
            rotateClockwise(faces[4]);

            for (int i = 0; i < 3; ++i) 
            {
                std::swap(faces[0][i], faces[3][2 + 3 * i]);
                std::swap(faces[1][3 * i], faces[5][6 + i]);
            }
            for (int i = 0; i < 3; ++i) std::swap(faces[3][2 + 3 * i], faces[1][3 * i]);
        }
        inline void BPrime() override { B(); B(); B(); }

        inline void U() override 
        {
            rotateClockwise(faces[0]);

            for (int i = 0; i < 3; ++i) 
            {
                std::swap(faces[1][i], faces[2][i]);
                std::swap(faces[3][i], faces[4][i]);
            }
            for (int i = 0; i < 3; ++i) std::swap(faces[2][i], faces[4][i]);
        }
        inline void UPrime() override { U(); U(); U(); }

        inline void D() override 
        {
            rotateClockwise(faces[5]);

            for (int i = 0; i < 3; ++i) 
            {
                std::swap(faces[4][6 + i], faces[3][6 + i]);
                std::swap(faces[3][6 + i], faces[2][6 + i]);
                std::swap(faces[2][6 + i], faces[1][6 + i]);
            }
        }
        inline void DPrime() override { D(); D(); D(); }

        inline void R() override 
        {
            rotateClockwise(faces[3]);

            for (int i = 0; i < 3; ++i) 
            {
                std::swap(faces[0][2 + 3 * i], faces[4][6 - 3 * i]);
                std::swap(faces[5][2 + 3 * i], faces[2][2 + 3 * i]);
            }
            for (int i = 0; i < 3; ++i) std::swap(faces[5][2 + 3 * i], faces[0][2 + 3 * i]);
        }
        inline void RPrime() override { R(); R(); R(); }

        inline void L() override 
        {
            rotateClockwise(faces[1]);

            for (int i = 0; i < 3; ++i)
            {
                std::swap(faces[0][3 * i], faces[2][3 * i]);
                std::swap(faces[5][3 * i], faces[4][8 - 3 * i]);
            }
            for (int i = 0; i < 3; ++i) std::swap(faces[5][3 * i], faces[0][3 * i]);
        }
        inline void LPrime() override { L(); L(); L(); }

        inline bool isSolved() override  { return faces == SOLVED_CUBE; }

        inline const std::array<std::array<Color, 9>, 6>& getFaces() const { return faces; }
};