#include <iostream>
#include <vector>
#include "RubiksCube.hpp"
#include "ClassicalCube.hpp"
#include "OptimizedCube.hpp"
#include "RubiksCubeSolver.hpp"

#include <cstdlib> // For system("clear") or system("cls")

int main() 
{
    ClassicalCube cube;

    std::string move;

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    bool solved = true;

    if (solved) std::cout << "\033[42m=============== SOLVED ===============\033[0m" << std::endl << std::endl;
    else std::cout << "\033[47m=============== SORTED ===============\033[0m" << std::endl << std::endl;

    cube.show();

    while (true) 
    {
        std::cout << std::endl << "Enter a move (U, F, B, D, R, L) or S to solve or Q to quit: ";
        std::cin >> move;

        if (move == "Q" || move == "q")
        {
            std::cout << "Exiting...\n";
            break;
        }

        for (auto &c : move) c = toupper(c);

        if (move == "U") cube.U();
        else if (move == "U'") cube.UPrime();
        else if (move == "F") cube.F();
        else if (move == "F'") cube.FPrime();
        else if (move == "B") cube.B();
        else if (move == "B'") cube.BPrime();
        else if (move == "D") cube.D();
        else if (move == "D'") cube.DPrime();
        else if (move == "R") cube.R();
        else if (move == "R'") cube.RPrime();
        else if (move == "L") cube.L();
        else if (move == "L'") cube.LPrime();
        else if (move == "S") 
        {
            if(cube.isSolved()) std::cout << "cube already solved !" << std::endl;
            else
            {
                std::string solution = movesToString(RubiksCubeSolver::solve(cube));
                if(solution.empty()) 
                {
                    std::cout << "No solution found" << std::endl;
                    std::cout << std::to_string(RubiksCubeSolver::counter) << " positions checked ..." << std::endl;
                }
                else
                {
                    std::cout << "The solution is : " << solution << std::endl;
                    std::cout << std::to_string(RubiksCubeSolver::counter) << " positions checked ..." << std::endl;
                }
            }
            continue;
        }
        else
        {
            std::cout << "Invalid move. Please try again.\n";
            continue;
        }

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        solved = cube.isSolved();
        if (solved) std::cout << "\033[42m=============== SOLVED ===============\033[0m" << std::endl << std::endl;
        else std::cout << "\033[47m=============== SORTED ===============\033[0m" << std::endl << std::endl;

        cube.show();
    }

    return 0;
}