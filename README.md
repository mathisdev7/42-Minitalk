# minitalk

![Final Score](https://i.ibb.co/4Vh48f6/image.png)

## Project Description

The `minitalk` project is a simple communication system that allows for the transmission of messages between a client and a server using Unix signals. Developed as part of the 42 School curriculum, this project emphasizes inter-process communication, signal handling, and the implementation of a basic messaging protocol in C.

## Journey

This project presented a unique challenge, requiring a deep understanding of Unix signals and process management. My initial attempts were fraught with issues related to signal timing and message integrity. However, through persistent debugging and testing, I was able to refine my implementation and successfully establish a reliable communication system.

## Key Learnings

- Understanding Unix signals and their handling in C
- Implementing inter-process communication using signals
- Managing timing and synchronization between processes
- Debugging issues related to signal delivery and message integrity
- Memory management and dynamic memory allocation in C

## Technical Details

- The project implements a client-server model where the client sends messages to the server using signals.
- The main operations include:
  - Sending a character from the client to the server using `SIGUSR1` and `SIGUSR2`.
  - The server decodes the received signals into characters and reconstructs the original message.
- The communication protocol ensures that messages are transmitted accurately and efficiently.

## Project Status

- **First Attempt**: Failed (Signal Timing Issues)
- **Second Attempt**: Success (Reliable Communication)
- **Completion Time**: ~4 days

## Challenges Faced

The most challenging aspects of this project included:

- Understanding the intricacies of signal handling and timing
- Ensuring message integrity during transmission
- Debugging complex interactions between the client and server processes
- Implementing a robust protocol for message acknowledgment

## Reflection

While this project was one of the more complex ones at 42, it significantly enhanced my understanding of inter-process communication and signal handling in Unix. The iterative process of refining my approach taught me the importance of synchronization and the need for thorough testing to ensure reliable message transmission.

## Skills Developed

- Signal handling and inter-process communication
- Process management in Unix
- Memory management
- Debugging complex interactions between processes
- Performance optimization in signal-based communication
