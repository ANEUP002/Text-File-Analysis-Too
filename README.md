# Text-File-Analysis-Too
The Text File Analyzer is a simple command-line tool written in C++ that allows you to read text files, extract words, sort them, and count their frequency.

Features
Read Text Files: You can use the "READ" command followed by the filename to read a text file. The program extracts words from the file and stores them in a vector, discarding all non-alphabetic characters and converting words to uppercase.

Sort Words: The "SORT" command sorts the words in alphabetical order and displays them.

Count Word Frequency: The "COUNT" command counts the frequency of each unique word in the file and displays the word along with its count.

Exit: The "EXIT" command allows you to quit the program.

Getting Started
To use the Text File Analyzer, compile the source code and run the executable. You can compile it on a Unix-like system using the following commands:

bash
Copy code
g++ your_program_name.cpp -o text_file_analyzer
