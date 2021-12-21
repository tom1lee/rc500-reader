


add_library(BossReaderWriter
        BossReaderWriter.hpp
        BossReaderWriter.cpp
)



add_library(BossReaderWriter::BossReaderWriter ALIAS BossReaderWriter)

target_include_directories(BossReaderWriter
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/sources>
)


set(CMAKE_MODULE_PATH "/json/;${CMAKE_MODULE_PATH}")
find_package(nlohmann_json 3.10.4 REQUIRED)

target_link_libraries(BossReaderWriter
    PUBLIC
        nlohmann_json::nlohmann_json
    PRIVATE
        rapidxml::rapidxml
        pantor::inja
)
