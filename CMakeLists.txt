cmake_minimum_required(VERSION 3.9)
project(filler)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

file(GLOB INC_LIB ./libs/libft/*.h)
file(GLOB INC_PRF ./libs/ft_printf/*.h)
file(GLOB INC_PROJ ./includes/*.h)
file(GLOB FILLER ./src/*.c)
file(GLOB SRCS_PRF ./libs/ft_printf/*.c)
file(GLOB SRCS_LIB ./libs/libft/*.c)
set(INC ${INC_LIB} ${INC_PRF} ${INC_PROJ})
set(LIBFT ${SRCS_LIB} ${SRCS_PRF})

include_directories("./libs/libft" "./libs/ft_printf" "./includes")
add_executable(imelnych.filler ${INC} ${LIBFT} ${FILLER})
