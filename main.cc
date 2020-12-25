#include <iostream>
#include <string>
#include "controller.h"

int main(int argc, char **argv) {
    int width = 500;
    int height = 500;
    for (int i = 1; i < argc; ++i) {
        if (argv[i] == std::string("-width")) {
            if (i == argc - 1) {
                std::cerr << "no width inputed" << std::endl;
            } else if (argv[i + 1] <= 0) {
                std::cerr << "invalid width" << std::endl;
            } else {
                width = std::stoi(argv[i + 1]);
                i++;
            }
        } else if (argv[i] == std::string("-height")) {
            if (i == argc - 1) {
                std::cerr << "no height inputed" << std::endl;
            } else if (argv[i + 1] <= 0) {
                std::cerr << "invalid height" << std::endl;
            } else {
                height = std::stoi(argv[i + 1]);
                i++;
            }
        }
    }

    Controller ctr(width, height);

    ctr.Gameloop();
    return 0;
}
