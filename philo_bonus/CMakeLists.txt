project(philo LANGUAGES C)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 99)

include_directories(include ../libft)
link_directories(../libft)
link_libraries(ft)

file(GLOB SRC src/*.c)
add_executable(philo_bonus ${SRC})
target_compile_options(philo_bonus PRIVATE -Wall -Wextra -Werror -pthread -g)