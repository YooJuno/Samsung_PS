for number in range(1, 101):
    output = number
    if(number % 3 == 0):
        output = 'Fizz'
    if(number % 5 == 0):
        output = 'Buzz'
    if(number % 15 == 0):
        output = 'FizzBuzz'
    print(output)