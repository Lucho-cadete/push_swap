This project has been created as part of the 42 curriculum by luimarti.

push_swap
Description

push_swap is a sorting problem with a deliberately hostile interface. Given a stack of integers, the program must output the sequence of operations that sorts it — using only two stacks and eleven permitted instructions, and using as few operations as possible.

The constraint is what makes the project: none of the familiar sorting algorithms translate directly, because you cannot access an arbitrary element. You can only push, swap and rotate. Solving it well means designing an algorithm around the available primitives rather than adapting a textbook one, and then measuring: the project is graded on operation count, so every heuristic has to justify itself against the numbers.

The program does not sort the numbers itself — it prints the instructions that would.

Allowed operations
Operation	Effect
sa / sb / ss	Swap the top two elements of a / b / both
pa / pb	Push the top of the other stack onto a / b
ra / rb / rr	Rotate a / b / both up
rra / rrb / rrr	Rotate a / b / both down
Instructions
bash
git clone https://github.com/Lucho-cadete/push_swap.git
cd push_swap
make

Run it with the numbers to sort as arguments:

bash
./push_swap 3 1 5 2 4

To check the result, pipe the instructions into the checker and count them:

bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l

Errors (non-integers, duplicates, values outside int) are reported on standard error and the program exits without printing instructions.

Technical choices
<!-- TODO: this is the section evaluators care about most. Describe the algorithm you actually implemented (e.g. a radix sort on normalised indices, or a greedy "cheapest insertion" / Turk algorithm), why you chose it, and the operation counts you reach for 100 and 500 random numbers. -->
Resources
push_swap visualiser by o-reo — seeing the stacks move is the fastest way to understand why a heuristic behaves as it does.
Radix sort (Wikipedia) — a natural fit for this instruction set once the values are normalised to indices.
Cormen et al., Introduction to Algorithms — chapter 8, sorting in linear time, for the reasoning behind non-comparison sorts.
Use of AI

AI assistance was used for: understanding what algorithmic complexity means and why the operation count is what this project is really measuring; comparing a radix approach with a greedy insertion approach before I committed to one; explaining how to normalise arbitrary values into sortable indices; and reviewing my argument parsing for integer overflow once written. The algorithm, its implementation and the optimisation work are mine.