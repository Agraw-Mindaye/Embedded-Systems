
# Const and Volatile
### Const
- const means that the value will not change as long as the code is concerned
- compiler assumes value will stay the same:
	- store in read-only memory
	- optimize away repeated reads

#### Ex:

```c
const int a = 10;
```

- 'a' should be treated as read-only
- the value may change (in memory) but as long as the program is concerned, 'a' will always be 10

### Volatile
- volatile means the value may change beyond the control of the program
- compiler is **not** allowed to optimize read/writes:

#### Ex:
```c
volatile int sensor_data;
while(sensor_data == 0) {
	// compiler will read from memory each loop
}
```

- the variable will **not** be retained (cached) in CPU register
- the value will always be read/write from memory

