#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

// 统计关键字出现的行号
map<string, vector<int>> findKeywords(istream &fin, const vector<string> &keys)
{
    map<string, vector<int>> ret;
    string line;
    int line_num = 1; // 1-indexed

    while (getline(fin, line))
    {
        // 将字符串中所有非字母的字符替换为空格
        for (char &c : line)
        {
            if (!isalpha(c))
            {
                c = ' ';
            }
        }

        istringstream sin(line);
        string word;
        vector<string> words_in_line;

        while (sin >> word)
        {
            words_in_line.push_back(word);
        }

        for (size_t i = 0; i < keys.size(); i++)
        {
            if (find(words_in_line.begin(), words_in_line.end(), keys[i]) != words_in_line.end())
            {
                ret[keys[i]].push_back(line_num);
            }
        }
        line_num++;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        cerr << "Usage: " << argv[0] << " <keywords_file.txt> <target_text_file.txt> <output_file.txt>\n";
        return 1;
    }

    ifstream keywordstxt(argv[1]);
    ifstream fin(argv[2]);
    ofstream fout(argv[3]);

    if (!keywordstxt.is_open())
    {
        cerr << "Error opening keywords file.\n";
        return 1;
    }
    if (!fin.is_open())
    {
        cerr << "Error opening target text file.\n";
        return 1;
    }
    if (!fout.is_open())
    {
        cerr << "Error opening output file.\n";
        return 1;
    }

    // Load keywords from the file
    string keyword;
    vector<string> keys;
    while (getline(keywordstxt, keyword))
    {
        // 去除可能的尾部回车符（兼容 Windows/Linux 文件）
        if (!keyword.empty() && keyword.back() == '\r')
            keyword.pop_back();
        if (!keyword.empty())
            keys.push_back(keyword);
    }

    // Find keywords in the target text file
    map<string, vector<int>> result = findKeywords(fin, keys);

    // Write results to the output file
    for (auto iter = result.begin(); iter != result.end(); ++iter)
    {
        fout << iter->first << ": ";
        for (size_t i = 0; i < (iter->second).size(); i++)
        {
            fout << (iter->second)[i] << " ";
        }
        fout << "\n";
    }

    keywordstxt.close();
    fin.close();
    fout.close();

    return 0;
}