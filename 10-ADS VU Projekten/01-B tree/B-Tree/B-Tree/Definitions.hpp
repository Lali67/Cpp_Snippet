//
//  Definitions.hpp
//  B-Plus Tree in C++
//
//  Created by Amittai Aviram on 6/10/16.
//  Copyright © 2018 Amittai Aviram. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#pragma once

#include <cstdlib>

#define VERSION "2.1.0"

const int DEFAULT_ORDER{4};

// Minimum order is necessarily 3.  We set the maximum
// order arbitrarily.  You may change the maximum order.
const int MIN_ORDER{DEFAULT_ORDER - 1};
const int MAX_ORDER{20};

// Size of the buffer used to get the arguments (1 or 2) of the
// "i" interactive instruction.
const int BUFFER_SIZE{256};

using KeyType = int64_t;
using ValueType = int64_t;

