#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>
#include "Area.h"

/**
 * @brief Base class representing a function.
 */
class Function {
protected:
    int dim; /**< Dimension of the function. */
    std::vector<double> x; /**< Vector representing the input variables. */
    double f; /**< Result of the function evaluation. */

public:
    /**
     * @brief Default constructor.
     */
    Function();

    /**
     * @brief Virtual destructor for proper polymorphic behavior.
     */
    virtual ~Function();

    /**
     * @brief Constructor initializing the function with a specified dimension.
     * @param dimension Dimension of the function.
     */
    explicit Function(const int dimension);

    /**
     * @brief Getter for the dimension of the function.
     * @return Dimension of the function.
     */
    int get_dim();

    /**
     * @brief Getter for the input vector.
     * @return Vector representing the input variables.
     */
    std::vector<double> get_x();

    /**
     * @brief Getter for the function value.
     * @return Result of the function evaluation.
     */
    double get_f();

    /**
     * @brief Calculates the gradient of the function at a given point.
     * @param x_ Point at which the gradient is calculated.
     * @param h Small step size for numerical differentiation.
     * @param a Area object representing the constraint on the input space.
     * @return Gradient vector.
     */
    std::vector<double> gradient(std::vector<double> x_, double h, const Area& a);

    /**
     * @brief Calculates the Hessian matrix of the function at a given point.
     * @param x_ Point at which the Hessian is calculated.
     * @param h Small step size for numerical differentiation.
     * @param a Area object representing the constraint on the input space.
     * @return Hessian matrix.
     */
    std::vector<std::vector<double>> hessian(std::vector<double> x_, double h, const Area& a);

    /**
     * @brief Pure virtual function for calculating the function value at a given point.
     * @param x Point at which the function is evaluated.
     * @return Result of the function evaluation.
     */
    virtual double calculate(std::vector<double> x) = 0;
};

/**
 * @brief Derived class representing the first function: Booth Function.
 */
class Function1 : public Function {
public:
    /**
     * @brief Default constructor initializing the function with dimension 2.
     */
    Function1();

    /**
     * @brief Calculates the function value for the first function.
     * @param x_ Point at which the function is evaluated.
     * @return Result of the function evaluation.
     */
    double calculate(std::vector<double> x_) override;
};

/**
 * @brief Derived class representing the second function: f(x) = x_1^2 + x_2^2 + (1 - x_3)^2 + x_1 * x_2.
 */
class Function2 : public Function {
public:
    /**
     * @brief Default constructor initializing the function with dimension 3.
     */
    Function2();

    /**
     * @brief Calculates the function value for the second function.
     * @param x_ Point at which the function is evaluated.
     * @return Result of the function evaluation.
     */
    double calculate(std::vector<double> x_) override;
};

/**
 * @brief Derived class representing the third function: Rosenbrock Function.
 */
class Function3 : public Function {
public:
    /**
     * @brief Default constructor initializing the function with dimension 4.
     */
    Function3();

    /**
     * @brief Calculates the function value for the third function.
     * @param x_ Point at which the function is evaluated.
     * @return Result of the function evaluation.
     */
    double calculate(std::vector<double> x_) override;
};
