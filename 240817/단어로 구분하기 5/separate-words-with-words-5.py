import sys

string_list = list(map(str, sys.stdin.readline().split(' ')))

x = 1
for string in string_list:
    if x % 2 == 0:
        print(string)
    x += 1