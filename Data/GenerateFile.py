import random

file = open("source.txt" , "r")

data = file.read()
file.close()

data = data.split()
out = ""

for i in range(180000 * 2):
    out += data[random.randint(0 , len(data) - 1)] + " "
    
    if i % 30 == 0:
        out += "\n"
        
file = open("input.txt" , "w")
file.write(out)
file.close()