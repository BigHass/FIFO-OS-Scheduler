## FIFO Scheduler

The project is an implementation of the FIFO (First-In-First-Out) scheduling algorithm in C/C++.

## Table of Contents

- [Description](#description)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Description

The FIFO scheduling algorithm is a simple and straightforward approach to CPU scheduling, where processes are executed in the order they arrive. The implementation of the algorithm in C/C++ involves creating a queue data structure to store the processes and then implementing the logic to add and remove processes from the queue.

The implementation includes a main function that simulates the arrival of processes and their execution. The user can modify the implementation to suit their needs, such as changing the time quantum or the arrival rate of processes.

      <p align="center">
            <img src="/assets/images/fifo_single_queue.gif" alt="fifo_single_queue">
      </p>

## Installation

To use the implementation, you will need a C/C++ compiler installed on your machine, such as GCC or Clang. You can then compile the code using the following command:
 ```sh
   $ g++ fifo_scheduler.cpp -o fifo_scheduler
 ```

This will create an executable file called `fifo_scheduler` that you can run by typing:
 ```sh
  $ ./fifo_scheduler
 ```
 
 
## Usage

Upon running the `fifo_scheduler` executable, the program will prompt the user to enter the number of processes to simulate. Once the user enters the number, the program will simulate the arrival of processes and their execution using the FIFO scheduling algorithm. 

The output will display the arrival time, burst time, waiting time, and turnaround time for each process, as well as the average waiting time and average turnaround time for all processes.

## Contributing

Contributions to the project are welcome. If you have any suggestions for improvements or would like to report a bug, please create a new issue on the project's GitHub repository.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).



