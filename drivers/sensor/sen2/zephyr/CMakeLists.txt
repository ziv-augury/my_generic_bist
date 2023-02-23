zephyr_library()

list(APPEND
  DTS_ROOT
  ${CMAKE_CURRENT_LIST_DIR}
  )

zephyr_library_sources(src/sen2.c)

zephyr_include_directories(include)
zephyr_include_directories(../../../../include)

# zephyr_library_compile_options(-Werror)
