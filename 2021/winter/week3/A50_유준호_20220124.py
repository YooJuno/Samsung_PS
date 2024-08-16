for i in list(input()):
    print(chr(ord(i)-3) if ord(i)>=68 else chr((ord(i)+23)), end="")