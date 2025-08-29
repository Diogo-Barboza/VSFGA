# pyproject.toml
from typing import Any
from dataclasses import dataclass
import math
import operator

type AST = list
type IR = list | callable | float


FUNCTIONS = {
    "sqrt": math.sqrt, 
    "cos": math.cos, 
    "sin": math.sin, 
    "*": operator.mul,
    "+": operator.add,
    "-": operator.sub,
    "/": operator.truediv,
    "%": operator.mod,
}

@dataclass
class Token:
    text: str
    kind: str
    value: Any = None

def lex(source: str) -> list[Token]:
    """
    Realiza a análise léxica do código fonte.
    """
    source = source.replace("(", " ( ")
    source = source.replace(")", " ) ")
    lexemes = source.split()
    tokens = []
    
    for substr in lexemes:
        if substr == "(":
            token = Token(substr, "LPAR")
        elif substr == ")":
            token = Token(substr, "RPAR")
        elif substr in FUNCTIONS:
            impl = FUNCTIONS[substr]
            token = Token(substr, "FUNCTION", impl)
        else:
            value = float(substr)
            token = Token(substr, "NUMBER", value)
        tokens.append(token)

    return tokens


def parse(tokens: list[Token]) -> AST:
    """
    Realiza a análise sintática do código.
    """
    curr = None
    stack = []
    
    for token in tokens:
        if token.kind == "LPAR":
            curr = []
            stack.append(curr)
        elif token.kind == "RPAR":
            lst = stack.pop()
            if not stack:
                return lst
            stack[-1].append(lst)
        else:
            curr.append(token.value)
    
    raise RuntimeError


def analysis(ast: AST) -> IR:
    """
    Análise semântica.
    """ 
    ir = ast
    return ir

def emit(ir: IR) -> str:
    """
    Emite código
    """
    raise NotImplementedError("PARA CASA ;)")

def interpret(ir: IR) -> Any:
    """
    Interpreta uma árvore sintática/IR.   
    """
    if isinstance(ir, float) or callable(ir):
        return ir
    elif isinstance(ir, list):
        func, *args = map(interpret, ir)
        return func(*args)
    else:
        raise RuntimeError("Erro de tipificacao")
    
def run(source: str) -> Any:
    tokens = lex(source)
    ast = parse(tokens)
    ir = analysis(ast)
    value = interpret(ir)
    
    print("=", value)

def run_shell():
    while True:
        try:
            source = input("lisp> ")
        except EOFError:
            break
        if not source:
            break
        run(source)

if __name__ == "__main__":
    import sys

    if len(sys.argv) == 2:
        filename = sys.argv[1]
        with open(filename) as fd:
            source = fd.read()
        run(source)
    else:
        run_shell()
