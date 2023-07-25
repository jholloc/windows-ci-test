#include <iostream>
#include <libxml/xmlversion.h>
#include <capnp/common.h>
#include <openssl/opensslv.h>
#include <spdlog/version.h>
#include <boost/version.hpp>
#include <rpc/rpc.h>

int main()
{
    std::cout << "libxml2 version = " << LIBXML_DOTTED_VERSION << std::endl;
    std::cout << "capnp version = " << CAPNP_VERSION << std::endl;
    std::cout << "openssl version = " << OPENSSL_VERSION_TEXT << std::endl;
    std::cout << "spdlog version = " << SPDLOG_VERSION << std::endl;
    std::cout << "boost version = " << BOOST_LIB_VERSION << std::endl;
    std::cout << "rpc version = " << RPC_MSG_VERSION << std::endl;
    return 0;
}