#include "packet.hpp"

std::vector<uint8_t> Packet::build() const
{
    std::vector<uint8_t> packet;
    packet.insert(packet.end(), header_.begin(), header_.end());
    if (serializer_) serializer_->serialize(packet);
    return packet;
}