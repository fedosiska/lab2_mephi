#pragma once
#include "BaseArraySequence.hpp"

template<typename T>
class ImmutableArraySequence : public BaseArraySequence<T> {
public:
    ImmutableArraySequence() : BaseArraySequence<T>() {}

    ImmutableArraySequence(T* items, int count) : BaseArraySequence<T>(items, count) {}

    ImmutableArraySequence(const DynamicArray<T>& other) : BaseArraySequence<T>(other) {}

    ImmutableArraySequence(const BaseArraySequence<T>& other) : BaseArraySequence<T>(other) {}

    BaseArraySequence<T>* Instance() override {
        return this->Clone();
    }
    BaseArraySequence<T>* Clone() const override {
        return new ImmutableArraySequence<T>(*this);
    }
};
