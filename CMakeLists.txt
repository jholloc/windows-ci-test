cmake_minimum_required( VERSION 3.14 )

project( Windows-CI-Test )

#find_package( LibXml2 REQUIRED )
find_package( Capnproto CONFIG REQUIRED )
#find_package( OpenSSL REQUIRED )
#find_package( spdlog REQUIRED )
#find_package( Boost COMPONENTS program_options REQUIRED )

add_executable( main src/main.cpp )
target_link_libraries( main
#                       LibXml2::LibXml2
                       CapnProto::capnp
#                       OpenSSL::SSL
#                       OpenSSL::Crypto
#                       spdlog::spdlog
                       )