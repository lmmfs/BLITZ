#pragma once

#include <string>
#include <cstring>
#include <iostream>

namespace blitz {

    class FileUtils{
        public:
            static std::string read_file(const char* filePath) {
                FILE* file = fopen(filePath, "rt");
                if (!file) {
                    std::cerr << "Error: Could not open file " << filePath << std::endl;
                    return "";
                }

                if (fseek(file, 0, SEEK_END) != 0) {
                    std::cerr << "Error: fseek failed" << std::endl;
                    fclose(file);
                    return "";
                }

                long length = ftell(file);
                if (length < 0) {
                    std::cerr << "Error: ftell failed" << std::endl;
                    fclose(file);
                    return "";
                }

                rewind(file);
                
                char* data = new char[length + 1];
                if (!data) {
                    std::cerr << "Error: Memory allocation failed" << std::endl;
                    fclose(file);
                    return "";
                }

                std::memset(data, 0, length + 1);
                size_t readSize = fread(data, 1, length, file);
                if (readSize != static_cast<size_t>(length)) {
                    std::cerr << "Error: fread failed" << std::endl;
                    delete[] data;
                    fclose(file);
                    return "";
                }

                fclose(file);

                std::string result(data);
                delete[] data;
                return result;
            }
    };
    
}