alphabet=" abcdefghijklmnopqrstuvwxyz"

# create dict - character : integer
# {'a' : 1} -> 'a' belongs to index 1
ctoi = { c : i for i,c in enumerate(alphabet)}
''' code above, is just a short way to do this:
ctoi = dict()
for index, char in enumerate(alphabet):
    itoc[char] = index
'''

# integer to char -> we can get chracter by its index, using regular list
# list[1] = a
# list[25] = z
itoc = [ c for c in alphabet ]
''' code above, is just a short way to do this:
ctoi = []
for char in alphabet:
    ctoi.append(char)
result:
[' ', 'a', 'b', 'c', ...]
'''

# constant for alpphabet length
LENGTH = len(itoc)

def encrypt(msg: str, shift: int) -> str:
    '''
    this funciton takes message and encrypts it using
    caesars cipher (shift each letter {n} indexes forward
    
    returns new encripted message
    '''
    # create string to save result there
    out = ""

    # get each character(letter) from message
    for c in msg:
        # ctoi.get() will return None if there is no such char
        index = ctoi.get(c)
        # check if index is exists and its not None
        if index is not None:
            # if index is in bounds
            if index+shift < LENGTH:
                index += shift
            else:
                # if index is more than end(z)
                # that we go back to the begining
                steps_to_end = LENGTH - index
                index = 0 + (shift - steps_to_end)
            '''code above returns index
            to the start of the alphabet
            if index+shift > alphabet's length:
            char = w
            shift = 5
            index = 23
            index+shift = 28 -> GREATER THAN LENGTH!!!
            ->w(23) y(24) x(25) z(26) ... nothing after z

            length - index(w) -> 26-23=3
            3 it's steps required to reach end
            23(w) + 3 steps = z (end)
            after END we can go to the START(0)
            calculate new shift, to get correct index
            shift - steps_to_end = 5-3
            5-3 = 2
            add this 2 to the start(start = 0)
            0+2 = 2 -> c
            a(0) b(1) ->c(2) d(3)
            w+5 = c
            w(index=23) + 5(shift) = c(index=2)
            '''
            out += itoc[index];
    # return result after for loop
    return out


def decrypt(msg: str, shift: int) -> str:
    out = ""
    for c in msg:
        index = ctoi.get(c)
        if index is not None:
            if index-shift >= 0:
                index-=shift
            else:
                index = LENGTH - (shift - index)
            out += itoc[index]
    return out


if (__name__ == "__main__"):
    secret = encrypt("Hello", 5)
    print(secret)
    print(decrypt(secret, 5))

