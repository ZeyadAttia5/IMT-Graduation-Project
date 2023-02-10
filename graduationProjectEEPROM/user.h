#ifndef user_MAIN
#define user_MAIN


#include "STD_TYPES.h"
#include <stdint.h>
#define MAX_LENGTH 256




//const u8 usernames[3][MAX_LENGTH] = {
//		{ 'u', 's', 'e', 'r', '1' },
//		{ 'u', 's','e', 'r', '2' },
//		{ 'u', 's', 'e', 'r', '3' } };
//const u8 passwords[3][MAX_LENGTH] = {
//		{ 'p', 'a', 's', 's', '1' },
//		{ 'p', 'a','s', 's', '2' },
//		{ 'p', 'a', 's', 's', '3' } };

typedef struct user{
	u8 dataUser[5];
	u8 dataPass[5];
} user;
void LogIn(void);
void void_getUser();
void void_getPass();
void user_init();
void add_user(u8 username, u8 password);
void del_user(u8 username, u8 password);
u8 get_username(u8 index);
u8 get_password(u8 index);
u8 u8_compareData(u8 EEPROM_DATA, u8* USER_DATA, uint32_t SIZE_OF_USER_DATA);

#endif
