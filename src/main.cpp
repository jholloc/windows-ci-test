#include <iostream>
#include <libxml/xmlversion.h>

int main()
{
    std::cout << "libxml2 version = " << LIBXML_DOTTED_VERSION << std::endl;
    return 0;
}