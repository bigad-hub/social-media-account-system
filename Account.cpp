// You shall implement the member functions of the Account class in this file.
#include "Account.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

// constructor
Account::Account(const string &username)
{
    username_ = username;
    nFollowing_ = 0;

    // seed random once
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }

    // character groups for password
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string digit = "0123456789";
    string special = "#$%&";
    string all = upper + lower + digit + special;

    int length = rand() % 5 + 8; // between 8 and 12

    password_ = "";

    // add at least one from each required type
    password_ += upper[rand() % upper.size()];
    password_ += lower[rand() % lower.size()];
    password_ += digit[rand() % digit.size()];
    password_ += special[rand() % special.size()];

    // fill the rest randomly
    while (password_.size() < length)
    {
        password_ += all[rand() % all.size()];
    }

    // shuffle password so it does not always follow the same pattern
    for (int i = 0; i < 20; i++)
    {
        int a = rand() % password_.size();
        int b = rand() % password_.size();

        char temp = password_[a];
        password_[a] = password_[b];
        password_[b] = temp;
    }
}

// print account info
string Account::to_string() const
{
    stringstream ss;

    ss << "The user " << username_
       << " has " << password_
       << " as their password and is following "
       << nFollowing_ << " account(s).";

    return ss.str();
}

// follow someone
bool Account::follow(const string &username)
{
    // if full, cannot add more
    if (nFollowing_ >= 20)
        return false;

    // check if already followed
    for (unsigned i = 0; i < nFollowing_; i++)
    {
        if (following_[i] == username)
            return false;
    }

    // add username at the end
    following_[nFollowing_] = username;
    nFollowing_++;

    return true;
}

// unfollow someone
bool Account::unfollow(const string &username)
{
    int index = -1;

    // find the username
    for (unsigned i = 0; i < nFollowing_; i++)
    {
        if (following_[i] == username)
        {
            index = i;
            break;
        }
    }

    // if not found
    if (index == -1)
        return false;

    // shift elements left
    for (unsigned i = index; i < nFollowing_ - 1; i++)
    {
        following_[i] = following_[i + 1];
    }

    nFollowing_--;

    return true;
}

// return following list, or only matches with key
string Account::get_following(const string &key) const
{
    stringstream ss;
    int count = 0;

    for (unsigned i = 0; i < nFollowing_; i++)
    {
        if (key == "" || following_[i].find(key) != string::npos)
        {
            ss << left << setw(15) << following_[i];
            count++;

            // move to next line every 4 names
            if (count % 4 == 0)
                ss << endl;
        }
    }

    return ss.str();
}