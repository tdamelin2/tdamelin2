from morse_data import morse_code
x = ""
x = input("Please enter a word > ")
x = x.upper()
def morsify(string):
  strings = ""
  for i in string: 
     strings += morse_code[i] + " "
  return strings
  
print(morsify(x))
