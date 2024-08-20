#pragma once

#include <string>
#include <cstring>
#include <iostream>
#include "../core/logger/logger.h"

namespace blitz {

    class FileUtils{
        public:
            static std::string read_file(const char* filePath) {
                FILE* file = fopen(filePath, "rt");
                if (!file) {
                    //BLITZ_LOG_ERROR("Error: Could not open file {}", filePath);
                    return "";
                }

                if (fseek(file, 0, SEEK_END) != 0) {
                    //BLITZ_LOG_ERROR("Error: fseek failed");
                    fclose(file);
                    return "";
                }

                long length = ftell(file);
                if (length < 0) {
                    //BLITZ_LOG_ERROR("Error: ftell failed");
                    fclose(file);
                    return "";
                }

                rewind(file);
                
                char* data = new char[length + 1];
                if (!data) {
                    //BLITZ_LOG_ERROR("Error: Memory allocation failed");
                    fclose(file);
                    return "";
                }

                std::memset(data, 0, length + 1);
                size_t readSize = fread(data, 1, length, file);
                if (readSize != static_cast<size_t>(length)) {
                    //BLITZ_LOG_ERROR("Error: fread failed");
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