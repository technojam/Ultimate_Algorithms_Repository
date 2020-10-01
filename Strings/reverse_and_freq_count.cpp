/* This class program contains two public methods. The first one is to reverse a given string using prdefined methods
and using loops. The second method contains code to find the frequency of a given Character in a given string, it also returns
a map of all frequency counts in the string*/
#include <bits/stdc++.h>
using namespace std;

class string_op{
public:
  string_op(string s,int method_type):_input_string(s),_method_type(method_type){}
  string reverse_input(string _input_string,int _method_type){
    if (_method_type==0){
      std::cout << "Reversing the string using predefined method-:" << '\n';
      reverse(_input_string.begin(),_input_string.end());
    }
    else if(_method_type==1){
      std::cout << "Reversing string using traditional for loops:-" << '\n';
      int n=_input_string.length();
      for(int i=0;i<n/2;i++) swap(_input_string[i],_input_string[n-i-1]);
    }
    else std::cout << "Please enter a valid method type value-:" << '\n';
    return _input_string;
  }

  void frequency_count(string _input_string,int _method_type){
    map <char,int> freq;
    int n=_input_string.length();
    if(_method_type==0){
      std::cout << "Using traditional frequency count approach" << '\n';
      for(int i=0;i<n;i++){
        int counter=0;
        if(freq.find(_input_string[i])==freq.end()){
          freq.insert({_input_string[i],counter});
          for (int j=0;j<n;j++){
            if(_input_string[i]==_input_string[j]) freq[_input_string[i]]=++counter;
          }
        }
      }
    }
    else if(_method_type==1){
      std::cout << "Using predefined functions:-" << '\n';
      for(int i=0;i<n;i++){
        char key=_input_string[i];
        int counter=0;
        if(freq.find(key)==freq.end()){
          freq.insert({key,counter});
          counter=count(_input_string.begin(),_input_string.end(),key);
          freq[key]=counter;
        }
      }
    }
    else std::cout << "Please provide a valid method type-:" << '\n';
    for(auto it=freq.begin();it!=freq.end();it++) cout<<it->first<<"\t"<<it->second<<"\n";
  }
};
