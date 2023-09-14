cmake_minimum_required( VERSION 3.14 )

project( Windows-CI-Test )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/Modules )

find_package( Boost COMPONENTS program_options REQUIRED )

add_executable( main src/main.cpp )
target_link_libraries( main
                       PRIVATE
                       Boost::program_options
                       )
