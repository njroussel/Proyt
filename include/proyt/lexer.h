#include <proyt/token.h>

#include <filesystem>
#include <fstream>
#include <string>

namespace proyt {

/**
 * @brief Lexer
 */
class Lexer {
 public:
  /**
   * @brief Sets current file to be lexed
   *
   * @param filePath Path to the file to be lexed
   */
  void initialize(const std::filesystem::path& filePath);

  /**
   * @brief Returns the next token in the file
   *
   * @param tokenStr
   * @param valid Whether or not a valid token could be found
   *
   * @return The next token in the file (token value should be ignored if @param valid
   * is true)
   */
  Token nextToken(const std::string& tokenStr, bool& valid);

 private:
  std::ofstream m_currentFile;
};

}  // namespace proyt
