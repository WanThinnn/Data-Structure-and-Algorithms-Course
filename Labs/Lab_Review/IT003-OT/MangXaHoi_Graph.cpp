//
//  MangXaHoi_Graph.cpp
//  IT003-OT
//
//  Created by Thinnn on 27/06/2023.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;



struct Person
{
    string name;
    string ID;
    string PassWord;
};

struct Date
{
    int day, mon, year;
};

struct Post
{
    int Like;
    int Share;
    Date date;
    vector <int> Liked;
    vector <int> Shared;
};

struct Account
{
    Person A;
    int n_Posts;
    int n_Friends;
    vector <Post> Posts;
    vector <Person> Friends;
    int Relative;
};

struct Grp
{
    vector <vector <Account>> L_Account;
    int n_Accounts;
};

void InputList(Grp &FB)
{
    cout << "So luong ban: ";
    cin >> FB.n_Accounts;
    FB.L_Account.resize(FB.n_Accounts, vector<Account>(FB.n_Accounts));

    for (int i = 0; i < FB.n_Accounts; i++)
        for (int  j = 0; j < FB.n_Accounts; j++)
            FB.L_Account[i][j].Relative = 0;
    
    for (int i = 0; i < FB.n_Accounts; i++)
    {
        int a, b;
        cin >> a >> b;
        FB.L_Account[a][b].Relative = 1;
        FB.L_Account[b][a].Relative = 1;
    }
}
void Output(Grp FB)
{
    for (int i = 0; i < FB.n_Accounts; i++)
    {
        for (auto j : FB.L_Account[i])
            cout << j.Relative << " ";
        cout << endl;
    }
}




int main()
{
    Grp Facebook ;
    InputList(Facebook);
    Output(Facebook);
}
