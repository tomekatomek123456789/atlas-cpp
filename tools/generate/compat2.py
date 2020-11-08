from __future__ import division

from past.utils import old_div
from builtins import object
class _C(object):
    def _m(self): pass


#Types compatibility
IntType = int
ListType = list
LongType = int
FloatType = float
DictType = dict
StringType = str
TupleType = tuple
InstanceType = object
ClassType = type(_C)

#Function comptatibility
def cmp(x, y):
    """
    Replacement for built-in function cmp that was removed in Python 3

    Compare the two objects x and y and return an integer according to
    the outcome. The return value is negative if x < y, zero if x == y
    and strictly positive if x > y.
    """

    return (x > y) - (x < y)


def div(a, b):
    return old_div(a,b)

def find(s, *args):
    """find(s, sub [,start [,end]]) -> in
    Return the lowest index in s where substring sub is found,
    such that sub is contained within s[start,end].  Optional
    arguments start and end are interpreted as in slice notation.
    Return -1 on failure.
    """
    return s.find(*args)

def join(words, sep = ' '):
    """join(list [,sep]) -> string
    Return a string composed of the words in list, with
    intervening occurrences of sep.  The default separator is a
    single space.
    (joinfields and join are synonymous)
    """
    return sep.join(words)

def split(s, sep=None, maxsplit=-1):
    """split(s [,sep [,maxsplit]]) -> list of strings
    Return a list of the words in the string s, using sep as the
    delimiter string.  If maxsplit is given, splits at no more than
    maxsplit places (resulting in at most maxsplit+1 words).  If sep
    is not specified or is None, any whitespace string is a separator.
    (split and splitfields are synonymous)
    """
    return s.split(sep, maxsplit)

def replace(s, old, new, maxreplace=-1):
    """replace (str, old, new[, maxreplace]) -> string
    Return a copy of string str with all occurrences of substring
    old replaced by new. If the optional argument maxreplace is
    given, only the first maxreplace occurrences are replaced.
    """
    return s.replace(old, new, maxreplace)

#Declarations compatibility 
lowercase = 'abcdefghijklmnopqrstuvwxyz'
uppercase = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'