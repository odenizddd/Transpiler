This is a transpiler from a mock language called 'advcalc' to LLVM's
intermediate representation (IR). It features a simple lexer that
tokenizes the source code and a recursive descent parser that creates
an abstract syntax tree (AST). Later AST is traversed recursively 
to produce IR code. Also there is a per-line error reporting mechanism.

To use the transpiler clone the repository to your local machine. Edit
'input.txt' in 'res' to your desired input. Then run 'make run' from 
within the root of the project. IR code will be placed in '/path/to/output'.

If you are into compiler/interpreter design, check out the links below 
to the resources I found very useful durin the making of this project.

TODO: Add links here.