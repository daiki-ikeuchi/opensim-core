/* -------------------------------------------------------------------------- *
 *                          OpenSim:  MOTFileAdapter.h                        *
 * -------------------------------------------------------------------------- *
 * The OpenSim API is a toolkit for musculoskeletal modeling and simulation.  *
 * OpenSim is developed at Stanford University and supported by the US        *
 * National Institutes of Health (U54 GM072970, R24 HD065690) and by DARPA    *
 * through the Warrior Web program.                                           *
 *                                                                            *
 * Copyright (c) 2005-2015 Stanford University and the Authors                *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may    *
 * not use this file except in compliance with the License. You may obtain a  *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0.         *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */

#ifndef OPENSIM_MOT_FILE_ADAPTER_H_
#define OPENSIM_MOT_FILE_ADAPTER_H_

#include "DelimFileAdapter.h"


namespace OpenSim {

/** MOTFileAdapter is a DelimFileAdapter that presets the delimiters 
appropriately for MOT files.                                                  */
class OSIMCOMMON_API MOTFileAdapter : public DelimFileAdapter {
public:
    MOTFileAdapter();
    MOTFileAdapter(const MOTFileAdapter&)            = default;
    MOTFileAdapter(MOTFileAdapter&&)                 = default;
    MOTFileAdapter& operator=(const MOTFileAdapter&) = default;
    MOTFileAdapter& operator=(MOTFileAdapter&&)      = default;
    ~MOTFileAdapter()                                = default;

    MOTFileAdapter* clone() const override;

    /** Read a MOT file.                                                      */
    static
    TimeSeriesTable read(const std::string& fileName);

    /** Write a MOT file.                                                     */
    static
    void write(const TimeSeriesTable& table, const std::string& fileName);
};

}

#endif // OPENSIM_MOT_FILE_ADAPTER_H_
