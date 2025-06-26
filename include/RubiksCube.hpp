#pragma once

#include <vector>
#include <string>

#include "Move.hpp"

enum Color
{
    WHITE = 0,
    RED = 1,
    BLUE = 2,
    ORANGE = 3,
    GREEN = 4,
    YELLOW = 5,
};

class RubiksCube
{   
    public :
    
        virtual ~RubiksCube() = default;

        virtual void show() = 0;
        virtual bool isSolved() = 0;

        // ==== Moves ====

        virtual void F() = 0;
        virtual void FPrime() = 0;
        virtual void B() = 0;
        virtual void BPrime() = 0;
        virtual void U() = 0;
        virtual void UPrime() = 0;
        virtual void D() = 0;
        virtual void DPrime() = 0;
        virtual void R() = 0;
        virtual void RPrime() = 0;
        virtual void L() = 0;
        virtual void LPrime() = 0;
};

void apply(RubiksCube& cube, Move move);
void undo(RubiksCube& cube, Move move);

// Helper to print squares
std::string getColoredSquare(Color color);