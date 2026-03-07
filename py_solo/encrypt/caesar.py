SECRET_KEY = 5
# simple_alphabet=" abcdefghijklmnopqrstuvwxyz"
alphabet=''' ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz/`_~|[]{}.,?*&^%$#@!()\'<>\\"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхчшщъыьэюя0123456789'''

# Character TO Integer
# create dict - character : integer
# {'a' : 1} -> 'a' belongs to index 1
ctoi = dict()
for index, char in enumerate(alphabet):
    ctoi[char] = index

# itoc = Integer TO Char -> we can get chracter by its index, using regular list
# list[1] = a
# list[26] = z
# lsit() - converts string to array
itoc = list(alphabet)

# constant for alpphabet's length
LENGTH = len(itoc)

def encrypt(msg: str, shift: int) -> str:
    '''
    this funciton takes message and encrypts it using
    caesars cipher (shift each letter {n} indexes forward)
    
    returns new encripted message
    '''
    # normolize shift, if it is way to large
    if shift > LENGTH:
        shift = shift % LENGTH
    # result will be saved here
    out = ""

    # get each character from message
    for c in msg:
        index = ctoi.get(c)
        # check if index is None (is it supported?, if no - add it straight to result, do not encrypt it)
        if index is None:
            out += c
            # skip to the next iteration
            continue

        # if index is in bounds
        if index+shift < LENGTH:
            index += shift # simply shift it forward
        else:
            # if index is more than END (z)
            # we must go back to the START
            steps_to_end = LENGTH - index
            index = 0 + (shift - steps_to_end)
        # add new shifted index to the result
        out += itoc[index];
    # return result after for loop
    return out


def decrypt(msg: str, shift: int) -> str:
    '''
    decrypt message using key
    returns decrypted message - str
    '''
    # normolize shift, if it is way to large
    if shift > LENGTH:
        shift = shift % LENGTH

    out = ""
    for c in msg:
        index = ctoi.get(c)
        if index is None:
            out += c
            continue

        if index-shift >= 0:
            index -= shift
        else:
            index = LENGTH - (shift - index)
        out += itoc[index]
    return out

def gtp_encrypt(msg: str, shift: int) -> str:
    shift %= LENGTH
    out = ""

    for c in msg:
        index = ctoi.get(c)

        if index is None:
            out += c
            continue

        index = (index + shift) % LENGTH
    return out

def gtp_decrypt(msg: str, shift: int) -> str:
    shift %= LENGTH
    out = ""

    for c in msg:
        index = ctoi.get(c)

        if index is None:
            out += c
            continue

        # loop around
        index = (index + shift) % LENGTH
        out += itoc[index]
    return out


if (__name__ == "__main__"):
    import sys
    msg = ""
    if len(sys.argv) > 1:
        msg = sys.argv[1]

    print(encrypt(msg, SECRET_KEY))


