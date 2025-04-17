#pragma once
#include <cassert>
#include <iostream>
#include "../include/ImmutableArraySequence.hpp"

void test_ImmutableArraySequence(){
    int data[] = {1,2,3,4,5};
    ImmutableArraySequence<int> seq(data,5);
    
    assert(seq.GetLength()==5);
    assert(seq.GetFirst() == 1);
    assert(seq.Get(2) == 3);
    assert(seq.GetLast() == 5);

    auto* appended = static_cast<ImmutableArraySequence<int>*>(seq.Clone());
    appended->AppendInternal(6);
    assert(appended->GetLength() == 6);
    assert(appended->GetLast() == 6);
    delete appended;

    auto* prepended = static_cast<ImmutableArraySequence<int>*>(seq.Clone());
    prepended->PrependInternal(0);
    assert(prepended->GetLength() == 6);
    assert(prepended->GetFirst() == 0);
    assert(prepended->Get(1) == 1);
    delete prepended;

    auto* inserted = static_cast<ImmutableArraySequence<int>*>(seq.Clone());
    inserted->InsertAtInternal(99, 2);
    assert(inserted->GetLength() == 6);
    assert(inserted->Get(2) == 99);
    assert(inserted->Get(3) == 3);
    delete inserted;

    Sequence<int>* sub = seq.GetSubSequence(1, 3);
    assert(sub->GetLength() == 3);
    assert(sub->Get(0) == 2);
    assert(sub->Get(1) == 3);
    assert(sub->Get(2) == 4);
    delete sub;

    int more[] = {10, 11};
    ImmutableArraySequence<int> other(more, 2);
    Sequence<int>* concat = seq.Concat(other);
    assert(concat->GetLength() == 7);
    assert(concat->Get(5) == 10);
    assert(concat->Get(6) == 11);
    delete concat;

    bool caught = false;
    try {
        seq.Get(-1);
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    caught = false;
    try {
        auto* badInsert = static_cast<ImmutableArraySequence<int>*>(seq.Clone());
        badInsert->InsertAtInternal(100, -5);
        delete badInsert;
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    std::cout << "All ImmutableArraySequence tests passed!" << std::endl;
}

int main(){
    test_ImmutableArraySequence();
}