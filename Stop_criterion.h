#pragma once

#include "Function.h"
#include "Area.h"
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>

class Optimization_method;

/**
 * @brief Base class representing a stopping criterion for optimization methods.
 */
class Stop_criterion {
protected:
    double eps;  /**< Tolerance value for termination conditions. */
    int max_num_of_iterations;  /**< Maximum number of iterations allowed. */

public:
    /**
     * @brief Default constructor for the stopping criterion.
     */
    Stop_criterion();

    /**
     * @brief Destructor for the stopping criterion.
     */
    virtual ~Stop_criterion();

    /**
     * @brief Constructor for the stopping criterion with specified parameters.
     * @param eps_ Tolerance value for termination conditions.
     * @param max_num_of_iterations_ Maximum number of iterations allowed.
     */
    Stop_criterion(double eps_, int max_num_of_iterations_);

    /**
     * @brief Getter for the tolerance parameter.
     * @return Tolerance value for termination conditions.
     */
    double get_eps();

    /**
     * @brief Getter for the maximum number of iterations allowed.
     * @return Maximum number of iterations allowed.
     */
    int get_max_num_of_iterations();

    /**
     * @brief Pure virtual function to check the termination condition.
     * @param optimization_method Pointer to the optimization method using the stopping criterion.
     * @return True if the termination condition is met, false otherwise.
     */
    virtual bool termination(Optimization_method* optimization_method) = 0;
};

/**
 * @brief Stopping criterion based on the difference in function values between iterations.
 */
class Criterion_f_difference_min : public Stop_criterion {
public:
    /**
     * @brief Default constructor for the criterion.
     */
    Criterion_f_difference_min();

    /**
     * @brief Constructor for the criterion with specified parameters.
     * @param eps_ Tolerance value for termination conditions.
     * @param max_num_of_iterations_ Maximum number of iterations allowed.
     */
    explicit Criterion_f_difference_min(double eps_, int max_num_of_iterations_ = 100);

    /**
     * @brief Checks the termination condition based on the difference in function values.
     * @param optimization_method Pointer to the optimization method using the stopping criterion.
     * @return True if the termination condition is met, false otherwise.
     */
    bool termination(Optimization_method* optimization_method) override;
};

/**
 * @brief Stopping criterion based on the maximum number of iterations.
 */
class Criterion_max_iter : public Stop_criterion {
public:
    /**
     * @brief Default constructor for the criterion.
     */
    Criterion_max_iter();

    /**
     * @brief Constructor for the criterion with specified maximum number of iterations.
     * @param max_num_of_iterations_ Maximum number of iterations allowed.
     */
    explicit Criterion_max_iter(int max_num_of_iterations_);

    /**
     * @brief Checks the termination condition based on the maximum number of iterations.
     * @param optimization_method Pointer to the optimization method using the stopping criterion.
     * @return True if the termination condition is met, false otherwise.
     */
    bool termination(Optimization_method* optimization_method) override;
};

/**
 * @brief Stopping criterion based on the number of iterations since the last improvement.
 */
class Criterion_num_iter_last_approx : public Stop_criterion {
public:
    /**
     * @brief Default constructor for the criterion.
     */
    Criterion_num_iter_last_approx();

    /**
     * @brief Constructor for the criterion with specified maximum number of iterations.
     * @param max_num_of_iterations_ Maximum number of iterations allowed.
     */
    explicit Criterion_num_iter_last_approx(int max_num_of_iterations_);

    /**
     * @brief Checks the termination condition based on the number of iterations since the last improvement.
     * @param optimization_method Pointer to the optimization method using the stopping criterion.
     * @return True if the termination condition is met, false otherwise.
     */
    bool termination(Optimization_method* optimization_method) override;
};

/**
 * @brief Stopping criterion based on the gradient of the objective function.
 */
class Criterion_grad_f : public Stop_criterion {
public:
    /**
     * @brief Default constructor for the criterion.
     */
    Criterion_grad_f();

    /**
     * @brief Constructor for the criterion with specified parameters.
     * @param eps_ Tolerance value for termination conditions.
     * @param max_num_of_iterations_ Maximum number of iterations allowed.
     */
    explicit Criterion_grad_f(double eps_, int max_num_of_iterations_ = 100);

    /**
     * @brief Checks the termination condition based on the gradient of the objective function.
     * @param optimization_method Pointer to the optimization method using the stopping criterion.
     * @return True if the termination condition is met, false otherwise.
     */
    bool termination(Optimization_method* optimization_method) override;
};

/**
 * @brief Stopping criterion based on the difference in variable values between iterations.
 */
class Criterion_x_difference : public Stop_criterion {
public:
    /**
     * @brief Default constructor for the criterion.
     */
    Criterion_x_difference();

    /**
     * @brief Constructor for the criterion with specified parameters.
     * @param eps_ Tolerance value for termination conditions.
     * @param max_num_of_iterations_ Maximum number of iterations allowed.
     */
    explicit Criterion_x_difference(double eps_, int max_num_of_iterations_ = 100);

    /**
     * @brief Checks the termination condition based on the difference in variable values between iterations.
     * @param optimization_method Pointer to the optimization method using the stopping criterion.
     * @return True if the termination condition is met, false otherwise.
     */
    bool termination(Optimization_method* optimization_method) override;
};

/**
 * @brief Stopping criterion based on the difference in function values between iterations.
 */
class Criterion_f_difference : public Stop_criterion {
public:
    /**
     * @brief Default constructor for the criterion.
     */
    Criterion_f_difference();

    /**
     * @brief Constructor for the criterion with specified parameters.
     * @param eps_ Tolerance value for termination conditions.
     * @param max_num_of_iterations_ Maximum number of iterations allowed.
     */
    explicit Criterion_f_difference(double eps_, int max_num_of_iterations = 100);

    /**
     * @brief Checks the termination condition based on the difference in function values between iterations.
     * @param optimization_method Pointer to the optimization method using the stopping criterion.
     * @return True if the termination condition is met, false otherwise.
     */
    bool termination(Optimization_method* optimization_method) override;
};

