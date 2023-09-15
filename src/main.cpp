#include <iostream>
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

    std::cout << "ok" << std::endl;

    return 0;
}
