# Author: Chiranjiv Goyal
# Date: 10/04/2019
# Week 7: campus training Zemoso

from sys import argv

def main():
    
    # Check for correct Usage
    if(len(argv) != 2):
        print("Usage: python bleep.py dictionary")
        sys.exit(1)
    
    # Getting the dictionary of banned words
    arguments = list(argv)
    dictionary = banned_words(arguments)

    # Getting the message
    words = input_message("What is the message you want to encode?\n")

    if len(words) == 0:
        print(message)
        return

    # Selecting words to encode
    words = check(words,dictionary)

    # Create new meassage with encoded words
    new_message = create_message(words)

    # Print new message
    print_message(new_message)


def banned_words(arguments):
    
    dictionary_file = open(arguments[1],'r')
    dictionary = []

    # Strip '\n' from readlines string
    for line in dictionary_file.readlines():
        line = line.strip('\n')
        dictionary.append(line)
    return dictionary

def input_message(call_for_var):
    message = input(call_for_var)
    words = message.split()
    return words

def check(words,dictionary):
    new_words = []

    # Check Encoding condition
    for word in words:
        if word in dictionary:
            result = encode(word)
            word = result
        new_words.append(word)
    return new_words

def encode(word):
    new_word = ""
    for l in word:
        new_word+='*'
    return new_word

def create_message(words):
    new_message = words[0]
    for word in words[1:]:
        new_message+=' '
        new_message+=word
    return new_message

def print_message(new_message):
    print(new_message)

if __name__ == "__main__":
    main()
