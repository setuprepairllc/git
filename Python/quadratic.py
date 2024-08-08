from sympy import symbols, Eq, solve

x = symbols('x')

# Define the equation
equation = Eq(x**2 + 2*x - 3, 0)

# Solve the equation
solution = solve(equation, x)

print(f'The solutions are {solution}')
