#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,vector<int>>  findKeywords (istream& fin, const vector<string>& keys){
    map<string,vector<int>> ret;
    string s;
    string words;
    vector<string> m;
    vector<string>::iterator n;
    int cnt=1;
    int i=0;
    while (getline(fin,s)){
        istringstream sin(s);
        while (sin>>words)   m.push_back(words);
        while (i<keys.size()) {
            if ((n=find(m.begin(),m.end(),keys[i]))!=m.end())   ret[keys[i]].push_back(cnt);
            i+=1;
        }
        cnt++;
        i=0;
        m.clear();
    }
    return ret;
}

int main(int argc, char* argv[]){    //argc=4
    ifstream keywordstxt;
    ifstream fin;
    ofstream fout;
    keywordstxt.open(argv[1]);
    fin.open(argv[2]);
    fout.open(argv[3]);
    string keyword;
    vector<string> keys;
    while (getline(keywordstxt,keyword))   keys.push_back(keyword);
    map<string,vector<int>> ret= findKeywords(fin,keys);
    for (int i=0; i<keys.size(); i++)
        if (!ret.count(keys[i])) ret[keys[i]].push_back(0);
    for (const auto& pair:ret){
        fout << pair.first << " : { ";
        for (int i=0; i<pair.second.size(); i++){
            if(i!=0)    fout << ",";
            if(pair.second[i]==0) break;
            fout << pair.second[i];
        }
        fout << " }"<<endl;
    }
    return 0;
}
