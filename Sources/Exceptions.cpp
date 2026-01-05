//
// Created by becbu on 12/7/2025.
//

#include "../Headers/Exceptions.hpp"

Exception::Exception(std::string msg): message(std::move(msg)) {}

const char * Exception::what() const noexcept {
    return message.c_str();
}

TextureLoadException::TextureLoadException(const std::string &path): Exception("Failed to load texture from: " + path) {}

FontLoadException::FontLoadException(const std::string &path): Exception("Failed to load sf::Font from: " + path) {}
