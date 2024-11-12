vector<string> get_words(string str)
{
    vector<string> ret;
    string word;
    stringstream ss(str);
    while (ss >> word) {
        ret.push_back(word);
    }
    return ret;
}
