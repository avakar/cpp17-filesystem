cmake_minimum_required(VERSION 3.12)
project(avakar_cpp17_fs)

add_library(avakar_cpp17_fs INTERFACE)
add_library(avakar::cpp17_fs ALIAS avakar_cpp17_fs)
target_compile_features(avakar_cpp17_fs INTERFACE cxx_std_17)

include(CheckIncludeFileCXX)
check_include_file_cxx(filesystem HAS_FILESYSTEM)

if (NOT HAS_FILESYSTEM)
target_include_directories(avakar_cpp17_fs INTERFACE include)
target_link_libraries(avakar_cpp17_fs INTERFACE stdc++fs)
endif()

include(CTest)
if (BUILD_TESTING)
	add_executable(avakar_cpp17_fs_test
		test/test.cpp
		)
	target_link_libraries(avakar_cpp17_fs_test PRIVATE avakar::cpp17_fs)
endif()
