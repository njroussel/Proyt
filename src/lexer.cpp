#include <proyt/lexer.h>

#include <iostream>

namespace proyt {

const char* const FILENAME_EXTENSION = ".pro";
const size_t FILENAME_EXTENSION_SIZE = 4;

void Lexer::initialize(const std::filesystem::path& filePath) {
  if (!std::filesystem::exists(filePath) ||
      std::filesystem::file_status(std::filesystem::status(filePath)).type() ==
          std::filesystem::file_type::directory) {
    std::cerr << "Specified path \"" << filePath.c_str()
              << "\" does not exist or is a folder!" << std::endl;
    return;
  }

  const std::string fileName = filePath.string();
  if (fileName.size() < FILENAME_EXTENSION_SIZE ||
      fileName.substr(fileName.size() - FILENAME_EXTENSION_SIZE,
                      FILENAME_EXTENSION_SIZE) != ".pro") {
    std::cerr << "File name \"" << fileName
              << "\" is invalid, file must end with \".pro\"!" << std::endl;
    return;
  }

  m_currentFile.open(filePath.string(), std::ios::in);
}

Token Lexer::nextToken(const std::string& tokenStr, bool& valid) {
  if (!m_currentFile.is_open()) {
    valid = false;
    return END_OF_FILE;
  }

  for (const Token& token : ALL_TOKENS) {
    std::regex tokenRegex(regexStr(token));
  }

  return END_OF_FILE;
}

}  // namespace proyt
