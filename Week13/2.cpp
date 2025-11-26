#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    set<string> uniqueWords;
    map<string, int> wordCount;

    string word = "";

    for (char c: sentence) {
        if (c == ' ') {
            if (!word.empty()) {
                uniqueWords.insert(word);
                wordCount[word]++;
                word = "";
            }
        } else {
            word += c;
        }
    }

    if (!word.empty()) {
        uniqueWords.insert(word);
        wordCount[word]++;
    }

    cout << "\nUnique words (alphabetical):\n";
    for (const string &w: uniqueWords) {
        cout << w << endl;
    }

    cout << "\nWord frequencies:\n";
    for (const auto &p: wordCount) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
