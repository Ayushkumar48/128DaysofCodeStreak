#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char value;
    vector<TrieNode *> children;
    bool isTerminal;
    TrieNode(char val)
    {
        this->value = val;
        children.resize(26, NULL);
        isTerminal = false;
    }
};
void insertWord(TrieNode *root, string word)
{
    if (word.size() == 0)
    {
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode *root, string word)
{
    if (word.size() == 0)
    {
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    bool ans = searchWord(child, word.substr(1));
    return ans;
}
void deleteWord(TrieNode *root, string word)
{
    if (word.size() == 0)
    {
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return;
    }
    deleteWord(child, word.substr(1));
}
void printAllString(TrieNode *root, string &b, vector<string> &strings)
{
    if (root->isTerminal == true)
    {
        strings.push_back(b);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            b.push_back('a' + i);
            printAllString(root->children[i], b, strings);
            b.pop_back();
        }
    }
}
void searchUpto(TrieNode *root, string a, string &b, vector<string> &strings)
{
    if (a.size() == 0)
    {
        printAllString(root, b, strings);
        return;
    }
    char ch = a[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] == NULL)
    {
        cout << "No Strings Found";
        return;
    }
    else
    {
        child = root->children[index];
    }
    searchUpto(child, a.substr(1), b, strings);
}
void getAllStrings(TrieNode *root, string a, string &b, unordered_map<string, vector<string>> &ump)
{
    for (int i = 0; i < a.size(); i++)
    {
        b.push_back(a[i]);
        vector<string> ans;
        searchUpto(root, b, b, ans);
        ump[b] = ans;
    }
}
int main()
{
    TrieNode *root = new TrieNode('-');
    insertWord(root, "care");
    insertWord(root, "car");
    insertWord(root, "bear");
    insertWord(root, "barber");
    insertWord(root, "bearer");
    insertWord(root, "angel");
    insertWord(root, "angle");
    insertWord(root, "dog");
    insertWord(root, "cat");
    searchWord(root, "angle") ? cout << "Found\n" : cout << "Not Found\n";
    deleteWord(root, "angle");
    searchWord(root, "angle") ? cout << "Found\n" : cout << "Not Found\n";
    vector<string> strings;
    string a = "car";
    string b = "";
    unordered_map<string, vector<string>> ump;
    getAllStrings(root, a, b, ump);
    for (auto it : ump)
    {
        cout << it.first << "->";
        for (auto i : it.second)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}