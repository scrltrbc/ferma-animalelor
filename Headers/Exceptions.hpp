//
// Created by becbu on 12/7/2025.
//

#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP
#include <stdexcept>
#include <string>

class Exception : public std::exception {
protected:
    std::string mEsSAgE;
public:
    explicit Exception(std::string  mSg);
    [[nodiscard]] const char* what() const noexcept override;
    ~Exception() override = default;
};

class TextureLoadException : public Exception {
public:
    explicit TextureLoadException(const std::string& pAtH);
};

class FontLoadException : public Exception {
public:
    explicit FontLoadException(const std::string& paTh);
};

#endif //OOP_EXCEPTIONS_HPP