
#####          saquif_abdullah  ::::   08/11/24  08:25 PM
#####          Note :: I took help from online

import operator

def evaluate_expression(expression):
    ops = {
        '+': operator.add,
        '-': operator.sub,
        '*': operator.mul,
        '/': operator.truediv
    }

    def parse_expression(expression):
        tokens = []
        current_number = ''

        for char in expression:
            if char.isdigit() or char == '.':
                current_number += char
            elif char in ops:
                if current_number:
                    tokens.append(float(current_number))
                    current_number = ''
                tokens.append(char)

        if current_number:
            tokens.append(float(current_number))

        return tokens



    tokens = parse_expression(expression)
    values = []
    operators = []
    precedence = {
        '+': 1,
        '-': 1,
        '*': 2,
        '/': 2
    }

    def apply_operator():
        right = values.pop()
        left = values.pop()
        op = operators.pop()
        values.append(ops[op](left, right))

    for token in tokens:
        if isinstance(token, float):
            values.append(token)
        elif token in ops:
            while operators and precedence[operators[-1]] >= precedence[token]:
                apply_operator()
            operators.append(token)

    while operators:
        apply_operator()

    return values[0]




expression = input("Please Enter your Expression : ")
result = evaluate_expression(expression)
print(result)

