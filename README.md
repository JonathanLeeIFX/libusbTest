Running this code prints out the following:
```
run 1
inside print_devs
058b:0230 (bus 2, device 30) path: 4.3.4
exiting print_devs
run 2
inside print_devs
058b:0230 (bus 2, device 30) path: 4.3.4
exiting print_devs
run 3
inside print_devs
058b:0230 (bus 2, device 30) path: 4.3.4
exiting print_devs
run 4
inside print_devs
exiting print_devs
run 5
inside print_devs
exiting print_devs
run 6
inside print_devs
exiting print_devs
run 7
inside print_devs
exiting print_devs
run 8
inside print_devs
058b:0230 (bus 2, device 31) path: 4.3.4
exiting print_devs
run 9
inside print_devs
058b:0230 (bus 2, device 31) path: 4.3.4
exiting print_devs
run 10
inside print_devs
058b:0230 (bus 2, device 31) path: 4.3.4
exiting print_devs
```
Program has been fixed and is running.
I unplug the target USB device after run 3 and plug it back in after run 7. It is detected properly and the device address is updated.
