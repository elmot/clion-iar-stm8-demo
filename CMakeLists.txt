cmake_minimum_required(VERSION 3.20)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(clion-iar-stm8-demo C CXX)
add_link_options(--config lnkstm8s103k3.icf)
add_link_options("SHELL:--config_def _HEAP_SIZE=0x100")
add_link_options("SHELL:--config_def _CSTACK_SIZE=0x100")

add_executable(test_iar_avr main.c)