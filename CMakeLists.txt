cmake_minimum_required(VERSION 3.12)
project(PacketForge)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    src
    src/PacketForge
    src/PacketForge/basic_type_andlers
    src/core
    src/core/header_repository
)

add_library(PacketForge
    src/PacketForge/basic_type_handlers/int_handlers.cpp
    src/PacketForge/basic_type_handlers/string_handlers.cpp
    src/PacketForge/core/header_repository/deserializer_header_repository.cpp
    src/PacketForge/core/header_repository/header_repository_node.cpp
    src/PacketForge/core/header_repository/header_repository.cpp
    src/PacketForge/core/header_repository/serializer_header_repository.cpp
    src/PacketForge/core/command_serializers.cpp
    src/PacketForge/core/packet.cpp
    src/PacketForge/command_factory.cpp
)

add_executable(main_app src/main.cpp)
target_link_libraries(main_app PacketForge)
