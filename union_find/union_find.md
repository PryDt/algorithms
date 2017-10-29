# Union Find (Dynamic Connectivity)
*AKA Disjointed-set Data Structure*

## The Problem
Given a set of `N` objects, implement two commands:
 - Union Command: connect two objects
 - Find / Connection Query: returns whether two objects are connected (can be connected through objects connected in common)

### Clarifications on Connections
 - Objects are connected to themselves (reflexive property)
 - Connections are two-way (symmetric property)
 - Connections can path through other objects and connections (as long as there is a path to the other object) (transitive property)

---

NOTE: sets of connected objects are called connected components

---
 
## Implementations
Moving on to implementations...

### Quick-Find (Eager Algorithm)
Quick Find will store the data of length N in a 1D array.
```CPlusPlus
id[N] // data
```

Every object will have an index in that array. We can find if two objects are connected by indexing into `id` and checking whether they have the same value.

*Fancy way of saying the above*:
`Objects A and B are connected iff they have the same id`

---

NOTE: `iff` means "if and only if", the jargon will be used throughout this repo

---

The `Find` method would literally be implemented as so:
```CPlusPlus
bool find(int a, int b)
{
	return id[a] == id[b]; // that's really it...
}
```

This extremely simple find gives this implementation its name; however there are downsides, and the downside here is the union method.

Union is extremely expensive for this implementation because once you connect two large connected components, you will have to replace every single `id` entry in one of the connected components which will take `O(n^2)` array accesses.

Union maybe be implemented like:
```CPlusPlus
void union(int a, int b)
{
	int idA = id[a];
	int idB = id[b];
	
	for(int i = 0; i < (sizeof(id) / sizeof(id[0])); i++)
	{
		if(id[i] == idA)
			id[i] = idB;
	}
}
```
A small improvement to this would be to decide which connected component is smaller and replace those objects, but it will *still* be too expensive (and will probably add overhead to the union method).

Remember... since the only two methods that the UnionFind object needs is union and find, they need to be efficent because they may be called a large number of times for large sets of data.

`O(n^2)` doesn't scale. As the problem size(`N`) gets larger, the algorithm will take more and more time in a quadratic manner.

*To be continued - This is still a work in progress site.*