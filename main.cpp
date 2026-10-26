// This program shall test an Account abstract data type that could be useful for managing accounts in a social media app.

#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
  cout << boolalpha;

  // ========== PASSWORD TEST ==========
  // create at least five accounts to show random secure passwords
  cout << "===== PASSWORD TEST =====\n";

  Account a1("Abdullah");
  Account a2("Ali");
  Account a3("Ahmed");
  Account a4("Sara");
  Account a5("John");

  cout << a1.to_string() << endl;
  cout << a2.to_string() << endl;
  cout << a3.to_string() << endl;
  cout << a4.to_string() << endl;
  cout << a5.to_string() << endl;

  // ========== FOLLOW TEST ==========
  cout << "\n===== FOLLOW TEST =====\n";

  Account demo("Abdullah");

  // case: account is not following anyone
  cout << "\nCase 1: account is not following anyone\n";
  cout << demo.to_string() << endl;
  cout << demo.get_following() << endl;

  // add names
  demo.follow("Ali");
  demo.follow("Ahmed");
  demo.follow("Sara");
  demo.follow("Soso");
  demo.follow("Bigo");
  demo.follow("Allen");
  demo.follow("John");

  cout << "\nCurrent following list:\n";
  cout << demo.get_following() << endl;

  // case: username is at the beginning
  cout << "\nCase 2: username already at beginning (Ali)\n";
  cout << demo.follow("Ali") << endl;

  // case: username is at the end
  cout << "\nCase 3: username already at end (John)\n";
  cout << demo.follow("John") << endl;

  // case: username is in the middle
  cout << "\nCase 4: username already in middle (Sara)\n";
  cout << demo.follow("Sara") << endl;

  // case: username does not match anyone followed
  cout << "\nCase 5: username not followed yet (bader)\n";
  cout << demo.follow("bader") << endl;

  cout << "\nAfter follow tests:\n";
  cout << demo.to_string() << endl;
  cout << demo.get_following() << endl;

  // ========== GET_FOLLOWING TEST ==========
  cout << "\n===== GET FOLLOWING TEST =====\n";

  // case: no key
  cout << "\nCase 1: no key\n";
  cout << demo.get_following() << endl;

  // case: one match
  cout << "\nCase 2: key = so (one match)\n";
  cout << demo.get_following("so") << endl;

  // case: multiple matches
  cout << "\nCase 3: key = a (multiple matches)\n";
  cout << demo.get_following("a") << endl;

  // case: no match
  cout << "\nCase 4: key = zzz (no match)\n";
  cout << demo.get_following("zzz") << endl;

  // ========== UNFOLLOW TEST ==========
  cout << "\n===== UNFOLLOW TEST =====\n";

  // case: beginning
  Account u1("Abdullah");
  u1.follow("Ali");
  u1.follow("Ahmed");
  u1.follow("Sara");

  cout << "\nCase 1: remove from beginning\n";
  cout << "Before:\n"
       << u1.get_following() << endl;
  cout << "Unfollow Ali: " << u1.unfollow("Ali") << endl;
  cout << "After:\n"
       << u1.get_following() << endl;

  // case: end
  Account u2("Abdullah");
  u2.follow("Ali");
  u2.follow("Ahmed");
  u2.follow("Sara");

  cout << "\nCase 2: remove from end\n";
  cout << "Before:\n"
       << u2.get_following() << endl;
  cout << "Unfollow Sara: " << u2.unfollow("Sara") << endl;
  cout << "After:\n"
       << u2.get_following() << endl;

  // case: middle
  Account u3("Abdullah");
  u3.follow("Ali");
  u3.follow("Ahmed");
  u3.follow("Sara");

  cout << "\nCase 3: remove from middle\n";
  cout << "Before:\n"
       << u3.get_following() << endl;
  cout << "Unfollow Ahmed: " << u3.unfollow("Ahmed") << endl;
  cout << "After:\n"
       << u3.get_following() << endl;

  // case: only one followed
  Account u4("Abdullah");
  u4.follow("John");

  cout << "\nCase 4: remove the only one followed\n";
  cout << "Before:\n"
       << u4.get_following() << endl;
  cout << "Unfollow John: " << u4.unfollow("John") << endl;
  cout << "After:\n"
       << u4.get_following() << endl;

  // case: no match
  Account u5("Abdullah");
  u5.follow("Ali");
  u5.follow("Ahmed");

  cout << "\nCase 5: username not found\n";
  cout << "Before:\n"
       << u5.get_following() << endl;
  cout << "Unfollow Sara: " << u5.unfollow("Sara") << endl;
  cout << "After:\n"
       << u5.get_following() << endl;

  return 0;
}