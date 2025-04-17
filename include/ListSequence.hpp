#pragma once
#include "LinkedList.hpp"
#include "Sequence.hpp"

template<typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> list;
    
public:
    ListSequence() = default;

    ListSequence(T* items, int count) {
        for (int i = 0; i < count; ++i) list.append(items[i]);
    }

    ListSequence(const ListSequence<T> &other) : list(other.list) {}

    ListSequence(const LinkedList<T> &otherLiList) : list(otherLiList) {}

    void Append(T data) override { list.append(data); }
    void Prepend(T data) override { list.prepend(data); }
    T GetFirst() const override { return list.GetFirst(); }
    T GetLast() const override { return list.GetLast(); }
    T Get(int index) const override { return list.get(index); }
    int GetLength() const override { return list.GetLength(); }
    void InsertAt(T item, int index) override { list.InsertAt(item, index); }
    Sequence<T>* GetSubSequence(int start, int end) const override { 
        LinkedList<T> *sub = list.GetSubList(start, end);
        return new ListSequence<T>(*sub); 
    }
    Sequence<T> *Concat(const Sequence<T> &other) const override
    {
        auto *result = new ListSequence<T>(*this);
        for (int i = 0; i < other.GetLength(); ++i){
            result->Append(other.Get(i));
        }
        return result;
    }
};
