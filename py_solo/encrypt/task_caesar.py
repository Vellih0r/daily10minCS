# тут я беру части своего кода из другого файла, чтобы их использовать 
from caesar import encrypt, decrypt
# ctoi means C haracter to I nteger (превратить букву(символ) в число)
from caesar import ctoi
from caesar import SECRET_KEY

# 1 -> превратить строку в набор чисел
# ( ' '(пробел) сделать 0, 'a' -> 1, 'b' -> 2, и т.д.)
message =  input("Введите сообщение, оно будет зашифровано:\n\t")

print("\nЗашифрованое сообщение в цифры")
result = ""
for letter in message:
    number = ctoi.get(letter)
    result += str(number)
print(result)

# 2 -> зашифровать сообщение переместив все буквы вперёд на число, которое в ключе (SECRET_KEY=2 -> перемесить на 2 вперёд)
print("Зашифрованое сообщение в буквы")
secret = ""
secret = encrypt(message, SECRET_KEY)
print(secret)

# 3 -> расшифроавть сообщение, с помощью ключа
false_key = int(input("\nВведите НЕПРАВЕЛЬНЫЙ ключ, чтобы расшифровать: "))
key = int(input("Введите ключ, чтобы расшифровать: "))
out_wrong = decrypt(secret, false_key)
out_right = decrypt(secret, key)

print("\nОтвет с неправельным ключём:\n", out_wrong)
print("Ответ\n", out_right)

