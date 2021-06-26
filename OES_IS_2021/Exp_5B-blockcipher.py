import pyDes
import os
plaintext = input("Enter plaintext : ")
def padded_text(s):
	while len(s)%8 !=0 :
		s+=' '
	return s

p = padded_text(plaintext)

k_ecb = pyDes.des("DESCRYPT",pyDes.ECB, "\0\0\0\0\0\0\0\0",pad=None,padmode=None)

e_ecb = k_ecb.encrypt(str.encode(p))

print("The Encrypted string (in bytes) : ",e_ecb)

d_ecb = k_ecb.decrypt(e_ecb)

print("The Decrypted string (in bytes) : ",d_ecb)    