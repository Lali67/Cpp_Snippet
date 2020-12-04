//
//  BPlusTree.cpp
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


#include <iostream>
#include <fstream>
#include <string>
#include "BPlusTree.hpp"
#include "Exceptions.hpp"
#include "InternalNode.hpp"
#include "LeafNode.hpp"
#include "Node.hpp"

BPlusTree::BPlusTree(int aOrder) : fOrder{aOrder}, fRoot{nullptr} {}

bool BPlusTree::isEmpty() const
{
    return !fRoot;
}

// INSERTION

void BPlusTree::insert(KeyType aKey, ValueType aValue)
{
    if (isEmpty()) {
        startNewTree(aKey, aValue);
    } else {
        insertIntoLeaf(aKey, aValue);
    }
}

void BPlusTree::startNewTree(KeyType aKey, ValueType aValue) {
    LeafNode* newLeafNode = new LeafNode(fOrder);
    newLeafNode->createAndInsertRecord(aKey, aValue);
    fRoot = newLeafNode;
}

void BPlusTree::insertIntoLeaf(KeyType aKey, ValueType aValue)
{
    LeafNode* leafNode = findLeafNode(aKey);
    if (!leafNode) {
        throw LeafNotFoundException(aKey);
    }
    Record* record = leafNode->lookup(aKey);
    if (record) {
        record->setValue(aValue);
        return;
    }
    int newSize = leafNode->createAndInsertRecord(aKey, aValue);
    if (newSize > leafNode->maxSize()) {
        LeafNode* newLeaf = split(leafNode);
        newLeaf->setNext(leafNode->next());
        leafNode->setNext(newLeaf);
        KeyType newKey = newLeaf->firstKey();
        insertIntoParent(leafNode, newKey, newLeaf);
    }
}

void BPlusTree::insertIntoParent(Node *aOldNode, KeyType aKey, Node *aNewNode)
{
    InternalNode* parent = static_cast<InternalNode*>(aOldNode->parent());
    if (parent == nullptr) {
        fRoot = new InternalNode(fOrder);
        parent = static_cast<InternalNode*>(fRoot);
        aOldNode->setParent(parent);
        aNewNode->setParent(parent);
        parent->populateNewRoot(aOldNode, aKey, aNewNode);
    } else {
        int newSize = parent->insertNodeAfter(aOldNode, aKey, aNewNode);
        if (newSize > parent->maxSize()) {
            InternalNode* newNode = split(parent);
            KeyType newKey = newNode->replaceAndReturnFirstKey();
            insertIntoParent(parent, newKey, newNode);
        }
    }
}

template <typename T>
T* BPlusTree::split(T* aNode)
{
    T* newNode = new T(fOrder, aNode->parent());
    aNode->moveHalfTo(newNode);
    return newNode;
}


// REMOVAL


void BPlusTree::remove(KeyType aKey)
{
    if (isEmpty()) {
        return;
    } else {
        removeFromLeaf(aKey);
    }
}

void BPlusTree::removeFromLeaf(KeyType aKey)
{
    LeafNode* leafNode = findLeafNode(aKey);
    if (!leafNode) {
        return;
    }
    if (!leafNode->lookup(aKey)) {
        return;
    }
    int newSize = leafNode->removeAndDeleteRecord(aKey);
    if (newSize < leafNode->minSize()) {
        coalesceOrRedistribute(leafNode);
    }
}

template <typename N>
void BPlusTree::coalesceOrRedistribute(N* aNode)
{
    if (aNode->isRoot()) {
        adjustRoot();
        return;
    }
    auto parent = static_cast<InternalNode*>(aNode->parent());
    int indexOfNodeInParent = parent->nodeIndex(aNode);
    int neighborIndex = (indexOfNodeInParent == 0) ? 1 : indexOfNodeInParent - 1;
    N* neighborNode = static_cast<N*>(parent->neighbor(neighborIndex));
    if (aNode->size() + neighborNode->size() <= neighborNode->maxSize()) {
        coalesce(neighborNode, aNode, parent, indexOfNodeInParent);
    } else {
        redistribute(neighborNode, aNode, parent, indexOfNodeInParent);
    }
}

template <typename N>
void BPlusTree::coalesce(N* aNeighborNode, N* aNode, InternalNode* aParent, int aIndex)
{
    if (aIndex == 0) {
        std::swap(aNode, aNeighborNode);
        aIndex = 1;
    }
    aNode->moveAllTo(aNeighborNode, aIndex);
    aParent->remove(aIndex);
    if (aParent->size() < aParent->minSize()) {
        coalesceOrRedistribute(aParent);
    }
    delete aNode;
}

template <typename N>
void BPlusTree::redistribute(N* aNeighborNode, N* aNode, InternalNode* aParent, int aIndex)
{
    if (aIndex == 0) {
        aNeighborNode->moveFirstToEndOf(aNode);
    } else {
        aNeighborNode->moveLastToFrontOf(aNode, aIndex);
    }
}

void BPlusTree::adjustRoot()
{
    if (!fRoot->isLeaf() && fRoot->size() == 1) {
        auto discardedNode = static_cast<InternalNode*>(fRoot);
        fRoot = static_cast<InternalNode*>(fRoot)->removeAndReturnOnlyChild();
        fRoot->setParent(nullptr);
        delete discardedNode;
    } else if (!fRoot->size()){
        delete fRoot;
        fRoot = nullptr;
    }
}


// UTILITIES AND PRINTING

LeafNode* BPlusTree::findLeafNode(KeyType aKey, bool aPrinting, bool aVerbose)
{
    if (isEmpty()) {
        if (aPrinting) {
            std::cout << "Not found: empty tree." << std::endl;
        }
        return nullptr;
    }
    auto node = fRoot;
    if (aPrinting) {
        std::cout << "Root: ";
        if (fRoot->isLeaf()) {
            std::cout << "\t" << static_cast<LeafNode*>(fRoot)->toString(aVerbose);
        } else {
            std::cout << "\t" << static_cast<InternalNode*>(fRoot)->toString(aVerbose);
        }
        std::cout << std::endl;
    }
    while (!node->isLeaf()) {
        auto internalNode = static_cast<InternalNode*>(node);
        if (aPrinting && node != fRoot) {
            std::cout << "\tNode: " << internalNode->toString(aVerbose) << std::endl;
        }
        node = internalNode->lookup(aKey);
    }
    return static_cast<LeafNode*>(node);
}

void BPlusTree::readInputFromFile(std::string aFileName)
{
    int key;
    std::ifstream input(aFileName);
    while (input) {
        input >> key;
        insert(key, key);
    }
}

void BPlusTree::print(bool aVerbose)
{
    fPrinter.setVerbose(aVerbose);
    fPrinter.printTree(fRoot);
}

void BPlusTree::printLeaves(bool aVerbose)
{
    fPrinter.setVerbose(aVerbose);
    fPrinter.printLeaves(fRoot);
}

void BPlusTree::destroyTree()
{
    if (fRoot->isLeaf()) {
        delete static_cast<LeafNode*>(fRoot);
    } else {
        delete static_cast<InternalNode*>(fRoot);
    }
    fRoot = nullptr;
}

void BPlusTree::printValue(KeyType aKey, bool aVerbose)
{
    printValue(aKey, false, aVerbose);
}

void BPlusTree::printValue(KeyType aKey, bool aPrintPath, bool aVerbose)
{
    LeafNode* leaf = findLeafNode(aKey, aPrintPath, aVerbose);
    if (!leaf) {
        std::cout << "Leaf not found with key " << aKey << "." << std::endl;
        return;
    }
    if (aPrintPath) {
        std::cout << "\t";
    }
    std::cout << "Leaf: " << leaf->toString(aVerbose) << std::endl;
    Record* record = leaf->lookup(aKey);
    if (!record) {
        std::cout << "Record not found with key " << aKey << "." << std::endl;
        return;
    }
    if (aPrintPath) {
        std::cout << "\t";
    }
    std::cout << "Record found at location " << std::hex << record << std::dec << ":" << std::endl;
    std::cout << "\tKey: " << aKey << "   Value: " << record->value() << std::endl;
}

void BPlusTree::printPathTo(KeyType aKey, bool aVerbose)
{
    printValue(aKey, true, aVerbose);
}

void BPlusTree::printRange(KeyType aStart, KeyType aEnd)
{
    auto rangeVector = range(aStart, aEnd);
    for (auto entry : rangeVector) {
        std::cout << "Key: " << std::get<0>(entry);
        std::cout << "    Value: " << std::get<1>(entry);
        std::cout << "    Leaf: " << std::hex << std::get<2>(entry) << std::dec << std::endl;
    }
}

std::vector<BPlusTree::EntryType> BPlusTree::range(KeyType aStart, KeyType aEnd)
{
    auto startLeaf = findLeafNode(aStart);
    auto endLeaf = findLeafNode(aEnd);
    std::vector<std::tuple<KeyType, ValueType, LeafNode*>> entries;
    if (!startLeaf || !endLeaf) {
        return entries;
    }
    startLeaf->copyRangeStartingFrom(aStart, entries);
    startLeaf = startLeaf->next();
    while (startLeaf != endLeaf) {
        startLeaf->copyRange(entries);
        startLeaf = startLeaf->next();
    }
    startLeaf->copyRangeUntil(aEnd, entries);
    return entries;
}
