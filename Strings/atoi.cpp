//
// Created by vineet on 01/10/2020.
//

#include<string>
#include<cctype>
/**
 * function atoi
 * @param s string passed int
 * @return integer value upto first invalid character (or 0)
 * The function will calculate the integer value
 * until the first invalid character (non-numeric character, for first character, sign - or + is accepted)
 * If no valid characters then 0 is returned
 */
int atoi(const std::string & s) {
	int ret = 0; // Value to return
	if(s.empty()) return ret; // Empty string
	int ind = 0; // Index to string
	if(ind == s.length()) return ret; // String is full of spaces
	const bool sign = s[ind] == '-';
	if(sign) ind++;
	if(!sign && (ind == s.length() || !isdigit(s[ind]))) return ret; // Invalid characters at beginning or string has ended
	while(ind < s.length() && isdigit(s[ind])) { // While there are valid characters
		ret *= 10;
		ret += s[ind] - '0';
		ind++;
	}
	return sign ? -ret : ret;
}

