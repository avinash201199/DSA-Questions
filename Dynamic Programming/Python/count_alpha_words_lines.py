"""
Name : Quadratic equation solver
Author : [Mayank Goyal) [https://github.com/mayankgoyal-13]
Question : To find the number of lines, number of words and no. of character
"""



def counter():
    file = open("report.txt", 'r')
    count_lines = 0
    count_words = 0
    count_char = 0

    for line in file:
        line = line.strip("\n")  # the interpreter will not count /n as a character
        words = line.split()
        count_lines += 1
        count_words += len(words)
        count_char += len(line)

    print("There are total", count_lines, "lines,", count_words, "words and", count_char, "characters")
    file.close()


counter()
