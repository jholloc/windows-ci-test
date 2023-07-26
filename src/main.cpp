#include <iostream>
#include <libxml/xmlversion.h>
#include <capnp/common.h>
#include <openssl/opensslv.h>
#include <spdlog/version.h>
#include <boost/version.hpp>
#include <rpc/rpc.h>

#if defined(_WIN32)
#if !defined(MINGW)
LIBRARY_API int gettimeofday(struct timeval* tp, struct timezone* tzp);
#endif
#endif

int main()
{
    std::cout << "libxml2 version = " << LIBXML_DOTTED_VERSION << std::endl;
    std::cout << "capnp version = " << CAPNP_VERSION << std::endl;
    std::cout << "openssl version = " << OPENSSL_VERSION_TEXT << std::endl;
    std::cout << "spdlog version = " << SPDLOG_VERSION << std::endl;
    std::cout << "boost version = " << BOOST_LIB_VERSION << std::endl;
    std::cout << "rpc version = " << MAX_NETOBJ_SZ << std::endl;
    return 0;
}