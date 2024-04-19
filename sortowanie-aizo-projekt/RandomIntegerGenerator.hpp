#ifndef RANDOMINTEGERGENERATOR_H
#define RANDOMINTEGERGENERATOR_H
#include <random>

class RandomIntegerGenerator
{
    public:
        RandomIntegerGenerator(int min, int max) : distribution(min, max) {}

        int generate() {
            return distribution(generator);
        }

    private:
        std::mt19937 generator{ std::random_device{}() };
        std::uniform_int_distribution<int> distribution;
};

#endif

