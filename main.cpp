#include <iostream>
#include <chrono>
#include <thread>
#include "libusb.h"

static void print_devs(libusb_device **devs)
{
	printf("inside print_devs\n");
	libusb_device *dev;
	int i = 0, j = 0;
	uint8_t path[8];

	int idVendor = 1419;
	int idProduct = 560;

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return;
		}

		if (desc.idVendor == idVendor && desc.idProduct == idProduct) {
			printf("%04x:%04x (bus %d, device %d)",
				desc.idVendor, desc.idProduct,
				libusb_get_bus_number(dev), libusb_get_device_address(dev));

			r = libusb_get_port_numbers(dev, path, sizeof(path));
			if (r > 0) {
				printf(" path: %d", path[0]);
				for (j = 1; j < r; j++)
					printf(".%d", path[j]);
			}
			printf("\n");
		}
		
	}
	printf("exiting print_devs\n");
}

int main(void)
{
	using namespace std::this_thread;
	using namespace std::chrono;

	libusb_device **devs;
	int r;
	ssize_t cnt;

	libusb_context* usb_context = nullptr;
    int res = libusb_init(&usb_context);
	if (r < 0)
		return r;

	int i = 0;
	do {
		printf("run %d\n", i+1);
		cnt = libusb_get_device_list(NULL, &devs);
		if (cnt < 0){
			libusb_exit(NULL);
			return (int) cnt;
		}

		print_devs(devs);
		libusb_free_device_list(devs, 1);
		sleep_for(seconds(1));
		i++;
	} while(i < 10);
	

	libusb_exit(NULL);
	return 0;
}