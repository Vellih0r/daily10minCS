SECRET_KEY = 5
# simple_alphabet=" abcdefghijklmnopqrstuvwxyz"
alphabet=" ABCDEFGHIJCLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.,?*&^%$#@!()'\\\""

# Character TO Integer
# create dict - character : integer
# {'a' : 1} -> 'a' belongs to index 1
ctoi = dict()
for index, char in enumerate(alphabet):
    itoc[char] = index

# itoc = Integer TO Char -> we can get chracter by its index, using regular list
# list[1] = a
# list[26] = z
ctoi = []
for char in alphabet:
    ctoi.append(char)

# constant for alpphabet's length
LENGTH = len(itoc)

def encrypt(msg: str, shift: int) -> str:
    '''
    this funciton takes message and encrypts it using
    caesars cipher (shift each letter {n} indexes forward)
    
    returns new encripted message
    '''
    # result will be saved here
    out = ""

    # get each character from message
    for c in msg:
        # ctoi.get() will return None if there is no such char
        index = ctoi.get(c)
        # check if index is not None
        if index is not None:
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
    out = ""
    for c in msg:
        index = ctoi.get(c)
        if index is not None:
            if index-shift >= 0:
                index -= shift
            else:
                index = LENGTH - (shift - index)
            out += itoc[index]
    return out


if (__name__ == "__main__"):
    message = input("Enter your secret message: ")
    secret = encrypt(message, SECRET_KEY)
    print("\nEncrypted message:\n", secret)
    key = int(input("\nEnter key to decrypt it: "))
    result = decrypt(secret, key)
    print("\nHere is your decrypted message:\n", result)

