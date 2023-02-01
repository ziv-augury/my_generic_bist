# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)


list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_LIST_DIR}/../drivers/drivers_list/)
list(APPEND
    DTS_ROOT
    ${CMAKE_CURRENT_LIST_DIR}/../drivers/drivers_list/zephyr/
    )

if("${BOARD}" MATCHES "my_board_1")
    list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_LIST_DIR}/../drivers/sensor/sen1/)
    list(APPEND
        DTS_ROOT
        ${CMAKE_CURRENT_LIST_DIR}/../drivers/sensor/sen1/zephyr/
        )
endif()


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(my_bist_example)

target_sources(app PRIVATE src/main.c)
target_sources(app PRIVATE src/bist_manager.c)



zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/../drivers/include)

# zephyr_library_compile_options(-Werror)