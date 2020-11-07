IntType = int
ListType = list
LongType = int
FloatType = float
DictType = dict
StringType = str
TupleType = tuple
InstanceType = object
def cmp(x, y):
    """
    Replacement for built-in function cmp that was removed in Python 3

    Compare the two objects x and y and return an integer according to
    the outcome. The return value is negative if x < y, zero if x == y
    and strictly positive if x > y.
    """

    return (x > y) - (x < y)


def div(a, b):
    return a/b