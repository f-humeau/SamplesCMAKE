cmake_minimum_required(VERSION 3.0.0)

# set the project name and version
project( myApp
	LANGUAGES CXX C
)
set( DIR_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/ )

set(HEADER_FILES
	${DIR_FILES}/myClass.h
    ${DIR_FILES}/myClassUser.h
)

set(SOURCE_FILES
	${DIR_FILES}/main.cpp
	${DIR_FILES}/myClass.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# ajoute répertoire "/include" racine
target_include_directories(${PROJECT_NAME} PRIVATE ${COMMON_INCLUDE})

# target_link_libraries(${PROJECT_NAME} /*myLibsA*/ )

########################
# add compiler options 
########################
target_link_libraries(${PROJECT_NAME} IMT_compiler_flags)
