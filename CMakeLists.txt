cmake_minimum_required(VERSION 3.19)
project(GameEindOpdrachtv2)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameEindOpdrachtv2 main.cpp Vector2.cpp Vector2.h Enemy.cpp Enemy.h Player.cpp Player.h Score.cpp Score.h Sound.cpp Sound.h TimeClass.cpp TimeClass.h Text.cpp Text.h Border.cpp Border.h stb_image.cpp stb_image.h DeltaTime.cpp DeltaTime.h)

include_directories(headers C:/SFML/include)
set(SFML_ROOT c:/SFML)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()