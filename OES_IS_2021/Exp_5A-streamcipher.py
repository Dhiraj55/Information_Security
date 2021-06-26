import pyaes
plaintext = input("Enter the Plain Text: ")
key = "sonbm#sssd0192837465r1t26yu89i51"
aes = pyaes.AESModeOfOperationCTR(str.encode(key))
e = aes.encrypt(plaintext)
print("The Encrypted text (in bytes): ",e)
aes = pyaes.AESModeOfOperationCTR(str.encode(key))
d = aes.decrypt(e)
print("The Decrypted text (in bytes): ",d)