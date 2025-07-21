# Mental Model of the System

### Components
- The system has a CPU, memory, and peripherals
- The CPU executes instructions and performs calculations
- Memory holds code and other data
  - It also has a way of controlling I/O with peripherals via `MMIO` (Memory Mapped Input Output)

### Communication
- CPU and memory are connected via a `bus` (wires)
- These wires allow information (electrical signals representing 0s and 1s) to flow
  - One set is called the `instruction bus`
  - Another set is called the `data bus`
  
### Architecture
- This setup is referred to as the `load/store` architecture
  - Data is brought in (load)
  - Computation is performed
  - Result is stored back (store)

<br>

# Mental Model of the CPU

### Components
- CPU consists of `ALU` (Arithmetic Logic Unit) and `CU` (Control Unit)
- It uses 2 sets of buses
  - One set consists of the `instruction bus`
  - Other set consists of `data bus`

- With the `load/store` architecture, the data (instruction) needs to first be fetched into CPU
  - To do this, `General Purpose Registers` are used
  
### Example (adding two numbers and storing result into memory)

- The two numbers are fetched into the General Purpose Registers
- The Control Unit reads from `instruction buffer` and instructs ALU to perform calculation
- The result is then stored into a GPR
- Contents of the GPR are then written to specified memory address

### Other Registers
- A special register called the `Program Counter` (PC) holds the memory address of the next instruction to be fetched
  - After each instruction, it is incremented to move to the next one

- When the ALU performs a computation, the status (zero value, negative, overflow, etc.) is recorded into the `status` register

- Another register called the `stack pointer` register is essential in C programming (functional calls, local variable storage, return address management)

<br>

# Mental Model of the Memory

- The idea of memory is that `state` can be retained

- From transistors, we can create logic gates
- From logic gates we can create a feedback loop that stores 1 bit

- A cillection of these 1 bit storage units in parallel forms a `register`

- A stack of these registers gives us the General Purpose Register bank
- Each one has a location that can be addressed with the use of some circuitry
