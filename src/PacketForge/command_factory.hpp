#pragma once

#include "core/packet.hpp"
#include "core/command_serializers.hpp"
#include "core/header_repository/header_repository.hpp"
#include "core/header_repository/command_type.hpp"

#include <unordered_map>
#include <functional>
#include <memory>

class CommandFactory
{
public:
    template <typename CommandType, typename ArgStruct>
    void registerCommand(CommandType cmd, const std::vector<uint8_t>& header)
    {
        headers.addHeader(cmd, header);
        deserializers_[static_cast<uint32_t>(cmd)] = []
        {
            return std::make_unique<CommandDeserializer<ArgStruct>>();
        };
    }

    template <typename CommandType, typename ArgStruct>
    Packet create(CommandType cmd, ArgStruct&& args) const
    {
        return Packet(
            cmd,
            std::make_unique<CommandSerializer<ArgStruct>>(std::forward<ArgStruct>(args)),
            headers
        );
    }

    std::pair<CommandType, std::unique_ptr<IDeserializer>>
    deserializePacket(const std::vector<uint8_t>& packet) const;

private:
    HeaderRepository headers;
    std::unordered_map<uint32_t, std::function<std::unique_ptr<IDeserializer>()>> deserializers_;
};

#define REGISTER_COMMAND(factory, cmd, arg_struct, header)                  \
    factory.template registerCommand<CommandType, arg_struct>(cmd, header);

