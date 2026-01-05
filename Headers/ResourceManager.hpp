//
// Created by becbu on 12/7/2025.
//

#ifndef OOP_RESOURCEMANAGER_HPP
#define OOP_RESOURCEMANAGER_HPP
#include <unordered_map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../Headers/Exceptions.hpp"

template<typename Resource>
class ResourceManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Resource>> items;

public:
    ResourceManager() = default;
    ~ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    std::shared_ptr<Resource> get(const std::string& path) {
        auto it = items.find(path);
        if (it != items.end()) {
            return it->second;
        }

        auto res = std::make_shared<Resource>();
        if constexpr (std::is_same_v<Resource, sf::Texture>) {
            if (!res->loadFromFile(path))
                throw TextureLoadException(path);
        }
        else if constexpr (std::is_same_v<Resource, sf::Font>) {
            if (!res->openFromFile(path))
                throw FontLoadException(path);
        }
        else {
            static_assert(
                std::is_same_v<Resource, void>,
                "ResourceManager: unsupported resource type."
            );
        }

        items[path] = res;
        return res;
    }
    [[nodiscard]] size_t size() const {
        return items.size();
    }
    void clear() {
        items.clear();
    }
};

#endif //OOP_RESOURCEMANAGER_HPP