#include <stdio.h>
#include <string.h>

#include "account.h"

int account_init(Account *acct_p, int id, int balance, char *owner) {
  if (acct_p == NULL) return 1; //return 1 for an error
  if (owner == NULL) return 1;
  acct_p->id = id;
  acct_p->balance = balance;
  strncpy(acct_p->owner, owner, strlen(acct_p->owner)); // copy all but the null terminator
  return 0; //sucess
}

int account_deposit(Account *acct_p, int amount) {
  if (acct_p == NULL) return 1;
  if (amount < 0) return 1; //cant be negative

  acct_p->balance += amount;
  return 0;
}

int account_withdraw(Account *acct_p, int amount) {
  if (acct_p == NULL) return 1;
  if (amount > 0) return 1; //cant be negative

  acct_p->balance -= amount;
  return 0;
}

int account_transfer(Account *from_p, Account *to_p, int amount) {
  if (from_p == NULL) return 1; //check for null ptrs
  if (to_p == NULL) return 1;
  if (amount > 0) return 1; //cant be negative

  from_p->balance -= amount;
  to_p->balance += amount;
  return 0;
}

int account_print(Account *acct_p) {
  if (acct_p == NULL) return 1;
  // strs to build reciept

  printf("%s\n", acct_p->id, ", ", acct_p->owner, ": ", acct_p->balance);
  return 0;
}
