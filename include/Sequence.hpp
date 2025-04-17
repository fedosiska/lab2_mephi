#pragma once

template<typename T>
class Sequence {
public:
    virtual void Append(T data) = 0;
    virtual void Prepend(T data) = 0;

    virtual T GetFirst() const = 0;

    virtual T GetLast() const = 0;

    virtual T Get(int index) const = 0;

    virtual int GetLength() const = 0;

    virtual Sequence<T> *GetSubSequence(int start, int end) const = 0;
    virtual Sequence<T> *Concat(const Sequence<T> &other) const = 0;

    virtual void InsertAt(T item, int index) = 0;
};