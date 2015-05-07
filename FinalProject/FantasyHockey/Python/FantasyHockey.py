__author__ = 'Craig'

from tkinter.filedialog import askopenfilename

def createFileOptions():
    options = {}
    options['defaultextension'] = '.txt'
    options['filetypes'] = [('all files', '.*'), ('text files', '.txt')]
    options['title'] = 'Please open a file with the NHL information you wish to process'
    return options

def getFileName():
    options = createFileOptions()
    name = askopenfilename(**options)
    return name

'''Returns a string in the form of: NAME scored INT goals!'''
def getNumGoals(goals, name):
    if not name in goals:
        return '{} scored {} goals!'.format(name, 0)
    else:
        return '{} scored {} goals!'.format(name, goals[name])

fileName = getFileName()
file = open(fileName)

goals = {}

for line in file:
    if "goal scored" in line.lower():
        parts = line.split()
        indexOfName = parts.index('by') + 1

        firstName = parts[indexOfName]
        lastName = parts[indexOfName + 1].split('(')[0]
        name = '{} {}'.format(firstName, lastName)

        if not name in goals:
            goals[name] = 1
        else:
            goals[name] += 1

print(getNumGoals(goals, 'Travis Zajac'))
print(getNumGoals(goals, 'Jaromir Jagr'))
print(getNumGoals(goals, 'Dmitry Kulikov'))
print(getNumGoals(goals, 'Dan Ellis'))
