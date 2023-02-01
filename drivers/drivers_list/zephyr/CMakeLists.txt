
zephyr_library()

list(APPEND
  DTS_ROOT
  ${CMAKE_CURRENT_LIST_DIR}
  )

zephyr_library_sources(src/drivers_list.c)
zephyr_include_directories(include)