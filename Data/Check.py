fin = open("Data/input.txt" , "r")
fout = open("Data/output.txt" , "r")

a = fin.read()
b = fout.read()

print(a == b)