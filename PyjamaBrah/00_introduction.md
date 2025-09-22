# What is embedded systems? 

- Deeply embedded CPU 
	- The CPU is hidden and not seen 
- A CPU can be programmed, allowing it to "change state" 
	- This allows for mistakes/changes to be re-programmed -
	- Doing the same with hardware components is much more difficult and expensive 
- To change state, CPU connects with **GPIO** (General Purpose Input/Output) 
	- Sensors (temperature/humidity, pressure) 
	- Actuators (motors)

# Firmware Engineering

- Uses the **microcontroller-class CPUs (M)**
    - Common CPU families:
        - **ARM Cortex-M** (M0, M0+, M3, M4, M7, M33, etc.)
        - **RISC-V** (open-source 32-bit/64-bit ISA)
        - **AVR** (e.g. ATmega328P), **PIC**

### Required Skills & Concepts 

- **C programming** is non-negotiable
    - Must master **pointers** and memory-level programming
- Understand the **Programmer’s Model** of ARM-M or RISC-V
- Write **state machines** with a **Real-Time Operating System (RTOS)**
    - Example: **FreeRTOS**        
    - Learn **OS primitives**: tasks, scheduler, mutexes, queues, etc.
- Familiarity with **assembly language**
    - Needed for low-level operations like boot code and cache control

### Memory-Mapped I/O (MMIO)

- CPU communicates via buses (wires) with:
    - **RAM / Flash memory** (program/data)
    - **Peripheral devices** (GPIO, UART, Timers, ADC, etc.)

- On a 32-bit CPU, the address space is 0 to 4GB (0x00000000 to 0xFFFFFFFF)
- Certain address ranges are **reserved for peripheral registers**.
- The CPU accesses peripherals as if it’s reading/writing memory.
- CPU doesn’t "know" if it’s talking to RAM or a hardware register, it just accesses an address.

### Registers

- **Registers** are the fundamental storage units inside hardware blocks (GPIO, UART, etc.)
- Built from **logic gates** using transistors
    - A pair of **inverters** can create a basic latch (stores 1 bit)
    - Adding a **clock signal** turns into a **flip-flop** (synchronous storage)
    - Multiple flip-flops in parallel create multi-bit **registers**
- These registers are **mapped to addresses** via MMIO, allowing CPU to:
    - **Write**: Send commands (e.g., turn on LED)
    - **Read**: Receive data (e.g., temperature sensor value)

# System Software Engineering

- Involves building **software** that runs on general-purpose computing systems
    - Laptops, smartphones, cloud servers, infotainment systems, etc.
- Unlike firmware, the system behavior isn't predictable, as users run arbitrary apps

### Required Skills & Concepts 

#### **Programming Skills**

- **C and C++** are essential for low-level access, memory control, systems APIs
- **Assembly language** (x86 or ARM-A) for boot code, interrupt handling, context switching
- **Scripting** (Python, Bash) for automation, testing, build systems, log parsing

#### **Operating System Internals**

- Understand **High-Level OS (HLOS)** architecture:
    - **Kernel space vs user space**
    - **System calls** and **interrupt handling**
- Core OS components:
    - **Scheduler**, **virtual memory**, **file systems**, **device drivers**
- Work with OS internals:
    - `fork()`, `exec()`, `mmap()`, `select()`, `ioctl()`, `signals`

#### **Memory Management & Virtualization**

- **Virtual memory** and the **MMU (Memory Management Unit)**
    - Virtual to physical address translation
    - Memory protection and isolation
- Process context: stacks, heap, segments
- Basic understanding of **page tables**, **TLB**, **paging vs segmentation**
- **Virtualization concepts** (e.g., KVM, QEMU, Xen)
    - Hypervisor control over guests
    - VM creation and isolation

#### **Device Drivers**

- Write and debug **kernel-mode drivers**
    - Character/block drivers
    - Interrupt service routines (ISRs)
- Interact with hardware safely via:
    - **I/O memory mapping**, **register access**
    - **DMA**, **interrupt lines**

#### **Concurrency and Synchronization**

- **Processes** **vs** **threads**
- Synchronization primitives:
    - **Mutexes**, **spinlocks**, **semaphores**, **condition variables**
- Avoiding deadlocks and race conditions
- Preemption and priority inversion

#### **Boot Process & System Initialization**

- Understand bootloader-to-kernel handoff:
    - U-Boot, GRUB
    - Kernel decompression, initramfs, `init()`
- System startup scripts, services (e.g., `systemd`, `init.d`)


### HLOS (High-Level Operating Systems)

- There is often an HLOS involved
	- Linux, Windows, Android, macOS, watchOS
- These systems require:
    - **Virtual Memory (VM)**
    - **Multitasking**
    - **User-space vs kernel-space separation**
    - Support for dynamic and unpredictable behavior

- The CPU involved is **application-class (A)**
	- ARM-A, x86
- These CPUs include **layers of isolation**
	- **Exception Levels (EL0–EL3)**
		-  These are privilege layers, where each higher level can restrict or control lower levels
		- OS runs in **EL1** layer 
		- Applications run in **EL0**. This is so applications do not interact with hardware (e.g. USB) 
		- In **EL2**, the **Hypervisor** runs **virtual machines**
- There are also **layers of separation**
	- **Secure (S**) vs **Non-Secure (NS)** 
	- For example, screenshotting in Netflix gives you a black/white screen since the code runs in **Secure** mode and the video buffer isn't shared

### Virtual Memory & MMU

- The **Memory Management Unit (MMU)** maps **virtual addresses** to **physical addresses**
- Each process assumes it owns memory from 0 to N, but the MMU ensures isolation
- Benefits:
    - A crash in process P1 doesn't affect P2
    - This enables process isolation, memory protection, and multitasking