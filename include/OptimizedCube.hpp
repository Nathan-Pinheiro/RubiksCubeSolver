#pragma once

#include <vector>
#include <string>

#include "RubiksCube.hpp"

extern std::vector<Color> MIDDLES;
extern std::vector<std::pair<Color, Color>> EDGES;
extern std::vector<std::tuple<Color, Color, Color>> CORNERS;

class OptimizedCube : public RubiksCube
{
    private:
        std::vector<int> middles;
        std::vector<std::pair<int, int>> edges;
        std::vector<std::pair<int, int>> corners;

    public:

        OptimizedCube();

        virtual void show() override;
        virtual bool isSolved() override;

        // Moves

        virtual void F() override;
        virtual void FPrime() override;
        virtual void B() override;
        virtual void BPrime() override;
        virtual void U() override;
        virtual void UPrime() override;
        virtual void D() override;
        virtual void DPrime() override;
        virtual void R() override;
        virtual void RPrime() override;
        virtual void L() override;
        virtual void LPrime() override;

};