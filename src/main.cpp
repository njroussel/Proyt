#include <proyt/ast.h>
#include <proyt/lexer.h>

#include <filesystem>
#include <iostream>

using namespace proyt;

int main() {
  std::cout << "Hello world! " << std::endl;

  Lexer lexer;
  lexer.initialize(
      std::filesystem::path("/home/nicolas/Documents/Proyt/res/example.pro"));

  bool valid = true;
  Token token = lexer.nextToken("tmp", valid);
  while (valid) {
    std::cout << token << std::endl;
  }

  return EXIT_SUCCESS;
}
