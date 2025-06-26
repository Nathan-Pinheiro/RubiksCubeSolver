#include "RubiksCube.hpp"

#include <iostream>

void apply(RubiksCube& cube, Move move) 
{
    switch (move) 
    {
        case Move::U: cube.U(); break;
        case Move::U_PRIME: cube.UPrime(); break;
        case Move::R: cube.R(); break;
        case Move::R_PRIME: cube.RPrime(); break;
        case Move::L: cube.L(); break;
        case Move::L_PRIME: cube.LPrime(); break;
        case Move::D: cube.D(); break;
        case Move::D_PRIME: cube.DPrime(); break;
        case Move::F: cube.F(); break;
        case Move::F_PRIME: cube.FPrime(); break;
        case Move::B: cube.B(); break;
        case Move::B_PRIME: cube.BPrime(); break;
        default: break;
    }
}

void undo(RubiksCube& cube, Move move) 
{
    switch (move) 
    {
        case Move::U: cube.UPrime(); break;
        case Move::U_PRIME: cube.U(); break;
        case Move::R: cube.RPrime(); break;
        case Move::R_PRIME: cube.R(); break;
        case Move::L: cube.LPrime(); break;
        case Move::L_PRIME: cube.L(); break;
        case Move::D: cube.DPrime(); break;
        case Move::D_PRIME: cube.D(); break;
        case Move::F: cube.FPrime(); break;
        case Move::F_PRIME: cube.F(); break;
        case Move::B: cube.BPrime(); break;
        case Move::B_PRIME: cube.B(); break;
        default: break;
    }
}

std::string getColoredSquare(Color color)
{
    switch (color)
    {
        case Color::WHITE: return "\033[47m  \033[0m";
        case Color::RED: return "\033[41m  \033[0m";
        case Color::BLUE: return "\033[44m  \033[0m";
        case Color::GREEN: return "\033[42m  \033[0m";
        case Color::YELLOW: return "\033[43m  \033[0m";
        case Color::ORANGE: return "\033[48;5;208m  \033[0m";
        default: return "  ";
    }
}