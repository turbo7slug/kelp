#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: kelp <script.js>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string source = buffer.str();

    std::cout << "=== File Content ===" << std::endl;
    std::cout << source << std::endl;

    return 0;
}