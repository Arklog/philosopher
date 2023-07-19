project(philo)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 99)

include_directories(include libft)
link_directories(libft)

add_compile_options(-Wall -Wextra -Werror)
file(GLOB SRC src/*.c)

add_executable(philo ${SRC} main.c)
target_link_libraries(philo ft pthread)