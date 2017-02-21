// ======================================================================== //
// Copyright 2009-2017 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include "sg/SceneGraphExports.h"
#include "sg/common/Common.h"

#include <atomic>

namespace ospray {
  namespace sg {
    
    //! \brief Implements an abstraction of Time
    /*! Abstracts the concept of time to be used for time-stamping
      node's last 'lastupdated' and /lastmodified' time stamps */
    struct OSPSG_INTERFACE TimeStamp
    {
      TimeStamp() = default;
      operator size_t() const;
      
    private:

      static size_t getNextValue();

      // Data members //

      size_t value {getNextValue()};

      //! \brief the uint64_t that stores the time value
      static std::atomic_size_t global;
    };

  } // ::ospray::sg
} // ::ospray
