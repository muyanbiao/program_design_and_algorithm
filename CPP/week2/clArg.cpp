#include <cstdio>

int main(int argc, char *argv[]) {

	for (int i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}

	return 0;
}

// 命令行参数