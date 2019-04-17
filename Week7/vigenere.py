from sys import argv

def main():

    # Check for correct Usage
    if(len(argv) != 2):
        print("Usage: python bleep.py dictionary")
        sys.exit(1)
    
    arguments = list(argv)
    print(type(arguments[1]))
    if arguments[1].isalpha() == False:
        print("Please insert a valid key")
        sys.exit(2)


    # Input Plain text and get key
    key = arguments[1]
    plain_text = input_message("Plain_text: ")

    # Encoding the Plain text
    cipher_text = encoding(plain_text,key)

    # Print cipher text
    print("cipher text: "+ cipher_text)

# Input message funtion
def input_message(call_for_var):
    plain_text = input(call_for_var)
    return plain_text

# Encoding the plain text
def encoding(plain_text,key):
    plain_index = 0
    cipher_index = 0
    cipher_text = ""
    cipher_length = len(key)

    # Iterate on plain_text
    for l in plain_text:
        if l.isalpha():
            if l.isupper():
                cipher_text+=chr((ord(l)- 65 + ord(key[cipher_index % cipher_length].lower())- 97)%26 + 65)
            else:
                cipher_text+=chr((ord(l)- 97 + ord(key[cipher_index % cipher_length].lower())- 97)%26 + 97)
            cipher_index+=1
        else:
            cipher_text+=l

    return cipher_text

if __name__ == "__main__":
    main()