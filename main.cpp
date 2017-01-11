#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include "src/exceptions.h"

/**
    Haal van project gutenberg de txt versie van de King Jame’s Bible.
    1.	Lees alle characters van deze file in een vector.
    2.	Print hoeveel characters de file bevat (vraag het aan de vector).
    3.	Print hoeveel regels de file bevat (gebruik de vector en een STL algorithme).
    4.	Print hoeveel alfabetische characters de file bevat (vector + algorithme).
    5.	Zet de letters in de vector om in kleine letters (max 3 regels code).
    6.	Tel in een lijst voor iedere letter (a..z) hoe vaak hij voorkomt in de vector (diverse manieren mogelijk).
    7.	Druk deze lijst af 1) op lettervolgorde 2) op hoe vaak een letter voorkomt (gebruikt een algoritme).
    8.	Bepaal welke woorden er in de tekst voorkomen en druk de 10 meest voorkomende woorden af. Een woord is aaneengesloten reeks letters. (gebruik een map)
 */
int main() {
    std::vector<char> bibleChars;
    std::string file_name("assets/bible.txt");
    std::ifstream input(file_name);
    std::map<std::string, int> words;
    std::map<char, int> chars;
    std::string word;

    if (!input.good()) {
        throw (unknown_file(file_name));
    }
    try {
        char c;
        while (input.get(c)) {
            bibleChars.push_back(c);
        }
    } catch (end_of_file) {
        std::cout << "EOF";
    } catch (std::exception &problem) {
        std::cout << problem.what();
    }
    input.close();

    std::cout << "amount of chars: " << bibleChars.size() << "\n";

    //http://en.cppreference.com/w/cpp/algorithm/count
    std::cout << "amount of lines: " << std::count(bibleChars.begin(), bibleChars.end(), '\n') << "\n";
    std::cout << "amount of alphabetical chars: " << std::count_if(bibleChars.begin(), bibleChars.end(), isalpha) <<
    "\n";
    std::cout << "amount of uppercase chars: " << std::count_if(bibleChars.begin(), bibleChars.end(), isupper) << "\n";
    std::for_each(bibleChars.begin(), bibleChars.end(), [](char &c) { if (isalpha(c)) { c = tolower(c); }});
    std::cout << "amount of uppercase chars: " << std::count_if(bibleChars.begin(), bibleChars.end(), isupper) << "\n";

    std::cout << "letters sorted on alphabet\n";
    for (char l = 'a'; l <= 'z'; ++l) {
        int count = std::count_if(bibleChars.begin(), bibleChars.end(), [&](char &c) { return l == c; });
        std::cout << l << " komt " << count << " voor\n";
        chars.insert(std::pair<char, int>(l, count));
    }
    std::cout << "letters sorted on size\n";
    std::vector<std::pair<char, int>> charMapVector(chars.size());
    std::copy(chars.begin(), chars.end(), charMapVector.begin());
    std::sort(charMapVector.begin(), charMapVector.end(), [](std::pair<char, int> a, std::pair<char, int> b) {
        return a.second != b.second ? a.second > b.second : a.first > b.first;
    });
    std::for_each(charMapVector.begin(), charMapVector.end(),
                  [](std::pair<char, int> a) { std::cout << a.first << " : " << a.second << "\n"; });


    std::cout << "10 Most used words\n";
    std::for_each(bibleChars.begin(), bibleChars.end(), [&](char &c) {
        if (c != ' ' && isalpha(c)) {
            word += c;
        }
        else {
            if (word != "") {
                if (words.find(word.c_str()) == words.end()) {
                    words.insert(std::pair<std::string, int>(word, 0));
                } else {
                    words[word]++;
                }
                word = "";
            }
        }
    });
    std::vector<std::pair<std::string, int>> mapVector(words.size());
    std::copy(words.begin(), words.end(), mapVector.begin());

    std::sort(mapVector.begin(), mapVector.end(), [&](std::pair<std::string, int> a, std::pair<std::string, int> b) {
        return a.second != b.second ? a.second > b.second : a.first > b.first;
    });

    std::for_each(mapVector.begin(), mapVector.begin() + 10,
                  [&](std::pair<std::string, int> a) { std::cout << a.first << " : " << a.second << "\n"; });


    return EXIT_SUCCESS;
}