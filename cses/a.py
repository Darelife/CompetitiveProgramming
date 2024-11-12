text = """Dominator069 was an expert in 2022. He became an international master (peak) in July 2023!!!!"""

# convert every letter to ascii and then binary and save it
newText = []


def bin8bit(n):
    return "".join(str((n & (1 << i)) and 1) for i in range(7, -1, -1))


for i in text:
    newText.append(bin8bit(ord(i)))

message = ""
for i in newText:
    message += i
# print(message)

key = "0101000010111010111011000011011001111010001010100101000"
# if the key is shorter than the message, we are basically repeating the key

key = key * (len(message) // len(key)) + key[: len(message) % len(key)]

cipher = ""
for i in range(len(message)):
    cipher += str(int(message[i]) ^ int(key[i]))

print(cipher)

# convert the binary to ascii
# every 8 bits is a character
decipher = ""
for i in range(0, len(cipher), 8):
    decipher += chr(int(cipher[i : i + 8], 2))

# print(decipher)
