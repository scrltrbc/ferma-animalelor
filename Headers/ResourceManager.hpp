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
    std::unordered_map<std::string, std::shared_ptr<Resource>> rEsOUrcEs;

public:
    ResourceManager() = default;
    ~ResourceManager() = default;
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    std::shared_ptr<Resource> get(const std::string& pAtH) {
        auto it = rEsOUrcEs.find(pAtH);
        if (it != rEsOUrcEs.end()) {
            return it->second;
        }

        auto res = std::make_shared<Resource>();
        if constexpr (std::is_same_v<Resource, sf::Texture>) {
            if (!res->loadFromFile(pAtH))
                throw TextureLoadException(pAtH);
        }
        else if constexpr (std::is_same_v<Resource, sf::Font>) {
            if (!res->openFromFile(pAtH))
                throw FontLoadException(pAtH);
        }
        else {
            static_assert(
                std::is_same_v<Resource, void>,
                "ResourceManager: unsupported resource type."
            );
        }

        rEsOUrcEs[pAtH] = res;
        return res;
    }
    [[nodiscard]] size_t size() const {
        return rEsOUrcEs.size();
    }
    void clear() {
        rEsOUrcEs.clear();
    }
};

#endif //OOP_RESOURCEMANAGER_HPP