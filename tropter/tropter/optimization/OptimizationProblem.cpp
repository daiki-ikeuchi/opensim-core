// ----------------------------------------------------------------------------
// tropter: OptimizationProblem.cpp
// ----------------------------------------------------------------------------
// Copyright (c) 2017 tropter authors
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may
// not use this file except in compliance with the License. You may obtain a
// copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------------------------------------------------------
#include "OptimizationProblemDecorator_double.h"
#include "OptimizationProblemDecorator_adouble.h"
#include <tropter/Exception.hpp>

namespace tropter {

void OptimizationProblemDecorator::set_verbosity(int verbosity) {
    TROPTER_VALUECHECK(verbosity == 0 || verbosity == 1,
            "verbosity", verbosity, "0 or 1");
    m_verbosity = verbosity;
}

void OptimizationProblemDecorator::set_findiff_hessian_step_size(double value) {
    TROPTER_VALUECHECK(value > 0, "findiff_hessian_step_size", value,
            "positive");
    m_findiff_hessian_step_size = value;
}

void OptimizationProblemDecorator::set_findiff_hessian_mode(
        const std::string& value) {
    TROPTER_VALUECHECK(value == "fast" || value == "slow",
            "findiff_hessian_mode", value, "'fast' or 'slow'");
    m_findiff_hessian_mode = value;
}

// Explicit instantiation.
template class OptimizationProblem<double>;
template class OptimizationProblem<adouble>;
// TODO extern to avoid implicit instantiation and improve compile time?

} // namespace tropter
