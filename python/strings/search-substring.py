#!/usr/bin/python

def search_substring():
	str1=raw_input("Enter first string:")
	print("First string is:" + str1)

	str2=raw_input("Enter second string:")
	print("Second string is:" + str2)

        len_str1 = len(str1)
        len_str2 = len(str2)
        temp_len_str1 = 0
        temp_len_str2 = 0

	while temp_len_str1 < len_str1 and temp_len_str2 < len_str2:
		if str1[temp_len_str1] is str2[temp_len_str2]:
                    temp_len_str2 = temp_len_str2 + 1
		else:
                    temp_len_str2 = 0
                temp_len_str1 = temp_len_str1 + 1

	if temp_len_str2 == len_str2:
            print("given substring is found in string")
	else: 
            print("given substring is NOT found in string")
        return

def main():
    search_substring()

main()

         
