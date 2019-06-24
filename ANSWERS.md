**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- running : process is currently running
- waiting : process waiting for resources or for event
- stopped : process has been stopped
- zombie : process is dead but has not been removed

**2. What is a zombie process?**

- It is a process that is done but has not been cleaned up.


**3. How does a zombie process get created? How does one get destroyed?**

- A zombie is created when a child process is done operating and the parent needs to collect exit data from it.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- The main benefits is the efficiency that is gained from working in a language that compiles to native code. With c  we also get more control. for example we have pointers in c which allow us to do lots of different things with memory.
