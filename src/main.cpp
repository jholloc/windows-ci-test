#include <iostream>
#include <libxml/xmlversion.h>
#include <capnp/common.h>
#include <openssl/opensslv.h>
#include <spdlog/version.h>
#include <boost/version.hpp>
#include <boost/program_options.hpp>
#include <sys/time.h>
#include <fmt/format.h>

#ifdef _WIN32
#  ifdef UDA_EXPORT
#    define LIBRARY_API __declspec(dllexport)
#  else
#    define LIBRARY_API __declspec(dllimport)
#  endif
#else
#  define LIBRARY_API
#endif

#if defined(_WIN32)
#if !defined(__MINGW32__)
LIBRARY_API int gettimeofday(struct timeval* tp, struct timezone* tzp);
#endif
#endif

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

    timeval current = {};
    gettimeofday(&current, nullptr);
    std::cout << "time = " << current.tv_sec << std::endl;

    const char* logdir = "/tmp/uda/log";
    std::string cmd = fmt::format("mkdir -p {} 2>/dev/null", logdir);
    std::cout << "cmd = " << cmd << std::endl;

    return 0;
}
