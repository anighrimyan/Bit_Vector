#include <iostream>

void invert_to_1(int& bit_array, int bit_pos);

int main() {
	const int size = 32;
	int bit_array[32]{};
	int bit_step = 32;
	int pos;
	bool comp;
	do {
		comp = true;
		std::cout << "Please, enter a positiv number as a position which value do you want to invert to 1. \n" << "pos = ";
		std::cin >> pos;
		if (pos < 0) {
			std::cout << "Position number can not be negativ number. \n";
			comp = false;
		}
	} while (!comp);
	if (pos > bit_step * size) {
		std::cout << "Position out of system bit range. \n";
		return;
	}
	int bit_pos;
	if (pos > bit_step) {
	    bit_pos = pos - bit_step;
		while (!(bit_pos < bit_step)) {
			bit_pos = pos - bit_step;
		}
	}
	else {
	    bit_pos = bit_step - pos;
	}
	for (int i = 0; i < size; ++i) {
		if ((0 + bit_step * i <= pos) && (pos < bit_step + bit_step * i)) {
			invert_to_1(bit_array[i], bit_pos);
			std::cout << bit_array[i];
			break;
		}
	}
	return 0;
}

//This function converts from 0 to 1 at the given position.
void invert_to_1(int &bit_array, int bit_pos) {
	int num = 1;
	num = num << (32 - (bit_pos + 1));
	bit_array = bit_array | num;
}