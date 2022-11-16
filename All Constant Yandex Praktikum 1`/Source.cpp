#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
/*Перед вами код парсинга поискового запроса. Сделайте его максимально понятным. Расставьте const везде, где нужно. 
Попробуйте изменить константные объекты. Сообщение об ошибке будет вам знакомо.
Формат входных и выходных данных.
Первая строка ввода содержит стоп-слова, разделённые пробелом. В следующей строке — текст поискового запроса.
Программа должна вывести слова поискового запроса по одному слову в строке. Каждое слово должно быть в квадратных скобках. 
Стоп-слова, которые есть в запросе, выводиться не должны.
Примеры входных и выходных данных
Ввод*/

vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(const string& text, const set<string>& stop_words) {
    vector<string> words;
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    const set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read query
    string query;
    getline(cin, query);
    const vector<string> query_words = ParseQuery(query, stop_words);

    for (const string& word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}