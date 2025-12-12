#include <iostream>
#include <fstream>
#include <string>

bool copy_and_replace(std::string filename, std::string s1, std::string s2) {
    std::ifstream infile(filename.c_str());
    
    if (!infile) {
        std::cerr << "Error during the opening of the file" << std::endl;
        return (1);
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile) {
        infile.close();
        std::cerr << "Error during the opening of the file" << std::endl;
        return (1);
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::size_t pos = 0;
        std::size_t found;
        std::string new_line;

        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            new_line += line.substr(pos, found - pos);
            new_line += s2;
            pos = found + s1.length();
        }
        new_line += line.substr(pos);
        outfile << new_line << std::endl;   
    }

    outfile.close();
    infile.close();
    return (0);
}

bool check_args(std::string filename, std::string s1, std::string s2) {
    if (filename.empty() || s1.empty() || s2.empty())
        return (1);
    return (0);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Wrong number of arguments" << std::endl;
        return (1);
    }

    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    if (check_args(filename, s1, s2)) {
        std::cout << "parameters contain an empty arg" << std::endl;
        return (1);
    }

    if (copy_and_replace(filename, s1, s2))
        return (1);
    return (0);
}
