//
//  Printer.hpp
//  BPlusTree.2a
//
//  Created by Amittai Aviram on 6/13/16.
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

#include <queue>

class Node;

class Printer
{
public:
    Printer();
    bool verbose() const;
    void setVerbose(bool aVerbose);
    void printTree(Node* aRoot) const;
    void printLeaves(Node* aRoot);
private:
    void printEmptyTree() const;
    void printNonEmptyTree(Node* aRoot) const;
    void printCurrentRank(std::queue<Node*>* aCurrentRank, std::queue<Node*>* aNextRank) const;
    bool fVerbose;
};