#pragma once

#include "Function.h"
#include "Stop_criterion.h"
#include "Area.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>

/**
 * @brief Base class representing an optimization method.
 */
class Optimization_method {
protected:
    std::vector<std::vector<double>> seq_x_i; /**< Sequence of points, where each element represents a single iterate in the optimization process. */
    std::vector<double> seq_f_i; /**< Sequence of function values during optimization. */
    Function* function; /**< Pointer to the objective function. */
    Area area; /**< Area constraint for optimization. */
    Stop_criterion* stop_criterion; /**< Pointer to the stopping criterion. */
    int num_of_iter; /**< Total number of iterations. */
    int num_of_iter_since_last_approx; /**< Number of iterations since the last approximation. */

public:
    /**
     * @brief Default constructor.
     */
    Optimization_method();

    /**
      * @brief Destructor for optimization method.
      * Deletes the function and stop criterion objects.
      */
    virtual ~Optimization_method();

    /**
     * @brief Constructor initializing the optimization method.
     * @param func Pointer to the objective function.
     * @param x_0 Initial point for optimization.
     * @param area_ Area constraint for optimization.
     * @param stop_crit_ Pointer to the stopping criterion.
     */
    Optimization_method(Function* func, std::vector<double> x_0, Area area_, Stop_criterion* stop_crit_);

    /**
     * @brief Getter for the sequence of iterates during optimization.
     * @return Sequence of points during optimization.
     */
    std::vector<std::vector<double>> get_seq_x_i();

    /**
     * @brief Getter for the sequence of function values during optimization.
     * @return Sequence of function values during optimization.
     */
    std::vector<double> get_seq_f_i();

    /**
     * @brief Getter for the pointer to the objective function.
     * @return Pointer to the objective function.
     */
    Function* get_function();

    /**
     * @brief Getter for the area constraint for optimization.
     * @return Area constraint for optimization.
     */
    Area get_area();

    /**
     * @brief Getter for the pointer to the stopping criterion.
     * @return Pointer to the stopping criterion.
     */
    Stop_criterion* get_stop_criterion();

    /**
     * @brief Getter for the total number of iterations.
     * @return Total number of iterations.
     */
    int get_num_of_iter();

    /**
     * @brief Getter for the number of iterations since the last approximation.
     * @return Number of iterations since the last approximation.
     */
    int get_num_of_iter_since_last_approx();

    /**
     * @brief Pure virtual function for performing the optimization.
     */
    virtual void optimization() = 0;
};
