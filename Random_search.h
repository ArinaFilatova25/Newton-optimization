#pragma once

#include "Function.h"
#include "Area.h"
#include "Stop_criterion.h"
#include "Optimization_method.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>

/**
 * @brief Random Search optimization method class.
 */
class Random_search : public Optimization_method {
private:
    unsigned seed; /**< Seed for random number generation. */
    std::default_random_engine generator; /**< Random number generator engine. */
    std::uniform_real_distribution<double> distribution; /**< Uniform distribution for generating random numbers. */
    double p; /**< Probability parameter for determining the search strategy. */
    double delta; /**< Initial radius neighborhood of a point. */
    double curr_delta; /**< Current radius neighborhood of a point. */
    double alpha; /**< Coefficient that diminishes the size of the delta neighborhood around a given point. */

public:
    /**
     * @brief Default constructor for Random Search optimization method.
     */
    Random_search();

    /**
     * @brief Constructor for Random Search optimization method.
     * @param function Pointer to the objective function.
     * @param x_0 Initial point for optimization.
     * @param area Area constraint for optimization.
     * @param stop_criterion Pointer to the stopping criterion.
     * @param p_ Probability parameter for determining the search strategy.
     * @param delta_ Initial radius neighborhood of a point. 
     * @param alpha_ Coefficient that diminishes the size of the delta neighborhood around a given point.
     */
    Random_search(Function* function, std::vector<double> x_0, Area area,
        Stop_criterion* stop_criterion, double p_ = 0.5, double delta_ = 1, double alpha_ = 1);

    /**
     * @brief Perform the Random Search optimization.
     */
    void optimization() override;
};
