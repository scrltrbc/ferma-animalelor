//
// Created by becbu on 12/7/2025.
//

#ifndef OOP_EXCEPTIONS_HPP
#define OOP_EXCEPTIONS_HPP
#include <stdexcept>
#include <string>

class Exception : public std::exception {
protected:
    std::string message;
public:
    explicit Exception(std::string  msg);
    [[nodiscard]] const char* what() const noexcept override;
    ~Exception() override = default;
};

class TextureLoadException : public Exception {
public:
    explicit TextureLoadException(const std::string& path);
};
class FontLoadException : public Exception {
public:
    explicit FontLoadException(const std::string& path);
};

#endif //OOP_EXCEPTIONS_HPP