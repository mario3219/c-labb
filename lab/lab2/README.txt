Some notes:

build.cc
    Used to process the txt file in /usr/share/dict/words. Automatically runs in Makefile.

trigrams.cc
    I chose to make a separate class for generating trigrams.

test_dictionary.cc 
    My own main script to test smaller functions.

dictionary.cc, trigrams.cc, word.cc and test_dictionary.cc are all compiled together when using 'make'.