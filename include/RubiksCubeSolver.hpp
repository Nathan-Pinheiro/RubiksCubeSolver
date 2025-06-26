#pragma once

#include <vector>
#include <string>
#include "RubiksCube.hpp"

#define MAX_MOVES 6

class RubiksCubeSolver
{
    private:
        static std::vector<Move> solve(RubiksCube& cube, std::vector<Move>& moves);
    public:
        static int counter;
        static std::vector<Move> solve(RubiksCube& cube);
};