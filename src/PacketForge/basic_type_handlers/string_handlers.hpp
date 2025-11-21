#pragma once

#include "../core/serializer_traits.hpp"

#include <string>

template <>
struct Serializer<std::string>
{
    static void serialize(const std::string& value, std::vector<uint8_t>& packet);
};

template <>
struct Deserializer<std::string>
{
    static void deserialize(std::string& value, const std::vector<uint8_t>& packet, size_t& offset);
};