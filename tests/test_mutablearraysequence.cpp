#pragma once
#include <cassert>
#include <iostream>
#include "../include/MutableArraySequence.hpp"

void test_MutableArraySequence() {
    int data[] = {1, 2, 3, 4, 5};
    MutableArraySequence<int> seq(data, 5);

    assert(seq.GetLength() == 5);
    assert(seq.GetFirst() == 1);
    assert(seq.Get(2) == 3);
    assert(seq.GetLast() == 5);

    seq.Append(6);
    assert(seq.GetLength() == 6);
    assert(seq.GetLast() == 6);

    seq.Prepend(0);
    assert(seq.GetLength() == 7);
    assert(seq.GetFirst() == 0);
    assert(seq.Get(1) == 1);

    seq.InsertAt(99, 3);
    assert(seq.Get(3) == 99);
    assert(seq.GetLength() == 8);

    Sequence<int>* sub = seq.GetSubSequence(2, 4);
    assert(sub->GetLength() == 3);
    assert(sub->Get(0) == seq.Get(2));
    assert(sub->Get(1) == seq.Get(3));
    assert(sub->Get(2) == seq.Get(4));
    delete sub;

    int more[] = {10, 11};
    MutableArraySequence<int> other(more, 2);
    Sequence<int>* concat = seq.Concat(other);
    assert(concat->GetLength() == seq.GetLength() + 2);
    assert(concat->Get(concat->GetLength() - 1) == 11);
    delete concat;

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

    std::cout << "All MutableArraySequence tests passed!" << std::endl;
}
int main()
{
    test_MutableArraySequence();
}