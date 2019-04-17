from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    lines1 = a.splitlines()
    lines2 = b.splitlines()

    common_lines = []

    for line in lines1:
        if line in common_lines:
            continue
        if line in lines2:
            common_lines.append(line)
    
    return common_lines




def sentences(a, b):
    """Return sentences in both a and b"""


    sentence1 = a.sent_tokenize()
    sentence2 = b.sent_tokenize()

    common_sentences = []

    for sentence in sentence1:
        if sentence in common_sentences:
            continue
        if sentence in sentence2:
            common_sentences.append(sentence)

    return common_sentences

    # Did it


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    
    def extract_substring(string, x):
        substring = []
        y = 0

        for i in string:
            if len(string[y:y+int(x)])<x:
                break
            if string[y:y+int(x)] < x:
                y+=1
                continue
            else:
                substring.append(string[y:y+int(x)])
                y+=1

        return substring

    substring1 = extract_substring(a,n)
    substring2 = extract_substring(b,n)

    common_substring = []

    for substring in substring1:
        if substring in common_substring:
            continue
        if substring in substring2:
            common_substring.append(substring)

    return common_substring
    # Did it babe
    return []