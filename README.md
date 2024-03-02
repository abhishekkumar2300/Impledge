<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>ReadMe - Impledge</title>
</head>
<body>

<h2>Impledge</h2>

<p>The provided C++ program aims to identify the longest and second longest compound words from a given list of words. It utilizes advanced C++ features and optimizations for efficient string manipulation and comparison.</p>

<h3>Design Decisions and Approach</h3>

<ul>
  <li><strong>Compiler Optimizations:</strong> The program begins with compiler pragmas to optimize the code for performance, specifying optimization level and target architecture for the GCC compiler.</li>
  <li><strong>Data Structures:</strong> Custom data structures like ordered set and ordered map are defined using the GNU Policy-Based Data Structures (pbds) library, offering additional functionalities like ordered operations and efficient element lookup.</li>
  <li><strong>Mathematical Functions:</strong> Mathematical functions such as greatest common divisor (gcd), least common multiple (lcm), and modular arithmetic operations are implemented to support various computations within the program.</li>
  <li><strong>String Manipulation:</strong> Custom hashing techniques are employed to efficiently compute substring hashes and compare substrings for faster string comparison.</li>
  <li><strong>Input/Output Handling:</strong> Operator overloads for input and output operators (>>, <<) are provided for seamless handling of input and output of pairs and vectors.</li>
  <li><strong>Main Function:</strong> The main function orchestrates the program's execution by reading input from "input.txt", performing computations using the solve function, and writing the output to "output.txt". It also measures the program's execution time.</li>
</ul>

<h3>Execution Instructions</h3>

<ul>
  <li><strong>Input:</strong> Ensure the input words are provided in "input.txt", with each word on a separate line.</li>
  <li><strong>Compilation:</strong> Compile the program using a C++ compiler. For example: <code>g++ -std=c++11 -O3 -o program_name program.cpp</code>.</li>
  <li><strong>Execution:</strong> Execute the compiled program. For example: <code>./program_name</code>.</li>
  <li><strong>Output:</strong> The program generates output in "output.txt", containing the longest and second longest compound words found in the input list.</li>
</ul>

</body>
</html>
