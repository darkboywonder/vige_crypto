vige_crypto
===========

Vigenère’s cipher program

Similar to Caeser cypher, please refer to repository https://github.com/darkboywonder/caes_crypto README.md for more info.

Major difference between this program and the other is that this program uses a string to encode a string instead of just a single integer. As the program cycles through the plaintext being encoded, it also cycles over a string changing the letter based off of the current letter in the cycle.

For example, if plaintext = Shawn and keyword is bacon

S is shifted by B

H is shifted by A

A is shifted by C

W is shifted by O

N is shifted by N

shift is based off of a 0 index alphabet so A symbols 0, B symbols 1 ... Z shifts letter 25 spots.

thus,
S is shifted by  1 becoming  T

H is shifted by  0  staying  H

A is shifted by  2 becoming  C

W is shifted by 13 becoming  J

N is shifted by 12 becoming  Z

If plaintext is a complete sentence with an infinite amount of characters and spaces, the key will rotate through itself changing the respective letter in the plain text, if it hits a space or punction, it will pause until it sees the next alphabet character. Thus a f character keyword can still handle a string of infinite number of characters.

Example:

Keyword is bacon  plaintext = "I love you"

b acon bac

I love you

this equals:
J lniq zoy 

This program was configured for the purpose of solving a problem set from an EDX course.
