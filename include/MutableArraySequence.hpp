#pragma once
#include "BaseArraySequence.hpp"

template<typename T>
class MutableArraySequence : public BaseArraySequence<T> {
public:
    MutableArraySequence() : BaseArraySequence<T>() {}

    MutableArraySequence(T* items, int count) : BaseArraySequence<T>(items, count) {}

    MutableArraySequence(const DynamicArray<T>& other) : BaseArraySequence<T>(other) {}

    MutableArraySequence(const BaseArraySequence<T>& other) : BaseArraySequence<T>(other) {}

    BaseArraySequence<T>* Instance() override {
        return this;
    }

    BaseArraySequence<T>* Clone() const override {
        return new MutableArraySequence<T>(*this);
    }
};
