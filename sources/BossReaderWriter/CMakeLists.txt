


add_library(BossReaderWriter
        BossReaderWriter.hpp
        BossReaderWriter.cpp
)



add_library(BossReaderWriter::BossReaderWriter ALIAS BossReaderWriter)

target_include_directories(BossReaderWriter
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/sources>
)



find_package(nlohmann_json REQUIRED)

target_link_libraries(BossReaderWriter
    PUBLIC
       $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/sources>
        nlohmann_json::nlohmann_json
    PRIVATE
        rapidxml::rapidxml
        pantor::inja
)
