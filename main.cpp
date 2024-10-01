#include <iostream>
#include <chrono>
#include <thread>
#include "libusb.h"

int main(void)
{
	printf("hello\n");

	libusb_device **devs;
	int r;
	ssize_t cnt;

	const struct libusb_version* version;

	version = libusb_get_version();
	printf("Using libusb v%d.%d.%d.%d\n\n", version->major, version->minor, version->micro, version->nano);

	// r = libusb_init_context(NULL, NULL, 0);
	// libusb_exit(NULL);

	printf("done\n");

	return 0;
}


// int main(void) {
// 	using namespace std::this_thread;
// 	using namespace std::chrono;
// 	int i = 0;
// 	do {
// 		std::cout << "Hello World" << std::endl;
// 		i++;
// 		// TODO: change this later
// 		sleep_for(seconds(1));
// 	} while (i < 4);
// }