from sys import argv

units = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
teens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
tens = ["", "Ten", "Twenty", "Thrirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninenty"]
bigs = ["", "Thousand", "Million", "Billion", "Trillion"]
hundred = "Hundred"

def main():
    
    inputReadStatus = validateInput(argv)


    if inputReadStatus == 1:
        print("Invalid Input\n")
        exit(1)
    
    else :
        
        arguments = list(argv)
        input = arguments[1]
        answer = getnumberintosentence(input)
        print(answer)

def validateInput(argv):
    arguments = list(argv)
    number = argv[1]

    # Check for correct Usage
    if(len(argv) != 2):
        print("Usage: python bleep.py dictionary")
        return 1
    
    length = len(number)
    if length <= 0 or length >13:
        return 2

    for i in number:
        if i.isdigit() == False:
            return 3

    if number[0] == '0' or (length == 13 and number[0] != '1'):
        return 4
    
    return 0

def getNumberAsSentence(input):
    
    length = len(input)
    digit_processed = 0

    while digit_processed < length:
        remaining = length - digit_processed
        
        largest_bid = remaining/3
        if remaining%3 == 0:
            largest_bid = largest_bid-1
        
        if remaining%3 == 0:
            largestBigSizeCount = 3
        else:
            remaining%3
        
        if remaining>3:
            if largestBigSizeCount == 1:
                subSentence = getSingelDigitAsSentence(input,digit_processed)
                





if __name__ = "__main__":
    main()