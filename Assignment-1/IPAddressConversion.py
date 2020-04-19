# Name - Amar Soni
# Roll no - 411702
# This code is for IP address conversion function
# The Function bts() converts IP address from decimal format seperated by '.' to binary
# The Function ip2B() converts IP address from binary format to decimal seperated by '.' 
def bts(IPinBinary):
  a=[0,0,0,0]
  for i in range(4):
    a[i]=str(int(IPinBinary[i*8:(i*8)+8],2))
  return '.'.join(a)

def ip2B(IP):
  a=[]
  ip=IP.split('.')
  for i in range(4):
    a.append(format(int(ip[i]),'08b'))
  return ''.join(a)

print("\"xxx.xxx.xxx.xxx\"")
IP=input("Enter the IP address in the above format: ")
print("Input IP address is ",IP)

binary=ip2B(IP)
print('Binary conversion of The given IP address is',binary)

print('Regaining IP address from binary :',bts(binary))
