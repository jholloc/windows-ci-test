cmake_minimum_required( VERSION 3.14 )

project( Windows-CI-Test )

find_package( LibXml2 REQUIRED )

add_executable( main src/main.cpp )
target_link_libraries( main LibXml2::LibXml2 )