cmake_minimum_required( VERSION 3.14 )

project( Windows-CI-Test )

set( CMAKE_PREFIX_PATH ${_VCPKG_INSTALLED_DIR}/x64-mingw-static )
#set( BOOST_ROOT ${_VCPKG_INSTALLED_DIR}/x64-mingw-static )

find_package( LibXml2 REQUIRED )
find_package( Capnproto CONFIG REQUIRED )
find_package( OpenSSL REQUIRED )
find_package( spdlog REQUIRED )
find_package( fmt REQUIRED )
find_package( Boost COMPONENTS program_options REQUIRED )

add_executable( main src/main.cpp )
target_link_libraries( main
                       PRIVATE
                       Boost::program_options
                       LibXml2::LibXml2
                       CapnProto::kj CapnProto::capnp CapnProto::capnpc CapnProto::kj-gzip
                       OpenSSL::SSL OpenSSL::Crypto
                       spdlog::spdlog
                       fmt::fmt
                       )
