import sympy

solutions = [9, 6, 2, 3]

def solve_four_equations():
    counter = 0
    solutions = [9, 6, 2, 3]
    equations = []
    for sol in solutions:
        a = sympy.randprime(1, 100)
        b = sympy.randprime(1, 100)
        c = a * sol + b
        equation = f"{a}x + {b} = {c}"
        equations.append(equation)
    for i, equation in enumerate(equations):
        print(f"Уравнение {i + 1}: {equation}")
    result = input("Напишите все решения в одну строку через пробелы: ")
    res_list = result.split()
    for j in range(len(solutions)):
        if res_list[j] == str(solutions[j]):
            counter += 1
        else:
            print(f"Уравнение {j + 1} было решено неправильно!")
            break
    if counter == 4:
        print("Вы молодцы! Ваш пароль - 9623")