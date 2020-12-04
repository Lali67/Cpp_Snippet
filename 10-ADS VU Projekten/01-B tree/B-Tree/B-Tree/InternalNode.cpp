//
//  InternalNode.cpp
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
#include <sstream>
#include "Exceptions.hpp"
#include "InternalNode.hpp"

InternalNode::InternalNode(int aOrder) : Node(aOrder) {}

InternalNode::InternalNode(int aOrder, Node* aParent) : Node(aOrder, aParent) {}

InternalNode::~InternalNode()
{
    for (auto mapping : fMappings) {
        delete mapping.second;
    }
}

bool InternalNode::isLeaf() const
{
    return false;
}

int InternalNode::size() const
{
    return static_cast<int>(fMappings.size());
}

int InternalNode::minSize() const
{
    return (order() + 1)/2;
}

int InternalNode::maxSize() const
{
    // Includes the first entry, which
    // has key DUMMY_KEY and a value that
    // points to the left of the first positive key k1
    // (i.e., a node whose keys are all < k1).
    return order();
}

KeyType InternalNode::keyAt(int aIndex) const
{
    return fMappings[aIndex].first;
}

void InternalNode::setKeyAt(int aIndex, KeyType aKey)
{
    fMappings[aIndex].first = aKey;
}

Node* InternalNode::firstChild() const
{
    return fMappings.front().second;
}

void InternalNode::populateNewRoot(Node *aOldNode, KeyType aNewKey, Node *aNewNode)
{
    fMappings.push_back(std::make_pair(DUMMY_KEY, aOldNode));
    fMappings.push_back(std::make_pair(aNewKey, aNewNode));
}

int InternalNode::insertNodeAfter(Node *aOldNode, KeyType aNewKey, Node *aNewNode)
{
    auto iter = fMappings.begin();
    for (; iter != fMappings.end() && iter->second != aOldNode; ++iter);
    fMappings.insert(iter + 1, std::make_pair(aNewKey, aNewNode));
    return size();
}

void InternalNode::remove(int aIndex)
{
    fMappings.erase(fMappings.begin() + aIndex);
}

Node* InternalNode::removeAndReturnOnlyChild()
{
    Node* firstChild = fMappings.front().second;
    fMappings.pop_back();
    return firstChild;
}

KeyType InternalNode::replaceAndReturnFirstKey()
{
    KeyType newKey = fMappings[0].first;
    fMappings[0].first = DUMMY_KEY;
    return newKey;
}

void InternalNode::moveHalfTo(InternalNode *aRecipient)
{
    aRecipient->copyHalfFrom(fMappings);
    size_t size = fMappings.size();
    for (size_t i = minSize(); i < size; ++i) {
        fMappings.pop_back();
    }
}

void InternalNode::copyHalfFrom(std::vector<MappingType> &aMappings)
{
    for (size_t i = minSize(); i < aMappings.size(); ++i) {
        aMappings[i].second->setParent(this);
        fMappings.push_back(aMappings[i]);
    }
}

void InternalNode::moveAllTo(InternalNode *aRecipient, int aIndexInParent)
{
    fMappings[0].first = static_cast<InternalNode*>(parent())->keyAt(aIndexInParent);
    aRecipient->copyAllFrom(fMappings);
    fMappings.clear();
}

void InternalNode::copyAllFrom(std::vector<MappingType> &aMappings)
{
    for (auto mapping : aMappings) {
        mapping.second->setParent(this);
        fMappings.push_back(mapping);
    }
}

void InternalNode::moveFirstToEndOf(InternalNode *aRecipient)
{
    aRecipient->copyLastFrom(fMappings.front());
    fMappings.erase(fMappings.begin());
    static_cast<InternalNode*>(parent())->setKeyAt(1, fMappings.front().first);
}

void InternalNode::copyLastFrom(MappingType aPair)
{
    fMappings.push_back(aPair);
    // fMappings.back().first = fMappings.back().second->fMappings.front().first;
    fMappings.back().first = fMappings.back().second->firstKey();
    fMappings.back().second->setParent(this);
}

void InternalNode::moveLastToFrontOf(InternalNode *aRecipient, int aParentIndex)
{
    aRecipient->copyFirstFrom(fMappings.back(), aParentIndex);
    fMappings.pop_back();
}

void InternalNode::copyFirstFrom(MappingType aPair, int aParentIndex)
{
    fMappings.front().first = static_cast<InternalNode*>(parent())->keyAt(aParentIndex);
    fMappings.insert(fMappings.begin(), aPair);
    fMappings.front().first = DUMMY_KEY;
    fMappings.front().second->setParent(this);
    static_cast<InternalNode*>(parent())->setKeyAt(aParentIndex, fMappings.front().first);
}

Node* InternalNode::lookup(KeyType aKey) const
{
    auto locator = fMappings.begin();
    auto end = fMappings.end();
    while (locator != end && aKey >= locator->first) {
        ++locator;
    }
    // locator->first is now the least key k such that aKey < k.
    // One before is the greatest key k such that aKey >= k.
    --locator;
    return locator->second;
}

int InternalNode::nodeIndex(Node *aNode) const
{
    for (size_t i = 0; i < size(); ++i) {
        if (fMappings[i].second == aNode) {
            return static_cast<int>(i);
        }
    }
    throw NodeNotFoundException(aNode->toString(), toString());
}

Node* InternalNode::neighbor(int aIndex) const
{
    return fMappings[aIndex].second;
}

std::string InternalNode::toString(bool aVerbose) const
{
    if (fMappings.empty()) {
        return "";
    }
    std::ostringstream keyToTextConverter;
    if (aVerbose) {
        keyToTextConverter << "[" << std::hex << this << std::dec << "]<" << fMappings.size() << "> ";
    }
    auto entry = aVerbose ? fMappings.begin() : fMappings.begin() + 1;
    auto end = fMappings.end();
    bool first = true;
    while (entry != end) {
        if (first) {
            first = false;
        } else {
            keyToTextConverter << " ";
        }
        keyToTextConverter << std::dec << entry->first;
        if (aVerbose) {
            keyToTextConverter << "(" << std::hex << entry->second << std::dec << ")";
        }
        ++entry;
    }
    return keyToTextConverter.str();
}

void InternalNode::queueUpChildren(std::queue<Node *>* aQueue)
{
    for (auto mapping : fMappings) {
        aQueue->push(mapping.second);
    }
}

const KeyType InternalNode::firstKey() const
{
    return fMappings[1].first;
}
