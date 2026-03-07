alphabet=" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.,/&~*^%$#@!(){}[]|<>_-1234567890\\\"'АБВГДЕЖЗИЙКЛМНОПРСТУФЧШЩЪЫЬЭЮЯ"

LENGTH = len(alphabet)

ctoi = { c : i for i,c in enumerate(alphabet)}
itoc = list(alphabet)

def decrypt(msg: str, key: int) -> str:
    key %= LENGTH
    out = ""

    for c in msg:
        index = ctoi.get(c)

        if index is None:
            out += c
            continue
        
        index = (index + key) % LENGTH
        out += itoc[index]
    return out

def get_caesar_key(msg: str) -> int:
    msg = msg[:100]
    key = 0
    for key in range(LENGTH):
        test = decrypt(msg, key)
        if key % 3 == 0: print()
        print(f'{key} -> {test}', end='\t')
    return 0

if __name__ == "__main__":
    import sys
    msg = ""
    if len(sys.argv) == 2:
        msg = sys.argv[1]
        key = get_caesar_key(msg)
    if len(sys.argv) == 3:
        msg = sys.argv[1]
        key = int(sys.argv[2])
        print(decrypt(msg, key))
