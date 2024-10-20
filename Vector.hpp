#pragma once

#include <cstddef>

template<typename T>
class Vector 
{
public:
  Vector();
  Vector(unsigned int max_capacity);
  Vector(unsigned int max_capacity, const T& initial);
  Vector(const Vector& other);
  ~Vector();
  
  void push_back(const T& item);

  unsigned int size() const;
  unsigned int capacity() const;

  const T& front() const;
  const T& back() const;

  const T& operator[](int index) const;

  T& operator[](int index);

  Vector<T>& operator=(const Vector<T>& other);

private:
  unsigned int size_ = 0;
  unsigned int capacity_ = 64;
  T* array_;
};

template<typename T>
Vector<T>::Vector(): size_(0), capacity_(64), array_(new T[capacity_]) {};

template<typename T>
Vector<T>::Vector(unsigned int max_capacity)
                  : size_(max_capacity), capacity_(max_capacity), array_(new T[max_capacity]) {};

template<typename T>
Vector<T>::Vector(unsigned int max_capacity, const T& initial)
                  : size_(max_capacity), capacity_(max_capacity), array_(new T[max_capacity]) {
  for (unsigned int i = 0; i < max_capacity; i++) {
    array_[i] = initial;
  }
};

template<typename T>
Vector<T>::Vector(const Vector& other): size_(other.size()), capacity_(other.capacity()), 
                             array_(new T[capacity_]) {
  for (unsigned int i = 0; i < other.size(); i++) {
    array_[i] = other.array_[i];
  }
};

template<typename T>
Vector<T>::~Vector() {
  if (array_ != nullptr) {
    delete[] array_; 
  }
}
  
template<typename T>
void Vector<T>::push_back(const T& item) {
  if (size_ >= capacity_) {
    this->capacity_ = capacity_ * 2;

    T* tmp_arr = new T[capacity_];
    for (unsigned int i = 0; i < this->size(); i++) {
      tmp_arr[i] = array_[i];
    }
    delete[] array_;

    array_ = tmp_arr;
    tmp_arr = NULL;
  }

  array_[size_] = item;
  size_++;
}

template <typename T>
unsigned int Vector<T>::size() const {
  return size_;
}  

template <typename T>
unsigned int Vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
const T& Vector<T>::front() const {
  return array_[0];
}

template <typename T>
const T& Vector<T>::back() const {
  return array_[size_];
}

template <typename T>
const T& Vector<T>::operator[](int index) const {
  return array_[index];
}

template <typename T>
T& Vector<T>::operator[](int index) {
  return array_[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
  delete[] array_;
  size_ = other.size();
  capacity_ = other.capacity();

  array_ = new T[other.capacity()];

  for (unsigned int i = 0; i < other.size(); i++) {
    array_[i] = other.array_[i];
  }

  return *this;
}

