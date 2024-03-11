#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <sstream>

/**
 * @brief Class representing an area defined by a bounding box.
 */
class Area {
private:
    std::vector<std::pair<double, double>> box; /**< Bounding box representing the area. */

public:
    /**
     * @brief Default constructor.
     */
    Area();

    /**
     * @brief Constructor initializing the area with a specified bounding box.
     * @param box_ Vector of pairs representing the bounding box in the format {min, max} for each dimension.
     */
    Area(const std::vector<std::pair<double, double>>& box_);

    /**
     * @brief Getter for the bounding box of the area.
     * @return Vector of pairs representing the bounding box in the format {min, max} for each dimension.
     */
    std::vector<std::pair<double, double>> get_box();

    /**
     * @brief Setter for the bounding box of the area.
     * @param min Minimum value for the bounding box.
     * @param max Maximum value for the bounding box.
     */
    void set_box(const double min, const double max);

    /**
     * @brief Checks if a given point is inside the area.
     * @param x Vector representing the point coordinates in each dimension.
     * @return True if the point is inside the area, false otherwise.
     */
    bool is_inside(std::vector<double> x) const;
};

