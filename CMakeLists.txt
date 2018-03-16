cmake_minimum_required(VERSION 3.9)
project(filler)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
file(GLOB INC_LIB ./libs/libft/*.h)
file(GLOB INC_PROJ ./includes/*.h)
file(GLOB FILLER ./src/*.c)
file(GLOB SRCS_LIB ./libs/libft/*.c)
set(INC ${INC_LIB} ${INC_PROJ})
set(LIBFT ${SRCS_LIB} )

include_directories("./libs/libft" "./includes")
add_executable(imelnych.filler ${INC} ${LIBFT} ${FILLER})
