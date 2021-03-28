from interface import Bag
from iterator import Iterator

def main():
    b1 = Bag(4)
    b1.add_item(2)
    b1.add_item(4)
    assert(len(b1) == 2)
    #print(b1.search(5))
    i1 = Iterator(b1)
    print(i1.getCurrent())

main()