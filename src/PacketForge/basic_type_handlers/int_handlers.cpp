#include "int_handlers.hpp"

#include <stdexcept>


void Serializer<uint8_t>::serialize(uint8_t value, std::vector<uint8_t>& packet)
{
    packet.push_back(value);
}

void Serializer<uint16_t>::serialize(uint16_t value, std::vector<uint8_t>& packet)
{
    packet.push_back(static_cast<uint8_t>(value & 0xFF));
    packet.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
}

void Serializer<uint32_t>::serialize(uint32_t value, std::vector<uint8_t>& packet)
{
    for (int i = 0; i < 4; ++i)
    {
        packet.push_back(static_cast<uint8_t>(value & 0xFF));
        value >>= 8;
    }
}


void Deserializer<uint8_t>::deserialize(uint8_t& value, const std::vector<uint8_t>& packet, size_t& offset)
{
    if (offset >= packet.size()) throw std::out_of_range("Packet too short");

    value = packet[offset++];
}

void Deserializer<uint16_t>::deserialize(uint16_t& value, const std::vector<uint8_t>& packet, size_t& offset)
{
    if (offset + 2 > packet.size()) throw std::out_of_range("Packet too short");

    value = static_cast<uint16_t>(packet[offset]) 
            | (static_cast<uint16_t>(packet[offset + 1]) << 8);
        offset += 2;
}

void Deserializer<uint32_t>::deserialize(uint32_t& value, const std::vector<uint8_t>& packet, size_t& offset)
{
    if (offset + 4 > packet.size()) throw std::out_of_range("Packet too short");

    value = 0;
    for (int i = 0; i < 4; ++i)
    {
        value |= static_cast<uint32_t>(packet[offset++]) << (i * 8);
    }
}