#include "RubiksCubeSolver.hpp"

#include "RubiksCube.hpp"

#include <iostream>
#include <vector>
#include <limits>

int RubiksCubeSolver::counter = 0;

std::vector<Move> generateMoves() 
{
    return {
        Move::U, Move::U_PRIME, 
        Move::R, Move::R_PRIME, 
        Move::L, Move::L_PRIME, 
        Move::D, Move::D_PRIME, 
        Move::F, Move::F_PRIME, 
        Move::B, Move::B_PRIME
    };
}

std::vector<Move> generateRelevantMoves(const std::vector<Move>& moves) 
{
    if (moves.empty()) return generateMoves();

    Move lastMove = moves.back();
    Move secondLastMove = moves.size() > 1 ? moves[moves.size() - 2] : Move::NONE;

    std::vector<Move> filteredMoves;
    for (Move move : generateMoves()) 
    {
        if (
            (lastMove == move && secondLastMove == move) 
            || (isPrime(lastMove) && lastMove == move) 
            || move == reverseMove(lastMove)
        )
        { continue; }

        filteredMoves.push_back(move);
    }
    return filteredMoves;
}

std::vector<Move> RubiksCubeSolver::solve(RubiksCube& cube, std::vector<Move>& moves)
{
    RubiksCubeSolver::counter += 1;

    if (cube.isSolved()) return moves;
    if (moves.size() >= MAX_MOVES) return {};

    std::vector<Move> bestSolution;

    for (Move nextMove : generateRelevantMoves(moves))
    {
        apply(cube, nextMove);
        moves.push_back(nextMove);

        std::vector<Move> solution = solve(cube, moves);
        if (!solution.empty() && (bestSolution.empty() || solution.size() < bestSolution.size())) 
            bestSolution = solution;

        undo(cube, nextMove);
        moves.pop_back();
    }

    return bestSolution;
}

std::vector<Move> RubiksCubeSolver::solve(RubiksCube& cube)
{
    RubiksCubeSolver::counter = 0;
    std::vector<Move> moves;
    return solve(cube, moves);
}