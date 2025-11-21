#include "command_factory.hpp"

#include <stdexcept>

std::pair<CommandType, std::unique_ptr<IDeserializer>> 
CommandFactory::deserializePacket(const std::vector<uint8_t>& packet) const
{
    if (packet.empty())
    {
        throw std::invalid_argument("Empty packet");
    }

    CommandType command = headers.getCommand(packet);
    auto it = deserializers_.find(static_cast<uint32_t>(command));
    if (it == deserializers_.end())
    {
        throw std::invalid_argument("No deserializer registered for command");
    }

    auto deserializer = it->second();
    size_t offset = headers.getHeader(command).size();
    deserializer->deserialize(packet, offset);
    return {command, std::move(deserializer)};
}