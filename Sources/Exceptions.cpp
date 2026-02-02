//
// Created by becbu on 12/7/2025.
//

#include "../Headers/Exceptions.hpp"

Exception::Exception(std::string mSg): mEsSAgE(std::move(mSg)) {}

const char * Exception::what() const noexcept {
    return mEsSAgE.c_str();
}

TextureLoadException::TextureLoadException(const std::string &pAtH): Exception("Failed to load texture from: " + pAtH) {}

FontLoadException::FontLoadException(const std::string &paTh): Exception("Failed to load sf::Font from: " + paTh) {}
