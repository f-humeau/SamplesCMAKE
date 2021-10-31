cmake_minimum_required(VERSION 3.0.0)

set( IMT_PROJECT_NAME "mySample" )

project(${IMT_PROJECT_NAME}
	LANGUAGES CXX C
)

set(COMMON_INCLUDE ${PROJECT_SOURCE_DIR}/include )

set(REF_LIBRARIES_DIR  libs )


#########
# GTest #
#########
## enable_testing()
## add_subdirectory(libs/gtest-1.11.0)
## include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#==================================
# define GENERIC compiler options 
#==================================
add_library(IMT_compiler_flags INTERFACE)
target_compile_features(IMT_compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(IMT_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wformat=2;-Wno-unknown-pragmas;-Wno-unused;-Wno-switch>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:/wd4251>>"
)

if(WIN32)
	target_compile_definitions(IMT_compiler_flags INTERFACE OS_WINDOWS NOMINMAX _CRT_SECURE_NO_DEPRECATE )
elseif(UNIX)
	target_compile_definitions(IMT_compiler_flags INTERFACE OS_LINUX)
endif()

# Build myApp
add_subdirectory(myApp)

