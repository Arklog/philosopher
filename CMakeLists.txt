project(philo)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 99)

include_directories(include libft)
file(GLOB SRC src/*.c)

add_executable(philo ${SRC})
target_link_libraries(philo libft)