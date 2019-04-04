int a = 2;

static void set_value(int num) {
	a = num;
}

static int get_value() {
	return a;
}

static int *get_values() {
	return &a;
}