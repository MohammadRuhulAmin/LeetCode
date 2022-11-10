class Solution {
public:
   bool backspaceCompare(string s, string t) {
       int slen = s.length();
       int tlen = t.length();
       string ns,nt;
       stack<char> sstk;
       stack<char>tstk;
       for(int i = 0;i<slen;i++){
           if(s[i] == '#' && sstk.empty())continue;
           else if((s[i] != '#' && !sstk.empty()) || (s[i] !='#' && sstk.empty()) ){
               sstk.push(s[i]);
           }
           else sstk.pop();
           
       }
       while(!sstk.empty()){
           ns += sstk.top();
           sstk.pop();
       }

       for(int i = 0;i<tlen;i++){
           if(t[i] == '#' && tstk.empty())continue;
           else if((t[i] != '#' && !tstk.empty()) || (t[i] !='#' && tstk.empty()) ){
               tstk.push(t[i]);
           }
           else tstk.pop();
           
       }
       while(!tstk.empty()){
           nt += tstk.top();
           tstk.pop();
       }

       if(ns == nt)return true;
       return false;

     

   }
};


