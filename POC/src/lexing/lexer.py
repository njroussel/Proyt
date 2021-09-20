from POC.src.lexing.tokens import TokenTypes
from typing import Iterable


class Lexer:
    def __init__(self, tokens: Iterable[TokenTypes]):
        self.tokens = tokens
