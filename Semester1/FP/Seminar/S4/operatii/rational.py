from operatii.utils import *

def add(a, b):
    c = {}
    if a["m"] != b["m"]:
        c["m"] = a["m"] * b["m"]
        c["n"] = a["n"] * b["m"] + b["n"] * a["m"]
    else:
        c["n"] = a["n"] + b["n"]
        c["m"] = a["m"]
    return c
def sub(a, b):
    c = {}
    if a["m"] != b["m"]:
        c["m"] = a["m"] * b["m"]
        c["n"] = a["n"] * b["m"] - b["n"] * a["m"]
    else:
        c["n"] = a["n"] - b["n"]
        c["m"] = a["m"]
    return c
def mul(a, b):
    c = {}
    c["n"] = a["n"] * b["n"]
    c["m"] = a["m"] * b["m"]
    return c
def div(a, b):
    c = {}
    c["n"] = a["n"] * b["m"]
    c["m"] = a["m"] * b["n"]
    return c

def simplify(a):
    c = {}
    cmm = cmmdc(a["n"], a["m"])
    c["n"] = a["n"] // cmm
    c["m"] = a["m"] // cmm
    return c

def cmp(a, b):
   if a == b:
       return 0

   if a["n"] * b["m"] > a['m']*b['n']:
        return 1
   else:
        return -1

