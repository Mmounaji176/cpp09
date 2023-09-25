# cpp09

# Containers in cpp
In C++, containers are objects or data structures that can hold, manage, and manipulate collections of elements. C++ provides a variety of container classes in the Standard Library, each with its own characteristics, use cases, and trade-offs. Here's an in-depth overview of some key container types in C++:

1. Sequence Containers:

std::vector:

Implemented as a dynamic array.
Efficient random access and fast iteration.
Dynamic sizing with automatic memory management.
Slower insertions/removals in the middle.
std::list:

Implemented as a doubly-linked list.
Efficient insertions/removals anywhere in the container.
No random access; linear time for indexing.
Good for frequent insertions/removals, but not for quick random access.
std::deque (Double-Ended Queue):

Implemented as a double-ended queue of dynamic arrays.
Efficient insertions/removals at both ends.
Good random access performance.
Slightly more memory overhead compared to std::vector.
2. Associative Containers:

std::set:

Stores unique elements in sorted order.
Implemented as a Red-Black Tree.
Efficient insertion, deletion, and search operations.
std::multiset:

Stores multiple instances of elements in sorted order.
Implemented as a Red-Black Tree.
Allows duplicate elements.
std::map:

Stores key-value pairs in sorted order based on keys.
Implemented as a Red-Black Tree.
Efficient key-based insertion, deletion, and search.
std::multimap:

Stores multiple key-value pairs with the same key.
Implemented as a Red-Black Tree.
Allows multiple key-value pairs with the same key.
3. Unordered Associative Containers:

std::unordered_set:

Stores unique elements in a hash table.
Efficient insertion, deletion, and search operations.
No specific order of elements.
std::unordered_multiset:

Stores multiple instances of elements in a hash table.
Allows duplicate elements.
No specific order of elements.
std::unordered_map:

Stores key-value pairs in a hash table.
Efficient key-based insertion, deletion, and search.
No specific order of key-value pairs.
std::unordered_multimap:

Stores multiple key-value pairs with the same key in a hash table.
Allows multiple key-value pairs with the same key.
No specific order of key-value pairs.
4. Container Adaptors:

std::stack:

Provides a Last-In-First-Out (LIFO) stack.
You can specify the underlying container type (default is std::deque).
std::queue:

Provides a First-In-First-Out (FIFO) queue.
You can specify the underlying container type (default is std::deque).
std::priority_queue:

Provides a priority queue.
You can specify the underlying container type (default is std::vector).
These container classes serve various purposes and have different performance characteristics. Choosing the right container for your specific use case is essential for writing efficient and effective C++ code. Consider factors such as the type of data you're working with, the required operations (insertions, deletions, lookups), and the expected usage patterns when selecting a container.

# ex02

**STD::list**:
std::list is a doubly-linked list container provided by the C++ Standard Library.
no random access, no contigous memory, biderectional iteration.

**std::vector**


The differences in sorting times between `std::list` and `std::vector` are likely due to the inherent differences in their data structures and how they interact with the sorting algorithm you've implemented (merge-insertion sort).

1. **Data Structure Differences**:
   - `std::list` is implemented as a doubly-linked list, which means that elements are stored in nodes scattered throughout memory. Insertions and deletions are fast, but accessing elements by index (random access) is slow. This can impact the efficiency of the merge and insertion sort operations.
   - `std::vector`, on the other hand, stores elements in a contiguous memory block, which can lead to better cache locality and faster access times for operations like merge and insertion sort.

2. **Merge Process**:
   - Your merge step, as implemented in the `merge` function, involves repeatedly comparing and inserting elements from two containers. This process may not be as efficient with `std::list` as it is with `std::vector`.
   - When you compare and insert elements in `std::list`, you are traversing the linked list structure, which involves jumping between non-contiguous memory locations. This can be less cache-friendly and slower than the contiguous memory access in `std::vector`.

3. **Insertion Sort**:
   - In your code, you use insertion sort for small subarrays. `std::vector` may perform better with insertion sort due to its better random access performance compared to `std::list`.

4. **Data Distribution and Size**:
   - The relative performance of different data structures and sorting algorithms can also depend on the specific distribution and size of the data being sorted. Some algorithms may perform better than others depending on these factors.

To further investigate and potentially optimize the sorting performance, you may consider the following:

- Experiment with different sorting algorithms to determine which one performs best with your data and container type.
- Consider the size and distribution of your data when choosing a sorting algorithm.
- Profile your code to identify performance bottlenecks and optimize the critical parts of your sorting process.
- Depending on the nature of your data and performance requirements, you may also consider alternative data structures or optimizations.

In practice, the choice of data structure and sorting algorithm often depends on the specific characteristics of your data and the trade-offs between factors like memory usage, speed, and ease of implementation.

# ex01
**std::stack**:
Container Agnostic: std::stack is container-agnostic, which means you can choose the underlying container type it uses. By default, it uses std::deque as the underlying container, but you can specify other containers, like std::vector or std::list, when creating a std::stack 

// Create a std::stack using std::vector as the underlying container
    std::stack<int, std::vector<int>> myStack;

RPN (Reverse Polish Notation) and normal (infix) notation are two different ways to represent and perform mathematical calculations. Each notation has its advantages and disadvantages, and they are used in different contexts. Here's a comparison between RPN and normal calculation:

**1. Notation**:

- **Normal (Infix) Notation**: This is the conventional way of writing mathematical expressions, where operators are placed between operands. For example, `3 + 5` is written in infix notation.

- **RPN (Reverse Polish Notation)**: In RPN, operators follow their operands. For example, `3 5 +` represents the same addition operation.

**2. Operator Precedence**:

- **Normal (Infix) Notation**: Infix notation typically relies on operator precedence rules (e.g., multiplication before addition) and parentheses to clarify the order of operations. This can sometimes lead to ambiguity and require the use of parentheses for complex expressions.

- **RPN (Reverse Polish Notation)**: RPN eliminates the need for operator precedence rules and parentheses because the order of operations is determined solely by the order in which operators are encountered.

**3. Evaluation**:

- **Normal (Infix) Notation**: Evaluating expressions in infix notation often requires parsing and converting the expression to an intermediate form (e.g., postfix notation or an expression tree) before performing the actual calculations.

- **RPN (Reverse Polish Notation)**: RPN expressions can be evaluated directly using a stack-based algorithm. The process is straightforward and doesn't require parsing or intermediate steps.

**4. Complexity**:

- **Normal (Infix) Notation**: Parsing and evaluating infix expressions can be more complex and may require implementing a full-fledged expression parser.

- **RPN (Reverse Polish Notation)**: RPN is simpler to evaluate using a stack-based algorithm, making it more straightforward for computation.

**5. Use Cases**:

- **Normal (Infix) Notation**: Infix notation is the standard way of writing mathematical expressions in textbooks and for human communication. It's intuitive for most people and is commonly used in everyday mathematical tasks.

- **RPN (Reverse Polish Notation)**: RPN is often used in calculators and programming languages where efficient parsing and evaluation of mathematical expressions are essential. It's also used in some stack-based programming languages (e.g., Forth).

**6. Examples**:

- **Normal (Infix) Notation**:
  - Addition: `3 + 5`
  - Parentheses: `(3 + 5) * 2`
  - Complex expressions: `3 + (5 * (7 - 2))`

- **RPN (Reverse Polish Notation)**:
  - Addition: `3 5 +`
  - Parentheses: `3 5 7 2 - *`
  - Complex expressions: `3 5 7 2 - * +`

In summary, the choice between RPN and normal notation depends on the context and requirements of your calculation. RPN can be more efficient for machine-based calculations, while normal infix notation is more familiar to humans for everyday mathematical expressions.

