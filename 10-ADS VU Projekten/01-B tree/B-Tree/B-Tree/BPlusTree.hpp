//
//  BPlusTree.hpp
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

#include <tuple>
#include <vector>
#include "Definitions.hpp"
#include "Printer.hpp"

class InternalNode;
class LeafNode;
class Node;


/// Main class providing the API for the Interactive B+ Tree.
class BPlusTree
{
public:
    /// Sole constructor.  Accepts an optional order for the B+ Tree.
    /// The default order will provide a reasonable demonstration of the
    /// data structure and its operations.
    explicit BPlusTree(int aOrder = DEFAULT_ORDER);
    
    /// The type used in the API for inserting a new key-value pair
    /// into the tree.  The third item is the type of the Node into
    /// which the key will be inserted.
    using EntryType = std::tuple<KeyType, ValueType, LeafNode*>;
    
    /// Returns true if this B+ tree has no keys or values.
    bool isEmpty() const;
    
    /// Insert a key-value pair into this B+ tree.
    void insert(KeyType aKey, ValueType aValue);
    
    /// Remove a key and its value from this B+ tree.
    void remove(KeyType aKey);
    
    /// Print this B+ tree to stdout using a simple command-line
    /// ASCII graphic scheme.
    /// @param[in] aVerbose Determins whether printing should include addresses.
    void print(bool aVerbose = false);
    
    /// Print the bottom rank of this B+ tree, consisting of its leaves.
    /// This shows all the keys in the B+ tree in sorted order.
    /// @param[in] aVerbose Determins whether printing should include addresses.
    void printLeaves(bool aVerbose = false);
    
    /// Print the value associated with a given key, along with the address
    /// at which the tree stores that value.
    /// @param[in] aVerbose Determines whether printing should include addresses.
    void printValue(KeyType aKey, bool aVerbose = false);
    
    /// Print the path from the root to the leaf bearing key aKey.
    /// @param[in] aVerbose Determines whether printing should include addresses.
    void printPathTo(KeyType aKey, bool aVerbose = false);

    /// Print key, value, and address for each item in the range
    /// from aStart to aEnd, including both.
    void printRange(KeyType aStart, KeyType aEnd);

    /// Remove all elements from the B+ tree. You can then build
    /// it up again by inserting new elements into it.
    void destroyTree();
    
    /// Read elements to be inserted into the B+ tree from a text file.
    /// Each new element should consist of a single integer on a line by itself.
    /// This B+ tree treats each such input as both a new value and the key
    /// under which to store it.
    void readInputFromFile(std::string aFileName);
private:
    void startNewTree(KeyType aKey, ValueType aValue);
    void insertIntoLeaf(KeyType aKey, ValueType aValue);
    void insertIntoParent(Node* aOldNode, KeyType aKey, Node* aNewNode);
    template <typename T> T* split(T* aNode);
    void removeFromLeaf(KeyType aKey);
    template <typename N> void coalesceOrRedistribute(N* aNode);
    template <typename N> void coalesce(N* aNeighborNode, N* aNode, InternalNode* aParent, int aIndex);
    template <typename N> void redistribute(N* aNeighborNode, N* aNode, InternalNode* aParent, int aIndex);
    void adjustRoot();
    LeafNode* findLeafNode(KeyType aKey, bool aPrinting = false, bool aVerbose = false);
    void printValue(KeyType aKey, bool aPrintPath, bool aVerbose);
    std::vector<EntryType> range(KeyType aStart, KeyType aEnd);
    const int fOrder;
    Node* fRoot;
    Printer fPrinter;
};
