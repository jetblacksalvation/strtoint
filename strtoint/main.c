#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_INTS 1000
char* nums = "1234567890";

bool innums(char val) {
	for (int x = 0; x < 10; x++) {
		if (val == nums[x]) {
			return true;
		}
	}

	return false;
}


int main() {
	FILE* ptr;
	fopen_s(&ptr,"nums.txt", "r");
	
	int arr[MAX_INTS];
	int arr_count = 0;

	char ch = 0;

	char buffer[1000];
	int buff_count =0;
	while (ch != EOF) {
		ch = fgetc(ptr);

		if (innums(ch)) {
			buffer[buff_count] = ch;
			buff_count++;
		}
		else {
			//clear buffer data
			
			printf("%i\n", atoi(buffer));
			arr[arr_count] = atoi(buffer);

			arr_count++;
			buff_count = 0;
			strcpy_s(buffer,1000, "");
		}
	}

}