//This file contains the definition of the Account class. Do not change anything in this file.

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
  private:
    string username_;
    string password_;
    string following_[20]; //to store the usernames of all accounts followed by the current account owner
    unsigned nFollowing_;  //number of people followed by this account
  public:
    //constructors
    Account(const string& username);

    //Accessors
    string get_following(const string& key = "") const; 
    string to_string() const;

    //mutator
    bool follow(const string& username);
    bool unfollow(const string& username);
};

#endif



