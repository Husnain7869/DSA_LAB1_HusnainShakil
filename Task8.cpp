#include <iostream>
#include <string>
using namespace std;

int naivePatternSearch(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();

    if (m == 0) return 0; // empty pattern matches at index 0

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) return i;
    }
    return -1;
}

void testNaivePatternSearch() {
    string text = "hello world";

    cout << "Pattern at beginning: " << naivePatternSearch(text, "hello") << "\n"; 
    cout << "Pattern at end: " << naivePatternSearch(text, "world") << "\n";       
    cout << "Pattern not present: " << naivePatternSearch(text, "test") << "\n";  
    cout << "Empty pattern: " << naivePatternSearch(text, "") << "\n";            
}

int main() {
    testNaivePatternSearch();
    return 0;
}
