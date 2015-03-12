//
//  main.cpp
//  PossibleWords
//
//  Created by Vinod Gupta on 3/12/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

string InsertAt(string str,int pos,char c)
{
    stringstream ss;
    ss<< str.substr(0,pos);
    ss<<c;
    ss<<str.substr(pos);
    return ss.str();
}

vector<string> findWords(const char *letters,int len, set<string> &dict)
{
    vector<string> out;
    
    queue<string> qs;
    for(int i=0;i<len;++i)
    {
        char c=letters[i];
        size_t qsize = qs.size();
        if(!qsize)
        {
            stringstream ss;
            ss<<c;
            qs.push(ss.str());
            continue;
        }
        
        for(int j=0;j<qsize;++j)
        {
            string top = qs.front();
            qs.pop();
            for(int k=0;k<=top.length();++k)
            {
                string perm=InsertAt(top,k,c);
                qs.push(perm);
                if(dict.find(perm) != dict.end())
                {
                    out.push_back(perm);
                }
            }
        }
    }
    return out;
    
}

int main(int argc, const char * argv[]) {
    
    set<string> dict;
    dict.insert("cat");
    dict.insert("act");
    dict.insert("ac");
    dict.insert("stop");
    dict.insert("cac");
    char letters[] = {'c','a','t'};
    
    vector<string> out = findWords(letters, 3, dict);
    
    for(vector<string>::iterator itr = out.begin(); itr!= out.end();++itr)
    {
        cout<<itr->c_str()<<" ";
    }
    cout<<endl;
    
    return 0;
}
