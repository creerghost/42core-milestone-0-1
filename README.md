# 42 Core — Milestone 0 & 1

C projects from the 42 Prague core curriculum, covering standard library re-implementation, I/O handling, and sorting algorithms.

---

## Projects

### [libft](https://github.com/creerghost/42core-milestone-0-1/tree/main/libft)
Re-implementation of a subset of the C standard library — string manipulation, memory functions, linked list utilities, and more. The foundation used across all subsequent 42 C projects.

### [ft_printf](https://github.com/creerghost/42core-milestone-0-1/tree/main/ft_printf)
A re-implementation of `printf` supporting format specifiers `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`. Built on top of `libft`.

### [get_next_line](https://github.com/creerghost/42core-milestone-0-1/tree/main/get_next_line)
A function that reads one line at a time from a file descriptor, handling arbitrary buffer sizes and multiple file descriptors simultaneously using static variables.

### [push_swap_mturk](https://github.com/creerghost/42core-milestone-0-1/tree/main/push_swap_mturk) and [push_swap_qs](https://github.com/creerghost/42core-milestone-0-1/tree/main/push_swap_qs)
Sorts a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations. Implements the **Mechanical Turk algorithm** and **quicksort** independently, minimising the total number of operations.

---

**Language:** C  
**Repo:** [creerghost/42core-milestone-0-1](https://github.com/creerghost/42core-milestone-0-1)
