#ifndef RANDOMFLOATGENERATOR_H
#define RANDOMFLOATGENERATOR_H
#include <random>

class RandomFloatGenerator
{
public:
    RandomFloatGenerator(int min, int max) : distribution(min, max) {}

    float generate() {
        return distribution(generator);
    }

private:
    std::mt19937 generator{ std::random_device{}() };
    std::uniform_real_distribution<float> distribution;
};

#endif

