/*Approach 1: Reversed Breadth-First Search
Intuition
We use breadth-first search to find the shortest path from the end of the array, n−1, back to the starting index 0.

Preprocessing: Use the Sieve of Eratosthenes to compute the list of prime factors for all numbers in the range, stored in factors.

Mapping: Traverse the array, and whenever a number is prime, store its index in edges. These act as "transit stations" that enable long-distance jumps.

During the breadth-first search, for the current index i in the queue q, we consider three types of movements:

Adjacent movement: move to i−1 or i+1.
Jump movement: for each prime factor p of nums[i], jump to all indices j stored in edges[p].
We return the depth of the BFS once index 0 is reached.*/