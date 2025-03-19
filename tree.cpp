#include <algorithm>
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

namespace fs = std::filesystem;

class Tree {
private:
    // counting the number of directories and files
    size_t directories = 0;
    size_t files = 0;

    // The current dir being worked on
    // On creating Tree this will be the cwd or input directory
    fs::directory_entry workingDir;

    // strings for labelling the tree
    std::vector<std::string> inner_pointers = {"├── ", "│   "};
    std::vector<std::string> final_pointers = {"└── ", "    "};

public:
    void walk(std::string inputDir, std::string prefix) {

        // Store items in current directory being walked
        std::vector<fs::directory_entry> elements;
        // Which type of line to use
        std::vector<std::string> line;

        // Push each entry in directory into vector
        for (auto &entry : fs::directory_iterator(inputDir)) {
            elements.push_back(entry);
        }

        for (auto &element : elements) {

            // Determine line type
            if (element == elements[elements.size() - 1]) {
                line = final_pointers;
            } else {
                line = inner_pointers;
            }

            if (element.is_directory()) {
                // Increment count and print dir name
                // Do recursive call
                directories++;
                std::cout << BLU << prefix << line[0] << BGRN << element.path().filename().string() << CRESET << std::endl;
                walk(element.path(), prefix + line[1]);
            } else {
                // Increment and print
                files++;
                std::cout << BLU << prefix << line[0] << RED << element.path().filename().string() << CRESET << std::endl;
            }
        }
    }

    // Print summary of directory
    void count() {
        std::cout << "\n"
                  << MAG << directories << " directories, " << files << " files" << CRESET << std::endl;
    }
};

int main(int args, char *argv[]) {

    // Name of directory we want to display
    std::string dir;

    // if args include directory name set the name or curr directory name instead
    if (args == 2) {
        dir = argv[1];
    } else {
        dir = ".";
    }

    // Create tree object
    Tree tree;

    // Print the parent directory
    std::cout << BGRN << dir << CRESET << std::endl;
    // Begin recursive walk
    tree.walk(dir, "");

    tree.count();
}