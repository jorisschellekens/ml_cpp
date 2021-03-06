#pragma once

#include <assert.h>
#include <functional>
#include <math.h>
#include <vector>

namespace numeric
{

    /*!
     * In mathematics, a partial derivative of a function of several variables is its derivative with respect to one of those variables,
     * with the others held constant (as opposed to the total derivative, in which all variables are allowed to vary).
     * Partial derivatives are used in vector calculus and differential geometry.
     */
    std::function<float(std::vector<float>,int)> partial_derivative(const std::function<float(std::vector<float>)>& f, float eps = pow(10.0f, -4.0f))
    {

        /*
         * returns a function that represents the partial derivative
         * its inputs are the coordinates at which to consider the partial derivative,
         * and the index of the variable to be allowed to vary.
         */
        return [&f, eps](const std::vector<float>& xs, int var_index)
        {

            assert(var_index >= 0);
            assert(var_index < xs.size());

            std::vector<float> xs_mod_0 = xs;
            xs_mod_0[var_index] += eps;

            std::vector<float> xs_mod_1 = xs;
            xs_mod_1[var_index] -= eps;

            return ( f(xs_mod_0) - f(xs_mod_1) ) / (2 * eps);
        };
    }

    /*!
     * The derivative of a function of a real variable measures the sensitivity to change
     * of the function value (output value) with respect to a change in its argument (input value).
     * Derivatives are a fundamental tool of calculus.
     * For example, the derivative of the position of a moving object with respect to time is the object's velocity:
     * this measures how quickly the position of the object changes when time advances.
     */
    std::function<float(float)> derivative(const std::function<float(float)>& f, float eps = pow(10.0f, -4.0f))
    {
        return [&f, eps](float x)
        {
            return ( f(x + eps) - f(x - eps) ) / (2 * eps);
        };
    }
}
