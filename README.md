# Social Media Account System

A C++ `Account` class that models a social media account. Every new account gets a randomly generated password that meets complexity rules, and each account keeps a list of the users it follows.

## What it does

- **Strong random passwords:** each new account gets a random password of 8 to 12 characters that always includes an uppercase letter, a lowercase letter, a digit, and a special character.
- **Follow and unfollow:** `follow` and `unfollow` return `true` or `false` so a duplicate follow or a missing user is handled without errors.
- **Search the following list:** `get_following(key)` returns every followed user whose name contains the key, or the full list if the key is empty.
- **Summary:** `to_string()` reports the username, password, and number of accounts followed.

## Built with

- C++ (classes, arrays, string handling, random number generation, `<iomanip>` formatting)

## Project structure

```
social-media-account-system/
├── Account.h     # Account class declaration
├── Account.cpp   # implementations
└── main.cpp      # password, follow, unfollow, and search tests
```

## How to run

```bash
g++ -std=c++17 main.cpp Account.cpp -o accounts
./accounts
```

## Sample output

Passwords are random, so yours will differ each run.

```
===== PASSWORD TEST =====
The user Abdullah has 2&yCIkOU as their password and is following 0 account(s).
The user Ali has 7uNjA%oF as their password and is following 0 account(s).

===== FOLLOW TEST =====
Case 2: username already at beginning (Ali)
false
Case 5: username not followed yet (bader)
true
```

## Testing

`main.cpp` checks that passwords are valid, then tests following a user who is first, last, in the middle, or not yet followed, along with unfollowing and searching the list with no key, one match, and several matches.

## What I learned

- Designing a class with private data and a clear public interface
- Generating random values safely and guaranteeing every character type is present
- Handling edge cases so functions return clear true or false results

*Built for my Computer Science II course at California State University San Marcos. The header file was provided by the course.*
