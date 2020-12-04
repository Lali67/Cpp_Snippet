//
//  Exceptions.hpp
//  BPlusTree.2a
//
//  Created by Amittai Aviram on 6/12/16.
//  Copyright © 2016 Amittai Aviram. All rights reserved.
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

#include <exception>
#include <string>
#include "Definitions.hpp"

class LeafNotFoundException : public std::exception
{
public:
    explicit LeafNotFoundException(KeyType);
    const char* what() const noexcept override;
private:
    KeyType fKey;
};

class NodeNotFoundException : public std::exception
{
public:
    explicit NodeNotFoundException(std::string, std::string);
    const char* what() const noexcept override;
private:
    std::string fSearchedNode;
    std::string fContainingNode;
};

class RecordNotFoundException : public std::exception
{
public:
    explicit RecordNotFoundException(KeyType);
    const char* what() const noexcept override;
private:
    KeyType fKey;
};