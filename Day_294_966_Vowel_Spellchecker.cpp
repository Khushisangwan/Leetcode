#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // Store all words for exact matching
        unordered_set<string> exactMatchSet(wordlist.begin(), wordlist.end());
        
        // Map lowercase versions to original words (first occurrence only)
        unordered_map<string, string> caseInsensitiveMap;
        
        // Map vowel-normalized versions to original words (first occurrence only)
        unordered_map<string, string> vowelInsensitiveMap;

        // Lambda to replace all vowels with '*' for vowel-insensitive matching
        auto normalizeVowels = [](const string& word) {
            string res = word;
            for (char& c : res) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    c = '*';
                }
            }
            return res;
        };

        // Build lookup maps from wordlist
        for (string& word : wordlist) {
            // Convert to lowercase for case-insensitive matching
            string lowerWord = word;
            transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

            // Store first occurrence only for case-insensitive map
            if (!caseInsensitiveMap.count(lowerWord)) {
                caseInsensitiveMap[lowerWord] = word;
            }

            // Store first occurrence only for vowel-insensitive map
            string vowelNormalized = normalizeVowels(lowerWord);
            if (!vowelInsensitiveMap.count(vowelNormalized)) {
                vowelInsensitiveMap[vowelNormalized] = word;
            }
        }

        vector<string> results;
        for (string& query : queries) {
            // Check for exact match first (highest priority)
            if (exactMatchSet.count(query)) {
                results.push_back(query);
                continue;
            }

            // Check for case-insensitive match (second priority)
            string lowerQuery = query;
            transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);
            if (caseInsensitiveMap.count(lowerQuery)) {
                results.push_back(caseInsensitiveMap[lowerQuery]);
                continue;
            }

            // Check for vowel-insensitive match (third priority)
            string vowelNormalized = normalizeVowels(lowerQuery);
            if (vowelInsensitiveMap.count(vowelNormalized)) {
                results.push_back(vowelInsensitiveMap[vowelNormalized]);
                continue;
            }

            // No match found
            results.push_back("");
        }
        return results;
    }
};