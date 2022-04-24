// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdexcept>

#include "vector.h"

Vector::Vector(size_t capacity) {
    data_ = new Fraction[capacity];
    size_ = 0;
    capacity_ = capacity;
}

Vector::Vector(const Vector &vector) {
    data_ = new Fraction[vector.capacity_];
    size_ = vector.size_;
    capacity_ = vector.capacity_;

    std::copy(vector.data_, vector.data_ + vector.capacity_, data_);
}

Vector::Vector(Vector &&vector) noexcept {
    data_ = new Fraction[vector.capacity_];
    size_ = vector.size_;
    capacity_ = vector.capacity_;

    std::copy(vector.data_, vector.data_ + vector.capacity_, data_);

    delete[] vector.data_;
    vector.data_ = new Fraction[0];
    vector.size_ = 0;
    vector.capacity_ = 0;
}

Vector::~Vector() {
    delete[] data_;
}

const Fraction *Vector::data() {
    return data_;
}

size_t Vector::size() const {
    return size_;
}

size_t Vector::capacity() const {
    return capacity_;
}

void Vector::push_back(Fraction fraction) {
    if (size_ == capacity_) {
        auto* new_data_ = new Fraction[capacity_ + 1];
        std::copy(data_, data_ + size_, new_data_);

        delete[] data_;
        data_ = new_data_;
        capacity_ += 1;
    }
    data_[size_] = fraction;
    size_ += 1;
}

Vector &Vector::operator=(const Vector& vector) {
    if (this != &vector) {
        delete[] data_;
        data_ = new Fraction[vector.capacity_];
        size_ = vector.size_;
        capacity_ = vector.capacity_;

        std::copy(vector.data_, vector.data_ + vector.capacity_, data_);
    }
    return *this;
}

Vector &Vector::operator=(Vector&& vector) noexcept {
    if (this != &vector) {
        delete[] data_;
        data_ = new Fraction[vector.capacity_];
        size_ = vector.size_;
        capacity_ = vector.capacity_;

        std::copy(vector.data_, vector.data_ + vector.capacity_, data_);

        delete[] vector.data_;
        vector.data_ = new Fraction[0];
        vector.size_ = 0;
        vector.capacity_ = 0;
    }
    return *this;
}

Fraction &Vector::operator[](std::size_t index) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("No element at this index.");
    return data_[index];
}

const Fraction &Vector::operator[](std::size_t index) const {
    if (index < 0 || index >= size_)
        throw std::out_of_range("No element at this index.");
    return data_[index];
}
