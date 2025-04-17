#pragma once
#include "DynamicArray.hpp"
#include "Sequence.hpp"

template<typename T>
class BaseArraySequence : public Sequence<T> {
protected:
    DynamicArray<T> array;

public:
    BaseArraySequence() {
        array.Resize(0);
    }

    BaseArraySequence(T* items, int count) {
        array.Resize(count);
        for (int i = 0; i < count; ++i)
            array.Set(i, items[i]);
    }

    BaseArraySequence(const DynamicArray<T>& other) : array(other) {}

    BaseArraySequence(const BaseArraySequence<T>& other) : array(other.array) {}

    T GetFirst() const override {
        return array.Get(0);
    }

    T GetLast() const override {
        return array.Get(array.GetSize() - 1);
    }

    T Get(int index) const override {
        return array.Get(index);
    }

    int GetLength() const override {
        return array.GetSize();
    }

    Sequence<T>* GetSubSequence(int start, int end) const override {
        BaseArraySequence<T>* sub = static_cast<BaseArraySequence<T>*>(this->Clone());
        sub->array = *(this->array.GetSubArray(start, end));
        return sub;
    }

    Sequence<T>* Concat(const Sequence<T>& other) const override {
        BaseArraySequence<T>* result = static_cast<BaseArraySequence<T>*>(this->Clone());
        for (int i = 0; i < other.GetLength(); ++i)
            result->AppendInternal(other.Get(i));
        return result;
    }
    //Instance()
    void Append(T item) override {
        Instance()->AppendInternal(item);
    }

    void Prepend(T item) override {
        Instance()->PrependInternal(item);
    }

    void InsertAt(T item, int index) override {
        Instance()->InsertAtInternal(item, index);
    }

    virtual void AppendInternal(T item) {
        array.Resize(array.GetSize() + 1);
        array.Set(array.GetSize() - 1, item);
    }

    virtual void PrependInternal(T item) {
        array.Resize(array.GetSize() + 1);
        for (int i = array.GetSize() - 1; i > 0; --i)
            array.Set(i, array.Get(i - 1));
        array.Set(0, item);
    }

    virtual void InsertAtInternal(T item, int index) {
        if (index < 0 || index > array.GetSize())
            throw std::out_of_range("Index out of range");
        array.Resize(array.GetSize() + 1);
        for (int i = array.GetSize() - 1; i > index; --i)
            array.Set(i, array.Get(i - 1));
        array.Set(index, item);
    }

    virtual BaseArraySequence<T>* Clone() const = 0;
    virtual BaseArraySequence<T>* Instance() = 0;
    virtual ~BaseArraySequence() = default;
};
