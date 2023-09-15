cmake_minimum_required( VERSION 3.14 )

project( Windows-CI-Test )

set( BOOST_ROOT ${_VCPKG_INSTALLED_DIR}/x64-mingw-static )

find_package( Boost COMPONENTS program_options REQUIRED )

add_executable( main src/main.cpp )
target_link_libraries( main
                       PRIVATE
                       Boost::program_options
                       )
