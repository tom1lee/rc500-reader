# CMake module to search for the nlohmann_json
# 
# If it's found it sets NLOHMANN_JSON_FOUND to TRUE
# and following variables are set:
#    NLOHMANN_JSON_INCLUDE_DIR
#    NLOHMANN_JSON_LIBRARY

FIND_PATH(NLOHMANN_JSON_INCLUDE_DIR NAMES yaml.h)
FIND_LIBRARY(NLOHMANN_JSON_LIBRARIES NAMES yaml libyaml)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NLOHMANN_JSON DEFAULT_MSG NLOHMANN_JSON_LIBRARIES NLOHMANN_JSON_INCLUDE_DIR)
MARK_AS_ADVANCED(NLOHMANN_JSON_INCLUDE_DIR NLOHMANN_JSON_LIBRARIES)
