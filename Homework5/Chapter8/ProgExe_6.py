def nestedSelections(first, second, third):
    if first < second:
        if second < third:
            min = first
            mid = second
            max = third
        else:
            min = first
            mid = third
            max = second
    elif second < first:
        if first < third:
            min = second
            mid = first
            max = third
        else:
            min = second
            mid = third
            max = first
    elif third < first:
        if first < second:
            min = third
            mid = first
            max = second
        else:
            min = third
            mid = second
            max = first

    return min, mid, max

def noNestedSelections(first, second, third):
    if first < second and second < third:
        min = first
        mid = second
        max = third

    if first < second and third < second:
        min = first
        mid = third
        max = second

    if second < first and first < third:
        min = second
        mid = first
        max = third

    if second < first and third < first:
        min = second
        mid = third
        max = first

    if third < first and first < second:
        min = third
        mid = first
        max = second

    if third < first and second < first:
        min = third
        mid = second
        max = first

    return min, mid, max


print(nestedSelections(2, 0, 1))
print(noNestedSelections(1, 2, 0))

"""
    I would argue that nested selections are a little more
    complex because there is more logic involved, and in order
    to figure out what to do, you have to wind your way through
    the selection statements. However, the non-nested selections
    are also complex because to there is no logical order to
    them so you're forced to read through every condition to see
    if you've found the one you want.

    In terms of reliability, they should be equally reliable. Since
    all cases are covered for both methods, there shouldn't be any
    problems. Overall, I prefer the nested selection statements,
    especially from a readability perspective. It's much easier to
    follow the logic of the code than to scan over all of the possible
    choices as in the case of no nested selection statements.
"""
