from tkinter.filedialog import askopenfilename
import traceback

var = {}

def createFileOptions():
    options = {}
    options['defaultextension'] = '.txt'
    options['filetypes'] = [('all files', '.*'), ('text files', '.txt')]
    options['initialfile'] = r'C:\Users\damonde\Desktop\CSE465\Homework1\prog4.zpm'
    options['title'] = 'Open source file'
    return options

def getFileName():
    options = createFileOptions()
    name = askopenfilename(**options)
    return name

def parseFile(fileName):
    try:
        file = open(fileName, 'r')
        for line in file:
            if line.strip():
                parseLine(line)
    except Exception:
        print(traceback.format_exc())

def parseLine(line):
    parts = line.split()
    if parts[0] == 'DEF':
        var[parts[1]] = 0
    elif parts[0] == 'FOR':
        statements = buildForStatements(parts[2:])
        count = int(parts[1])
        for i in range(count):
            for s in statements:
                doOp(s)
    elif parts[0] in var:
        if parts[1] == '=':
            if parts[2] in var:
                var[parts[0]] = var[parts[2]]
            else:
                var[parts[0]] = int(parts[2])
        else:
            doOp(parts)

def buildForStatements(parts):
    parts = [s.split() for s in (" ".join(parts)).split(';')]
    return parts[:-1]

def doOp(parts):
    if '+' in parts[1]:
        if parts[2] in var:
            var[parts[0]] = var[parts[0]] + var[parts[2]]
        else:
            var[parts[0]] = var[parts[0]] + int(parts[2])
    if '-' in parts[1]:
        if parts[2] in var:
            var[parts[0]] = var[parts[0]] - var[parts[2]]
        else:
            var[parts[0]] = var[parts[0]] - int(parts[2])
    if '*' in parts[1]:
        if parts[2] in var:
            var[parts[0]] = var[parts[0]] * var[parts[2]]
        else:
            var[parts[0]] = var[parts[0]] * int(parts[2])


def printVars():
    for key in var:
        print(key + ' = ' + str(var[key]))


if __name__ == '__main__':
    fileName = getFileName()
    parseFile(fileName)
    printVars()




