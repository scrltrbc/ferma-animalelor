//
// Created by becbu on 12/7/2025.
//

#ifndef OOP_CUSTOMALLOCATOR_HPP
#define OOP_CUSTOMALLOCATOR_HPP
#include <iostream>

template <typename T>
class CA : public std::allocator<T> {
public:
    size_t max_size() const noexcept {
        return 100;
    }
};


#endif //OOP_CUSTOMALLOCATOR_HPP