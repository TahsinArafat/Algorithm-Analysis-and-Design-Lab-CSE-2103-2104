#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int32_t main()
{
    // String Input
    string s = "BCAADDDCCACACAC";
    cin >> s;

    // Frequency Array
    map<char, int> tmpMap;
    for (auto& it : s)
        tmpMap[it]++;

    // Storing the frequency of each character
    vector<pair<int, int>> freq;
    for (auto& it : tmpMap)
        freq.push_back({ it.second, it.first });
    sort(freq.begin(), freq.end());

    // Huffman Tree Creation
    vector<pair<char, char>> huffman;
    if (freq.size() > 1) {
        huffman.push_back({ freq[0].second, freq[1].second });
    } else {
        huffman.push_back({ 0, freq[0].second });
    }
    for (int i = 2; i < freq.size(); i++) {
        huffman.push_back({ 0, freq[i].second });
    }
    reverse(huffman.begin(), huffman.end());

    // Tree Traversal + Code Generation
    map<char, string> code;
    string curString = "";
    for (int i = 0; i < huffman.size(); i++) {
        code[huffman[i].second] = curString + '1';
        curString += '0';
    }
    if (freq.size() > 1)
        code[huffman.back().first] = curString;

    // Endcoding
    string encodedString = "";
    for (auto& it : s)
        encodedString += code[it];
    cout << "The Huffman Character Map is as follows:\n";
    cout << "Character\tFrequency\tCode\n";
    for (auto& it : code)
        cout << it.first << "\t\t" << tmpMap[it.first] << "\t\t" << it.second << "\n";
    cout << "Original String: " << s << "\n";
    cout << "Encoded String: " << encodedString << "\n";
    cout << "Total Bits in String:\t" << encodedString.size() << "\n";
    int totalBitsinMap = 0;
    for (auto& it : code)
        totalBitsinMap += it.second.size() + 8;
    cout << "Total Bits in Map:\t" << totalBitsinMap << "\n";
    cout << "Neat Total Bits:\t" << encodedString.size() + totalBitsinMap << "\n";

    // Decoding
    cout << '\n';
    map<string, char> decode;
    for (auto& it : code)
        decode[it.second] = it.first;
    string tmp = "", decoded = "";
    for (auto& it : encodedString) {
        tmp += it;
        if (decode.find(tmp) != decode.end()) {
            decoded += decode[tmp];
            tmp = "";
        }
    }
    cout << "Decoded String: " << decoded << "\n";
}

/*
    Note: We represented the binary (1010...) as binary string for the ease of understanding and display.
*/