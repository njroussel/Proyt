from enum import Enum, auto
from typing import Callable


class TokenType(Enum):
    EOF = auto()
    DEFINITION = auto()
    IMPORT = auto()
    IDENTIFIER = auto()
    LITERAL = auto()


class Token:
    def __init__(
        self,
        tokenType: TokenType,
        validator: Callable[[str], bool],
    ):
        self.tokenType = tokenType
        self.validator = validator


def validateEOF(string: str) -> bool:
    return string is None


eofToken = Token(TokenType.EOF, validateEOF)


def validateDefinition(string: str) -> bool:
    return string.strip() == "def"


definitionToken = Token(TokenType.DEFINITION, validateDefinition)


def validateImport(string: str) -> bool:
    return string.strip() == "import"


importToken = Token(TokenType.IMPORT, validateImport)


def validateIdentifier(string: str) -> bool:
    stripped = string.strip()
    if len(stripped) < 1:
        return False

    return stripped[0].isalpha()


indentifierToken = Token(TokenType.IDENTIFIER, validateIdentifier)


def validateLiteral(string: str) -> bool:
    stripped = string.strip()
    if len(stripped) < 1:
        return False

    return stripped.isdecimal()


literalToken = Token(TokenType.LITERAL, validateLiteral)

ALL_TOKENS = [
    eofToken,
    definitionToken,
    importToken,
    indentifierToken,
    literalToken,
]
