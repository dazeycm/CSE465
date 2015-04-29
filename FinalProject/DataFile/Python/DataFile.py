__author__ = 'Craig'

from tkinter.filedialog import askopenfilename
from statistics import mean

def createFileOptions():
    options = {}
    options['defaultextension'] = '.txt'
    options['filetypes'] = [('all files', '.*'), ('text files', '.txt')]
    options['title'] = 'Please open a file with the grades you wish to calculate'
    return options

def getFileName():
    options = createFileOptions()
    name = askopenfilename(**options)
    return name

fileName = getFileName()
file = open(fileName)

gradeBook = {}

for line in file:
    parts = line.split()

    #change number strings to ints in list
    parts = [int(parts[i]) if parts[i].isdigit() else parts[i] for i in range(8)]

    name = parts[0]
    hw = float("{0:.1f}".format(mean(parts[1:4])))
    quiz = float("{0:.1f}".format(mean(parts[4:-1])))
    exam = float("{0:.1f}".format(parts[-1]))

    finalScore = float("{0:.1f}".format((hw * .35) + (quiz * .2) + (exam * .45)))

    if finalScore >= 90:
        letterGrade = 'A'
    elif finalScore >= 80:
        letterGrade = 'B'
    elif finalScore >= 70:
        letterGrade = 'C'
    elif finalScore >= 60:
        letterGrade = 'D'
    else:
        letterGrade = 'F'

    gradeBook[name] = {'hw': hw, 'quiz': quiz, 'exam': exam, 'finalScore': finalScore, 'letterGrade': letterGrade}

#simple tests to use with test.txt to check to make sure values are calculated correctly
#assert gradeBook['Zmuda']['hw'] == 97.7, "Homework grade was figured incorrectly"
#assert gradeBook['Zmuda']['quiz'] == 97.0, "Quiz grade was figured incorrectly"
#assert gradeBook['Zmuda']['exam'] == 100.0, "Exam grade was figured incorrectly"
#assert gradeBook['Zmuda']['finalScore'] == 98.6, "FinalScore grade was figured incorrectly"
#assert gradeBook['Zmuda']['letterGrade'] == 'A', "LetterGrade was figured incorrectly"

for name in gradeBook:
    print('{} {} {}'.format(name, gradeBook[name]['finalScore'], gradeBook[name]['letterGrade']))





