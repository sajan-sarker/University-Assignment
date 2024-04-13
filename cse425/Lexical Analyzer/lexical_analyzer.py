# Filename: lexical_analyzer.py
# Problem: Write a program using either C/C++, Java or Python language for a lexical analyzer that can tokenize a C statement and can detect C keyword.

#########################################
###  Submitted by: Sajan Kumer Sarker  ##
###  ID: 2111131642                    ##
#########################################

# import the required libraries
import re   # Regular expression library
import nltk # type: ignore  # Natural Language Toolkit library
import sys # System-specific parameters and functions
import os # Miscellaneous operating system interfaces
nltk.download('punkt') # Download the 'punkt' package from the NLTK library for tokenization if not available.

### patterns for regular expressions for different tokens
keywords = r"auto|break|case|#include|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|string|class|struc|include"
operators = r"(\++)|(-)|(=)|(\*)|(/)|(%)|(--)|(<=)|(>=)"
constant = r"^(\d+)$"
special_characters = r"[@&~#!$\^\|:?,\.']|\""
identifiers = r"^[a-zA-Z_]+[a-zA-Z0-9_]*"
headers = r"([a-zA-Z]+\.[h])"
semicolon = r";"
parentheses = r"\(|\)"
braces = r"\{|\}"
square_brackets = r"\[|\]"
angle_brackets = r"\<|\>"

def remove_comments(program):
    """
    Removes both single-line and multiple-line comments from the given program.

    Args:
        program (str): The program code from which comments need to be removed.

    Returns:
        str: The program code without any comments.
    """
    single_line_comments = r"//.*"
    multiple_line_comments = r"/\*[^*]*\*+(?:[^/*][^*]*\*+)*/"
    sub_multiple_line_comments = re.sub(multiple_line_comments, "", program)
    program_without_comments = re.sub(single_line_comments, "", sub_multiple_line_comments)
    return program_without_comments

def remove_newline(program):
    """
    Removes the '\\n' characters from each line of the given program and returns the modified program.

    Args:
        program (str): The input program with '\\n' characters.

    Returns:
        list: The modified program with '\\n' characters removed from each line.
    """
    prog = program.split('\n')
    scanned_program = []
    for line in prog:
        if '\\n' in line:
            line = line.replace('\\n', '')
            scanned_program.append(line.strip())
        else:
            scanned_program.append(line.strip())
    return scanned_program

def remove_spaces(program):
    """
    Removes leading and trailing spaces from each line in the program.

    Args:
        program (list): The program as a list of strings, where each string represents a line of code.

    Returns:
        list: The program with leading and trailing extra spaces removed from each line.
    """
    scanned_program = []
    for line in program:
        if line.strip() != '':
            scanned_program.append(line.strip())
    return scanned_program

def get_tokens(program):
    """
    Tokenizes the given program and prints the tokens along with their corresponding lexemes.

    Args:
        program (list): The program code as a list of lines.

    Returns:
        None
    """
    source_code = []
    for line in program:
        source_code.append(line)
    count = 0
    for line in source_code:
        if line.startswith("#include"):
            tokens = nltk.word_tokenize(line)
        else:
            tokens = nltk.wordpunct_tokenize(line)
        for token in tokens:
            count += 1
            #print(token)
            if(re.findall(keywords, token)):
                print("Token is KEYWORDS,{:>10} Lexeme is-> {}.".format("",token))
            elif(re.findall(headers, token)):
                print("Token is HEADERS,{:>11} Lexeme is-> {}.".format("",token))
            elif (re.findall(identifiers, token)):
                if 'include' or '.h' not in token:
                    print("Token is IDENTIFIERS,{:>7} Lexeme is-> {}.".format("",token))
            elif(re.findall(operators, token)):
                print("Token is OPERATORS,{:>9} Lexeme is-> {}.".format("",token))
            elif(re.findall(constant, token)):
                print("Token is CONSTANT,{:>10} Lexeme is-> {}.".format("",token))
            elif(re.findall(special_characters, token)):
                if '.h' not in token:
                    print("Token is SPECIAL CHARACTERS, Lexeme is-> {}.".format(token))
            elif(re.findall(semicolon, token)):
                print("Token is SEMICOLON,{:>9} Lexeme is-> {}.".format("",token))
            elif(re.findall(parentheses, token)):
                print("Token is PARENTHESES,{:>7} Lexeme is-> {}.".format("",token))
            elif(re.findall(braces, token)):
                print("Token is BRACES,{:>12} Lexeme is-> {}.".format("",token))
            elif(re.findall(square_brackets, token)):
                print("Token is SQUARE BRACKETS,{:>10} Lexeme is-> {}.".format("",token))
            elif(re.findall(angle_brackets, token)):
                print("Token is ANGLE BRACKETS,{:>4} Lexeme is-> {}.".format("",token))
            else:
                print("Token is UNKNOWN,{:>11} Lexeme is-> {}.".format("",token))
    print("Total number of tokens are: ", count)

def main():
    """
    Entry point of the program.
    
    Reads a file, removes comments, newlines, and spaces from the file content,
    and then extracts tokens from the processed program.
    """
    try:
        #print(os.getcwd())  # Current working directory
        f = open('D:/Programing/University-Assignment/cse425/Lexical Analyzer/code.c')      # Take the input from a .c file
        main_program = f.read()
        #main_program = input("Enter the Script: ") # Take the input from the user
        without_comments = remove_comments(main_program)
        without_newline = remove_newline(without_comments)
        program = remove_spaces(without_newline)
        get_tokens(program)

    except FileNotFoundError:
        sys.exit("File not found")  # Exit the program if the file is not found

if __name__ == "__main__":  # Run the main function if the script is executed
    main()