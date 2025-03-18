#include <algorithm>
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class Tree {
private:
    // counting the number of directories and files
    size_t directories;
    size_t files;

    // The current dir being worked on
    // On creating Tree this will be the cwd or input directory
    fs::directory_entry workingDir;

    // strings for labelling the tree
    std::vector<std::string> inner_pointers = {"├── ", "│   "};
    std::vector<std::string> final_pointers = {"└── ", "    "};

public:
    Tree(std::string inputDir) {

        std::string pathStr = fs::current_path().string();
        if (inputDir != ".") {
            pathStr = pathStr + "/" + inputDir;
        }
        std::cout << pathStr << std::endl;

        fs::path p = fs::path("..");
        std::cout << p << std::endl;
    }

    // void getInputDir(std::string &input) {
    //     fs::path currPath = fs::current_path();
    //     std::cout << currPath << std::endl;
    // }
};

int main(int args, char *argv[]) {

    std::string dir; // Name of directory we want to display

    // if args include directory name set the name or curr directory name instead
    if (args == 2) {
        dir = argv[1];
    } else {
        dir = ".";
    }

    Tree tree(dir);

    // std::string RED = "033[1;31m";
    // std::string NOCOLOUR = "33[0m]";
}