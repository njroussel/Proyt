#include <array>
#include <regex>
/**
 * @brief Holds all possible token values
 */
enum Token {
  // Meta
  END_OF_FILE,
  END_OF_EXPRESSION,
  OPEN_CURLY_BRACE,
  CLOSE_CURLY_BRACE,

  // Commands
  DEFINITION,
  IMPORT,

  // Primary
  IDENTIFIER,
  LITERAL,
  RETURN,
  EQUAL_SIGN,
  PLUS_SIGN,
  MULTIPLY_SIGN
};

const std::array<Token, 12> ALL_TOKENS = {
    END_OF_FILE,       END_OF_EXPRESSION, OPEN_CURLY_BRACE,
    CLOSE_CURLY_BRACE, DEFINITION,        IMPORT,
    IDENTIFIER,        LITERAL,           RETURN,
    EQUAL_SIGN,        PLUS_SIGN,         MULTIPLY_SIGN};

constexpr const char* regexStr(Token token) {
  switch (token) {
    case END_OF_FILE:
      return "\\s*$";
    case END_OF_EXPRESSION:
      return "\\s*return.*$";
    case OPEN_CURLY_BRACE:
      return "\\s*\\{.*$";
    case CLOSE_CURLY_BRACE:
      return "\\s*\\}.*$";
    case DEFINITION:
      return "\\s*def\\s.*$";
    case IMPORT:
      return "\\s*import\\s.*$";
    case IDENTIFIER:
      return "\\s*\\d.*$";
    case LITERAL:
      return "\\s*\\d.*$";
    case RETURN:
      return "\\s*return{1}.*$";
    case EQUAL_SIGN:
      return "\\s*\\={1}.*$";
    case PLUS_SIGN:
      return "\\s*\\+{1}.*$";
    case MULTIPLY_SIGN:
      return "\\s*\\*{1}.*$";
    default:
      return "";
  }
}
