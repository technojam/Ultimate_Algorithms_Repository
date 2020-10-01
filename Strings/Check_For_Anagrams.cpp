#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2)
{
    unordered_map<char, int> frequency_of_chars_of_s1;
    unordered_map<char, int> frequency_of_chars_of_s2;

    for (auto i : s1)
        frequency_of_chars_of_s1[i]++;

    for (auto i : s2)
        frequency_of_chars_of_s2[i]++;

    for (auto i : frequency_of_chars_of_s1)
    {
        if (i.second != frequency_of_chars_of_s2[i.first])
            return false;
    }

    for (auto i : frequency_of_chars_of_s2)
    {
        if (i.second != frequency_of_chars_of_s1[i.first])
            return false;
    }

    return true;
}

int main()
{
    string s1 = "TestString";
    string s2 = "StringTest";

    if (isAnagram(s1, s2))
    {
        cout << "Both Strings are Anagrams" << endl;
    }
    else
    {
        cout << "Both Strings are not Anagrams" << endl;
    }
    return 0;
}