#include "Move.hpp"

#include <iostream>

bool isPrime(const Move& move)
{
    switch (move)
    {
        case Move::U_PRIME:
        case Move::R_PRIME:
        case Move::L_PRIME:
        case Move::D_PRIME:
        case Move::F_PRIME:
        case Move::B_PRIME: return true;
        default: return false;
    }
}

Move reverseMove(const Move& move)
{
    switch (move) 
    {
        case Move::U: return Move::U_PRIME;
        case Move::U_PRIME: return Move::U;
        case Move::R: return Move::R_PRIME;
        case Move::R_PRIME: return Move::R;
        case Move::L: return Move::L_PRIME;
        case Move::L_PRIME: return Move::L;
        case Move::D: return Move::D_PRIME;
        case Move::D_PRIME: return Move::D;
        case Move::F: return Move::F_PRIME;
        case Move::F_PRIME: return Move::F;
        case Move::B: return Move::B_PRIME;
        case Move::B_PRIME: return Move::B;
        default: throw std::invalid_argument("Invalid Move");
    }
}

std::string moveToString(const Move& move) 
{
    switch (move) 
    {
        case Move::U: return "U";
        case Move::U_PRIME: return "U'";
        case Move::R: return "R";
        case Move::R_PRIME: return "R'";
        case Move::L: return "L";
        case Move::L_PRIME: return "L'";
        case Move::D: return "D";
        case Move::D_PRIME: return "D'";
        case Move::F: return "F";
        case Move::F_PRIME: return "F'";
        case Move::B: return "B";
        case Move::B_PRIME: return "B'";
        default: return "Invalid Move";
    }
}

std::string movesToString(const std::vector<Move>& moves)
{
    std::string result = "";

    for(Move move : moves)
    {
        if(!result.empty()) result += " ";
        result += moveToString(move);
    }

    return result;
}