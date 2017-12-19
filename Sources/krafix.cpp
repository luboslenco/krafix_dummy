#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

void usage() {
    printf("Usage: krafix profile in out tempdir system\n");
}

int main(int argc, char* argv[]) {
	if (argc < 6) return 1;
	
	int version = -1;
	bool getversion = false;

	for (int i = 6; i < argc; ++i) {
		std::string arg = argv[i];
		if (getversion) {
			version = atoi(argv[i]);
			getversion = false;
		}
		else if (arg == "--version") {
			getversion = true;
		}
	}

	const char* targetlang = argv[1];
	const char* from = argv[2];
	const char* to = argv[3];
    const char* tempdir = argv[4];
	const char* system = argv[5];

	std::ifstream t(from);
	t.seekg(0, std::ios::end);
	size_t size = t.tellg();
	std::string buffer(size, ' ');
	t.seekg(0);
	t.read(&buffer[0], size);

	std::ofstream out(to);
	out << buffer;

	return 0;
}
