# GIF cmakelists.txt
cmake_minimum_required(VERSION 2.8)

include(${CMAKE_CURRENT_LIST_DIR}/../../lib/CMakeLists.txt)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
  if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions("-ggdb")
  endif()
  if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUGS} /Od /ZI")
    endif()
endif()

set(gif_base_dir ${CMAKE_CURRENT_LIST_DIR})
set(gif_src_dir ${gif_base_dir}/src)
set(gif_include_dir ${gif_base_dir}/include)
set(gif_lib_dir ${gif_base_dir}/lib/${roxlu_platform}/${roxlu_bits})

include_directories(
  ${gif_include_dir}
  ${gif_src_dir}
)

set(gif_source_files
  ${gif_src_dir}/gif/Gif.cpp
  ${gif_src_dir}/gif/GifIO.c
  ${gif_src_dir}/gif/MedianCut.cpp
  ${gif_src_dir}/gif/GifOpenGL.cpp
)

set(roxlu_addon_sources 
  ${roxlu_addon_sources} 
  ${gif_source_files}
)


add_library(roxlu_gif STATIC ${gif_source_files})
