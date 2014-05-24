/*
 * test.cpp
 * Copyright (C) 2014 fuel <fuel@fuel-3330>
 *
 * Distributed under terms of the MIT license.
 */

#include "print.hpp"
using namespace std;

int main() {
    cout<<"\nprint vectors\n";
    cout<<"======================\n";
    vector<vector<int> > v0 {};
    cout<<v0<<endl;
    vector<int> v1 {1,2,3};
    cout<<v1<<endl;
    vector<vector<int> > v2 {{4},{1,2,3}};
    cout<<v2<<endl;
    vector<vector<vector<int> > > v3 {{},{{4},{1,2,3}}};
    cout<<v3<<endl;

    cout<<"\nprint maps\n";
    cout<<"======================\n";
    map<string,int> m0 {};
    cout<<m0<<endl;
    map<string,int> m1 {{"key1",1},{"key2",3}};
    cout<<m1<<endl;
    map<string,vector<int> > m2 {{"key1",{1,2}},{"key2",{}}};
    cout<<m2<<endl;

    cout<<"\nprint unordered_map\n";
    cout<<"======================\n";
    unordered_map<string,int> um0 {};
    cout<<um0<<endl;
    unordered_map<string,int> um1 {{"key1",1},{"key2",3}};
    cout<<um1<<endl;
    map<string,vector<int> > um2 {{"key1",{1,2}},{"key2",{}}};
    cout<<m2<<endl;

    cout<<"\nprint sets\n";
    cout<<"======================\n";
    set<int> s0 {};
    cout<<s0<<endl;
    set<int> s1 {1,1,1,3,4,2354,23,423,4};
    cout<<s1<<endl;
    set<vector<int>> s2 {{1,2},{1,2},{1,1}};
    cout<<s2<<endl;
    map<int,set<vector<int>>> s3 {{5,{{},{1,2}}},
                                 {6,{{1,2}}},
                                 {1,{{1},{1},{1,2,3,4},{5,6}}}};
    cout<<s3<<endl;

    cout<<"\nprint unordered_sets\n";
    cout<<"======================\n";
    unordered_set<int> us0 {};
    cout<<s0<<endl;
    unordered_set<int> us1 {1,1,1,3,4,2354,23,423,4};
    cout<<us1<<endl;
    // unordered_set<vector<int>> us2 {{1,2},{1,2},{1,1}};  // not hashable
    // cout<<us2<<endl;
    // map<int,unordered_set<vector<int>>> us3 {{5,{{},{1,2}}}, // not hashable
    //                              {6,{{1,2}}},
    //                              {1,{{1},{1},{1,2,3,4},{5,6}}}};
    // cout<<s3<<endl;

    return 0;
}

