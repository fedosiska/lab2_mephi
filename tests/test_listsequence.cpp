#pragma once
#include <cassert>
#include <iostream>
#include "../include/ListSequence.hpp"

void test_ListSequence() {
    int items[] = {10, 20, 30, 40, 50};
    ListSequence<int> seq(items, 5);

    assert(seq.GetLength() == 5);
    assert(seq.GetFirst() == 10);
    assert(seq.GetLast() == 50);
    assert(seq.Get(2) == 30);

    seq.Append(60);
    assert(seq.GetLast() == 60);
    assert(seq.GetLength() == 6);

    seq.Prepend(5);
    assert(seq.GetFirst() == 5);
    assert(seq.GetLength() == 7);
    assert(seq.Get(1) == 10);

    seq.InsertAt(99, 3);
    assert(seq.Get(3) == 99);
    assert(seq.Get(4) == 30);

    Sequence<int>* sub = seq.GetSubSequence(2, 4);
    assert(sub->GetLength() == 3);
    assert(sub->Get(0) == 20);
    assert(sub->Get(1) == 99);
    assert(sub->Get(2) == 30);
    delete sub;

    ListSequence<int> other;
    other.Append(777);
    other.Append(888);

    Sequence<int>* concatenated = seq.Concat(other);
    assert(concatenated->GetLength() == seq.GetLength() + 2);
    assert(concatenated->Get(concatenated->GetLength() - 2) == 777);
    assert(concatenated->Get(concatenated->GetLength() - 1) == 888);
    delete concatenated;

    bool caught = false;
    try {
        seq.Get(-1);
    } catch (std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    caught = false;
    try {
        seq.InsertAt(100, -5);
    } catch (std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    std::cout << "All ListSequence tests passed!" << std::endl;
}


int main()
{
    test_ListSequence();
}