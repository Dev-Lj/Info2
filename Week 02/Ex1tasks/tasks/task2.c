/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 1 - Task 2                                                      *
 *                                                                          *
 * @author <your name>                                                      *
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// hard-coded maximum length for input strings
const int MAX_LENGTH = 1000;
const char vowels[] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U'};

int count_vowels(char A[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		char current = A[i];
		for (int i = 0; i < 9; i++) {
			if (current == vowels[i]) {
				count++;
				break;
			}
		}
	}
	return count;
}

void BS(char A[], int size, char bs[]) {
	int bs_pos = 0;
	for (int i = 0; i < size; i++) {
		char current = A[i];
		bool is_vowel = false;
		for (int i = 0; i < 9; i++) {
			if (current == vowels[i]) {
				bs[bs_pos] = current;
				bs[++bs_pos] = 'b';
				bs[++bs_pos] = current;
				is_vowel = true;
				break;
			}
		}
		if (!is_vowel) {
			bs[bs_pos] = current;
		}
		bs_pos++;
	}
}

int main() {
	char input_string[MAX_LENGTH + 1];
	printf("Enter a string: ");
	scanf("%[^\n]s", input_string);

	int string_size = strlen(input_string);
	int count = count_vowels(input_string, string_size);
	printf("vowels: %d\n", count);

	char bs[string_size + count * 2];
	BS(input_string, string_size, bs);
	printf("BS string: %s\n", bs);



	return 0;
}
