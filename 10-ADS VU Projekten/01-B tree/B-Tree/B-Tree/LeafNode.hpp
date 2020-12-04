//
//  LeafNode.hpp
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
#include <utility>
#include <vector>
#include "Node.hpp"
#include "Record.hpp"

class LeafNode : public Node
{
public:
    explicit LeafNode(int aOrder);
    explicit LeafNode(int aOrder, Node* aParent);
    ~LeafNode() override;
    using MappingType = std::pair<KeyType, Record*>;
    using EntryType = std::tuple<KeyType, ValueType, LeafNode*>;
    bool isLeaf() const override;
    LeafNode* next() const;
    void setNext(LeafNode* aNext);
    int size() const override;
    int minSize() const override;
    int maxSize() const override;
    int createAndInsertRecord(KeyType aKey, ValueType aValue);
    void insert(KeyType aKey, Record* aRecord);
    Record* lookup(KeyType aKey) const;
    int removeAndDeleteRecord(KeyType aKey);
    const KeyType firstKey() const override;
    void moveHalfTo(LeafNode* aRecipient);
    void moveAllTo(LeafNode* aRecipient, int /* Unused */);
    void moveFirstToEndOf(LeafNode* aRecipient);
    void moveLastToFrontOf(LeafNode* aRecipient, int aParentIndex);
    void copyRangeStartingFrom(KeyType aKey, std::vector<EntryType>& aVector);
    void copyRangeUntil(KeyType aKey, std::vector<EntryType>& aVector);
    void copyRange(std::vector<EntryType>& aVector);
    std::string toString(bool aVerbose = false) const override;
private:
    void copyHalfFrom(std::vector<MappingType>& aMappings);
    void copyAllFrom(std::vector<MappingType>& aMappings);
    void copyLastFrom(MappingType aPair);
    void copyFirstFrom(MappingType aPair, int aParentIndex);
    std::vector<MappingType> fMappings;
    LeafNode* fNext;
};
