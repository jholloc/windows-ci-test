cmake_minimum_required( VERSION 3.14 )

project( Windows-CI-Test )

set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/Modules )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${_VCPKG_INSTALLED_DIR}/x64-mingw-static )

find_package( LibXml2 REQUIRED )
find_package( Capnproto CONFIG REQUIRED )
find_package( OpenSSL REQUIRED )
find_package( spdlog REQUIRED )
find_package( fmt REQUIRED )
find_package( Boost COMPONENTS program_options REQUIRED )
if( WIN32 OR MINGW )
  find_package( XDR REQUIRED )
  if( NOT MINGW )
    find_package( dlfcn-win32 CONFIG REQUIRED )
  endif()
endif()

add_executable( main src/main.cpp )
target_include_directories( main PRIVATE ${XDR_INCLUDE_DIR} )
target_link_libraries( main
                       PRIVATE
                       LibXml2::LibXml2
                       CapnProto::capnp
                       OpenSSL::SSL
                       OpenSSL::Crypto
                       spdlog::spdlog
                       fmt::fmt
                       )

if( WIN32 OR MINGW )
  target_link_libraries( main PRIVATE ${XDR_LIBRARIES} )
  if( NOT MINGW )
    target_link_libraries( main PRIVATE dlfcn-win32::dl )
  endif()
endif()
