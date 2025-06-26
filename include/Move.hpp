#pragma once

#include <vector>
#include <string>

enum class Move 
{
    U, U_PRIME,
    R, R_PRIME,
    L, L_PRIME,
    D, D_PRIME,
    F, F_PRIME,
    B, B_PRIME,
    NONE
};

bool isPrime(const Move& move);
Move reverseMove(const Move& move);
std::string moveToString(const Move& move);
std::string movesToString(const std::vector<Move>& moves);