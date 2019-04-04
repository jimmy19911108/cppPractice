static int a = 1;

void set_value(int num) {
	a = num;
}

int get_value() {
	return a;
}

int *get_values() {
	return &a;
}