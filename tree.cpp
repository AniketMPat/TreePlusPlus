#include <algorithm>
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

class Tree {
private:
    // counting the number of directories and files
    size_t directories;
    size_t files;

    // strings for labelling the tree
    std::vector<std::string> inner_pointers = {"├── ", "│   "};
    std::vector<std::string> final_pointers = {"└── ", "    "};

public:
};