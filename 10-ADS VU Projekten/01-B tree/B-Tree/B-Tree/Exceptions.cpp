//
//  Exceptions.cpp
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

#include <sstream>
#include <string>
#include "Exceptions.hpp"
#include "Node.hpp"

LeafNotFoundException::LeafNotFoundException(KeyType aKey) : fKey{aKey} {}

const char* LeafNotFoundException::what() const noexcept
{
    std::ostringstream ss;
    ss << "Key not found in any leaf node:  ";
    ss << fKey;
    static std::string message;
    message = ss.str();
    return message.c_str();
}


NodeNotFoundException::NodeNotFoundException(std::string aSearchedNode,
                                             std::string aContainingNode) :
fSearchedNode{aSearchedNode}, fContainingNode{aContainingNode}
{}

const char* NodeNotFoundException::what() const noexcept
{
    std::ostringstream ss;
    ss << "Node |" << fSearchedNode << "| not found";
    ss << " as a child of node ";
    ss << fContainingNode;
    static std::string message;
    message = ss.str();
    return message.c_str();
}

RecordNotFoundException::RecordNotFoundException(KeyType aKey) : fKey{aKey} {}

const char* RecordNotFoundException::what() const noexcept
{
    std::ostringstream ss;
    ss << "Record not found with key:  " << fKey;
    static std::string message;
    message = ss.str();
    return message.c_str();
}

