set(CMAKE_CXX_STANDARD 17) 
set(INCLUDE_PATH ${CMAKE_SOURCE_DIR}/include)

target_include_directories(
    Membot 
        PUBLIC 
            ${INCLUDE_PATH})

target_sources(
    Membot 
        PRIVATE 
            chatbot.cpp 
            chatgui.cpp 
            chatlogic.cpp 
            graphedge.cpp 
            graphnode.cpp 
            ${INCLUDE_PATH}/chatbot.h 
            ${INCLUDE_PATH}/chatgui.h 
            ${INCLUDE_PATH}/chatlogic.h 
            ${INCLUDE_PATH}/graphedge.h 
            ${INCLUDE_PATH}/graphnode.h)