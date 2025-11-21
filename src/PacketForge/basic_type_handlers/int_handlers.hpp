#pragma once

#include "../core/serializer_traits.hpp"

// Serializer specializations
template <>
struct Serializer<uint8_t>
{
    static void serialize(uint8_t value, std::vector<uint8_t>& packet);
};

template <>
struct Serializer<uint16_t>
{
    static void serialize(uint16_t value, std::vector<uint8_t>& packet);
};

template <>
struct Serializer<uint32_t>
{
    static void serialize(uint32_t value, std::vector<uint8_t>& packet);
};

// Deserializer specializations
template <>
struct Deserializer<uint8_t>
{
    static void deserialize(uint8_t& value, const std::vector<uint8_t>& packet, size_t& offset);
};

template <>
struct Deserializer<uint16_t>
{
    static void deserialize(uint16_t& value, const std::vector<uint8_t>& packet, size_t& offset);
};

template <>
struct Deserializer<uint32_t>
{
    static void deserialize(uint32_t& value, const std::vector<uint8_t>& packet, size_t& offset);
};
