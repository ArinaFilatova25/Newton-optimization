#pragma once

#include "Function.h"
#include "Area.h"
#include <vector>
#include <random>
#include <chrono>
#include <sstream>
#include <cfloat>
#include "Stop_criterion.h"
#include "Optimization_method.h"
#include <Eigen/Dense>

/**
 * @brief Newton's optimization method class.
 */
class Newton_opt : public Optimization_method {
public:
    /**
     * @brief Default constructor.
     */
    Newton_opt();

    /**
     * @brief Constructor initializing Newton's optimization method.
     * @param function Pointer to the objective function.
     * @param x_0 Initial point for optimization.
     * @param area Area constraint for the optimization.
     * @param stop_criterion Pointer to the stopping criterion.
     */
    Newton_opt(Function* function, std::vector<double> x_0, Area area, Stop_criterion* stop_criterion);

    /**
     * @brief Destructor for Newton's optimization method.
     */
    ~Newton_opt();

    /**
     * @brief Perform the Newton optimization.
     */
    void optimization() override;
};
