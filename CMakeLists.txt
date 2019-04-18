cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME GuessWordX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH /Users/hey/Qt/5.12.2/clang_64)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
include_directories(3rdparty)
set(BACKEND_SOURCE_FILES
        3rdparty/nlohmann/json.hpp
        3rdparty/sqlite/sqlite3.h
        3rdparty/sqlite_modern_cpp.h
        3rdparty/
        3rdparty/sqlite/sqlite3.c
        src/backend/common.h  src/backend/AbstractRequestEndpoint.h src/backend/Dispatcher.h
        src/backend/enpoints/RegisterEndpoint.cpp src/backend/enpoints/RegisterEndpoint.h
        )

set(CLIENT_HEADER_FILES


        )
set(CLIENT_SOUECE_FILES
        src/UI/MainWindow.h
        src/UI/MainWindow.cpp
#        src/UI/ExaminerHome.cpp
#        src/UI/PlayerHome.cpp
        src/UI/RegisterDialog.cpp
#        src/UI/LoginDialog.cpp
#        src/UI/GamingDialog.cpp
        src/UI/MainWindow.h
#        src/UI/ExaminerHome.h
#        src/UI/PlayerHome.h
        src/UI/RegisterDialog.h
#        src/UI/LoginDialog.h
#        src/UI/GamingDialog.h
        src/transports/MessageBroker.cpp
        src/transports/MessageBroker.h
        src/UI/common.h)

set(TRANSPORT_CS_HEADER_FILES


        )
set(TRANSPORT_SERVER_SOURCE_FILES
        src/transports/Server.h
        src/transports/Server.cpp
        )

set(TRANSPORT_DIRECT_HEADER_FILES

        )
set(TRANSPORT_DIRECT_SOURCE_FILES

        )

set(RESOURCE_FILE resource.qrc)

# Set non-Debug build as GUI application.
# Debug build remains consle application.
if (NOT CMAKE_BUILD_TYPE MATCHES Debug) #Release, RelWithDebInfo and MinSizeRel
    if (WIN32) # Check if we are on Windows
        set(SYSTEM_TYPE WIN32)
    elseif (APPLE) # MacOS X
        set(SYSTEM_TYPE MACOSX_BUNDLE)
    else () # UNIX
        set(SYSTEM_TYPE EXCLUDE_FROM_ALL)
    endif ()
    message("System type is" ${SYSTEM_TYPE})
endif ()

add_executable(GuessWordXServer ${SYSTEM_TYPE} src/entry_server.cpp ${BACKEND_SOURCE_FILES} ${TRANSPORT_SERVER_SOURCE_FILES})
add_executable(GuessWordXClient ${SYSTEM_TYPE} src/entry_client.cpp ${CLIENT_SOUECE_FILES} ${RESOURCE_FILE})
add_executable(GuessWordXBundle ${SYSTEM_TYPE} src/entry_bundle.cpp ${BACKEND_SOURCE_FILES} ${CLIENT_SOUECE_FILES} ${TRANSPORT_DIRECT_SOURCE_FILES} ${RESOURCE_FILE})

target_link_libraries(GuessWordXClient Qt5::Widgets Qt5::Gui Qt5::Core Qt5::OpenGL Qt5::Network)
target_link_libraries(GuessWordXBundle Qt5::Widgets Qt5::Gui Qt5::Core Qt5::OpenGL Qt5::Network)

target_compile_definitions(GuessWordXClient PUBLIC TRANSPORT_SOCKET)
target_compile_definitions(GuessWordXBundle PUBLIC TRANSPORT_DIRECT)