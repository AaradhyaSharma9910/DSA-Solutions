#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct trienode
    {
        trienode *child[10];
        trienode()
        {
            for(int i=0;i<10;++i)
            child[i]=NULL;
        }
    };
    void trie_insert(string& s, trienode* curr)
    {
        int idx;
        for(int i=0;s[i]!='\0';++i)
        {
            idx=s[i]-'0';
            if(curr->child[idx]==NULL)
            curr->child[idx]=new trienode();
            curr=curr->child[idx];
        }
    }
    int trie_match(string &s,trienode*curr)
    {
        int idx;
        int count = 0;
        for(int i = 0;s[i]!='\0';i++)
        {
            idx=s[i]-'0';
            if(!curr->child[idx])
            break;
            curr=curr->child[idx];
            count++;

        }
        return count++;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trienode* root = new trienode();
        string curr;
        for(int ele:arr1)
        {
            curr = to_string(ele);
            trie_insert(curr,root);
        }
        int maxlen =0;
        for(int ele:arr2)
        {
            curr = to_string(ele);
            int len = trie_match(curr,root);
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};