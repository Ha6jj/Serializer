#pragma once

#include "serialization_base.hpp"
#include "header_repository/header_repository.hpp"

#include <vector>
#include <memory>

class Packet
{
public:
    template <typename Command>
    Packet(Command cmd, 
           std::unique_ptr<ISerializer> serializer,
           const HeaderRepository& header_repo)
        : header_(header_repo.getHeader(cmd)), serializer_(std::move(serializer)) {}

    std::vector<uint8_t> build() const;

private:
    std::vector<uint8_t> header_;
    std::unique_ptr<ISerializer> serializer_;
};