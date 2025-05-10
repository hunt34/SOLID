#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Journal
{
    string title;
    vector<string>entries;

    Journal(const string &title):title(title){}

    void add_entries(const string &entry)
    {
        static int count=1;
        entries.push_back(to_string(count++) + ": " + entry);
    }


   
};


struct PresistenceManager
{
    static void save(const Journal& j, string &filename)
    {
        ofstream ofs(filename);
        for(auto &e :j.entries)ofs << e << endl;
    }
};


int main()
{
    Journal jour("DeathNote");
    jour.add_entries("Pakistan");
    jour.add_entries("China");

    PresistenceManager pm;
    pm.save(jour,jour.title);
    return 0;

}
