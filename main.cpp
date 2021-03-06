/**
 * File       : main.cpp
 * Authors    : Lucas ELISEI, Dany TCHENTE & David TRUAN
 *
 * Created on : 12.01.2017
 *
 * Contains the main program.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

#include "Dictionary.h"
#include "SpellChecker.h"

// Defaults values.
#define DEFAULT_DICT_FILE   "dictionary.txt"
#define DEFAULT_SPELL_FILE  "input_lates.txt"

using namespace std;

/**
 * Display command-line help.
 */
void displayHelp() {
    cout << "Usage: spell_checker [options]" << endl;
    cout << endl;
    cout << "Options:" << endl;

    cout << " -d <path>\tSpecify the path of the dictionary file. Default: " << DEFAULT_DICT_FILE << endl;
    cout << "\t\tBeware: File must be in data/ directory." << endl;

    cout << " -h\t\t" << "Display this help." << endl;

    cout << " -f\t\t" << "Specify the file to spell check. Default: " << DEFAULT_SPELL_FILE << endl;
    cout << "\t\tBeware: File must be in data/ directory." << endl;

    cout << " --tst\t\tTell the program to use a Ternary Search Tree as dictionary." << endl;
}

/**
 * Main program.
 */
int main(int argc, char *argv[]) {
    bool useTST = false;

    string dictionaryPath(DEFAULT_DICT_FILE);
    string filePath(DEFAULT_SPELL_FILE);

    if(argc > 1) {
        if(!strcmp(argv[1], "-h")) {
            displayHelp();

            return EXIT_SUCCESS;
        }

        for(int i = 1; i < argc; ++i) {
            if(!strncmp(argv[i], "-d", 2)) {
                dictionaryPath = argv[++i];
            }
            else if(!strncmp(argv[i], "--tst", 5)) {
                useTST = true;
            }
            else if(!strncmp(argv[i], "-f", 2)) {
                filePath = argv[++i];
            }
            else {
                cout << "Unknown option: " << argv[i] << endl;
                displayHelp();

                return EXIT_FAILURE;
            }
        }
    }

    Dictionary* dictionary;

    if(useTST)
        dictionary = new DictionaryTST(dictionaryPath);
    else
        dictionary = new DictionarySet(dictionaryPath);

    SpellChecker checker(filePath, dictionary);

    return EXIT_SUCCESS;
}
