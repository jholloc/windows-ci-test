#include <iostream>
#include <libxml/xmlversion.h>
#include <capnp/common.h>
#include <openssl/opensslv.h>
#include <spdlog/version.h>
#include <boost/version.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, const char** argv)
{
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
    try {
        po::notify(vm);
    } catch (po::error& err) {
        if (vm.count("help")) {
            std::cout << "Usage: " << argv[0] << " [options] request\n";
            std::cout << desc << "\n";
            return 1;
        } else {
            std::cout << "Error: " << err.what() << "\n\n";
            std::cout << "Usage: " << argv[0] << " [options] request\n";
            std::cout << desc << "\n";
            return -1;
        }
    };

    if (vm.count("help")) {
        std::cout << "Usage: " << argv[0] << " [options] request\n";
        std::cout << desc << "\n";
        return 1;
    }

    std::cout << "libxml2 version = " << LIBXML_DOTTED_VERSION << std::endl;
    std::cout << "capnp version = " << CAPNP_VERSION << std::endl;
    std::cout << "openssl version = " << OPENSSL_VERSION_TEXT << std::endl;
    std::cout << "spdlog version = " << SPDLOG_VERSION << std::endl;
    std::cout << "boost version = " << BOOST_LIB_VERSION << std::endl;

    std::cout << "ok" << std::endl;

    return 0;
}
