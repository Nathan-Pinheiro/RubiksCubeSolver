#pragma once

#include <array>
#include <string>

#include "RubiksCube.hpp"

class ClassicalCube : public RubiksCube
{
    private:
        std::array<std::array<Color, 9>, 6> faces;

    public:
        ClassicalCube() 
        {
            faces = std::array<std::array<Color, 9>, 6>{
                std::array<Color, 9>{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
                std::array<Color, 9>{GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
                std::array<Color, 9>{RED, RED, RED, RED, RED, RED, RED, RED, RED},
                std::array<Color, 9>{BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},
                std::array<Color, 9>{ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE, ORANGE},
                std::array<Color, 9>{YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW, YELLOW},
            };
        }

        virtual void show() override;

        // Moves

        void F() override;
        void FPrime() override;
        void B() override;
        void BPrime() override;
        void U() override;
        void UPrime() override;
        void D() override;
        void DPrime() override;
        void R() override;
        void RPrime() override;
        void L() override;
        void LPrime() override;

        bool isSolved() override;

        const std::array<std::array<Color, 9>, 6>& getFaces() const { return faces; }
};